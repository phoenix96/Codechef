#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q1,q2,q3,q4,n;
ll MIN = -100000000000000000;
vector <ll> a;
/* Implementation of Kadane Algorithm from geek4geeks */
ll foo()
{
    ll max_so_far = a[0];
    ll curr_max = a[0];

    for (ll i = 1; i < a.size(); i++)
    {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;
}
int main()
{
    ll t,c,in,c_m,m_f;
    cin>>t;
    while(t--)
    {   c=0;a.clear();
        cin>>n>>q1>>q2>>q3>>q4;
        m_f=MIN;
        c_m=MIN;
        for(ll i=0;i<n;i++)
            {
                cin>>in;
                if(in==q1||in==q2||in==q3||in==q4)
                    {   c++;
                        if(a.size()!=0)
                        {
                            c_m=foo();
                            m_f=max(c_m,m_f);
                        }
                        a.clear();
//                        for(int i=0;i<a.size();i++)
//                            cout<<a[i]<<" ";
//                        cout<<endl;
                    }
                    else
                    {
                        a.push_back(in);
                    }

            }
            if(a.size()!=0)
                        {
                            c_m=foo();
                            m_f=max(c_m,m_f);
                        }
            if(c==n) m_f=0;
            cout<<m_f<<endl;
    }
    return 0;
}
