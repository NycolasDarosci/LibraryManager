#include <iostream>
#include <string>
#include <vector>

#include "book.hpp"
#include "user.hpp"
#include "library.hpp"

using namespace std;

void borrow_book(vector<Book> &books_vector, vector<User> &users_vector) {
    string name, title, author;
    cin.ignore();
    
    cout << "Digite o nome do usuário que irá emprestar: ";
    getline(cin, name);
    
    User* user = find_by_name(users_vector, name);
    if (user == nullptr) {
        cout << "Usuário não encontrado!" << endl;
        return;
    }
    
    cout << "Digite o título do livro: "; getline(cin, title);
    cout << "Digite o autor: "; getline(cin, author);
    
    Book* book = find(books_vector, title, author);
    if (book == nullptr) {
        cout << "Livro não encontrado!" << endl;
        return;
    }

    if (book->copies == 0) {
        cout << "Sem o livro: " << book->title << " no estoque!";
    } else {
        user->story_borrowed_books.push_back(*book);
        user->current_borrowed_books.push_back(*book);
        user->balance++;
        book->copies--;

        cout << "Livro emprestado com sucesso!";
    }
}

void return_book(vector<Book> &books_vector, vector<User> &users_vector) {
    SelectedUser selected_user = select(users_vector);

    if (selected_user.user->current_borrowed_books.size() == 0) {
        cout << "\nUsuário não contém livros em empréstimo \n";
        return;
    }

    SelectedBook selected_book = select(selected_user.user->current_borrowed_books);

    Book* book = find(books_vector, selected_book.book->title, selected_book.book->author);
    if (book == nullptr) {
        cout << "Livro não encontrado!" << endl;
        return;
    }

    book->copies += 1;
    selected_user.user->current_borrowed_books.erase(selected_user.user->current_borrowed_books.begin() + selected_book.index - 1);

    cout << "\nDevolução do livro " << book->title << " realizada com sucesso!\n";
    cout << "Livro contém agora " << book->copies << " cópias.\n";
}
