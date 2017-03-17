#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#include <limits.h>
#include <stdlib.h>
#define V 22
void dijkstra(int G[V][V],int n,int startnode,int d)
{
    int cost[V][V],distance[V],pred[V];
    int visited[V],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
    for(i=0;i<n;i++)
        if(i==d)
        {
            printf("\nDistance of node%d=%d",i,distance[i]);
            printf("\nPath=%d",i);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
    }
}
int reversefunc(int n) {
   static int r = 0;
   if (n == 0)
      return 0;
   r = r * 10;
   r = r + n % 10;
   reversefunc(n/10);
   return r;
}
int main()
{
    FILE *myFile;
    myFile = fopen("sehirmesafe.txt", "r");
    int f , g ,source,target,start,dist[22][22],i , x , y;
    char chara , selected[V] ,a[2] , b[2] , c[2];
    for(f=0;f<V;f++){
        for(g=0;g<V;g++){
            dist[f][g]=0;}}
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
                    dist[x][y]=atoi(c);
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
    dijkstra(dist, V , source , target );

    return 0;
}
