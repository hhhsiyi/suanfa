#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
#define maxn 105

int a[maxn][maxn];
int dp[maxn][maxn];
int n;
int main()
{
	int i,j;
	int M;
	cin>>M;
	while(M--)
	{
		
		cin>>n;
		for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			cin>>a[i][j];
	
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)  //填数塔最底层
		dp[n-1][i]=a[n-1][i];
	for(i=n-2;i>=0;i--)  { //更新除数塔最底层外的各个点的路径最大和 
		for(j=0;j<=i;j++){
			dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
			
		//	cout<<(max(dp[i+1][j],dp[i+1][j+1])+a[i][j])<<" ";
}
//cout<<endl;
}
	cout<<dp[0][0]<<endl;
	}

	return 0;
}
