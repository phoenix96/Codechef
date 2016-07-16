#include<bits/stdc++.h>
using namespace std;
long long answer[100001];
int main()
{
    long long t,n,ans;
    cin>>t;
    long long rj;
    long long int a[100001];
    while(t--)
    {   rj=1;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        answer[0]=1;
        int max_so_far = 1, max_ending_here = 0;
        int ans=1;
        for (int i = n - 2 ; i >= 0 ; i-- )
        {
            if(a[i]>0)
            {
                if(a[i+1]<0)
                    max_so_far++;
                else
                {
                    if(max_so_far>ans)
                        ans=max_so_far;
                    max_so_far=1;
                }
            }
            else
            {
                if(a[i+1]>0)
                    max_so_far++;
                else
                {
                    if(max_so_far>ans)
                        ans=max_so_far;
                    max_so_far=1;
                }
            }
            answer[rj]=max_so_far;
            rj++;
        }
        for(int i=n-1; i>=0; i--)
        {
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
