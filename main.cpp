#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Sofa
{
public:
    int fsr,fsc,ssr,ssc;
    char dir;
    int moves;

    Sofa(int fsr,int fsc,int ssr,int ssc,char dir,int moves)
    {
        this->fsr=fsr;
        this->fsc=fsc;
        this->ssr=ssr;
        this->ssc=ssc;
        this->dir=dir;
        this->moves=moves;
    }
};

string delim="-";
bool canAdd(int fsr,int fsc,int ssr,int ssc,unordered_set<string> &visited)
{
    string key = to_string(fsr) + delim + to_string(fsc) + delim + to_string(ssr) + delim + to_string(ssc);
    if(visited.find(key)!=visited.end())
    {
        return false;
    }
    visited.insert(key);
    return true;
}

int main()
{
    int R,C;cin>>R>>C;
    int fsr,fsc,ssr,ssc,sofa_count=0;
    fsr=fsc=ssr=ssc=-1;
    queue<Sofa> q;
    vector<vector<char>> grid(R,vector<char>(C));
    for(int row=0;row<R;row++)
    {
        for(int col=0;col<C;col++)
        {
            cin>>grid[row][col];
            if(grid[row][col]=='s')
            {
                sofa_count++;
                if(sofa_count==1) fsr=row,fsc=col;
                else
                {
                    ssr=row,ssc=col;
                    Sofa s=Sofa(fsr,fsc,ssr,ssc,(fsr==ssr)?'H':'V',0);
                    q.push(s);
                }
            }
        }
    }
    unordered_set<string> visited;
    while(!q.empty())
    {
        Sofa s=q.front(); q.pop();
        if (grid[s.fsr][s.fsc]=='S' && grid[s.ssr][s.ssc]=='S')
        {
            cout << s.moves+1 << endl;
            return 0;
        }

        if (s.dir='H')
        {
            if (s.ssc<C-1 && grid[s.ssr][s.ssc+1]!='H'){
                if (canAdd(s.fsr,s.ssc,s.ssr,s.ssc+1,visited)){
                    Sofa newSofa =Sofa(s.fsr, s.ssc, s.ssr, s.ssc + 1, 'H', s.moves + 1);
                    q.push(newSofa);
                }
            }
            if (s.fsc-1>0 && grid[s.fsr][s.fsc-1]!='H'){
                if (canAdd(s.fsr,s.fsc-1,s.ssr,s.fsr,visited)){
                    Sofa newSofa=Sofa(s.fsr,s.fsc-1,s.ssr,s.fsc,'H',s.moves+1);
                    q.push(newSofa);
                }
            }
            if (s.fsr-1>0 && s.ssr-1>0 && grid[s.fsr-1][s.ssr-1]!='H')
            {
                if (canAdd(s.fsr-1,s.fsc,s.ssr-1,s.ssc,visited)){
                    Sofa newSofa=Sofa(s.fsr-1,s.fsc,s.ssr-1,s.ssc,'H',s.moves+1);
                    q.push(newSofa);
                }
            }
            if (s.fsr+1<R && s.ssr+1<C && grid[s.fsr+1][s.fsc]!='H' && grid[s.ssr+1][s.ssc]!='H')
            {
                if (canAdd(s.fsr+1,s.fsc,s.ssr+1,s.ssc,visited))
                {
                    Sofa newSofa=Sofa(s.fsr+1,s.fsc,s.ssr+1,s.ssc,'H',s.moves+1);
                    q.push(newSofa);
                }
            }

            if (s.fsr>0 && grid[s.fsr-1][s.fsc]!='H' && grid[s.ssr-1][s.ssc]!='H')
            {
                if (canAdd(s.ssr-1,s.ssc,s.ssr,s.ssc,visited)){
                    Sofa newSofa=Sofa(s.ssr-1,s.ssc,s.ssr,s.ssc,'V',s.moves+1);
                    q.push(newSofa);
                }
                if (canAdd(s.fsr,s.fsc,s.fsr-1,s.fsc,visited)){
                    Sofa newSofa=Sofa(s.fsr,s.fsc,s.fsr-1,s.fsc,'V',s.moves+1);
                    q.push(newSofa);
                }
            }
            if (s.fsc<C-1 && grid[s.fsr+1][s.fsc]!='H' && grid[s.ssr+1][s.ssc]!='H')
            {
                if (canAdd(s.ssr+1,s.ssc,s.ssr,s.ssc,visited))
                {
                    Sofa newSofa=Sofa(s.ssr+1,s.ssc,s.ssr,s.ssc,'V',s.moves+1);
                    q.push(newSofa);
                }
                if (canAdd(s.fsr,s.fsc,s.fsr+1,s.fsc,visited))
                {
                    Sofa newSofa=Sofa(s.fsr,s.fsc,s.fsr+1,s.fsc,'V',s.moves+1);
                    q.push(newSofa);
                }
            }
        }
        if(s.dir == 'V'){
            //check if we can move down
            if(s.ssr < R-1 && grid[s.ssr+1][s.ssc] != 'H'){
                if(canAdd(s.ssr, s.ssc, s.ssr+1, s.ssc, visited)){
                    Sofa newSofa = Sofa(s.ssr, s.ssc, s.ssr+1, s.ssc, 'V', s.moves+1);
                    q.push(newSofa);
                }
            }
            //check if we can move up
            if(s.fsr > 0 && grid[s.fsr-1][s.fsc] != 'H'){
                if(canAdd(s.fsr-1, s.fsc, s.fsr, s.fsc, visited)){
                    Sofa newSofa = Sofa(s.fsr-1, s.fsc, s.fsr, s.fsc, 'V', s.moves+1);
                    q.push(newSofa);
                }
            }
            //check if we can move left
            if(s.fsc > 0 && grid[s.fsr][s.fsc-1] != 'H' && grid[s.ssr][s.ssc-1] != 'H'){
                if(canAdd(s.fsr, s.fsc-1, s.ssr, s.ssc-1, visited)){
                    Sofa newSofa = Sofa(s.fsr, s.fsc-1, s.ssr, s.ssc-1, 'V', s.moves+1);
                    q.push(newSofa);
                }
            }
            //check if we can move right
            if(s.fsc < C-1 && grid[s.fsr][s.fsc+1] != 'H' && grid[s.ssr][s.ssc+1] != 'H'){
                if(canAdd(s.fsr, s.fsc+1, s.ssr, s.ssc+1, visited)){
                    Sofa newSofa = Sofa(s.fsr, s.fsc+1, s.ssr, s.ssc+1, 'V', s.moves+1);
                    q.push(newSofa);
                }
            }


            if(s.fsc > 0 && grid[s.fsr][s.fsc-1] != 'H' && grid[s.ssr][s.ssc-1] != 'H'){
                if(canAdd(s.fsr, s.fsc-1, s.fsr, s.fsc, visited)){
                    Sofa newSofa = Sofa(s.fsr, s.fsc-1, s.fsr, s.fsc, 'H', s.moves+1);
                    q.push(newSofa);
                }
                if(canAdd(s.ssr, s.ssc, s.ssr, s.ssc-1, visited)){
                    Sofa newSofa = Sofa(s.ssr, s.ssc, s.ssr, s.ssc-1, 'H', s.moves+1);
                    q.push(newSofa);
                }
            }
            if(s.fsc < C-1 && grid[s.fsr][s.fsc+1] != 'H' && grid[s.ssr][s.ssc+1] != 'H'){
                if(canAdd(s.fsr, s.fsc+1, s.fsr, s.fsc, visited)){
                    Sofa newSofa = Sofa(s.fsr, s.fsc+1, s.fsr, s.fsc, 'H', s.moves+1);
                    q.push(newSofa);
                }
                if(canAdd(s.ssr, s.ssc, s.ssr, s.ssc+1, visited)){
                    Sofa newSofa = Sofa(s.ssr, s.ssc, s.ssr, s.ssc+1, 'H', s.moves+1);
                    q.push(newSofa);
                }
            }
        }
    }
    cout << "Impossible" << endl;
    return 0;
}

