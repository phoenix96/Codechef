#include<iostream>
#include<algorithm>
#include<string.h>
#define fast ios_base::sync_with_stdio(false);
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    char a[100][201];
    char ans[201];
    char x;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>x;
        int c=0,m=0;
        for(int i=0;i<n;i++)
        {c=0;
            for(int j=0;j<strlen(a[i]);j++)
            {
                if(x==a[i][j])
                    c++;
            }
            if(c>m)
            {
                m=c;
                strcpy(ans,a[i]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
 