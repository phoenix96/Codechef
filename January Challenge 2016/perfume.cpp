#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    long long int t,i,n,k,ans,l,m,topmax,botmax,leftmax,rightmax;
    scanf("%lld",&t);
    char in;
    while(t--)
    {
        ans=0;

        scanf("%lld %lld",&n,&m);
        topmax=n+1;
        botmax=-1;
        leftmax=m+1;
        rightmax=-1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>in;
                if(in=='*')
                {
                    if(topmax>i)
                        topmax=i;
                    if(botmax<i)
                        botmax=i;
                    if(leftmax>j)
                        leftmax=j;
                    if(rightmax<j)
                        rightmax=j;

                }
            }
        }
//        cout<<"\n--------------";
//        cout<<topmax<<endl;
//        cout<<botmax<<endl;
//        cout<<leftmax<<endl;
//        cout<<rightmax<<endl;
//        cout<<"\n--------------";
        l=rightmax-leftmax;
        k=botmax-topmax;
        if(l%2!=0) l++;
        if(k%2!=0) k++;
        if(botmax==-1) ans=0;
        else if(l>k)
            ans=l/2+1;
        else
            ans=k/2+1;
        printf("%lld\n",ans);
    }
    return 0;
}

