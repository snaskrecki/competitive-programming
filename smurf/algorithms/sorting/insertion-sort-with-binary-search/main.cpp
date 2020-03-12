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

#define FOR(x, b, e) \
  for (int x = b; x <= (e); ++x)
#define FORD(x, b, e) \
  for (int x = b; x >= (e); --x)
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

void print_vi(VI::iterator b, VI::iterator e) {
  cout << "vi contains: ";
  auto lamda = [](int i) { cout << i << " "; };
  for_each(b, e, lamda);
  cout << "\n";
}

void print_vi(VI a) {
  print_vi(a.begin(), a.end());
}

void print_bin_search(VI a, int l, int s, int r) {
  int n = a.size()-1;
  cout << "vi contains: ";
  FOR(i, 0, n) {
    char c = ' ';
    if (i == l) c = 'l';
    else if (i == r) c = 'r';
    else if (i == s) c = 's';
    else c = ' ';
    cout << c << " ";
  }
  cout << "\n";
}

void insertion_sort_with_binary_search(VI &a) {
  int n = a.size()-1;
  FOR(i, 2, n) {
    print_vi(a);
    int x = a[i];
    int l = 0, r = i, s = -1;
    /* searching max idx j such that a[j-1] <= x */
    while (r-l > 1) {
      /* invariant: a[l] <= x and x < a[r] if r < i */
      s = (r+l)/2;
      print_bin_search(a, l, s, r);
      if (a[s] <= x) {
        l = s;
      } else {
        r = s;
      }
    }
    print_bin_search(a, l, s, r);
    int j = l+1;
    FORD(k, i, j+1) {
      a[k] = a[k-1];
    }
    a[j] = x;
  }
  print_vi(a);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  VI a{0, 5, 4, 8, 6, 2, 1, 9, 7, 8};

  insertion_sort_with_binary_search(a);

  //a[0] = INF;

  //(a);

  print_vi(a.begin()+1, a.end());

  return 0;
}