#include<iostream>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);
    long long int a[100000];
    long long int t,n,s=0,c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];
        c=1;
        s=0;
        a[n]=-1;
        for(int i=0; i<n; i++)
        {
            if(a[i]<=a[i+1])
                {c++;
                continue;
                }
            else
            {
                s+=(c*(c-1))/2;
                c=1;
            }
 
        }
        s+=n;
        cout<<s<<"\n";
    }
    return 0;
 
}