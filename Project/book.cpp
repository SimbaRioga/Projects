#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//  declare global variables such as an array to store inventory of books
const int = maxBooks = 25; // maximum number of books
Book inventory[maxBooks];  // array to store the inventory
int numBooks = 0;          // number of books in the inventory

// define a structure to represent a book
struct Book
{
    string title;
    string author;
    string genre;
    string isbn;
    int quantity;
};
// declare prototypes for functions you will implement later
void displayMenu() // gives menu choices
{
    cout << "====Library Management System====" << endl;
    cout << "1. Add a book to the inventory" << endl;
    cout << "2. Remove a book from the inventory" << endl;
    cout << "3. Search for a book in the inventory" << endl;
    cout << "4. Display all the books in the inventory" << endl;
    cout << "5. Save inventory to file" << endl;
    cout << "6. Load inventory from file" << endl;
    cout << "7. Exit the program" << endl;
    cout << "Please enter 1-7." << endl;
};
void addBook()
{
    // check if inventory is full
    if (numBooks >= maxBooks)
    {
        cout << "Error: inventory is full" << endl;
        return;
    }

    // prompt user for book details
    cout << "Enter book details: " << endl;
    Book newBook;
    cout << "Title: " << endl;
    cin.ignore(); // ignore any leftover newline characters
    getline(cin, newBook.title);
    cout << "Author: " << endl;
    cin.ignore();
    getline(cin, newBook.author);
    cout << "Genre: " << endl;
    cin.ignore();
    getline(cin, newBook.genre);
    cout << "ISBN: " << endl;
    cin >> newBook.isbn;
    cout << "Quantity: " << endl;
    cin >> newBook.quantity;

    // check if a book with the same ISBN already exists
    for (int i = 0; i < numBooks; i++)
    {
        if (inventory[i].isbn == newBook.isbn)
        {
            // update the quantity of the book
            inventory[i].quantity = newBook.quantity;
            cout << "Existing book updated with additional copies." << endl;
            return;
        }
    }

    // add the new book to the inventory
    inventory[numBooks++] = newBook;
    cout << "New book added to inventory." << endl;
};
void removeBook();
void searchBooks();
void displayAllBooks();
void saveInventoryToFile();
void loadInventoryFromFile();
void exit();

int main()
{
    int choice;

    do
    {
        displayMenu(); // display the menu
        cin >> choice; // user inputs the choice number

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            searchBooks();
            break;
        case 4:
            displayAllBooks();
        case 5:
            saveInventoryToFile();
        case 6:
            loadInventoryFromFile();
        case 7:
            exit();
        default:
            cout << "Invalid choice. Please choose 1-7." << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}