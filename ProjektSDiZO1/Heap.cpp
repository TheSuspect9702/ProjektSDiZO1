#include "Heap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include "Pomiary.h"
using namespace std;
string cr, cl, cp;
Pomiary pomiar2;
Heap::Heap() {
	size = 0;
}

Heap::~Heap() {
	size = 0;
	delete arr;
}

void printHeap(string sp, string sn, int v, int* arr, int size) {
	string s;

	if (v < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printHeap(s + cp, cr, 2 * v + 2, arr,size);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << arr[v] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printHeap(s + cp, cl, 2 * v + 1, arr,size);
	}

}

void Heap::display() {
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	printHeap("", "", 0, arr, n);
}

int Heap::loadFromFile(string fileName) {
	ifstream file(fileName);
	file >> size;
	size *= 10;
	arr = new int[size];
	for (int i = 0; i < size/10; i++) {
		n++;
		file >> arr[i];
	}
	file.close();
	for (int i = (n / 2) - 1; i >= 0; i--)
		floydHeapify(i);
	return 1;
}

void Heap::floydHeapify(int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		floydHeapify(largest);
	}
}

void Heap::Tests()
{
	srand(time(NULL));
	double timeTableDelete[10] = { 0 };
	double timeTableAdd[10] = { 0 };
	double timeTableSearch[10] = { 0 };
	int value;
	int index;
	int k = 0;
	for (int j = 1; j <= 10; j++) {
		for (int i = 0; i < 100; i++) {
			value = rand() % 2000;
			generateHeap(j * 1000 * (k + 1));
			pomiar2.StartCounter();
			addValue(value);
			timeTableAdd[k] += pomiar2.GetCounter();
			index = rand() % (j * 1000 - 10);
			pomiar2.StartCounter();
			deleteIndex(index);
			timeTableDelete[k] += pomiar2.GetCounter();
			pomiar2.StartCounter();
			value = rand() % 2000;
			isValueInHeap(value);
			timeTableSearch[k] += pomiar2.GetCounter();
			system("cls");
			cout << "test zakoñczony" << endl;
			delete arr;
			n = 0;
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < 10; i++) {
		timeTableAdd[i] *= 10000;
		timeTableDelete[i] *= 10000;
		timeTableSearch[i] *= 10000;
		cout << "Œredni czas dla " << (i + 1) * 1000 * k << " próbek" << endl;
		cout << "DODAJ: " << timeTableAdd[i] << " ms" << endl;
		cout << "USUN: " << timeTableDelete[i] << " ms" << endl;
		cout << "WYSZUKAJ: " << timeTableSearch[i] << " ms" << endl;
		k++;
	}
}

bool Heap::isValueInHeap(int value) {
	for (int i = 0; i < n; i++) 
		if (arr[i] == value)
			return true;
	return false;
}

void Heap::addValue(int value) {
	int i;
	i = ++n;
	arr[i-1] = value;
	if(n!=1)
	floydHeapifyDown((n / 2) - 1);
}
void Heap::floydHeapifyDown(int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		if (i != 1 && i != 2 && i >0)
			floydHeapifyDown((i / 2) - 1);
		else if (i == 1 || i == 2)
			floydHeapifyDown(0);
	}
}
void Heap::deleteIndex(int index) {
	if (index < n) {
		int temp = arr[n-1];
		arr[index] = arr[index * 2 + 1];
		arr[index * 2 + 1] = temp;
		n--;
		floydHeapify(index);
		floydHeapify(index * 2 + 1);
	}
}

void Heap::generateHeap(int size1) {
	srand(time(NULL));
	size = size1*10;
	arr = new int[size];
	for (int i = 0; i < size/10; i++) {
		n++;
		arr[i] = rand() % 2000;
	}
	for (int i = (n / 2) - 1; i >= 0; i--)
		floydHeapify(i);
}