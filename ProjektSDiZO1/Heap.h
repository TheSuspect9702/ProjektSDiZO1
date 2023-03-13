#pragma once
#include <string>

class Heap {
	int* arr = new int[1000];
	int size;
public:
	Heap();
	~Heap();
	void display();
	int loadFromFile(std::string fileName);
	bool isValueInHeap(int value);
	void addValue(int index, int value);
	//void deleteValue(int value);
	void deleteIndex(int index);
	void generateHeap(int size);
	void floydHeapify(int i);
};