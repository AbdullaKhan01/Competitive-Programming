#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
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
using namespace __gnu_pbds;


#define indexed_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* 
for fast input output use printf and scanf;
*/


// VERDICT -> ACCEPTED


void update(indexed_set &left,indexed_set &right,int l,int r,int g)
{
    left.insert({l,g});
    right.insert({r,g});
}

int query(indexed_set &left,indexed_set &right,int x)
{
    
    // no of elements < x
    int a = 0;
    a = right.order_of_key({x,0});
    

    // no of elements > x
    int b = 0;
    b = left.size() - left.order_of_key({x+1,0});
    return max(0LL,left.size() - (a + b)); 
}

ll getSum(ll n){
    ll sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

ll findAns(int range, ll num){
    ll temp = num;
    for(int i = 0; i < min(3LL,range); i++){
        temp = getSum(temp);
    }
    return temp;
}

void solve2()
{
    indexed_set left,right;
    int n,q;
    cin >> n >> q;
    vi arr(n);
    input(arr);

    int g = 1;
    while(q--)
    {
        int a;
        cin >> a;
        if(a == 1)
        {
            int l,r;
            cin >> l >> r;
            update(left,right,l,r,g++);
        }
        if(a == 2)
        {
            int x;
            cin >> x;
            int find = query(left,right,x);
            // int g = findAns(find,arr[x-1]);
            // arr[x-1] = g;
            // cout << g << endl;
            cout << findAns(find,arr[x-1]) << endl;
        }
    }
    // return ans;
}



void update(ordered_multiset<int> &left,ordered_multiset<int> &right,int l,int r)
{
    left.insert(l);
    right.insert(r);
}

int query(ordered_multiset<int> &left,ordered_multiset<int> &right,int x)
{
    
    // no of elements < x
    int a = 0;
    a = right.order_of_key(x);
    

    // no of elements > x

    // 2 3 4 5
    // 4 5 9 10
    int b = 0;
    b = left.size() - left.order_of_key(x+1);
    return max(0LL,left.size() - (a + b)); 
}


// void test(){
//     srand(time(NULL));
//     int cnt = 1;
//     int MAX = 1e3;
//     while(cnt <= MAX){
//         int n = rand() % 20 + 1;
//         vector<int> arr(n);
//         for(int i=0;i<n;i++){
//             arr[i] = rand() % 1000 + 1;
//         }
//         int q = rand() % 10 + 1;
//         vector<vector<int>> que;
//         while(q--)
//         {
//             int x = rand() % 2 + 1;
//             if(x == 1)
//             {
//                 int l = rand() % n + 1;
//                 int r = rand() % n + 1;
//                 if(l > r) swap(l,r);
//                 que.push_back({1,l,r});
//             }
//             else 
//             {
//                 int m = rand() % n + 1;
//                 que.push_back({2,m});
//             }
//         }
//         vector<int> correct = solve(n,que,arr);
//         vector<int> my = solve2(n,que,arr);
//         if(correct != my)
//         {
//             cout << n << " " << que.size() << endl;
//             output(arr);
//             cout << endl;
//             for(auto it:que)
//             {
//                 for(auto jt:it)
//                 {
//                     cout << jt << " ";
//                 }
//                 cout << endl;
//             }
//             cout << "Printing correct" << endl;
//             output(correct);
//             cout << endl;
//             cout << "Printing wrong" << endl;
//             output(my);
//             cout << endl;
//             break;
//         }
//         cnt++;
//     }
//     if(cnt == MAX)
//     {
//         cout << "Nothing Found" << endl;   
//     }
// }
signed main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        solve2();
        // solve2(n,ans,arr);
    }
    return 0;
}