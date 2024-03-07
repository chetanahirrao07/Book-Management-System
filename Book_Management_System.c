#include <stdio.h>
#include <string.h>

struct book 
{
    int BookID;
    char BookName[10];
    char AuthorName[10];
    float Price;
    float Rating;
};

void store_b(struct book* b1, int size,int* num_of_b);
void Display_b(struct book* b1, int num_of_b);
void Add_b(struct book* b1, int size, int* num_of_b);
void Remove_b(struct book* b1, int* num_of_b);
void Search_b(struct book* b1, int num_of_b);
void ShowAuthor(struct book* b1, int num_of_b);
void Update_b(struct book* b1, int num_of_b);
void Display_Top3_Ratings(struct book* b1, int num_of_b);

int main() {
    int size = 10;
    struct book b1[size];
    int num_of_b = 0;
    int choice;

    do {
        printf("\n\t**-----------------------------------**\n");
        printf("\t  * Book Management System Project *\n");
        printf("\t**-----------------------------------**\n\n");
        printf("\t\t--- > MENU < ---\n\n");
        printf("\t1.  Store book information\n");
        printf("\t2.  Display book information\n");
        printf("\t3.  Add book information\n");
        printf("\t4.  Remove Book\n");
        printf("\t5.  Search Book\n");
        printf("\t6.  Show Authors Books\n");
        printf("\t7.  Update Book Data\n");
        printf("\t8.  Display Top 3 Books\n");
        printf("\t9.  Exit\n\n");

        printf("\tEnter one of the above :> ");
        scanf("%d", &choice);
        printf("\n");
        

        switch (choice) {
            case 1:
                store_b(b1, size, &num_of_b);
                break;

            case 2:
                Display_b(b1, num_of_b);
                break;

            case 3:
                Add_b(b1, size, &num_of_b);
                break;

            case 4:
                Remove_b(b1, &num_of_b);
                break;

            case 5:
                Search_b(b1, num_of_b);
                break;

            case 6:
                ShowAuthor(b1, num_of_b);
                break;

            case 7:
                Update_b(b1, num_of_b);
                break;

            case 8:
                Display_Top3_Ratings(b1, num_of_b);
                break;
        }
    } while (choice != 9);
    return 0;
}
void store_b(struct book* b1, int size, int* num_of_b) 
{
    if (*num_of_b < size) 
	{
        b1[0].BookID = 1;
        strcpy(b1[0].BookName, "Python");
        strcpy(b1[0].AuthorName, "abc");
        b1[0].Price = 50.0;
        b1[0].Rating = 5.5;
        (*num_of_b)++;
        
        b1[1].BookID = 2;
        strcpy(b1[1].BookName, "C");
        strcpy(b1[1].AuthorName, "xyz");
        b1[1].Price = 45.0;
        b1[1].Rating = 4.8;      
        (*num_of_b)++;
        
        b1[2].BookID = 3;
        strcpy(b1[2].BookName, "Sql");
        strcpy(b1[2].AuthorName, "xyz");
        b1[2].Price = 40.0;
        b1[2].Rating = 3.8;      
        (*num_of_b)++;
        
        printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t Book Stored Successfully \n");
        printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    } 
}
void Display_b(struct book* b1, int num_of_b) 
{
    int i;
    if (num_of_b == 0) {
        printf("\tNo books available to display.\n");
        return;
    }
    for (i = 0; i < num_of_b; i++) 
    {
    	printf("\t--------------------\n");
    	printf("\t   * ID: %d\n", b1[i].BookID);
        printf("\t   * Name: %s\n", b1[i].BookName);
        printf("\t   * Author: %s\n", b1[i].AuthorName);
        printf("\t   * Price: %.2f\n", b1[i].Price);
        printf("\t   * Rating: %.2f\n\n", b1[i].Rating);
        printf("\t--------------------\n");
    }
}
void Add_b(struct book* b1, int size, int* num_of_b) 
{
    char New_add = 'y';

    printf("\t~~~~~~~~~~~~~~~~~~\n");
    printf("\t  Add Your Book \n");
    printf("\t~~~~~~~~~~~~~~~~~~\n");
    printf("\n");

    while (New_add == 'y' && *num_of_b < size) 
    {
        int i = *num_of_b;

        printf("\tEnter Book ID: ");
        scanf("%d", &b1[i].BookID);

        printf("\tEnter Book Name: ");
        scanf("%s", b1[i].BookName);

        printf("\tEnter Author Name: ");
        scanf("%s", b1[i].AuthorName);

        printf("\tEnter Book price: ");
        scanf("%f", &b1[i].Price);

        printf("\tEnter The Rating: ");
        scanf("%f", &b1[i].Rating);
        printf("\n");

        (*num_of_b)++;
        
        printf("\t~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\tBook Added Successfully.\n");
        printf("\t~~~~~~~~~~~~~~~~~~~~~~~~\n");

        printf("\tDo You Want To Add Another Book ? (y/n): ");
        scanf(" %c", &New_add);
        printf("\n");
    }
}
void Remove_b(struct book* b1, int* num_of_b) 
{
    int choice;
    printf("\tHow would you like to remove the book?\n\n");
    printf("\t1. Remove by Book ID\n");
    printf("\t2. Remove by Book Name\n\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1) {
        int IDRemove;
        printf("\tEnter the ID of the book you want to remove: ");
        scanf("%d", &IDRemove);
        int i, j;
        for (i = 0; i < *num_of_b; i++) {
            if (b1[i].BookID == IDRemove)       // Comparing
			 {
                for (j = i; j < *num_of_b - 1; j++)   // shifting one book on left in array  
				 {
                    b1[j] = b1[j + 1];
                }
                (*num_of_b)--;
                printf("\tBook with ID %d is removed. \n", IDRemove);
                return;
            }
        }
        printf("\tBook with ID %d not found. \n", IDRemove);
    } 
    else if (choice == 2) 
    {
        char NameRemove[10];
        printf("\tEnter the name of the book you want to remove: ");
        scanf("%s", NameRemove);

        int i, j;
        int found = 0;
        for (i = 0; i < *num_of_b; i++) {
            if (strcmpi(b1[i].BookName, NameRemove) == 0) {
                for (j = i; j < *num_of_b - 1; j++) {
                    b1[j] = b1[j + 1];
                }
                (*num_of_b)--;
                printf("\tBook with Name '%s' is removed. \n", NameRemove);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\tBook with Name '%s' not found. \n", NameRemove);
        }
    } 
    else 
    {
        printf("\tInvalid choice.\n");
    }
}
void Search_b(struct book* b1, int num_of_b) {
    int choice;
    printf("\tHow would you like to search the book?\n\n");
    printf("\t1. Search by Book ID\n");
    printf("\t2. Search by Book Name\n\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1) {
        int Search_ID;
        printf("\tEnter the ID of the book you want to search: ");
        scanf("%d", &Search_ID);
        printf("\n");

        int i, found = 0;
        for (i = 0; i < num_of_b; i++) {
            if (b1[i].BookID == Search_ID) {
                printf("\t---> Book found <---\n");
                printf("\t--------------------\n");
            	printf("\t   * ID: %d\n", b1[i].BookID);
                printf("\t   * Name: %s\n", b1[i].BookName);
                printf("\t   * Author: %s\n", b1[i].AuthorName);
                printf("\t   * Price: %2f\n", b1[i].Price);
                printf("\t   * Rating: %2f\n", b1[i].Rating);
                printf("\t--------------------\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\tBook with ID %d not found.\n", Search_ID);
        }
    } else if (choice == 2) {
        char Search_Name[10];
        printf("\tEnter the name of the book you want to search: ");
        scanf("%s", Search_Name);
        printf("\n");

        int i, found = 0;
        for (i = 0; i < num_of_b; i++) {
            if (strcmpi(b1[i].BookName, Search_Name) == 0) {
                printf("\t---> Book found <---\n");
                printf("\t--------------------\n");
            	printf("\t   * ID: %d\n", b1[i].BookID);
                printf("\t   * Name: %s\n", b1[i].BookName);
                printf("\t   * Author: %s\n", b1[i].AuthorName);
                printf("\t   * Price: %2f\n", b1[i].Price);
                printf("\t   * Rating: %2f\n\n", b1[i].Rating);
                printf("\t--------------------\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\tBook with name '%s' not found.\n", Search_Name);
        }
    } 
    else 
    {
        printf("\tInvalid choice.\n");
    }
}
void ShowAuthor(struct book* b1, int num_of_b) 
{
    char SearchAuthor[10];
    int i;
    int found = 0;

    printf("\tEnter the name of the author's books you want to search: ");
    scanf("%s", SearchAuthor);
    printf("\n");

    for (i = 0; i < num_of_b; i++) 
    {
        if (strcmpi(b1[i].AuthorName, SearchAuthor) == 0) 
        {
            printf("\t---> Book found <---\n");
                printf("\t--------------------\n");
            	printf("\t   * ID: %d\n", b1[i].BookID);
                printf("\t   * Name: %s\n", b1[i].BookName);
                printf("\t   * Author: %s\n", b1[i].AuthorName);
                printf("\t   * Price: %.lf\n", b1[i].Price);
                printf("\t   * Rating: %.lf\n", b1[i].Rating);
                printf("\t--------------------\n");
            found = 1;
        }
    }
    if (!found) 
    {
        printf("\tBook with author '%s' not found.\n", SearchAuthor);
    }
}
void Update_b(struct book* b1, int num_of_b) {
    int choice;
    printf("\tHow would you like to update the book?\n\n");
    printf("\t1. Update by Book ID\n");
    printf("\t2. Update by Book Name\n\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1) {
        int UpdateId;
        printf("\tEnter the ID of the book you want to update: ");
        scanf("%d", &UpdateId);
        printf("\n");

        int i;
        int found = 0;
        for (i = 0; i < num_of_b; i++) {
            if (b1[i].BookID == UpdateId) {
                printf("\t---> Book found <---\n");
                printf("\t--------------------\n");
                printf("\t   * ID: %d\n", b1[i].BookID);
                printf("\t   * Name: %s\n", b1[i].BookName);
                printf("\t   * Author: %s\n", b1[i].AuthorName);
                printf("\t   * Price: %.2f\n", b1[i].Price);
                printf("\t   * Rating: %.2f\n", b1[i].Rating);
                printf("\t--------------------\n");

                printf("\tEnter the updated book ID: ");
                scanf("%d", &b1[i].BookID);

                printf("\tEnter the updated book name: ");
                scanf("%s", b1[i].BookName);

                printf("\tEnter the updated book author: ");
                scanf("%s", b1[i].AuthorName);

                printf("\tEnter the updated price: ");
                scanf("%f", &b1[i].Price);

                printf("\tEnter the updated rating: ");
                scanf("%f", &b1[i].Rating);

                printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\tBook updated successfully.\n");
                printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\tBook with ID %d not found.\n", UpdateId);
        }
    } else if (choice == 2) {
        char UpdateName[10];
        printf("\tEnter the name of the book you want to update: ");
        scanf("%s", UpdateName);

        int i;
        int found = 0;
        for (i = 0; i < num_of_b; i++) {
            if (strcmpi(b1[i].BookName, UpdateName) == 0) {
                printf("\t---> Book found <---\n");
                printf("\t--------------------\n");
            	printf("\t   * ID: %d\n", b1[i].BookID);
                printf("\t   * Name: %s\n", b1[i].BookName);
                printf("\t   * Author: %s\n", b1[i].AuthorName);
                printf("\t   * Price: %2f\n", b1[i].Price);
                printf("\t   * Rating: %2f\n", b1[i].Rating);
                printf("\t--------------------\n");
                
                printf("\tEnter the updated book ID: ");
                scanf("\t%d", &b1[i].BookID);
                
                printf("\tEnter the updated book name: ");
                scanf("\t%s", &b1[i].BookName);

                printf("\tEnter the updated book author: ");
                scanf("\t%s", b1[i].AuthorName);

                printf("\tEnter the updated price: ");
                scanf("\t%f", &b1[i].Price);

                printf("\tEnter the updated rating: ");
                scanf("\t%f", &b1[i].Rating);

                printf("\tBook updated successfully.\n");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\tBook with name '%s' not found.\n", UpdateName);
        }
    } else {
        printf("\tInvalid choice.\n");
    }
}
void Display_Top3_Ratings(struct book* b1, int num_of_b) 
{
    int i, j;
    struct book temp;

    for (i = 0; i < num_of_b - 1; i++) 
    {
        for (j = 0; j < num_of_b - 1 - i; j++) 
        {
            if (b1[j].Rating < b1[j + 1].Rating) 
            {
                temp = b1[j];
                b1[j] = b1[j + 1];
                b1[j + 1] = temp;
            }
        }
    }
    printf("\tTop 3 Books by Rating:\n\n");
    for (i = 0; i < 3 && i < num_of_b; i++) {
        printf("\tRank %d: %s (Rating: %.2lf)\n", i + 1, b1[i].BookName, b1[i].Rating);
    }
}