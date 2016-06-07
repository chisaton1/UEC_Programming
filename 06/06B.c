#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef int elemtype;

struct stack {
  int n;
  int m;
} comb;

struct stack {
  int top;
  elemtype elem[SIZE];
};

void push(struct stack *s, elemtype val){
  s->top++;
  if(s->top >= SIZE){
printf("stack overflow\n");
 exit(1);
  }else{
    s->elem[s->top] = val;
  }
}

elemtype pop(struct stack *s){
  elemtype val;
  if(s->top < 0){
    printf("stack underflow\n");
    exit(1);
  }else{
    val = s->elem[s->top];
    s->top--;
return val;
  }
}

void initstack(struct stack *s){
  s->top = -1;
}
int stackempty(struct stack *s){
  return s->top < 0;
}

int combination(int n, int m);//プロトタイプ宣言

int main(void){

  int n,m,ans;
  scanf("%d %d",&n,&m);
  ans=combination(n,m);
  printf("%d\n",ans);
  return 0;
}


int combination(int n, int m){
struct stack s;
initstack(&s);//初期化

 comb a={n,m};
 int ans=0;

 push(&s,a);
 while(!stackempty(&s)){
  a=pop(&s);
  if(a.n==a.m||a.m==0||a.n==1){
    return ans+1;
  }else{
    a.n=a.n-1;
    push(&s,a);
    a.m=a.m-1;
    push(&s,a);
  }
 }
 return ans;
}

/*L0:
  if(n!=m||m!=0||m!=1){
  push(&s,n); push(&s,m);
  n=n-1; m=m-1;
  goto L0;
 L1:
  n=n-1;//mはそのまま
  }
  if(stackempty(&s))goto L2;//スタックが空になったら繰り返しを抜ける
  m=pop(&s); n=pop(&s);
  goto L1;
 L2:
  return n+m; 
  }*/

/*int combination(int n, int m){

 if(n==m||m==0){
    return 1;//終端条件
  }else if(m==1){
    return n;
  }else{
   combination(n-1,m-1)+combination(n-1,m);
 }
 }*/

