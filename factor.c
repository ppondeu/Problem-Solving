#include <stdio.h>
#include<math.h>
int main() {

    long long n;
    scanf("%lld",&n);
  if(n<=1){
    printf("ERROR!");
    return 0;
  }
    long long div=2;
    while(n>1){
        while(n%div==0){
            if(n==div){
                printf("%d",n);
                return 0;
            }
            printf("%d x ",div);
            n/=div;
        }
        if(div==2){
            div=3;
        }else{
            div+=2;
        }
    }
    return 0;
}
