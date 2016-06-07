#include<stdio.h>

int v[2] = {29, 29* 63 + 15};
int fiv(int n) {
  int a;
  int b;
  int i;

  /*この時点の様子１*/
  /* for(i=3;i>=n;i--){
    if(i==3)printf("[");
    printf("{n=%d, a=?, b=?}",i);
    if(i!=n){
      printf(", ");
    }else{
      printf("]\n");
    }
    }*/
    
  printf("{n=%d, a=?, b=?}\n",n);
  if (n <= 1) {
    return v[n];
  } else {
    a = fiv(n - 1);
    /*この時点の様子２*/
    printf("{n=%d, a=%d, b=?}\n",n,a);
    b = fiv(n - 2);
    /*この時点の様子３*/
    printf("{n=%d, a=%d, b=%d}\n",n,a,b);
    return a + b;
  }
}

/*int ss(int n) {
  int m,i;
  
  for(i=4;i>=n;i--){
    if(i==4)printf("[");
    printf("{n=%d, m=?}",i);
    if(i!=n){
      printf(", ");
    }else{
      printf("]\n");
    }
 
  if (n < 2) {
    return n;//mがまだ定まっていない時
  } else {
    m = ss(n-1);
    
    for(i=4;i>n;i--){
      if(i==4)printf("[");
      printf("{n=%d, m=?}, ",i);
    }
    if(i==4)printf("[");
    printf("{n=%d, m=%d}]\n",n,m);
    return n*n + m;//mがすでに定まっている時
  }
}*/

int main(void){
  int ans,n;
  fiv(3);
  return 0;
}
