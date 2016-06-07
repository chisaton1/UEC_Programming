#include<stdio.h>
#include<stdlib.h>

struct mydata {int i; char c; double d;};
int gi; char gc; double gd;
int ga[100];
struct mydata gs;
void f1(void) {
int i;
/* ここで，局所変数i のアドレスを表示．*/
 printf("%p\n",&i);
}
void f2(void) {
int a[10]; /* この下で，このa のアドレスも表示するとよい．*/
 printf("%p\n",&a);
f1();
}
void f3(void) {
int a[20]; /* この下で，このa のアドレスも表示するとよい．*/
 printf("%p\n",&a);
f1();
}

int main(void) {
int mi; char mc; double md;
int ma[100];
struct mydata ms;
char *p, *q;
p = (char*)malloc(100);
q = (char*)malloc(100);
/* ここで，大域変数，main の局所変数，malloc() で確保したアドレスを表示．*/
 printf("%p\n%p\n",&p,&q);
f1();
f2();
f3();
return 0;
}
