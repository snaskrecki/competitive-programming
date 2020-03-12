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

void PrintVI(VI::iterator b,VI::iterator e) {
  cout << "vi contains: ";
  auto lamda = [](int i) { cout << i << " "; };
  for_each(b, e, lamda);
  cout << "\n";
}

void PrintVI(VI a) {
  PrintVI(a.begin(), a.end());
}

void Merge(VI &a,int l,int p,int s) {
  int m = s-l+1;
  VI b(m+1);
  FOR(i, l, s)
    b[i-l+1] = a[i];

  int i = 1;
  int j = s+1;
  int k = l-1;
  while (i <= m && j <= p) {
    k++;
    if (b[i] < a[j]) {
      a[k] = b[i];
      i++;
    } else {
      a[k] = a[j];
      j++;
    }
  }

  FOR(x, i, m) {
    k++;
    a[k] = b[x];
  }
}

void MS(VI &a,int l,int p) {
  if (l >= p) return;
  int s = (l+p)/2;
  MS(a, l, s);
  MS(a, s+1, p);
  Merge(a, l, p, s);
}

void MergeSort(VI &a) {
  int n = a.size()-1;
  MS(a, 1, n);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  VI a{0, 5, 4, 8, 6, 2, 1, 9, 7, 3};

  MergeSort(a);

  //a[0] = INF;

  //(a);

  PrintVI(a.begin()+1, a.end());

  return 0;
}