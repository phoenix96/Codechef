#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long int v[101];
long long int edges[1000][1000];
#include <stdio.h>
#include <string.h>
void s(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
static long long int c;
void permute(char a[], int l, int r)
{
   int i;
   if (l == r)
     { c++;
        c=c%1000000007;
     }
   else
   {
       for (i = l; i <= r; i++)
       {
         if(i==l||(edges[l][i]==0))
         {s((a+l), (a+i));
          permute(a, l+1, r);
          s((a+l), (a+i));
         }
       }
   }
}

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
            if (n==1)
            {
                printf("1\n");
            }
            else if(n==2)
            {   c=0;
                permute("01",0,n-1);
                printf("%lld\n",c);

            }
            else if(n==3)
            {   c=0;
                permute("012",0,n-1);
                printf("%lld\n",c);

            }
            else if(n==4)
            {   c=0;
                permute("0123",0,n-1);
                printf("%lld\n",c);

            }
            else if(n==5)
            {   c=0;
                permute("01234",0,n-1);
                printf("%lld\n",c);

            }
            else if(n==6)
            {   c=0;
                permute("012345",0,n-1);
                printf("%lld\n",c);

            }
            else if(n==7)
            {   c=0;
                permute("0123456",0,n-1);
                printf("%lld\n",c);

            }
            else if(n==8)
            {   c=0;
                permute("01234567",0,n-1);
                printf("%lld\n",c);

            }
            else if(n==9)
            {   c=0;
                permute("012345678",0,n-1);
                printf("%lld\n",c);

            }
            else if(n==10)
            {   c=0;
                permute("0123456789",0,n-1);
                printf("%lld\n",c);

            }
            else
                printf("0\n");

    }
}
