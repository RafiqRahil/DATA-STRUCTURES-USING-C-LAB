#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *createNode(){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &node->data);
    node->next = NULL;
    return node;
}

void createList(){
    int n, i;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);
    struct Node *temp=NULL;
    for(i=0;i<n;i++){
        struct Node *newNode = createNode();
        if(head==NULL)
            head = newNode;
        else {
            temp->next = newNode;  
        }
        temp = newNode;
    }
}

void displayList(){
    if(head==NULL)
    printf("List is empty!!!\n");
    else{
        struct Node *temp=head;
        while(temp!=NULL){
           printf("%d ", temp->data);
           temp=temp->next;
        }
    }
}

void insertNodeInBeg(){
    struct Node *newNode=createNode();
   newNode->next = head;
   head = newNode;
}

void insertNodeInEnd(){
    struct Node *newNode=createNode();
    if(head==NULL)
     head = newNode;
     else{
        struct Node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
     }
}

void insertNodeAtAnyLoc() {
    if (head == NULL)
        printf("Invalid position!!!\n");
    else {
        int pos, count = 1;
        struct Node *temp = head;
        printf("Enter Position: ");
        scanf("%d", &pos);
        if (pos == 1) { // Insert at beginning
            struct Node *newNode = createNode();
            newNode->next = head;
            head = newNode;
        } else {
            while (temp != NULL && count < pos - 1) {
                temp = temp->next;
                count++;
            }
            if (temp == NULL)
                printf("Invalid Position!!!\n");
            else {
                struct Node *newNode = createNode();
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
}

void deleteNodeAtAnyLoc(){
    int pos, count = 1;
        struct Node *temp = head;
        printf("Enter Position: ");
        scanf("%d", &pos);
        if (pos == 1) { // Delete at beginning
            head = head->next;
        } else {
            while (temp != NULL) {
               if(count == pos-1){
                 break;
               }
               count++;
               temp = temp->next;
            }
            if (temp == NULL)
                printf("Invalid Position!!!\n");
            else {
                temp->next = temp->next->next;
            }
        }
    
}

void search(){
    if(head==NULL) printf("List Empty!!!\n");
    else{
        int num, flag=0;
        printf("Enter data to search: ");
        scanf("%d", &num);
        struct Node *temp = head;
        while(temp!=NULL){
            if(temp->data == num){
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if(flag==1) printf("Found!!!\n");
        else printf("Not Found!!!\n");
    }
}

int main()
{
    createList();
    int choice;
    while(1){
        
        printf("1. Inset Node in Beginning\n");
        printf("2. Insert Node in End\n");
        printf("3. Insert Node at any position\n");
        printf("4. Delete Node From Given Position\n");
        printf("5. Search Node in list\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        
    switch(choice){
        case 1:
        insertNodeInBeg();
        break;
        case 2:
        insertNodeInEnd();
        break;
        case 3:
        insertNodeAtAnyLoc();
        break;
        case 4:
        deleteNodeAtAnyLoc();
        break;
        case 5:
        search();
        break;
        case 6:
        displayList();
        break;
        case 7:
        exit(0);
        break;
    }
    }
    return 0;
}