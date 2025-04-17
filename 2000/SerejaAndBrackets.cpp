#include<bits/stdc++.h>
using namespace std; 
/*
CODEFORCES 2000 Level QUESTION
Sereja and Brackets
VERDICT -> ACCEPTED
*/
class Info{
    public:
    int open,close,full;
    Info(int _open,int _close,int _full){
        open = _open;
        close = _close;
        full = _full;  
    }
    Info(){
        open = close = full = 0;
    }
};
Info merge(Info left,Info right){
    Info ans = Info();
    ans.full = left.full + right.full + min(left.open,right.close);
    ans.open = left.open + right.open - min(left.open,right.close);
    ans.close = left.close + right.close - min(left.open,right.close);
    return ans;
}
void build(int ind,int low,int high,string &s,Info seg[]){
    if(low == high){
        seg[ind] = Info(s[low] == '(',s[low]==')',0);
        return ;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1,low,mid,s,seg);
    build(2 * ind + 2,mid+1,high,s,seg);
    seg[ind] = merge(seg[2 * ind +1 ],seg[2*ind + 2]);
}
Info query(int ind,int low,int high,int l,int r,Info seg[]){
        //no overlap 
        // l r low high or low high l r
        if(r < low || high < l) return Info();

        //complete overlap
        // [l low high r]
        if(low >=l && high<=r){
            return seg[ind];
        }
        //else partial overlap
        int mid = (low+high)/2;
        Info left = query(2 * ind + 1,low,mid,l,r,seg);
        Info right = query(2 * ind + 2,mid+1,high,l,r,seg);
        return merge(left,right);
}
int main(){ 

    string s;
    cin >> s; 
    int n = s.length();
    Info seg[4*n];
    build(0,0,n-1,s,seg); 
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--,r--;
        Info ans = query(0,0,n-1,l,r,seg);
        cout << ans.full * 2 << endl;
    } 
    return 0;
}