#pragma once
#include <string>
class List {
	int value;
	int size;
	List* next;
	List* prev;
public:
	List();
	void DList();
	void loadListFromFile(std::string fileName);
	void display();
	bool isValueInList(int value);
	void addValue(int index, int value);
	void deleteValue(int value);
	void generateList(int size);
	void addValueFromFile(int value1);
	void deleteIndex(int index);
	void Test();
private:
	List* head;
	List* tail;
};