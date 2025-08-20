#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book { /* Structure for holding book details */
    string id;
    string title;
    string author;
    bool issued;
};
void addBook() { /*Function for adding a new book */
    Book book;
    cout << "Enter Book ID: ";
    cin >> book.id;

    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, book.title);
    cout << "Enter Author Name: ";
    getline(cin, book.author);
    book.issued = false;

    ofstream file("library.txt", ios::app); /*Open file in append mode for saving new book */
    file << book.id << "|" << book.title << "|" << book.author << "|0" << endl;
    file.close();

    cout << "Book added successfully!" << endl;
}

void viewBooks() { /* Function to view all books */
    ifstream file("library.txt");
    if (!file) {
        cout << "No books found!" <<endl;
        return;
    }
    string id, title, author, status;
    cout << "\n--- Book List ---" <<endl;
    while (getline(file, id, '|')) { /*Read file line by line*/
        getline(file, title, '|');
        getline(file, author, '|');
        getline(file, status);
        cout << "ID: " << id <<endl; /*Display book details*/
        cout<< ", Title: " << title <<endl;
        cout<< ", Author: " << author <<endl;
        cout<< ", Issued: " << (status == "1" ? "Yes" : "No") << endl;
    }
    file.close();
}

void searchBook() { /* Function for searching a book*/
    string searchId;
    cout << "Enter Book ID to search: ";
    cin >> searchId;

    ifstream file("library.txt");
    string id, title, author, status;
    bool found = false;
    while (getline(file, id, '|')) {
        getline(file, title, '|');
        getline(file, author, '|');
        getline(file, status);
        if (id == searchId) {
            cout << "Book Found!" <<endl;
            cout << "ID: " << id
                 << ", Title: " << title
                 << ", Author: " << author
                 << ", Issued: " << (status == "1" ? "Yes" : "No") << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Book not found!"<<endl;
    file.close();
}

void issueBook() { /* Function for issuing a book*/
    string issueId;
    cout << "Enter Book ID to issue: ";
    cin >> issueId;

    ifstream file("library.txt");
    ofstream temp("temp.txt");
    string id, title, author, status;
    bool issued = false;

    while (getline(file, id, '|')) {
        getline(file, title, '|');
        getline(file, author, '|');
        getline(file, status);
        if (id == issueId && status == "0") {
            temp << id << "|" << title << "|" << author << "|1"<<endl;
            issued = true;
        } else {
            temp << id << "|" << title << "|" << author << "|" << status <<endl;
        }
    }
    file.close();
    temp.close();
    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (issued)
        cout << "Book issued successfully!"<<endl;
    else
        cout << "Book not found or already issued!"<<endl;
}

void returnBook() { /* Function for returning the issued book*/
    string returnId;
    cout << "Enter Book ID to return: ";
    cin >> returnId;

    ifstream file("library.txt");
    ofstream temp("temp.txt");
    string id, title, author, status;
    bool returned = false;

    while (getline(file, id, '|')) {
        getline(file, title, '|');
        getline(file, author, '|');
        getline(file, status);
        if (id == returnId && status == "1") {
            temp << id << "|" << title << "|" << author << "|0"<<endl;
            returned = true;
        } else {
            temp << id << "|" << title << "|" << author << "|" << status <<endl;
        }
    }
    file.close();
    temp.close();
    remove("library.txt"); /* Replace old file with updated file*/
    rename("temp.txt", "library.txt");

    if (returned)
        cout << "Book returned successfully!"<<endl;
    else
        cout << "Book not found or not issued!"<<endl;
}
void deleteBook() { /* Function for Deleting a book*/
    string deleteId;
    cout << "Enter Book ID to delete: ";
    cin >> deleteId;

    ifstream file("library.txt");
    ofstream temp("temp.txt");

    string id, title, author, status;
    bool deleted = false;

    while (getline(file, id, '|')) { /* Loop through file and update issued status back to 0*/
        getline(file, title, '|');
        getline(file, author, '|');
        getline(file, status);

        if (id == deleteId) {
            deleted = true;
            continue;
        }
        temp << id << "|" << title << "|" << author << "|" << status << endl;
    }

    file.close();
    temp.close();

    remove("library.txt"); /* Replace old file with updated file*/
    rename("temp.txt", "library.txt");

    if (deleted)
        cout << "Book deleted successfully!" << endl;
    else
        cout << "Book not found!" << endl;
}

int main() {
    int choice;
    do { /* MAin Feature of my project*/
        cout << endl << "===== Library Management System =====" << endl;
cout << "1. Add Book" << endl;
cout << "2. View Books" << endl;
cout << "3. Search Book" << endl;
cout << "4. Issue Book" << endl;
cout << "5. Return Book" << endl;
cout << "6. Delete Book" << endl;
cout << "0. Exit" << endl;
cout << "Enter choice: ";
        cin >> choice;

        switch (choice) { /* Call corresponding functions*/
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 0: cout << "Exiting..."<<endl; break;
            default: cout << "Invalid choice!"<<endl;
        }
    } while (choice != 0);

    return 0;
}
