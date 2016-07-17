#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int jc,sc,m,b;
    cin>>jc>>sc>>m;
    b=(m-jc)/sc;
    if(b%2==0)
        cout<<"Lucky Chef"<<endl;
        else
             cout<<"Unlucky Chef"<<endl;
   return 0;

}
