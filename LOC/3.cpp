#include<bits/stdc++.h>
using namespace std;
int main()
{
    long double PI=3.141592653589793238462643383279502884197;
    long long int t;
    long double r1,h1,r2,h2,t1,t2,t3;
    cin>>t;
    while(t--)
    {
        cin>>r1>>h1>>r2>>h2;
        cout<<fixed;
        t1=(4.0/3.0)*PI*r1*r1*r1/2.0;
        t2= (1.0/3.0)*PI*r1*r1*h1;
        t3= PI*r2*r2*h2;
        cout<<setprecision(15)<<(t1+t2)<<" "<<t3<<endl;
    }
    return 0;
}
