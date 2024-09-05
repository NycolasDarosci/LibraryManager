#include "book.hpp"
#include "iostream"
#include "vector"
#include "string"
using namespace std;

vector<Books> books;

int main () {
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

    insert(books, newBook);

    return 0;
}
