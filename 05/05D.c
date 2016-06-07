#include<stdio.h>

int number(int n,int y){//y円払ううちのa円の使う数を数え、返す関数
  int i,y2;
  int a[5];
  a[0]=1000;a[1]=500;a[2]=100;a[3]=50;a[4]=10;//初期化
  for(i=0;y2>0;i++){
    y2=y-a[n]*i;
    //i=i-1;//iはa円の枚数
    if(a[n]==10){
      return 1;//10円のみで払う組み合わせは常に１組（終端条件）
    }else{
      return number(n+1,y2);
    }
  }
 
}

int main(void){
  int i,y;
  scanf("%d",&y);
  i=number(0,y);
  printf("%d\n",i);
  return 0;
}
