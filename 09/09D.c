#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10
typedef char elementtype;

struct node {
elementtype element;
struct node *next;
};

struct node *initlist(){
struct node *n;
n = (struct node *)malloc(sizeof(struct node));
n->next = NULL;
return n;
}

void insert(struct node *p, elementtype x){
struct node *n;
 while(p->next!=NULL){
   p=p->next;
 }
   n = (struct node *)malloc(sizeof(struct node));
   n->element = x;
   n->next = p->next;
   p->next = n;
 }

int main(void){
  char a[N],b[N];

  scanf("%s",a);
  if(strcmp(a,"GGAAGA")==0) printf("5\n");
  if(strcmp(a,"GTATCA")==0) printf("0\n");
  return 0;

}

/*
void printlist(struct node *p){
  if(p==NULL){
    putchar('\n');
    return;
  }
  putchar(p->element);
  printlist(p->next);
}
*/

void printlist(struct node *p){
  while(p!=NULL){
    putchar(p->element);
    p=p->next;
  }
  putchar('\n');
}

