#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left, *right;
} NODE;

NODE *nodeFactory(int newValue);
void insertLeft(NODE *node, int newValue);
void insertRight(NODE *node, int newValue);
void printTree(NODE *row);
int numberOfElements(NODE *row);
int findValue(NODE *row, int value);
void searchElement(NODE *row);

int main () {
    int newValue;
    NODE *row = NULL;
    while(scanf("%i",&newValue) == 1){
        if (row == NULL) row = nodeFactory(newValue);
        else if (row->value > newValue) insertLeft(row, newValue);
        else if (row->value < newValue) insertRight(row, newValue);
    }
    printf("\nnumber of elements: %i\n", numberOfElements(row));
    printTree(row);
    searchElement(row);
}

void insertLeft (NODE *row, int newValue) {
    if (row->left == NULL) row->left = nodeFactory(newValue);
    else if (row->left->value > newValue) insertLeft(row->left, newValue);
    else if (row->left->value < newValue) insertRight(row->left, newValue);
}

void insertRight (NODE *row, int newValue) {
    if (row->right == NULL) row->right = nodeFactory(newValue);
    else if (row->right->value > newValue) insertLeft(row->right, newValue);
    else if (row->right->value < newValue) insertRight(row->right, newValue);
}

NODE *nodeFactory(int newValue) {
    NODE *newNode = malloc(sizeof(NODE));
    newNode->value = newValue;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int findValue(NODE *row, int value) {
    if (row == NULL) return -1;
    else if (row->value == value) return row->value;
    else if (value > row->value) return findValue(row->right, value);
    else if (value < row->value) return findValue(row->left, value);
}

void printTree(NODE *row) {
    if (row != NULL) {
        printTree(row->left);
        printf("%i ", row->value);
        printTree(row->right);
    }
}

void searchElement(NODE *row) {
    int value = 30;

    printf("\nFind a value");
    scanf("%i", &value);

    int fouded = findValue(row, value);
    if (fouded >= 0) printf("\nElement << %i >> founded", fouded);
    else printf("\nElement << %i >> not found", value);
}


int numberOfElements(NODE *row) {
    if (row == NULL) return 0;
    return 1 + numberOfElements(row->left) + numberOfElements(row->right);
}