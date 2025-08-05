#include <unordered_map> 
using namespace std;

struct Book { int id; string title; string author;

Book(int i, string t, string a) : id(i), title(t), author(a) {}
};

unordered_map<int, Book> library;

void addBook() { int id; string title, author;

cout << "Enter Book ID: ";
cin >> id;
cin.ignore();
cout << "Enter Title: ";
getline(cin, title);
cout << "Enter Author: ";
getline(cin, author);

if (library.find(id) != library.end()) {
    cout << "Book with this ID already exists.\n";
    return;
}

library[id] = Book(id, title, author);
cout << "Book added successfully.\n";
}

void searchBook() { int id; cout << "Enter Book ID to search: "; cin >> id;

if (library.find(id) != library.end()) {
    Book b = library[id];
    cout << "Found Book:\n";
    cout << "ID: " << b.id << ", Title: " << b.title << ", Author: " << b.author << "\n";
} else {
    cout << "Book not found.\n";
}
}

void deleteBook() { int id; cout << "Enter Book ID to delete: "; cin >> id;

if (library.erase(id)) {
    cout << "Book deleted successfully.\n";
} else {
    cout << "Book not found.\n";
}
}

void displayBooks() { if (library.empty()) { cout << "No books in library.\n"; return; }

cout << "\n--- Library Books ---\n";
for (auto &entry : library) {
    Book b = entry.second;
    cout << "ID: " << b.id << ", Title: " << b.title << ", Author: " << b.author << "\n";
}
}

int main() { int choice; while (true) { cout << "\n--- Library Menu ---\n"; cout << "1. Add Book\n"; cout << "2. Search Book\n"; cout << "3. Delete Book\n"; cout << "4. Display All Books\n"; cout << "5. Exit\n"; cout << "Enter your choice: "; cin >> choice;

    switch (choice) {
        case 1: addBook(); break;
        case 2: searchBook(); break;
        case 3: deleteBook(); break;
        case 4: displayBooks(); break;
        case 5: cout << "Exiting...\n"; return 0;
        default: cout << "Invalid choice. Try again.\n";
    }
}

}
