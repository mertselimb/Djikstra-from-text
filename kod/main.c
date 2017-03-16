#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
int calculate(int path[23]){
    int calculation , i;
    for(i=1;i<23;i++){
        calculation=path[i]+calculation;
    }
    return calculation;
}
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
    int v=1,f , g ,source,target,least=99,start,distance[23][23],i , x , y,pathNow[23],pathBest[23],distanceNow=0,distanceBest=0,k,save;
    char chara , selected[23] ,a[2] , b[2] , c[2];
    for(f=1;f<23;f++){
        for(g=1;g<23;g++){
            distance[f][g]=INFINITY;}}
    chara=getc(myFile);
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

            i=0;
            if(chara=='a'){
                while(!(feof(myFile))){
                    if(chara=='b'){
                    x=atoi(a);
                        break;}
                    chara=getc(myFile);
                    a[i]=chara;
                    i++;
                }
                continue;
            }
            i=0;
            if(chara=='b'){
                while(!(feof(myFile))){
                    if(chara=='c'){
                    y=atoi(b);
                        break;}
                    chara=getc(myFile);
                    b[i]=chara;
                    i++;
                }
                continue;
            }
            i=0;
            if(chara=='c'){
                while(!(feof(myFile))){
                    if(chara=='a'){
                    distance[x][y]=atoi(c);
                        break;}
                    chara=getc(myFile);
                    c[i]=chara;
                    i++;
                }
                continue;
            }
            i=0;

        }
    printf("Please write the plate number of the selected city:");
    scanf("%d" , &source);
    printf("Please write the plate number of the destination:");
    scanf("%d" , &target);
    for(f=1;f<23;f++)
        selected[f]=0;
    selected[source]=1;
    start=source;
    while(1){
        for(f=1;f<23;f++){
            if(distance[start][f]<least&&selected[f]==0){
                least=distance[start][f];
                save=f;
            }
        }
        v++;
        selected[save]=1;
        start=save;
        pathNow[v]=save;
        if(selected[source]=1){
        distanceNow=calculate(pathNow);
            if(distanceNow>distanceBest){
                for(k=0;k<23;k++){
                    pathBest[k]=pathNow[k];
                }
                v=1;
            }
        }
    }

    return 0;
}
