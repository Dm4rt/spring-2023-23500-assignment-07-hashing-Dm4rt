#include "Node.h"
#include "Person.h"
#include "List.h"
#include "Dictionary.h"
#include <cmath>

Dictionary::Dictionary() : tableSize(10){
	table = new List*[tableSize];
	for(int x=0;x<tableSize;x++){
		table[x]= new List();
	}
}

Dictionary::Dictionary(int size) : tableSize(size){
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
int Dictionary::hash(std::string s) {
  long sum = 0, mul = 1;
  for (int i = 0; i < s.length(); i++) {
    mul = (i % 4 == 0) ? 1 : mul * 256;
    sum += s.at(i) * mul;
  }
  return (int)(std::abs(sum) % tableSize);
}
void Dictionary::insert(Person* data){
	//we need to hash first, then insert
	
	//hash
	int loc = hash(data->get_name());
	
	//insert
	//first check for collision
	if(table[loc]->length()==0){
	
	}else{
	
	}
}
Person* Dictionary::find(Person* data){
	return nullptr;
}
std::string getKeys(){
	return "";
}
