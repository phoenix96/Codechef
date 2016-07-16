#include<iostream>
#include<conio.h>
#include <fstream>
#include <time.h>
using namespace std;
int a[1000000];
int num;
int comparisons;
int swaps;
void insertionSort(int length) {
      int i, j, tmp;comparisons=0;swaps=0;
      for (i = 1; i < length; i++) {
            j = i;comparisons++;
            while (j > 0 && a[j - 1] > a[j]) {
                  swaps++;
                  tmp = a[j];
                  a[j] = a[j - 1];
                  a[j - 1] = tmp;
                  j--;
            }
      }
}
void createfile()
{
    ifstream myfile;
    myfile.open("Increasing.txt");
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
        insertionSort(num);
        t2=clock();
        t=(float)(t2)-(float)(t1);
        cout<<"Time for "<<num<<" is "<<t/CLOCKS_PER_SEC<<" and comparisons/swaps: ";
        cout<<comparisons<<" "<<swaps<<endl;
    }
    return 0;
}
