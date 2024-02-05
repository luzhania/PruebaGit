#include <iostream>
#include <string>

using namespace std;

class Utils
{
    public:
        static int menu()
        {
            int option;
            cout << "---------------MENU---------------" << endl;
            cout << "1. Insert randomly" << endl;
            cout << "2. Count nodes" << endl;
            cout << "3. Calculate height" << endl;
            cout << "4. Visit InOrder" << endl;
            cout << "5. Visit PreOrder" << endl;
            cout << "6. Visit PostOrder" << endl;
            cout << "7. MirrorTree" << endl;
            cout << "0. Exit" << endl;
            cout << "-----------------------------------" << endl;
            cout << "Select an option: ";
            cin >> option;
            return option;
        }

};