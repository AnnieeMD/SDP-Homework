#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/atp/include/ATPElement.hpp"

TEST_CASE("ATPElement Constructor and Getter Methods") {
    
    std::vector<ATPElement*> children;
    ATPElement element("Parent", children);

    REQUIRE(element.getName() == "Parent");
    REQUIRE(element.getChildren().empty());
    REQUIRE_FALSE(element.getModified());
    REQUIRE_FALSE(element.getSaved());
}

TEST_CASE("ATPElement Setter Methods") {
    
    ATPElement element("Element", {});

    element.setModified(true);
    element.setSaved(true);

    REQUIRE(element.getModified());
    REQUIRE(element.getSaved());
}

TEST_CASE("ATPElement Child Management") {
    
    ATPElement element("Parent", {});

    element.addChild("Child1");
    element.addChild("Child2");
    element.addChild("Child3");

    REQUIRE(element.getChildren().size() == 3);

    element.removeChild("Child2");

    REQUIRE(element.getChildren().size() == 2);
    REQUIRE(element.getChildren()[0]->getName() == "Child1");
    REQUIRE(element.getChildren()[1]->getName() == "Child3");
    REQUIRE(element.getChildren()[0]->isLeaf() == true);
}


TEST_CASE("ATPElement Deallocation") {
    ATPElement* root = new ATPElement("Root");

    root->addChild("Child1");
    root->addChild("Child2");

    ATPElement::deallocate(root);

   //??????? REQUIRE(root == nullptr);
}