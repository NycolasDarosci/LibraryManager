#ifndef ALG_II_USER_H
#define ALG_II_USER_H

#include <string>
#include <vector>

using namespace std;

struct User{
    string name;
    int balance;
    string story_borrowed_books;
    string current_borrowed_books;
};

void insert(vector<User> &users_vector);
void listAll(vector<User> &users_vector);
User& getUser(vector<User> &users_vector, string name);
void return_book();
void loaned_books();

#endif