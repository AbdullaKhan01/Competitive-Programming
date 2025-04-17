#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds; 

#define indexed_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 

// Constants
typedef long long ll;

void update(indexed_set &left,indexed_set &right,int l,int r, int q){
    left.insert({l,q});
    right.insert({r,q});
}

int query(indexed_set &left,indexed_set &right,int x){
    
    // no of elements < x
    int a = 0;
    a = right.order_of_key({x,0});
    

    // no of elements > x
    
    int b = 0;
    b = left.size() - left.order_of_key({x+1,0});
    return max(0LL,(ll)left.size() - (a + b)); 
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
    for(int i = 0; i < min(3,range); i++){
        temp = getSum(temp);
    }
    return temp;
}

void solve(){
    int n,q;
    cin >> n >> q;
    vector<ll>a(n);
    indexed_set left, right;
    for(int i = 0; i < n; i++) cin >> a[i];
    while(q--){
        int choice;
        cin >> choice;
        if(choice == 1){
            int l,r;
            cin >> l >> r;
            update(left, right, l, r, q);
        }else{
            int x;
            cin >> x;
            int number_of_ranges = query(left,right,x);
            cout << findAns(number_of_ranges, a[x-1]) << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
}