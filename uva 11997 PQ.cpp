#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Item
{
    int value;
    int pos;
    bool operator<(const Item &b)const{
        return value > b.value;
    }
};


int main()
{
    int n;

    while(cin>>n){
        int LA[800],LB[800];

        for(int i=0;i<n;++i)
            cin>>LA[i];
        sort(LA,LA+n);

        for(int i=1;i<n;++i){

            for(int j=0;j<n;++j)
                cin>>LB[j];
            sort(LB,LB+n);

            priority_queue<Item> PQ;

            for(int j=0;j<n;++j){
                Item temp;
                temp.value = LA[j] + LB[0];
                temp.pos = 0;
                PQ.push(temp);
            }

            for(int j=0;j<n;++j){
                Item temp = PQ.top();
                PQ.pop();
                LA[j] = temp.value;
                if(temp.pos+1<n){
                    temp.value = temp.value - LB[temp.pos] + LB[temp.pos+1];
                    temp.pos++;
                    PQ.push(temp);
                }
            }
        }
        cout<<LA[0];
        for(int i=1;i<n;++i)
            cout<<" "<<LA[i];
        cout<<endl;

    }
}
