#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <iomanip>

#define Vector Point
using namespace std;

struct Point{
    double x, y;

    Point ():x(0), y(0){}
    Point (double a, double b):x(a), y(b){}

    bool operator <(const Point &b)const{
        return (x==b.x&&y<b.y)||x<b.x;
    }
    Vector operator +(Point b){
        return Vector(x+b.x, y+b.y);
    }
    Vector operator -(Point b){
        return Vector(x-b.x, y-b.y);
    }
    double length(const Point &b){
        return sqrt((x-b.x)*(x-b.x)+(y-b.y)*(y-b.y));
    }
};

double Cross(Vector A, Vector B){
    return A.x*B.y-A.y*B.x;
}
int ConvexHull(int n, Point *p, Point *tem){
    sort(p, p+n);
    int m = 0, start = 0, next;
    tem[m] = p[start];
    next = start;
    while(++m){
        for(int i=0;i<n;++i){
            double c = Cross(p[next]-tem[m-1], p[i]-tem[m-1]);
            if(c<0||(c==0&&tem[m-1].length(p[next])<tem[m-1].length(p[i])))
                next = i;
        }
        if(next==start) break;
        tem[m] = p[next];
    }
    return m;
}
double PolyonArea(Point* p,int n)
{
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}
bool isPointInPolygon(Point *p, int n, Point o){
    for(int i=0;i<n-1;++i){
        double c = Cross(p[i+1]-p[i], o-p[i]);
        if(c<0) return false;
    }
    return true;
}
int main()
{
    Point M[35][505], p[505], tem;
    int n, m, ind, used[35], coun[35];
    ind = 0;
    memset(used, 0, sizeof(used));
    while(cin>>n){
        if(n==-1) break;
        for(int i=0;i<n;++i)
            cin>>p[i].x>>p[i].y;
        m = ConvexHull(n, p, M[ind]);
        coun[ind] = m;
        ind++;
    }
    double area = 0;
    while(cin>>tem.x>>tem.y){
        for(int i=0;i<ind;++i){
            if(used[i]) continue;
            if(isPointInPolygon(M[i], coun[i], tem)){
                area += PolyonArea(M[i], coun[i]);
                used[i] = 1;
            }
        }
    }
    cout<<fixed;
    cout<<setprecision(2)<<area<<endl;
    return 0;
}
