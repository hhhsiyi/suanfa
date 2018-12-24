#include <iostream>

using namespace std;
int d[5][5]={{8,0,0,0,0},{12,15,0,0,0},{3,9,6,0,0},{8,10,5,12,0},{16,4,18,10,9}};

int main()
{
    int path[5][5] = {0};
    int maxAdd[5][5]={0};
    for(int i= 0;i<5;i++){
        for(int j = 0;j<5;j++)
            cout<<d[i][j]<<" ";
        cout<<endl;}
    //    for(int i= 0;i<5;i++)
    //        for(int j = 0;j<5;j++)
    //            maxAdd[i][j]=d[i][j];
    for(int i = 0;i<5;i++){
        maxAdd[4][i] = d[4][i];
        cout<<" "<<maxAdd[4][i]<<" ";}
//    for(int i = 0;i<5;i++)
//        maxAdd[4][i]=0;
    for(int i= 0;i<5;i++){
        for(int j = 0;j<5;j++)
            cout<<maxAdd[i][j]<<" ";
        cout << endl;}
    for(int i = 3;i>=0;i--){
        for(int j = 0;j<4;j++)
            cout<<maxAdd[i][j]<<" ";
        cout<<endl;}
    cout<<endl;
    for(int i = 0;i<5;i++)
    cout<<maxAdd[4][i]<<endl;
    for(int i = 3;i>=0;i--){
        for(int j = 0;j<=i;j++)
        {
            if(maxAdd[i+1][j]>maxAdd[i+1][j+1])
            {
                maxAdd[i][j]=d[i][j]+maxAdd[i+1][j];
                path[i][j] = j;
            }
            else
            {
                maxAdd[i][j]=d[i][j]+maxAdd[i+1][j+1];
                path[i][j] = j+1;
            }
        }
    }
    cout<<"\nÂ·¾¶"<<d[0][0];
    int j = path[0][0];
    for(int i= 1;i<5;i++)
    {
        cout<<d[i][j]<<" ";
        j = path[i][j];
    }
    cout<<"\n"<<maxAdd[0][0]<<endl;
    return 0;
}

