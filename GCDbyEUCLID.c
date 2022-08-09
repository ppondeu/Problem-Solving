#include <stdio.h>

int main() {

    int a,b;
    scanf("%d%d",&a,&b);

    while(a%b!=0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    printf("%d",b);
   return 0;
}
