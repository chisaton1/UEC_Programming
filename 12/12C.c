#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char account[9]; /* アカウント名*/
  int score[10]; /* 10 種の試験の点数(各100 点満点) */
} student;

struct node {
  struct node *next;
  student data;
};

void listsort(struct node* l){//list=p
  
  int i, l2total, l3total;
  struct node *l2, *oldl2, *l3, *oldl3, *keep, *head;
 
  //l2を定義する
  oldl2 = l;
  l = l->next;
  l2 = l;
 
  //選択ソート→全体順になめる
  while(l2->next != NULL){
    //l3を定義する
    oldl3 = l2;
    l3 = l2->next;
    //l2の得点の合計を求める
    l2total = 0;
    for(i=0;i<10;i++){
      l2total = l2total + l2->data.score[i];
    }
    while(l3 != NULL){
      //l3の得点の合計を求める
      l3total = 0;
      for(i=0;i<10;i++){
	l3total = l3total + l3->data.score[i];
      }
      //もしl3の合計値の方が大きかったら
      if(l3total >= l2total){	
	//l3の合計値の方が大きい　または　辞書順でl3の方が先だったら
	if(l3total > l2total || strcmp(l3->data.account, l2->data.account) < 0){
	  //交換する
	  if(oldl3 != l2){
	    oldl2->next = l3;
	    keep = l2->next;
	    l2->next = l3->next;
	    l3->next = keep;
	    oldl3->next = l2;
	    l2 = oldl2->next;
	    l3 = oldl3->next;
	  }else{ 
	    l2->next = l3->next;
	    oldl2->next = l3;
	    l3->next = l2;
	    l2 = l3;
	    l3 = oldl3;
	  }
	  //l2の合計値を更新
	  l2total = l3total;   
	}
      } 
      //l3を更新
      oldl3 = l3;
      l3 = l3->next;
    }
    //l2を更新
    oldl2 = l2;
    l2 = l2->next;
  } 
}

int main(void) {
#define BUFLEN 1024
  char buf[BUFLEN], *s;
  struct node *list, *p;
  int i, n;
  p = list = (struct node*)malloc(sizeof(struct node));
  while (fgets(buf, sizeof(buf), stdin) != NULL) {
    p = p->next = (struct node*)malloc(sizeof(struct node));
    buf[8] = '\0';
    strcpy(p->data.account, buf);
    s = buf+9;
    for (i = 0; i < 10; i++) {
      while (isspace(*s)){//空白なら真の値を返す
	++s;
      }
      for (n = 0; isdigit(*s); ++s){//数字なら真の値を返す
	n = n*10 + (*s-'0');
      }
      p->data.score[i] = n;
    }
  }
  p->next = NULL;
  listsort(list);  

  for (p = list->next; p; p = p->next) {//表示
    printf("%s", p->data.account);
    for (i = 0; i < 10; i++){
      printf("%3d", p->data.score[i]);
    }
    printf("\n");
  }
  return 0;
}
  
