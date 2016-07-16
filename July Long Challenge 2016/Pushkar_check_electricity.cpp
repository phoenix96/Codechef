#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define LI long int
#define LLI long long int
#define ULLI unsigned long long int
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sf(n) scanf("%f",&n)
#define sli(n) scanf("%ld",&n)
#define slli(n) scanf("%lld",&n)
#define sulli(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define pi(n) printf("%d",n)
#define pf(n) printf("%f",n)
#define plli(n) printf("%lld",n)
#define pulli(n) printf("%llu",n)
#define pd(n) printf("%lf",n)
#define ss(n) scanf("%s",n)
#define pln printf("\n")
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}

int main()
{
int t;
si(t);
while(t--)
{
LLI n;
slli(n);
LLI i,j,k,arr1[n],arr2[n],wire=0;
char str[n+1];
cin>>str;

FOR(i,0,n)
arr1[i] = str[i] - '0';

FOR(i,0,n)
slli(arr2[i]);

LLI next,prev,first;

for(int i=0;i<n;i++)
{
	if(arr1[i]==1)
        break;
}
cout<<"i"<<i<<endl;
cout<<"wire initially "<<wire<<endl;
wire=wire+arr2[i]-arr2[0];
cout<<"wire after left part "<<wire<<endl;
prev=i;
first=i;
for(i=first;i<n;)
{
	for(j=i+1;j<n;j++)
	{
	if(arr1[j]==1)
	break;
	else
	continue;
	}
	if(j==n)
	{
		wire=wire+arr2[j-1]-arr2[i];
		break;
	}
	else
	{
		next=j;
		k=i;
		while(k!=j-1)
		{
			if(arr2[k+1]-arr2[k]>arr2[j]-arr2[j-1])
		{
			wire=wire+arr2[j]-arr2[j-1];
			j--;
		}
		else
		{
			wire=wire+arr2[k+1]-arr2[k];
			k++;
		}
		}
		i=next;
	}
}
cout<<wire<<endl;
}
return 0;
}
