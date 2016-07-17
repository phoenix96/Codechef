#include<bits/stdc++.h>
using namespace std;
long long in[500000];
long long c[5000000];
int main()
{   int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%lld",&in[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=j+1;k<j;k++)
            {
                if(in[j]==in[k])
                    c[j]++;
            }
        }
    }

    return 0;

}

