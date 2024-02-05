#include <iostream>
#include "Tree.h"
#include "Utils.h"
#define CAPACITY 100

using namespace std;

int main()
{
    Tree<int> t, mirrorT;
    int element;
    t.insertRandomly(6, 1);
    t.insertRandomly(3, 1);
    t.insertRandomly(7, 1);
    t.insertRandomly(2, 1);
    t.insertRandomly(5, 1);
    t.insertRandomly(8, 1);
    t.insertRandomly(6, 1);
    t.insertRandomly(3, 1);
    t.insertRandomly(7, 1);
    t.insertRandomly(2, 1);
    t.insertRandomly(5, 1);
    t.insertRandomly(8, 1);
    t.insertRandomly(9, 1);
    int option;
    do
    {
        option = Utils::menu();
        system("cls");
        switch (option)
        {
        case 1:
            cout << "Enter an element: ";
            cin >> element;
            t.insertRandomly(element, 1);
            system("pause");
            break;
        case 2:
            cout << "The tree has " << t.countNodes(1) << " nodes" << endl;
            system("pause");
            break;
        case 3: //calcular altura
            cout << "The height of the tree is " << t.calculateHeight(1) << endl;
            system("pause");
            break;
        case 4:
            cout << "Visit inOrder:" << endl;
            t.visitInOrder(1);
            system("pause");
            break;
        case 5:
            cout << "Visit preOrder:" << endl;
            t.visitPreOrder(1);
            system("pause");
            break;
        case 6:
            cout << "Visit postOrder:" << endl;
            t.visitPostOrder(1);
            system("pause");
            break;
        case 7:
            cout << "Original tree:" << endl;
            t.printWithFormat();
            cout << endl;
            cout << "Mirror tree:" << endl;
            mirrorT= t.mirrorTree();
            mirrorT.printWithFormat();
            system("pause");
            break;
        }
    } while (option != 0);
}
