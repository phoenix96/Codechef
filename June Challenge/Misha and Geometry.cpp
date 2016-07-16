/*
CONVEX HULL IMPLEMENTATION FROM GEEKS4GEEKS.ORG
POLYGON AREA : http://alienryderflex.com/polygon_area/
*/
#include <bits/stdc++.h>
using namespace std;
vector<long long> ax;
vector<long long> ay;
struct Point
{
    int x, y;
};
stack<Point> S;
double polygonArea(int p) {

  double  area=0.0;
  int i,j=p-1;
  for (i=0; i<p; i++)
    {
        area+=(ax.at(j)+ax.at(i))*(ay.at(j)-ay.at(i));
        j=i;
    }
  return area*.5;
}
vector<Point> points;
vector<Point> in;
Point p0;
bool operator==(const Point& lhs, const Point& rhs)
{
    if(lhs.x==rhs.x&&lhs.y==rhs.y)
        return true;
    return false;
}

Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return ( distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
   return (o == 2)? -1: 1;
}
double convexHull(int n)
{
   int ymin = points.at(0).y, mi = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points.at(i).y;
    if ((y < ymin) || (ymin == y && points.at(i).x < points.at(mi).x))
        ymin = points.at(i).y, mi = i;
   }
   swap(points.at(0), points.at(mi));
   p0 = points.at(0);
   qsort(&points.at(1), n-1, sizeof(Point), compare);
   int m = 1;
   for (int i=1; i<n; i++)
   {
        while (i < n-1 && orientation(p0, points.at(i),points.at(i+1)) == 0)
        i++;
        points.at(m) = points.at(i);
        m++;
   }
   if (m < 3) return 0.0;
   S.push(points.at(0));
   S.push(points.at(1));
   S.push(points.at(2));
   for (int i = 3; i < m; i++)
   {
      while (orientation(nextToTop(S), S.top(), points.at(i)) != 2)
      S.pop();
      S.push(points.at(i));
   }
   //cout<<"ap1"<<endl;
    int i=0,j=0;
    ax.clear();
    ay.clear();
    while (!S.empty())
        {
            Point p = S.top();
            //cout<<p.x<<" "<<p.y<<endl;
            ax.push_back(p.x);
            ay.push_back(p.y);
            S.pop();
        }
       // cout<<"aa1"<<endl;
    return abs(polygonArea( ax.size() ));
}
int main()
{
    long long t,inx,iny,po;
    char sig;
    cin>>t;
    int w;
    while(t--)
    {   w=0;
        points.clear();
        cin>>po;
        while(po--)
        {
        cin>>sig>>inx>>iny;
        Point m;
        m.x=inx;
        m.y=iny;
        //cout<<"in taken"<<endl;
        if(sig=='+')
            {
                points.push_back(m);
            }
        else
        {
            vector<Point>::iterator position = find(points.begin(), points.end(), m);
            if (position!=in.end())
                    {
                        points.erase(position);
                    }
        }
        if(points.size()<3)
            cout<<"0.0\n";
        else
            {
                double sol=convexHull(points.size());
                cout<<fixed<<setprecision(1)<<sol<<endl;
            }

        }
    }
    return 0;
}
