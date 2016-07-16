#include<bits/stdc++.h>
#define ll long long
using namespace std;
/* Formulae are taken from:
http://mathworld.wolfram.com/PolyhedronColoring.html

Formulae from OEIS

Inverse Modulo from
https://codeaccepted.wordpress.com/2014/02/15/output-the-answer-modulo-109-7/
*/
int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
        return 1;
    if(n==1)
        return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}
int main()
{
    ll n,c,in,f,sol,mul,M=1000000000+7;
    cin>>n>>c;
    for(int i=0; i<n; i++)
    {
        cin>>f;
        for(int j=0; j<f; j++)
        {
            cin>>in;
        }
    }
    if(n==6)
    {
        n=c;
        sol = (((fast_pow(n,6,M) + (3*fast_pow(n,4,M))%M )%M+ (12*fast_pow(n,3,M))%M )%M + (8*fast_pow(n,2,M))%M)%M;
        mul = findMMI_fermat(24,M);
        sol = (sol * mul) % M;
    }
    else if(n==12)
    {
        n=c;
        //n^2*(n^2+1)*(n^8-n^6+16*n^4+44)/120.
        sol = (((fast_pow(n,2,M)*(fast_pow(n,2,M)+1)%M)%M)*(((fast_pow(n,8,M)-fast_pow(n,6,M))%M+(16*fast_pow(n,4,M))%M)%M+44)%M)%M;
        mul = findMMI_fermat(120,M);
        sol = (sol * mul) % M;
    }
    else if(n==20)
    {   // THIS IS WRONG
        n=c;
        //a(n) = n^2*(n^18+15*n^10+16*n^8+20*n^6+44*n^2+24)/120.

        sol = (fast_pow(n,2,M)*(((((fast_pow(n,18,M)+(15*fast_pow(n,10,M))%M )%M+ (16*fast_pow(n,8,M))%M )%M+ (20*fast_pow(n,6,M))%M )%M+ (44*fast_pow(n,2,M))%M)%M + 24)%M)%M;
        mul = findMMI_fermat(120,M);
        sol = (sol * mul) % M;
    }
    else if(n==8)
    {   //THIS TOO IS WRONG
        n=c;
//      a(n) = n*(n+1)*(n^2+n+2)*(n^2+n+4)/48.  or a(n) = (1/48)*(20*n^2 + 21*n^4 + 6*n^6 + n^8).

        sol = ((((20*fast_pow(n,2,M)%M)+(21*fast_pow(n,4,M)%M))%M+(6*fast_pow(n,6,M)%M))%M+fast_pow(n,8,M))%M;
        mul = findMMI_fermat(48,M);
        sol = (sol * mul) % M;
    }
    else if(n==4)
    {
        n=c;
        n+=3;
        n=n%M;
        //a(n) = n*(n-1)*(n-2)*(n-3)/24. a(n+3) is solution
        sol = (((n*(n-1)%M)*(n-2))%M*(n-3))%M;
        mul = findMMI_fermat(24,M);
        sol = (sol * mul) % M;
    }
    cout<<sol<<endl;
}
