#include "Heap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <Windows.h>
using namespace std;
Heap::Heap() {

}

Heap::~Heap() {
}
//Jeszcze do dopracowania

void Heap::display() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int Heap::loadFromFile(string fileName) {
	ifstream file(fileName);
	file >> size;
	for (int i = 0; i < size; i++) {
		file >> arr[i];
	}
	file.close();
	for (int i = (size / 2) - 1; i >= 0; i--)
		floydHeapify(i);
	return 1;
}

void Heap::floydHeapify(int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		floydHeapify(largest);
	}
}

bool Heap::isValueInHeap(int value) {
	return true;
}
//dodac jakas 
void Heap::addValue(int index, int value) {
}
//ZMIENIC USUWANIE
//void Heap::deleteValue(int value) {
//}
//ZMIENIC NA WYBOR CO USUNAC
void Heap::deleteIndex(int index) {
	int* arr1 = new int[1000];
	for (int i = 0; i < size - 1; i++) {
		arr1[i] = arr[i + 1];
	}
	delete arr;
	arr = arr1;
	size--;
	delete arr1;
	floydHeapify(0);
}
//nie tworzy sie odpowiednio posortowanie 
void Heap::generateHeap(int size1) {
	srand(time(NULL));
	size = size1;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 2000;
	}
	for (int i = (size / 2) - 1; i >= 0; i--)
		floydHeapify(i);
}