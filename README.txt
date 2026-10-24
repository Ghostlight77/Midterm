The library let people manage books. 
They can add view search borrow and view borrowing history

Features:
-add and track
-view all books
-search books
-borrow books
-record history
-count copies
-sort borrowing history
-validate user input

Files:
-Main.cpp is the loop and option choices
-Library.h declares the classes and defines maps
-Library.cpp implements the options and has stl containers
-Readme.txt || this is what we are in rn

get_number()
makes sure they type a number over 0

get_required_text()
makes sure input is not empty

get_menu_choice()
gets a number input to chose which option in the menu you want to pick. once picked the option will launch. if incorrect input is entered it will try again

display_all()
displays all books and copy count from map<string, int>& books. if empty it will prompt empty

search_book()
searches for books in the library. if it cant find it, itll print book not found

add_book()
adds book to library. if book exists itll add it to the existing. also prompts for copys

borrow_book()
it will ask for book to borrow then it will put it in borrowing histroy and prompt book borrowed successfully

display_history()
it will display all from borrowing_history

count_available_books() 
it will count how many books are available to borrow

sort_history()
it will sort the history in alphabetical order
