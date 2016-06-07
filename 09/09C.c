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


void printlist(struct node *p){
  while(p!=NULL){
    putchar(p->element);
    p=p->next;
  }
  putchar('\n');
}


int check(struct node *p,struct node *keep, int i){//回文なら１それ以外なら０を返す関数 

 if(p==NULL){
   return;
 }
 check(p->next,keep,i++);
 
 //while(i!=0){
 // keep=keep->next;//checkした分だけまわす
 // i++;
 // }

  printf("%d\n",i);
  putchar(keep->element);
  // putchar(p->element);
  putchar('\n');
}




int main(void) {
  struct node *list;
  list = initlist();
  while (1) {
    int c = getchar();//入力
    if (c == '\n' || c == EOF) {
      break;
    }
    insert(list, c);
  }
  // printlist(list->next);
  check(list,list,0);
  // putchar('\n');
  return 0;
}
