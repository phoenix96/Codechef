#include<bits/stdc++.h>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);
    int t,n,k;
    int co=0;
    int a[100001];
    cin>>t;
    while(t--)
    {   co=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>k;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]*a[j]==k)
                    co++;
            }
        }
        cout<<co<<endl;
    }
    return 0;
}
