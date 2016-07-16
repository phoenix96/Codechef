#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
long long int visited[101];
long long int edges[100][100];
int main()
{
    long long int t,n,m,i,j,k,l,v,e,a,b,c,d;
    scanf("%lld",&t);
    while(t--)
    {   memset(edges, 0, sizeof(edges[0][0]* 100 * 100);
        scanf("%lld %lld",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%lld %lld",a,b);
            edges[a-1][b-1]=1;
            edges[b-1][a-1]=1;
            edges[i][i]=1;
        }
        for(int i=0;i<n;i++)
        {
            visited[i]=1;
            for(int j=0;j<n&&j!=i;j++,j=0)
            {
                if((visited[j]==0)&&(edges[i][j]==0))
                {
                    visited[j]=1;
                }

            }
        }
    }
}
