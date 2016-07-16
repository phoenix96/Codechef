#include<iostream>
#include<conio.h>
#include <fstream>
#include <time.h>
using namespace std;
int a[1000000];
int num;
int comparisons;
int swaps;
//Printing the array
void print(int *a, int n)
{
    int i=0;
    while(i<n){
        cout<<a[i]<<",";
        i++;
    }
}
//A simple swap function
void swap(int i,int j, int *a){swaps++;
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

//main algo
void quicksort(int *a, int left, int right){
    int min = left+(right-left)/2;//to avoid overflow
    int i = left;
    int j = right;
    int pivot = a[min];

    while(left<j || i<right)
    {
        while(a[i]<pivot)
        { i++; comparisons++;}
        while(a[j]>pivot)
        { j--; comparisons++;}

        if(i<=j){
            swap(i,j,a);
            i++;
            j--;
        }
        else{
            if(left<j)
                quicksort(a, left, j);
            if(i<right)
                quicksort(a,i,right);
            return;
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
    {   comparisons=0;
        swaps=0;
        createfile();
        t1=clock();
        quicksort(a,0,num);
        t2=clock();
        t=(float)(t2)-(float)(t1);
        cout<<"Time for "<<num<<" is "<<t/CLOCKS_PER_SEC<<" and comparisons/swaps: ";
        cout<<comparisons<<" "<<swaps<<endl;
    }
    return 0;
}

