#include<bits/stdc++.h>
#define ll long long
using namespace std;
int d[11];
int isSpecial(int n)
{
    int number=n;
    int di;
    int ans=0;
    while(n>0)
    {
        di=n%10;
        d[di]=1;
        n/=10;
    }
    for(int i=1;i<10;i++)
        {
            if(d[i])
            {
                if(number%i==0)
                {
                    ans++;
                }
                d[i]=0;
            }
        }
    return ans;
}
ll sol[10];
int main()
{
    ll q,l,r,k,ans;
    cin>>q;
    while(q--)
    {   ans=0;
        for(int i=0;i<10;i++)
            sol[i]=0;
        cin>>l>>r;
        for(int i=l;i<=r;i++)
        {
            sol[isSpecial(i)]++;
        }
         for(int i=0;i<10;i++)
            cout<<sol[i]<<" ";
        cout<<endl;
    }
}
