#include<bits/stdc++.h>
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define int long long
using namespace std; 
/* 
for fast input output use printf and scanf;
*/

/*

Problem Statement:

From a set of Strings, Answer Q queries, which are:

? ‘S’ K → Find the lexicographically smallest Top K 
results for the prefix match ‘S’.

*/

struct TrieNode {
    map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node, string& currentSuffix, vector<string>& results, int K) {
        if (results.size() >= K) return;
        if (node->isEnd) {
            results.push_back(currentSuffix);
        }
        for (auto& pair : node->children) {
            currentSuffix.push_back(pair.first);
            dfs(pair.second, currentSuffix, results, K);
            currentSuffix.pop_back();
            if (results.size() >= K) return;
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEnd = true;
    }

    vector<string> getTopKStrings(string prefix, int K) {
        vector<string> results;
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children.find(c) == current->children.end()) {
                return results; // Prefix not found
            }
            current = current->children[c];
        }

        string suffix;
        dfs(current, suffix, results, K);

        // Prepend the prefix to each suffix to form the full strings
        for (string& s : results) {
            s = prefix + s;
        }

        // Ensure only top K elements are returned (in case K < results.size())
        if (results.size() > K) {
            results.resize(K);
        }
        return results;
    }
};

void solve()
{
	int n,M,q;
	cin >> n >> M >> q;

	Trie t;
	for(int i=0;i<n;i++){
		int u;string s;
		cin >> u >> s;
		t.insert(s);
	}
	while(q--){
		int len;string s;int k;
		cin >> len >> s >> k;
		string temp = "";
		for(int i=0;i<len;i++){
			temp.push_back(s[i]);
			vector<string> ans = t.getTopKStrings(temp,k);
			for(auto it : ans){
				cout << it << " ";
			}
			cout << endl;
		}
	}
	
}

_ _ _ _  
9 90 900 9000
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}