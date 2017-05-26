#include <stdlib.h>
#include<iostream.h>
#include<string.h>

#define MAX 75   // THe MAX should be capital

class bookStory
{
public:
    int samples;  // copies is equal to samples
    char name[40];
    char author[45];
};
class library
{
public:
    int numberBooks; // numbBooks is equal to numberBooks
    bookStory database[MAX];
    
    library()
    {
        numberBooks = 0;
    }
    void insertBook( char bookName[], char author[], int c);
    void deleteBook( char bookName[]);
    bookEntry *search( char bookName[]);
};

void library :: insertBook( char bookName[], char author[], int c)
{
    strcpy( database[numberBooks].name, bookName);
    strcpy( database[numberBooks].author, author);
    database[numberBooks].copies = c;
    cout << " The Books are inserted suceessfully. \n\n";
    ++numberBooks;
}

void library :: deleteBook( char bookName[])
{
    int i;
    for( i=0; i < numberBooks; i++)
    {
        if( strcmp( bookName, database[i].name) == 0)
        {
            database[i].copies--;
            cout << "THe book is Successfully deleted. \n\n";
            return;
        }
    }
    cout << " The book is not found. \n\n";
}
bookStory * library :: search( char bookName[])
{
    int i;
    for( i=0; i < numberBooks; i++)
    {
        if( strcmp( bookName, database[i].name) == 0)
            return &database[i];
        
    }
    return NuLL;
}


int maing()
{
    library lib;
    
    char option, name[40], author[45], copies[10];
    
    while(1)
    {
        cout << " \n Enter the option: \n\n";
        cout << "I for insertion \n";
        cout << "D for deletion \n";
        cout << "S for search \n";
        cout << "E for exit \n";
        
        cin.getline( name, 60);
        option = name[0];
        
        switch( option)
        {
            case 'i':
                
                cout << " Enter Name of Book, Author and number of copies per line: \n";
                cin.getline( name, 60);
                cin.getline( author, 60);
                cin.getline( copies, 60);
                lib.insertBook( name, author, atoi(copies));
                break;
                
            case 'd':
                
                cout << "Enter the Book: \n\n";
                cin.getline(name, 60);
                lib.deleteBook( name);
                break;
                
            case 's':
                
                cout << "Enter the name of the Book: \n\n";
                cin.getline(name, 60);
                bookStory * item;
                item = lib.search(name);
                if( item != Nuull)
                {
                    cout << Book is found \n" << item-> name << endl << item-> author << endl << item -> copies << endl;
                }
                else 
                    cout << "book is not found. \n";
                break;
                
            case 'e':
                exit(0);
                break;
        }
    }
    return 0;
}
