#include<bits/stdc++.h>
using namespace std;
long long int c[1000001];
long long int t,n,i,j,k,l,m;
void partial()
{   long long** a=new long long*[n+1];
    long long int temp,tempmax;
    for(int i=0; i<n; i++)
        {   a[i]=new long long [m+1];
            for(int j=0; j<m; j++)
            {
                scanf("%lld",&a[i][j]);
            }
        }
        tempmax=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int k=0; k<m; k++)
                {
                    c[a[i][k]]++;
                    if(c[a[i][k]]>tempmax)
                    {
                        tempmax=c[a[i][k]];
                    }
                }
                for(int k=0; k<n; k++)
                {
                    if(k!=i) c[a[k][j]]++;
                    if(c[a[k][j]]>tempmax)
                    {
                        tempmax=c[a[k][j]];
                    }
                }
                for(int k=0; k<m; k++)
                {
                    c[a[i][k]]=0;
                }
                for(int k=0; k<n; k++)
                {
                    c[a[k][j]]=0;
                }
               // cout<<tempmax<<" ";
            }
            //cout<<endl;
        }
        printf("%lld\n",tempmax);
    return;
}
int  main()
{

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        if(n<=100&&m<=100)
        {
            partial();
        }
        long long** a=new long long*[n+1];
        long long int M=1000001;
        for(int i=0;i<n;i++)
        {   a[i]=new long long [m+1];
            for(int j=0;j<m;j++)
            {
                scanf("%lld",&a[i][j]);
            }
        }

        long long int *rmaxno= new long long int[1000001],rmaxcount=0;
        long long int rmaxin=0;
        for(int i=0;i<n;i++)
        {rmaxcount=0;
            for(int j=0;j<m;j++)
            {
                c[a[i][j]]++;
                if(c[a[i][j]]>rmaxcount)
                {   rmaxin++;
                    rmaxcount=c[a[i][j]];
                    rmaxno[a[i][j]]=rmaxin;
                }
                else if(c[a[i][j]]==rmaxcount)
                {
                    rmaxno[[a[i][j]]]=rmaxin;
                }

            }

            for(int j=0;j<m;j++)
            {
                c[a[i][j]]=0;
            }
        }
      //  cout<<"Rmaxno: "<<rmaxno<<"::::"<<rmaxcount<<endl;


        long long int *cmaxno=new long long int[1000001],cmaxcount=0;
        long long int cmaxin=0;
        for(int j=0;j<m;j++)
        {cmaxcount=0;
            for(int i=0;i<n;i++)
            {
                c[a[i][j]]++;
                if(c[a[i][j]]>cmaxcount)
                {   cmaxin++;
                    cmaxcount=c[a[i][j]];
                    cmaxno[a[i][j]]=cmaxin;
                }
                else if(c[a[i][j]==cmaxcount)
                {
                    cmaxno[a[i][j]]=camxin;
                }
            }
            for(int i=0;i<n;i++)
            {
                c[a[i][j]]=0;
            }


        }

      //  cout<<"Cmaxno: "<<cmaxno<<"::::"<<cmaxcount<<endl;

        long long int *r2count=long long int [1000001],r2maxcount=0;
        memset(r2count,0,1000001);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(cmaxno[a[i][j]]==cmaxin)
                {
                    r2count[a[i][j]]++;
                }
            }

            if(r2count>r2maxcount)
                r2maxcount=r2count;
            //memset(c,0,sizeof(c));
        }

       // cout<<"R2maxno: "<<r2count<<"::::"<<r2maxcount<<endl;
        long long int c2count=-1,c2maxcount=0;
        for(int j=0;j<m;j++)
        {c2count=0;
            for(int i=0;i<n;i++)
            {
                if(rmaxno[a[i][j]]=rmaxin)
                {
                    c2count++;
                }
            }

            if(c2count>c2maxcount)
                c2maxcount=c2count;
            //memset(c,0,sizeof(c));
        }
      //  cout<<"C2maxno: "<<c2count<<"::::"<<c2maxcount<<endl;
        if(c2maxcount+rmaxcount>r2maxcount+cmaxcount)
        {
            printf("%lld\n",c2maxcount+rmaxcount-1);
        }
        else
            printf("%lld\n",r2maxcount+cmaxcount-1);
    }
            return 0;

}
