/*  Fractional Knapsack Implementation by Rishabh Jain
    Time Complexity: O(N)
*/
#include<bits/stdc++.h>
using namespace std;
struct item
{
    long long weight;
    long long cost;
    long long knapsack_value;
};
bool compare_function(item left, item right)
{   //Increasing order
    //We swap when order is not correct. Left>Right is not correct for increasing!
    return (left.knapsack_value>right.knapsack_value);
}
int main()
{       item items[10001];
        long long t,n,w,knapsack_max_value;
        cin>>t;
        while(t--)
        {
            cin>>n>>w;
            for(int i=0;i<n;i++)
            {
                cin>>items[i].weight;
                cin>>items[i].cost;
                items[i].knapsack_value=items[i].cost/items[i].weight;
            }
            sort(items,items+n,compare_function);
            knapsack_max_value=0;
            //w is the weight left
            for(int i=0;i<n;i++)
            {
                if(w>=items[i].weight)
                    knapsack_max_value+=items[i].cost;
                else
                    knapsack_max_value+=items[i].knapsack_value * w;
                w -= items[i].weight;
            }
            cout<<knapsack_max_value<<endl;
        }
        return 0;
}
