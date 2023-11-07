#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

struct Node* createLinkedList(int data) {
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;

    return n;
}

void addNodeHeadOfLinkedList(struct Node** root, int data) {
    node* temp = createLinkedList(data);
    temp->next = *root;
    *root = temp;
}

void addNodeEndOfLinkedList(struct Node** root, int data) {
    node* temp = *root;
    while(temp->next !=NULL) {
        temp = temp->next;
    }
    temp->next = createLinkedList(data);
}

void deleteNodeFromLinkedList(struct Node** root, int data) {
    node* iter = *root;
    node* temp;
    if(*root == NULL) {
        printf("Linked List is empty.");
    }else if( (*root)->data == data ) {
        temp = (*root)->next;
        free(*root);
        (*root) = temp;
    }else {
        while(iter->data != data && iter->next !=NULL) {
            temp = iter;
            iter = iter->next;
        }
        if(iter==NULL) {
            printf("Data not found.");
        }else {
            temp->next = iter->next;
            free(iter);
        }
    }
}

void writeLinkedList(struct Node* root) {
    node* temp = root;
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main() {

    node* root = createLinkedList(5);
    addNodeEndOfLinkedList(&root,6);
    addNodeEndOfLinkedList(&root,7);
    addNodeEndOfLinkedList(&root,8);
    writeLinkedList(root);
    printf("\n");
    deleteNodeFromLinkedList(&root,5);
    writeLinkedList(root);


    return 0;
}
