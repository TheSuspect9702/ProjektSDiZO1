#include "BRT.h"
#include <iostream>
#include <fstream>
#include "Pomiary.h"
string cr1, cl1, cp1;
using namespace std;
Pomiary pomiar3;
BRT::BRT()
{
}

BRT::~BRT()
{
}

bool BRT::isValueInTree(int value)
{
    BRT* current = root;
    while (true) {
        if (current->value == value)
            return true;
        if (current->value > value && current->left != NULL)
            current = current->left;
        else if (current->value < value && current->right != NULL)
            current = current->right;
        else
            break;
    }
	return false;
}

void BRT::loadFromFile(string fileName)
{
  
    clearTree(root);
    root = NULL;
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
        if (B->right == NULL && B->left != NULL && B->left->color > 'R') {
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
            if (B->father->left != NULL)
                B->father->left->color = 'B';
            break;
        }
        else if (B->left == NULL && B->right != NULL && B->right->color > 'R') {
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
            if (B->father->right != NULL)
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
            else if (B->left->color == 'B' && B->left->right != NULL && B->left->left != NULL && B->left->right->color == 'B' && B->left->left->color == 'B') {
                B->right->color -= 'B';
                B->color += 'B';
                B->left->color = 'R';
                B = B->father;
                continue;
            }
            else if (B->left->right == NULL && B->left->left == NULL) {
                B->color = 'B';
                B->right->color -= 'B';
                B->left->color = 'R';
                break;
            }
            else if (B->left->color == 'B' && B->left->right != NULL && B->left->left != NULL && B->left->right->color == 'R' && B->left->left->color == 'B') {
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
            else if (B->right->left != NULL && B->right->right != NULL && B->right->left->color == 'B' && B->right->right->color == 'B') {
                B->left->color -= 'B';
                B->color += 'B';
                B->right->color = 'R';
                B = B->father;
                continue;
            }
            else if (B->right->left == NULL && B->right->right == NULL) {
                B->color = 'B';
                B->left->color -= 'B';
                B->right->color = 'R';
                break;
            }
            //else if (B->right->color == 'B' && ((B->right->right != NULL && B->right->left != NULL && B->right->right->color == 'B' && B->right->left->color == 'B')
            //    || (B->right->right == NULL && B->right->left == NULL))) {
            //    B->color = 'B';
            //    B->right->color = 'R';
            //    break;
            //}
            else if (B->right->left != NULL && B->right->right != NULL && B->right->left->color == 'R' && B->right->right->color == 'B') {
                rotateRight(B->right);
                B->right->right->color = B->right->color;
                B->right->color = 'R';
            }
            else if (B->right->left != NULL && B->right->right == NULL && B->right->left->color == 'R') {
                rotateRight(B->right);
                B->right->right->color = B->color;
                B->right->color = 'B';
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
    BRT* temp = new BRT();
    temp->color = 'B';
    BRT * current = root;
    while (true) {
        if (current->value == value) {
            if (current->left == NULL && current->right == NULL) { //jesli wezel nie ma dzieci
                if(current->father != NULL)
                {
                    if (current->value < current->father->value)
                        current->father->left = NULL;
                    else
                        current->father->right = NULL;
                }
                else 
                    root = NULL;
                current = NULL;
                break;
            }
            else if (current->right != NULL && current->right->right == NULL && current->right->left == NULL && current->left == NULL) { //jesli wezel ma prawe dziecko ale lewego nie ma
                if (current->father != NULL)
                {
                    if (current->value < current->father->value)
                        current->father->left = current->right;
                    else
                        current->father->right = current->right;
                }
                else 
                    root = current->right;
                current->right->color = 'B';
                current->right->father = current->father;
                current = NULL;
                break;
            }
            else if (current->left != NULL && current->left->right == NULL && current->left->left == NULL && current->right == NULL) { //jesli wezel ma lewe dziecko a prawego nie ma 
                if (current->father != NULL)
                {
                    if (current->value < current->father->value)
                        current->father->left = current->left;
                    else
                        current->father->right = current->left;
                }
                else 
                    root = current->left;
                current->left->color = 'B';
                current->left->father = current->father;
                current = NULL;
                break;
            }
            else if (current->left->right == NULL) {    //jesli lewy syn nie ma prawego dziecka (poprzednik)
                current->left->right = current->right;
                if (current->father != NULL) {
                    current->left->father = current->father;
                    if (current->value < current->father->value)
                        current->father->left = current->left;
                    else
                        current->father->right = current->left;
                }
                else {
                    current->left->father = NULL;
                    root = current->left;
                }
                current->right->father = current->left;
                if (current->left->color == 'R') {
                    current->left->color = 'B';
                }
                else if (current->left->color == 'B' && current->left->left == NULL) {
                    current->left->color = current->color;
                    BRT* current1 = new BRT();
                    current->left->left = current1;
                    current1->father = current->left;
                    current1->color = 'z';
                    revalueTree(current->left);
                    current->left->left = NULL;
                    current1 == NULL;
                }
                else if (current->left->color == 'B' && current->left->left != NULL) {
                    current->left->left->color = 'B';
                }
                current = NULL;
                break;
            }
            else { //co jak nastepnik to nie prawy syn
                BRT* current1 = current->left;
                while (current1->right != NULL) { //ustalenie nastepnika wezla ktory chcemy usunac
                    current1 = current1->right;
                }
                current->value = current1->value;
                if (current1->color == 'B') {
                    if (current1->left == NULL) {
                       /* temp = current1;
                        while (true)
                        {
                            if (temp->father->left != NULL && temp->father->left->color == 'R') {
                                temp->father->color = 'R';
                                temp->father->left->color = 'B';
                                rotateRight(temp->father);
                            }
                            else if (temp->father->left == NULL) {
                                temp->father->color += 'B';
                                temp = temp->father;
                                continue;
                            }
                            else if (temp->father->right->left != NULL && temp->father->right->left->color == 'R') {
                                temp->father->right->color = 'R';
                                temp->father->right->left->color = 'B';
                                rotateRight(temp->father->right);
                            }
                            if (temp->father->right != NULL) {
                                temp->father->right->color = temp->father->color;
                                if (temp->father->right->right != NULL)
                                    temp->father->right->right->color = 'B';
                            }
                            temp->father->color = 'B';
                            rotateLeft(temp);
                            break;
                            
                        }*/
                        temp->color = 'z';
                        temp->father = current1->father;
                        current1->father->right = temp;
                        revalueTree(current1->father);
                    }
                    else {
                        current1->father->right = current1->left;
                        current1->left->father = current1->father;
                        current1->left->color = 'B';
                        break;
                    }
                }

                current1->father->right = NULL;
                current1 = NULL;
                break;
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
        else
            break;
    }
}

void BRT::generateTree(int size)
{
    clearTree(root);
    root = NULL;
    int val;
    for (int i = 0; i < size; i++) {
        val = rand() % 100;
        addValue(val);
    }
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

void BRT::clearTree(BRT* root1)
{
    if (root1 != NULL) {
        if(root1->left != NULL)
            clearTree(root1->left);
        if(root1->right != NULL)
            clearTree(root1->right);
        delete root1;
    }
}

void BRT::Tests()
{
    srand(time(NULL));
    double timeTreeDelete[10] = { 0 };
    double timeTreeAdd[10] = { 0 };
    double timeTreeSearch[10] = { 0 };
    int value;
    int index;
    int k = 0;
    for (int j = 1; j <= 10; j++) {
        for (int i = 0; i < 100; i++) {
            value = rand() % 2000;
            generateTree(j * 1000 * (k + 1));
            pomiar3.StartCounter();
            addValue(value);
            timeTreeAdd[k] += pomiar3.GetCounter();
            value = rand() % 2000;
            pomiar3.StartCounter();
            removeValue(value);
            timeTreeDelete[k] += pomiar3.GetCounter();
            pomiar3.StartCounter();
            value = rand() % 2000;
            isValueInTree(value);
            timeTreeSearch[k] += pomiar3.GetCounter();
            system("cls");
            cout << "test zakoñczony" << endl;
        }
        k++;
    }
    k = 1;
    for (int i = 0; i < 10; i++) {
        timeTreeAdd[i] *= 10000;
        timeTreeDelete[i] *= 10000;
        timeTreeSearch[i] *= 10000;
        cout << "Œredni czas dla " << (i + 1) * 1000 * k << " próbek" << endl;
        cout << "DODAJ: " << timeTreeAdd[i] << " ms" << endl;
        cout << "USUN: " << timeTreeDelete[i] << " ms" << endl;
        cout << "WYSZUKAJ: " << timeTreeSearch[i] << " ms" << endl;
        k++;
    }
}
