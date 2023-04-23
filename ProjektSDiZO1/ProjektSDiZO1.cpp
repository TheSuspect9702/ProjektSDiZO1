// ProjektSDiZO1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "Table.h"
#include "List.h"
#include "Heap.h"
#include <iostream>
#include "BRT.h"



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

Table	myTab; 
List*	myList = new List();
Heap	myHeap;
BRT		myTree;
//Zapytac o co tu chodzi z tymi funkcjami

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

		case '7': 
			myTab.Test();
			break;
		}

	} while (opt != '0');
	myTab.~Table();
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

		case '7': 
			myList->Test();
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
			cout << " podaj index:";
			cin >> index;
			myHeap.deleteIndex(index);
			myHeap.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj wartość:";
			cin >> value;
			myHeap.addValue(value);
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

		case '7': 
			myHeap.Tests();
			break;
		}

	} while (opt != '0');
}

void menu_BRT() {
	char opt;
	string fileName;
	int index, value;
	do {
		displayMenu("--- Drzewo Czerwono Czarne ---");
		cin >> opt;
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwę zbioru:";
			cin >> fileName;
			myTree.loadFromFile(fileName);
			myTree.displayTree();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj wartosc:";
			cin >> value;
			myTree.removeValue(value);
			myTree.displayTree();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj wartość:";
			cin >> value;
			myTree.addValue(value);
			myTree.displayTree();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (myTree.isValueInTree(value))
				cout << "podana wartosc jest w kopcu";
			else
				cout << "podanej wartosci NIE ma w kopcu";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów kopca:";
			cin >> value;
			myTree.generateTree(value);
			myTree.displayTree();
			break;

		case '6':  //tutaj wyświetlanie tablicy
			myTree.displayTree();
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
		cout << "4.Drzewo BRT" << endl;
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
		case '4':
			menu_BRT();
			break;
		}
	} while (option != '0');
	myTab.~Table();
	return 0;
}

