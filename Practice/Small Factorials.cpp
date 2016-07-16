#include<stdio.h>
#include<iostream>
using namespace std;
int a[102][250];
void compute()
{
    for(int i=0; i<102; i++)
    {
        for(int j=0; j<250; j++)
        {
            a[i][j]=-1;
        }
    }
 
 
 
    a[1][0]=1;
    int i,j;
    for(i=2; i<=100; i++)
    {
        int k=0,temp=0,carry=0;
        for(j=0; a[i-1][j]!=-1; j++)
        {
 
            a[i][j]=(a[i-1][j]*i+carry)%10;
            carry=(a[i-1][j]*i+carry)/10;
 
        }
        while(carry!=0)
        {
            a[i][j]=carry%10;
            carry=carry/10;
            j++;
        }
    }
 
//for(int i=1;i<16;i++)
//{
//    for(int j=0;j<25;j++)
//    {   if(a[i][j]!=-1)
//        cout<<a[i][j];
//    }
//    cout<<endl;
//}
 
 
}
int main()
{
    compute();
    long long int t,n,i,j,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=249;i>=0;i--)
        {
            if(a[n][i]!=-1)
                printf("%d",a[n][i]);
        }
        printf("\n");
 
    }
 
return 0;
}