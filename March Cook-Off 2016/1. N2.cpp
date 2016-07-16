#include<bits/stdc++.h>
using namespace std;
long long int a[100001];
int main()
{   ios_base::sync_with_stdio(false);
    long long t,n,ans;
    long long rj;
    long long prev;
    cin>>t;
    while(t--)
    {   rj=1;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            rj=1; prev=i;
            for(int j=i+1;j<n;j++)
            {
                if(a[j]*a[prev]<0)
                {
                    rj++;
                }
                else
                {
                    break;
                }
                prev=j;
            }
            cout<<rj<<" ";
        }
        cout<<endl;
    }
    return 0;
}
