#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define FOR(x, b, e) for (int x = b; x <= (e); ++x)
#define FORD(x, b, e) for (int x = b; x >= (e); --x)
#define REP(x, n) for (int x = 0; x < (n); ++x)
#define VAR(v, n) decltype(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

const int INF = 1'000'000'001;
const double EPS = 10e-9;

using VI = vector<int>;
using LL = long long;
using VVI = vector<VI>;
using VL = vector<LL>;
using VD = vector<double>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;

template <class V, class E>
struct Graph {
    struct Ed : E {
        int v;
        Ed(E p, int w) : E(p), v(w) {}
    };

    struct Ve : V, vector<Ed> {};

    vector<Ve> g;

    Graph(int n = 0) : g(n) {}

    void EdgeD(int b, int e, E d = E()) {
        g[b].PB(Ed(d, e));
    }

    void EdgeU(int b, int e, E d = E()) {
        Ed eg(d, e);
        eg.rev = SIZE(g[e]) + (b == e);
        g[b].PB(eg);
        eg.rev = SIZE(g[eg.v = b]) - 1;
        g[e].PB(eg);
    }

    void Write() {
        REP(x, SIZE(g)) {
            cout << x << ":";
            FOREACH(it, g[x])
                cout << " " << it->v;
            cout << endl;
        }
    }

    void Bfs(int s) {
        FOREACH(it, g)
        it->t = it->s = -1;
        g[s].t = 0;
        queue<int> qu;
        qu.push(s);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            FOREACH(it, g[u])
            if (g[it->v].t == -1) {
                qu.push(it->v);
                g[it->v].t = g[u].t + 1;
                g[it->v].s = u;
            }
        }
    }
};

struct MyEdge {
    int rev;  // counterpart reverse edge

    MyEdge() {
        this->rev = -1;
    }
};

struct MyNode {
    int t;
    int s;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph<MyNode, MyEdge> gr(n);

    REP(i, m) {
        int b, e, c;
        cin >> b >> e >> c;
        gr.EdgeU(--b, --e, MyEdge(c));
    }

    return 0;
}
