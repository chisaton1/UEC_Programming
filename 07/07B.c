#include<stdio.h>

double xn1(double x, double n){//再帰を用いたxのn乗
  if(n==1){
    return x;
  }else if(x==0){
    return 0;
  }else if(n==0){
    return 1;
  }else{
    return x*xn1(x,n-1);
  }
  }

double xn2(double x, double n){//繰り返しを用いたxのn乗
  int i,ans=1;
  if(n==1){
  return x;
  }else if(x==0){
    return 0;
  }else if(n==0){
    return 1;
  }else{
    for(i=0;i<n;i++){
      ans=ans*x;
    }
    return ans;
  }
}
  
double factsub(double n, double a){//再帰を用いたnの階乗
  if (n <= 1){ 
    return a;
  }
  return factsub(n-1,a*n);
}
double fact1(double n){
  return factsub(n,1);
}

double fact2(double n){//繰り返しを用いたnの階乗
  int ans=1;
  while(n!=0){
    ans=ans*n;
    n--;
  }
  return ans;
  }

/*int main(void){
  double x,n=0,ans=0;
  //scanf("%lf",&x);
  while(1){//n=0からn=29まで
    ans=ans+xn2(0.5,n)/fact2(n);
    n++;
    if(n==29){
      break;
    }
  }
  printf("%f\n",ans);
  return 0;
  }*/

int main(void){
  double ans,n,x;
  scanf("%lf %lf",&x,&n);
  ans=xn2(x,n);
  printf("%lf\n",ans);
  return 0;
  }
