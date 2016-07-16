#define fast ios_base::sync_with_stdio(false);
#include<iostream>
#include<stdio.h>
using namespace std;
int p[5000001];
int p1[5000001];
void seive()
{int n=5000001;
int i=0;
    while(i<n)
    {
        p[i]=1;
        i++;
    }
    i=0;
    for(i=2;i<n;i++)
    {
        if(p[i])
        {
            for(int j=2;j*i<n;j++)
                p[i*j]=0;
        }
    }
    /*for(int k=0;k<n;k++)
    {
        cout<<p[k]<<" ";
    }*/
    for(i=2;i<n;i++)
    {
        if(p[i]&&(i-1)%4==0)
        {
            for(int j=1;j*i<n;j++)
                p1[i*j]=1;
        }
    }
    //cout<<endl;
    /*for(int k=0;k<n;k++)
    {
        cout<<p1[k]<<" ";
    }*/
 
}
int main()
{   fast
    seive();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(p1[n]==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}