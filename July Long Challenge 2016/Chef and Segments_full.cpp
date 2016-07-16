#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1001];
bitset<1000000001> freq1;
int main()
{
    int t,tt,n,sol,left,linear_strike;
    scanf("%d",&tt);
    for(int t=0; t<tt; t++)
    {
        scanf("%d",&n);
        sol=0;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

        for(int si = 0; si <n; si ++)
        {
            for(int st = 0; st<n; st++)
            {
                freq.set(a[st],true);
                linear_strike=0;
                for(int v=st; v<si; v++)
                {
                    if(!freq.test(a[v]))
                        linear_strike++;
                    else
                    {
                        sol+=(linear_strike*(linear_strike+1))/2;
                        linear_strike=0;
                    }
                }
                sol+=(linear_strike*(linear_strike+1))/2;
            }
            freq.set(a[st],false);


        }
        cout<<sol<<endl;
    }
}
