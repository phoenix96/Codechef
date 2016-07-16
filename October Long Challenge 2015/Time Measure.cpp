#include<math.h>
#include<iostream>
#include<stdio.h>
#define fast ios_base::sync_with_stdio(false);
using namespace std;
int main()
{   fast
    int t;
    float a,d;
    cin>>t;
    while(t--)
    {float an;
        cin>>a;
        for(int h=0;h<12;h++)
        {
            for(int m=0;m<60;m++)
            {
             an=(m*6.0000)-(h*30.0000+m*0.5);
             if(an<0) an=-an;
             if(an>180) an=360-an;
             d=an-a;
             if(d<0) d=-d;
             if(d<=(1/120.00))
             {
                 printf("%02d:%02d\n",h,m);
             }
            }
        }
    }
    return 0;
}
 
 