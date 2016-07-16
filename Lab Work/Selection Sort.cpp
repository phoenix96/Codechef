#include<iostream>
#include<conio.h>
#include <fstream>
#include <time.h>
using namespace std;
int a[1000000];
int num;
int comparisons;
int swaps;
void s_sort(int n)
{
    comparisons=0;
    swaps=0;
    int i,j,t;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            comparisons++;
            if(a[j]<a[i]) //for descending order use if(a[j]>a[i])
            {
                swaps++;
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
}
void createfile()
{
    ifstream myfile;
    myfile.open("Random.txt");
    for(int i = 0; i<num; i++)
    {
        myfile >>a[i];
    }

    myfile.close();
}
int main()
{   clock_t t1,t2; float t;
    for(num=10; num<100000; num*=10)
    {
        createfile();
        t1=clock();
        s_sort(num);
        t2=clock();
        t=(float)(t2)-(float)(t1);
        cout<<"Time for "<<num<<" is "<<t/CLOCKS_PER_SEC<<" and comparisons/swaps: ";
        cout<<comparisons<<" "<<swaps<<endl;
    }
    return 0;
}
