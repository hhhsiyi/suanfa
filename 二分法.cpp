#include<iostream>
using namespace std;
int main()
{
	int n=7,k;
	int a[n]={1,2,3,4,5,6,7};
	int l=0,r=n-1,mid;
	cin>>k;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(k<a[mid])
		r=mid-1;
		else if(k>a[mid])
		l=mid+1;
		else 
		{
		
		cout<<mid<<endl;

break;	}}
	return 0;
	
	
	
}
