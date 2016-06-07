#include<stdio.h>

#include<stdlib.h>

#define N 3 /*行列のサイズ*/

#define M 4

#define BUFLEN 100

float m[N][N];/*読み込んだ行列*/

char buf[BUFLEN];/*１行を読み込む配列*/

 /*行列と行列の乗算を行う関数*/

 

int main(void){

  int r,c;

  /*読み込み*/

  for(r = 0; r < N; r++){

    char *p = fgets(buf,sizeof(buf),stdin);

    for(c = 0; c < N; c++){

      m[r][c] = strtof(p, &p);

    }

  }

  /*行列の乗算*/

  int i,j,k,z=0;

    float b[N][N];

    float a[N][N];

    /*初期化*/

    for(i=0;i<N;i++){

      for(j=0;j<N;j++){

	b[i][j] = 0;
	
      }

    }

      /*m行列をa行列に保存*/

    for(i=0;i<N;i++){

       for(j=0;j<N;j++){
	
	a[i][j] = m[i][j];

      }
      
     }

 /*M回繰り返す*/

    while(z<M){

    for(i=0;i<N;i++){

      for(j=0;j<N;j++){

	for(k=0;k<N;k++){

	  b[i][j] = b[i][j] + m[i][k] * a[k][j];

	}

      }

    }

    /*m行列の更新*/

 for(i=0;i<N;i++){

      for(j=0;j<N;j++){

    m[i][j] = b[i][j];

      }

 }

     z++;

     }

  /*出力*/

  for(r = 0; r < N; r++){

    for(c = 0; c < N; c++){

      if(c > 0){

	printf(" ");

      }

      printf("%f", b[r][c]);

    }

    printf("\n");

  }

  return 0;

}
