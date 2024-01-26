#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

#include <stdexcept>

class ATPElement {

private:

    std::string name;
    std::vector<ATPElement*> children;

    bool modified = false;
    bool saved = false;

public:

    ATPElement() = default;

    ATPElement(const std::string& n, const std::vector<ATPElement*>& children = std::vector<ATPElement*>());

    const std::string& getName() const;

    std::vector<ATPElement*>& getChildren();

    const bool getModified() const;

    const bool getSaved() const;

    void setModified(const bool m);

    void setSaved(const bool s);

    bool isLeaf();

    static void deallocate(ATPElement* root);

    void removeChild(const std::string& childName);

    void addChild(const std::string& ch);

    void print();
};