#ifndef ALG_II_BOOK_H
#define ALG_II_BOOK_H

#include <string>
#include <vector>

using namespace std;

struct Books {
    string title;
    string author;
    int year;
    int copies;
};

void insert(vector<Books> &books_vector);
vector<Books> list(vector<Books> &books_vector, Books props);
void listAll(vector<Books> &books_vector);
Books& getBook(vector<Books> &books_vector, string title, string author);


#endif