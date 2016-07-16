#include<bits/stdc++.h>
using namespace std;
long long grid[700][700];
long long n,m,headx,tailx,heady,taily;
int checkx(int x)
{
    if(x>=0&&x<n)
        return 1;
    else return 0;
}
int checky(int y)
{
    if(y>=0&&y<m)
        return 1;
    else return 0;
}
int mv(int x, int y,int e)
{
    if((checkx(x+1)==1)&&(checky(y)==1)&&(grid[x+1][y]!=-1))
    {
        cout<<"MOVE "<<x+1<<" "<<y+1<<" "<<x+2<<" "<<y+1<<endl;
        fflush(stdout);
        grid[x+1][y]=-1;
        if(e==0) {
                    headx++;
                 }
        else
                {
                    tailx++;
                }
        return 1;
    }
    else if((checkx(x-1)==1)&&(checky(y)==1)&&(grid[x-1][y]!=-1))
    {
        cout<<"MOVE "<<x+1<<" "<<y+1<<" "<<x<<" "<<y+1<<endl;
        fflush(stdout);
        grid[x-1][y]=-1;
        if(e==0) {
                    headx--;
                 }
        else
                {
                    tailx--;
                }
        return 1;
    }

    else if((checkx(x)==1)&&(checky(y+1)==1)&&(grid[x][y+1]!=-1))
    {
        cout<<"MOVE "<<x+1<<" "<<y+1<<" "<<x+1<<" "<<y+2<<endl;
        fflush(stdout);
        grid[x][y+1]=-1;
        if(e==0) {
                    heady++;
                 }
        else
                {
                    taily++;
                }
        return 1;
    }
    else if((checkx(x)==1)&&(checky(y-1)==1)&&(grid[x][y-1]!=-1))
    {
        cout<<"MOVE "<<x+1<<" "<<y+1<<" "<<x+1<<" "<<y<<endl;
        fflush(stdout);
        grid[x][y-1]=-1;
        if(e==0) {
                    heady--;
                 }
        else
                {
                    taily--;
                }
        return 1;
    }
    return -1;
}
void print_grid(int n,int m)
{
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            cout<<grid[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    return;
}

int main()
{   ios_base::sync_with_stdio(false);
    long long k,x,y,inx,iny,inx2,iny2,t,ans=0;
    string s;
    headx=heady=tailx=taily=-1;
    t=0;
    cin>>n>>m>>k;
    t=k;
    for(int i=0; i<k; i++)
    {
        cin>>x>>y;
        grid[x-1][y-1]=-1;
    }
    if(t==(n*m))
    {
        cout<<"EXIT\n";
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]!=-1)
            {
                cout<<"NEW "<<i+1<<" "<<j+1<<"\n";
                t++;
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
    print_grid(n,m);
    fflush(stdout);
    if(t==n*m)
    {
        cin>>s;
        return 0;
    }
    while(t!=(n*m))
    {
        cin>>s;
        if(s=="EXIT")
        {
            return 0;
        }
        else if(s=="MOVE")
        {
            cin>>inx>>iny>>inx2>>iny2;
            grid[inx2-1][iny2-1]=-1;
            t++;
        }
        else if(s=="FREEZE")
        {
            cin>>inx;
        }
        else if(s=="NEW")
        {
            cin>>inx>>iny;
            grid[inx-1][iny-1]=-1;
            t++;
        }
        int  g= mv(tailx,taily,1);
        if(g == -1)
            g = mv(headx,heady,0);
        print_grid(n,m);
        if(g == -1)
        {
            headx=heady=tailx=taily=-1;
            for(int i=n-1; i>=0; i--)
            {
                for(int j=m-1; j>=0; j--)
                {
                    if(grid[i][j]!=-1 )
                    {   ans++;
                        cout<<"NEW "<<i+1<<" "<<j+1<<"\n";
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
        }
        if(headx==-1||t==(n*m)||(ans==10000))
        {
            cout<<"EXIT\n";
            return 0;
        }
    }
    return 0;
}
