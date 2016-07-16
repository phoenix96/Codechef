#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,red,blue,green,m;
    char c;
    cin>>t;
    while(t--)
    {
        cin>>n;
        blue=red=green=0;
        for(int i=0; i<n; i++)
        {
            cin>>c;
            if(c=='B')
                blue++;
            if(c=='G')
                green++;
            if(c=='R')
                red++;
        }
        m=((blue>red)?(blue>green?(blue):(green)):(red>green?(red):(green)));
        cout<<n-m<<endl;
    }
    return 0;
}
