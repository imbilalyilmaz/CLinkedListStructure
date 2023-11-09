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
    if(*root == NULL) {
        *root = createLinkedList(data);
    } else {
        while(temp->next !=NULL) {
            temp = temp->next;
        }
        temp->next = createLinkedList(data);
    }

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
    if(temp == NULL) {
        printf("Böyle bir liste yok.");
        return;
    }
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void writeLinkedListRecursive(struct Node* root){
    if(root!=NULL) {
        printf("%d ",root->data);
        writeLinkedListRecursive(root->next);
    }
    else{
        printf("\n");
    }
}

void writeLinkedListReverse(struct Node* root) {

    if(root!=NULL) {
        writeLinkedListReverse(root->next);
        printf("%d ",root->data);
    }

}

void destroyLinkedList(struct Node** root) {
    node* temp;
    while(*root!=NULL) {
        temp = *root;
        (*root) = (*root)->next;
        free(temp);
    }
}

void sortLinkedList(struct Node** root) {
    if(*root==NULL || (*root)->next ==NULL) return;

    struct Node *a,*b,*c,*d;
    d = (*root)->next;
    (*root)->next = NULL;
    while (d!=NULL) {
        c = d;
        d = d->next;
        b = *root;
        while(b!=NULL && b->data < c->data ) {
            a = b;
            b = b->next;
        }
        if(b == *root) {
            c->next = *root;
            *root = c;
        }else {
            a->next =c;
            c->next =b;
        }
    }
}

void reverseList(struct Node** root) {
    node *a,*b;
    a = NULL;
    while (*root != NULL) {
        b = *root;
        *root = (*root) ->next;
        b->next = a;
        a=b;
    }
    *root = a;
}


int main() {

    node* root = createLinkedList(4);
    addNodeEndOfLinkedList(&root,2);
    addNodeEndOfLinkedList(&root,6);
    addNodeEndOfLinkedList(&root,1);
    addNodeEndOfLinkedList(&root,3);
    writeLinkedList(root);
    printf("\n");
    reverseList(&root);
    writeLinkedList(root);



    return 0;
}
