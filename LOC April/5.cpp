#include<bits/stdc++.h>
using namespace std;
long long poles[100001],run[100001],dpole[100001];
int main()
 {
     long long int t,n,k,flag,ans;
     cin>>t;
     while(t--)
     {  ans=0;
         cin>>n>>k;
         for(int i=0;i<n;i++)
            cin>>poles[i];
         for(int i=0;i<k;i++)
              cin>>run[i];
              flag=0;
              dpole[0]=0;
              cout<<"0 ";
        for(int i=1;i<n;i++)
        {
            dpole[i]=poles[i]-poles[i-1];
            cout<<dpole[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<k;i++)
        {
            if(run[i]!=run[i-1])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
                //Normal Case
                long long offset=0;
            for(int i=1;i<n;i++)
            {   if(offset==k)
                {
                    offset=0;
                    ans++;
                    i+=offset;
                    cout<<"found ";
                }
                cout<<i<<" "<<dpole[i+offset]<<" "<<run[offset]<<" ";
                if(dpole[i+offset]==run[offset])
                {
                    offset++;
                    cout<<"if ";
                    i--;
                }
                else
                {   i+=offset+1;
                    offset=0;
                    cout<<"else ";
                }
                cout<<"o2: "<<offset<<" ";

                cout<<endl;
            }
        }
        else
        {
            cout<<"Bakchodi Case\n";
        }
        cout<<ans<<endl;
     }
     return 0;
 }
