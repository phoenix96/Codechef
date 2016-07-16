#include<bits/stdc++.h>
using namespace std;
vector <int><int> hap[101][101];
vector <int> pr[101];
vector <int> na[101];
vector  <int> dem[101];
void insertionSort(int length) {
      int i, j, tmp;comparisons=0;swaps=0;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && a[j - 1] > a[j]) {

                  tmp = pr[j];
                  pr[j] = pr[j - 1];
                  pr[j - 1] = tmp;
                  tmp = na[j];
                  na[j] = na[j - 1];
                  na[j - 1] = tmp;
                  j--;
            }
      }
}
int main()
{   long long int tt,n,x,in,in2;
    cin>>tt;
    long long pr_length=0;
    while(tt--)
    {
        cin>>x>>n;
        cin>>in;
        for(int i=0;i<x;i++)
            na[i]=i+1;
        while(in!=-1)
        {
            cin>>in2;
            hap[in-1][in2-1]=1;
            pr[in-1]++;
            pr_length++;
            dem[in2-1]++;
            cin>>in;
        }
        insertionSort(pr_length);
        for(int i=0;i<x;i++)
        {
            m=min_element(hap,hap+x);
        }
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout<<hap[i][j]<<" ";
//            }
//            cout<<endl;
//        }

    }
    return 0;
}
