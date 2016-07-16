#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,n,red,p,total;
    string s,q;
    cin>>t;
    while(t--)
    {   total=0;
        cin>>n>>s;
        if(s=="INDIAN")
            red=200;
        else
            red=400;
        while(n--)
        {
            cin>>q;
            if(q=="CONTEST_WON")
            {
                cin>>p;
                total+=300;
                if(p<=20)
                {
                    total+=20-p;
                }
            }
            else if(q=="TOP_CONTRIBUTOR")
            {
                total+=300;
            }
            else if(q=="BUG_FOUND")
            {
                cin>>p;
                total+=p;
            }
            else if(q=="CONTEST_HOSTED")
            {
                total+=50;
            }
        }
        //cout<<total<<endl;
        cout<<total/red<<endl;
    }
}
