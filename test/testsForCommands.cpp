#include "catch.hpp"
#include "../src/atp/include/Commands.hpp"

TEST_CASE("Helper functions to commands") {

    SECTION("Parse Input / toLower") {
        Commands commands;

        std::string input1 = "SAVE object_name file_name.txt";
        commands.parseInput(input1);
        REQUIRE(commands.getArguments()[0] == "save");
        REQUIRE(commands.getArguments()[1] == "object_name");
        REQUIRE(commands.getArguments()[2] == "file_name.txt");

        std::string input2 = "SAVE";
        commands.toLower(input2);

        REQUIRE(input2 == "save");

    }

    SECTION("Remove Extra Whitespaces") {
        Commands commands;

        std::string input1 = "   extra   spaces   ";
        commands.removeExtraWhitespaces(input1);
        REQUIRE(input1 == "extra spaces");

        std::string input2 = "remove   extra   spaces";
        commands.removeExtraWhitespaces(input2);
        REQUIRE(input2 == "remove extra spaces");

        std::string input3 = "   ";
        commands.removeExtraWhitespaces(input3);
        REQUIRE(input3.empty());
    }

    SECTION("Valid Object Name") {
        Commands commands;

        REQUIRE(commands.validObjectName("Valid_Object_Name123") == true);

        REQUIRE(commands.validObjectName("Invalid Object Name") == false);

        REQUIRE(commands.validObjectName("Invalid@Object#Name") == false);

        REQUIRE(commands.validObjectName("") == false);
    }
}

TEST_CASE("Process - Save command to a file") {
    Commands commands;

    commands.getTrees().emplace_back("Company1", new ATPElement("CEO_to"));

    std::string outputFileName = "output_test.txt";
    std::string saveCommand = "save Company1 " + outputFileName;

    REQUIRE_NOTHROW(commands.process(saveCommand));

    std::ifstream outputFile(outputFileName);
    REQUIRE(outputFile.good());

    remove(outputFileName.c_str());

    commands.deallocateTrees();

}

TEST_CASE("Save - Save tree to file") {
    Commands commands;

    ATPElement* root = new ATPElement("CEO_to");
    root->addChild("Manager");
    commands.getTrees().emplace_back("Company1", root);

    std::string outputFileName = "output_test.txt";

    REQUIRE_NOTHROW(commands.save("Company1", outputFileName));

    std::ifstream outputFile(outputFileName);
    REQUIRE(outputFile.good());

    remove(outputFileName.c_str());

    commands.deallocateTrees();
}

TEST_CASE("Exit") {

    Commands commands;

    ATPElement* root1 = new ATPElement("CEO_to");
    commands.getTrees().emplace_back("Boss", root1);

    ATPElement* root2 = new ATPElement("Manager");
    commands.getTrees().emplace_back("Employee", root2);

    root1->setSaved(true);
    root2->setSaved(true);

    REQUIRE_NOTHROW(commands.exit());
}

TEST_CASE("Deallocate Trees") {

    Commands commands;

    ATPElement* root1 = new ATPElement("CEO_to");
    commands.getTrees().emplace_back("Company1", root1);

    ATPElement* root2 = new ATPElement("Manager");
    commands.getTrees().emplace_back("Company2", root2);

    commands.deallocateTrees();

    REQUIRE(commands.getTrees().size() == 0);
}

TEST_CASE("Functions directly related to the root of the tree") {

    Commands commands;

    ATPElement* root = new ATPElement("CEO_to");
    ATPElement* child1 = new ATPElement("Manager1");
    ATPElement* child12 = new ATPElement("Employee1");

    root->getChildren().push_back(child1);
    child1->getChildren().push_back(child12);

    commands.getTrees().emplace_back("Company1", root);

    SECTION("find") {

        REQUIRE(commands.find(root, "Manager1") == true);

        REQUIRE(commands.find(root, "NonExistingEmployee") == false);
    }

    SECTION("modernize") {

        REQUIRE_NOTHROW(commands.modernize(root));
    }

    SECTION("fire") {

        REQUIRE(commands.fire(root, "Employee1") == true);

        REQUIRE(commands.fire(root, "nonexistent") == false);
    }

    SECTION("numOfEmployeesOfCurrPerson") {

        REQUIRE(commands.numOfEmployeesOfCurrPerson(root) == 2);

        REQUIRE(commands.numOfEmployeesOfCurrPerson(nullptr) == 0);
    }

    SECTION("overloaded") {

        REQUIRE(commands.overloaded(nullptr) == 0);

        REQUIRE(commands.overloaded(root) == 0);
    }

    SECTION("numEmployees") {

        REQUIRE(commands.numEmployees(root) == 3);
    }

    SECTION("salary") {

        REQUIRE(commands.salary(root, root->getChildren().size() ) == 550);
        
    }

    SECTION("findPerson") {

        REQUIRE(commands.findPerson(nullptr, "CEO_to") == nullptr);

        // Test case 2: name not found
        REQUIRE(commands.findPerson(root, "nonexistent") == nullptr);

        // Test case 3: name found
        REQUIRE(commands.findPerson(root, "Employee1")->getName() == "Employee1");
    }

    SECTION("findParent") {
        
        REQUIRE(commands.findParent(nullptr, "CEO_to") == nullptr);

        // Test case 2: name not found
        REQUIRE(commands.findParent(root, "nonexistent") == nullptr);

        // Test case 3: name found
        REQUIRE(commands.findParent(root, "Manager1")->getName() == root->getName());
    }

    SECTION("manager") {

        REQUIRE(commands.manager(nullptr, "CEO_to") == "");

        REQUIRE(commands.manager(root, "nonexistent") == "");

        REQUIRE(commands.manager(root, "Manager1") == root->getName());
        
    }

    SECTION("getTreePerLevel") {
        
        REQUIRE(commands.getTreePerLevel(nullptr).empty());

        std::vector<std::vector<ATPElement*>> result = commands.getTreePerLevel(root);

        std::vector<std::vector<ATPElement*>> output = {{root}, {child1}, {child12}};

        REQUIRE(result == output);
    }

    commands.deallocateTrees();
}