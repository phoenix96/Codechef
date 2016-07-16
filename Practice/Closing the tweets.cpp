#include<iostream>
#include<string.h>
#define fast ios_base::sync_with_stdio(false);
using namespace std;
int main()
{   fast
    int c=0;
    int n,k;
    char s[10];
    cin>>n>>k;
    int a[n];
    int x;
    memset(a,0,sizeof(a));
    while(k--)
    {
        cin>>s;
        if(!strcmp(s,"CLOSEALL"))
        {
            memset(a,0,sizeof(a));
            c=0;
        }
        else
        {
            cin>>x;
            a[x-1]=!a[x-1];
            if (a[x-1]) c++;
            else c--;
 
        }
        cout<<c<<"\n";
    }
    return 0;
}