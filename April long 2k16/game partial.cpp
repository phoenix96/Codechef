#include<bits/stdc++.h>
using namespace std;
long long grid[700][700];
void print_grid(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    long long n,m,k,x,y,inx,iny,inx2,iny2,t,headx,tailx,heady,taily;
    string s;
    headx=heady=tailx=taily=-1;
    t=0;
    cin>>n>>m>>k;
    t=k;
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        grid[x-1][y-1]=-1;
    }
    if(t==(n*m))
    {
        cout<<"EXIT\n";
        return 0;
    }
    //first move
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]!=-1)
            {
                cout<<"NEW "<<i+1<<" "<<j+1<<"\n";
                fflush(stdout);
                headx=i;
                heady=j;
                tailx=i;
                heady=j;
                grid[i][j]=-1;
                break;
            }
        }
        if(headx!=-1)
            break;
    }
//    print_grid(n,m);
    t++;
//    while(t!=(n*m))
//    {
        cin>>s;
        if(s=="EXIT")
        {
            return 0;
        }
        else if(s=="MOVE")
        {    //   fflush(stdout);
            cin>>inx>>iny>>inx2>>iny2;
            grid[inx2-1][iny2-1]=-1;
        }
        else if(s=="FREEZE")
        {  //     fflush(stdout);
            cin>>inx;
        }
        else if(s=="NEW")
        {//       fflush(stdout);
            cin>>inx>>iny;
            grid[inx-1][iny-1]=-1;
        }
  //          print_grid(n,m);
    //        fflush(stdout);
            cout<<"EXIT\n";

//    }

}

