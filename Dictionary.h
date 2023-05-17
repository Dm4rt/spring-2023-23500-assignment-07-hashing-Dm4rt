#pragma once
#include "List.h"
#include "Person.h"
#include "Node.h"
#include <memory>
#include <string>

class Dictionary{
	private:
		int tableSize;
    		List** table;
	public:
		Dictionary();
		Dictionary(int size);
		~Dictionary();
		int hash(std::string s, int M);
		void insert(Person* data);
		Person* find(Person* data);
		std::string getKeys();
		
};
