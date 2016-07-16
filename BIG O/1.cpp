#include<bits/stdc++.h>
using namespace std;
int enc[1008];
int main()
{
    long long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n=n%1007;
        if(enc[n]==0)
            {
                cout<<n<<endl;
                enc[n]=1;
            }
    }
    return 0;
}
