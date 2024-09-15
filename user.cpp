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

    users_vector.push_back(User{name, 0});
    cout << "Usuário cadastrado com sucesso!";
}

// função apenas para ver se User foi criado. Desnessário para o projeto
void listAll(vector<User> &users_vector) {
    if (users_vector.empty()) {
        return;
    }
    
    for (const User& user : users_vector) {
        cout << "Nome: " << user.name << endl;
        cout << "Número de livros emprestados: " << user.balance << endl;
        cout << "Histórico de livros emprestados: " << user.story_borrowed_books << endl;
        cout << "Livro emprestado atualmente: " << user.current_borrowed_books << endl;
        cout << "\n";
    }
}

User& getUser(vector<User> &users_vector, string name) {
    //User &returnUser;
    for (User &user : users_vector) {
        if (user.name == name) {
            return user;
        }
    }
    //cout << "Não foi encontrado nenhum usuário com o nome: " << name << endl;
}