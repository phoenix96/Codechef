#include<bits/stdc++.h>
using namespace std;
struct in
{
    int no;
    char c;
}a[1000001];
long long int r[1000001];
long long int b[1000001];
long long int y[1000001];
int main()
{
    long long int n,blue=0,yellow=0,red=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {   cout<<"No: ";
        cin>>a[i].no;
        cout<<"Colour: ";
        cin>>a[i].c;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {

        if(a[i].c=='B'||a[i].c=='b')
            b[blue++]=a[i].no;
            else if(a[i].c=='r'||a[i].c=='R')
            r[red++]=a[i].no;
            else
                y[yellow++]=a[i].no;
    }
    for(int i=0;i<red;i++)
    {
        a[i].c='R';
        a[i].no=r[i];
    }
    for(int i=red;i<blue+red;i++)
    {
        a[i].c='B';
        a[i].no=b[i-red];
    }
    for(int i=blue+red;i<blue+red+yellow;i++)
    {
        a[i].c='Y';
        a[i].no=y[i-blue-red];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i].no<<"";
        cout<<a[i].c<<",";
    }
    cout<<endl;

}
