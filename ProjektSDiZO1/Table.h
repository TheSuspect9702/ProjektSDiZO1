#pragma once

#include <string>

class Table {
	int* tab;
	int size;
public:
	Table();
	~Table();
	void display();
	int loadFromFile(std::string fileName);
	bool isValueInTable(int value);
	void addValue(int index, int value);
	void deleteValue(int value);
	void deleteIndex(int index);
	void generateTable(int size);
	void Test();
};
