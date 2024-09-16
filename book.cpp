#include <iostream>
#include <string>

#include "book.hpp"
#include "vector"

using namespace std;

vector<Book> list(vector<Book> &books_vector) {
    for (const Book& book : books_vector) {
        cout << "Título: " << book.title << endl;
        cout << "Autor: " << book.author << endl;
        cout << "Ano de publicação: " << book.year << endl;
        cout << "Cópias: " << book.copies << endl;
        cout << "\n";
    }
    return books_vector;
}
vector<Book> list(vector<Book> &books_vector, const Book props) {
    vector<Book> matched_books;

    for (const Book& book : books_vector) {
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

        if (matches) {
            matched_books.push_back(book);
        }
    }

    for (const Book& book : matched_books) {
        cout << "Título: " << book.title << endl;
        cout << "Autor: " << book.author << endl;
        cout << "Ano de publicação: " << book.year << endl;
        cout << "Cópias: " << book.copies << endl;
        cout << "\n";
    }
    return matched_books;
}

void insert(vector<Book> &books_vector) {
    string title, author;
    int year, copies;

    cout << "Preencha as informações do livro" << endl;
    cin.ignore();
    cout << "Título: "; getline(cin, title);
    cout << "Autor: "; getline(cin, author);
    cout << "Ano de lançamento: "; cin >> year;
    cout << "Número de cópias: "; cin >> copies;

    books_vector.push_back((Book){title, author, year, copies});
    cout << "Livro cadastrado com sucesso!";
}

Book* find(vector<Book> &books_vector, string title, string author) {
    for (Book &book : books_vector) {
        if (book.title == title && book.author == author) {
            return &book;
        }
    }
    cout << "Não foi encontrado nenhum livro com o título: " << title << " e autor: " << author << endl;
    return nullptr;
}

