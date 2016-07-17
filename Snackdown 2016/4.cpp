#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ss[5];
int set_size;
int li;

int lis( int arr[], int n )
{  // for(int i=0;i<n;i++) {cout<<arr[i]<<" ";}

    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );

    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
    free(lis);

    return max;
}
int printPowerSet()
{   vector <int> v;
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
    int count=0;
    for(counter = 0; counter < pow_set_size; counter++)
    { v.clear();
      for(j = 0; j < set_size; j++)
       {
          if(counter & (1<<j))
            {
               // printf("%d", ss[j]);
                v.push_back(ss[j]);
            }
       }
       //printf("\n");
       if(v.size()!=li) continue;
       if(v.size()==1) { count++;}
       else
       {
           int flag=0;
           for(int i=1;i<v.size();i++)
            {
                if(v[i]<v[i-1])
                {
                    flag=-1;
                    break;
                }
            }
            if(flag==0)
                {
                    //cout<<"Yes\n";
                    count++;
                }
       }
    }
    return count;
}

int main()
{
    int t,n,q,m,m2,a;
    set_size=6;
    ss[0]=1;
    ss[1]=2;
    ss[2]=3;
    ss[3]=4;
    ss[4]=5;
    ss[5]=6;
    do
    {li=0;
    li=lis(ss,6);
    //cout<<li<<" ";
    for(int i=0;i<6;i++)
            cout<<ss[i]<<" ";
    cout<<": ";
    t=printPowerSet();
    cout<<t<<endl;
    }while(next_permutation(ss,ss+set_size));
}
