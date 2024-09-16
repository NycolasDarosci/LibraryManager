#ifndef ALG_II_USER_H
#define ALG_II_USER_H

#include <string>
#include "vector"
#include "book.hpp"

using namespace std;

struct User{
    string name;
    int balance;
    vector<Book> story_borrowed_books;
    vector<Book> current_borrowed_books;
};

void insert(vector<User> &users_vector);
void list(vector<User> &users_vector);
User* find_by_name(vector<User> &users_vector, string name);
//void return_book();
//void loaned_books();

#endif