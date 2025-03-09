#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book {
    int bookID;
    char bookName[50];
    char authorName[50];
    char bookCategory[50];
    float bookPrice;
    float bookRating;
};

typedef struct Book Book;

void addBook(Book* b, int* size)
 {
    int a;
    printf("Enter how many books you want to add: ");
    scanf("%d", &a);
    for (int i = *size; i < *size + a; i++) 
 {
        printf("Enter book ID: ");
        scanf("%d", &b[i].bookID);
        printf("Enter book name: ");
        scanf(" %s", b[i].bookName);  
        printf("Enter author name: ");
        scanf(" %s", b[i].authorName);
        printf("Enter book price: ");
        scanf("%f", &b[i].bookPrice);
        printf("Enter book rating: ");
        scanf("%f", &b[i].bookRating);
        printf("Enter book category: ");
        scanf(" %s", b[i].bookCategory);
        printf("The books added successfully!\n");
    }
    *size += a;
}

void removeBook(Book* b, int* size)
 {
    int id;
    int found = 0;
    printf("Enter book ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < *size; i++)
  {
        if (b[i].bookID == id) 
  {
            found = 1;
            for (int j = i; j < *size - 1; j++) 
   {
                b[j] = b[j + 1];
            }
            (*size)--;  
            printf("Book removed successfully!\n");
            break;
        }
    }
    if (!found) 
 {
        printf("Book not found!\n");
    }
}

void searchBookByID(Book* b, int size)
 {
    int ID;
    printf("Enter the ID of the book: ");
    scanf("%d", &ID);
    int found = 0;
    for (int i = 0; i < size; i++)
  {
        if (b[i].bookID == ID)
  {
            printf("Found: %s by %s\n", b[i].bookName, b[i].authorName);
            found = 1;
            break;
        }
    }
    if (!found) 
 {
        printf("Book not found!\n");
    }
}

void searchByBookName(Book* b, int size) 
{
    char nm[50];
    printf("Enter the book name: ");
    scanf(" %s", nm);
    int found = 0;
    for (int i = 0; i < size; i++) 
 {
        if (strcmp(b[i].bookName, nm) == 0) 
  {
            printf("Found: %s by %s\n", b[i].bookName, b[i].authorName);
            found = 1;
            break;
        }
    }
    if (!found) 
 {
        printf("Book name not found!\n");
    }
}

void authorBook(Book* b, int size)
 {
    char author[100];
    printf("Enter the author name: ");
    scanf(" %s", author);
    int found = 0;
    for (int i = 0; i < size; i++) 
 {
        if (strcmp(b[i].authorName, author) == 0)
  {
            printf("Found: %s in category %s priced at %f\n", b[i].bookName, b[i].bookCategory, b[i].bookPrice);
            found = 1;
        }
    }
    if (!found) 
 {
        printf("No book found by that author!\n");
    }
}

void categoryBook(Book* b, int size)
 {
    char bookCategory[100];
    printf("Enter category: ");
    scanf(" %s", bookCategory);
    int found = 0;
    for (int i = 0; i < size; i++)
 {
        if (strcmp(b[i].bookCategory, bookCategory) == 0) 
  {
            printf("Found: %s priced at %f\n", b[i].bookName, b[i].bookPrice);
            found = 1;
        }
    }
    if (!found)
 {
        printf("No book found in that category!\n");
    }
}

void updateBook(Book* b, int size)
 {
    int id;
    printf("Enter the ID of the book to update: ");
    scanf("%d", &id);
    int index = -1;

    for (int i = 0; i < size; i++) 
 {
        if (b[i].bookID == id) 
  {
            index = i;
            break;
        }
    }

    if (index == -1) 
 {
        printf("Book not found!\n");
        return;
    }

    int ch,i;
    printf("Enter the choice:\n1. Update price\n2. Update rating\n");
    scanf("%d", &ch);

    if (ch == 1) 
 {
        printf("Old book price is %.2f\n", b[i].bookPrice);
        printf("Enter new price: ");
        scanf("%f", &b[i].bookPrice);
    } 
 else if (ch == 2)
 {
        printf("Old book rating is %.2f\n", b[i].bookRating);
        printf("Enter new rating: ");
        scanf("%f", &b[i].bookRating);
    } 
 else
 {
        printf("Invalid choice!\n");
    }
}

void sortBooksByPrice(Book* b, int size) 
{
    for (int i = 0; i < size - 1; i++) 
 {
        for (int j = 0; j < size - i - 1; j++) 
  {
            if (b[j].bookPrice > b[j + 1].bookPrice)
    {
                Book temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    printf("Books sorted by price successfully!\n");
}

void displayAllBooks(Book* b, int size)
 {
    if (size == 0) 
 {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < size; i++) 
 {
        printf("Book ID: %d\n", b[i].bookID);
        printf("Book Name: %s\n", b[i].bookName);
        printf("Author: %s\n", b[i].authorName);
        printf("Category: %s\n", b[i].bookCategory);
        printf("Price: %f\n", b[i].bookPrice);
        printf("Rating: %f\n", b[i].bookRating);
        printf("------------------------\n");
    }
}

int main() 
{
    int size;
    Book* b = (Book*)malloc(sizeof(Book) * size);

    if (b == NULL) 
 {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int ch;
    do {
        printf("Enter choice:\n");
        printf("1.Add Book\n 2.Remove Book\n 3.Search by ID\n 4.Search by Name\n 5.Search by Author\n 6.Search by Category\n 7.Update Book\n 8.Sort Books by Price\n 9.Display All Books\n");
        scanf("%d", &ch);

        switch (ch)
   {
            case 1:
                addBook(b, &size);
                break;
            case 2:
                removeBook(b, &size);
                break;
            case 3:
                searchBookByID(b, size);
                break;
            case 4:
                searchByBookName(b, size);
                break;
            case 5:
                authorBook(b, size);
                break;
            case 6:
                categoryBook(b, size);
                break;
            case 7:
                updateBook(b, size);
                break;
            case 8:
                sortBooksByPrice(b, size);
                break;
            case 9:
                displayAllBooks(b, size);
                break;
        }
    }
  while (ch != 0);

    free(b);
    return 0;
}