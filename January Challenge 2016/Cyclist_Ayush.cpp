#include<iostream>
using namespace std;
int main()
{
    int i,j,k=0,l,m,n,q,t,c,ns,type;
    cin>>n>>q;
    int id[n], speed[n], dist[n], out[q], maximum, previous=0,index;
    for(i=0; i<n; i++)
    {
        id[i]=i+1;
        speed[i]=0;
        dist[i]=0;
    }
    for(i=0; i<q; i++)
    {
        cin>>type;
        index=-1;
        if(type==1)
        {

            cin>>t>>c>>ns;
            if(speed[c-1]==0)
                index=c-1;
            speed[c-1]=ns;
            for(m=0; m<n; m++)
            {

                if(m==index)
                    continue;
                else
                    dist[m]=dist[m]+speed[m]*(t-previous);
            }
            previous=t;

        }
        else
        {
            cin>>t;
            for(m=0; m<n; m++)
            {

                if(m==index)
                    continue;
                else
                    dist[m]=dist[m]+speed[m]*(t-previous);
            }
            previous=t;
            maximum=-1;
            for(j=0; j<n; j++)
                if(dist[j]>maximum)
                    maximum=dist[j];
            out[k]=maximum;
            k++;
        }
    }
    for(i=0; i<k; i++)
        cout<<out[i]<<endl;
}
