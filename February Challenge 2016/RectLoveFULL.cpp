#include<bits/stdc++.h>
using namespace std;
//int a[101][101];
//void print(int n,int m)
//{
//
//    return;
//}
long long int a[101][101];
int main()
{
    long long int r,c,t,k,p,q,in,num;
    cin.sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        num=0;
        cin>>r>>c>>k;
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                a[i][j]=((j-1)*(c+1-j)+(c-j)+1)*((i-1)*(r+1-i)+(r-i)+1);
            }
        }
//        for(int i=1; i<=r; i++)
//        {
//            for(int j=1; j<=c; j++)
//            {
//                cout<<a[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        num=0;
        while(k--)
        {
            scanf("%lld",&in);
            p=in%c;
            if(p==0) p=c;
            if(in%c==0)
                q=in/c;
            else
                q=in/c+1;
            num+=a[q][p];
        }
        long double den=((r*r+r)*(c*c+c))/4.0;
        long double ans= (num*1.0)/(den*1.0);
        cout<<ans<<"\n";
    }
    //  print(r,c);

    return 0;
}
