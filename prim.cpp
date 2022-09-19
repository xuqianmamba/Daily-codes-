//前提：边E，点V，复杂度O（v²）
//所以适合求解边稠密的情况
// data:
7 12
1 2 23 
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25
#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
const int N = 1e3+4;
int dis[N][N];
int closest[N];
int low[N];
bool is_in[N]={false};

void prim(int n,int now_node){
    is_in[now_node]=true;
    int min_dis=0x3f3f3f3f;
    int min_id=-1;
    for(int i=1;i<=n;i++){
        if(!is_in[i]){
            if(dis[i][now_node]<low[i]) low[i]=dis[i][now_node];
            if(low[i]<min_dis) 
            {
                min_id=i;
                min_dis=low[i];
            }
        }
    }
    if(min_id==-1) return;
    prim(n,min_id);
    return;
} 

int main(){
    int n,m,x,y,z,first_node;
    int sumcost=0;
    memset(dis,inf,sizeof(dis));
    memset(low,inf,sizeof(low));
    cout<<"please input number of nodes n and the number of edges m:"<<endl;
    cin>>n>>m;
    cout<<"please input point x,y and value z:"<<endl;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        dis[x][y]=z;
        dis[y][x]=z;
    }
    cout<<"please select init node first_node:"<<endl;
    cin>>first_node;
    low[first_node]=0;
    prim(n,first_node);
    cout<<"member in low is:"<<endl;
    for(int i=1;i<=n;i++)cout<<low[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) sumcost+=low[i];
    cout<<"min cost is "<<sumcost<<endl;
    return 0;
}