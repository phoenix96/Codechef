#include<stdio.h>
int main()
{
    int t,n,i,j,k,c,l1,l2,flag;char fl[100][6];char ml[2500][6];
    scanf("%d",&t);
    while(t--)
    {c=0;
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%s",&fl[i]);
            l2=0;
        for(i=0;i<k;i++)
        {
            scanf("%d",&l1);
            for(j=0;j<l1;j++)
            {scanf("%s",&ml[j+l2]);
            }
            l2+=l1;
    }
 
    for(i=0;i<n;i++)
    {flag=0;
        for(j=0;j<l2;j++)
        {
            if(strcmp(fl[i],ml[j])==0)
            { flag =1;printf("YES "); break;}
        }
        if(flag==0)
            printf("NO ");
 
 
    }
    printf("\n");
    }
    return 0;
}