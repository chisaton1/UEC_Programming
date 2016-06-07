#include<stdio.h>
#include<stdlib.h>
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

void headinsert(struct node *p, elementtype x){//割り込ませて前に入れるタイプ
  struct node *n;
  n = (struct node *)malloc(sizeof(struct node));
  n->element = x;
  n->next = p->next;
  p->next = n;
}

void tailinsert(struct node *p, elementtype x){//後ろから入れるタイプ
  struct node *n;
  while(p->next!=NULL){
    p=p->next;
  }
  n = (struct node *)malloc(sizeof(struct node));
  n->element = x;
  n->next = p->next;
  p->next = n;
}

void printlist(struct node *p){
  if(p==NULL){
    putchar('\n');
    return;
  }
  putchar(p->element);
  printlist(p->next);
}

int main(void) {
  struct node *list;
  list = initlist();
  while (1) {
    int c = getchar();//入力
    if (c == '\n' || c == EOF) {
      break;
    }
    
    if(c=='a'){
      headinsert(list, c);
    }
    if(c=='b'){
      tailinsert(list,c);
    }
  }
  printlist(list->next);
  return 0;
}


