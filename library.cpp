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

    User *user = find_by_name(users_vector, name);
    if (user == nullptr) {
        cout << "Usuário não encontrado!" << endl;
        return;
    }

    Book *book = select_book(books_vector).book;

    if (book->copies == 0) {
        cout << "Sem o livro: " << book->title << " no estoque!";
    } else {
        user->story_borrowed_books.push_back(*book);
        user->current_borrowed_books.push_back(*book);
        user->balance++;
        book->copies--;
        book->numberOfLoans++;

        cout << "Livro emprestado com sucesso!";
    }
}

void loan_report(vector<Book> &books_vector, vector<User> &users_vector) {
    Book most_popular_books[3];
    User most_active_users[3];
    int total_number_loans = 0;

    for (int i = 0; i < 3; i++) {
        most_popular_books[i] = Book();
        most_active_users[i] = User();
    }

    for (const Book& book : books_vector) {
        cout << "Título: " << book.title << endl;
        cout << "Número de empréstimos: " << book.numberOfLoans << endl;

        total_number_loans += book.numberOfLoans;

        if (book.numberOfLoans > most_popular_books[2].numberOfLoans) {
            most_popular_books[2] = book;

            for (int i = 2; i > 0; i--) {
                if (most_popular_books[i].numberOfLoans > most_popular_books[i - 1].numberOfLoans) {
                    Book temp = most_popular_books[i];
                    most_popular_books[i] = most_popular_books[i - 1];
                    most_popular_books[i - 1] = temp;
                } else {
                    break;
                }
            }
        }

        cout << "\n";
    }

    for (const User& user : users_vector) {
        if (user.current_borrowed_books.size() > most_active_users[2].current_borrowed_books.size()) {
            most_active_users[2] = user;

            for (int i = 2; i > 0; i--) {
                if (most_active_users[i].current_borrowed_books.size() > most_active_users[i - 1].current_borrowed_books.size()) {
                    User temp = most_active_users[i];
                    most_active_users[i] = most_active_users[i - 1];
                    most_active_users[i - 1] = temp;
                } else {
                    break;
                }
            }
        }
    }

    cout << "O número total de empréstimos da biblioteca é: " << total_number_loans << endl;

    cout << "Os 3 livros mais populares são: " << endl;
    for (int i = 0; i < 3; i++) {
        if (!most_popular_books[i].title.empty()) {
            cout << "Título: " << most_popular_books[i].title << endl;
        }
    }

    cout << "Os 3 usuários mais ativos são: " << endl;
    for (int i = 0; i < 3; i++) {
        if (!most_active_users[i].name.empty()) {
            cout << "Nome: " << most_active_users[i].name << endl;
        }
    }
}

void list_book_by_user(vector<User> &users_vector){
    SelectedUser selected_user = select_user(users_vector);

    if (selected_user.user->current_borrowed_books.size() == 0) {
        cout << "\nUsuário não contém livros em empréstimo \n";
        return;
    }

    for(int i = 0; i <= selected_user.user->current_borrowed_books.size() - 1; i++){
        Book* current_borrowed_book = &selected_user.user->current_borrowed_books[i];
        cout << "Título: " << current_borrowed_book->title << endl;
        cout << "Autor: " << current_borrowed_book->author << endl;
        cout << "Ano: " << current_borrowed_book->year << endl;
        cout << "Cópias: " << current_borrowed_book->copies << endl;
        cout << "Número de Cópias: " << current_borrowed_book->numberOfLoans << endl;
    }
}

void return_book(vector<Book> &books_vector, vector<User> &users_vector) {
    SelectedUser selected_user = select_user(users_vector);

    if (selected_user.user->current_borrowed_books.size() == 0) {
        cout << "\nUsuário não contém livros em empréstimo \n";
        return;
    }

    SelectedBook selected_book = select_book(selected_user.user->current_borrowed_books);

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
