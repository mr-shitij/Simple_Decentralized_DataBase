#include<stdio.h>
#include<stdlib.h>
#include"SLL.h"

SLL* Init_List() {
	SLL *singly = (SLL *)malloc(sizeof(SLL));
	singly->head = NULL;
	return singly;
}

size_t getDataTypeSize(const char type) {
	switch(type) {
		case 'i':
			return sizeof(int); 
		case 'f':
			return sizeof(float); 
		case 'd':
			return sizeof(double); 
		case 's':
		case 'c':
			return sizeof(char);
		default:
			printf("\n Invalid Type");
			exit(1);
	}
} 

void assignDataToMemory(const char type, size_t data_size, void *newNode, void *new_data) {
	int i;
	switch(type) {
		case 'i':
			for (i=0; i<data_size; i++) {
				*(int *)(newNode + i) = *(int *)(new_data + i);
			}
			break;
		case 'f':
			for (i=0; i<data_size; i++) {
				*(float *)(newNode + i) = *(float *)(new_data + i);
			}
			break;
		case 'd':
			for (i=0; i<data_size; i++) {
				*(double *)(newNode + i) = *(double *)(new_data + i);
			}
			break;
		case 'c':
			for (i=0; i<data_size; i++) {
				*(char *)(newNode + i) = *(char *)(new_data + i);
			}
			break;
		case 's':
			i=0;
			while(*(char *)(new_data + i) != NULL) {
				*(char *)(newNode + i) = *(char *)(new_data + i);
				i++;
			}
			break;
		default:
			printf("\n Invalid Type");
			exit(1);
	}

}

void InsertAtFirst(SLL *list, const char type, void *data, unsigned int n) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	if(newNode == NULL) {
		printf("\n Overflow ..!!");
		return;
	}
	size_t dataSize = getDataTypeSize(type);
	newNode->type = type;
	newNode->data = malloc(dataSize * n);
	newNode->next = NULL;

	printf("\n N : %d \n", n);

	assignDataToMemory(type, dataSize, newNode->data, data);
	
	if(list->head == NULL) {
		list->head = newNode;
	}
	else {
		Node *temp = list->head;
		list->head = newNode;
		newNode->next = temp;
	}
}

void InsertAtLast(SLL *list, const char type, void *data, unsigned int n) { // add to last
	Node *newNode = (Node *) malloc(sizeof(Node));
	if(newNode == NULL) {
		printf("\n Overflow ..!!");
		return;
	}
	size_t dataSize = getDataTypeSize(type);
	newNode->type = type;
	newNode->data = malloc(dataSize * n);
	newNode->next = NULL;

	assignDataToMemory(type, dataSize, newNode->data, data);

	
	if(list->head == NULL) {
		list->head = newNode;
	}
	else {	
		Node *temp = list->head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void RemoveFromLast(SLL *list) {
	if(list->head == NULL) {
		printf("List is empty ..!!");
		return;
	}
	else if(list->head->next == NULL) {
		free(list->head);
		list->head = NULL;
	}
	else {
		Node *temp = list->head, *prev;
		while(temp->next != NULL) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		temp->data = 0;
		free(temp);
		temp = NULL;
	
	}
}

void RemoveFromFirst(SLL *list) {
	if(list->head == NULL) {
		printf("List is empty ..!!");
		return;
	}
	else {
		Node *temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
}

void printInt(void *n) {
	printf(" %d", *(int *)n);
}

void printChar(void *n) {
	printf(" %c", *(char *)n);
}
 
void printString(void *n) {
	char *ptr = (char*)n;	
	while(*ptr != NULL) {
		printf("%c", *ptr);
		ptr++;
	}
}
 
void printFloat(void *f) {
	printf(" %f", *(float *)f);
}

void printDouble(void *n) {
	printf(" %lf", *(double *)n);
}


void printBasedOnData(const char type, void *data) {
	if(type == 'i') {
		printInt(data);
	}
	else if(type == 'c') {
		printChar(data);
	}
	else if(type == 'f') {
		printFloat(data);
	}
	else if(type == 'd') {
		printDouble(data);
	}
	else if(type == 's') {
		printString(data);
	}

}

void PrintColums(SLL *list) {
	Node *temp = list->head;
	while(temp != NULL) {
		printBasedOnData('s', temp->data);
		printf("\t");
		temp = temp->next;
	}	
}

void Traverse(SLL *list) {
	Node *temp = list->head;
	while(temp != NULL) {
		printBasedOnData(temp->type, temp->data);
		temp = temp->next;
	}	
}

void getNode(SLL *list, unsigned int index) {
	Node *temp = list->head;
	while(index != 0) {
		temp = temp->next;
		index --;
	}

	printf("\nDATA : ");
	printBasedOnData(temp->type, temp->data);
	printf("\n");

}

void Search(SLL *list, int data) {
	Node *temp = list->head;
	
	while(temp != NULL) {
		if(temp->data == data) {
			printf("Found ..!!");
			return;
		}
		temp = temp->next;
	}	
}
