#include <stdio.h>
#include <stdlib.h>
#define maxsize 1000
int list[maxsize], size;
void CreateList(int list[]) {
    int i;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    if (size > maxsize) printf("\nList Overflow !!!");
    else {
        printf("Enter the list Elements: ");
        for (i = 0; i < size; i++) {
            scanf("%d", &list[i]);
        }
    }
}
void InsertElement(int list[]) {
    if (size == 0) printf("\nList is Empty !!!!\n");
    else {
        int pos, value, i;
        printf("Enter the position of the element to be inserted: ");
        scanf("%d", &pos);
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        if (pos >= 1 && pos <= size + 1) {
            for (i = size - 1; i >= pos - 1; i--) {
                list[i + 1] = list[i];
            }
            list[pos - 1] = value;
            size++;
            printf("Element Added !!!");
        }
        else printf("Invalid position !!!");
    }
}
void DisplayList(int list[]) {
    if (size == 0) printf("\nList is Empty !!!!\n");
    else {
        printf("\nList Elements are : ");
        int i;
        for (i = 0; i < size; i++) {
            printf("%d ", list[i]);
        }
    }
    printf("\n");
}
void DeleteElement(int list[]) {
    if (size == 0) printf("\nList is Empty !!!!\n");
    else {
        int pos;
        printf("Enter the position of the element to delete: ");
        scanf("%d", &pos);
        if (pos >= 1 && pos <= size) {
            for (int i = pos - 1; i < size - 1; i++)
                list[i] = list[i + 1];
            size--;
            printf("Element Deleted !!!");
        }
        else printf("Invalid position!!!");
    }
}
void SearchElement(int list[]) {
    if (size == 0) printf("\nList is Empty !!!!\n");
    else {
        int element;
        printf("Enter the element to be searched: ");
        scanf("%d", &element);
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (list[i] == element) {
                printf("Element %d found at position %d", element, i + 1);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Element %d not found", element);
        }
    }
    printf("\n");
}
int main() {
    CreateList(list);
    InsertElement(list);
    DisplayList(list);
    DeleteElement(list);
    DisplayList(list);
    SearchElement(list);
    return 0;
}