#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct Building{
    int id;
    double x, y, w, d, h;
    bool operator < (const Building &b)const{
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};

void getdata();
void solve();
bool judge(Building temp);

vector<Building> input;
int n;

int main() {
    int t = 1;
    while(cin>>n&&n){
        if(t!=1)cout<<endl;
        getdata();
        cout<<"For map #"<<t<<", the visible buildings are numbered as follows:"<<endl;
        solve();
        t++;
        input.clear();
    }

    return 0;
}
void getdata(){
    Building temp;

    for(int i=1;i<=n;++i){
        cin>>temp.x>>temp.y>>temp.w>>temp.d>>temp.h;
        temp.id = i;
        input.push_back(temp);
    }

    sort(input.begin(),input.end());
}

void solve(){
    int t=0;
    for(int i=0;i<n;++i)
        if(judge(input[i])){
            if(t==1)cout<<" ";
            cout<<input[i].id;
            t=1;
        }
    cout<<endl;
}

bool judge(Building temp){
    for(int j=0;j<n;++j){
        if(temp.y<=input[j].y)continue;
        if(temp.x>=(input[j].x+input[j].w))continue;
        if((temp.x+temp.w)<=input[j].x)continue;
        if(temp.h>input[j].h)continue;

        if(temp.x<input[j].x)return true;
        else if(input[j].x+input[j].w>=temp.x+temp.w)return false;
        else{
            temp.w = temp.x + temp.w - input[j].x - input[j].w;
            temp.x = input[j].x + input[j].w;
        }
    }
    return true;
}

