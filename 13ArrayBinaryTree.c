#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};
int arr[100];
int top=-1;
int target;
void push(int a){
    top++;
    arr[top]=a;
}
struct Node* createNode(){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter tree element: ");
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    return temp;
}

void insertInLeft(struct Node *parent){
    parent->left=createNode();
}
void insertInRight(struct Node *parent){
    parent->right=createNode();
}

struct Node* preorder(struct Node *root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
struct Node* inorder(struct Node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);

        inorder(root->right);
        

    }

}
struct Node* postorder(struct Node*root){
    if(root!=NULL){
        postorder(root->left);

        postorder(root->right);
        printf("%d ",root->data);
    }
    
}
void search(struct Node*root){
    
    if(root!=NULL){
        
        inorder(root->left);
        printf("%d ",root->data);
        push(root->data);
        inorder(root->right);
        

    }
    for(int i=top; i>=0; i--){
        if(arr[i]==target){
            printf("element found!");
            break;
        }
        else{
            continue;
        }
        
    }
}

int main(){
    struct Node *root = createNode(); //19
    insertInRight(root);               //72
    insertInLeft(root->right);      //12
    insertInLeft(root);             //52
    insertInLeft(root->right->left);//32
    insertInRight(root->right->left->left);     //5
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    printf("\nenter the target element: ");
    scanf("%d",&target);

    return 0;
}