#include <iostream>
#include <string>

#include "user.hpp"
#include "vector"

using namespace std;

void insert(vector<User> &users_vector) {
    string name;

    cout << "Digite o nome do usuário: ";
    cin.ignore();
    getline(cin, name);

    users_vector.push_back((User){name, 0});
    cout << "Usuário cadastrado com sucesso!";
}

// função apenas para ver se User foi criado. Desnessário para o projeto
void list(vector<User> &users_vector) {
    if (users_vector.empty()) {
        return;
    }
    
    for (const User& user : users_vector) {
        cout << "Nome: " << user.name << endl;
        cout << "Número de livros emprestados: " << user.balance << endl;
        for (const Book& book : user.story_borrowed_books) {
            cout << "Histórico de livros emprestados: " << book.title << endl;
        }
        for (const Book& book : user.current_borrowed_books) {
            cout << "Livro emprestado atualmente: " << book.title << endl;
        }
        cout << "\n";
    }
}

User* find_by_name(vector<User> &users_vector, const string name) {
    for (User &user : users_vector) {
        if (user.name == name) {
            return &user;
        }
    }
    return nullptr;
}