#include <iostream>
#include <fstream>
using namespace std;
int a[1000000];
int main()
{
    ifstream myfile;
    myfile.open("Random.txt");
    for(int i = 0; i<1000000; i++)
       {
           myfile >>a[i];
           cout<<a[i]<<endl;
       }

    myfile.close();
    return 0;
}
