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

void printReverseList(Node* head){
	if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main(){
	Node* head = NULL;
	int n, value;
	printf("nhap so phan tu trong danh sach: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &value);
		insertEnd(&head, value);
	}
	printf("danh sach dao nguoc: ");
	printReverseList(head);
	return 0;
}

