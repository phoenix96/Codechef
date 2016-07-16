#include<bits/stdc++.h>s
using namespace std;
long long int *p;
void seive()
{
    p=new long long int[10000001];
    int n=10000001;
    int i=0;
    while(i<n)
    {
        p[i]=1;
        i++;
    }
    i=0;
    for(i=2; i<n; i++)
    {
        if(p[i])
        {
            for(int j=2; j*i<n; j++)
                p[i*j]=0;
        }
    }
}
int main()
{seive();
return 0;
}
