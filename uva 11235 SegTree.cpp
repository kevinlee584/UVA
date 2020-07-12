#include <iostream>

#define Max 100000

using namespace std;

struct node
{
    struct node *Lc,*Rc;
    int max_value;
};

typedef struct node* node_pointer;

struct segment
{
    int L,R;
    int value;
};

void BuildTree(node_pointer *O,int L,int R);
int QueryMax(node_pointer O,int L,int R,int QR,int QL);
void destroytree(node_pointer O,int L,int R);

int sequence[Max+1];
int index[Max*2+1];
node_pointer root;
segment seg[Max+1];

int main()
{
    int time;
    int number_of_node;

    while(cin>>number_of_node&&number_of_node){

        cin>>time;

        for(int i=1;i<=number_of_node;++i) cin>>sequence[i];

        int cnt = 0;
        int last = 1;

        for(int i=1;i<=number_of_node;++i){

            if(sequence[last]!=sequence[i]){
                cnt++;
                index[Max+sequence[last]] = cnt;
                seg[cnt].L = last;
                seg[cnt].R = i - 1;
                seg[cnt].value = i - last;
                last = i;
            }
        }

        cnt++;
        index[Max+sequence[last]] = cnt;
        seg[cnt].L = last;
        seg[cnt].R = number_of_node;
        seg[cnt].value = number_of_node - last + 1;

        BuildTree(&root,1,cnt);

        while(time--){
            int ql,qr,most_times;

            cin>>ql>>qr;
            int indexL = index[sequence[ql]+Max];
            int indexR = index[sequence[qr]+Max];

            if(indexL!=indexR){
                most_times = max((seg[indexL].R-ql+1), (qr-seg[indexR].L+1));

                if(indexL+1<=indexR-1)
                    most_times = max(most_times,QueryMax(root,1,cnt,indexL+1,indexR-1));
            }
            else
                most_times = qr - ql +1;


            cout<<most_times<<endl;
        }
        destroytree(root,1,cnt);

    }
}
void BuildTree(node_pointer *O,int L,int R)
{
    node_pointer temp = new node;

    if(L==R){
        temp->max_value = seg[L].value;
        *O = temp;
        return;
    }

    int M = (L+R)/2;
    BuildTree(&temp->Lc, L , M);
    BuildTree(&temp->Rc, M+1 ,R);
    temp->max_value = max(temp->Lc->max_value,temp->Rc->max_value);
    *O = temp;
}
void destroytree(node_pointer O,int L,int R)
{
    if(L!=R){
        int M = (L+R)/2;
        destroytree(O->Lc,L,M);
        destroytree(O->Rc,M+1,R);
    }
    delete O;
}


int QueryMax(node_pointer O,int L,int R,int QL,int QR)
{
    if(R<QL||QR<L)return 0;
    if(QL<=L&&R<=QR) return O->max_value;

    int M = (L+R)/2;
    int Lime_L = QueryMax(O->Lc, L, M, QL, QR);
    int Limt_R = QueryMax(O->Rc, M+1, R, QL, QR);

    return max(Lime_L, Limt_R);
}
