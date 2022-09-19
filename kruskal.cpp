//在kruskal算法里面，需要用到并查集的知识（好像还挺简单的。。）
//这里在struct里面用cmp来比较来对边进行排序，需要O(logE)的时间
//总的时间复杂度为O（ElogE）
//这就说明了Kruskal算法适用于边比较稀疏而顶点较多的图

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define N 200005
int point_num,edge_num,ans=0,current_connect_num=0;
int boss[N];

struct node{
    int from,to,dis;
}edge[N];

//compare by val of edge
bool cmp(const node &a,const node &b){
    return a.dis<b.dis;
}

//find boss of x
int find_boss(int x){
    return boss[x]==x? x:find_boss(boss[x]);
}

//union two set
void union_set(int x,int y){
    boss[find_boss(y)]=find_boss(x);
}

int main(){
    cout<<"Please input point num and edge num:"<<endl;
    cin>>point_num>>edge_num;
    cout<<"Please input "<<edge_num<<" edges:"<<endl;
    for(int i=1;i<=edge_num;i++){
        cin>>edge[i].from>>edge[i].to>>edge[i].dis;
    }
    //init boss
    for(int i=1;i<=point_num;i++) boss[i]=i;

    sort(edge+1,edge+1+edge_num,cmp);
    for(int i=1;i<=edge_num;i++){
        if(current_connect_num==point_num-1) break;
        if(find_boss(edge[i].from)!=find_boss(edge[i].to)){
            //cout<<"select"<<edge[i].from<<"  "<<edge[i].to<<endl;
            //cout<<"boss from "<<find_boss(edge[i].from)<<" "<<find_boss(edge[i].to)<<endl;
            union_set(find_boss(edge[i].from),find_boss(edge[i].to));
            ans+=edge[i].dis;
            current_connect_num++;
        }
    }
    //for(int i=1;i<=7;i++) cout<<find_boss(i)<<" ";
    //cout<<endl;
    cout<<"the total cost is: "<<ans<<endl;
    return 0;
}