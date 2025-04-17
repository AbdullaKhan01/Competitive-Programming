// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #define mod 1000000007
// #define mod2 998244353
// #define ceil(a,b) ((a+b-1)/b)
// #define floor(a,b)((a-b+1)/b)
// #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// #define ll long long
// #define int long long
// #define vi vector<int>
// #define all(x) (x).begin(),(x).end()
// #define rall(x) (x).rbegin(),(x).rend()
// #define input(x) for(auto &a:x) cin >> a;
// #define output(x) for(auto a:x) cout << a <<" ";
// #define rep(i,a,n) for(int i=(a);i<n;i++)
// #define pb push_back
// #define ppb pop_back
// #define pf push_front
// #define ppf pop_front
// #define ff first
// #define ss second
// #define si set<int>
// #define pii pair<int,int>
// #define mii map<int,int>
// #define msi map<string,int>
// #define yes "YES"
// #define no "NO"
// #define endl '\n'

// using namespace std; 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//     tree_order_statistics_node_update>
//     ordered_set;

// // no of ranges covering l to r 

// // int a = no of l > x = size - no of l <= x;
// // int b = no of r >= x = size of no of r < 22222222222222222222222222222222222222222222222222222222222x;
// // int ans = b - a;
// const int N = 2e5 + 5;
// int arr[N];
// struct Range_Query
// {
// 	ordered_set left,right;
// 	void add(int l,int r)
// 	{
// 		left.insert(l);
// 		right.insert(r);
// 	}
// 	void query(int x)
// 	{
// 		auto it = left.upper_bound(x);
// 		int a;
// 		if(it == left.end()) a = left.size();
// 		auto jt = right.lower_bound(x);
// 		int b;
// 		if(it != right.begin()) it--;
// 		else
// 		{
			
// 		}

// 	}
// };
// /* 
// for fast input output use printf and scanf;
// */
// signed main(){
// 	fast_io();
    
//     return 0;
// }

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

// typedef tree<int, null_type, less<int>, rb_tree_tag,
//     tree_order_statistics_node_update>
//     ordered_set;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* 
for fast input output use printf and scanf;
*/

// SOME ERROR FIND IT OUT


void update(ordered_multiset<int> &left,ordered_multiset<int> &right,int l,int r)
{
    left.insert(l);
    right.insert(r);
}
void print(ordered_multiset<int> ms)
{
    for(auto it:ms)
    {
        cout << it << " ";
    }
    cout << endl;
}
int query(ordered_multiset<int> &left,ordered_multiset<int> &right,int x)
{
    
    // no of elements < x
    int a = 0;
    a = right.order_of_key(x);
    

    // no of elements > x
    int b = 0;
    b = left.size() - left.order_of_key(x+1);
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
// void solve()
signed main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {

        ordered_multiset<int> left,right;
        int n,q;
        cin >> n >> q;
        vi ans(n);
        input(ans);
        while(q--)
        {
            int a;
            cin >> a;
            if(a == 1)
            {
                int l,r;
                cin >> l >> r;
                update(left,right,l,r);
            }
            if(a == 2)
            {
                int x;
                cin >> x;
                --x;
                int ang = query(left,right,x);
                cout << findAns(ang,ans[x]) << endl;
                // int k = ans[x];
                // if(k <= 9)
                // {
                //     cout << k << endl;
                //     continue;
                // }
                
                // while(k > 9 && ang--)
                // {
                //     int sum = k;
                //     int nsum = 0;
                //     while(sum != 0)
                //     {
                //         int d = sum % 10;
                //         sum /= 10;
                //         nsum += d;
                //     }
                //     k = nsum;
                // }
                // cout << k << endl;
            }
        }
    }
    return 0;
}