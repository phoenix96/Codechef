#include<iostream>
using namespace std;
char k[25][25];
int main()
{   int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               cin>>k[i][j];
            }
        }
        if(m==1) { cout<<"YES"<<endl; continue; }
        for(int i=0;i<n;i++)
        {   x=0;y=0;z=0;
            for(int j=0;j<n;j++)
            {
                if(k[i][j]=='X')
                {
                    x++;
                    if(x==(k-1))
                    {
                        flag=1;
                        break;
                    }
                }
                else if(k[i][j]=='O')
                {
                    x=0;
                }
                if(k[j][i]=='X')
                {
                    y++;
                    if(y==(k-1))
                    {
                        flag=1;
                        break;
                    }
                }
                else if(k[j][i]=='O')
                {
                    y=0;
                }
                if(k[i][i]=='X')
                {
                    y++;
                    if(y==(k-1))
                    {
                        flag=1;
                        break;
                    }
                }
                else if(k[i][i]=='O')
                {
                    x=0;
                }


            }
            if(flag==1) break;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}
