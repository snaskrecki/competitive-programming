#include <bits/stdc++.h>

#define foru(x, b, e)       for (int x = b; x <= (int)(e); ++x)
#define ford(x, b, e)       for (int x = b; x >= (int)(e); --x)
#define rep(x, n)           for (int x = 0; x < (int)(n); ++x)
#define var(v, n)           decltype(n) v = (n)
#define tr(i, c)            for (var(i, (c).begin()); i != (c).end(); ++i)
#define all(c)              (c).begin(), (c).end()
#define sz(x)               int((x).size())
#define pb                  push_back
#define pf                  push_front
#define mp                  make_pair
#define st                  first
#define nd                  second
#define present(c, x)       ((c).find(x) != (c).end())
#define cpresent(c, x)      (find(all(c), x) != (c).end())
#define dontsyncio          ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

using ll                    = long long;
using vi                    = vector<int>;
using ii                    = pair<int ,int>;
using vii                   = vector<ii>;
using si                    = set<int>;
using msi                   = map<string, int>;
using vvi                   = vector<vi>;
using vll                   = vector<ll>;
using vd                    = vector<double>;
using vs                    = vector<string>;

const int inf               = 1e9 + 1;
const double eps            = 10e-9;

int main() {
  int n;
  scanf("%d", &n);
  int a, b;
  while (n--) {
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
  }
  return 0;
}
