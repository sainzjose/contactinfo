#include "contactheader.h"

int main() {

	Node *head = NULL;
	FILE *infile = fopen("contactinfo.txt", "r");;
	int option;
	Contact info;


	if (infile == NULL) {

		puts("FILE NOT SUCCESFULLY OPENED");
	}

	option = menu();

	switch(option) {

		case 1: // insert new contact
		
			info = newContact();
			insertContactInOrder(&head, info); 
			printList(&head);
			break;
		case 2: // delete contact
			printf("Enter the last name of the contact you wish to delete: ");
			scanf("%s", &info.last_name);
			deleteContact(&head, info);
			break;
		case 3: // edit contact information
			break;
		case 4: //
			break;
		case 5: 
			break;
		case 6:
			break;
		case 7: 
			break;
	}



	fclose(infile);


	return 0;
}
