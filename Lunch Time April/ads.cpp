#include<bits/stdc++.h>
using namespace std;
long long a[100001];
long long sum[100001];
int main()
{
    long long t,n,prev,prev_count,next,next_count;
    //cin>>t;
    t=1;
    while(t--)
    {   n=20;
        //cin>>n>>k;
//        for(int i=0;i<n;i++)
//        {
//            cin>>a[i];
//        }
        sum[0]=a[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        prev=1;
        prev_count=1;
        next=n;
        next_count=n;
        for(int i=0;i<20;i++)
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
           cout<<prev<<" ";
//           if(next == next_count)
//           {
//               next_count--;
//           }
//           else
//           {
//               next--;
//           }
//

        }

    }

    return 0;
}
