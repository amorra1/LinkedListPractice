#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node {
    int value;
    struct list_node *next;
};

void print_list(struct list_node *head);
// TODO: implement this function for printing all nodes(task 1).
    struct list_node *ptr = NULL; //ptr is a pointer to a node
    ptr = head; //ptr points to the head node
    while(ptr != NULL){
        printf("%d ", ptr -> value); //print the value of the node
        ptr = ptr->next; //ptr points to the next node
    };
    printf("\n");
}

struct list_node* insertFirst(struct list_node *head, int data) {
// TODO: implement this function for inserting the first node in an empty linked list(task 1)
    struct list_node* newNode = (struct list_node*) malloc(sizeof(struct list_node));

    if(newNode != NULL) {
        newNode->value = data;
        newNode->next = NULL;

        head = newNode;
    }

    return head;
}

void insert_at_tail(struct list_node **head, int value) {
// TODO: implement this function for inserting a node at the tail of the linked list  (task 1).
    struct list_node *ptr, *temp; //creating new pointers
    ptr = *head; //initializing the ptr to head
    temp = (struct list_node*) malloc(sizeof(struct list_node)); //creating memory for new node

    temp-> value = value; //updating the value input into the function into the new node
    temp-> next = NULL; //assigning the link of the new node to be NULL

    while (ptr -> next != NULL){
        ptr = ptr-> next; //checking which node has a NULL link
    }
    ptr -> next = temp; //updating the NULL link to have the memory address of the new node
}


struct list_node * swap_adjacent(struct list_node *head) {
    // TODO: implement this (task 2).
    if(head == NULL || head->next == NULL) //checking if list is empty or if there is only one node
        return head;

    struct list_node* currNode = head;
    struct list_node* newHead = head->next; //assigning newHead to be the second node of the list

    while(currNode != NULL && currNode-> next != NULL){
        struct list_node* temp = currNode->next; //stores next node temporarily
        currNode->next = currNode->next->next; //currNode skips next node and points to node after it
        temp->next = currNode; //swap positions of currNode and temp
        currNode = currNode->next; //move currNode to next position
        if(currNode !=NULL && currNode->next != NULL)
            temp->next->next = currNode->next;
    }
    return newHead;
}

void double_list(struct list_node *head) {
    // TODO: implement this (task 3).

    if (head == NULL) //check if list is empty
        return;

    struct list_node *current = head;

    // Traverse to the end of the original list
    while (current->next != NULL) {
        current = current->next;
    }

    // Copy the original list and append it to the end
    struct list_node *newHead = NULL;
    struct list_node *newCurrent = NULL;

    while (head != NULL) {
        // Create a new node with the same data
        struct list_node *newNode = (struct list_node *)malloc(sizeof(struct list_node));
        if (newNode != NULL) { //checks if memory allocation worked
            newNode->value = head->value;
            newNode->next = NULL;

            // Append the new node to the new list
            if (newHead == NULL) {
                newHead = newNode;
                newCurrent = newNode;
            } else {
                newCurrent->next = newNode;
                newCurrent = newNode;
            }
        }

        head = head->next;
    }

    // Append the new list to the end of the original list
    current->next = newHead;
}

void remove_adjacent_duplicates(struct list_node *head) {
    // TODO: implement this (task 4).
    if(head == NULL) //checking if list is empty
        return;

    struct list_node* current = head; //current pointer that starts at head

    while(current -> next != NULL){ //while loop to traverse the list
        if(current->value == current->next->value){ //checking if current value is equal to the next value
            struct list_node* duplicate = current-> next; //if it is store the current data into new duplicate pointer
            current->next = duplicate->next; //sets current next to the following node
            free(duplicate); //frees up duplicate and deletes it
        }else{
            current = current->next; //if not equal, move to next node
        }

    }

}


int main() {
    // List is initially empty.
    struct list_node *head = NULL;

    // insert head
    head = insertFirst(head, 1);
    insert_at_tail(&head, 2);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 3);
    insert_at_tail(&head, 4);
    insert_at_tail(&head, 5);
    insert_at_tail(&head, 6);


    printf("Original list: ");
    print_list(head);

    printf("\nSwapping adjacent items: ");
    head = swap_adjacent(head);
    print_list(head);

    printf("\nDuplicating all items: ");
    double_list(head);
    print_list(head);

    printf("\nRemoving adjacent duplicates: ");
    remove_adjacent_duplicates(head);
    print_list(head);

    //free(head);

    return 0;
}