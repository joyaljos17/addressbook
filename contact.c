#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("\nCONTACT DETAILS\n");
    printf("%-7s %-15s %-15s %-15s\n","SL.NO","NAME","PHONE","EMAIL");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%-7d %-15s %-15s %-15s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    char name[20];

    int i=5;
    while(i)
    {
        printf("\nEnter the Name\n");
        scanf(" %[^\n]",name);
        int res =validate_name(name);
        if (res==0)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].name,name);
            break;
        }
        printf("%d attempts remaining\n",--i);
    }
     if(i==0)
        {
            printf("INVALID ENTRY!");
            return;
        }
    

    char phone[12];

    i=5;
    while(i)
    {
    printf("Enter the Phone\n");
    scanf("%s",phone);
    int res =validate_phone(phone,addressBook);
    if(res==0)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
        break;

    }
     printf("%d attempts remaining\n",--i);

    }
     if(i==0)
    {
        printf("INVALID ENTRY!");
        return;
    }


    char email[20];

    i=5;
    while(i)
    {
    printf("Enter the email\n");
    scanf("%s",email);
    int res =validate_email(email,addressBook);
    if(res==0)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].email,email);
        break;

    }
     printf("%d attempts remaining\n",--i);

    }
 if(i==0)
    {
       printf("INVALID ENTRY!");
       return;
    }
    (addressBook->contactCount)++;

	/* Define the logic to create a Contacts */
    
}

int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;
    do 
    {
        printf("\nSEARCH CONTACT:\n");
        printf("1. Search by Name\n");
        printf("2. Search by Phone\n");
        printf("3. Search by Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
               return search_byname(addressBook);
                break;
            case 2:
                return search_byphone(addressBook);
                break;
            case 3:
                return search_byemail(addressBook);
                break;
            case 4:
                printf("Exiting...\n");
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice !=4 );
    return 1000;
}



void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int res=searchContact(addressBook);
    int choice;
    do 
    {
        printf("\nEDIT CONTACT:\n");
        printf("1. Edit by Name\n");
        printf("2. Edit by Phone\n");
        printf("3. Edit by Email\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                    char name[50];
                    int i=5;
                        while(i)
                        {
                            printf("Enter new name\n");  
                            getchar();
                            scanf("%[^\n]",name);
                            int result =validate_name(name);
                            if(result==0)
                            {
                                strcpy(addressBook->contacts[res].name,name);
                                break;
                            }
                            printf("%d attempts remaining\n",--i);

                        }
                       if(i==0)
                        {
                            printf("INVALID ENTRY!");
                            return;
                        }
                     break;
            case 2:
                        char phone[12];
                        i=5;
                        while(i)
                        {
                        printf("Enter the NewPhone number\n");
                        scanf("%s",phone);
                        int result =validate_phone(phone,addressBook);
                        if(result==0)
                        {
                            strcpy(addressBook->contacts[res].phone,phone);
                            break;

                        }
                        printf("%d attempts remaining\n",--i);

                        }
                        if(i==0)
                        {
                            printf("INVALID ENTRY!");
                            return;
                        }
                        
                                    
                    break;
            case 3:
                    char email[20];

                    i=5;
                    while(i)
                    {
                    printf("Enter the email\n");
                    scanf("%s",email);
                    int result =validate_email(email,addressBook);
                    if(result==0)
                    {
                        strcpy(addressBook->contacts[res].email,email);
                        break;

                    }
                    printf("%d attempts remaining\n",--i);

                    }
                     if(i==0)
                        {
                            printf("INVALID ENTRY!");
                            return;
                        }
                    break;
            case 4:
                printf("Exiting...\n");
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice !=4 );

    return ;


}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char choice;
     int res=searchContact(addressBook);
     printf("Do you want to delete(y/n)\n");
     getchar();
     scanf("%c",&choice);
     if(choice=='y')
     {
     for(int i=res;i<addressBook->contactCount;i++)
     {
        addressBook->contacts[i]=addressBook->contacts[i+1];
     }
        addressBook->contactCount--;
        printf("Succesfully Deleted\n");
    }
    else
    {
        printf("Not deleted!");
        return;
    }
}
int validate_name(char *str)
{

    int length=strlen(str);
    if(length<4)
    {
        printf("Entered Name must contain at least 4 characters\n");
        return 1;
    }
    if(!(isalnum(str[length-1])))
    {
        printf("Last digit should be either alpahabet or number\n");
        return 1;
    }
    int i=0;
    while(i<=(length-2))
    {
       if(!isalpha(str[i]) && (str[i]!=' '))
       {
        printf("Entered Name should contain only alphabets\n ");
        return 1;
       }
       i++;
    }
    return 0;

    
}
int validate_phone(char *str,AddressBook *addressBook)
{

    int length=strlen(str);
    if(length!=10)
    {
        printf("Entered phonenumber should have 10 numbers\n");
        return 1;
    }
    int i=0;
    while(str[i]!=('\0'))
    {
       if(!isdigit(str[i]))
       {
        printf("Entered phonenumber should contain numbers\n");
        return 1;
       }
       i++;
    }
    if (!(str[0]>='6' && str[0]<= '9'))
    {
        printf("Entered phonenumber should be between 6 and 9\n");
        return 1;
    }
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(str,addressBook->contacts[i].phone) == 0)
        {
            printf("Entered phonenumber should be unique\n");
            return 1;
        }
    }

      return 0;
    
    
}
int validate_email(char *str,AddressBook *addressBook)
{
    //startingalphabet
    if (!isalpha(str[0]))
    {
        printf("Entered email should start with alphabet\n");
        return 1;
    }


    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '@')
            count++;
    }

    if (count != 1)
    {
        printf("Entered email should have  one @\n");
        return 1;
    }
    
    char *check=strstr(str,".com");
    if (check == NULL)
    {
        printf("Entered email should contain .com\n");
        return 1;
    }
    if(strcmp(check,".com"))
    {
        printf("Entered email should not contain alphabets and numerals after.com\n");
        return 1;

    }


    //lowercase
    for (int i = 0;str[i] != '\0'; i++)
    {
        if (isupper(str[i]))
        {
            printf("Entered email should contain lowercase\n");
            return 1;
        }
    }

    char *at = strchr(str, '@');
    char *dot = strrchr(str, '.');

if (at == NULL)
{
    printf("Entered email should contain @ \n");
    return 1;
}

if (dot == NULL)
{
    printf("Entered email should contain .(dot)\n");
    return 1;
}

if (dot < at)
{
    printf("In Entered email. (dot) must appear after @ symbol\n");
    return 1;
}


if (dot - at <= 1)
{
    printf("Entered email should contain @ and . between\n");
    return 1;
}
for(char *i=at+1;i<dot;i++)
{
    if(!(isalpha(*i)))
    {
        printf("Entered email should contain only alphabets or digits after @ and before .\n");
    }
}
    //unique
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(str, addressBook->contacts[i].email) == 0)
        {
            printf("Entered email must be unique\n");
            return 1;
        }
    }
    return 0;
}

int search_array[100];

int search_byname(AddressBook *addressBook)
{
    char str[50];
    printf("Enter the name\n");
    getchar();
    scanf("%[^\n]",str);
    int j=0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcasestr(addressBook->contacts[i].name,str))
        {
            search_array[j]=i;
            printf("%d. %-15s %-15s %-15s\n",++j,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    if(j==0)
    {
        printf("Contact not found\n");
        return 0;
    }
    int choice;
    printf("Select the contact\n");
    scanf("%d",&choice);
    printf("%d. %-15s %-15s %-15s\n",choice,addressBook->contacts[search_array[choice-1]].name,addressBook->contacts[search_array[choice-1]].phone,addressBook->contacts[search_array[choice-1]].email);
    return search_array[choice-1];

}
int search_byphone(AddressBook *addressBook)
{
    char str[50];
    printf("Enter the Phone number\n");
    scanf("%s",str);
    int j=0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcasestr(addressBook->contacts[i].phone,str))
        {
            search_array[j]=i;
            printf("%d. %-15s %-15s %-15s\n",++j,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    if(j==0)
    {
        printf("Contact not found\n");
        return 0;
    }

    int choice;
    printf("Select the contact\n");
    scanf("%d",&choice);
    printf("%d. %-15s %-15s %-15s\n",choice,addressBook->contacts[search_array[choice-1]].name,addressBook->contacts[search_array[choice-1]].phone,addressBook->contacts[search_array[choice-1]].email);
    return search_array[choice-1];

}
int search_byemail(AddressBook *addressBook)
{
    char str[50];
    printf("Enter the email\n");
    scanf("%s",str);
    int j=0;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcasestr(addressBook->contacts[i].email,str))
        {
            search_array[j]=i;
            printf("%d. %-15s %-15s %-15s\n",++j,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    if(j==0)
    {
        printf("Contact not found\n");
        return 0;
    }
    int choice;
    printf("Select the contact\n");
    scanf("%d",&choice);
    printf("%d. %-15s %-15s %-15s\n",choice,addressBook->contacts[search_array[choice-1]].name,addressBook->contacts[search_array[choice-1]].phone,addressBook->contacts[search_array[choice-1]].email);
    return search_array[choice-1];

}