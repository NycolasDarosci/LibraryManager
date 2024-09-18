#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "book.hpp"
#include "user.hpp"
#include "library.hpp"

using namespace std;

void borrow_book(vector<Book> &books_vector, vector<User> &users_vector) {
    time_t current_time = time(NULL);

    SelectedUser selected_user = select_user(users_vector);

    User *user = find_by_name(users_vector, selected_user.user->name);
    if (user == nullptr) {
        cout << "Usuário não encontrado!" << endl;
        return;
    }

    Book *book = select_book(books_vector).book;

    if (book->copies == 0) {
        cout << "Sem o livro: " << book->title << " no estoque!";
    } else {
        // Define o tempo de uma semana em segundos (7 dias * 24 horas * 3600 segundos por hora).
        const time_t one_week = 7 * 24 * 3600;
        // Adiciona o tempo de uma semana no tempo atual (1 semana do momento do aluguel).
        time_t future_time = current_time + one_week;

        user->story_borrowed_books.push_back(*book);
        user->current_borrowed_books.push_back((UserBorrowedBook){
            .book = book,
            .return_date = future_time
        });
        user->balance++;
        book->copies--;
        book->number_of_loans++;

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
        cout << "Número de empréstimos: " << book.number_of_loans << endl;

        total_number_loans += book.number_of_loans;

        if (book.number_of_loans > most_popular_books[2].number_of_loans) {
            most_popular_books[2] = book;

            for (int i = 2; i > 0; i--) {
                if (most_popular_books[i].number_of_loans > most_popular_books[i - 1].number_of_loans) {
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
        cout << "\nUsuário não contém livros em empréstimo\n";
        return;
    }

    for(int i = 0; i <= selected_user.user->current_borrowed_books.size() - 1; i++){
        UserBorrowedBook* current_borrowed_book = &selected_user.user->current_borrowed_books[i];
        cout << "\nTítulo: " << current_borrowed_book->book->title << endl;
        cout << "Autor: " << current_borrowed_book->book->author << endl;
        cout << "Ano: " << current_borrowed_book->book->year << endl;
        cout << "Número de Cópias: " << current_borrowed_book->book->number_of_loans << endl;
        cout << "Final do empréstimo: (1 semana após o aluguel) " << ctime(&current_borrowed_book->return_date) << endl;
    }
}

void return_book(vector<Book> &books_vector, vector<User> &users_vector) {
    SelectedUser selected_user = select_user(users_vector);

    if (selected_user.user->current_borrowed_books.size() == 0) {
        cout << "\nUsuário não contém livros em empréstimo \n";
        return;
    }

    vector<Book> books;
    for (const UserBorrowedBook &borrowedBook : selected_user.user->current_borrowed_books) {
        books.push_back(*borrowedBook.book);
    }
    SelectedBook selected_book = select_book(books);

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

void loan_fine(vector<User> &users_vector) {
    time_t current_time = time(NULL);

    if (users_vector.size() == 0) {
        cout << "Sua biblioteca ainda não consta usuários no sistema.\n";
    } else {
        for (User &user : users_vector) {

            for (const UserBorrowedBook &borrowed_book : user.current_borrowed_books) {
                if (borrowed_book.return_date < current_time) {
                    cout << "\nO período de empréstimo do usuário " << user.name << " para o livro " << borrowed_book.book->title << " expirou!\n";
                    cout << "Expirou em: " << ctime(&borrowed_book.return_date);
                    cout << "Adicionada uma multa de R$ 20.\n";
                    user.balance -= 20;
                } else {
                    cout << "\nO período de empréstimo do usuário " << user.name << " para o livro " << borrowed_book.book->title << " está em dia.\n";
                    cout << "Irá expirar em: " << ctime(&borrowed_book.return_date) << endl;
                }
            }

        }
    }
}
