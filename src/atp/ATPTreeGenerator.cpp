#include "ATPTreeGenerator.hpp"

bool Generator::isValidName(const std::string& name) {
    
    return (name.find(' ') == std::string::npos) && (name.find('-') == std::string::npos);
}

bool Generator::isElementInVector(const std::vector<std::string>& vec, const std::string& target) {

    for (std::size_t i = 0; i < vec.size(); i++) {

        if (vec[i] == target) {

            return true; 
        }
    }

    return false;
}

int Generator::numberOfOccurrences (const std::vector<std::string>& vec, const std::string& name) {
    
    int count = 0;

    for(std::size_t i = 0; i < vec.size(); i++) {
        
        if(vec[i] == name) {
            count++;
        }
    }

    return count;
}

std::vector<std::string> Generator::readFromFile(const std::string& fileName) {

    std::vector<std::string> lines;
    std::ifstream in(fileName);

    if (!in.is_open()) {
        
        throw std::runtime_error("Problem while opening the file!");
    }

    std::string line;

    while(std::getline(in, line)) {
        lines.push_back(line);
    }

    in.close();
    return lines;
}

ATPElement* Generator::findChild(ATPElement* root, const std::string& key) {

    if(root->getName() == key) {
        return root;
    }

    for(std::size_t i = 0; i < root->getChildren().size(); i++) {

        ATPElement* result = findChild(root->getChildren()[i], key);

        if(result != nullptr) return result; 
    }

    return nullptr;
}

ATPElement* Generator::GenerateTree(const std::vector<std::string>& input) {

    ATPElement* root = new ATPElement("CEO_to");

    try {

        std::string line;
        std::vector<std::string> supervisors;
        supervisors.push_back("CEO_to");

        for (const std::string& line : input) {

            std::size_t dashPos = line.find("-");
            std::string supervisor, subordinate;

            std::size_t supervisorEnd = line.find_last_not_of(" \t", dashPos - 1);
            
            if (supervisorEnd != std::string::npos) {
                
                supervisor = line.substr(0, supervisorEnd + 1);
            
            } else {
                
                throw std::invalid_argument("Invalid input! Unable to extract supervisor.");
            }

            std::size_t subordinateStart = line.find_first_not_of(" \t", dashPos + 1);

            if (subordinateStart != std::string::npos) {
                
                subordinate = line.substr(subordinateStart);

            } else {
                
                throw std::invalid_argument("Invalid input! Unable to extract subordinate.");
            }

            if (!isValidName(supervisor) || !isValidName(subordinate)) {
            
                throw std::invalid_argument("Invalid names! Names should not contain spaces or dashes.");
            }

            if(isElementInVector(supervisors, supervisor)) {
                
                if(numberOfOccurrences(supervisors, subordinate) > 0) {
                    
                    throw std::invalid_argument("Invalid input! Each person is supposed to meet exactly once in the subordinate role.");

                } else {

                    ATPElement* newChild = findChild(root, supervisor);
                    newChild->addChild(subordinate);
                    supervisors.push_back(subordinate);
                }

            } else {

                throw std::logic_error("You cannot add a supervisor before he has been a subordinate!");
            }
        }

        return root;

    } catch (const std::exception& e) {

        std::cout << "Exception caught: ";

        if(root) {
            root->deallocate(root);
        }

        throw;
    }
}