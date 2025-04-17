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
int solve1(int n){
        int x = sqrtl(n);
        // cout << x << " ";
        cout << x << endl;
        if(n%2!=0){
        	// cout << (x/2) +  1 << endl;
        	return (x/2) + 1;
        }
        else{
        	// cout << x/2 << endl; 
        	return (x/2);
        }
}
// int solve2(int n){
// 	// long long n;
//     //     cin >> n;
//         if(n == 1){
//             // cout << 1 << endl;
//             // continue;
//             return 1;
//         }
//         long long sum = 1;
//         long long i;
//         long long ans = 0;
//         if(n%2!=0) sum = 1,i=3;
//         else sum = 4,i=5;
        
//         // cout << sum << n << endl;
//         while(true){
//             if(n>=sum){
//                 ans++;
//                 sum+=i;
//                 i+=2;
//                 sum+=i;
//                 i+=2;
//             }
//             else{
//                 break;
//             }
//         }
//         // cout << ans << endl;
//         return ans;
// }
signed main(){
	
	cout << solve1(36) << endl;
	// cout << solve1(323) << endl;
    // ll tt;
    // cin >> tt;
    // vector<int> arr(100);
    // for(int i=0;i<100;i++){
    // 	int x = rand() % 1000;
    // 	arr.pb(x);
    // }
    // // for(auto it:arr){
    // // 	cout << it << " ";
    // // }
    // cout << endl;
    // for(int i=0;i<arr.size();i++){
    // 	int n = arr[i];
    // 	cout << n << " " << solve1(n) << " " << solve2(n) << endl;
    // }
    // while(tt--)
    // {
    //     int n;
    //     cin >> n;
    //     int x = sqrt(n);
    //     if(x%2!=0){
    //     	cout << (x/2) +  1 << endl;
    //     }
    //     else{
    //     	cout << x/2 << endl; 
    //     }
    // }
    return 0;
}
/*

0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
41 3 3
467 10 11
334 9 9
500 11 11
169 6 7
724 13 13
478 10 10
358 9 9
962 15 15
464 10 10
705 13 13
145 6 6
281 8 8
827 14 14
961 15 16
491 11 11
995 15 16
942 15 15
827 14 14
436 10 10
391 9 10
604 12 12
902 15 15
153 6 6
292 8 8
382 9 9
421 10 10
716 13 13
718 13 13
895 14 15
447 10 11
726 13 13
771 13 14
538 11 11
869 14 15
912 15 15
667 12 13
299 8 9
35 2 3
894 14 14
703 13 13
811 14 14
322 8 8
333 9 9
673 12 13
664 12 12
141 5 6
711 13 13
253 7 8
868 14 14
547 11 12
644 12 12
662 12 12
757 13 14
37 3 3
859 14 15
723 13 13
741 13 14
529 11 12
778 13 13
316 8 8
35 2 3
190 6 6
842 14 14
288 8 8
106 5 5
40 3 3
942 15 15
264 8 8
648 12 12
446 10 10
805 14 14
890 14 14
729 13 14
370 9 9
350 9 9
6 1 1
101 5 5
393 9 10
548 11 11
629 12 13
623 12 12
84 4 4
954 15 15
756 13 13
840 14 14
966 15 15
376 9 9
931 15 15
308 8 8
944 15 15
439 10 10
626 12 12
323 8 9
537 11 12
538 11 11
118 5 5
82 4 4
929 15 15
541 11 12

*/