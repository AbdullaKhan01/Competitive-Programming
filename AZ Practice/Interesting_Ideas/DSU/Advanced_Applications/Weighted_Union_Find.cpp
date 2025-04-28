#include<bits/stdc++.h>
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
/* 
for fast input output use printf and scanf;
*/
/*

Motivation Problem -> KNOWLEDGE BASE

We have a Knowledge Base in which there are 2 types 
of Queries 

1 a b c -> add xa - xb = c in the knowledge base 
2 a b -> find the value of xa - xb 

if on adding xa - xb = c we find that we already 
know value of xa - xb = v and v != c then print that 
we have Inconsistent data and continue

if v = c then just continue because already know that

otherwise add this information to the knowledge base

in the 2nd query if there is Insufficient data to find 
the value of xa - xb then print Insufficient data
otherwise print the value of xa - xb

*/

/*

How to solve the Problem ????

We can keep a Weighted Union Find for this Problem

-> HURRAY NEW DATA STRUCTURE Unlocked

in the union find we can keep a directed edge from the
node a to b with edge cost C which denotes that
xa - xb = C

so Find(x) will know return <P,C> 
P -> is the Leader of the element x and C is the total
sum of cost in the path from x to its leader

we can implement Path compression in the recursive call

Now how to union(a,b,c) 
add a to b edge with cost C

instead of doing union on nodes a and b 

we will union their leaders so that a DSU tree like
structure is maintained and we can easily query 

so we will find Leader of a and b 

now we will implement Rank Compression

we will know which leader has less rank

let's say rank of leader of b < rank of leader of a
then merge leader of b into leader of a

how ?? 

let C1 = sum of cost in path from a to Leader A
 	C2 = sum of cost in path from b to Leader B

we have to add xa - xb = C

going to leader of a from a Cost = C1
going to leader of a from a to b to Leader of B 
Cost = C + C2 + x(weight of edge from leader B to leader A)
so both cost should be equal

so C + C2 + x = C1
x = C1 - C2 - C

so add Edge of Weight x from leader B to leader A

how to find Answer of 2nd query

lets say find a b

we have to find xa - xb

just call find(a) find(b)

we get <P1,C1> and <P2,C2>
if(P1 != P2) both in different component then answer
cannot be determined insufficient data

otherwise answer is just C1 - C2

*/
struct WeightedUnionFind
{
	int n,set_size;
	vector<pair<int,int>> parent;
	vector<int>rank;
	WeightedUnionFind(){}
	WeightedUnionFind(int a)
	{
		n = set_size = a;
		parent.assign(n+1,{0,0});
		rank.assign(n+1,1);
		for(int i=1;i<=n;i++)
		{
			parent[i].first = i;
		}
	}
	pair<int,int> find(int x)
	{
		// returns <Leader,Cost> 
		if(x != parent[x].first) 
		{
			pair<int,int> par = find(parent[x].first);
			pair<int,int> ans = make_pair(par.first,par.second + parent[x].second);
			return parent[x] = ans;
		}
		else return {x,0};
	}
	void merge(int xc,int yc,int w)
	{
		// add nx - ny = w
		pair<int,int> x = find(xc) , y = find(yc);
		int xroot = x.first , yroot = y.first;
		int xcost = x.second , ycost = y.second;
		if(xroot != yroot)
		{
			if(rank[xroot] >= rank[yroot])
			{
				// xcost = w + ycost + s
				// s = xcost - w - ycost 
				int cost = xcost - w - ycost;
				parent[yroot] = make_pair(xroot,cost);
				rank[xroot] += rank[yroot];
			}
			else
			{
				// xcost + s = w + ycost
				// s = w + ycost - xcost
				int cost = w + ycost - xcost;
				parent[xroot] = make_pair(yroot,cost);
				rank[yroot] += rank[xroot];
			}
			set_size -= 1;
		}
	}
	void query(int xc,int yc){
		pair<int,int> x = find(xc) , y = find(yc);
		if(x.first != y.first){
			cout << "?" << endl;
		}
		else{
			cout << x.second - y.second << endl;
		}
	}
	void reset()
	{
		set_size = n;
		for(int i=1;i<=n;i++)
		{
			parent[i].first = i;
			rank[i] = 1;
		}
	}
};
void solve(){
	int n,q;cin >> n >> q;
	WeightedUnionFind wuf(n);
	while(q--){
		int a,x,y,w;
		cin >> a;
		if(a == 0){
			cin >> x >> y >> w;
			wuf.merge(y,x,w);
		}
		else{
			cin >> x >> y;
			wuf.query(y,x);
		}
	}
}
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