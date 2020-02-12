#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Store contact info: (struct)
Name, Phone, Email, Professional Title
Must support:
	insertions in order (last name)
	deletions
	modifications
	printing of contracts
Use dynamic singly linked list / grows and shrinks at runtime
Build a menu that allows user to:
	add contact info
	remove contact info
	edit contact info
	print contact info
	store contact info (writes the info into a file)
	load contact info (read info from the same file into a list)
Contact struct, A node must also be a struct w contract struct inside of it

*/

typedef enum boolean {

	FALSE, TRUE
} Boolean;

typedef struct contact {

	char last_name[50];
	char phone[12]; // 18005557577
	char email[50];
	char title[20];
 } Contact;

typedef struct node
{
	Contact data;
	struct node *pNext;
} Node;

// Description: Presents a menu for the user in order to chose what action 
// the program should execute
// Returns: Number between 1-7 from the menu
int menu();
// Description: Checks if a list is empty or not
// Returns: TRUE if the list is empty; FALSE otherwise
Boolean isEmpty (Node *pList);

Contact newContact();
// Description: Allocates space for a new Node and inserts the new
// Node into the list in alphabetic order ('a' - 'z')
// based on the name field
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise
Boolean insertContactInOrder(Node **pList, Contact newData);
// Description: Deletes a Contact in the list based on the name field;
// deletes the first occurrence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean deleteContact(Node **pList, Contact searchContact);
// Description: Edits a Contact in the list based on the name field; edits
// the first occurrence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean editContact(Node *pList, Contact searchContact);
// Description: Loads all Contact information from the given file, in
// alphabetic order, based on the name, into the list
// Returns: TRUE if all Contacts were loaded; FALSE otherwise
Boolean loadContacts(FILE *infile, Node **pList);
// Description: Stores all Contact information from the list into the
// given file
// Returns: TRUE if all Contacts were stored; FALSE otherwise
Boolean storeContacts(FILE *outfile, Node *pList);
// Description: Prints all contact information in the list
// Returns: Nothing
void printList(Node* pList);
