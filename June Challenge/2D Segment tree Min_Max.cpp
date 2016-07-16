#include <bits/stdc++.h>
using namespace std;
/* 2D Segment Tree node copied from STACK OVERFLOW*/
/* LINK: http://stackoverflow.com/questions/25121878/2d-segment-quad-tree-explanation-with-c*/
#define ll long long
#define Max 1001
#define INF (1 << 30)
ll P[Max][Max]; // container for 2D grid

struct Point {
    ll x, y, mx;
    Point() {}
    Point(ll x, ll y, ll mx) : x(x), y(y), mx(mx) {}

    bool operator < (const Point& other) const {
        return mx < other.mx;
    }
};

struct Segtree2d {
    Point T[16000001]; // TODO: calculate the accurate space needed
    ll n, m;
    // initialize and construct segment tree
    void init(ll n, ll m) {
        this -> n = n;
        this -> m = m;
        build(1, 1, 1, n, m);
    }

    // build a 2D segment tree from data [ (a1, b1), (a2, b2) ]
    // Time: O(n logn)
    Point build(ll node, ll a1, ll b1, ll a2, ll b2) {
        // out of range
        if (a1 > a2 or b1 > b2)
            return def();

        // if it is only a single index, assign value to node
        if (a1 == a2 and b1 == b2)
            return T[node] = Point(a1, b1, P[a1][b1]);

        // split the tree into four segments
        T[node] = def();
        T[node] = maxNode(T[node], build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
        T[node] = maxNode(T[node], build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
        T[node] = maxNode(T[node], build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
        T[node] = maxNode(T[node], build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
        return T[node];
    }

    // helper function for query(ll, ll, ll, ll);
    Point query(ll node, ll a1, ll b1, ll a2, ll b2, ll x1, ll y1, ll x2, ll y2) {
        // if we out of range, return dummy
        if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
            return def();

        // if it is within range, return the node
        if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2)
            return T[node];

        // split into four segments
        Point mx = def();
        mx = maxNode(mx, query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));

        // return the maximum value
        return mx;
    }

    // query from range [ (x1, y1), (x2, y2) ]
    // Time: O(logn)
    Point query(ll x1, ll y1, ll x2, ll y2) {
        return query(1, 1, 1, n, m, x1, y1, x2, y2);
    }

    // helper function for update(ll, ll, ll);
    Point update(ll node, ll a1, ll b1, ll a2, ll b2, ll x, ll y, ll value) {
        if (a1 > a2 or b1 > b2)
            return def();

        if (x > a2 or y > b2 or x < a1 or y < b1)
            return T[node];

        if (x == a1 and y == b1 and x == a2 and y == b2)
            return T[node] = Point(x, y, value);

        Point mx = def();
        mx = maxNode(mx, update(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x, y, value) );
        mx = maxNode(mx, update(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x, y, value));
        mx = maxNode(mx, update(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x, y, value));
        mx = maxNode(mx, update(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x, y, value) );
        return T[node] = mx;
    }

    // update the value of (x, y) index to 'value'
    // Time: O(logn)
    Point update(ll x, ll y, ll value) {
        return update(1, 1, 1, n, m, x, y, value);
    }

    // utility functions; these functions are virtual because they will be overridden in child class
    virtual Point maxNode(Point a, Point b) {
        return max(a, b);
    }

    // dummy node
    virtual Point def() {
        return Point(0, 0, -INF);
    }
};

/* 2D Segment Tree for range minimum query; a override of Segtree2d class */
struct Segtree2dMin : Segtree2d {
    // overload maxNode() function to return minimum value
    Point maxNode(Point a, Point b) {
        return min(a, b);
    }

    Point def() {
        return Point(0, 0, INF);
    }
};

// initialize class objects
Segtree2d Tmax;
long long sum[1001][1001];
int main() {
    ll n, m,q,a,b;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)
            {
                scanf("%lld", &P[i][j]);
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+P[i][j];
            }
    Tmax.init(n, m);
    scanf("%lld",&q);
    ll sol=0;
    ll sol2=0;
    ll temp=0;
    while(q--)
    {   sol=0;
        temp=LONG_LONG_MAX;
            scanf("%lld %lld",&a,&b);
                for(ll i = 1; i <= n-a+1; i++)
                    for(ll j = 1; j <= m-b+1; j++)
                    {
                        sol=Tmax.query(i,j,i+a-1,j+b-1).mx;
                        sol2=sum[i+a-1][j+b-1]-sum[i+a-1][j-1]-sum[i-1][j+b-1]+sum[i-1][j-1];
                        temp=min(sol*(a*b)-sol2,temp);
                    }
                    printf("%lld\n",temp);
    }
    return 0;
}
