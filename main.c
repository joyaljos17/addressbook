/*
    JOYAL JOSE
    03-02-2026
    PROJECT01-ADDRESSBOOK 
    Description:
    Address Book is a C-based application developed to create and manage 
    contacts containing name, phone number, and email ID. 
    The system validates all inputs before storing them and uses file handling to support persistent storage. 
    It provides a menu-driven interface to perform core operations such as creating, searching (by name, phone number, or email), 
    editing, deleting, and listing contacts. All modifications are written to the file when the user selects the "Save and Exit" option, 
    allowing contacts to be reloaded and maintained across program executions.
*/
#include <stdio.h>
#include "contact.h"

int main() 
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do 
    {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save and Exit\n");		
        // printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
