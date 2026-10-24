#include "library.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <stdexcept>

using namespace std;

int get_number(const string& prompt) {
    int number;

    while (true) {
        cout << prompt;

        if (cin >> number && number > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }

        cout << "Please enter a valid positive number.\n";

        if (cin.eof()) {
            throw runtime_error("Input stream closed.");
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string get_required_text(const string& prompt) {
    string text;

    while (true) {
        cout << prompt;

        if (!getline(cin, text)) {
            throw runtime_error("Input stream closed.");
        }

        if (text.find_first_not_of(" \t") != string::npos) {
            return text;
        }

        cout << "This field cannot be empty.\n";
    }
}

int get_menu_choice() {
    cout << "\nLIBRARY CATALOG\n";
    cout << "------------------------------\n";
    cout << "1. Display all books\n";
    cout << "2. Search for a book\n";
    cout << "3. Add a book\n";
    cout << "4. Borrow a book\n";
    cout << "5. Display borrowing history\n";
    cout << "6. Count available titles\n";
    cout << "7. Sort borrowing history\n";
    cout << "8. Exit\n\n";

    int choice;

    while (true) {
        choice = get_number("Choice: ");

        if (choice >= 1 && choice <= 8) {
            return choice;
        }

        cout << "Please choose an option from 1 to 8.\n";
    }
}

void search_book(const map<string, int>& books) {
    string title = get_required_text("Enter book title: ");

    auto it = find_if(
        books.begin(),
        books.end(),
        [&title](const pair<const string, int>& book) {
            return book.first == title;
        }
    );

    if (it == books.end()) {
        cout << "Book not found.\n";
        return;
    }

    cout << "\nBook found:\n";
    cout << "Title: " << it->first << endl;
    cout << "Available copies: " << it->second << endl;
}

void add_book(map<string, int>& books) {
    string title = get_required_text("Enter book title: ");
    int copies = get_number("Enter number of copies: ");

    books[title] += copies;

    cout << "Book added successfully!\n";
}

void borrow_book(
    map<string, int>& books,
    vector<string>& borrowing_history
) {
    string title = get_required_text("Enter book title to borrow: ");

    auto it = books.find(title);

    if (it == books.end()) {
        cout << "Book not found.\n";
        return;
    }

    if (it->second <= 0) {
        cout << "No copies are available.\n";
        return;
    }

    it->second--;
    borrowing_history.push_back(title);

    cout << "Book borrowed successfully!\n";
}

void display_history(const vector<string>& borrowing_history) {
    cout << "\nBORROWING HISTORY\n";
    cout << "------------------------------\n";

    if (borrowing_history.empty()) {
        cout << "No borrowing history found.\n";
        return;
    }

    for (size_t i = 0; i < borrowing_history.size(); i++) {
        cout << i + 1 << ". "
             << borrowing_history[i] << endl;
    }
}

void count_available_books(const map<string, int>& books) {
    int count = count_if(
        books.begin(),
        books.end(),
        [](const pair<const string, int>& book) {
            return book.second > 0;
        }
    );

    cout << "Titles with available copies: "
         << count << endl;
}

void sort_history(vector<string>& borrowing_history) {
    sort(
        borrowing_history.begin(),
        borrowing_history.end()
    );

    cout << "Borrowing history sorted successfully.\n";
}
