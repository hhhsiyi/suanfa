#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
int d[20][40000];
using namespace std;
#define inf 0x3f3f3f
int main()
{
   int arc[20][20];
   int n;
   while(~scanf("%d",&n))
   {
       int ans = inf;
       memset(arc,0,sizeof arc);
       for(int i=0;i<n;i++)
       {
           for(int j = 0;j<n;j++)
           {
               if(i!=j)
                   cin>>arc[i][j];
               else
                   arc[i][j] = inf;
           }
       }
       int total = (1<<(n-1));
       d[0][0] = 0;
       for(int i = 1;i<n;i++)
           d[i][0] = arc[i][0];
       d[0][total-1] = inf;
       for(int j = 1;j<(total-1);j++){
           for(int i= 1;i<n;i++){
               if((j&(1<<(i-1)))==0)
               {
                   int x,y = inf;
                   for(int k = 1;k<n;k++){
                       if((j&(1<<(k-1)))>0)
                       {
                           x = d[k][(j-(1<<(k-1)))]+arc[i][k];
                           y = min(y,x);
                       }
                   }
                   d[i][j] = y;
               }
           }
       }
       d[0][total-1] = inf;
       for(int i=  1;i<n;i++)
           d[0][total-1]= min(d[0][total-1],arc[0][i]+d[i][(total-1)-(1<<(i-1))]);
       cout<<d[0][total-1]<<endl;}
    return 0;
}

