#include "types.h"
#include <fstream>

int main()
{
    bool quit = false;
    while (!quit) {
        system("cls");
        cout << "1: Create list" << endl << "2: Store list to file" <<
            endl << "3: Restore list from file" << endl <<
            "4: Add new object to list" << endl <<
            "5: Show list" << endl <<
            "6: Searh list by author and name" << endl <<
            "7: Delete object in list by author and name" << endl <<
            "8: Delete all objects" << endl <<
            "9: Delete list" << endl <<
            "0: Exit" << endl;
        char response;
        cin >> response;
        switch (response) {
        case '1':createList();
            break;
        case '2': store_to_file();
            break;
        case '3': restore_from_file();
            break;
        case '4': pushFront();
            break;
        case '5':printList();
            break;
        case '6':printList_search();
            break;
        case '7':pop();
            break;
        case '8':delete_all_object();
            break;
        case '9':destroyList();
            break;
        case '0':destroyList();
            quit = true;
            break;
        default: cout << "Please use 1-10 numbers"
            << endl; pause();

        }

    }
    return 0;
}

