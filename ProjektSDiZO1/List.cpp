#include "List.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include "Pomiary.h"
Pomiary pomiar1;


List::List() {
	value = 0;
	prev = nullptr;
	next = nullptr;
}

List::~List() {
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
	delete current;
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
		cout << "index poza zasiêgiem" << endl;
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
	if (current == nullptr && i == index) {
		tail->next = tempList;
		tempList->prev = tail;
		tail = tempList;
		return;
	}
	tempList->next = current;
	tempList->prev = current->prev;
	if (current->prev != nullptr) {		//ustawienie nowego obiektu w liscie
		current->prev->next = tempList;
	}
	current->prev = tempList;
}

void List::deleteValue(int value) {
	List* current = head;
	while (current != nullptr) {
		if (current->value == value) {
			if (current == head && current == tail) {
				head = nullptr;
				tail = nullptr;
				delete current;
				break;
			}
			if (current == head) {
				head = current->next;
				current->next->prev = nullptr;
				delete current;
				break;
			}
			if (current == tail) {
				tail = current->prev;
				current->prev->next = nullptr;
				delete current;
				break;
			}
			else {
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
}

void List::display() {
	List* current = head;
	while (current != nullptr) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
	current = tail;
	while (current != nullptr) {
		cout << current->value << " ";
		current = current->prev;
	}
}

void List::clearList() {

}

void List::generateList(int size) {
	srand(time(NULL));
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
	/*if (tail != nullptr)
		~List();
	if (head != nullptr)
		~List();*/
	ifstream read(fileName);
	int size = 0;
	int value;
	string line;
	getline(read, line);
	size = stoi(line);
	for (int i = 0; i < size; i++) {
		getline(read, line);
		value = stoi(line);
		addValueFromFile(value);
	}
	read.close();
}

void List::Test() {
	srand(time(NULL));
	double timeListDelete[10] = { 0 };
	double timeListAdd[10] = { 0 };
	int value;
	int index;
	int k = 0;
	for (int j = 1; j <= 10; j++) {
		for (int i = 0; i < 10; i++) {
			value = rand() % 1000;
			index = rand() % (j * 1000 - 10);
			generateList(j * 1000 * (k + 1));
			pomiar1.StartCounter();
			addValue(index, value);
			timeListAdd[k] += pomiar1.GetCounter();
			value = rand() % 1000;
			index = rand() % (j * 1000 - 10);
			pomiar1.StartCounter();
			deleteValue(value);
			timeListDelete[k] += pomiar1.GetCounter();
			system("cls");
			cout << "test zakoñczony" << endl;
		}
		k++;
	}
	k = 1;
	for (int i = 0; i < 10; i++) {
		timeListAdd[i] /= 100;
		timeListDelete[i] /= 100;
		cout << "Œredni czas dla " << (i + 1) * 1000 * k << " próbek" << endl;
		cout << "DODAJ: " << timeListAdd[i] << endl;
		cout << "USUN: " << timeListDelete[i] << endl;
		k++;
	}
}