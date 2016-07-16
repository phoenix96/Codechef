#include <stdio.h>

#define max(a,b) (a > b ? a : b)

int matrix[100][100] = {0};
int picks[100][100] = {0};

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

void printPicks(int item, int size, int weights[]){

    while (item>0){
        if (picks[item][size]==1){
            printf("%d ",weights[item]);

            size -= weights[item];
            item--;
        }
        else{
            item--;
        }
    }

    printf("n");

return;
}

int main(){
    int nItems = 2;
    int knapsackSize = 7;
    int weights[2] = {6,5};
    int values[2] = {1,1};

    printf("Max value = %dn",knapsack(nItems,knapsackSize,weights,values));
    printf("Picks were: ");
    printPicks(nItems,knapsackSize, weights);

    return 0;
}
