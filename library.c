#include <stdio.h>
#include <string.h>

// Structure to store book details
struct Book {
    int id;
    char title[100];
    char author[100];
};

// Global array of books
struct Book library[100];
int bookCount = 0;

// Function to add a new book
void addBook() {
    struct Book newBook;
    printf("\nEnter Book ID: ");
    scanf("%d", &newBook.id);
    getchar(); 
    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; 
    printf("Enter Author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; 
    
    library[bookCount++] = newBook;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    printf("\nBooks in the Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

// Function to search for a book by title
void searchBook() {
    char searchTitle[100];
    printf("\nEnter the title of the book to search: ");
    getchar(); // Clear newline from buffer
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0'; 
    
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book Found - ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}