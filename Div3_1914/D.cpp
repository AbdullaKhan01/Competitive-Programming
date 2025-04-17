#include<bits/stdc++.h>
using namespace std; 

class SGTree1{
    public:
    vector<int> seg;
    SGTree1(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low,int high,int arr[]){
    if(low == high){
        seg[ind] = arr[low];
        return ;
    }
    int mid = (low + high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
    }
    pair<int,int> query(int ind,int low,int high,int l,int r){
        //no overlap 
        // l r low high or low high l r
        if(r < low || high < l) return {INT_MIN,INT_MIN};

        //complete overlap
        // [l low high r]
        if(low >=l && high<=r){
            return {seg[ind],ind};
        }
        int mid = (low+high)>>1;
        pair<int,int> left = query(2 * ind + 1, low,mid,l,r);
        pair<int,int> right = query(2* ind + 2,mid+1,high,l,r);
        // return min(left,right);
        if(left.first >= right.first){
            return left;
        }
        else return right;
    }
};


class SGTree{
    public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low,int high,int arr[]){
    if(low == high){
        seg[ind] = arr[low];
        return ;
    }
    int mid = (low + high)/2;
    build(2*ind+1,low,mid,arr);
    build(2*ind+2,mid+1,high,arr);
    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
    }
    pair<int,int> query(int ind,int low,int high,int l,int r){
        //no overlap 
        // l r low high or low high l r
        if(r < low || high < l) return {INT_MAX,INT_MAX};

        //complete overlap
        // [l low high r]
        if(low >=l && high<=r){
            return {seg[ind],ind};
        }
        int mid = (low+high)>>1;
        pair<int,int> left = query(2 * ind + 1, low,mid,l,r);
        pair<int,int> right = query(2* ind + 2,mid+1,high,l,r);
        // return min(left,right);
        if(left.first <= right.first){
            return left;
        }
        else return right;
    }
};
int main(){ 
    int n;
    cin >> n; 
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    SGTree minimum(n);
    SGTree1 maximum(n);
    minimum.build(0,0,n-1,arr);
    maximum.build(0,0,n-1,arr);
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << minimum.query(0,0,n-1,l,r).first <<  " " << minimum.query(0,0,n-1,l,r).second << endl;
        cout << maximum.query(0,0,n-1,l,r).first << " " << maximum.query(0,0,n-1,l,r).second << endl;
    }
    return 0;
}