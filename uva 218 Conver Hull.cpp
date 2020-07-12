#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <math.h>
#define Vector Point

using namespace std;

const int M = 2000;

struct Point{
    Point():x(0), y(0){}
    Point(double a, double b):x(a), y(b){}
    double x, y;
}p[M];

Vector operator + (Vector a, Vector b){
    return Vector(a.x+b.x, a.y+b.y);
}
Vector operator - (Vector a, Vector b){
    return Vector(a.x-b.x, a.y-b.y);
}
double Dot(Vector A, Vector B){
    return A.x*B.x+A.y+B.y;
}
double Cross(Vector A, Vector B){
    return A.x*B.y-A.y*B.x;
}
bool compare_length(Vector A, Vector B){
    return (A.x*A.x+A.y*A.y)<(B.x*B.x+B.y*B.y);
}
bool compare_position(Point A, Point B){
    return A.x<B.x||(A.x==B.x&&A.y<B.y);
}
bool compare_angle(Point A, Point B){
    double c = Cross(A-p[0], B-p[0]);
    return c>0||(c==0&&compare_length(A-p[0], B-p[0]));
}
double length2(Point A, Point B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double PolyArea(Point *ch, int n){
    double area = 0;
    for(int i=1;i<n-1;++i)
        area += Cross(ch[i]-ch[0], ch[i+1]-ch[0]);
    return area/2;
}
int ConverHull(int n, Point *ch){
    swap(p[0], *min_element(p, p+n, compare_position));
    sort(p+1, p+n, compare_angle);

    int m = 0;
    for(int i=0;i<n;++i){
        while(m>1&&Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0){
            m--;
        }
        ch[m++] = p[i];
    }
    ch[m] = p[0];
    m++;
    return m;
}
bool isPointInPolygon(Point *ch, Point t, int n){
    for(int i=0;i<n-1;++i)
        if(Cross(ch[i+1]-ch[i], t-ch[i])<0)
            return false;
    return true;
}
int main()
{
    int n, m, t = 1;
    Point ch[M];
    while(cin>>n&&n){
        for(int i=0;i<n;++i)
            cin>>p[i].x>>p[i].y;
        m = ConverHull(n, ch);
        double ans = 0;
        if(t!=1) cout<<endl;
        cout<<"Region #"<<t<<":"<<endl;
        cout<<fixed;
        cout<<setprecision(1)<<"("<<ch[m-1].x<<","<<ch[m-1].y<<")";
        for(int i=m-2;i>=0;--i){
            cout<<setprecision(1)<<"-("<<ch[i].x<<","<<ch[i].y<<")";
            ans += length2(ch[i+1], ch[i]);
        }
        cout<<endl;
        cout<<"Perimeter length = "<<setprecision(2)<<ans<<endl;
        t++;
    }



}
