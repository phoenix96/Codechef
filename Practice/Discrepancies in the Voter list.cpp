#include<bits/stdc++.h>
#include<set>
using namespace std;
int main()
{
    multiset <long long> voters;
    multiset <long long> ans;
    long long t,t2,a,b,c,in;
    cin>>a>>b>>c;
    t=a+b+c;
    voters.clear();
    ans.clear();
    while(t--)
    {
        cin>>in;
        voters.insert(in);
    }
    multiset <long long> ::iterator it = voters.begin();
    while(!voters.empty())
    {
        if(voters.count(*it)>=2)
        {
            ans.insert(*it);
        }
        voters.erase(*it);
        it=voters.begin();
    }
    cout<<ans.size()<<endl;
    multiset<long long> ::iterator ansit = ans.begin();
    while(ansit!=ans.end())
    {
        cout<<*ansit<<endl;
        ansit++;
    }
    return 0;
}
