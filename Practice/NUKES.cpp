#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
typedef long long lld;
typedef long ld;

//definition
#define vi vector < int >
#define vld vector < ld >
#define vlld vector < lld >
#define pii pair <int, int>
#define plld pair<lld, lld>
#define vpii vector< pii >
#define vplld vector< plld >

//important constants
#define MOD 1000000007
#define INF 1LL<<57LL
#define MAX 1000000
#define pi 3.14159265358979
#define ESP (1e-9)

//looping
#define fr(i,a) for(i=0;i<a;i++)
#define fe(i,a) for(i=0;i<=a;i++)
#define fu(i,a,n) for(i=a;i<n;i++)
#define fue(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>a;i--)
#define fde(i,n,a) for(i=n;i>=a;i--)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

//input output
#define sd(n) scanf("%d",&n)
#define sld(n) scanf("%ld",&n)
#define slld(n) scanf("%lld",&n)
#define pfd(n) printf("%d",n)
#define pfld(n) printf("%ld",n)
#define pflld(n) printf("%lld",n)

#define ff first
#define ss second
#define sz size()
#define clr clear()
#define len length()
#define pb push_back
#define mp make_pair
#define gcd(a,b)  __gcd(a,b)
#define all(vi) vi.begin(), vi.end()
#define mem(i,n) memset(i,n,sizeof(i))
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)

#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define ldmax numeric_limits<ld>::max()
#define ldmin numeric_limits<ld>::min()
#define lldmax numeric_limits<lld>::max()
#define lldmin numeric_limits<lld>::min()
//end of definition

int main()
{
    IOS;
    int a,n,k,i;
    vi v;
    cin>>a>>n>>k;
    double d;
    d=(log(a*1.0+1.0)/log((n+1)*1.0))-1;
    int c=ceil(d)+1;
    //cout<<"c:"<<c<<endl;
    int h=1;
    v.clear();
    if(c>k)
    {
        a=a%((int)pow(n+1,c));

    }

    while(a>0)
    {
        v.push_back(a%(n+1));
        a=a/(n+1);
        h++;
        if((h-1)==k) break;
    }

    fr(i,h)
    {
        cout<<v[i]<<" ";
    }
    fr(i,k-h-1)
    {
        cout<<"0 ";
    }
    cout<<endl;
    return 0;
}
