#include "BRT.h"
#include <iostream>
#include <fstream>
string cr1, cl1, cp1;
using namespace std;

BRT::BRT()
{
}

BRT::~BRT()
{
}

bool BRT::isValueInTree(int value)
{
	return false;
}

void BRT::loadFromFile(string fileName)
{
    int size;
    int val;
    ifstream read(fileName);
    int i = 0;
    read >> size;
    for (int i = 0; i < size; i++) {
        read >> val;
        addValue(val);
    }
    read.close();
}
void BRT::printBRT(string sp, string sn, BRT * p)
{
    string t;

    if (p != NULL)
    {
        t = sp;
        if (sn == cr1) t[t.length() - 2] = ' ';
        printBRT(t + cp1, cr1, p->right);

        t = t.substr(0, sp.length() - 2);
        cout << t << sn << p->color << ":" << p->value << endl;

        t = sp;
        if (sn == cl1) t[t.length() - 2] = ' ';
        printBRT(t + cp1, cl1, p->left);
    }
}

void BRT::displayTree()
{
    cr1 = cl1 = cp1 = "  ";
    cr1[0] = 218; cr1[1] = 196;
    cl1[0] = 192; cl1[1] = 196;
    cp1[0] = 179;
    printBRT("", "", root);
}

void BRT::addValue(int value)
{
    BRT* uncle = new BRT();
    BRT* temp = new BRT();
    temp->value = value;
    temp->father = NULL;
    temp->right = NULL;
    temp->left = NULL;
    if (root == NULL) {
        temp->color = 'B';
        root = temp;
    }
    else {
        temp->color = 'R';
        BRT* current = root;
           while (current->left != NULL || current->right != NULL) {
                if (current->value > temp->value) {
                    if (current->left == NULL) {
                        current->left = temp;
                        temp->father = current;
                        break;
                    }
                    else
                        current = current->left;
                }
                else if (current->value < temp->value) {
                    if (current->right == NULL) {
                        current->right = temp;
                        temp->father = current;
                        break;
                    }
                    else
                        current = current->right;
                }
                else { //kiedy jest rowna wartosc
                    if (current->left == NULL) {
                        current->left = temp;
                        temp->father = current;
                        break;
                    }
                    else if (current->right == NULL) {
                        current->right = temp;
                        temp->father = current;
                        break;
                    }
                    else
                        current = current->right;
                }
           }
           if (current->left == NULL && current->right == NULL) {
               if (current->value > temp->value) {
                   if (current->left == NULL) {
                       current->left = temp;
                       temp->father = current;
                   }
                   else
                       current = current->left;
               }
               else if (current->value < temp->value) {
                   if (current->right == NULL) {
                       current->right = temp;
                       temp->father = current;
                   }
                   else
                       current = current->right;
               }
               else { //kiedy jest rowna wartosc
                   if (current->left == NULL) {
                       current->left = temp;
                       temp->father = current;
                   }
                   else if (current->right == NULL) {
                       current->right = temp;
                       temp->father = current;
                   }
                   else
                       current = current->right;
               }
           }
        while ((temp != root) && (temp->father->color == 'R'))
        {
            if (temp->father == temp->father->father->left) //lewa galaz
            {
                uncle = temp->father->father->right;
                if (uncle == NULL) { //ten przypadek dzial chyba
                   /* temp->father->color = 'B'; 
                    temp->father->father->color = 'R';
                    rotateRight(temp->father->father);*/
                    if (temp == temp->father->right) {
                        temp = temp->father;
                        rotateLeft(temp);
                    }
                    if (temp->father != NULL && temp->father->father != NULL) {
                        if (temp->father->color == 'B')
                            temp->father->color = 'R'; // Przypadek 3
                        else
                            temp->father->color = 'B';
                        if (temp->father->father->color == 'B')
                            temp->father->father->color = 'R'; // Przypadek 3
                        else
                            temp->father->father->color = 'B';
                        rotateRight(temp->father->father);
                    }
                }
                else {
                    if (uncle->color == 'R') // Przypadek 1
                    {
                        temp->father->color = 'B';
                        uncle->color = 'B';
                        temp->father->father->color = 'R';
                        temp = temp->father->father;
                        continue;
                    }

                    else if (temp == temp->father->right) // Przypadek 2
                    {
                        temp = temp->father;
                        rotateLeft(temp);
                    }

                    if (temp->father != NULL && temp->father->father != NULL) {
                        temp->father->color = 'B'; // Przypadek 3
                        temp->father->father->color = 'R';
                        rotateRight(temp->father->father);
                    }
                    break;
                }
            }
            else
            {                  // Przypadki lustrzane
                uncle = temp->father->father->left;
                if (uncle == NULL) { //ten przypadek dzial 
                   /* temp->father->color = 'B';
                    temp->father->father->color = 'R';*/
                    if (temp == temp->father->left) {
                        temp = temp->father;
                        rotateRight(temp);
                    }
                    if (temp->father != NULL && temp->father->father != NULL) {
                        if (temp->father->color == 'B')
                            temp->father->color = 'R'; // Przypadek 3
                        else
                            temp->father->color = 'B';
                        if (temp->father->father->color == 'B')
                            temp->father->father->color = 'R'; // Przypadek 3
                        else
                            temp->father->father->color = 'B';
                        rotateLeft(temp->father->father);
                    }
                }
                else {
                    if (uncle->color == 'R') // Przypadek 1
                    {
                        temp->father->color = 'B';
                        uncle->color = 'B';
                        temp->father->father->color = 'R';
                        temp = temp->father->father;
                        continue;
                    }

                    else if (temp == temp->father->left) // Przypadek 2
                    {
                        temp = temp->father;
                        rotateRight(temp);
                    }
                    if (temp->father != NULL && temp->father->father != NULL) {
                        temp->father->color = 'B'; // Przypadek 3
                        temp->father->father->color = 'R';
                        rotateLeft(temp->father->father);
                    }
                    break;
                }
            }
        }
    }
        root->color = 'B';
}

void BRT::revalueTree(BRT* B) { 
    while (true) {
        if (B->right == NULL && B->left != NULL && B->left->color < 'R') {
            if (B->left->color == 'R') {
                rotateRight(B);
                B->father->color = B->color;
                B->color = 'R';
                continue;
            }
            else if (B->left->right != NULL && B->left->left != NULL && B->left->color == 'B' && B->left->right->color == 'B' && B->left->left->color == 'B') {
                B->color += 'B';
                B->left->color = 'R';
                B = B->father;
                continue;
            }
            else if (B->left->right != NULL && B->left->left != NULL && B->left->color == 'B' && B->left->right->color == 'R' && B->left->left->color == 'B') {
                rotateLeft(B->left);
                B->left->left->color = B->left->color;
                B->left->color = 'R';
            }
            rotateRight(B);
            B->father->color = B->color;
            B->color = 'B';
            B->father->left->color = 'B';
            break;
        }
        else if (B->left == NULL && B->right != NULL && B->right->color < 'R') {
            if (B->right->color == 'R') {
                rotateLeft(B);
                B->father->color = B->color;
                B->color = 'R';
                continue;
            }
            else if (B->right->right != NULL && B->right->left != NULL && B->right->color == 'B' && B->right->left->color == 'B' && B->right->right->color == 'B') {
                B->color += 'B';
                B->right->color = 'R';
                B = B->father;
                continue;
            }
            else if (B->right->right != NULL && B->right->left != NULL && B->right->color == 'B' && B->right->left->color == 'R' && B->right->right->color == 'B') {
                rotateRight(B->right);
                B->right->right->color = B->right->color;
                B->right->color = 'R';
            }
            rotateLeft(B);
            B->father->color = B->color;
            B->color = 'B';
            B->father->right->color = 'B';
            break;
        }
        else if (B->right->color > 'R') { //jesli podowjny kolor ma prawy syn 
            if (B->left->color == 'R') {
                rotateRight(B);
                B->father->color = B->color;
                B->color = 'R';
                continue;
            }
            else if (B->left->color == 'B' && B->left->right->color == 'B' && B->left->left->color == 'B') {
                B->right->color -= 'B';
                B->color += 'B';
                B->left->color = 'R';
                B = B->father;
                continue;
            }
            else if (B->left->color == 'B' && B->left->right->color == 'R' && B->left->left->color == 'B') {
                rotateLeft(B->left);
                B->left->left->color = B->left->color;
                B->left->color = 'R';
            }
            rotateRight(B);
            B->father->color = B->color;
            B->color = 'B';
            B->right->color -= 'B';
            B->father->left->color = 'B';
            break;
        }
        else {  //jesli podowjny kolor ma lewy syn 
            if (B->right->color == 'R') {
                rotateLeft(B);
                B->father->color = B->color;
                B->color = 'R';
                continue;
            }
            else if (B->right->color == 'B' && B->right->left->color == 'B' && B->right->right->color == 'B') {
                B->left->color -= 'B';
                B->color += 'B';
                B->right->color = 'R';
                B = B->father;
                continue;
            }
            else if (B->right->color == 'B' && B->right->left->color == 'R' && B->right->right->color == 'B') {
                rotateRight(B->right);
                B->right->right->color = B->right->color;
                B->right->color = 'R';
            }
            rotateLeft(B);
            B->father->color = B->color;
            B->color = 'B';
            B->left->color -= 'B';
            B->father->right->color = 'B';
            break;
        }
    }
}

void BRT::removeValue(int value)
{
    BRT * current = root;
    while (true) {
        if (current->value == value) {
            if (current->left == NULL && current->right == NULL) {
                if (current->value < current->father->value) 
                    current->father->left = NULL;
                else 
                    current->father->right = NULL;
                current = NULL;
                break;
            }
            else if (current->left != NULL && current->left->right == NULL && current->left->left == NULL && current->right == NULL) {
                if (current->value < current->father->value)
                    current->father->left = current->left;
                else
                    current->father->right = current->left;
                current->left->color = 'B';
                current->left->father = current->father;
                current = NULL;
                break;
            }
            else if (current->right != NULL && current->right->right == NULL && current->right->left == NULL && current->left == NULL) {
                if (current->value < current->father->value)
                    current->father->left = current->right;
                else
                    current->father->right = current->right;
                current->right->color = 'B';
                current->right->father = current->father;
                current = NULL;
                break;
            }
            /*else if (current->right->left == NULL) {
                current->right->left = current->left;
                current->right->father = current->father;
                if (current->value < current->father->value)
                    current->father->left = current->right;
                else
                    current->father->right = current->right;
                current->left->father = current->right;
                if (current->right->color == 'B' && current->right->right != NULL) {
                    current->right->right->color += 'B';
                    current->right->color = current->color;
                    revalueTree(current->right);
                }
                else if (current->right->right == NULL && current->right->color == 'B') {
                    current->right->color = current->color;
                    revalueTree(current->right);
                }
                current = NULL;
                break;
            }*/
            else { //co jak nastepnik to nie prawy syn
                BRT* current1 = current->right;
                while (current1->left != NULL) { //ustalenie nastepnika wezla ktory chcemy usunac
                    current1 = current1->left;
                }
                if (current1->right != NULL) {
                    current1->right->father = current1->father;
                }
                if (current == root) {
                    root = current1;
                }
                if (current1->father->left == current1 && current1->right != NULL)
                    current1->father->left = current1->right;
                else if (current1->father->left == current1)
                    current1->father->left = NULL;
                else if (current1->father->right == current1 && current1->right != NULL)
                    current1->father->right = current1->right;
                else
                    current1->father->right = NULL;


                //dokonaj równowa¿enia jeœli nastêpnik by³ czarny
                if (current1->color == 'B') {
                    while (current1->right != NULL && current1->right != root && current->right->color == 'B') {

                    }
                }
                /*current1->right->father = current1->father;
                current->left->father = current1;
                current->right->father = current1;
                if (current->value < current->father->value)
                    current->father->left = current1;
                else
                    current->father->right = current1;
                if (current1->color = 'B' && current1->right != NULL) {
                    current1->right += 'B';
                }
                current1->father = current->father;
                current1->color = current->color;
                if (current1->color = 'B' && current1->right != NULL) {
                    current1 = current1->right;
                    revalueTree(current1->father);
                }
                current = NULL;
                break;*/
            }
        }
        if (current->left == NULL && current->right == NULL)
            break;
        if (current->value > value && current->left != NULL) {
            current = current->left;
            continue;
        }
        else if (current->value < value && current->right != NULL)
            current = current->right;
    }
}

void BRT::generateTree(int size)
{
    int val;
    for (int i = 0; i < size; i++) {
        val = rand() % 100;
        cout << val << " ";
        addValue(val);
    }
    cout << endl;
}

void BRT::rotateLeft(BRT* temp1)
{
    BRT* father;
    BRT* right;
    right = temp1->right;
    if (right != NULL) {
        father = temp1->father;
        temp1->right = right->left;
        if (temp1->right != NULL)
            temp1->right->father = temp1;
        right->left = temp1;
        right->father = father;
        temp1->father = right;
        if (father != NULL) {
            if (father->right == temp1)
                father->right = right;
            else
                father->left = right;
        }
        else
            root = right;
    }
}

void BRT::rotateRight(BRT* temp1)
{
    BRT* father;
    BRT* left;
    left = temp1->left;
    if (left != NULL) {
        father = temp1->father;
        temp1->left = left->right;
        if (temp1->left != NULL)
            temp1->left->father = temp1;
        left->right = temp1;
        left->father = father;
        temp1->father = left;
        if (father != NULL) {
            if (father->left == temp1)
                father->left = left;
            else
                father->right = left;
        }
        else
            root = left;
    }
}
