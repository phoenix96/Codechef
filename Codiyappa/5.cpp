#include <bits/stdc++.h>
#define max(a,b) (a > b ? a : b)
using namespace std;
int matrix[1000][1000];
int picks[1000][1000];

int knapsack(int nItems, int size, int weights[], int values[]){
    int i,j;

    for (i=1;i<=nItems;i++){
        for (j=0;j<=size;j++){
            if (weights[i-1]<=j){
                matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
                if (values[i-1]+matrix[i-1][j-weights[i-1]]>matrix[i-1][j])
                    picks[i][j]=1;
                else
                    picks[i][j]=-1;
            }
            else{
                picks[i][j] = -1;
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    return matrix[nItems][size];

}

int printPicks(int item, int size, int weights[]){
int ans=0;
    while (item>0){
        if (picks[item][size]==1){
            ans+=weights[item-1];
            size -= weights[item];
            item--;
        }
        else{
            item--;
        }
    }

    //printf("n");

return ans;
}
int main()
{   int t,n,k,ans1,ans2;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int W=k;
        int val[n]; int wt[n];
        for(int i=0;i<n;i++)
        {
            cin>>wt[i]>>val[i];
        }
        ans2=knapsack(n, k, wt, val);
        ans1=printPicks(n,k,wt);
        cout<<ans1<<" "<<ans2<<"\n";

    }
    return 0;
}
