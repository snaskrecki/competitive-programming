#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <complex>
#include <iterator>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cmath>
#include <cassert>
#include <list>

#define FOR(x, b, e) \
    for (int x = b; x <= (e); ++x)
#define FORD(x, b, e) \
    for (int x = b; x >= (e); --x)
#define FORS(x, b, e, s) \
    for (int x = b; x <= (e); x+=s)
#define FORDS(x, b, e, s) \
    for (int x = b; x >= (e); x-=s)
#define REP(x, n) \
    for (int x = 0; x < (n); ++x)
#define VAR(v, n) \
    decltype(n) v = (n)
#define ALL(c) \
    (c).begin(), (c).end()
#define SIZE(x) \
    ((int)(x).size())
#define FOREACH(i, c) \
    for (VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

const int inf = 1'000'000'001;
const double eps = 10e-9;

using VI = vector<int>;
using LL = long long;
using VVI = vector<VI>;
using VL = vector<LL>;
using VD = vector<double>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;

void printVI(VI::iterator b,VI::iterator e) {
    cout << "vi contains: ";
    auto lamda = [](int i) { cout << i << " "; };
    for_each(b, e, lamda);
    cout << "\n";
}

void printVI(VI a) {
    printVI(a.begin(), a.end());
}

void printVVI(VVI w) {
    int n = w.size();
    cout << "vvi contains:\n";
    FOR(i, 0, n-1)
        printVI(w[i]);
}

/**
 * sorts all words in lexicographical order, 
 * all words are the same size, equal to `k`
 * word's characters are from alphabet sigma, which size is `m`
 */
void radixSort(VVI &w, int m, int k) {
    int n = w.size();
    VI a(n); //a[i] = current position of i'th word 
    VI t(m); //t[i] = auxiliary counting array
    VI b(n); //b[i] = a[i] after iteration
    FOR(j, 0, n-1) 
        a[j] = j;
    //sortowanie stabilnie słów w[a[1]], w[a[2]],..., w[a[n]]
    //względem elementów z pozycji o numerze faza
    FORD(faza, k-1, 0) {
        //sortowanie przez zliczanie, względem `faza` pozycji
        FOR(i, 0, m-1) 
            t[i] = 0;
        FOR(j, 0, n-1) 
            t[w[a[j]][faza]]++;
        FOR(i, 1, m-1) 
            t[i] += t[i-1];
        FORD(j, n-1, 0) {
            b[t[w[a[j]][faza]]] = a[j];
            t[w[a[j]][faza]]--;
        }
        a = b;
    }
    //mamy w[a[1]] <= w[a[2]] <= ... <= w[a[n]]
    VVI u(n);
    FOR(i, 0, n-1)
        u[i] = w[a[i]];
    w = u;
}



void loadData(VVI &w) {
    w[0] = VI({3,5,5});
    w[1] = VI({3,2,9});
    w[2] = VI({4,5,7});
    w[3] = VI({6,5,7});
    w[4] = VI({8,3,9});
    w[5] = VI({4,3,6});
    w[6] = VI({7,2,0});
}

void loadData2(VVI &w) {
    w[0] = VI({3,5,5,0,2,8});
    w[1] = VI({3,2,9});
    w[2] = VI({4,5,7,4});
    w[3] = VI({6,5,7});
    w[4] = VI({8,3,9,5});
    w[5] = VI({4,3,6,1});
    w[6] = VI({7,2,0});
}

int main() {
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n = 7;
    VVI w(n);

    loadData(w);

    radixSort(w, 10, 3);

    printVVI(w);

    //a[0] = INF;

    //(a);

    return 0;
}