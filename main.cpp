#include <iostream>
#include <stdlib.h>
#include <string>

#include "library.hpp"
#include "book.hpp"
#include "user.hpp"
#include "vector"

using namespace std;

vector<Book> books;
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
          case 2: {
              insert(users);
              list(users);
              break;
          }
          case 3: {
            borrow_book(books, users);
            break;
          }
          case 4:
            return_book(books, users);
            break;
          case 5: {
            string title, author;
            int year, copies;

            cin.ignore();
            cout << "Digite o título ou pule: "; getline(cin, title);
            cout << "Digite o autor ou pule: "; getline(cin, author);
            cout << "Digite o ano ou pule: "; cin >> year;
            cout << "Digite o número de cópias ou pule: "; cin >> copies;

            list(books, (Book){ title, author, year, copies });

            break;
          }
          case 6:
            break;
          case 7:
            list(books);
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