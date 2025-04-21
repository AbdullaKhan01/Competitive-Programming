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

int findMaxXOR(vector<int>& arr) {
    Trie trie;
    int maxResult = 0;
    for (int num : arr) {
        trie.insert(num);
    }
    for (int num : arr) {
        maxResult = max(maxResult, trie.findMaxXOR(num));
        maxResult = max(maxResult,num);
    }
    return maxResult;
}

/*

Basically the Idea of maximum XOR subarray is that
we know that the subarray will end at each point so
try to find the maximum xor subarray from 0 to i

and take the max of all XOR's

now how to find Max Xor subarray for each prefix

we know that if some subarray l ..... r has the XOR
as maximum in prefix of i 

then XOR[l,r] = XOR[r] ^ XOR[l-1]

we know how to find 2 numbers in an array i,j i!=j
such that the Xor of them is maximum of all such pairs

so we if make an array of prefixXor at each index

then the question changes to the above question only
because in the prefix I need to find a value such 
that Xor[curr_idx] ^ Xor[prev_idx] is maximum and that 
we know how to find.

*/



void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i > 0) a[i] ^= a[i-1];
    }
    cout << findMaxXOR(a) << endl;
}
int main() {
    int tt=1;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}

