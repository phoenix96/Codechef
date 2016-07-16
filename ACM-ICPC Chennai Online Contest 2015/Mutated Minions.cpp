//Rishabh Jain
#include<iostream>
#include<stdio.h>
using namespace std;
int a[101];
int main()
{
    int c;int n,k;int t;
    scanf("%d",&t);
    //t=100;
    while(t--)
    {
        scanf("%d %d",&n,&k);
      //  n=100;k=100;
        c=0;
        k=k%7;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if((a[i]+k)%7==0)
                c++;
        }
       printf("%d\n",c);
    }
    return 0;
}
