#include <iostream>

using namespace std;

struct data{
    int l,r;
    int prefix,suffix;
    int Maxpre,Maxsuf;
};

void buildtree(int o,int l,int r);
data query(int o,int l,int r);
data MakeData(data a,data b);

data segment[500005*4];
long long int sum[500005];

int main()
{
    sum[0] = 0;
    int Case = 1;
    int n,m;

    while(cin>>n>>m){
        for(int i=1;i<=n;++i){
            cin>>sum[i];
            sum[i] += sum[i-1];
        }

        buildtree(1,1,n);
        cout<<"Case"<<" "<<Case<<":"<<endl;
        Case++;
        for(int i=0;i<m;++i){
            int ql,qr;
            cin>>ql>>qr;
            data ans = query(1,ql,qr);
            cout<<ans.Maxpre<<" "<<ans.Maxsuf<<endl;
        }

    }

}

long long int getSum(int l,int r){
    return sum[r] - sum[l-1];
}

void buildtree(int o,int l,int r){
    if(l==r){
        segment[o].l = segment[o].r = l;
        segment[o].prefix = segment[o].suffix = l;
        segment[o].Maxpre = segment[o].Maxsuf = l;
        return;
    }
    int m = (l+r)/2;
    buildtree(o*2,l,m);
    buildtree(o*2+1,m+1,r);
    segment[o] = MakeData(segment[o*2],segment[o*2+1]);
}

bool compare(int x,int y,int a,int b){
    long long int sa = getSum(x,y);
    long long int sb = getSum(a,b);

    if(sa!=sb)return sa<sb;
    if(a==x) return y>b;
    return x>a;
}

data MakeData(data a,data b){
    data NewData;

    NewData.l = a.l;
    NewData.r = b.r;
    NewData.Maxpre = a.suffix;
    NewData.Maxsuf = b.prefix;

    if(compare(NewData.Maxpre,NewData.Maxsuf, a.Maxpre,a.Maxsuf))
        {NewData.Maxpre = a.Maxpre; NewData.Maxsuf = a.Maxsuf;}
    if(compare(NewData.Maxpre,NewData.Maxsuf, b.Maxpre,b.Maxsuf))
        {NewData.Maxpre = b.Maxpre; NewData.Maxsuf = b.Maxsuf;}

    NewData.prefix = a.prefix;
    if(compare(NewData.l,NewData.prefix,NewData.l,b.prefix))
        NewData.prefix = b.prefix;

    NewData.suffix = b.suffix;
    if(compare(NewData.suffix,NewData.r,a.suffix,NewData.r))
        NewData.suffix = a.suffix;

    return NewData;
}

data query(int o,int l,int r){
    if(l<=segment[o].l&&segment[o].r<=r)
        return segment[o];

    int m = (segment[o].l+segment[o].r)/2;

    if(l<=m&&m<r)
        return MakeData(query(o*2,l,r),query(o*2+1,l,r));
    else if(r<=m)
        return query(o*2,l,r);
    else
        return query(o*2+1,l,r);
}
