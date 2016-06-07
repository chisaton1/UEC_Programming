#include<stdio.h>

#include<string.h>

#define MAXLEN 78

char buf[MAXLEN+2];

char buf2[MAXLEN+2];

int main(void){

  while(1) {
    
    int len,len2,a,b,max=0;
  
    while( fgets(buf, sizeof(buf), stdin) != NULL){ /*配列名　サイズ(バイト) ファイルポインタ で一行読み込む*/

  if(buf[0] == '\n' || buf[0] == '\0') break; /*空行または改行であれば終了*/

  len = strlen(buf);

  if(buf[len-1] == '\n'){

    buf[len-1] = '\0';
  }/*改行がきたらナル文字に変更*/

  for(a=0; a < len-1; a++){
  
  if(buf[a] == '#'){
    
    buf[a] = '\0';
    
  }/*'#'をナル文字に変更*/

  }

  len2 = strlen(buf);
 
  if(max < len2){

    max = len2;

 strlcpy(buf2, buf, MAXLEN+2);/*bufをbuf2にコピー、一時的に保持する*/

  len2 = strlen(buf2);/*len2はbuf2の文字数*/

  }

  if(max == len2){

    b = strcmp(buf,buf2);

    if(b < 0){

       strlcpy(buf2, buf, MAXLEN+2);/*bufをbuf2にコピー、一時的に保持する*/

  len2 = strlen(buf2);/*len2はbuf2の文字数*/

    }

  }

    }/*ここまでを一行ずつ繰り返す*/

  printf("%s\n",buf2);

}

return 0;

}

