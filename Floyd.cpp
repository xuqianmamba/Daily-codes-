//Flotd算法是计算N个点中任意两个点之间的最短距离，其时间复杂度为O（V3）

#include <bits/stdc++.h>
using namespace std;
#define N 1000
const int inf=0x3f3f3f3f;
int edge[N][N],point_num,edge_num;
int main(){
    int one_point,another_point,dis;
    cout<<"Please input point num and edge num:"<<endl;
    cin>>point_num>>edge_num;
    cout<<"Please input "<<edge_num<<" edges:"<<endl;
    memset(edge,inf,sizeof(edge));
    for(int i=1;i<=point_num;i++) edge[i][i]=0;
    for(int i=1;i<=edge_num;i++){
        cin>>one_point>>another_point>>dis;
        edge[one_point][another_point]=min(edge[one_point][another_point],dis);
        edge[another_point][one_point]=min(edge[another_point][one_point],dis);
    }
    for(int k=1;k<=point_num;k++)
        for(int i=1;i<=point_num;i++)
            for(int j=1;j<=point_num;j++)
                if(edge[i][j]>edge[i][k]+edge[k][j]) edge[i][j]=edge[i][k]+edge[k][j];
    for(int i=1;i<=point_num;i++)
        for(int j=1;j<=point_num;j++)
            cout<<"The min dis between "<<i<<" and "<<j<<" is: "<<edge[i][j]<<endl;
    return 0;    
}