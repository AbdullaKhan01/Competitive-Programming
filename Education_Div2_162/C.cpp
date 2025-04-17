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
int clockwise(int n,int rotation,int pos){

    int g = (pos+rotation);
    if(g > n)
        g = g%n;
    return g;
}
int anticlockwise(int n,int rotation,int pos){

    int g = pos - rotation;
    if(g < 1){
        g = n - abs(g);
    }
    return g;
}

signed main(){
    
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m,x;
        cin >> n >> m >> x;
        vector<int> p;
        int pos = x;
        while(m--){
            int a;
            char b;
            cin >> a >> b;
            if(b == '0'){
                pos = clockwise(n,a,pos);
            }
            else if(b == '1'){
                pos = anticlockwise(n,a,pos);
            }
            else if(b == '?'){
                p.push_back(a);
            }
        }
        set<int> l;
        l.insert(pos);
        for(int i=0;i<p.size();i++){
            int dist = p[i];
            set<int> s;
            for(auto it:l){
                s.insert(clockwise(n,dist,it));
                s.insert(anticlockwise(n,dist,it));
            }
            l = s;
        }
        cout << l.size() << endl;
        for(auto it:l){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}