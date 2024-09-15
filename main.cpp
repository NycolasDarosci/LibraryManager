#include <iostream>
#include <stdlib.h>
#include <string>

#include "library.hpp"
#include "book.hpp"
#include "user.hpp"
#include "vector"

using namespace std;

vector<Books> books;
vector<User> users;

int main () {

  int option;
  do {
        do {
            cout << "\n*Biblioteca*\n";
            cout << "Escolha uma option de acordo com o numero:\n";
            cout << "Cadastro de Livros (1)\n";
            cout << "Cadastro de Usuários (2)\n";
            cout << "Empréstimo de Livros (3)\n";
            cout << "Devolução de Livros (4)\n";
            cout << "Pesquisa de Livros (5)\n";
            cout << "Pesquisa de Livros por Usuário (6)\n";
            cout << "Listagem de Livros (7)\n";
            cout << "Controle de Multas (8)\n";
            cout << "Relatórios de empréstimo (9)\n";
            cout << "Sair (10)\n";
            cin >> option;
            system("cls || clear");
        } while (option < 1 || option > 10);

        switch (option) {
          case 1:
            insert(books);
            break;
          case 2:
            insert(users);
            listAll(users);
            break;
          case 3: {
                borrowBook(books, users);
                break;
            }
          case 4:
            break;
          case 5: {
                string title, author;
                int year;
                
                cin.ignore();
                cout << "Digite o título ou pule: "; getline(cin, title);
                cout << "Digite o autor ou pule: "; getline(cin, author);
                cout << "Digite o ano ou pule: "; cin >> year;
                
                vector<Books> booksSearched = list(books, Books{title, author, year});
                
                for (const Books& book : booksSearched) {
                    cout << "Título: " << book.title << endl;
                    cout << "Autor: " << book.author << endl;
                    cout << "Ano de publicação: " << book.year << endl;
                    cout << "Cópias: " << book.copies << endl;
                    cout << "\n";
                }
                break;
            }
          case 6:
            break;
          case 7:
            listAll(books);
            break;
          case 8:
            break;
          case 9:
            break;
          default:
            break;
        }
        
    } while (option != 10);
    
    cout << "Voce saiu!\n";

    return 0;
}