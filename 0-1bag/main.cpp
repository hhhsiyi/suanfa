#include <iostream>
#include<cmath>
using namespace std;
int n=4;
int w[] = {7,3,4,5};
int v[] = {42,12,40,25};
int maxValue = 0;
int maxWeight = 10;
int max = pow(2,n);
//struct good
//{
//    int weight,value,flag;
//}goods[100];
//int main()
//{
//    int Value = 0;
//    int Weight = 0;
//    for(int i=0;i<n;i++){
//        goods[i].flag=0;
//        goods[i].value = v[i];
//        goods[i].weight = w[i];
//    }
//    for(int i=0;i<n;i++)
//    {
//        if(Value+goods[i].value>Value&&Weight+goods[i].weight<=Weight)
//        {
//            Value+=goods[i].value;
//            goods[i].flag = 1;
//        }
//    }
int main(){
    int  value;
    int weight; value = weight = 0;
    for(int i= 0;i<n;i++)
    {
        cout<<w[i]<<" ";
        for(int j = i ;j<n;j++)
        {
            if((weight+w[j])<= maxWeight)
            {
                weight += w[j];
                value += v[j];
            }
            if(maxValue<value)
            {
                maxValue = value;
            }
        }
    }

    cout <<value<<" "<<weight<< endl;
    return 0;
}

