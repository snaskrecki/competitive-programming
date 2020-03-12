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

void insertion_sort(VI &a) {
  int n = SIZE(a)-1;
  FOR(i, 2, n) {
    int key = a[i];
    int j = i;
    while (a[j-1] > key) {
      a[j] = a[j-1];
      j--;
    }
    a[j] = key;
  }
}


void insertion_sort_desc(VI &a) {
  int n = SIZE(a)-1;
  FOR(i, 2, n) {
    int key = a[i];
    int j = i;
    while (a[j-1] < key) {
      a[j] = a[j-1];
      j--;
    }
    a[j] = key;
  }
}

void print_vi(VI::iterator b, VI::iterator e) {
  cout << "vi contains: ";
  auto lamda = [](int i) { cout << i << " "; };
  for_each(b, e, lamda);
  cout << endl;
}

void print_vi(VI a) {
  print_vi(a.begin(), a.end());
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  VI a{-INF, 5, 4, 8, 6, 13, 1, 10, 7, 8};

  //insertion_sort(a);

  a[0] = INF;

  insertion_sort_desc(a);

  print_vi(a.begin()+1, a.end());

  return 0;
}