#ifndef ALG_II_USER_H
#define ALG_II_USER_H

#include <string>
#include <ctime>
#include "vector"
#include "book.hpp"

using namespace std;

struct UserBorrowedBook {
    Book *book;
    time_t return_date;
};

struct User{
    string name;
    double balance;
    vector<Book> story_borrowed_books;
    vector<UserBorrowedBook> current_borrowed_books;
};
struct SelectedUser{
    int index;
    User* user;
};

void insert(vector<User> &users_vector);
void list(vector<User> &users_vector);
User* find_by_name(vector<User> &users_vector, string name);
SelectedUser select_user(vector<User> &users_vector);

#endif