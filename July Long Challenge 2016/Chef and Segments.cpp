#include<bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> freq;
int main()
{
    int t,n,temp,l,s,e,v,i,j;
    long long sol,psol,ans;
    freq.resize(1001);
    scanf("%d",&t);
    while(t--)
    {
        sol=0;
        psol=0,ans=0;
        scanf("%d",&n);
        a.resize(n);
        b.resize(n);
        for( i=0; i<n; i++)
            scanf("%d",&a[i]);

        for( i=0; i<n; i++)
        {
            if(a[i]!=-1)
            {
                temp = a[i];
                for(j=0; j<n; j++)
                {
                    if(a[j]==temp)
                    {
                        b[j]=i+1;
                        a[j]=-1;
                    }
                }
            }
        }
        for(s =0; s<n; s++)
        {
            psol=-1;
            if(s%2==0)
            {
                for(e=s; e<n; e++)
                {
                    l=0;
                    sol=0;
                    freq[b[e]]++;
                    if(freq[b[e]]==1)
                    {
                        for(v=e+1; v<n; v++)
                        {
                            if(freq[b[v]]==0)
                                l++;
                            else
                            {
                                sol+=(l*(l+1))/2;
                                l=0;
                            }
                        }
                        sol+=(l*(l+1))/2;
                        psol=sol;
                        ans+=sol;
                    }
                    else
                    {
                        ans+=psol;
                    }
                }
            }
            else
            {
                for(e = n-2; e>=s; e--)
                {
                    sol=0;
                    psol=-1;
                    l=0;
                    freq[b[e+1]]--;
                    if(freq[b[e+1]]!=0)
                    {
                    for(v=e+1; v<n; v++)
                        {
                            if(freq[b[v]]==0)
                            l++;
                            else
                            {
                                sol+=(l*(l+1))/2;
                                l=0;
                            }
                        }
                        sol+=(l*(l+1))/2;
                        psol=sol;
                        ans+=sol;
                    }
                    else
                    {
                        ans+=psol;
                    }
                }

            }
            freq[b[s]]--;
        }
        printf("%lld\n",ans);
    }
}
