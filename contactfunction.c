#include "contactheader.h"

int menu() {

	int option;

	do {

		puts("\t*Contact Info Menu*\t\n");
		puts("1. Insert new information by last name");
		puts("2. Delete contact information by last name");
		puts("3. Edit contact information based on last name");
		puts("4. Load contact information from a file\n   in alphabetical order by last name");
		puts("5. Store all contacts into a file");
		puts("6. Print list of Contacts");
		puts("7. Exit Menu");
		
		scanf("%d", &option);

		system("clear");

	} while(option < 1 || option > 7);

	return option;
}
Boolean isEmpty (Node *pList) {

	if (pList == NULL) {

		return TRUE;
	}
	else {

		return FALSE;
	}
}
Contact newContact() {

	Contact info = {" "," "," "," "};

	printf("Contact last name: ");
	scanf("%s", &info.last_name);

	printf("Contact phone: ");
	scanf("%s", &info.phone);

	printf("Contact email: ");
	scanf("%s", &info.email);

	printf("Contact title: ");
	scanf("%s", &info.title);

	system("pause");
	system("clear");

	return info;
}
Boolean insertContactInOrder(Node **pList, Contact newData) {

	// allocating mem for new data node
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	Node *current = *pList, *temp, *prev;
	newNode->pNext = NULL;
	newNode->data = newData;


	// adding to an empty list
	if(isEmpty(current)) {

		*pList = newNode;
		return FALSE;
	}
	// adding node to the head of the list
	if (newNode->data.last_name <= current->data.last_name) {

		newNode->pNext = current;
		*pList = newNode;
	}
	else {

		temp = (*pList)->pNext;
		prev = *pList;

		while (temp != NULL && temp->data.last_name < newData.last_name) {

			prev = temp;
			temp = temp->pNext;
		}
		newNode->pNext = temp;
		prev->pNext = newNode;
	}
	return TRUE;

}
Boolean deleteContact(Node **pList, Contact searchContact) {

	Node *current = *pList, *prev;

	if (isEmpty(current)) {

		puts("NOTHING TO DELETE");
		return FALSE;
	}
	if (strcmp(current->data.last_name, searchContact.last_name) == 0) {

		*pList = current->pNext;
		free(current);
		return TRUE;
	}
	while (current != NULL && strcmp(current->data.last_name, searchContact.last_name) != 0) {

		prev = current;
		current = current->pNext;
	}
	if (current == NULL) {

		puts("NAME WAS NO FOUND");
		return FALSE;
	}
	else {

		prev->pNext = current->pNext;
		free(current);
	}
	return TRUE;
}
Boolean editContact(Node *pList, Contact searchContact) {


}
Boolean loadContacts(FILE *infile, Node **pList) {



}
Boolean storeContacts(FILE *infile, Node *pList) {



}
void printList(Node **pList) {

	Node *current = *pList;

	if(isEmpty(current)) {

		puts("LIST IS EMPTY NOTHING TO PRINT");
	}
	else {
		
		while(current->pNext != NULL) {

			printf("Name: %s\nPhone: %s\nEmail: %s\nTitle: %s\n\n",
				current->data.last_name, current->data.phone, current->data.email, current->data.title);

			current = current->pNext;
		}
	}
}