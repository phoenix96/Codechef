#include<bits/stdc++.h>
using namespace std;
char s[100007];
int nesting_depth()
{
    char it;
    long long int i=0;
    long long one =0, onemax=0,index=0;
    while(s[i]!='\0')
    { it=s[i];
       // cout<<it<<": ";
        if(it=='(')
        {
          one++;
        }
        else if(it==')')
        {
            if(one>onemax)
            {
                onemax=one;
                index=i;
                //cout<<index<<endl;
            }
            one--;
        }
        i++;
    }
   // cout<< onemax <<" " << index <<" ";
   return index;
}
int main()
{
 gets(s);
 //cout<<s;
 vector<char> ans;
 vector<char>::iterator it;
 int l=nesting_depth();
 //cout<<l<<endl;
 l--;
 //return 0;
 while(s[l]!='(')
 {
    ans.push_back(s[l]);
    l--;
 }
 reverse(ans.begin(),ans.end());
 it=ans.begin();
 while(it!=ans.end())
 {
     cout<<*it;
     it++;
 }
 cout<<endl;
 return 0;
}
