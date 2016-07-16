#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,prev,next;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0) {
                cout<<"0\n";
                continue;
        }
        for(int i=1;i<=100000;i++)
        {   prev=((i-1)*i)/2;
            next=(i*(i+1))/2;
            if(n>prev&&n<next)
            {
                cout<<i-1<<endl;
                break;
            }
            else if(n==next)
            {
                cout<<i<<endl;
                break;
            }
        }
    }

    return 0;
}
