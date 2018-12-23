#include <iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const double MAX = 1e10;
struct point{
    int  x;
    int  y;

};
bool f(point a,point b)
{
    return a.y<b.y;
}
bool f1(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x<b.x;
    //return a.y<b.y;
}
double dd(point a,point b)
{
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}
point px[100005],py[100005];
point p[100005],s[100005];
double closest(point s[] ,int l,int r)
{
    double d1,d2,d3,d=MAX;
    int mid ,index=0;
    if(l==r)
        return MAX;
    if(r-l==1)
        return dd(s[l],s[r]);
  //  double d = min(getmin(l,mid),getmin(mid+1,r));
    mid=(l+r)/2;
    d1 = closest(s,l,mid);
    d2 = closest(s,mid+1,r);
    if(d1<d2)
        d=d1;
    else
        d=d2;
    index=0;
    for(int i=l;i<=r;i++)
        if(fabs(s[i].x-s[mid].x)<d)
            p[index++]=s[i];
    sort(p,p+index,f);

//    for(int i=mid;i>=l&&px[mid].x-px[i].x<d;i--)
//        py[index++]=px[i];
//    for(int i=mid+1;i<=r&&px[i].x-px[mid].x<d;i++)
//        py[index++]=px[i];

//    sort(py,py+index,compare_y);

    for(int i=0;i<index;i++)
        for(int j=i+1;j<index;j++)
            if(p[j].y-p[i].y>=d)
                break;
            else
            {
                d3=dd(p[i],p[j]);
                if(d3<d)
                    d=d3;
            }
            //d = min(d,dd(py[i],py[j]));
    return d;
}
//void QuickSort(point p[],int l,int r)
//{
//    int pivot;
//    if(l<r)
//    {
//        pivot=getmin(l,r);
//        QuickSort(p,l,pivot-1);
//        QuickSort(p,pivot+1,r);
//    }
//}

int main()
{
    //ios::sync_with_stdio(false);
    int c;
    cin>>c;
    while(c--)
    {int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>px[i].x>>px[i].y;
        sort(px,px+n,f1);

        //QuickSort(px);
        cout<<fixed<<setprecision(2)<<closest(px,0,n-1)<<endl;
    //cout << "Hello World!" << endl;
    //return 0;
    }
}
