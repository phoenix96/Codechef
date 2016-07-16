#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[1001];
ll pass[1001];
ll dp[1001][1001];
ll M,N;
//N=3;
//M=3;      0       2
void recur(int np, int pos)
{
    //cout<<"a";
    //  cout<<pos<<"->";
    //cout<<np<<" "<<pos<<endl;
    if(pos>(N-1)||pos<0)
    {
        //    cout<<"Error"<<endl;
        return;
    }
    if(np == M)
    {
        //  cout<<"End"<<endl;
        ans[pos]++;
        return;
    }
    recur(np+1,pos+pass[np]);
    //cout<<pos<<"->";
    recur(np+1,pos-pass[np]);
    return;
}
void dpfunct(int np, int pos)
{

}
int main()
{
    ll t,n,s;
    cin>>t;
    while(t--)
    {
        cin>>N>>M>>s;
        for(int i=0; i<M; i++)
            cin>>pass[i];
//{1,1,1}
        for(int i=0; i<N; i++)
            ans[i]=0;
        recur(0,s-1);
        for(int i=0; i<N; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
