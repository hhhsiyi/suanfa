#include <iostream>
#define inf 9999
using namespace std;
int n;
int maps[20][20];
int dis[20][1<<16];
int main()
{
    int a;
    while(cin>>n)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == j)
                {
                    maps[i][i] = inf;
                    continue;
                }
                int a;
                cin>>a;
                maps[i][j] = a;
            }

        }
        for(int i= 0;i<n;i++)
            for(int s = 0;s<(1<<n);s++)
                dis[i][s] = inf;
        for(int s = 0;s<(1<<n-1);s++)
        {
            for(int i=0;i<n;i++)
            {
                if(s==0)
                    dis[i][s]=maps[i][0];
                for(int j=1;j<n;j++)
                    if(s&(1<<(j-1)))
                        dis[i][s]=min(dis[i][s],dis[j][s^(1<<(j-1))]+maps[i][j]);
            }
        }
        cout<<dis[0][(1<<n-1)-1]<<endl;
    }
   // cout << "Hello World!" << endl;
    return 0;
}

