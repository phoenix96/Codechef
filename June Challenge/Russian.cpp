/*
CONVEX HULL : http://e-maxx.ru/algo/convex_hull_graham
POLYGON AREA : http://alienryderflex.com/polygon_area/
*/
#include <bits/stdc++.h>
using namespace std;
struct pt
{
    double x, y;
};
vector<pt> points;
bool cmp (pt a, pt b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c)
{
    return a.x*(b.y-c.y)*1.0+b.x*(c.y-a.y)*1.0+c.x*(a.y-b.y)*1.0 < 0.0;
}

bool ccw (pt a, pt b, pt c)
{
    return a.x*(b.y-c.y)*1.0+b.x*(c.y-a.y)*1.0+c.x*(a.y-b.y)*1.0 > 0.0;
}
double polygonArea(vector<pt> p)
{

    double  area=0;
    int i,j=p.size()-1;
    for (i=0; i<p.size(); i++)
    {
        area+=(p[j].x+p[i].x)*(p[j].y-p[i].y);
        j=i;
    }
    return area*.5;
}
double convex_hull (vector<pt> a)
{
    if (a.size() < 3)  return 0.0;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i)
    {
        if (i==a.size()-1 || cw (p1, a[i], p2))
        {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2))
        {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    a.clear();
    for (size_t i=0; i<up.size(); ++i)
        a.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        a.push_back (down[i]);
//    for(size_t i=0;i<a.size();i++)
//        cout<<a[i].x<<" "<<a[i].y<<endl;
    return abs(polygonArea(a));
}
bool operator==(const pt& lhs, const pt& rhs)
{
    if(lhs.x==rhs.x&&lhs.y==rhs.y)
        return true;
    return false;
}
int main()
{
    double t,inx,iny,po;
    char sig;
    cin>>t;
    pt m;
    while(t--)
    {
        points.clear();
        cin>>po;
        while(po--)
        {
            cin>>sig>>inx>>iny;
            m.x=inx;
            m.y=iny;
            if(sig=='+')
            {
                points.push_back(m);
            }
            else
            {
                vector<pt>::iterator it = find(points.begin(), points.end(), m);
                if (it != points.end())
                {
                    iter_swap(it, points.end() - 1);
                    points.erase(points.end() - 1);
                }
            }
            cout<<fixed<<setprecision(1)<<convex_hull(points)<<endl;

        }
    }
    return 0;
}
