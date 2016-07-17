#include<bits/stdc++.h>
using namespace std;
vector <long long> b;
int nesting_depth()
{
    vector <long long> :: iterator it;
    it=b.begin();
    long long one =0, onemax=0,index=0;
    while(it!=b.end())
    {
        if(*it==1)
        {
          one++;
        }
        else
        {
            if(one>onemax)
            {
                onemax=one;
                index=it-b.begin();
            }
            one--;
        }
        it++;
    }
    cout<< onemax <<" " << index <<" ";
}
int seq()
{
    vector <long long>:: iterator it;
    vector <long long> one;
    it=b.begin();
    long long k=0,maxseq=0,start=0;
    while(it!=b.end())
    {//cout<<*it;
        if(*it==1)
        {
          one.push_back(it-b.begin());
        }
        else
        {//   cout<<" else"<< it-b.begin()<<" "<<one[one.size()-1];
            if(((it-b.begin())-(one[one.size()-1]))>maxseq)
            {//   cout<<" true";
                maxseq=(it-b.begin()-one[one.size()-1]);
                start=one[one.size()-1];
            }
            one.erase(one.end()-1);
        }
        it++;
        //cout<<endl;
    }
    cout<<maxseq+1<<" "<<start+1<<endl;
    return 0;
}
int main()
{
    long long t,in;
    cin>>t;
    while(t--)
    {
        cin>>in;
        b.push_back(in);
    }
    nesting_depth();
    seq();
    return 0;
}
