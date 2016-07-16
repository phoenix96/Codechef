#include<bits/stdc++.h>
using namespace std;
long long int p[1001];
void seive()
{
    for(int i=2; i<1001; i++)
    {
        if(p[i]==0)
        {
            for(int j=i*2; j<1001; j+=i)
            {
                p[j]=1;
            }
        }
    }
}
int main()
{
    long long int t,n,d,d2,flag;
    long double ans1; long long int ans2,ans3;
    char s[1000]; long long int o=0; long long int c=0;
    seive();
    cin>>t;
    while(t--)
    { o=0;
        flag=0;
        cin>>n;
        cin>>d;
        while(d2%2==0)
            d2/=2;
        while(d2%5==0)
            d2/=5;
        for(int i=3;i<d2;i++)
        {
            if((p[i]==0)&&(d2%i==0))
            {   cout<<i<<" "<<p[i]<<endl;
                flag=1;
                break;
            }
        }
        cout<<"here"<<endl;
        cout<<flag<<endl;

        if(flag==0)
        {
            ans1=(n*1.0)/(d*1.0);
            cout<<ans1<<"\n";
        }
        else
        {
            ans3=n/d;
            n=n%d;
            flag=0;
            while(1)
            {
                n=n*10;
                s[o]= (char)(n/d);
                cout<<"s:"<<s[o]<<" ";
                o++;
                c++;
                    for(int i=0;i<o-1;i++)
                    {
                        if(s[i]==s[o-1])
                            {
                                break;
                                flag=1;
                            }
                    }
                    if(flag==1) break;

                n/=d;
            }
            cout<<fixed;
            cout<<ans3<<".(";
            cout<<setprecision(c)<<((n%d)/d)<<")"<<"\n";

        }

    }
     return 0;
}
