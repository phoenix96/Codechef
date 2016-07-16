#include<bits/stdc++.h>
using namespace std;
long long ans[100003];
void solve()
{ //  ans[1]=1;
//    ans[2]=1;
    for(int i=1;i<100001;i++)
    {   //cout<<i<<":";
        long long k=sqrt(i);
        for(int j=1;j<=k;j++)
        {
            if(i%j==0)
               {    //cout<<j<<" ";
                    if(j%2!=0)
                        ans[i]+=j;
                    long long h=(i*1.0/j*1.0);
                       // cout<<h<<" ";
                        if(h%2 !=0)
                        ans[i]+=h;
                    if(j == h && h%2!=0)
                        ans[i]-=j;

                }
        }
       // cout<<endl;
    }
//    for(int i=1;i<11;i++)
//    {
//           cout<<ans[i]<<endl;
//    }

}
int main()
{  //  SieveOfEratosthenes();
    ios_base::sync_with_stdio(false);
    long long t=0,n,tans,fans,temp,k,c,a,b,l,r,i,ansb,mul;
    solve();
    cin>>t;
    while(t--)
    {   tans=1;
        fans=0;
        cin>>l>>r;
        //cout<<l<<r<<endl;
        for(i=l;i<=r;i++)
        {   //cout<<i<<":";
            c=0;
            fans+=ans[i];
        }
        cout<<fans<<endl;
    }
//            tans=1;
//            temp=i;
//            k=0;
//            while(temp%2==0)
//                temp=temp/2;
//            //cout<<temp;
//            while(temp>1)
//            {
//                if(temp%pr[k]==0)
//                    {   //cout<<temp<<"p"<<pr[k]<<" ";
//                        temp=temp/pr[k];
//                        c++;
//                        if(temp%pr[k]!=0)
//                        {
//                            tans=(power(pr[k],c+1)-1)/(pr[k]-1);
//                            fans+=tans;
//                        }
//                    }
//                else
//                    {
//                        k++;
//                    }
//            }
//          //  cout<<"::"<<ans<<endl;
//        }

//    cout<<fans<<endl;
  //  }
    return 0;
}
