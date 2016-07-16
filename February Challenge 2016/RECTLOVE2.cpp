#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int r,c,t,k,p,q,in,i,j;
    long double num;
    scanf("%lld",&t);
    while(t--)
    {
        num=0.0;
        scanf("%lld %lld %lld",&r,&c,&k);
        long double den1=r*(r+1)*0.50;
        long double den2=(c*c+c)*0.50;
        while(k--)
        {
            scanf("%lld",&in);
            p=in%c;
            if(p==0) p=c;
            if(in%c==0)
                q=in/c;
            else
                q=in/c+1;
            i=q;
            j=p;
            num+=(((j-1)*(c+1-j)+(c-j)+1)*1.0)/(den1*1.0)*((((i-1)*(r+1-i)+(r-i)+1)*1.0)/(den2*1.0));
        }
            cout<<num<<"\n";
    }
    return 0;
}
