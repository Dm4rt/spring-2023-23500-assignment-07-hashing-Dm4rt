#pragma once
#include <iostream>
#include "Node.h"
#include "Person.h"

class List{
 private:
  Node *head;
 public:
  List();
  ~List();
  void insert(Person *data);
  void insert(int loc, Person *data); //0 indexed
  int length();
  Person* find(Person *data);

  std::string toString(); // for testing purposes
  void remove(int loc);

  /*
    

    

  */
  
  

};
