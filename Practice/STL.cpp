#include<bits/stdc++.h>
using namespace std;
int bin_search()
{
    int a[]={4,3,2,1,7,6};
    int n = sizeof(a)/sizeof(int);
    sort(a,a+n);
    cout<<binary_search(a,a+n,3)<<endl;//OUTPUT: 1
    cout<<binary_search(a,a+n,10)<<endl;//OUTPUT: 0
    return 0;
}
void STL_PAIR()
{   //pair <dt1, dt2>
    pair <int,string> p,p2;
    p=make_pair(5,"Rishabh");
    p2=make_pair(4,"Tarun");
    cout<<p.first<<" "<<p.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
    swap(p,p2);
    cout<<p.first<<" "<<p.second<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
}
int main()
{
    //bin_search();
    STL_PAIR();
    return 0;
}
