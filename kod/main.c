#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
int reverse(int n) {
   static int r = 0;

   if (n == 0)
      return 0;

   r = r * 10;
   r = r + n % 10;
   reverse(n/10);
   return r;
}
int main()
{
    FILE *myFile;
    myFile = fopen("sehirmesafe.txt", "r");
    int distance[22][7];
    int i , x , y;
    char chara , save ,a[2] , b[2] , c[2];
    while(!(feof(myFile))){
            for(i=0;i<2;i++){
                a[i]='d';
            }
            for(i=0;i<2;i++){
                b[i]='d';
            }
            for(i=0;i<2;i++){
                c[i]='d';
            }
            chara=getc(myFile);
            i=0;
            if(chara=='a'){
                while(!(feof(myFile))){
                    if(chara=='b'){
                    x=atoi(a);
                    printf("%dx" , x);
                        break;}
                    chara=getc(myFile);
                    a[i]=chara;
                    i++;
                }
            }
            i=0;
            if(chara=='b'){
                while(!(feof(myFile))){
                    if(chara=='c'){
                    y=atoi(b);
                    printf("%dy" , y);
                        break;}
                    chara=getc(myFile);
                    b[i]=chara;
                    i++;
                }

            }
            i=0;
            if(chara=='c'){
                while(!(feof(myFile))){
                    if(chara=='a'){
                    distance[x][y]=atoi(b);
                    printf("%d**\n" , distance[x][y]);
                        break;}
                    chara=getc(myFile);
                    c[i]=chara;
                    i++;
                }
            }
            i=0;
            if(chara=='a'){
                while(!(feof(myFile))){
                    if(chara=='b'){
                    x=atoi(a);
                    printf("%dx" , x);
                        break;}
                    chara=getc(myFile);
                    a[i]=chara;
                    i++;
                }
            }
        }

    return 0;
}
