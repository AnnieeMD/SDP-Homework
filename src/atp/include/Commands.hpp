#pragma once

#include "ATPElement.hpp"
#include "ATPTreeGenerator.hpp"

class Commands {

private:

    std::vector<std::string> arguments;

    std::vector<std::pair<std::string, ATPElement*>> trees;

public:

    std::vector<std::string> getArguments() const;

    std::vector<std::pair<std::string, ATPElement*>> getTrees() const;

    void parseInput(std::string& input);

    void removeExtraWhitespaces(std::string& string);

    void toLower (std::string &str);

    void process(std::string& command);

    void save(const std::string& objectName, const std::string& fileName);

    void help();

    void exit();

    void deallocateTrees();

    bool find(ATPElement* root, const std::string& name);

    bool validObjectName(const std::string& name);

    bool modernize(ATPElement* root);

    bool fire(ATPElement* root, const std::string& name);

    int numOfEmployeesOfCurrPerson (ATPElement* root);

    int overloaded(ATPElement* root);

    int numEmployees(ATPElement* root);

    int salary(ATPElement* root, std::size_t numSubordinates);

    ATPElement* findPerson(ATPElement* root, const std::string& name);

    ATPElement* findParent (ATPElement* root, const std::string& name);

    std::string manager(ATPElement* root, const std::string& name);

    std::vector<std::vector<ATPElement*>> getTreePerLevel(ATPElement* root);

};