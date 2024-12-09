#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
}

void insertEnd(Node** head, int data){
	Node* newNode = createNode(data);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void changeElement(Node** head, int data, int newData, int* found){
	Node* temp = *head;
	while(temp->next != NULL){
		if(temp->data == data){
			temp->data = newData;
			(*found)++;
		}
		temp = temp->next;
	}
}

void printList(Node* head){
	if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
	Node* temp = head;
	while(temp != NULL){
		printf("%d <-> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){
	Node* head = NULL;
	int n, value, newValue;
	int found = 0;
	printf("nhap so phan tu trong danh sach: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &value);
		insertEnd(&head, value);
	}
	printf("danh sach: ");
	printList(head);
	printf("nhap gia tri can thay the trong danh sach: ");
	scanf("%d", &value);
	printf("nhap gia tri moi: ");
	scanf("%d", &newValue);
	changeElement(&head, value, newValue, &found);
	if(!found){
		printf("khong tim thay phan tu thay the");
	} else {
		printf("danh sach sau khi cap nhat: ");
		printList(head);
	}
	return 0;
}

