#pragma once

#include "ATPElement.hpp"

class Generator {

private:

    ATPElement* root;

public:

bool isValidName(const std::string& name);

bool isElementInVector(const std::vector<std::string>& vec, const std::string& target);

static int numberOfOccurrences (const std::vector<std::string>& vec, const std::string& name);

std::vector<std::string> readFromFile(const std::string& fileName);

ATPElement* findChild(ATPElement* root, const std::string& key);

ATPElement* GenerateTree(const std::vector<std::string>& input);

};
