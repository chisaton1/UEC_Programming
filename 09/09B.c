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

void delete(struct node *p){//pの指す次のノードを削除
  if(p->next != NULL){
    p->next = p->next->next;
  }
}

struct node *check(struct node *p){//同じ文字があればその文字のアドレスを返す関数
  struct node *keep; 
  keep = p;//保存

  while(1){ 
    if(p->next==NULL){
      return p->next;//NULLの場所を返す
    }
    if(keep->element==p->next->element){//pを先に進めた訳じゃない
      return p;
    }
    p=p->next;
  }
}

int main(void) {
  int i=-1;//ナル文字分
  struct node *list,*p,*keep;
  list = initlist();
  while (1) {
  int c = getchar();//入力
  i++;
  if (c == '\n' || c == EOF) {
    break;
  }
  insert(list, c);
 }

 
while(i>0){
   p = check(list->next);
    if(p!=NULL){
      delete(p);
      delete(list);
      i=i-2;
    }else{
     putchar(list->next->element);
      list=list->next;
      i--;
      }
 }

    putchar('\n');
  return 0;
}


