#include<bits/stdc++.h>
using namespace std;
long a[101];
int main()
{
    long long t,n,ans;
    cin>>t;
    while(t--)
    {   ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                        ans++;
                }
            }
        }
        for(int i=0;i<(n-1);i++)
        {
            if(a[i]>a[i+1])
                ans--;
        }
        if(ans==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO\n";
    }
    return 0;
}
