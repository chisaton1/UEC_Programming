#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 10000
#define N 7

/* (x,y) 地点とそこまでの距離c を記録する構造体*/
struct cost {
  int x;
  int y;
  int c;
};

 typedef struct cost elemtype;

 struct queue{
    int head;/*キューの先頭が配列のどこにあるか*/
    int tail;/*キューの最後尾が配列のどこにあるか*/
    elemtype elem[QUEUESIZE];/*キューに蓄えられたデータ*/
  };
 
  void enqueue(struct queue *q, elemtype val) {
    
    q->elem[q->tail] = val;/*受け取った数値を代入*/
    q->tail++;/*どんどん後ろにずらしていく*/
    if(q->tail >= QUEUESIZE){/*指定のサイズまで増えたら*/
      q->tail = 0;/*先頭に戻る*/
    }
    if(q->tail == q->head){
      exit(1);
    }
  }
  
 elemtype dequeue(struct queue *q){
   elemtype val;/*enqueueの逆操作*/
   if(q->head == q->tail){
     exit(1);
   }else{
     val = q->elem[q->head];
     q->head++;
    if(q->head >= QUEUESIZE){
      q->head = 0;
    }
    return val;/*取り出した値を返す*/
   }
 }
 
 void initqueue(struct queue *q){/*初期化*/
   q->head = q->tail = 0;
 }
 

int main(void) {
#define BUFSIZE (N*2)

  char buf[BUFSIZE];
  char maze[N][N];
  int i, j, sx, sy, gx, gy;
  struct cost pos;/*この時点でメンバpos.x,pos.y,pos.cが存在する*/
  struct cost pos2;
  /* 迷路を読み込み、maze にセットする。*/
  for (i = 0; i < N; i++) {
    fgets(buf, BUFSIZE, stdin);
    for (j = 0; j < N && (buf[j] != '\n' && buf[j] != '\0'); j++) {
      if (buf[j] == 'S') {
	sx = i; sy = j; buf[j] = ' ';/*Sのある場所をsxとsyに記録*/
      } else if (buf[j] == 'G') {
	gx = i; gy = j; buf[j] = ' ';/*Gのある場所をgxとgyに記録*/
      }
      maze[i][j] = buf[j];
    }
    while (j < N) maze[i][j++] = ' ';
  }

  pos.x = sx;
  pos.y = sy;
  pos.c = 0;/*初期化*/
 
 initqueue(&q);
  
 enqueue(&q, pos);/*構造体を構造体へ入れる*/

 while(1){

   pos = dequeue(&q);

   if(maze[pos.x+1][pos.y] != '*'){/*migi*/

     pos2.x = pos.x+1;

     pos2.y = pos.y;

     pos2.c = pos.c+1;

   }

   if(maze[pos.x][pos.y+1] != '*'){/*shita*/

     pos2.x = pos.x;

     pos2.y = pos.y+1;
  
     pos2.c = pos.c+1;
   
   }

   if(maze[pos.x-1][pos.y] != '*'){/*hidari*/

     pos2.x =pos.x-1;

     pos2.y = pos.y;

     pos2.c = pos.c+1;

   }

 if(maze[pos.x][pos.y-1] != '*'){/*ue*/

     pos2.x =pos.x;

     pos2.y = pos.y-1;

     pos2.c = pos.c+1;

   }


 


 /* 最短距離を表示する。*/
 printf("%d\n", pos.c);
 return 0;
}
