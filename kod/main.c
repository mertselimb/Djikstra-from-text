#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
int minDistance(int dist[], int sptSet[])
{
   // Initialize min value
   int min = INFINITY, min_index , v;

   for (v = 0; v < 23; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   int i ;
   for (i = 0; i < 23; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
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
    int f , g ,source,target,start,distance[23][23],i , x , y;
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
//----------------------------------------------------------------------------------------------
    int dist[23] , v  , count;
    int sptSet[23];
    for (i = 0; i < 23; i++)
        dist[i] = INFINITY, sptSet[i] = 0;
    dist[0] = 0;
    for (count = 0; count < 23-1; count++)
     {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (v = 0; v < 23; v++)
            if (!sptSet[v] && distance[u][v] && dist[u] != INFINITY
                                       && dist[u]+distance[u][v] < dist[v])
                dist[v] = dist[u] + distance[u][v];
     }
     printSolution(dist, 23);
    //printf("Closest paths length is ;%d" , calculate(pathBest));

    return 0;
}
