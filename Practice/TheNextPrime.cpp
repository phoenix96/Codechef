#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int check_palindrome(char n[1000001])
{

}
int main()
{
    long long int t;
    char s[1000001];
    long long int l;
    scanf("%lld",&t);
    while(t--)
    {   int i=0;
        scanf("%s",&s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]!='9')
                break;
        }
        if(i==l)
        {
            strcpy(s,"");
            s[0]='1';
            for(int i=1;i<=l;i++)
                s[i]='0';
                s[l+1]='\0';
        }
        int k=strlen(s);
        while(true)
        {
            if(check_palindrome(s))
                break;
            else

        }
    }
    return 0;
}
