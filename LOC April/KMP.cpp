#include<bits/stdc++.h>
using namespace std;
string pat;
string txt;
long long lps[100000];
long long M,N;
long long ans;
void computeLPSArray();

long long KMPSearch()
{
    int M = pat.size();
    int N = txt.size();
    int j  = 0;
    computeLPSArray();

    int i = 0;
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }

      if (j == M)
      {
        ans=i-j;
        j = lps[j-1];
      }

      else if (i < N && pat[j] != txt[i])
      {
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    return ans;
    // to avoid memory leak
}

void computeLPSArray()
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example
           // AAACAAAA and i = 7.
           len = lps[len-1];

           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
int main()
{
    long long int t,n,k,flag;
     cin>>t;
     while(t--)
     {   ans=-1;
         cin>>pat>>txt;
         KMPSearch();
         cout<<ans<<endl;
     }
   return 0;
}
