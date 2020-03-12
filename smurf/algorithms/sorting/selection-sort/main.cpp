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

int min_idx(VI a, int i, int n) {
  int j = i;
  FOR(k, j + 1, n) {
    if (a[k] < a[j]) j = k;
  }
  return j;
}

int max_idx(VI a, int i, int n) {
  int j = i;
  FOR(k, j + 1, n) {
    if (a[k] > a[j]) j = k;
  }
  return j;
}

void selection_sort(VI &a) {
  int n = SIZE(a) - 1;
  FOR(i, 1, n - 1) {
    int j = min_idx(a, i, n);
    std::swap(a[i], a[j]);
  }
}

void selection_sort_2(VI &a) {
  int n = SIZE(a) - 1;
  FORD(i, n, 2) {
    int j = max_idx(a, 1, i);
    std::swap(a[i], a[j]);
  }
}

void print_vi(VI a) {
  int n = SIZE(a) - 1;
  FOR(i, 1, n) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  VI a{-INF, 5, 4, 8, 6, 13, 1, 10, 7, 8};

  // selection_sort(a);
  selection_sort_2(a);

  print_vi(a);

  return 0;
}