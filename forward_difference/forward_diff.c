#include <stdio.h>
#include <math.h>


double func(double x) {
  return x*x;
}

//前進差分
double forward_diff(double h,double x) {
  return (func(x + h) - func(x)) / h ;
}

int main(void) {
  double h,x;
  int    n;

  //任意の値
  x = 1.0;

  //f(x)の最上位bitを求める
  n = floor(log2(fabs(func(x))));

  //f(x)の最上位bit
  h = pow( 2.0 , n );
  //h = 2^n,2^(n-1),...2^(n-52)
  for (int i = 0; i < 53; i++) {
    //f'(x)を出力
    printf("[%2d]%.15lf\th=%.15e\n",i+1,forward_diff(h,x),h);
    //有効桁数の範囲で1bitずつ下げる
    h *= 0.5;
  }

  return 0;
}
