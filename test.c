#include <stdio.h>
#include <stdlib.h>

#define DEBUG printf("\n!!!\n");

struct Node {
    int num;
    struct Node* next;
};

struct Pointers {
    struct Node* First;
    struct Node* Last;
};

struct Node* NewNode (int n) {
    struct Node* new = (struct Node *)malloc(sizeof(struct Node));
    new->num=n;
    new->next=NULL;
    return new;
}

void addNode(){

}


int main(){
    struct Pointers list;
    struct Node* node = NewNode(1);
    list.First = node;
    list.Last = node;
    struct Node* new;
    int i=2;
    while (i<10) {
        new = NewNode(i);
        ++i;
        list.Last->next = new;
        list.Last = new;
    }
    struct Node* ptr = list.First;
    while(ptr->next != NULL) {
        //DEBUG
        printf("%d ",ptr->num);
        ptr = ptr->next;
    }
    printf("%d\n",ptr->num);
}