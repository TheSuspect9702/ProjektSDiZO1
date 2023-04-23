#pragma once
#include <string>
using namespace std;
class BRT
{
	BRT * father;
	BRT * left;
	BRT * right;
	int value;
	char color; // R - Czerwony B - Czarny 
public:
	BRT();
	~BRT();
	bool isValueInTree(int value);
	void loadFromFile(string fileName);
	void printBRT(string sp, string sn, BRT* p);
	void displayTree();
	void addValue(int value);
	void revalueTree(BRT* A);
	void removeValue(int value);
	void generateTree(int size);
	void rotateLeft(BRT * temp);
	void rotateRight(BRT * temp);
private:
	BRT * root;
	BRT* S;
};

