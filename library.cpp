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
    
    cout << "Digite o título do livro: "; getline(cin, title);
    cout << "Digite o autor: "; getline(cin, author);
    
    Book* book = find(books_vector, title, author);
    
    if (book->copies == 0) {
        cout << "Sem o livro: " << book->title << " no estoque!";
    } else {
        user->story_borrowed_books.append(book->title + " ");
        user->current_borrowed_books = user->current_borrowed_books.append(book->title.append(", " + book->author));
        user->balance++;
        book->copies--;

        cout << "Livro emprestado com sucesso!";
    }

}
