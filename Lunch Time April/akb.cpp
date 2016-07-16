#include<bits/stdc++.h>
using namespace std;
long long a[100001];
long long sum[100001];
int main()
{
    long long t,n,prev,prev_count,next,k,next_count;
    cin>>t;
    //t=1;
    while(t--)
    {   //n=20;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sum[0]=a[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        prev=1;
        prev_count=1;
        next=n;
        next_count=n;
        for(int i=0;i<k;i++)
        {
           if(prev == 1)
           {
               prev=prev_count;
               prev_count++;
           }
           else
           {
               prev--;
           }





            if((prev-2)>=0)
           cout<<sum[next-1]-sum[prev-2]<<" ";
            else
                cout<<sum[next-1]<<" ";






           if(prev==1)
           {
               next=n;
           }
           else
           {
               next--;
           }


        }
        cout<<endl;

    }

    return 0;
}
