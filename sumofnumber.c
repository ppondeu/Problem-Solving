#include <stdio.h>
#include<string.h>

int main()
{
   char a[101];
   char b[101];
   scanf("%s %s",a,b);
   int h = strlen(a);
   int l = strlen(b);
    int N;
    if(h>=l){
        N = h+1;
    }else{
        N = l+1;
    }

    char c[N+1];
    char d[N+1];
    strcpy(c,"");
    strcpy(d,"");

   for(int i=0;i<N-h;i++){
      c[i]='0';
   }

   for(int i=0;i<N-l;i++){
      d[i]='0';
   }

    c[N-h] ='\0';
    d[N-l]='\0';

   // printf("%s\n%s\n",c,d);

   //  memset(c,'0',N-h);
   //  memset(d,'0',N-l);

    strcat(c,a);
    strcat(d,b);



    char e[N+1];
    strcpy(e,"");
   int mod=0,div=0;
   int cnt=0;
   int j=0;
   for(int i=N-1;i>=0;i--){
    int x = c[i] -'0';
    int y = d[i] -'0';
    int sum = x+y+div;
    div = sum/10;
    mod = sum%10;
    char cv = mod + '0';
    e[j++]=cv;

   }

    for(int i=N-1;i>=0;i--){
        if(i==N-1&&e[i]=='0'){
            continue;
        }
        printf("%c",e[i]);
    }

    return 0;
}
