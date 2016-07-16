#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long int v[101];
long long int edges[1000][1000];
int main()
{
    long long int t,n,m,i,j,k,l,e,a,b,c,d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        memset(edges, 0, sizeof(edges[0][0]*n*n));
        for(i=0; i<m; i++)
        {   scanf("%lld %lld",&a,&b);
            a--;
            b--;
            edges[a][b]=1;
            edges[b][a]=1;
            edges[i][i]=1;
        }
//        for(i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout<<edges[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
        for(i=0;i<n;i++)
            v[i]=i;
            long long int f=0;
        do
        {   k=0;
            for(i=0;i<n-1;i++)
            {  //cout<<v[i];
                if(edges[v[i]][v[i+1]]==1)
                {   k=1;
                    break;
                    //cout<<endl;
                }
            }
            if(k==0) f++;
            f=f%1000000007;
            //cout<<v[i]<<endl;
        }
        while ( std::next_permutation(v,v+n) );
                printf("%lld\n",f);

    }
}
