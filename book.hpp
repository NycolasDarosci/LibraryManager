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
};

void insert(vector<Book> &books_vector);
vector<Book> list(vector<Book> &books_vector);
vector<Book> list(vector<Book> &books_vector, Book props);
Book* find(vector<Book> &books_vector, string title, string author);

#endif