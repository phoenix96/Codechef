#include<bits/stdc++.h>
using namespace std;
int c[1000000];
int a[1000000];
int main()
{
        long long int t,n,required_sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            c[a[i]]++;
        }
        cin>>required_sum;
        for(int i=0;i<n;i++)
        {
            if(c[required_sum-a[i]]>0)
            {
                cout<<a[i]<<" "<<required_sum-a[i]<<endl;
                c[a[i]]--;
                c[required_sum-a[i]]--;

            }
        }
        return 0;
}
