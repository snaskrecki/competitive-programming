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
#define round(d)            int((double)d + 0.5)

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

void print_vi_as_pairs(vi &a) {
    if (sz(a) & 1)  // set size must be an even number
        return;
    for (int i = 0; i < sz(a); i += 2) {
        printf("(%d,%d)", a[i], a[i+1]);
        if (i+1 != sz(a))
            printf(", ");
    }
    printf("\n");
}

void generate_all_pairings(vi &a, int s, int n) {
    if (sz(a) & 1)  // set size must be an even number
        return;
    if (s == n) {   // solution found
        print_vi_as_pairs(a);
        return;
    }
    for (int i = s+1; i < n; ++i) {
        swap(a[i], a[s+1]);
        generate_all_pairings(a, s+2, n);
        swap(a[i], a[s+1]);
    }
}

int main() {
    //std::ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    vi a{1,2,3,4,5,6};
    
    generate_all_pairings(a, 0, sz(a));

    return 0;
}


