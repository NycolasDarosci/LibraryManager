#ifndef ALG_II_LIBRARY_H
#define ALG_II_LIBRARY_H

#include "book.hpp"
#include "user.hpp"
#include "vector"
using namespace std;

void borrow_book(vector<Book> &books_vector, vector<User> &users_vector);
void return_book(vector<Book> &books_vector, vector<User> &users_vector);
void loan_report(vector<Book> &books_vector, vector<User> &users_vector);
void list_book_by_user(vector<User> &users_vector);
void loan_fine(vector<User> &users_vector);

#endif