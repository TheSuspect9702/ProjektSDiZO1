#pragma once
#include <string>

class Heap {
	int* arr;
	int size;
	int n;
public:
	Heap();
	~Heap();
	void display();
	int loadFromFile(std::string fileName);
	bool isValueInHeap(int value);
	void addValue(int value);
	//void deleteValue(int value);
	void deleteIndex(int index);
	void generateHeap(int size);
	void floydHeapify(int i);
	void floydHeapifyDown(int i);
	void Tests();
};


