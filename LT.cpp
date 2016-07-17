#include<bits/stdc++.h>
using namespace std;
char k[25][25];
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>k[i][j];
            }
        }
        int x,y,z,b;
        int dx,dy,dz,db,flag=0;
        if(m==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        for(int l=0;l<3;l++)
        {
            if(k[l][1]=='X'&&k[l][1]=='X'&&k[l][1]=='.')
            {
                flag=1;
            }
        }
        for(int l=0;l<3;l++)
        {
            if(k[l][0]=='X'&&k[l][0]=='.'&&k[l][0]=='X')
            {
                flag=1;
            }
        }
        for(int l=0;l<3;l++)
        {
            if(k[l][2]=='.'&&k[l][2]=='X'&&k[l][2]=='X')
            {
                flag=1;
            }
        }
        for(int l=0;l<3;l++)
        {
            if(k[1][l]=='X'&&k[1][l]=='X'&&k[1][l]=='.')
            {
                flag=1;
            }
        }
        for(int l=0;l<3;l++)
        {
            if(k[0][l]=='X'&&k[0][l]=='.'&&k[0][l]=='X')
            {
                flag=1;
            }
        }
        for(int l=0;l<3;l++)
        {
            if(k[2][l]=='.'&&k[2][l]=='X'&&k[2][l]=='X')
            {
                flag=1;
            }
        }
        int dot=0;x=0;
        for(int l=0;l<3;l++)
        {
            if(k[l][l]=='.')
            {
                dot=1;
            }
            if(k[l][l]=='X')
            {
                x++;
            }
        }
        dot=0; x=0;
        for(int l=0;l<3;l++)
        {
            if(k[2-l][l]=='.')
            {
                dot=1;
            }
            if(k[2-l][l]=='X')
            {
                x++;
            }
        }
        if(x==2&&dot==1) flag=1;

             if(flag==1)
            cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
    }
    return 0;

}
