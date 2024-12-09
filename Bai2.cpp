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

void insertInPosition(Node** head, int data, int position){
	Node* newNode = createNode(data);
	if(*head == NULL || position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	Node* temp = *head;
	int currentPos = 0;
	while(temp != NULL && currentPos < position - 1){
		temp = temp->next;
		currentPos++;
	}
	if (temp == NULL) {
        printf("vi tri nay khong co trong danh sach\n");
        return;
    }
	newNode->next = temp->next;
    temp->next = newNode;
    temp->prev = newNode;
}

void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d <-> ", temp->data);
		temp = temp->next;
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
	printf("moi ban nhap vao phan tu muon them: ");
	scanf("%d", &value);
	printf("nhap vi tri chen: ");
	int position;
	scanf("%d", &position);
	insertInPosition(&head, value, position);
	printList(head);
	return 0;
}

