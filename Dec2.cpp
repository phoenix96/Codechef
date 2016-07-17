#include<bits/stdc++.h>
using namespace std;
long long int fast_pow(long long int base, long long int n,long long int M)
    {
        if(n==0)
           return 1;
        if(n==1)
        return base;
        long long int halfn = fast_pow(base,n/2,M);
        if(n%2==0)
            return ( halfn * halfn ) % M;
        else
            return ( ( ( halfn * halfn ) % M ) * base ) % M;
    }
int main()
{
long long int mul=1;
long long int M=999998999999;
long long int y=696969;
long long int g=21309;
    for(long long int i=0;i<100000000000000;i++)
    {   mul=(mul*g)%M;
        if(mul==y)
        cout<<mul<<endl;
//        if(i==100000000000) cout<<"Phase 2"<<endl;
//        if(i==10000000000) cout<<"Phase 1"<<endl;}
//    cout<<"1.349919908";
    }
return 0;
}
