#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
#define int long long
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define yes "YES"
#define no "NO"
#define endl '\n'
using namespace std; 

std::pair<int, int> tree[1000000];
int length;

void update(int index, int value, int position = 1, int currentL = 0, int currentR = length-1) {
    if (currentL == currentR) {
        tree[position] = { value, index };
        return;
    }
    int mid = (currentL+currentR)/2;
    if (index <= mid) {
        update(index, value, position*2, currentL, mid);
    } else {
        update(index, value, position*2+1, mid+1, currentR);
    }
    tree[position] = min(tree[position*2], tree[position*2+1]);
}

std::pair<int, int> query(int qL, int qR, int c = 1, int cL = 0, int cR = length-1) {
    if (qL <= cL && cR <= qR) {
        return tree[c];
    }
    int mid = (cL+cR)/2;
    std::pair<int, int> ans = { std::numeric_limits<int>::max(), std::numeric_limits<int>::max() };
    if (qL <= mid) {
        ans = min(ans, query(qL, qR, 2*c, cL, mid));
    }
    if (qR > mid) {
        ans = min(ans, query(qL, qR, 2*c+1, mid+1, cR));
    }
    return ans;
}

signed main(){
	
    
    return 0;
}