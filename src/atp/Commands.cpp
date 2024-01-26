#include "Commands.hpp"

std::vector<std::string> Commands::getArguments() const {
    return this->arguments;
}

std::vector<std::pair<std::string, ATPElement*>> Commands::getTrees() const {
    return this->trees;
}

void Commands::parseInput(std::string& input) {

    std::size_t length = input.length();

    while(!input.empty()) {

        removeExtraWhitespaces(input);

        std::size_t space = input.find(" ");

        std::string currWord = input.substr(0, space);
        input.erase(0, (space == std::string::npos) ? space : space + 1);

        this->arguments.push_back(currWord);

    }

    toLower(this->arguments[0]);

}

void Commands::removeExtraWhitespaces(std::string& string) {

    std::size_t currentIndex = 0;
    std::size_t length = string.length();

    std::string result = "";

    while (string[currentIndex] == ' ') {

        ++currentIndex;
    }

    bool spaceFound = false;

    while (currentIndex < length) {

        if (string[currentIndex] != ' ') {

            result.push_back(string[currentIndex++]);
            spaceFound = false;

        } else {

            if (!spaceFound) {

                result.push_back(string[currentIndex++]);
                spaceFound = true;

            } else {

                ++currentIndex;
            }
        }
    }

    if (result.back() == ' ') {

        result.pop_back();
    }

    string = result;
}

void Commands::toLower (std::string &str) {

    for (size_t i = 0; i < str.length(); i++) {

        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }

    }
}

void Commands::process(std::string& command) {

    parseInput(command);

    std::string generalCommand = this->arguments[0]; 
    std::string argument1 = ""; 
    std::string argument2 = ""; 
    std::string argument3 = ""; 

    if (!this->arguments.empty()) {

        // generalCommand = this->arguments[0];

        if (this->arguments.size() >= 2) {
            argument1 = this->arguments[1];
        }

        if (this->arguments.size() >= 3) {
            argument2 = this->arguments[2];
        }

        if (this->arguments.size() == 4) {
            argument3 = this->arguments[3];
        }

        if(this->arguments.size() > 4) {
            
            throw std::invalid_argument("Too many arguments!");
        }
    }

    if(generalCommand == "load" && this->arguments.size() >= 2) {

        if(!validObjectName(argument1)) {

            throw std::invalid_argument("Invalid object name!");
        }

        if (argument2.empty()) {

            std::vector<std::string> input;
            std::string line;

            while(std::getline(std::cin, line) && !line.empty()) {

                input.push_back(line);
            }

            Generator tree;
            ATPElement* root = tree.GenerateTree(input);
            trees.emplace_back(argument1, root);

            std::cout << argument1 << " loaded successfully!" << std::endl;

            this->arguments.clear();

        } else {

            Generator tree;
            ATPElement* root;

            std::vector<std::string> input = tree.readFromFile(argument2);

            root = tree.GenerateTree(input);
            trees.emplace_back(argument1, root);

            std::cout << argument1 << " loaded successfully!" << std::endl;
            
            this->arguments.clear();
        }


    } else if (generalCommand == "help" && this->arguments.size() == 1) {

        help();
        this->arguments.clear();

    } else if (generalCommand == "exit" && this->arguments.size() == 1) {

        exit();
        this->arguments.clear();

    }  else if (generalCommand == "save" && this->arguments.size() >= 2) {

        if(argument2.empty()) {

            for(std::size_t i = 0; i < trees.size(); i++) {

                if(argument1 == trees[i].first) {

                    trees[i].second->print();
                    trees[i].second->setSaved(true);
                    trees[i].second->setModified(false);    
                }
            }
        } else {
            
            save(argument1, argument2);
        }


        this->arguments.clear();

    } else if(generalCommand == "find" && this->arguments.size() == 3) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                if(find(trees[i].second, argument2)) {

                    std::cout << argument2 << " is employed in " << trees[i].first << "." << std::endl;

                } else {
                    std::cout << argument2 << " does not work in " << trees[i].first << "." << std::endl;
                }
                
            }
        }

        this->arguments.clear();

    } else if (generalCommand == "num_subordinates" && this->arguments.size() == 3) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                ATPElement* person = findPerson(trees[i].second, argument2);

                std::size_t count = person->getChildren().size();

                if(count == 0) {

                    std::cout << argument2 << " has no subordinates." << std::endl;

                } else {
                    std::cout << argument2 << " has " << count << " subordinates." << std::endl;
                }
            }
        }

        this->arguments.clear();

    } else if(generalCommand == "manager" && this->arguments.size() == 3) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                std::string name = manager(trees[i].second, argument2);

                if (!name.empty()) {
                    
                    std::cout << "The manager of " << argument2 << " is " <<  name << "." << std::endl;

                } else if(argument2 == "CEO_to") {

                    std::cout << "The CEO_to doesn't have manager." << std::endl;

                } else {

                    std::cout << "There is no " << argument2 << " in " << trees[i].first << "." << std::endl;
                }
            }
        }

        this->arguments.clear();

    } else if(generalCommand == "num_employees" && this->arguments.size() == 2) {

        bool flag = false;

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                std::cout << "There are " << numEmployees(trees[i].second) << " employees in " << trees[i].first << "." << std::endl;
                flag = true;
            }
        }

        if(flag == false) {

            std::cout << argument1 << " is an unknown office!" << std::endl;
        }

        this->arguments.clear();

    } else if(generalCommand == "overloaded" && this->arguments.size() == 2) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                if(overloaded(trees[i].second) == 0) {

                    std::cout << "No overloaded employees in " << trees[i].first << "." << std::endl;
                    
                } else {

                    std::cout << "There are " << overloaded(trees[i].second) << " employees." << std::endl;
                }
                
            }
        }

        this->arguments.clear();

    } else if(generalCommand == "join" && this->arguments.size() == 4) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                trees[i].second->setSaved(false);
                trees[i].second->setModified(true);
                
            }
        }

        this->arguments.clear();

    } else if(generalCommand == "fire" && this->arguments.size() == 3) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                if (argument2 == "CEO_to") {

                    std::cout << "You cannot fire the Big boss!" << std::endl;

                } else if (fire(trees[i].second, argument2)) {

                    std::cout << argument2 << " was fired." << std::endl;

                } else {

                    std::cout << "There isn't a person with that name." << std::endl;
                }
            }

            trees[i].second->setSaved(false);
            trees[i].second->setModified(true);
        }

        this->arguments.clear();

    } else if(generalCommand == "hire" && this->arguments.size() == 4) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                ATPElement* person = findPerson(trees[i].second, argument3);
                ATPElement* employee = findPerson(trees[i].second, argument2);

                if (person == nullptr) {
                    throw std::invalid_argument ("Opa!");
                }

                if (!employee) {

                    person->addChild(argument2);
                    
                    std::cout << argument2 << " was hired." << std::endl;

                } else {

                    person->addChild(argument2);

                    fire(trees[i].second, argument2);

                    std::cout << argument2 << " was hired." << std::endl;

                } 

                trees[i].second->setSaved(false);
                trees[i].second->setModified(true);
            }
        }

        this->arguments.clear();

    } else if(generalCommand == "salary" && this->arguments.size() == 3) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                ATPElement* person = findPerson(trees[i].second, argument2);

                int s = salary(person, person->getChildren().size());
                
                std::cout << "The salary is " << s << " euro." << std::endl;
            }
        }

        this->arguments.clear();

    } else if(generalCommand == "incorporate" && this->arguments.size() == 2) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {


                trees[i].second->setSaved(false);
                trees[i].second->setModified(true);
                
            }
        }

        this->arguments.clear();

    } else if(generalCommand == "modernize" && this->arguments.size() == 2) {

        for(std::size_t i = 0; i < trees.size(); i++) {

            if(argument1 == trees[i].first) {

                if(modernize(trees[i].second)) {

                    std::cout << trees[i].first << " modernized." << std::endl;

                } else {

                    std::cout << "Problem while modernizing." << std::endl;
                }

                trees[i].second->setSaved(false);
                trees[i].second->setModified(true);
                
            }
        }

        this->arguments.clear();

    } else {

        std::cout << "Invalid number of arguments or wrong command." << std::endl;

        this->arguments.clear();
    }
} 

void Commands::save(const std::string& objectName, const std::string& fileName) {

    std::ofstream output(fileName);

    if(!output.is_open()) {
        
        throw std::runtime_error("Couldn't open the file!");
    }

    for(std::size_t i = 0; i < trees.size(); i++) {

        if(objectName == trees[i].first) {
            
            std::queue<std::pair<ATPElement*, std::string>> bfsQueue;

            bfsQueue.push({trees[i].second, ""});

            while (!bfsQueue.empty()) {

                std::pair<ATPElement*, std::string> current = bfsQueue.front();

                bfsQueue.pop();

                if (!current.second.empty()) {

                    output << current.second << "-" << current.first->getName() << std::endl;
                }

                for (std::size_t i = 0; i <  current.first->getChildren().size(); i++) {

                    bfsQueue.push({current.first->getChildren()[i], current.first->getName()});
                }
            }

            trees[i].second->setSaved(true);
            trees[i].second->setModified(false);
        }
    }

    if(output.good()) {
        std::cout << objectName << " saved." << std::endl;
    } else {
        std::cout << "Error saving file!" << std::endl;
    }

}

void Commands::help() {

std::cout << "Available commands:\n"
        << "LOAD <object_name><file_name>: loads hierarchy data from a file with the supplied name.\n"
        << "SAVE <object_name><file_name>: saves the hierarchy information of the specified object to a file with the specified name.\n"
        << "FIND <object_name><employee_name>: checks whether an employee with the specified name exists in the specified object.\n"
        << "NUM_SUBORDINATES <name_of_object><name_of_employee>: displays the number of direct subordinates of the given employee in the specified object.\n"
        << "MANAGER <name_of_object> <name_of_employee>: displays the name of the manager of the given employee in the specified object.\n"
        << "NUM_EMPLOYEES <object_name>: displays the number of employees in the specified object.\n"
        << "OVERLOADED <name_of_object>: displays the number of employees in the specified object for whom the number of subordinates (direct or not) is greater than 20.\n"
        << "JOIN <name_of_object_1> <name_of_object_2> <name_of_object_result>: joins the two submitted objects into a new object.\n"
        << "FIRE <name_of_object> <name_of_employee>: removes the employee from the corresponding object.\n"
        << "HIRE <name_of_object> <name_of_employee> <name_of_manager>: appoints the employee in the relevant object as subordinate to the submitted manager.\n"
        << "SALARY <object_name> <employee_name>: displays the employee's salary.\n"
        << "INCORPORATE <name_of_object>: incorporates the company.\n"
        << "MODERNIZE <name_of_object>: modernizes the company.\n"
        << "HELP: Display this help message.\n"
        << "EXIT: Exit the program.\n"; 
} 

void Commands::exit() {

    for(std::size_t i = 0; i < this->trees.size(); i++) {

        if(this->trees[i].second->getSaved() == false) {

            if(this->trees[i].second->getModified() == true) {

                std::cout << trees[i].first << " is modified, but not saved." << std::endl;
                std::cout << "Enter file name to save it: ";

                std::string fileName;
                getline(std::cin, fileName);

                save(trees[i].first, fileName);

            } else {

                std::cout << trees[i].first << " is not saved." << std::endl;
                std::cout << "Enter file name to save it: ";

                std::string fileName;
                getline(std::cin, fileName);

                save(trees[i].first, fileName);

            }
        }
    }

    deallocateTrees();
    
    std::cout << "Goodbye!" << std::endl;
    return;
}

void Commands::deallocateTrees() {

    for(std::size_t i = 0; i < this->trees.size(); i++) {

        ATPElement* root = trees[i].second;
        ATPElement::deallocate(root);
    }

    trees.clear();
}

bool Commands::find(ATPElement* root, const std::string& name) {

    if(root->getName() == name) {
        return true;
    }

    for(std::size_t i = 0; i < root->getChildren().size(); i++) {
       
        if(find(root->getChildren()[i], name)) {

            return true;
        }
    }

    return false;
}

bool Commands::validObjectName(const std::string& name) {

    if(name.empty()) return false;

    for(std::size_t i = 0; i < name.size(); i++) {

        char ch = name[i];

        if(!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')) {
            return false;
        }
    }

    return true;

}

bool Commands::modernize(ATPElement* root) {

    if (!root) {

        return true;
    }

    std::vector<std::vector<ATPElement*>> result = getTreePerLevel(root);

    if(result.size() % 2 == 0) {

        for(int i = result.size() - 1; i >= 1; i -= 2) {

            for(std::size_t j = 0; j < result[i].size(); j++) {

                if(!result[i][j]->isLeaf()) {

                    fire(root, result[i][j]->getName());
                }
            }
        }

    } else {

        for(int i = result.size() - 2; i >= 1; i -= 2) {
            
            for(int j = 0; j < result[i].size(); j++) {
                
                if(!result[i][j]->isLeaf()) {

                    fire(root, result[i][j]->getName());
                }
            }
        }
    }
}

bool Commands::fire(ATPElement* root, const std::string& name) {

    ATPElement* parent = findParent(root, name);
    ATPElement* child = findPerson(root, name);

    if(parent && child) {

        for(std::size_t i = 0; i < child->getChildren().size(); i++) {

            parent->getChildren().push_back(child->getChildren()[i]);
        }

        parent->removeChild(name);

        return true;
    }

    return false;
}

int Commands::numOfEmployeesOfCurrPerson (ATPElement* root) {

    int count = 0;

    if(!root) return count;

    count = root->getChildren().size();

    for(std::size_t i = 0; i < root->getChildren().size(); i++) {

        count += numOfEmployeesOfCurrPerson(root->getChildren()[i]);
    }

    return count;

}

int Commands::overloaded(ATPElement* root) {

    int count = 0;

    if(!root) return count;

    if(numOfEmployeesOfCurrPerson(root) > 20) {
        
        count++;
    }

    for(std::size_t i = 0; i < root->getChildren().size(); i++) {

        count += overloaded(root->getChildren()[i]);
    }

    return count;

}

int Commands::numEmployees(ATPElement* root) {

    int counter = 1;

    if(!root) return counter;

    for(std::size_t i = 0; i < root->getChildren().size(); i++) {

        counter += numEmployees(root->getChildren()[i]);
    }

    return counter;
}

int Commands::salary(ATPElement* root, std::size_t numSubordinates) {

    int count = 500 * numSubordinates + 50 * (numEmployees(root) - numSubordinates - 1);

    return count;
}

ATPElement* Commands::findPerson(ATPElement* root, const std::string& name) {

    if (!root) {
        return nullptr;
    }

    if(root->getName() == name) {
        return root;
    }

    for(std::size_t i = 0; i < root->getChildren().size(); i++) {
       
        ATPElement* person = findPerson(root->getChildren()[i], name);
        if(person) return person;
    }

    return nullptr;
}

ATPElement* Commands::findParent (ATPElement* root, const std::string& name) {

    if (!root) return nullptr;

    for(std::size_t i = 0; i < root->getChildren().size(); i++) {

        if(root->getChildren()[i]->getName() == name) {

            return root;

        }

        ATPElement* result = findParent(root->getChildren()[i], name);

        if (result) {
            return result;  
        }
    }

    return nullptr;

}

std::string Commands::manager(ATPElement* root, const std::string& name) {

    if(!root) return "";

    std::string boss = "";

    for (std::size_t i = 0; i < root->getChildren().size(); i++) {

        if (root->getChildren()[i]->getName() == name) {

            boss = root->getName();

        } else {

            std::string subBoss = manager(root->getChildren()[i], name);

            if (!subBoss.empty()) {
                boss = subBoss;
                break;  
            }
        }
    }

    return boss;
}

std::vector<std::vector<ATPElement*>> Commands::getTreePerLevel(ATPElement* root) {

    std::vector<std::vector<ATPElement*>> result;
    std::queue<ATPElement*> queue;

    if (!root)
    {
        return result;
    }

    std::vector<ATPElement*> currentLevel;

    queue.push(root);

    std::size_t elementsAtCurrentLevel = 1, elementsAtNextLevel = 0;

    while (!queue.empty()) {
        
        ATPElement* currentBox = queue.front();
        currentLevel.push_back(currentBox);
        queue.pop();
        --elementsAtCurrentLevel;

        for (std::size_t i = 0; i < currentBox->getChildren().size(); ++i)
        {
            ++elementsAtNextLevel;
            queue.push(currentBox->getChildren()[i]);
        }

        if (elementsAtCurrentLevel == 0)
        {
            result.push_back(currentLevel);
            currentLevel.clear();
            elementsAtCurrentLevel = elementsAtNextLevel;
            elementsAtNextLevel = 0;
        }
    }

    return result;
}
