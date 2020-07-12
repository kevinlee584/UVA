#include <iostream>
#include <vector>
#include <algorithm>
#define Vector Point

using namespace std;

struct Point{
    int x, y, pos;
    Point():x(0), y(0){}
    Point(int a, int b):x(a), y(b){}
    bool operator <(const Point &b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }

};
Vector operator +(const Vector &a, const Vector &b){
    return Vector(a.x+b.x, a.y+b.y);
}
Vector operator -(const Vector &a, const Vector &b){
    return Vector(a.x-b.x, a.y-b.y);
}
int Cross(const Vector &a, const Vector &b){
    return a.x*b.y-a.y*b.x;
}
int Dot(const Vector &a, const Vector &b){
    return a.x*b.x+a.y*b.y;
}
bool far(Point O, Point a, Point b){
    int x1 = a.x-O.x; x1 *= x1;
    int x2 = b.x-O.x; x2 *= x2;
    int y1 = a.y-O.y; y1 *= y1;
    int y2 = b.y-O.y; y2 *= y2;
    return (x1+y1)<(x2+y2);
}
int ConvexHull(Point *p, int n, Point *ch){
    int m, start, next, c;
    sort(p, p+n);
    start = 0; m = 0; next = start;
    ch[m] = p[start];

    while(true){
        m++;
        for(int i=0;i<n;++i){
            c = Cross(p[next]-ch[m-1], p[i]-ch[m-1]);
            if(c<0||((c==0)&&far(ch[m-1], p[next], p[i])))
                next = i;
        }
        if(next==start) break;
        ch[m] = p[next];
    }
    ch[m] = p[0];
    m++;
    return m;
}

int main()
{
    int n, m;
    Point mass, p[1000], ch[1000];
    while(true){
        string name;
        while(name.empty())getline(cin, name);
        if(name[0]=='#') break;

        cin>>mass.x>>mass.y;
        n = 0;
        while(true){
            cin>>p[n].x>>p[n].y;
            p[n].pos = n+1;
            if(p[n].x==0&&p[n].y==0) break;
            n++;
        }
        m = ConvexHull(p, n, ch);
        int Ans = n, nMax;
        for(int i=0;i<m-1;++i){
            if(Cross(mass-ch[i], ch[i+1]-ch[i])>0) continue;
            if(Dot(mass-ch[i], ch[i+1]-ch[i])<0) continue;
            if(Dot(mass-ch[i+1], ch[i]-ch[i+1])<0) continue;
            nMax = max(ch[i].pos, ch[i+1].pos);
            Ans = min(Ans, nMax);
        }

        cout<<name<<' '<<Ans<<endl;
    }
    return 0;
}

