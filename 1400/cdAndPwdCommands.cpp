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
void display(stack<char> s){
    string ans;
    while(!s.empty()){
        ans.pb(s.top());
        s.pop();
    }
    reverse(all(ans));
    cout << ans << endl;
}
void clear(stack<char>&s){
    while(!s.empty()){
        s.pop();
    }
}
void run_cases(stack<char>&ans){
    string s;
    getline(cin,s);
    if(s[0] =='p') display(ans);
    else{
        if(s[3]=='/') clear(ans);
        rep(i,3,s.size()){
            // cout << s[i] << " ";
            if(s[i] == '.'){
                int b = 2;
                // if(s[i-1]=='/') b++;
                while(!ans.empty()){
                    char x = ans.top();
                    ans.pop();
                    b-=(x=='/');
                    if(b==0) break;
                }
                i++;
            }
            else if(s[i] == '/'){
                if(ans.empty()) ans.push(s[i]);
                if(ans.top()!=s[i]) ans.push(s[i]);
            }
            else{
                ans.push(s[i]);
            }
        }
        ans.push('/');
    }
}
signed main(){
    ll tt;
    cin >> tt;
    tt++;
    stack<char> ans;
    while(tt--)
    {
        run_cases(ans);
        
    }
    return 0;
}   