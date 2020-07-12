#include <iostream>

using namespace std;

#define N 501
#define INF 999999

struct ans
{
    int Max_value;
    int Min_value;
}Ans;

int n;
int Max[N*3][N*3];
int Min[N*3][N*3];
int x_is_leaf[N*3];
int xl,xr,yl,yr;
int X,Y,Value;

void build_1D(int xo,int o,int l,int r,int x);
void build_2D(int o,int l,int r);
void query_1D(int xo,int o,int l,int r);
void query_2D(int o,int l,int r);
void modify(){build_2D(1,1,n);}
void query(){
    Ans.Max_value = -INF;
    Ans.Min_value = INF;
    query_2D(1,1,n);
    cout<<Ans.Max_value<<" "<<Ans.Min_value<<endl;
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            X = i;
            Y = j;
            cin>>Value;
            modify();
        }

    int count;
    cin>>count;

    while(count--){
        char c;
        cin>>c;

        switch(c){
            case'q':
                cin>>xl>>yl>>xr>>yr;
                query();
                break;
            case'c':
                cin>>X>>Y>>Value;
                modify();
                break;
            default:
                break;
        }
    }

    return 0;

}

void build_1D(int xo,int o,int l,int r){

    if(l==r){
        if(x_is_leaf[xo]){
            Max[xo][o] = Value;
            Min[xo][o] = Value;
            return;
        }
        Max[xo][o] = max(Max[xo*2][o],Max[xo*2+1][o]);
        Min[xo][o] = min(Min[xo*2][o],Min[xo*2+1][o]);
    }
    else{
        int m = (l+r)/2;
        if(Y<=m)build_1D(xo,o*2,l,m);
        else build_1D(xo,o*2+1,m+1,r);

        Max[xo][o] = max(Max[xo][o*2],Max[xo][o*2+1]);
        Min[xo][o] = min(Min[xo][o*2],Min[xo][o*2+1]);
    }
}
void build_2D(int o,int l,int r){

    if(l==r){
        x_is_leaf[o] = 1;
        build_1D(o,1,1,n);
    }
    else{
        int m = (l+r)/2;
        if(X<=m)build_2D(o*2,l,m);
        else build_2D(o*2+1,m+1,r);

        x_is_leaf[o] = 0;
        build_1D(o,1,1,n);
    }
}
void query_1D(int xo,int o,int l,int r){

    if(yl<=l&&r<=yr){
        Ans.Max_value = max(Ans.Max_value,Max[xo][o]);
        Ans.Min_value = min(Ans.Min_value,Min[xo][o]);
    }
    else{
        int m = (l+r)/2;
        if(yl<=m)query_1D(xo,o*2,l,m);
        if(m<yr)query_1D(xo,o*2+1,m+1,r);
    }
}
void query_2D(int o,int l,int r){

    if(xl<=l&&r<=xr){
         query_1D(o,1,1,n);
    }
    else{
        int m = (l+r)/2;
        if(xl<=m)query_2D(o*2,l,m);
        if(m<xr)query_2D(o*2+1,m+1,r);
    }
}
