//Dijkstra算法是基于贪心策略的，求一点到其他所有点的最短路径的长度
//其时间复杂度为O（V²）
//需要注意的是dijkstra算法不支持带有负权重的路径

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int N=100;
const int inf=0x3f3f3f3f;
int dis_map[N][N],dist[N],pre[N],point_num,edge_num;
bool is_in[N];

void Dijkstra(int x){
    for(int i=1;i<=point_num;i++){
        dist[i]=dis_map[x][i];
        is_in[i]=false;
        //record pre node of i
        if(dist[i]==inf) pre[i]=-1;
        else pre[i]=x; 
    }
    is_in[x]=true;
    dist[x]=0;
    for(int i=1;i<=point_num;i++){
        int temp_min=inf,temp_select=x;
        for(int j=1;j<=point_num;j++){
            if(!is_in[j]&&dist[j]<temp_min){
                temp_select=j;
                temp_min=dist[j];
            }
        }
        if(temp_select==x) return;
        is_in[temp_select]=true;
        //update distance between points and chosen point set
        for(int j=1;j<=point_num;j++){
            if(!is_in[j]&&dis_map[temp_select][j]<inf){
                if(dist[j]>dist[temp_select]+dis_map[temp_select][j]){
                    dist[j]=dist[temp_select]+dis_map[temp_select][j];
                    pre[j]=temp_select;
                }
            }
        }
    }
}

int main(){
    int one,another,dis,start;
    cout<<"please input point num and edge num:"<<endl;
    cin>>point_num>>edge_num;
    cout<<"please input "<<edge_num<<" edges and the dis:"<<endl;
    memset(dis_map,inf,sizeof(dis_map));
    for(int i=1;i<=edge_num;i++){
        cin>>one>>another>>dis;
        dis_map[one][another]=min(dis_map[one][another],dis);
    }
    cout<<"please set the start point: "<<endl;
    cin>>start;

    cout<<point_num<<endl;
    Dijkstra(start);
    cout<<"start point is:"<<start<<endl;
    for(int i=1;i<=point_num;i++){
        cout<<"the min distance between "<<start<<" and "<<i<<" is:"<<dist[i]<<endl;
    }
    return 0;
}