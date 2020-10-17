#include <bits/stdc++.h>

#define FOR0(i, n) for(int i = 0; i < int(n); ++i)
#define FOR1(i, n) for(int i = 1; i <= int(n); ++i)
#define REP(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define FORD(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define SZ(x) int((x).size())
#define VAR(v, n) __typeof(n) v = (n)
#define TR(c, i) for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define PRESENT(c, x) ((c).find(x) != (c).end())
#define CPRESENT(c, x) (find(ALL(c), x) != (c).end())
#define MP make_pair
#define PB push_back
#define PF push_front
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vd> vvd;
typedef vector<vs> vvs;
typedef vector<vpii> vvpii;
typedef map<string, int> msi;
typedef map<string, string> mss;

const int INF = (int) 1E9 + 7;
const ld EPS = 10E-9;
const ld PI = 2 * acos(0.0);

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int x = 0;

    for (int i = 0; i < n; i++)
        x += (v[i][1] == '-') ? -1 : +1;

    cout << x << "\n";
}

int main() {
//#ifdef ONLINE_JUDGE
//  freopen("file.in", "r", stdin);
//  freopen("file.out", "w", stdout);
//#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
  
    return 0;
}

