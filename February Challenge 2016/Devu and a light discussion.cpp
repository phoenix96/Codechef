#include<iostream>
using namespace std;
int main()
{
    long long t,n,v,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n>=1&&n<=6)
        {   cout<<"-1\n";
            continue;
        }
        else if(n==7)
        {
            cout<<n<<"\n";
            cout<<"1 2\n";
            cout<<"2 3\n";
            cout<<"3 4\n";
            cout<<"4 5\n";
            cout<<"2 6\n";
            cout<<"4 6\n";
            cout<<"6 7\n";
            cout<<"3\n";
        }
        else if(n%3==1)
        {
            cout<<n<<"\n";
            cout<<"1 2\n";
            cout<<"2 3\n";
            cout<<"3 4\n";
            cout<<"4 5\n";
            cout<<"2 6\n";
            cout<<"4 6\n";
            cout<<"6 7\n";
            int l=1,r=5,d=7;
            for(int i=8;i<=n;i++)
            {
                if(i%3==0)
                {
                    cout<<i<<" "<<l<<"\n";
                    l=i;
                }
                else if(i%3==1)
                {
                    cout<<i<<" "<<r<<"\n";
                    r=i;
                }
                else
                {
                    cout<<i<<" "<<d<<"\n";
                    d=i;
                }

            }
            cout<<"3\n";
        }
        else if(n%3==2)
        {n--;
            cout<<n+2<<"\n";
            cout<<"1 2\n";
            cout<<"2 3\n";
            cout<<"3 4\n";
            cout<<"4 5\n";
            cout<<"2 6\n";
            cout<<"4 6\n";
            cout<<"6 7\n";
            int l=1,r=5,d=7;
            for(int i=8;i<=n;i++)
            {
                if(i%3==0)
                {
                    cout<<i<<" "<<l<<"\n";
                    l=i;
                }
                else if(i%3==1)
                {
                    cout<<i<<" "<<r<<"\n";
                    r=i;
                }
                else
                {
                    cout<<i<<" "<<d<<"\n";
                    d=i;
                }

            }
            cout<<"3 "<<n+1<<"\n";
            cout<<n+1<<" 6"<<"\n";
            cout<<"3\n";
        }
        else if(n%3==0)
        {
            n-=2;
            cout<<n+3<<"\n";
            cout<<"1 2\n";
            cout<<"2 3\n";
            cout<<"3 4\n";
            cout<<"4 5\n";
            cout<<"2 6\n";
            cout<<"4 6\n";
            cout<<"6 7\n";
            int l=1,r=5,d=7;
            for(int i=8;i<=n;i++)
            {
                if(i%3==0)
                {
                    cout<<i<<" "<<l<<"\n";
                    l=i;
                }
                else if(i%3==1)
                {
                    cout<<i<<" "<<r<<"\n";
                    r=i;
                }
                else
                {
                    cout<<i<<" "<<d<<"\n";
                    d=i;
                }

            }
            cout<<"3 "<<n+1<<"\n";
            cout<<n+1<<" "<<n+2<<"\n";
            cout<<n+2<<" 6"<<"\n";
            cout<<"3\n";
        }
    }
    return 0;
}
