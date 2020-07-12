#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdio>
#define Vector Point

using namespace std;

const int M = 1000;

struct Point{
    Point():x(0), y(0){}
    Point(double a, double b):x(a), y(b){}
    double x, y;
    int pos;
}p[M];

Vector operator + (Vector a, Vector b){
    return Vector(a.x+b.x, a.y+b.y);
}
Vector operator - (Vector a, Vector b){
    return Vector(a.x-b.x, a.y-b.y);
}
bool operator == (Point a, Point b){
    return a.x==b.x&&a.y==b.y;
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
    return A.x>B.x||(A.x==B.x&&A.y<B.y);
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
        while(m>1&&(Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<0||ch[m-1]==p[i])){
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
    int n, nn, m, ind, t = 0;
    Point ch[M];
    string str, name;
    while(cin>>str){
        if(str=="END"){
            if(t!=0){
                m = ConverHull(nn, ch);
                cout<<name<<" convex hull:"<<endl;
                for(int i=0;i<m;++i) cout<<" ("<<ch[i].x<<","<<ch[i].y<<")";
                cout<<endl;
            }
            break;
        }
        else if(str=="S"){
            if(t!=0){
                m = ConverHull(nn, ch);
                cout<<name<<" convex hull:"<<endl;
                for(int i=0;i<m;++i) cout<<" ("<<ch[i].x<<","<<ch[i].y<<")";
                cout<<endl;
            }
            getchar();
            getline(cin, name);
            nn = 0;
            ind = 0;
            t++;
        }
        else if(str=="P"){
            cin>>n;
            for(int i=0;i<n;++i){
                cin>>p[nn].x>>p[nn].y;
                p[nn].pos = ind;
                nn++;
            }
            ind++;
        }
    }


}
