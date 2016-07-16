#include<bits/stdc++.h>
using namespace std;
long long int ar[15],ar2[15];
int main()
{
    ios_base::sync_with_stdio(false);
    long long int p,s,c,i,k,a,v,x,t,d,r,l;
    cin>>t;
    while(t--)
    {   c=1;x=0;
        cin>>a>>d>>l>>r;
        ar[0]=(a-1)%9+1;
        s=ar[0];
        for(c=1;c<=11;c++)
        {   a+=d;
            p=(a-1)%9+1;
            if(p==ar[0]) break;
            ar[c]=p;
            s+=p;
        }
 
        v=l%c?l%c:c;
        //cout<<v<<endl;
        for(i=v-1;i<c;i++)
        {
            ar2[x]=ar[i];
            x++;
        }
        for(i=0;i<v-1;i++)
        {
            ar2[x]=ar[i];
            x++;
        }
        s=((r-l+1)/c)*s;
 
        for(i=0; i<(r-l+1)%c; i++)
            s+=ar2[i];
        cout<<s<<"\n";
    }
    return 0;
}