#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(const string& title, const string& author, int year) : title(title), author(author), year(year) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }

    void printInfo() const {
        cout << "Назва: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Рік видання: " << year << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void printAllBooks() const {
        cout << "Книги в бібліотеці:" << endl;
        for (const Book& book : books) {
            book.printInfo();
            cout << endl;
        }
    }
};

int main() {
    Library library;

    ifstream file("books.txt");
    if (!file.is_open()) {
        cerr << "Помилка відкриття файлу" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string title, author, yearStr;
        int year;

        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, yearStr);
        year = stoi(yearStr);

        library.addBook(Book(title, author, year));
    }


    file.close();

    library.printAllBooks();

    return 0;
}
