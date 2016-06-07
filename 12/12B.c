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

void pushdown(recordtype a[], int first, int last){
  int r = first; 
  int k = r+r+1;
  
  while(k<=last){
    if(k<last && a[k].key<a[k+1].key){
      k++;
    }
    if(a[r].key >= a[k].key){
      break;
    }
    swap(&a[r],&a[k]);
    r=k; 
    k=r+r+1;
  }
}

/* a[1]～a[n] のソート*/
void heapsort(recordtype a[], int n){
  int i;
  for(i=n/2;i>=0;i--){
    pushdown(a,i,n);
  }  
  for(i=n-1; i>=1; i--) {
    swap(&a[0], &a[i]);
    pushdown(a,0,i-1);
  }
}

