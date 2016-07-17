#include<iostream>
#include<algorithm>
#define fast ios_base::sync_with_stdio(false);
using namespace std;
int main()
{   int a[100000];
    fast
    int t,n,k,len=0;
    cin>>t;
    while(t--)
    {len=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        len=n;
        for(int i=0;i<n-1;i++)
        {
            if(a[i+1]-a[i]>k)
                len--;
        }
        cout<<len<<"\n";
    }
    return 0;
}