#include<iostream>
using namespace std;
int main()
{
    long long int t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n>m)
        {
            cout<<"Bipin "<<(n-m)<<endl;
        }
        else if(n==m)
        {
            cout<<"No Winner"<<endl;
        }
        else
        {
            cout<<"Balaji "<<(m-n)<<endl;
        }
    }
    return 0;
}
