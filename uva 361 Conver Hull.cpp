#include <iostream>
#include <algorithm>
#define Vector Point

using namespace std;
const int N = 1<<20;
struct Point{
    Point():x(0), y(0){}
    Point(double a, double b):x(a), y(b){}
    double x, y;
}S[N];
Vector operator + (Vector A, Vector B){
    return Vector(A.x+B.x, A.y+B.y);
}
Vector operator - (Vector A, Vector B){
    return Vector(A.x-B.x, A.y-B.y);
}
bool operator == (Point A, Point B){
    return A.x==B.x&&A.y==B.y;
}
bool operator != (Point A, Point B){
    return A.x!=B.x||A.y!=B.y;
}
double Cross(Vector A, Vector B){
    return A.x*B.y-A.y*B.x;
}
double Dot(Vector A, Vector B){
    return A.x*B.x+A.y*B.y;
}
bool  compare_length(Vector A, Vector B){
    return A.x*A.x+A.y*A.y<B.x*B.x+B.y*B.y;
}
bool compare_position(Vector A, Vector B){
    return A.x<B.x||(A.x==B.x&&A.y<B.y);
}
bool compare_angle(Vector A, Vector B){
    double c = Cross(A-S[0], B-S[0]);
    return c>0||(c==0&&compare_length(A-S[0], B-S[0]));
}
int ConverxHull(Point *p, int n, Point *ch){
    swap(p[0], *min_element(p, p+n, compare_position));
    sort(p+1, p+n, compare_angle);
    int m = 0;
    for(int i=0;i<n;++i){
        while(m>1&&Cross(p[i]-ch[m-2], ch[m-1]-ch[m-2])>=0) m--;
        ch[m++] = p[i];
    }
    //for(int i=0;i<m;++i) cout<<ch[i].x<<" "<<ch[i].y<<endl;
    return m;
}
bool On(Point o, Point A, Point B){
    if(A==o||B==o) return true;
    if(A==B&&A!=o) return false;

    if(Cross(o-A, B-A)==0&&compare_length(o-B, A-B)&&compare_length(o-A, B-A)) return true;
    else return false;
}
bool isPointInpolygon(Point *ch, int m, Point t){
    if(m==2) return On(t, ch[0], ch[1]);
    for(int i=0;i<m-1;++i)
        if(Cross(t-ch[i], ch[i+1]-ch[i])>0) return false;
    if(Cross(t-ch[m-1], ch[0]-ch[m-1])>0) return false;
    return true;
}
int main()
{
    int m, c, r, o, coun[5], t = 1;
    Point M[5][205], tem;

    while(cin>>c>>r>>o){
        if(c==0&&r==0&&o==0) break;

        for(int i=0;i<c;++i) cin>>S[i].x>>S[i].y;
        if(c>2){
            m = ConverxHull(S, c, M[0]);
            coun[0] = m;
        }

        for(int i=0;i<r;++i) cin>>S[i].x>>S[i].y;
        if(r>2){
            m = ConverxHull(S, r, M[1]);
            coun[1] = m;
        }

        cout<<"Data set "<<t<<":"<<endl;
        for(int i=0;i<o;++i){
            cin>>tem.x>>tem.y;
            cout<<"     ";
            if(c>2&&isPointInpolygon(M[0], coun[0], tem))
                cout<<"Citizen at ("<<tem.x<<","<<tem.y<<") is safe."<<endl;
            else if(r>2&&isPointInpolygon(M[1], coun[1], tem))
                cout<<"Citizen at ("<<tem.x<<","<<tem.y<<") is robbed."<<endl;
            else cout<<"Citizen at ("<<tem.x<<","<<tem.y<<") is neither."<<endl;
        }
        cout<<endl;
        t++;
    }
    return 0;

}
