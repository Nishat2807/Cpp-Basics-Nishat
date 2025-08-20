## Library Management System (LMS)

A simple *Library Management System* project written in *C++, using **basic file handling*.  
The system allows users to manage books in a library with options to add, view, search, issue, return, and delete books.

---

## Project Objectives
- To demonstrate the use of *C++ file handling* in a practical project.  
- To implement *basic CRUD operations* (Create, Read, Update, Delete) using text files.  
- To help beginners understand how a simple management system works without a database.  

---

## Technologies Used
- *Programming Language:* C++  
- *Concepts:* File Handling, Structures, Menu-Driven Program  
- *Files Used:*  
  - library.txt → Stores all book records  
  - temp.txt → Temporary file used for update/delete operations  

---

## Features
1. *Add Book* – Add new books with ID, Title, Author.  
2. *View Books* – Display all saved books.  
3. *Search Book* – Find a book by its unique ID.  
4. *Issue Book* – Mark a book as borrowed.  
5. *Return Book* – Mark a borrowed book as returned.  
6. *Delete Book* – Remove a book permanently.  
7. *Exit* – Close the system.  

*Status Codes:*  
- 0 → Not Issued  
- 1 → Issued  

---

## How to Run
1. Copy the code into a file named **main.cpp**  
2. Compile using any C++ compiler:  
   bash
   g++ main.cpp -o lms
   
3. Run the program:  
   bash
   ./lms
   
4. Use the menu to manage your library.  

---

## Example Menu

===== Library Management System =====
1. Add Book
2. View Books
3. Search Book
4. Issue Book
5. Return Book
6. Delete Book
0. Exit


---

## Notes
- Implemented using *basic C++ file handling* (no database).  
- library.txt will be created automatically after adding the first book.  
- Best suited for *beginners* learning file handling in C++.  
- This project is for *educational purposes only*.  

---

## Challenges Faced
- Handling file updates (issue/return/delete) → solved using a *temporary file system*.  
- Ensuring unique book IDs.  
- Keeping the project simple and beginner-friendly.