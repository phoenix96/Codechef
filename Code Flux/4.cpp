#include<bits/stdc++.h>
using namespace std;
int k[]={1,10,11,12,13,14,15,16,17,18,19,21,31,41,51,61,71,81,91,100};
int main()
{   unsigned long long int tt,n,a,b,c;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        if((n-3)%21==0)
        {
            cout<<"-1\n";
            continue;
        }
        a=n%21;
        b=n/21*100;
        if(a>=4) a--;
        c=b+k[a-1];
        cout<<c<<endl;
    }
    return 0;
}
