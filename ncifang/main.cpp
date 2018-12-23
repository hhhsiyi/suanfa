#include <iostream>
#include<cmath>
using namespace std;
long long a,n,m;
long long func(long long a,long long n)
{
    if(n==1)
        return a%m;
    if(n%2==0)
    {
        long long k = func(a,n/2);
        return (k*k)%m;
    }
    else
    {
        long long k = func(a,(n-1)/2);
        return (((a*k)%m)*k)%m;
    }
}

int main()
{
    cin>>a>>n>>m;
    if(n==0)
        cout<<1<<endl;
    else
        cout<<func(a,n)<<endl;

    //cout << "Hello World!" << endl;
    return 0;
}

