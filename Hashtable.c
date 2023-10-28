#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

typedef struct Node {
    int key;
    int data;
    struct Node* next;
} Node;

Node* hashArray[SIZE];

// Hash function
int hashCode(int key) {
    return key % SIZE;
}

// Function to insert into hash table
void insert(int key, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->data = data;
    newNode->next = NULL;

    int index = hashCode(key);

    if (hashArray[index] == NULL) {
        hashArray[index] = newNode;
    } else {
        Node* current = hashArray[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search in hash table
Node* search(int key) {
    int index = hashCode(key);
    Node* current = hashArray[index];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
