#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* child[2];
    int cnt = 0;
    Node(){
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

struct Trie{
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int n) {
        Node* curr = root;
        for(int i=30;i >= 0;i--){ // 20 will be sufficient
            int x = (n & (1LL<<i))?1:0;
            if(!curr->child[x]) {
                curr->child[x] = new Node();
            }
            curr = curr->child[x];
            curr->cnt++;
        }
    }
    void erase(int n) {
        Node* curr = root;
        for(int i=30;i >= 0;i--){ // 20 will be sufficient
            int x = (n & (1LL<<i))?1:0;
            curr = curr->child[x];
            curr->cnt--;
        }
    }
    int findMaxXOR(int n) {
        Node* curr = root;
        int ans = 0;
        for(int i = 30; i >= 0; i--){
            int x = (n & (1LL<<i)) ? 1 : 0;
            if(curr->child[1-x] && curr->child[1-x]->cnt > 0) {
                ans |= (1LL<<i);
                curr = curr->child[1-x];
            }
            else {
                curr = curr->child[x];
            }
        }
        return ans;
    }
};


void solve(){
    int q;cin >> q;
    Trie t;
    t.insert(0);
    while(q--){
        char ch;int n;
        cin >> ch >> n;
        if(ch == '+'){
            t.insert(n);
        }
        else if(ch == '-'){
            t.erase(n);
        }
        else{
            // ch = ?
            cout << t.findMaxXOR(n) << endl;
        }
    }
}
signed main(){
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
