#include<stdio.h>
#define SIZE 78
char buf[SIZE+2];

char *check(int *c, char *s){
  char *save;

  while(1){

  if(s=='('){
    s++;//括弧の次の文字のポインタへ
    save = s;//括弧の次のポインタを保存
    *c = 4;//４はABCいずれも満たさないときとする。
    return &check(&c,&s);

    if(s==')'){
      return &check(&c,%save)//文字チェックへ戻る
	}else{
      return 3;//パターンC（とじ括弧が足りない）へ
    }
  }

  if(s=='{'){
    s++;//括弧の次の文字のポインタへ
    save = s;//括弧の次のポインタを保存
    *c = 4;//４はABCいずれも満たさないときとする。
    return &check(&c,&s);
    
    if(s==')'){
      return &check(&c,%save)//文字チェックへ戻る
	}else{
      return 3;//パターンC（とじ括弧が足りない）へ
    }
  }
    
    if(s==')'){
      return &check(&c,&s);
    }

    if(s=='}'){ 
      return &check(&c,&s);
    }
    
  s++;//while全体のポインタ更新
  
  if(s=='\0'){//文字の最後まできたらwhile文終了
    return 1;//パターンA(すべての括弧が対応して使われている)へ
  }

  }

}
  
  
  int main(void){
    
    fgets(buf, sizeof(buf), stdin); /* 一行読み込む */
  
    
    
