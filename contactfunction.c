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

	getchar(); // gets the \n the user enters so the next fgets can work

	printf("Contact last name: ");
	fgets(info.last_name, 50, stdin);

	printf("Contact phone: ");
	fgets(info.phone, 12, stdin);
	//scanf("%s", &info.phone);

	printf("Contact email: ");
	fgets(info.email, 50, stdin);
	//scanf("%s", &info.email);

	printf("Contact title: ");
	fgets(info.title, 20, stdin);
	//scanf("%s", &info.title);

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
	while (!isEmpty(current) && strcmp(current->data.last_name, searchContact.last_name) != 0) {
		prev = current;
		current = current->pNext;
	}
	if (isEmpty(current)) {

		puts("NAME WAS NOT FOUND");
		return FALSE;
	}
	else {

		prev->pNext = current->pNext;
		free(current);
	}
	return TRUE;
}
Boolean editContact(Node *pList, Contact searchContact) {

	int option;

	if(isEmpty(pList)) {

		return FALSE;
	}
	while(!isEmpty(pList)) {

		if(strcmp(searchContact.last_name, pList->data.last_name) == 0) {
			
			do {

				printf("1) Contact last name: %s",pList->data.last_name);
				printf("2) Contact phone: %s",pList->data.phone);
				printf("3) Contact email: %s",pList->data.email);
				printf("4) Contact title: %s",pList->data.title);
				printf("5) Done editing\nEnter option: ");
				scanf("%d", &option);
				
				switch(option) {

					case 1: printf("Enter new contact name: ");
						getchar();
						fgets(pList->data.last_name, 50, stdin);
						break;
					case 2: printf("Enter new contact phone: ");
						getchar();
						fgets(pList->data.phone, 12, stdin);
						break;
					case 3: printf("Enter new contact email: ");
						getchar();
						fgets(pList->data.email, 50, stdin);
						break;
					case 4: printf("Enter new contact title: ");
						getchar();
						fgets(pList->data.title, 50, stdin);
						break;
				}
				system("clear");

			} while(option != 5);

			return TRUE;
		}
		pList = pList->pNext;
	}
	puts("Contact not found");
	return FALSE;
}
Boolean loadContacts(FILE *infile, Node **pList) {

	Contact tempContact;
	char newLine[2];

	if(infile == NULL) {

		return FALSE;
	}
	while(!feof(infile)) {

		fgets(tempContact.last_name, 50, infile);
		fgets(tempContact.phone, 12, infile);
		fgets(tempContact.email, 50, infile);
		fgets(tempContact.title, 20, infile);
		fgets(newLine, 2, infile);
		insertContactInOrder(pList, tempContact);
	}
	puts("Contacts have been loaded");
	getchar();
	getchar();
	system("clear");
	return TRUE;
}
Boolean storeContacts(FILE *outfile, Node *pList) {

	if(outfile == NULL) {

		return FALSE;
	}
	while(!isEmpty(pList)) {

		fprintf(outfile, "%s%s%s%s\n", pList->data.last_name, pList->data.phone, pList->data.email, pList->data.title);
		pList = pList->pNext;
	}
	puts("Contacts have been stored!");
	getchar();
	getchar();
	system("clear");
	return TRUE;
}

void printList(Node* pList) {

	if(isEmpty(pList)) {
		puts("LIST IS EMPTY NOTHING TO PRINT");
		return;
	}
	while(!isEmpty(pList)) {

		printf("Name: %sPhone: %sEmail: %sTitle: %s\n", pList->data.last_name, pList->data.phone, pList->data.email, pList->data.title);
		pList = pList->pNext;
	}
	getchar();
	getchar();
	system("clear");

}
