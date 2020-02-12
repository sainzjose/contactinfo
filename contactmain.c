#include "contactheader.h"

int main() {

	Node* head = NULL;
	FILE* contactList;
	int option;
	Contact info, searchContact;
	char* token;

	do {

		option = menu();

		switch(option) {

			case 1: // insert new contact
				info = newContact();
				insertContactInOrder(&head, info); 
				//printList(&head);
				break;
			case 2: // delete contact
				printf("Enter the last name of the contact you wish to delete: ");
				getchar();
				fgets(info.last_name, 50, stdin); // will end it with a new line
				deleteContact(&head, info);
				puts("Contact was deleted!");
				getchar();
				system("clear");
				break;
			case 3: // edit contact information
				printf("Enter contact's last name: ");
				getchar();
				fgets(searchContact.last_name, 50, stdin);
				editContact(head, searchContact);
					break;
			case 4: // load info from a file
				contactList = fopen("contactinfo.txt", "r");
				if (contactList == NULL) {
					puts("FILE NOT SUCCESFULLY OPENED");
					return 1;
				}
				loadContacts(contactList, &head);
				fclose(contactList);
				break;
			case 5: // store into a file
				contactList = fopen("contactinfo.txt", "w");
				if (contactList == NULL) {
					puts("FILE NOT SUCCESFULLY OPENED");
					return 1;
				}
				storeContacts(contactList, head);
				fclose(contactList);
				break;
			case 6: // print the list
				printList(head);
				break;
			case 7: 
				system("clear");
				printf("***PROGRAM HAS BEEN EXITED***\n");
				break;
		}
	}while(option != 7);

	return 0;
}
