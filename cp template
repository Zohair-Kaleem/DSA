
#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define nl cout<<endl;
/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
// Function to perform DFS (Depth-First Search)
void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";  // Process the node (can be changed based on problem)

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
template<typename T>
T read() {
    T x;
    cin >> x;
    return x;
}
void write(int x) {
    cout << x << '\n';
}
ll min(ll a,int b) { return a < b ? a : b; }
ll min(int a,ll b) { return a < b ? a : b; }
ll max(ll a,int b) { return a > b ? a : b; }
ll max(int a,ll b) { return a > b ? a : b; }
ll gcd(ll a,ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a,ll b) { return a / gcd(a, b) * b; }
string to_upper(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0; i < (int)a.size(); ++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }
bool prime(ll a) { if (a == 1) return 0; for (int i = 2; i <= round(sqrt(a)); ++i) if (a % i == 0) return 0; return 1; }
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);

    return 0;
}
