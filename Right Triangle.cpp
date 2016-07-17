#include<bits/stdc++.h>
#define ll long long
using namespace std;
int py(double a, double b, double c)
{
    if(a*a+b*b==c*c||a*a+c*c==b*b||c*a+c*b==a*a)
        return 1;
    return 0;
}
int main()
{
    ll t;
    double hy,b,hei,a;
    cin>>t;
    while(t--){
        cin>>hy>>a;
        b=2.0*a*1.0/hei;
        hei=hy*hy-b*b;
    }
}
