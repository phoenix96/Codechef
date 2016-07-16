#include<bits/stdc++.h>
using namespace std;
int  main()
{
    long long int t,n,i,j,k,l,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        long long int a[n+1][m+1];
        long long int b[n+1][m+1];
        long long int c[n+1][m+1];
        long long int M=1000001;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%lld",&a[i][j]);
                b[i][j]=a[i][j];
                c[i][j]=a[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    a[i][a[i][j]%M]+=M;
                    b[b[i][j]%M][j]+=M;
                    c[i][c[i][j]%M]+=M;
                    c[c[i][j]%M][j]+=M;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }

    }
            return 0;

}
