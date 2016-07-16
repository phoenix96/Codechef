#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long a[n],ans=0;
        for(int i=0;i<n;i++)
            a[i]=i;
        do
        {   long long flag=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]==i)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                    ans++;
        }while(next_permutation(a,a+n));
        cout<<ans<<endl;
    }
    return 0;
}
