#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
// using namespace std;
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
    /*
    order_of_key (k)
    find_by_order(k)
	*/


/* 
for fast input output use printf and scanf;
*/
ordered_set ms;

void query(int x)
{
	
}
void solve()
{

	ms.clear();
	int n;
	cin >> n;
	int sz = 0;
	int idx = 1;
	int cnt = 1;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		sz++;
		ms.insert({x,idx++});
		int a = ms.order_of_key({cnt,1e9});
		// cout << a << " ";
		int b = sz - a;
		if(b >= cnt+1) cnt++;
		cout << cnt << " ";
	}
	cout << endl;
}
signed main(){
    int tt = 1;
    cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}