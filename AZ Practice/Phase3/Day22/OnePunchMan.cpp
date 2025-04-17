// #include<bits/stdc++.h>
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

// template <typename T>
// void print(deque<T> q)
// {
//     while (!q.empty())
//     {
//     	auto a = q.front();q.pop_front();
//     	cout << "{"<<a.first.first << "," << a.first.second << "},{" << a.second.first<<","<<a.second.second<<"},";
//         // cerr << (f++ ? "," : ""), print(q.front()), q.pop_front();
//     }
//     cout <<"||||"<<endl;
// }
// /* 
// for fast input output use printf and scanf;
// */
// // 5 5
// // . . # . .
// // # . # . #
// // # # . # #
// // # . # . #
// // . . # . .
// const int INF = 1e9;
// int n,m;
// vector<string> g;
// int dist[1001][1001];
// int vis[1001][1001];

// using ii = pair<int,int>;
// int dx[] = {0,-1,0,+1,-1,+1,-1,+1};
// int dy[] = {-1,0,+1,0,-1,-1,+1,+1};

// pair<int,int> nalla = {-INF,-INF};

// bool isSafe(int i,int j)
// {
// 	return (i>=1 && i<=n && j>=1 && j<=m);
// }
// vector<pair<int,int>>neighbours(pair<int,int>&a,int sz)
// {
// 	vector<pair<int,int>>ans;
// 	for(int i=0;i<sz;i++)
// 	{
// 		int r = a.first + dx[i];
// 		int c = a.second + dy[i];

// 		if(isSafe(r,c))
// 		{
// 			ans.push_back({r,c});
// 		}
// 	}
// 	return ans;
// }
// int findW(pair<int,int>&a,pair<int,int>&b)
// {
// 	int r = a.first;
// 	int c = a.second;
// 	if(g[r][c] == '.') return 0;

// 	int r1 = b.first;
// 	int c1 = b.second;

// 	int rmin = abs(r1-r);
// 	int cmin = abs(c1-c);

// 	if(max(rmin,cmin) <= 1) return 0;
// 	else return 1;
// }
// int find(pair<int,int> &a,pair<int,int> &b)
// {
// 	return max(abs(a.first-b.first),abs(a.second-b.second));
// }
// void BFS01again(int i,int j)
// {
// 	for(int x=1;x<=n;x++)
// 	{
// 		for(int y=1;y<=m;y++)
// 		{
// 			dist[x][y] = INF;
// 		}
// 	}
// 	deque<ii> dq;
// 	dist[i][j] = 0;
// 	dq.push_back({i,j});
// 	while(!dq.empty())
// 	{
// 		auto p1 = dq.front();dq.pop_front();
// 		cout << p1.first << " " << p1.second << " " << dist[p1.first][p1.second] << endl;
// 		for(auto v:neighbours(p1,4))
// 		{
// 			int r = v.first;
// 			int c = v.second;
			
// 			if(g[r][c] == '.')
// 			{
// 				if(dist[r][c] > dist[p1.first][p1.second])
// 				{
// 					dist[r][c] = dist[p1.first][p1.second];
// 					dq.push_front({r,c});
// 				}
// 			}
// 			else
// 			{
// 				// cell is r,c
// 				if(dist[r][c] > dist[p1.first][p1.second] + 1)
// 				{
// 					if(r == 2 && c == 2)
// 					{
// 						cout << "yes" << endl;
// 						// cout << vij.first << " " << vij.second << endl;
// 					}
// 					dist[r][c] = dist[p1.first][p1.second] + 1;
// 					for(auto vij:neighbours(v,8))
// 					{

// 						if(dist[vij.first][vij.second] > dist[r][c])
// 						{
// 							dist[vij.first][vij.second] = dist[r][c];
// 							dq.push_back(vij);
// 						}
// 					}	
// 				}
// 			}
 	
// 		}
// 	}
// }
// // void BFS01(int i,int j)
// // {
// // 	// just keep track of the last one punched wall

// // 	// and we can go from there
// // 	for(int i=1;i<=n;i++)
// // 	{
// // 		for(int j=1;j<=m;j++)
// // 		{
// // 			dist[i][j] = INF;
// // 		}
// // 	}
// // 	deque<pair<ii,ii>> q;
// // 	q.push_back({nalla,{i,j}}); 
// // 	dist[i][j] = 0;
// // 	while(!q.empty())
// // 	{
// // 		// print(q);
// // 		auto it = q.front();q.pop_front();
// // 		pair<int,int> now = it.second;
// // 		pair<int,int> last = it.first;
// // 		// cout << "going to " << now.first << " " << now.second << endl;
// // 		for(auto v:neighbours(now))
// // 		{
// // 			int w = findW(v,last);
// // 			// cout << v.first << " " << v.second << " " << last.first << " " << last.second << " going to find w " << endl;
// // 			// cout << w << endl;
// // 			int r = v.first;
// // 			int c = v.second;
// // 			if(dist[r][c] > dist[now.first][now.second] + w)
// // 			{
// // 				// cout << r << " " << c << " found good " << endl;
// // 				dist[r][c] = dist[now.first][now.second] + w;
// // 				vis[r][c] = 1;
// // 				// cout << dist[r][c] << endl;

// // 				if(w == 1)
// // 				{

// // 					// cout << "pushing " << r << " " << c << " " << r << " " << c << endl;	
// // 					q.push_back({v,v});
// // 				}
// // 				else
// // 				{
// // 					if(g[r][c] == '.')
// // 					{
// // 						// cout << "pushing " << nalla.first << " " << nalla.second << " " << r << " " << c << endl;
// // 						q.push_front({nalla,v});
// // 					}
// // 					else
// // 					{
// // 						// cout << "pushing " << last.first << " " << last.second << " " << r << " " << c << endl;
// // 						q.push_front({last,v});
// // 					} 
						
// // 				}
// // 			}
// // 			else 
// // 			{
// // 				// cout << r << " " << c << " not found good " << endl;
// // 			}
// // 		}
// // 		// cout << "done" << endl; 
// // 	}
// // }
// void solve()
// {
// 	cin >> n >> m;
// 	g.resize(n+1);
// 	for(int i=1;i<=n;i++)
// 	{
// 		string s;
// 		cin >> s;
// 		for(int j=1;j<=m;j++)
// 		{
// 			g[i][j] = s[j-1];
// 		}
// 	}
// 	BFS01again(1,1);
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=m;j++)
// 		{
// 			cout << dist[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// 	// cout << dist[n][m] << endl;
// }	
// signed main(){
// 	fast_io();
//     int tt = 1;
//     // cin >> tt;
//     while(tt--)
//     {
//     	solve();
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0}; // Directions for moving up, down, left, right
const int dy[4] = {0, 0, -1, 1};

struct State {
    int x, y, punches;
    bool operator<(const State& other) const {
        return punches > other.punches; // For priority queue, we need min-heap based on punches
    }
};

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> punches(H, vector<int>(W, INF)); // To track the minimum punches to each cell
    priority_queue<State> pq;

    punches[0][0] = 0; // Starting point requires 0 punches
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;
        int currentPunches = current.punches;

        // If we've reached the bottom-right corner, we can stop
        if (x == H - 1 && y == W - 1) {
            cout << currentPunches << endl;
            return 0;
        }

        if (currentPunches > punches[x][y]) continue;

        // Move in the 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                int newPunches = currentPunches + (grid[nx][ny] == '#' ? 1 : 0);

                // If we found a better path (fewer punches), update and push to the queue
                if (newPunches < punches[nx][ny]) {
                    punches[nx][ny] = newPunches;
                    pq.push({nx, ny, newPunches});
                }
            }
        }
    }

    return 0;
}
