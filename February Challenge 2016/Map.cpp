#include<map>
#include<iostream>
#include<cassert>
using namespace std;
int main()
{
    map<string,int> m;
    m["hello"]=23;
    if(m.find("world")!=m.end())
        cout<<"map contains key world"<<endl;
    cout<< m["hello"] <<"\n";
    map<string, int>::iterator i = m.find("hello");
    assert(i!=m.end());
    cout<<"Key: "<<i->first<<" value: "<<i->second<<"\n";
    return 0;
}
