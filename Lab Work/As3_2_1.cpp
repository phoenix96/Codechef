#include<bits/stdc++.h>
using namespace std;
long long int a[10001];
void merge_arrays(int low, int mid, int high)
{

    long long int h,i,j,b[10001],k;
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];

}
void merge_sort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge_arrays(low,mid,high);
    }
}

int main()
{
    long long int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        //USING N(LOG N) SORTING -- MERGE SORT
        merge_sort(0,n-1);
        //FINISH SORTING
        //JUST PAIRING UP FIRST AND LAST ELEMENTS!
        cout<<"The respective pairs are: "<<endl;
        for(int i=0;i<n/2;i++)
        {
            cout<<"("<<a[i]<<","<<a[n-1-i]<<")"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
