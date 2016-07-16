#include<bits/stdc++.h>
using namespace std;
long long int k[10000];
long long int un[100000];
int check(char s1[1000],char s[1000],int i,int j,int k,int l)
{   //cout<<"Checking "<<s<<" "<<s1<<endl;
    char test[1000], test1[1000]; char temp;
    strcpy(test1,s1);
    strcpy(test,s);
    temp=test1[i];
    test1[i]=test1[j];
    test1[j]=temp;
    temp=test1[k];
    test1[k]=test1[l];
    test1[l]=temp;
    //cout<<"After "<<test<<" "<<test1<<endl;
    if(strcmp(test1,test)==0) return 1;
    return 0;
}
int main()
{   long long int M=1000000000+7;
    long long int tt,l,ans,sim,c;
    cin>>tt;
    char s[1000],s1[1000],s2[1000];
    while(tt--)
    {
        ans=0;
        sim=0;
        cin>>s;
        sort(s,s+(strlen(s)));
        int p=1;
        strcpy(s1,s);
        l=strlen(s);
        long long ris=0;
        //do
        //{
            do
            {  // cout<<s<<" "<<s1<<" "<<endl;
                c=0;
                for(int i=0; i<l; i++)
                {
                    if(s[i]!=s1[i])
                        c++;
                }
                cout<<c<<",";
                k[c]++;
               // cout<<c<<endl;
                if(c==4)
                {   int p[4];int k=0;
                    //sim++;
                    // cout<<s1<<" "<<s<<endl;
                    for(int i=0; i<l; i++)
                    {
                        if(s[i]!=s1[i])
                            {
                             p[k++]=i;
                            }
                    }
//                for(int i=0;i<4;i++)
//                {
//                    cout<<p[i]<<",";
//                }
//                cout<<endl;
             if((check(s1,s,p[0],p[1],p[2],p[3]))||(check(s1,s,p[0],p[2],p[1],p[3]))||(check(s1,s,p[0],p[3],p[1],p[2])))
             {

             }
             else{
                ans++;
                un[c]++;
                ans=ans%M;
                //if(s1[0]=='a') {cout<<s1<<endl; ris++;}
                //cout<<"Unsimilar!"<<endl;
                //cout<<s1<<endl;
             }
                }
                else if(c>4&&p==1)
                {   // cout<<"Unsimilar!!"<<endl;
                    ans++;
                    un[c]++;
                    ans=ans%M;
                   // if(s1[0]=='a') { cout<<s1<<endl; ris++;}
                   // cout<<s1<<"::"<<c<<"  ";
                   //cout<<s1<<endl;
                }
               // cout<<s<<" "<<s1<<" "<<sim<<" ";
            }
            while(next_permutation(s1,s1+l));
            for(int i=0;i<=10;i++)
                //cout<<k[i]-un[i]<<",";
                //cout<<endl;
                for(int i=0;i<=10;i++)
                //cout<<un[i]<<",";
                //cout<<endl;
            //}
        //while(next_permutation(s,s+l));
        cout<<ans<<endl;
    }
    return 0;
}
