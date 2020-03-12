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

void PrintVI(VI::iterator b,VI::iterator e) {
  cout << "vi contains: ";
  auto lamda = [](int i) { cout << i << " "; };
  for_each(b, e, lamda);
  cout << "\n";
}

void PrintVI(VI a) {
  PrintVI(a.begin()+1, a.end());
}

void BucketSort(VI &a, int m) {
  //assert(a[i] in {0,1,..,m-1})
  int n = SIZE(a)-1;
  vector<list<int>> b(m); //b[0..m-1]
  FORD(i, n, 1) {
    b[a[i]].push_front(a[i]);
  }
  //scalam listy w jedna b[i+1] na koniec b[i]
  int k = 1;
  FOR(i, 0, m-1) {
    FOREACH(it, b[i]) {
      a[k] = *it;
      k++;
    }
  }
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  VI a{-INF,5,9,4,5,8,2,1,7,3};

  BucketSort(a, 10);

  //a[0] = INF;

  //(a);

  PrintVI(a);

  return 0;
}