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
string addition(string a,string b){
    int carry = 0;
    int i = a.size()-1 , j = b.size()-1;
    string ans = "";
    while(i>=0 && j>=0){
        int e1 = a[i]-'0';
        int e2 = b[j]-'0';
        i--;j--;
        int sum = e1 + e2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans = to_string(sum)+ans;
    }
    while(i>=0){
        int e1 = a[i]-'0';
        i--;
        int sum = e1 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans = to_string(sum)+ans;
    }
    while(j>=0){
        int e2 = b[j]-'0';
        j--;
        int sum = e2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans = to_string(sum)+ans;
    }
    if(carry != 0) ans = to_string(carry) + ans;
    return ans;
    
}
string multiplication(string a,int b){
    int carry = 0;
    int i = a.size()-1;
    string ans = "";
    while(i>=0){
        int e1 = a[i]-'0';
        i--;
        int sum = (e1 * b) + carry;
        // cout << sum << " ";
        carry = sum / 10;
        sum = sum % 10;
        // cout << endl<<carry << " " << sum << endl;
        ans = to_string(sum)+ans;
    }
    if(carry != 0) ans = to_string(carry) + ans;
    return ans;    
}
string solve(int A) {
    if(A <= 9){
        int p = 1;
        for(int i=2;i<=A;i++){
            p *= i;  
        }
        return to_string(p);
    }
    else{
        int l = 1;
        for(int i=1;i<=10;i++){
            l *= i;
        }
        string var = to_string(l);
        // cout << var << endl;
        for(int i=11;i<=min(A,1LL*99);i++){
            int m = i/10;
            int a = 10*m;
            int b = i-a;
            // cout << var << endl;

            // cout << m << " " << a << " " << b << endl;
            string a1 = multiplication(var,m)+"0";
            string b1 = multiplication(var,b);
            var = addition(a1,b1);
            // cout << "var is " << var << endl;
            // cout << a1 << endl << b1 << endl<<var << endl<<endl;
        }
        if(A == 100) var = var + "00";
        return var;
    }    
}
signed main(){
    
    string g = solve(100);
    cout << g << endl;
    return 0;
}