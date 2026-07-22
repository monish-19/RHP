#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    int row=1,col=1;
    int diff[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    int R=mat.size(),C=mat[0].size(),sum=0;
    for(int i=0;i<8;i++){
        int nr=row+diff[i][0];
        int nc=col+diff[i][1];
        if(nr>=0&&nr<R&&nc>=0&&nc<C)
            sum+=mat[nr][nc];
    }
    cout<<sum;
    return 0;
}