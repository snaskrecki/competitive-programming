#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define SZ(x) int((x).size())
#define VAR(v, n) __typeof(n) v = (n)
#define TR(c, i) for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define PRESENT(c, x) ((c).find(x) != (c).end())
#define CPRESENT(c, x) (find(ALL(c), x) != (c).end())
#define MP make_pair
#define PB push_back
#define PF push_front
#define ST first
#define ND second
#define LENGTH 1000001

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef map<string, int> msi;

const int inf = 1e9 + 1;
const double eps = 10e-9;
const int mod = 1e9 + 7;

int n;
vector<int> V;

void solve() {
    cin >> n;
    REP(i, 0, n - 1) {
        int a;
        cin >> a;
        V.PB(a);
    }
    auto result = minmax_element(V.begin(), V.begin() + n);
    int smallest = *result.ST;
    int greatest = *result.ND;
    //printf("smallest is %d, greatest is %d\n", smallest, greatest);
    int answer = greatest - smallest;
    printf("%d\n", answer);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
  
    solve();
  
    return 0;
}
