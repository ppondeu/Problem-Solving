#include<stdio.h>
int main() {
  int A,B,H;
  scanf("%d%d%d",&A,&B,&H);
  int dif = H-A;
  int up = A-B;
  int mod = dif%up;
  int days;
  if(mod==0){
    days = dif/up;
  }else{
    days = dif/up + 1;
  }
  printf("%d",days+1);
  return 0;
}
