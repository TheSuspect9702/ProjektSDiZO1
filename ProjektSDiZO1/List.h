#pragma once
#include <string>
class List {
	int value;
	List* next;
	List* prev;
public:
	List();
	~List();
	void display();
	bool isValueInList(int value);
	void addValue(int index, int value);
	void deleteValue(int value);
	void generateList(int size);
	void addValueFromFile(int value1);
private:
	List* head;
	List* tail;
};