#include <iostream>
#include <string>

#include "book.hpp"
#include "vector"

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

        if (matches) {
            matched_books.push_back(book);
        }
    }

    return matched_books;
}

void listAll(vector<Books> &books_vector) {
    if (books_vector.empty()) {
        return;
    }
    
    for (const Books& book : books_vector) {
        cout << "Título: " << book.title << endl;
        cout << "Autor: " << book.author << endl;
        cout << "Ano de publicação: " << book.year << endl;
        cout << "Cópias: " << book.copies << endl;
        cout << "\n";
    }
}


void insert(vector<Books> &books_vector) {
    string title, author;
    int year, copies;

    cout << "Preencha as informações do livro" << endl;
    cin.ignore();
    cout << "Título: "; getline(cin, title);
    cout << "Autor: "; getline(cin, author);
    cout << "Ano de lançamento: "; cin >> year;
    cout << "Número de cópias: "; cin >> copies;

    books_vector.push_back(Books{title, author, year, copies});
    cout << "Livro cadastrado com sucesso!";
}

Books& getBook(vector<Books> &books_vector, string title, string author) {
    //Books &returnBook;
    for (Books &book : books_vector) {
        if (book.title == title && book.author == author) {
            return book;
        }
    }
    //cout << "Não foi encontrado nenhum livro com o título: " << title << " e autor: " << author << endl;
}

