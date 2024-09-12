#include "book.hpp"
#include "vector"
#include <iostream>
#include <string>
using namespace std;

vector<Books> list(vector<Books> &books_vector, Books props) {
    vector<Books> matched_books;

    for (const Books& book : books_vector) {
        bool matches = true;

        if (!props.title.empty() && book.title != props.title) {
            matches = false;
        }
        if (!props.author.empty() && book.author != props.author) {
            matches = false;
        }
        if (props.year != 0 && book.year != props.year) {
            matches = false;
        }
        if (props.copies != 0 && book.copies != props.copies) {
            matches = false;
        }

        if (matches) {
            matched_books.push_back(book);
        }
    }

    return matched_books;}

void insert(vector<Books> &books_vector) {
    string title, author;
    int year, copies;

    cout << "Preencha as informações do livro: " << endl;

    cout << "Título do livro: ";
    getline(cin, title);
    cout << "Autor do livro: ";
    getline(cin, author);
    cout << "Ano de lançamento do livro: ";
    cin >> year;
    cout << "Número de cópias do livro: ";
    cin >> copies;

    Books newBook = {title, author, year, copies};

    books_vector.push_back(newBook);
}
