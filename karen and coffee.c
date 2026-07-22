#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> diff(200002,0);
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        diff[l]++;
        diff[r+1]--;
    }
    vector<int> pref(200002,0);
    int cover=0;
    for(int i=1;i<=200000;i++){
        cover+=diff[i];
        pref[i]=pref[i-1]+(cover>=k);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<"\n";
    }
    return 0;
}