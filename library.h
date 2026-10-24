#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int get_number(const string& prompt);
int get_menu_choice();
string get_required_text(const string& prompt);

template <typename Key, typename Value>
void display_all(const map<string, int>& books);

void search_book(const map<string, int>& books);
void add_book(map<string, int>& books);
void borrow_book(
    map<string, int>& books,
    vector<string>& borrowing_history
);
void display_history(const vector<string>& borrowing_history);
void count_available_books(const map<string, int>& books);
void sort_history(vector<string>& borrowing_history);

#endif
