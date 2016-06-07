#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
  int id; /* 学籍番号*/
  char account[9]; /* アカウント名*/
};

void set(struct student *s, int id, char *account) {
  s->id = id;
  strncpy(s->account, account,9);/*s.accountにaccountの内容をコピー*/
}
struct student *search(struct student students[], int n, int id) {
  int i;
  for(i=0;i<n;i++){/*students[i]とidが一致しているかどうかのチェック*/
    if(id == students[i].id){
      return &students[i]; 
    }
  }  
  if(i==n){   
      return NULL;
  }
}

int main(void) {
#define BUFSIZE 80
#define STDNT 5
  struct student students[STDNT], *s;
  char buf[BUFSIZE], *account;
  int i, len, id;

  /* 5(STDNT) 人分の学籍番号とアカウント名を読み込み，配列students にセットする．*/
  for (i = 0; i < STDNT; i++) {
    fgets(buf, sizeof(buf), stdin);
    len = strlen(buf);
    if (buf[len - 1] == '\n') buf[len - 1] = '\0';
    buf[7] = '\0';
    id = atoi(buf);
    account = buf + 8;
    while (*account == ' ') {account++;}

　s = realloc(s,sizeof(buf) * 100);
　free(s);

    set(&students[i], id, account); /* ここからset を呼び出している*/
  }

  /* 学籍番号が与えられる間，それに対応するアカウント名を表示する．*/
  while (fgets(buf, sizeof(buf), stdin)) {
    if (buf[0] == '\n' || buf[0] == '\0') break;
    s = search(students, STDNT, atoi(buf)); /* ここからsearch を呼び出している*/
    if (s == NULL)
      printf("no data\n");
    else
      printf("%s\n", s->account);
  }
  return 0;
}
