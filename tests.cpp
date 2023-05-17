#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include "doctest.h"
#include "Node.h"
#include "Dictionary.h"
#include "Person.h"
#include "List.h"

TEST_CASE("Dictionary operations") {
    // Create a dictionary
    Dictionary dict(5);

    SUBCASE("Insert and find") {
        Person person1("John", "Doe", 123);
        Person person2("Jane", "Smith", 456);

        // Insert persons into the dictionary
        dict.insert(&person1);
        dict.insert(&person2);

        // Find persons in the dictionary
        Person* foundPerson1 = dict.find(&person1);
        Person* foundPerson2 = dict.find(&person2);

        CHECK(foundPerson1 != nullptr);
        CHECK(foundPerson2 != nullptr);
        CHECK_EQ(foundPerson1->get_name(), "Doe, John");
        CHECK_EQ(foundPerson1->get_id(), 123);
        CHECK_EQ(foundPerson2->get_name(), "Smith, Jane");
        CHECK_EQ(foundPerson2->get_id(), 456);
    }

    SUBCASE("Get keys") {
        Person person1("John", "Doe", 123);
        Person person2("Jane", "Smith", 456);

        // Insert persons into the dictionary
        dict.insert(&person1);
        dict.insert(&person2);

        // Get all keys
        std::string keys = dict.getKeys();

        // Check if both keys are present
        CHECK(keys.find("Doe, John") != std::string::npos);
        CHECK(keys.find("Smith, Jane") != std::string::npos);
    }

    SUBCASE("Hashing and collision") {
        Person person1("John", "Doe", 123);
        Person person2("Jane", "Smith", 456);
        Person person3("Alice", "Johnson", 789);

        // Insert persons with the same hash into a small dictionary to force collision
        Dictionary smallDict(2);
        smallDict.insert(&person1);
        smallDict.insert(&person2);
        smallDict.insert(&person3);

        // Find persons in the small dictionary
        Person* foundPerson1 = smallDict.find(&person1);
        Person* foundPerson2 = smallDict.find(&person2);
        Person* foundPerson3 = smallDict.find(&person3);

        CHECK(foundPerson1 != nullptr);
        CHECK(foundPerson2 != nullptr);
        CHECK(foundPerson3 != nullptr);
        CHECK_EQ(foundPerson1->get_name(), "Doe, John");
        CHECK_EQ(foundPerson1->get_id(), 123);
        CHECK_EQ(foundPerson2->get_name(), "Smith, Jane");
        CHECK_EQ(foundPerson2->get_id(), 456);
        CHECK_EQ(foundPerson3->get_name(), "Johnson, Alice");
        CHECK_EQ(foundPerson3->get_id(), 789);
    }
    
    //Testing exceptions and throws
    SUBCASE("Exceptions and Throws"){
    	Dictionary dict;
    	Person person1("John", "Doe", 123);
    	Person person2("Jane", "Smith", 456);
    	dict.insert(&person1);
    	CHECK_THROWS_AS(dict.insert(nullptr), std::invalid_argument);
    	CHECK_THROWS_AS(dict.find(nullptr), std::invalid_argument);
    	CHECK_THROWS_AS(dict.find(&person2), std::out_of_range);
    }
}


