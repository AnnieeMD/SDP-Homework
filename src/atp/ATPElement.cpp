#include "ATPElement.hpp"

ATPElement::ATPElement(const std::string& n, const std::vector<ATPElement*>& children) {
    this->name = n;
    this->children = children;
} 

const std::string& ATPElement::getName() const {
    return name;
}

std::vector<ATPElement*>& ATPElement::getChildren() {
    return children;
}

const bool ATPElement::getModified() const {
    return this->modified;
}

const bool ATPElement::getSaved() const {
    return this->saved;
}

void ATPElement::setModified(const bool m) {
    this->modified = m;
}

void ATPElement::setSaved(const bool s) {
    this->saved = s;
}

bool ATPElement::isLeaf() {

    return this->children.empty();
}

void ATPElement::deallocate(ATPElement* root) {

    if(!root) return;
    
    for (std::size_t i = 0; i < root->getChildren().size(); ++i) {
        
        delete root->getChildren()[i];
    }

    delete root;
}

void ATPElement::removeChild(const std::string& childName) {
    
    for (std::size_t i = 0; i < children.size(); i++) {

        if (children[i]->getName() == childName) {

            delete children[i]; 
            children.erase(children.begin() + i);  
        }
    }
}

void ATPElement::addChild(const std::string& ch) {

    ATPElement* child = new ATPElement(ch);

    if(!child) {
        throw std::bad_alloc();
    }
    children.push_back(child);
}

void ATPElement::print() {

    std::queue<std::pair<ATPElement*, std::string>> bfsQueue;

    bfsQueue.push({this, ""});

    while (!bfsQueue.empty()) {

        std::pair<ATPElement*, std::string> current = bfsQueue.front();

        bfsQueue.pop();

        if (!current.second.empty()) {
            std::cout << current.second << "-" << current.first->name << std::endl;
        }

        for (std::size_t i = 0; i <  current.first->children.size(); i++) {

            bfsQueue.push({current.first->children[i], current.first->name});
        }
    }
}