// ProjektSDiZO1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "Tablica.h"
#include "List.h"
#include "Heap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;
void displayMenu(string info) {
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

Tablica myTab; 
List* myList = new List();
Heap myHeap;

void menu_table() {
	char opt;
	string fileName;
	int index, value;
	do {
		displayMenu("--- TABLICA ---");
		cin >> opt;
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwę zbioru:";
			cin >> fileName;
			myTab.loadFromFile(fileName);
			myTab.display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj index:";
			cin >> index;
			myTab.deleteIndex(index);
			myTab.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj waertość:";
			cin >> value;

			myTab.addValue(index, value);
			myTab.display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (myTab.isValueInTable(value))
				cout << "podana wartosc jest w tablicy";
			else
				cout << "podanej wartosci NIE ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów tablicy:";
			cin >> value;
			myTab.generateTable(value);
			myTab.display();
			break;

		case '6':  //tutaj wyświetlanie tablicy
			myTab.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego 
			// można sobie tu dodać własne dodatkowe case'y
			break;
		}

	} while (opt != '0');
}

void menu_list() {
	char opt;
	string fileName;
	int index, value;
	do {
		displayMenu("--- LISTA ---");
		cin >> opt;
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwę zbioru:";
			cin >> fileName;
			myList->loadListFromFile(fileName);
			myList->display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj liczbe:";
			cin >> value;
			myList->deleteValue(value);
			myList->display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj wartość:";
			cin >> value;
			myList->addValue(index, value);
			myList->display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (myList->isValueInList(value))
				cout << "podana wartosc jest w liscie";
			else
				cout << "podanej wartosci NIE ma w liscie";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów listy:";
			cin >> value;
			myList->generateList(value);
			myList->display();
			break;

		case '6':  //tutaj wyświetlanie tablicy
			myList->display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego 
			// można sobie tu dodać własne dodatkowe case'y
			break;
		}

	} while (opt != '0');
}

void menu_heap() {
	char opt;
	string fileName;
	int index, value;
	do {
		displayMenu("--- KOPIEC ---");
		cin >> opt;
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwę zbioru:";
			cin >> fileName;
			myHeap.loadFromFile(fileName);
			myHeap.display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj liczbe:";
			cin >> value;
			myHeap.deleteValue(value);
			myHeap.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj wartość:";
			cin >> value;
			myHeap.addValue(index, value);
			myHeap.display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (myHeap.isValueInHeap(value))
				cout << "podana wartosc jest w kopcu";
			else
				cout << "podanej wartosci NIE ma w kopcu";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów kopca:";
			cin >> value;
			myHeap.generateHeap(value);
			myHeap.display();
			break;

		case '6':  //tutaj wyświetlanie tablicy
			myHeap.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego 
			// można sobie tu dodać własne dodatkowe case'y
			break;
		}

	} while (opt != '0');
}

int main(int argc, char* argv[]) {

	char option;
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		cin >> option;
		cout << endl;

		switch (option) {
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;
		}

	} while (option != '0');
	myTab.~Tablica();
	return 0;
}

Tablica::Tablica() {
	myTab.tab = NULL;
	myTab.size = 0;
}

Tablica::~Tablica() {
	delete[] myTab.tab;
	myTab.size = 0;
}
//dodac jakos warunek na to czy tablica wgl zostala juz stworzona
int Tablica::loadFromFile(string fileName) {
	ifstream read(fileName);
	int i = 0;
	while (!read.eof()) {
		if (i != 0)
			read >> myTab.tab[i-1];
		else {
			read >> size;
			myTab.size = size;
			myTab.tab = new int[size];
		}
		i++;
	}
	read.close();
	return 0;
}

bool Tablica::isValueInTable(int value) {
	for (int i = 0; i < size; i++)
		if (tab[i] == value)
			return true;
	return false;
}

void Tablica::addValue(int index, int value) {
	if (!(index < 0 || index >= size)) {
		int* tab1 = new int[myTab.size];
		int size1 = 0;
		int j = 0;
		bool insert = false;
		for (int i = 0; i < myTab.size; ) {
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
		delete myTab.tab;
		myTab.size = size1;
		myTab.tab = new int[size];
		for (int i = 0; i < size; i++)
			myTab.tab[i] = tab1[i];
	}
	else {
		cout << "Podany indeks jest niepoprawny";
	}
}

void Tablica::deleteIndex(int index) {
	if (!(index < 0 || index >= size)) {
		int* tab1 = new int[myTab.size];
		int size1 = 0;
		int j = 0;
		for (int i = 0; i < myTab.size; i++) {
			if (i != index) {
				tab1[j] = tab[i];
				j++;
				size1++;
			}
		}
		delete myTab.tab;
		myTab.size = size1;
		myTab.tab = new int[size];
		for (int i = 0; i < size; i++)
			myTab.tab[i] = tab1[i];
	}
	else 
		cout << "Podany indeks jest niepoprawny";
}

void Tablica::display() {
	for (int i = 0; i < size; i++) {
		cout << myTab.tab[i] << " ";
	}
}

void Tablica::generateTable(int size) {
	srand(time(NULL));
	myTab.size = size;
	myTab.tab = new int[size];
	for (int i = 0; i < size; i++) {
		myTab.tab[i] = rand() % 2000;
	}
}

void Tablica::deleteValue(int value) {
	int* tab1 = new int[myTab.size];
	int size1 = 0;
	int j = 0;
	for (int i = 0; i < myTab.size; i++) {
		if (tab[i] != value) {
			tab1[j] = tab[i];
			j++;
			size1++;
		}
	}
	delete myTab.tab;
	myTab.size = size1;
	myTab.tab = new int[size];
	for (int i = 0; i < size; i++)
		myTab.tab[i] = tab1[i];
}

List::List() {
	value = 0;
	prev = nullptr;
	next = nullptr;
}
//zapytac sie czy clearList to moze byc po prostu ten destruktor
List::~List() {
	clearList();
}

bool List::isValueInList(int value) {
	List* current = head;
	while (current != nullptr) {
		if (current->value == value)
			return true;
		current = current->next;
	}
	return false;
}   

void List::addValueFromFile(int value1) {
	List* tempList = new List();
	tempList->value = value1;

	if (tail != nullptr) {
		tail->next = tempList;
		tempList->prev = tail;
	}

	if (head == nullptr) {
		head = tempList;
	}

	tail = tempList;
}

void List::addValue(int index, int value1) {
	List* tempList = new List();
	tempList->value = value1;
	if (head == nullptr && index != 0) {
		cout << "index poza zasięgiem" << endl;
		return;
	}
	if (index == 0) {
		tempList->next = head;	//wstawienie nowej wartosci do listy i ustawienie jej nastepcy jako stara "glowe"
		if (head != nullptr) {
			head->prev = tempList;
		}
		head = tempList;	//wstawienie obiektu na poczatek listy 
		if (tail == nullptr) {
			tail = tempList;
		}
		return;
	}
	//co kiedy nie jest to na poczatku
	List* current = head;
	int i = 0;
	while (current != nullptr && i < index) {		//przejscie do odpowiedniego miejsca
		current = current->next;
		i++;
	}
	
	if (current == nullptr) {		//sprawdzenie czy nie wyszlismy poza liste
		cout << "index poza zasięgiem" << endl;
		return;
	}
	tempList->next = current;
	tempList->prev = current->prev;
	if (current->prev != nullptr) {		//ustawienie nowego obiektu w liscie
		current->prev->next = tempList;
	}
	current->prev = tempList;
	if (current == head) {
		head = tempList;
	}
}

void List::deleteValue(int value) {
	List* current = head;
	while (current != nullptr) {
		if (current == head && current == tail && current->value == value) {
			head = nullptr;
			tail = nullptr;
			delete current;
			break;
		}
		if (current == head && current->value == value) {
			head = current->next;
			current->next->prev = nullptr;
			delete current;
			break;
		}
		if (current == tail && current->value == value) {
			tail = current->prev;
			current->prev->next = nullptr;
			delete current;
			break;
		}
		if (current->value == value) {
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			break;
		}
			current = current->next;
		if (current == nullptr) {
			cout << "Nie znaleziono liczby ktora chciales usunac" << endl;
		}
	}
}	 

void List::display() {
	List* current = myList->head;
	while (current != nullptr) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
	current = myList->tail;
	while (current != nullptr) {
		cout << current->value << " ";
		current = current->prev;
	}
}

void List::clearList() {
	List* next1;
	List* current = head;
	if (head != nullptr || tail != nullptr) {
		while (current != nullptr) {
			next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
		tail = nullptr;
	}
}

void List::generateList(int size) {
	clearList();
	for (int i = 0; i < size; i++) {
		List* tempList = new List();
		tempList->value = rand() % 1000;
		if (head == nullptr) {
			head = tempList;
			tail = tempList;
		}
		else {
			tail->next = tempList;
			tempList->prev = tail;
			tail = tempList;
		}
	}
}	 

void List::loadListFromFile(string fileName) {
	clearList();
	ifstream read(fileName);
	int size = 0;
	int value;
	string line;
	getline(read, line);
	size = stoi(line);
	for (int i = 0; i < size; i++) {
		getline(read, line);
		value = stoi(line);
		myList->addValueFromFile(value);
	}
	read.close();
}

Heap::Heap() {

}

Heap::~Heap() {
}

void Heap::display() {
	for (int i=0; i<size; i++)
	cout << arr[i] << " ";
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

void Heap::addValue(int index, int value) {
}

void Heap::deleteValue(int value) {
}

void Heap::deleteIndex(int index) {
}

void Heap::generateHeap(int size) {
}