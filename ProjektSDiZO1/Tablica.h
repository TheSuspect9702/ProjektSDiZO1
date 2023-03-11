#pragma once
//Tablica.h
#include <string>

class Tablica {
	int* tab;
	int size;
public:
	Tablica();
	~Tablica();
	void display();
	int loadFromFile(std::string fileName);
	bool isValueInTable(int value);
	void addValue(int index, int value);
	void deleteValue(int value);
	void deleteIndex(int index);
	void generateTable(int size);
};
