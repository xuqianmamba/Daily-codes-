#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int next_ [10000];
string S,T;
void get_next_(string T,int next_[10000]){
    int i=1,j=0;
    next_[1]=0;
    while (i<T.length())
    {      
        if(j==0||T[i]==T[j])//Partial match
            next_[++i]=++j;
        else j=next_[j];
    }
}
int Index_KMP(string S,string T,int next_[10000]){
    int i=1,j=1;
    while(i<=S.length()&&j<=T.length()){
        if(j==0||S[i]==T[j]){//continue compare
            ++i;
            ++j;
        }
        else j=next_[j];
    }
    if(j>T.length())//find
        return i-T.length();
    else
        return 0;
}
int main()
{
    cin>>S>>T;
    get_next_(T,next_);
    cout<<Index_KMP(S,T,next_);
    return 0;
}