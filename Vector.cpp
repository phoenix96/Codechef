#include<vector>
#include<iostream>
typedef std::vector<int> iv;
using namespace std;
int main()
{
    iv v;
    v.reserve(10);
    for(int i=0;i<10;++i)
        v.push_back(i);
    for(int i=0;i<10;++i)
        cout<<v[i]<<",";
        return 0;
}
