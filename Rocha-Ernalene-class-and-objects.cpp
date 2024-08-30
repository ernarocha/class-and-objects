#include <iostream>
#include <iomanip>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book() : title(""), author(""), year(0) {}

    void setDetails(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    string getTitle() {
        return title;
    }

    void displayBook() {
        cout << left << setw(25) << title << setw(20) << author << setw(4) << year << endl;
    }

    void displaySearchBooks() {
        cout << endl << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl << endl;
    }
};

class Library {
private:
    Book books[100];
    int bookCount;

public:
    Library() : bookCount(0) {}

    void addBook(string title, string author, int year) {
        if (bookCount < 100) {
            books[bookCount].setDetails(title, author, year);
            bookCount++;
            cout << endl << "Book added successfully!" << endl << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    void displayBooks() {
        if (bookCount == 0) {
            cout << endl << "No books to display." << endl << endl;
            return;
        }

        cout << endl << "Display all books" << endl << endl;
        cout << left << setw(25) << "Title" << setw(20) << "Author" << setw(4) << "Year" << endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBook();
        }
        cout << endl;
    }

    void searchBook(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                cout << endl << "Book found!" << endl;
                books[i].displaySearchBooks();
                return;
            }
        }
        cout << endl << "Book not found!" << endl << endl;
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    do {
        cout << "Menu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << endl << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                library.addBook(title, author, year);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << endl << "Enter a book title to search: ";
                cin.ignore();
                getline(cin, title);
                library.searchBook(title);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}