#include "library.h"
#include <iostream>

using namespace std;

int main() {
    map<string, int> books;
    vector<string> borrowing_history;

    int choice;

    do {
        choice = get_menu_choice();

        if (cin.eof()) {
            cout << "\nInput closed. Exiting program.\n";
            break;
        }

        switch (choice) {
            case 1:
                display_all(books);
                break;
            case 2:
                search_book(books);
                break;
            case 3:
                add_book(books);
                break;
            case 4:
                borrow_book(books, borrowing_history);
                break;
            case 5:
                display_history(borrowing_history);
                break;
            case 6:
                count_available_books(books);
                break;
            case 7:
                sort_history(borrowing_history);
                break;
            case 8:
                cout << "Thank you for using the library catalog!\n";
                break;
        }

    } while (choice != 8);

    return 0;
}
