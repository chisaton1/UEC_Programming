#include<stdio.h>

typedef struct {
  int key;
} recordtype;

void heapsort(recordtype*, int);

void swap(recordtype *x, recordtype *y){
  recordtype tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

#define LIMIT 10000
recordtype a[LIMIT];

//通論の資料通り
void f(recordtype a[],int first){
  int i = first;
  int j = first/2;

  while(i != 0){
    if(a[i].key < a[j].key){
      break;
    }
    swap(&a[i],&a[j]);
    i = j;
    j = i/2;
  }
}

int main(void) {
#define BUFLEN 16
  char buf[BUFLEN];
  int i, n;
  for (n = 0; n < LIMIT; n++) {
    if (fgets(buf, sizeof(buf), stdin) == NULL) break;
    a[n].key = atoi(buf);
  }
  heapsort(a, n);
  for (i = 0; i < n; i++) printf("%d\n", a[i].key);
  return 0;
}



/* a[1]～a[n] のソート*/
//通論の資料のやりかた
void heapsort(recordtype a[], int n){
  int i,j;
  for(i=0;i<n;i++){
    f(a,i);
  }  
  for(i=n-1;i>=1;i--) {
    swap(&a[0], &a[i]);
    for(j=0;j<=i-1;j++){
      f(a,j);
    }
  }
}

