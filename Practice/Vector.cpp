#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> a;
    a.push_back(10);
    a.push_back(11);
    a.push_back(12);



    cout<<a.at(0)<<" "<<a.at(1)<<" "<<a.at(2)<<" "<<endl;
    vector<int>::iterator it;
    it=a.begin();
    while(it!=a.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    return 0;
}
