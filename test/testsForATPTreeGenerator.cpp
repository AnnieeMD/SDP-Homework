#include "catch.hpp"
#include "../src/atp/include/ATPTreeGenerator.hpp"

TEST_CASE("ATPTreeGenerator Tests", "[ATPTreeGenerator]") {

    Generator test;

    SECTION("isValidName") {
        REQUIRE(test.isValidName("JohnDoe") == true);
        REQUIRE(test.isValidName("John Doe") == false);
        REQUIRE(test.isValidName("John-Doe") == false);
    }

    SECTION("isElementInVector") {
        std::vector<std::string> vec = {"Alice", "Bob", "Charlie"};
        REQUIRE(test.isElementInVector(vec, "Alice") == true);
        REQUIRE(test.isElementInVector(vec, "David") == false);
    }

    SECTION("numberOfOccurrences") {
        std::vector<std::string> vec = {"Alice", "Bob", "Charlie", "Alice"};
        REQUIRE(Generator::numberOfOccurrences(vec, "Alice") == 2);
        REQUIRE(Generator::numberOfOccurrences(vec, "David") == 0);
    }

    SECTION("readFromFile") {
        
        std::ofstream tempFile("test_file.txt");
        tempFile << "Alice-Bob\nCharlie-David\n";
        tempFile.close();

        std::vector<std::string> lines = test.readFromFile("test_file.txt");

        REQUIRE(lines.size() == 2);
        REQUIRE(lines[0] == "Alice-Bob");
        REQUIRE(lines[1] == "Charlie-David");

        
        std::remove("test_file.txt");
    }

    SECTION("findChild") {
        ATPElement root("CEO");
        root.addChild("Manager1");
        root.addChild("Manager2");

        ATPElement* result = test.findChild(&root, "Manager1");

        REQUIRE(result != nullptr);
        REQUIRE(result->getName() == "Manager1");
    }

    SECTION("GenerateTree") {
        std::vector<std::string> input = {"CEO_to-Manager1", "Manager1-Employee1"};
        ATPElement* root = test.GenerateTree(input);

        REQUIRE(root != nullptr);
        REQUIRE(root->getName() == "CEO_to");
        REQUIRE(root->getChildren().size() == 1);

        ATPElement* manager1 = root->getChildren()[0];
        REQUIRE(manager1->getName() == "Manager1");
        REQUIRE(manager1->getChildren().size() == 1);

        REQUIRE(test.findChild(root, "Manager1")->getName() == "Manager1");

        root->deallocate(root);
    }
}
