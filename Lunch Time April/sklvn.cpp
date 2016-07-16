#include<bits/stdc++.h>
using namespace std;
long long a[100001];
long long sum[100001];
long long ans[1000001];
int main()
{
    long long t,n,prev,prev_count,next,k,next_count;
    long long start=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
         sort(a,a+n,std::greater<int>());
        //sort(a,a+n);
        sum[0]=a[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        prev=1;
        prev_count=1;
        next=n;
        next_count=n;
        for(int i=0;i<=((n*(n+1))/2);i++)
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
                ans[i]=sum[next-1]-sum[prev-2];
            else
                ans[i]=sum[next-1];
            if(prev==1)
           {
                next=n;
           }
           else
           {
               next--;
           }
        }
        sort(ans,ans+((n*(n+1))/2),std::greater<int>());
        for(int i=0;i<k;i++)
            cout<<ans[i]<<" ";

    return 0;
}
