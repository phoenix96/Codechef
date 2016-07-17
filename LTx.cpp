#include<bits/stdc++.h>
using namespace std;
char a[100][100];
int main()
{
    long long int t,n,k,x=0,dx=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='O')
                  {
                    x=0;
                    dx=0;
                  }
                  else if (a[i][j]=='.')
                    dx++;
                  else
                    x++;



            }
        }
    }
}
