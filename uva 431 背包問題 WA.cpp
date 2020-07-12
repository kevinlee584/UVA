#include <iostream>
#include <vector>
#include<sstream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct evidence{
    int Score, Time;
    string Description;
    bool operator < (evidence const &b) const{
        if(Time==b.Time)return Score > b.Score;
        return Time<b.Time;
    }
};

int main()
{
    vector<evidence> a;
    int t, max_hours, h, s, score[105][250];
    string str;
    evidence temp;

    cin>>t;

    while(t--){
        cin>>max_hours;
        getchar();
        a.clear();
        for(int i=0;i<=max_hours;++i) score[0][i] = 0;
        int flag = 0;
        while(true){
            getline(cin,str);
            if(str.size() == 0) break;
            stringstream in(str);
            in>>temp.Score>>temp.Time;
            getline(in, temp.Description);
            temp.Description.assign(temp.Description.begin()+1, temp.Description.end());
            a.push_back(temp);
            if(temp.Time<=max_hours) flag = 1;
        }
        int total_hours = 0;
        if(flag==1){
            sort(a.begin(), a.end());
            int n = 0;
            for(int i=0;i<a.size();++i){
                s = a[i].Score, h = a[i].Time;
                n++;
                for(int j=0;j<=max_hours;++j){
                    if(j<h) score[n][j] = score[n-1][j];
                    else score[n][j] = max(score[n-1][j], score[n-1][j-h]+s);
                }
            }
            printf("Score  Time  Description\n");
            printf("-----  ----  -----------\n");

            vector<evidence> ans;

            for(int x=n,y=max_hours;x!=0;--x){
                if(score[x][y]==score[x-1][y]) continue;
                ans.push_back(a[x-1]);y-=a[x-1].Time;
            }
            for(int i=ans.size()-1;i>=0;--i){
                printf("%3d%7d",ans[i].Score,ans[i].Time);
                cout<<"   "<<ans[i].Description<<endl;
                total_hours += ans[i].Time;
            }

            printf("\nTotal score: %d points\n",score[n][total_hours]);
            printf(" Total time: %d hours\n",total_hours);
		}
        else cout<<"There is not enough time to present any evidence. Drop the charges."<<endl;
        if(t) cout<<endl;
    }

    return 0;
}
