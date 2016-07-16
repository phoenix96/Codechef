#include<bits/stdc++.h>
using namespace std;
int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}
int main()
{
    cin.sync_with_stdio(0);
long long int t,n,f,ans;
cin>>t;
string in;
while(t--)
{   f=0;
    cin>>in;
    ans=0;
  // cout<<in;
    //cout<<endl;
    for(int i=0;i<in.length()/3;i++)
    {  // cout<<endl<<in.substr(0,i+1)<<countSubstring(in,in.substr(0,i+1))<<" "<<in.substr(in.length()-i-1,i+1)<<endl;
        if((in.substr(0,i+1)==in.substr(in.length()-i-1,i+1))&&countSubstring(in,in.substr(0,i+1))>=3)
        {
            ans=i+1;
            f=1;
        }

    }
     //if(f==0)  cout<<"1"<<endl;
     cout<<ans<<"\n";
}
return 0;
}
