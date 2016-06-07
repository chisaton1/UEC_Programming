#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLENGTH 80 /* 曲名の最大長*/
typedef char* elementtype;

struct node {
  elementtype element;
struct node *next;
};

typedef struct node *link;
typedef link list;
typedef link position;

//プロトタイプ宣言    
list initlist(void);
position first(list l);
position end(list l);
position next(list, position p);
void printlist(list l);
void insert(list l, position p, elementtype e);
elementtype retrieve(list l, position p);


int main(void){
  list l;
  char a[MAXLENGTH+2];
  l=initlist();
  
  while(1){
    fgets(a, sizeof(a), stdin);
    if(a[0] == '.'){
      break;
    }
    insert(l,end(l),a);//リストの最後に挿入
  }
  
  printlist(l);
  
  return 0;
}

list initlist(void){//リストの初期化
  list l;
  l = (list)malloc(sizeof(struct node));
  l->next = NULL;
  return l;
}

position first(list l){//リストlの先頭のノードの位置を返す
  return l;
}

position end(list l){//リストlの最後のノードの位置を返す
  position p;
  p = l;
  while(p->next != NULL){
    p = p->next;
  }
  return p;
}

position next(list l, position p){//位置pの次の要素の位置を返す
  return p->next;
}

void printlist(list l){//リスト内の要素を順に表示する
  position p;
  p = l;
  while(p->next != NULL){
    p = p->next;
    printf("%s\n",p->element);
   
  }
}

void insert(list l, position p, elementtype e){//前からの挿入パターン
  list l2;
  int i = 0;
  
  //リストl2とそれに格納する要素の領域をつくる
  l2 = (list)malloc(sizeof(struct node));
  l2->element = (elementtype)malloc(sizeof(char)*(MAXLENGTH+2));
  
  //リストl2に曲名をコピーする  
  while(e[i] != '\n' && e[i] != '\0'){
    l2->element[i] = e[i];
    i++;
  }
  l2->element[i] = '\0';
  
  //p->nextにl2を挿入
  l2->next = p->next;
  p->next = l2;
}

elementtype retrieve(list l, position p){//リストl 内の位置pにある要素の値を返す
  return p->element;
}
