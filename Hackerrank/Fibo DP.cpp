    #include<iostream>
    #include<stdio.h>
    using namespace std;
    int main()
    {
        unsigned long long int n,a,b,ans;
            ans=0;
            cin>>a>>b>>n;
            for(int i=0;i<n-2;i++)
            {
                ans=b*b+a;
             //   std::cout<<ans<<std::endl;
                a=b;
                b=ans;
            }
            cout<<ans<<endl;
    }
