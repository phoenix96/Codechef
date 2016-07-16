/*
                                        A Rishabh Jain's Production
                                                (9914103137)
                                    Jaypee Institute of Information Technology

*/
#include<bits/stdc++.h>
using namespace std;
//int freq[26];
int main()
{
    long long tt,flag,i,o;
    string s,ls,rs,temp;
    long long no;
    cin>>tt;
    while(tt--)
    {
        cin>>s;
        if(s.length()==1||s.length()==0)
        {
            cout<<"NO\n";
            continue;
        }
        else if(s.length()%2==0)
        {
            if(s.substr(0,s.length()/2)==s.substr(s.length()/2,s.length()/2))
            cout<<"YES\n";
            else
                cout<<"NO\n";
            continue;
        }
        flag=0;
        no=0;
        i=0;
        ls=s.substr(0,s.length()/2+1);
        //cout<<"Left String: "<<ls<<endl;
        rs=s.substr(s.length()/2+1,s.length()/2+1);
        //cout<<"Right String: "<<rs<<endl;
        for(int j=0; j<rs.length(); i++,j++)
        {
            //cout<<ls[i]<<" "<<rs[j]<<endl;
            if(ls[i]!=rs[j])
            {
           //     cout<<"NE"<<endl;
                j--;
                flag++;
                if(flag>1)
                {
         //           cout<<"BREAKED!"<<endl;
                    no=1;
                    break;
                }
            }
        }
       // cout<<s.substr(1,s.length()/2)<<endl;
       // cout<<s.substr(s.length()/2+1,s.length())<<endl;
//        if(s.substr(1,s.length()/2)==s.substr(s.length()/2+1,s.length()))
//            no=0;
        if(no==1)
        {   //cout<<"__________________________________\n";
            no=0;
            flag=0;
            i=0;
            rs=s.substr(0,s.length()/2);
            ls=s.substr(s.length()/2);
            //cout<<ls<<endl;
            //cout<<rs<<endl;
            for(int j=0; j<rs.length(); i++,j++)
            {
                //cout<<ls[i]<<" "<<rs[j]<<endl;
                if(ls[i]!=rs[j])
                {
                    //cout<<"NE"<<endl;
                    j--;
                    flag++;
                    if(flag>1)
                    {
                       // cout<<"BREAKED!"<<endl;
                        no=1;
                        break;
                    }
                }
            }
            if(no==0) cout<<"YES\n";
            else cout<<"NO\n";

        }
        else
            cout<<"YES\n";
    }
    return 0;
}
