
#include <bits/stdc++.h>
using namespace std;


#define ll int64_t
int dp[105][100100];
vector<int> sol;
bool rec(int level,int left,vector<int>&a)
{
   //pruning
    if(left < 0) return 0;
   //base case
    if(level == (int)a.size())
    {
        if(left == 0) return 1;
        return 0;
    }
   //cache check
    if(dp[level][left] != -1)
    {
        return dp[level][left];
    }
   //transition
    int ans = 0;
    if(rec(level+1,left,a)) ans = 1;
    else if(rec(level+1,left-a[level],a)) ans = 1;
   //save and return

   return (dp[level][left] = ans);
}

void generate(int level,int left,vector<int>&a)
{
    //base case
    if(level == (int)a.size())
    {
        return ;
    }
    if(rec(level+1,left,a))
    {
        generate(level+1,left,a);
    }
    else if(rec(level+1,left-a[level],a))
    {
        sol.push_back(level);
        generate(level+1,left-a[level],a);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.

    vector<vector<int>>ans;
    memset(dp,-1,sizeof(dp));
    vector<int> temp = {-1};
    for(int i=0;i<(int)queries.size();i++)
    {
        int a = queries[i];
        bool ap = rec(0,a,arr);
        if(ap)
        {
            sol.clear();
            generate(0,a,arr);
            ans.push_back(sol);
        }
        else
        {
            ans.push_back(temp);
        }
    }
    return ans;
}


void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];  
    auto ans = subset_queries(arr, queries);

    // checker.


    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
