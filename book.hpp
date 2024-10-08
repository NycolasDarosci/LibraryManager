#ifndef ALG_II_BOOK_H
#define ALG_II_BOOK_H

#include <string>
#include "vector"

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    int copies;
    unsigned short int number_of_loans;
};

struct SelectedBook {
    int index;
    Book* book;
};

void insert(vector<Book> &books_vector);
void list(vector<Book> &books_vector);
void list(vector<Book> &books_vector, Book props);
Book* find(vector<Book> &books_vector, string title, string author);
SelectedBook select_book(vector<Book> &books_vector);

#endif