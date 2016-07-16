#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    while(a)
    {
        int temp;
        temp=a;
        a=b%a;
        b=temp;
    }
    return b;
}

int main()
{
    int t, i, j, k, l, n, m, ans, sum, add, index, sumtwo, arr;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n], two[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        ans=a[0];
        for(i=1;i<n;i++)
            ans=gcd(ans,a[i]);
        if(ans==1)
        {
            if(a[n-1]%2==0)
                arr=a[n-1]/2-1;
            else
                arr=a[n-1]/2;
            int b[arr][n];
            sumtwo=0;
            for(i=0;i<n;i++)
            {
                two[i]=a[i]%2;
                sumtwo=sumtwo+two[i];
            }
            for(i=0;i<arr;i++)
            {
                sum=0;
                l=2*i+3;
                for(j=0;j<n;j++)
                {
                    b[i][j]=a[j]%l;
                    if(b[i][j]==0)
                        add=0;
                    else
                        add=l-b[i][j];
                    sum=sum+add;

                }
                if(sum<sumtwo)
                {
                    sumtwo=sum;
                    index=l;
                }
            }
            cout<<sumtwo<<endl;
        }
        else
            cout<<"0"<<endl;
    }
}

