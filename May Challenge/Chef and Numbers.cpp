#include<bits/stdc++.h>
#define MOD 1000000007
#include <ctime>

//void f() {
//  using namespace std;
//
//
//  code_to_time();
//
//
//
//}
double el,el2;
using namespace std;
long long a[10];
long long buff[200];
//set<long long> s;
long long amazing(long long k)
{   int i=0;
    int k2=k;
  //  clock_t begin = clock();
    while(k>0)
    {
        a[i]=k%10;
        k/=10;
        i++;
    }
    //clock_t end = clock();
    //el += double(end - begin) / CLOCKS_PER_SEC;
    //s.clear();
    //begin = clock();
    int ans=0;
    for(int ii=i-1; ii>=0; ii--)
    {
        int val=0;
        for(int j=ii; j>=0; j--)
        {
            val^=a[j];
            if(buff[val]!=k2)
            {
                ans+=val%MOD;
                ans%=MOD;
            }
            buff[val]=k2;
//            int si = s.size();
//            s.insert(val);
//            if(si!=s.size())
//            {
//                ans+=val%MOD;
//                ans%=MOD;
//            }
        }
    }
  //  end = clock();
    //el2 += double(end - begin) / CLOCKS_PER_SEC;
    return ans;
}
long long arr[1000001];
int no[8];
int main()
{   ios_base::sync_with_stdio(false);
    long long soa = 1000001;
    for(long long i=1; i<soa; i++)
    {

        arr[i]=(arr[i-1]+amazing(i)%MOD)%MOD;
    }
    long long t,n,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl;
    }
    return 0;

}
