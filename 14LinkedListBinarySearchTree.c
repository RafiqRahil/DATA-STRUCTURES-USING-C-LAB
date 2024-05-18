#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};
struct Node* createNode(int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
struct Node* insert(struct Node *root, int value){ 
    if(root==NULL){
        root=createNode(value);
    }
    else if(value<root->data){
        root->left=insert(root->left,value);
    }
    else{
        //greater hoga
        root->right=insert(root->right,value);
    }
    return root;
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
int search(struct Node *root, int value){
    static int flag=0;
    if(root!=NULL){
        if(root->data==value){
            flag=1;
        }
        else{
            search(root->left,value);
            search(root->right,value);
        }
    }
    return flag;
}
struct Node *deleteElement(struct Node *root, int key){
    if(root==NULL){
        return root;
    }
    else if(key<root->data){
        root->left=deleteElement(root->left,key);
        return root;
    }
    else if(key>root->data){
        root->right=deleteElement(root->right,key);
        return root;
    }
    else{
        //here we write the logic to delete the node

        
        
        //deleting node having 0 or 1 children
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        else{
            //deleting node having 2 children
            struct Node *temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deleteElement(root->right,temp->data);
            return root;
        }

    }
}
int main(){
    struct Node *root=NULL;
    while(1){
        system("cls");
        printf("********** Binary Search Tree **********\n");
        printf("1.Insert Node in Binary Search Tree\n");
        printf("2.Pre-Order Traversal\n");
        printf("3.In-Order Traversal\n");
        printf("4.Post-Order Traversal\n");
        printf("5.Search Element\n");
        printf("6.Delete Element");
        printf("7.Exit\n");

        int choice;
        printf("enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            int value;
            printf("enter the value: ");
            scanf("%d",&value);
            root = insert(root,value);
            break;
            case 2:
            preorder(root);
            break;
            case 3:
            inorder(root);
            break;
            case 4:
            postorder(root);
            break;
            case 5:
            
            printf("enter searching element: ");
            scanf("%d",&value);
            if(search(root,value)==1){
                printf("found!!!\n");
            }
            else{
                printf("not found!!!\n");
            }
            break;
            case 6:
            int key;
            printf("enter key: ");
            scanf("%d",&key);

            root=deleteElement(root,key);
            break;
            case 7:
            
            break;
        }

        system("pause");

    }
}