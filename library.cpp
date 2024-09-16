#include <iostream>
#include <string>
#include <vector>

#include "book.hpp"
#include "user.hpp"
#include "library.hpp"

using namespace std;

void loanBook(vector<Book> &books_vector, vector<User> &users_vector) {
    string name, title, author;
    cin.ignore();
    
    cout << "Digite o nome do usuário que irá emprestar: ";
    getline(cin, name);
    
    User* user = getByName(users_vector, name);
    
    cout << "Digite o título do livro: "; getline(cin, title);
    cout << "Digite o autor: "; getline(cin, author);
    
    Book* book = getBook(books_vector, title, author);
    
    if (book->copies == 0) {
        cout << "Sem o livro: " << book->title << " no estoque!";
        //return;
    }
    
    user->story_borrowed_books.append(book->title + " ");
    user->current_borrowed_books = user->current_borrowed_books.append(book->title.append(", " + book->author));
    user->balance++;
    book->copies--;
    
    cout << "Livro emprestado com sucesso!";
}
