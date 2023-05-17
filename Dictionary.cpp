#include "Node.h"
#include "Person.h"
#include "List.h"
#include "Dictionary.h"
#include <cmath>
#include <stdexcept>

Dictionary::Dictionary() : tableSize(10){
	table = new List*[tableSize];
	for(int x=0;x<tableSize;x++){
		table[x]= new List();
	}
}

Dictionary::Dictionary(int size) : tableSize(size){
	//Special case if someone creates a 0 size table
	if (size <= 0) {
        	throw std::invalid_argument("Invalid table size. Size must be greater than zero.");
    	}
	table = new List*[tableSize];
	for(int x=0;x<tableSize;x++){
		table[x]= new List();
	}
}
Dictionary::~Dictionary(){
	for(int x=0;x<tableSize;x++){
		table[x]= new List();
	}
}
//string folding hashing gotten from:
//https://opendsa-server.cs.vt.edu/ODSA/Books/CS3/html/HashFuncExamp.html
//The link you gave us on the project page
int Dictionary::hash(std::string s, int M) {
  long sum = 0, mul = 1;
  for (int i = 0; i < s.length(); i++) {
    mul = (i % 4 == 0) ? 1 : mul * 256;
    sum += s.at(i) * mul;
  }
  return (int)(std::abs(sum) % M);
}
void Dictionary::insert(Person* data){
	//Special case, inserting nullptr
	if (data == nullptr) {
        	throw std::invalid_argument("Invalid argument. Cannot insert a null pointer.");
    	}
	//we need to hash first, then insert
	
	//hash
	int loc = hash(data->get_name(), tableSize);
	
	//special case if somehow,hash calculates incorrectly out of range
	if (loc < 0 || loc >= tableSize) {
        	throw std::out_of_range("Index out of bounds. Calculated location is outside the table range.");
    	}
	
	//insert
	table[loc]->insert(data);
}
Person* Dictionary::find(Person* data){
	//special case, trying to find nullptr
	if (data == nullptr) {
        	throw std::invalid_argument("Invalid argument. Cannot search for a null pointer.");
    	}
	int loc = hash(data->get_name(), tableSize);
	return table[loc]->find(data);
}
std::string Dictionary::getKeys(){
	std::string allKeys = "";
	try {
		for (int x = 0; x < tableSize; x++) {
		    if (table[x]->length() != 0) {
			allKeys += table[x]->toString();
		    }
		}
	} catch (const std::exception& e) {
		//special case, error with the Person -> get_name()
		throw std::runtime_error("Unhandled exception occurred while getting keys: " + std::string(e.what()));
	}
	return allKeys;
}
