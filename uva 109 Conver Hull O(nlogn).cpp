#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#define Vector Point

using namespace std;

const int N = 35;
const int M = 505;

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
double PolyArea(Point *ch, int n){
    double area = 0;
    for(int i=1;i<n-1;++i)
        area += Cross(ch[i]-ch[0], ch[i+1]-ch[0]);
    return area/2;
}
int ConverHull(int n, Point *ch){
    int Min = 0;
    for(int i=1;i<n;++i)
        if(compare_position(p[i], p[Min]))
            Min = i;

    swap(p[0], p[Min]);
    sort(p+1, p+n, compare_angle);

    int m = 0;
    for(int i=0;i<n;++i){
        while(m>1&&Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0){
            m--;
        }
        ch[m++] = p[i];
    }
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
    int n, m, coun[N], ind = 0, used[N];
    Point ch[N][M], tem;
    memset(used, 0, sizeof(used));

    while(cin>>n){
        if(n==-1) break;
        for(int i=0;i<n;++i)
            cin>>p[i].x>>p[i].y;
        m = ConverHull(n, ch[ind]);
        coun[ind] = m;
        ind++;
    }
    double area = 0;
    while(cin>>tem.x>>tem.y){
        for(int i=0;i<ind;++i){
            if(used[i]) continue;
            if(!isPointInPolygon(ch[i], tem, coun[i])) continue;
            area += PolyArea(ch[i], coun[i]);
            used[i] = 1;
        }
    }
    cout<<fixed;
    cout<<setprecision(2)<<area<<endl;

}
