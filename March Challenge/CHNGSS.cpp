#include<iostream>
using namespace std;
long long int a[1000][1000];
int main()
{       //cin.tie(0);
        ios_base::sync_with_stdio(false);
        long long int n,m,c,input;
        cin>>n>>m>>c;
        long long int n2,m2;
        n2=n;
        m2=m;
        if(n2>1000) n2=1000;
        if(m2>1000) m2=1000;
        for(int i=0;i<n2;i++)
        {
            for(int j=0;j<m2;j++)
            {
                for(int k=1;k<=50;k++)
                {
                    cout<<"1 "<<(i+1)<<" "<<(i+1)<<" "<<(j+1)<<" "<<(j+1)<<" "<<k<<" "<<k;
                    cin>>input;
                    if(input==1)
                    {
                        a[i][j]=k;
                        break;
                    }
                }
            }
        }
        cout<<"3"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]!=0) cout<<a[i][j]<<" ";
                else cout<<"25 ";
            }
            cout<<"\n";
        }
        return 0;
}
