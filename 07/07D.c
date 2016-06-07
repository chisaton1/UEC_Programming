#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 20 * 1024
#define N 10
#define BUFSIZE (N*2)

int hitohude(int maze[N][N],int ans,int n){//初回は東京からなのでn＝１
  int m=1;
  for(m>N,m++){
    if(maze[n][m]!=-1){
      maze[n][m]=maze[m][n]-1;//同じ道を二度と繰り返さないように(往復)
      ans=ans+hitohude(maze,ans,m);
    }
  }
  return ans=0;//通ってない道がもうなければそれ以上ないという値を返す
}

int main(void) {
  int buf[BUFSIZE];
  int maze[N][N];
  int n, m;//n行m列
  int ans=0;
  
  /* 行列を読み込み、maze にセットする。*/
  for (n = 0; n < N; n++) {
    fgets(buf, BUFSIZE, stdin);
    for (m = 0; m < N && (buf[m] != '\n' && buf[m] != '\0'); m++) {
    }
    maze[n][m] = buf[m];
  }
  ans=hitohude(maze,ans,1);//初回は東京からなのでn＝１
    printf("%d\n",ans);
  return 0;
}
