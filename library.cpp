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
    cout << "Digite o número do usuário que irá devolver:\n";
    for (int i = 1; i <= users_vector.size(); i++) {
        cout << users_vector.at(i - 1).name << " (" << i << ") \n";
    }
    int selected_user_index;
    cin >> selected_user_index;
    User *selected_user = &users_vector.at(selected_user_index - 1);

    if (selected_user->current_borrowed_books.size() == 0) {
        cout << "\nUsuário não contém livros em empréstimo \n";
        return;
    }

    cout << "\nDigite o número do livro a ser devolvido:\n";
    for (int i = 1; i <= selected_user->current_borrowed_books.size(); i++) {
        cout << selected_user->current_borrowed_books.at(i - 1).title << " (" << i << ") \n";
    }
    int selected_book_index;
    cin >> selected_book_index;
    Book *selected_book = &selected_user->current_borrowed_books.at(selected_book_index - 1);

    Book* book = find(books_vector, selected_book->title, selected_book->author);
    if (book == nullptr) {
        cout << "Livro não encontrado!" << endl;
        return;
    }

    book->copies += 1;
    selected_user->current_borrowed_books.erase(selected_user->current_borrowed_books.begin() + selected_book_index - 1);

    cout << "\nDevolução do livro " << book->title << " realizada com sucesso!\n";
    cout << "Livro contém agora " << book->copies << " cópias.\n";
}
