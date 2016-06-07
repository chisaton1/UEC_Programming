#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define LISTMAX 1000

typedef char * elementtype;
typedef struct {
  elementtype music[LISTMAX];
  int n;
} ListPlayer;

ListPlayer LP_init();
ListPlayer LP_addmusic(ListPlayer lp, elementtype music);
void LP_play(ListPlayer lp, int b, int e);
void LP_search(ListPlayer lp, char * buf);
void chomp(char *buf, int n);

main(){
  ListPlayer myplayer;
  char * music;
  int b, e, d, bi, ci;
  char buf[1024], cmdbuf[16], cmd;

  myplayer = LP_init();

  while(1){
    fgets(buf, sizeof(buf), stdin);
    chomp(buf, sizeof(buf));
    if(buf[0] == '.') break;
    music = strdup(buf); // keep a text line on memory 文字列をコピーしてポインタを返す
    myplayer = LP_addmusic(myplayer, music);//myplayerは構造体
  }
  
  /* command parser */
  while(1){
    b = e = d = 0;
    fgets(buf, sizeof(buf), stdin);
    bi=0;
    ci=0;
    while(isdigit(buf[bi])){
      cmdbuf[ci] = buf[bi];
      bi++; ci++;
    }
    cmdbuf[ci] = '\0';
    b = atol(cmdbuf);//char型をint型に変換
    if(buf[bi] == ','){
      bi++;
      ci=0;
      while(isdigit(buf[bi])){
	cmdbuf[ci] = buf[bi];
	bi++; ci++;
      }
      cmdbuf[ci] = '\0';
      e = atol(cmdbuf);
    }
    cmd = buf[bi];
    if(cmd != '/'){
      bi++;
      ci=0;
      while (isdigit(buf[bi])){
	cmdbuf[ci] = buf[bi];
	bi++; ci++;
      }
      cmdbuf[ci] = '\0';
      d = atol(cmdbuf);
    }
    /* command execution */
    if (cmd == 'p'){
      LP_play(myplayer, b, e);
    }
    else if (cmd == '/'){
      chomp(&buf[bi+1], sizeof(buf)-bi-1);
      LP_search(myplayer, &buf[bi+1]);
    }else if (cmd == '.'){
      break;
    }
  }
}

void LP_search(ListPlayer lp, char * buf){
  printf("LP_search : %s size %d\n", buf, (int)strlen(buf));
  /* 問B の/ 検索と表示をここで行う*/
}

ListPlayer LP_addmusic(ListPlayer lp, elementtype music){
  int i,j;
  //elementtpyeはcharのポインタ
  if(lp.n >= LISTMAX){//容量が足りないとき
    return lp;//そのまま曲を挿入せずに返す
  }

  lp.n++;//lp.n曲目（もちろん最初は１曲目）

  for(i=lp.n-1;i>=0;i--){//挿入する位置の決定
    if(strcmp(lp.music[i],music)>0){
      lp.music[i+1]=lp.music[i];//挿入位置まですべての要素を一つずつずらす
    }else{
      i++;//格納されている曲目を次に進める
      break;
    }
  }
  lp.music[i]=music;//挿入
  return lp;
}

void LP_play(ListPlayer lp, int b, int e){
  int i;
  //表示できない条件のときの処理
  
  if(b<1){//表示する曲が０番目以下のとき
    if(e<1){//表示する終わりの曲も０以下のとき
      return;
    }
    if(e>=1){//表示する終わりの曲が１以上のとき、はじめの表示する曲を１番目とする
      b = 1;
    }
  }
  if(b>lp.n) return;//b番目に曲がないとき
  if(e<b){//終わりのe番目よりはじめのb番目の方が大きいとき
    e = b;
  }
  if(e>lp.n){//終わりの曲が入力した曲数より大きい場合
    e=lp.n;
  }

  
  for(i=b;i<=e;i++){
    printf("%s\n",lp.music[i]);
  }
  /* ListPlayer 内の「配列」から範囲を出力するプログラムをここに書く*/
}

ListPlayer LP_init(){
  ListPlayer lp;
  lp.n = 0;/* 適切な値を設定すること*/
    lp.music[0] = strdup(""); /* 文字列の番兵(最小の文字列) */
  return lp;
}

void chomp(char *buf, int n){
  int i;
  for(i=0; i<n; i++){
    if(buf[i] == '\n'){
      buf[i] = '\0';
      break;
    }
  }
}
