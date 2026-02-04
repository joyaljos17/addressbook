#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int validate_name(char *str);
int validate_phone(char *str,AddressBook *addressBook);
int validate_email(char *str,AddressBook *addressBook);
int search_byname(AddressBook *addressBook);
int search_byphone(AddressBook *addressBook);
int search_byemail(AddressBook *addressBook);
#endif
