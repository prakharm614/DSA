#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertFirst(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}
struct Node* insertLast(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* newHead = head->next;
    if (newHead != NULL) newHead->prev = NULL;
    free(head);
    return newHead;
}
struct Node* deleteLast(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) return NULL;
    if (position == 1) {
        struct Node* newHead = head->next;
        if (newHead != NULL) newHead->prev = NULL;
        free(head);
        return newHead;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL || temp->next == NULL) return head;
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) nodeToDelete->next->prev = temp;
    free(nodeToDelete);
    return head;
}
void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = NULL;
    printf("\ninserting at first:\n");
    head = insertFirst(head, 10);
    head = insertFirst(head, 20);
    head = insertFirst(head, 30);
    displayList(head);
    head = insertLast(head, 40);
    head = insertLast(head, 50);
    printf("\ninserting at last:\n");
    displayList(head);
    head = deleteFirst(head);
    printf("\ndeleting at first:\n");
    displayList(head);
    head = deleteLast(head);
     printf("\ndeleting at last:\n");
    displayList(head);
    head = deleteAtPosition(head, 2);
     printf("\ndeleting at position 2t:\n");
    displayList(head);
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
