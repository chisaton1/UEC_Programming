#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLENGTH 80 /* 曲名の最大長*/
typedef char* elementtype;

struct node {
  elementtype element;
  struct node *next;
  struct node *prev;
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

position lseek(list l, int num);
position previous(list l, position p);
void delete(list l, position p);

void p(list l, int num1, int num2);
void r(list l, int num1, int num2);
void m(list l, int num1, int num2);
void d(list l, int num2);

int main(void){
  list l;
  char a[MAXLENGTH+2];
  char com;
  int num1,num2;
  l=initlist();
  
  while(1){
    fgets(a, sizeof(a), stdin);
    if(a[0] == '.'){
      break;
    }
    insert(l,end(l),a);//リストの最後に挿入
  }
  while(1){

    scanf("%c %d %d",&com, &num1, &num2);

    if(com == 'p'){
      p(l,num1,num2);
    }
    if(com == 'r'){
      r(l,num1,num2);
    }
    if(com == 'm'){
      m(l,num1,num2);
    }
    if(com == 'd'){
      d(l,num2);
    }
    if(com == 'q'){
      break;
    }
  }
  return 0;
}
      

list initlist(void){//リストの初期化
  list l;
  l = (list)malloc(sizeof(struct node));
  l->next = NULL;
  l->prev = NULL;
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
  if(p->next != NULL){
    p->next->prev = l2;
  }
  l2->next = p->next;
  p->next = l2;
  l2->prev = p;
}

elementtype retrieve(list l, position p){//リストl 内の位置pにある要素の値を返す
  return p->element;
}

position lseek(list l, int num){//リストlの先頭からnum番目の位置を返し、num番目がないときは0を返す
  position p;
  p = l;
  int i;
  for(i=0;i<num;i++){
    if(p==NULL){
      return 0;
    }
    p=p->next;
  }
  return p;
}

position previous(list l, position p){//リストl内の位置pの直前の要素の位置を返す
  return p->prev;
}

void delete(list l, position p){//リストl内の位置pの直前の要素を削除する
  position prep, nextp;
  prep = previous(l,p);
  nextp = next(l,p);

  prep->next = nextp;

  // if(nextp != NULL;){
    nextp->prev = prep;
    // }

  free(p);
  free(p->element);
}

void p(list l, int num1, int num2){//コマンドpの実装
  position p;
  int i;
  if(num1<=num2){
    while(1){
  p = lseek(l,num1);
  if(p == 0){//pがリストの範囲外にあったら
    break;
  }
  if(num1 != 0){
    printf("%s\n",retrieve(l,p));
  }
  if(num1 == num2){
    break;
  }
  num1++;
    }
  }
}

void r(list l, int num1, int num2){//コマンドrの実装
  position p;
  int i;
  p = lseek(l,num1);
  for(i=0;i<num2;i++){
    if(num1 == 0){ break;//ヘッダなら終了
    }
    if(p != 0){
 printf("%s\n", retrieve(l,p));
    }
    num1--;
    p = lseek(l,num1);//一つ前に戻す
  }
}

void m(list l, int num1, int num2){
    position p1, p2;
    elementtype e1, e2, e3;
    int i;
    
    if(num1 != 0 && num2 != 0){
      //num1,num2の位置をp1,p2に格納する
      p1 = lseek(l,num1);
      p2 = lseek(l,num2);
      if(p1 != 0 && p2 != 0){//もしp１、p２どちらもリスト内ならば
        e1 = (elementtype)malloc(sizeof(char) * (MAXLENGTH+2));
        e2 = (elementtype)malloc(sizeof(char) * (MAXLENGTH+2));
        e3 = retrieve(l,p1);//p1の場所をe3へ
        for(i=0;e3[i]!='\0';i++){//コピー
	  e1[i] = e3[i];
        }
        e1[i] = '\0';
        e3 = retrieve(l,p2);//p2の場所をeへ
        for(i=0;e3[i]!='\0';i++){//コピー
	  e2[i] = e3[i];
        }
        e2[i] = '\0';
        
        insert(l,p1,e2);//p1の次の場所へe２の要素を挿入
        delete(l,p1);//p１削除
        insert(l,p2,e1);//p2の次の場所へe1の要素を挿入
        delete(l,p2);//p2削除
        free(e1);//解放（不要になったので）
        free(e2);
      }
    }
    printlist(l);
}

void d(list l, int num2){//num2番目を削除してからリストすべてを表示する
    position p;    
    p = lseek(l,num2);
    if(num2 != 0){
      delete(l,p);
    }
    printlist(l);
}

