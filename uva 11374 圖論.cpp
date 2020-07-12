#include <iostream>
#include <vector>
#define INF 999999
using namespace std;

struct node{
    int x;
    int y;
    int value;
};

void initial();
void input();
void Floyd_Warshall();
void find_path(int i, int j);
void show();

int number_of_node;
int s,e;
int medium[501][501];
int w[501][501];

vector<node> data;
vector<node> cem;

int t = 0;

int main()
{
    while(cin>>number_of_node>>s>>e){

        if(t==1)cout<<endl;
        t = 1;

        initial();
        input();
        Floyd_Warshall();

        int ans = w[s][e];
        int flag = 0;
        int new_p,new_q,new_value;
        int p,q,value;

        for(int i=0;i<cem.size();++i){
            p = cem[i].x;
            q = cem[i].y;
            value = cem[i].value;

            if(w[s][p]+w[q][e]+value<ans){
                ans = w[s][p]+w[q][e]+value;
                new_p = p;
                new_q = q;
                new_value = value;
                flag = 1;

            }
            if(w[s][q]+w[p][e]+value<ans){
                ans = w[s][p]+w[q][e]+value;
                new_p = q;
                new_q = p;
                new_value = value;
                flag = 1;

            }
        }

        if(flag==1){
            w[new_p][new_q] = new_value;
            medium[new_p][new_q] = -1;
            Floyd_Warshall();
            show();
            cout<<new_p<<endl;
            cout<<w[s][e]<<endl;
        }
        else{
            if(s==e)cout<<s<<endl;
            else show();
            cout<<"Ticket Not Used"<<endl;
            if(w[s][e]==INF)cout<<0<<endl;
            else cout<<w[s][e]<<endl;
        }

    }
    return 0;
}
void initial(){
    for (int i=1; i<=number_of_node; i++)
        for (int j=1; j<=number_of_node; j++){
            medium[i][j] = -1;
            if(i!=j)w[i][j] = INF;
            else w[i][j] = 0;
        }
    data.clear();
    cem.clear();
}
void input(){
    int count;
    int p,q,value;

    cin>>count;
    for(int i=0;i<count;++i){
        cin>>p>>q>>value;
        data.push_back((node){p,q,value});
        w[p][q] = w[q][p] = value;
    }

    cin>>count;
    for(int i=0;i<count;++i){
        cin>>p>>q>>value;
        cem.push_back((node){p,q,value});
    }
}
void Floyd_Warshall()
{
    for (int k=1; k<=number_of_node; k++)
        for (int i=1; i<=number_of_node; i++)
            for (int j=1; j<=number_of_node; j++){
                 if (w[i][k] + w[k][j] < w[i][j]){
                    w[i][j] = w[i][k] + w[k][j];
                    medium[i][j] = k;
                }
            }
}

void find_path(int i, int j)
{
    if (medium[i][j] == -1){return;}

    find_path(i, medium[i][j]);
    cout << medium[i][j]<<" ";
    find_path(medium[i][j], j);
}
void show()
{
    cout<<s<<" ";
    find_path(s, e);
    cout<<e<<endl;
}
