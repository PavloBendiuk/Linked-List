#include "types.h"
#include <cstddef>
#include <stddef.h>
#include <stdlib.h>
using namespace std;
List* l = NULL;

void createList() {
    l = createList_1();
    cout << endl << "List is created successfully!" << endl;
    pause();
}
void pause() {
    cout << "\nFor continue press any button";
    getch();
}
List* createList_1() {
    List* s = new List();
    s->prev = NULL;

    s->next = NULL;
    return s;
}
void pushFront() {
    if (l == NULL) {
        cout << "List doesent created!" << endl;
        pause();
    }
    else {
        while (l->next != NULL) {
            l = l->next;
        }
        List* tmp = new List();
        //tmp->pages=NULL;
        tmp->next = NULL;
        tmp->prev = l;
        cout << "Enter author for the book: ";
        cin >> l->autor;
        cout << "Enter name for the book: ";
        cin >> l->name;
        cout << "Enter year for the book: ";
        cin >> l->year;
        cout << "Enter genere for the book: " << endl;
        cout << "Detective=D" << endl;
        cout << "Roman=R" << endl;
        cout << "Fantasy=F" << endl;
        char s;
        cin >> s;
        l->gen = (genre)s;
        cout << "Enter pages for the book: ";
        cin >> l->pages;
        l->next = tmp;
        while (l->prev != NULL) {
            l = l->prev;
        }
    }
}
void printList() {
    int i = 1;
    if (l == NULL) {
        cout << "List doesent created!" << endl;
        pause();
    }
    else {
        while (l->next != NULL) {
            cout << "Book number# " << i << endl;
            cout << "Author# " << l->autor << endl;
            cout << "Name# " << l->name << endl;
            cout << "Year# " << l->year << endl;
            cout << "Genere# " << char(l->gen) << " (Detective=D,Roman=R,Fantasy=F) " << endl;
            cout << "Pages# " << l->pages << endl;
            cout << endl;
            i++;
            l = l->next;
        }
        while (l->prev != NULL) {
            l = l->prev;
        }
        pause();
    }

}

void pop() {
    if (l == NULL) {
        cout << "List doesent created!" << endl;
        pause();
    }
    else {
        string tmp_a, tmp_n;
        cout << "Enter author and name of book, which need to be deleted: ";
        cin >> tmp_a >> tmp_n;
        while (l->next != NULL) {


            if (l->autor == tmp_a && l->name == tmp_n) {

                if (l->prev == NULL && l->next->next == NULL) {
                    free(l);
                    l = new List();
                    l->next = NULL;
                    l->prev = NULL;
                    break;
                }
                if (l->prev == NULL && l->next->next != NULL) {
                    l = l->next;
                    free(l->prev);
                    l->prev = NULL;
                }
                if (l->next->next == NULL && l->prev != NULL) {
                    free(l->next);
                    l = l->prev;
                    l->next = new List();
                    l->next->next = NULL;
                    l->next->prev = l;
                }


                if (l->prev != NULL && l->next->next != NULL) {
                    List* tmp = l;
                    l->prev->next = l->next;
                    l->next->prev = l->prev;
                    l = l->next;
                    free(tmp);

                }
            }
            if (l->next != NULL)
                l = l->next;
        }
        while (l->prev != NULL) {
            l = l->prev;
        }
        pause();
        printList();
    }


}
void printList_search() {
    if (l == NULL) {
        cout << "List doesent created!" << endl;
        pause();
    }
    else {
        string tmp_a, tmp_n;
        cout << "Enter author and name of book, which need to be finded: ";
        cin >> tmp_a >> tmp_n;
        int i = 1;
        while (l->next != NULL) {
            if (l->autor == tmp_a && l->name == tmp_n) {
                cout << "Book number# " << i << endl;
                cout << "Author# " << l->autor << endl;
                cout << "Name# " << l->name << endl;
                cout << "Year# " << l->year << endl;
                cout << "Genere# " << char(l->gen) << " (Detective=D,Roman=R,Fantasy=F) " << endl;
                cout << "Pages# " << l->pages << endl;
                cout << endl;

            }
            i++;
            l = l->next;
        }
        pause();
    }
}
void store_to_file() {
    //system("cls");
    if (l == NULL) {
        cout << "List doesent created!" << endl;
        pause();
    }
    else {
        ofstream file;
        file.open("text.txt");
        while (l->next != NULL) {
            file << l->autor << " " << l->name << " " << l->pages << " " << l->year << " " << char(l->gen);
            l = l->next;
        }
        while (l->prev != NULL)l = l->prev;
        file.close();
        pause();
    }
}
void restore_from_file() {
    ifstream file;
    file.open("text.txt");
    destroyList();
    l = createList_1();
    while (!(file.eof())) {
        l->next = new List();
        l->next->prev = l;
        char c;
        file >> l->autor >> l->name >> l->pages >> l->year >> c;
        l->gen = (genre)c;
        l = l->next;
    }
    l = l->prev;
    free(l->next);
    l->next = NULL;
    while (l->prev != NULL)l = l->prev;
    file.close();
    pause();
}
void destroyList() {
    List* t = l;
    while ((t = l) != NULL) {
        l = l->next;
        free(t);
    }
}
void delete_all_object() {
    if (l == NULL) {
        cout << "List doesent created!" << endl;
        pause();
    }
    else {
        destroyList();
        l = createList_1();
    }
}

