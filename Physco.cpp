#include<bits/stdc++.h>
using namespace std;
long long a[18][10];
int main()
{   long long in;
    long long people=10, questions=17, answers=5;
    //long long people=2, questions=3, answers=5;
    for(int i=0;i<people;i++)
    {
        for(int j=0;j<questions;j++)
        {
            cin>>in;
            a[j][in]++;
        }
        cout<<"next"<<endl;
    }
    for(int i=0;i<questions;i++)
    {
        for(int j=1;j<=answers;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}
