#include "Table.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include "Pomiary.h"
Pomiary pomiar;
Table::Table() {
	tab = NULL;
	size = 0;
}

Table::~Table() {
	delete[] tab;
	size = 0;
}

int Table::loadFromFile(string fileName) {
	delete tab;
	ifstream read(fileName);
	int i = 0;
	read >> size;
	tab = new int[size];
	for (int i = 0; i < size; i++)
		read >> tab[i];
	read.close();
	return 0;
}

bool Table::isValueInTable(int value) {
	for (int i = 0; i < size; i++)
		if (tab[i] == value)
			return true;
	return false;
}

void Table::addValue(int index, int value) {
	if (index >= 0 && index <= size) {
		int* tab1 = new int[size + 1];
		int size1 = 0;
		int j = 0;
		bool insert = false;
		for (int i = 0; i < size; ) {
			if (i != index || insert) {
				tab1[j] = tab[i];
				i++;
			}
			else {
				tab1[j] = value;
				insert = true;
			}
			j++;
			size1++;
		}
		if (index == size) {
			tab1[size] = value;
			size1++;
			tab = tab1;
			size = size1;
		}
		else {
			tab = tab1;
			size = size1;
		}
	}
}

void Table::deleteIndex(int index) {
	if (!(index < 0 || index >= size)) {
		int* tab1 = new int[size - 1];
		int size1 = 0;
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != index) {
				tab1[j] = tab[i];
				j++;
				size1++;
			}
		}
		tab = tab1;
		size = size1;
	}
}

void Table::display() {
	for (int i = 0; i < size; i++) {
		cout << tab[i] << " ";
	}
}

void Table::generateTable(int size1) {
	delete tab;
	srand(time(NULL));
	size = size1;
	tab = new int[size];
	for (int i = 0; i < size; i++) {
		tab[i] = rand() % 2000;
	}
}

void Table::deleteValue(int value) {
	int* tab1 = new int[size];
	int size1 = 0;
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (tab[i] != value) {
			tab1[j] = tab[i];
			j++;
			size1++;
		}
	}
	tab = tab1;
	size = size1;
}

void Table::Test() {
	srand(time(NULL));
	double timeTableDelete[10] = { 0 };
	double timeTableDeleteFront[10] = { 0 };
	double timeTableDeleteBack[10] = { 0 };
	double timeTableAdd[10] = { 0 };
	double timeTableAddFront[10] = { 0 };
	double timeTableAddBack[10] = { 0 };
	double timeTableSearch[10] = { 0 };
	int value;
	int index;
	int k = 0;
	for (int j = 1; j <= 10; j++) {
		for (int i = 0; i < 100; i++) {
			value = rand() % 1000;
			index = rand() % (j * 1000 - 10);
			generateTable(j * 1000 * (k + 1));
			pomiar.StartCounter();
			addValue(index, value);
			timeTableAdd[k] += pomiar.GetCounter();
			value = rand() % 1000;
			pomiar.StartCounter();
			addValue(0, value);
			timeTableAddFront[k] += pomiar.GetCounter();
			value = rand() % 1000;
			pomiar.StartCounter();
			addValue(size-1, value);
			timeTableAddBack[k] += pomiar.GetCounter();
			value = rand() % 1000;
			pomiar.StartCounter();
			deleteValue(value);
			timeTableDelete[k] += pomiar.GetCounter();
			pomiar.StartCounter();
			deleteIndex(0);
			timeTableDeleteFront[k] += pomiar.GetCounter();
			pomiar.StartCounter();
			deleteIndex(size-1);
			timeTableDeleteBack[k] += pomiar.GetCounter();
			value = rand() % 1000;
			pomiar.StartCounter();
			isValueInTable(100000);
			timeTableSearch[k] += pomiar.GetCounter();
			system("cls");
			cout << "test zakoñczony" << endl;
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < 10; i++) {
		timeTableAdd[i] *= 10000;
		timeTableAddFront[i] *= 10000;
		timeTableAddBack[i] *= 10000;
		timeTableDelete[i] *= 10000;
		timeTableDeleteFront[i] *= 10000;
		timeTableDeleteBack[i] *= 10000;
		timeTableSearch[i] *= 10000;
		cout << "Œredni czas dla " << (i + 1) * 1000 * k << " próbek" << endl;
		cout << "DODAJ: " << timeTableAdd[i] << " ns" << endl;
		cout << "DODAJ DO PRZODU: " << timeTableAddFront[i] << " ns" << endl;
		cout << "DODAJ DO TY£U: " << timeTableAddBack[i] << " ns" << endl;
		cout << "USUN: " << timeTableDelete[i] << " ns" << endl;
		cout << "USUN NA POCZ¥TKU: " << timeTableDeleteFront[i] << " ns" << endl;
		cout << "USUN NA KONCU: " << timeTableDeleteBack[i] << " ns" << endl;
		cout << "USUN NA KONCU: " << timeTableSearch[i] << " ns" << endl;
		k++;
	}
}