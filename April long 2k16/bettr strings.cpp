#include<bits/stdc++.h>
#include<fstream>
#include<ctime>
using namespace std;
static int ans;
ofstream fout;
ifstream fin;
int isgood(string s)
{
    vector <int> ia,ib,ic;
    long long iia[5100],iib[5100],iic[5100];
    for(int i=0; i<51; i++)
    {
        iia[i]=iib[i]=iic[i]=0;
    }
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='a')
        {
            ia.push_back(i);
            iia[i]=1;
        }
        if(s[i]=='b')
        {
            ib.push_back(i);
            iib[i]=1;
        }
        if(s[i]=='c')
        {
            ic.push_back(i);
            iic[i]=1;
        }
    }
    for(int i=0; i<ia.size(); i++)
    {
        for(int j=i+1; j<ia.size(); j++)
        {
            if((ia[i]+ia[j]%2==0)&&(iia[(ia[i]+ia[j])/2]==1))
                return -1;
        }
    }
    for(int i=0; i<ib.size(); i++)
    {
        for(int j=i+1; j<ib.size(); j++)
        {
            if((ib[i]+ib[j]%2==0)&&(iib[(ib[i]+ib[j])/2]==1))
                return -1;
        }
    }
    for(int i=0; i<ic.size(); i++)
    {
        for(int j=i+1; j<ic.size(); j++)
        {
            if((ic[i]+ic[j]%2==0)&&(iic[(ic[i]+ic[j])/2]==1))
                return -1;
        }
    }
    return 1;
}
int hamdist(string s,string t)
{
    long long ham=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]!=t[i])
            ham++;
    }
    return ham;
}
void fun(string s,int k,int A,int K,string t)
{
    string f;
    if(A==3)
        f="abc";
    else
        f="ab";
    if(k == s.length())
    {
        fout<<s;
        if((isgood(s)==1))
        {
            fout<<" good";
            if(hamdist(s,t)<=K)
            {
                fout<<" hlk "<<hamdist(s,t);
                ans++;
            }
        }
        fout<<endl;
        return;
    }
    for(int i=0; i<A; i++)
    {
        s[k]=f[i];
        fun(s,k+1,A,K,t);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    fout.open("testout.txt");
    fin.open("testin.txt");
    long long t,A,K,ham;
    string s,s1,s2;
    fin>>t;
    while(t--)
    {
        ans=0;
        fin>>A>>K;
        fin>>s;
        if(A==1)
        {
            if(s.length()<3)
                fout<<"1\n";
            else
                fout<<"0\n";
        }
        else
        {
            fun(s,0,A,K,s);
            fout<<ans<<endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
