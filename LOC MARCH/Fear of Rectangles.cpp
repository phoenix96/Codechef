#include<bits/stdc++.h>
using namespace std;
long long a[501][501];
long long ROW;
long long COL;

int min(int a, int b)
{
    return (a < b)? a: b;
}


int min(int a, int b, int c)
{
    return min(min(a, b), c);
}


int max(int a, int b)
{
    return (a > b)? a: b;
}

void diagonalOrder()
{
    for (int line=1; line<=(ROW + COL -1); line++)
    {
        int start_col =  max(0, line-ROW);
        int count = min(line, (COL-start_col), ROW);
        for (int j=0; j<count; j++)
            printf("%d ", a[min(ROW, line)-j-1][start_col+j]);
    }
}
int main()
{
    long long t,n,m,height,j,inc;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        inc=1;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        ROW=m;
        COL=n;
        diagonalOrder();
    }
    return 0;
}
