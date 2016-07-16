#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main()
{
    long long int t,n,m,k,flag,sum;
    cin>>t;
    while(t--)
    {
        flag=0;
        sum=0;
        cin>>n>>k;
        for(int i=0; i<n; i++)
            cin>>a[i];
        m=a[0];
        for(int i=0; i<n; i++)
        {
            sum+=a[i];
            if(m>a[i])
            {
                m=a[i];
            }
        }
        if(sum%k>=m)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<(sum/k*1LL)<<endl;
        }
    }
    return 0;
}
