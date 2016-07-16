#include<iostream>
#include<conio.h>
#include <fstream>
#include <time.h>
using namespace std;
int a[10000];
int num;
int comparisons;
int swaps;


void merge(int,int,int);
void merge_sort(int low,int high)
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
 }
}
void merge(int low,int mid,int high)
{
 int h,i,j,b[10000],k;
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high))
 {comparisons++;
  if(a[h]<=a[j])
  {swaps++;
   b[i]=a[h];
   h++;
  }
  else
  {swaps++;
   b[i]=a[j];
   j++;
  }
  i++;
 }
 comparisons++;
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {swaps++;
   b[i]=a[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {swaps++;
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) {a[k]=b[k]; swaps++;}
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
    {   comparisons=0;
        swaps=0;
        createfile();
        t1=clock();
        merge_sort(0,num);
        t2=clock();
        t=(float)(t2)-(float)(t1);
        cout<<"Time for "<<num<<" is "<<t/CLOCKS_PER_SEC<<" and comparisons/swaps: ";
        cout<<comparisons<<" "<<swaps<<endl;
    }
    return 0;
}

