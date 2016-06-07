#include<stdio.h>
#define SIZE 78
char buf[SIZE+2];

char *check(int *c, char *s){

  while(1){

    if(*s=='('){
      s++;//括弧の次の文字のポインタへ
      *c = 3;
      return check(c,s);

      if(*s==')'){
        s++;
        return check(c,s);//文字チェックへ戻る
	   }else{
        *c=3;//パターンC（とじ括弧が足りない）
    }
  }

  if(*s=='{'){
    s++;//括弧の次の文字のポインタへ
    *c = 4;//４はABCいずれも満たさないときとする
    return check(c,s);
    
    if(*s=='}'){
      s++;
      return check(c,s);//文字チェックへ戻る
	}else{
      *c=3;//パターンC(とじ括弧が足りない)
    }
  }
    
    if(*s==')'){
      return check(c,s);
    }

    if(*s=='}'){ 
      return check(c,s);
    }
    
  s++;//while全体のポインタ更新
  
  if(*s=='\0'){//文字の最後まできたらwhile文終了
    *c=1;//パターンA(すべての括弧が対応して使われている)
    break;
  }

  }

}
    
int main(void){
  int *c;
    fgets(buf, sizeof(buf), stdin); //一行読み込む
 
    check(c,buf);

    if(*c==1){
      printf("yes\n");
    }

    if(*c==2||*c==3){
      printf("no\n");
    }

    return 0;
  }
