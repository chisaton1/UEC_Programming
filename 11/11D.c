#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 10000
struct student {
  int id,kaasoru;
    char account[9];
};

void swap(struct student *x, struct student *y) {
    struct student temp;
    temp = *x; 
    *x = *y;
    *y = temp;
}

//idとassountをsetする
void set(struct student* a, int id, char *account) {
    a->id = id;
    strcpy(a->account, account);
}

//挿入ソート
void insert(struct student* a, int n, struct student v){
    int i, j;
    
    a[n] = v;
    //最初の要素に０を代入
    if(n == 0){
      a[n].kaasoru = 0;
    }
    //ソートする
    for(i=0;i<n;i++){
        if(a[i].id > a[n].id){
            a[n].kaasoru = a[i].kaasoru;
            a[i].kaasoru++;
        }
    }
}

//配列をソートする
void sort(struct student* a, int n){
    int i, j;
    
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(i == a[j].kaasoru) break;
        }
        swap(&a[i], &a[j]);
    }
}

int main(void) {
#define BUFSIZE 80
    struct student *students, v;
    char buf[BUFSIZE], *account;
    int nstudents; /* 読み込んだ学生の数 */
    int i, len, id;
    
    /* LIMIT 件分の配列を確保 */
    students = (struct student*) malloc(sizeof(struct student) * LIMIT);
    
    /* 読み込み */
    for (nstudents = 0; nstudents < LIMIT; nstudents++) {
        if (fgets(buf, sizeof(buf), stdin) == NULL)
            break; /* 入力の終わりで抜ける */
        len = strlen(buf);
        if (buf[len-1] == '\n') buf[len-1] = '\0'; /* 行末の改行文字を消す */
        buf[7] = '\0';
        id = atoi(buf);
        account = buf + 8;
        while (*account == ' ') account++;
        set(&v, id, account); /* v の id と account を設定 */
        insert(students, nstudents, v); /* students 配列の適切な位置に v を挿入 */
    }
    
    /*配列をカーソルの順にソート*/
    sort(students, nstudents);
    /* 表示 */
    for (i = 0; i < nstudents; i++)
        printf("%7d %s\n", students[i].id, students[i].account);
    return 0;
}

