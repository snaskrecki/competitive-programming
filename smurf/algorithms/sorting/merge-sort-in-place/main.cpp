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

void Merge2(VI &a, int p, int r, int s) {
  // assert(p-1 >= s-p+1);
  // zamiana a[p..s] z a[1..s-p+1]
  FOR(i, p, s)
    swap(a[i], a[i-p+1]);
  // wlasciwe scalanie
  int i = 1, j = s+1, k = p-1;
  while (i <= s-p+1 && j <= r) {
    k++;
    if (a[i] <= a[j]) {
      swap(a[i], a[k]);
      i++;
    } else {
      swap(a[j], a[k]);
      j++;
    }
  }
  //jeśli nie wyczerpaliśmy ciągu  a[1..s-p+1], 
  //to przepisujemy go na koniec tablicy a 
  FOR(x, i, s-p+1) {
    k++;
    swap(a[k], a[x]);
  }
}

void MergeSortBis(VI &a, int p, int r) {
  if (p >= r) return;
  int s = (p+r)/2;
  MergeSortBis(a, p, s);
  MergeSortBis(a, s+1, r);
  Merge2(a, p, r, s);
}

void MergeSortInPlace(VI &a) {
  int n = a.size()-1;
  if (n < 1) return;
  int p = ceil(n/2.0) + 1; // ceil(n/2) = n - floor(n/2)
  MergeSortBis(a, p, n);
  // mamy posortowane a[p..n] = a[(n-1)/2..n]
  while (p-1 > 1) { // a[1..p-1] jest nie pusta
    int l = ceil((p-1)/2.0) + 1; // a[l..p-1] musi byc niedluzsza od a[1..l-1]
    MergeSortBis(a, l, p-1);
    Merge2(a, l, n, p-1);
    p = l;
  }
  Merge(a, 1, n, 1);
}

int NextPow2(int n) {
  int clg = ceil(log2(n));
  return 1 << clg;
}

void MSBNoStack(VI &a, int l, int p) {
  if (l >= p) return;
  int sz = 1; // dlugosc scalanego przedzialu
  int pv = 1;
  int ub = NextPow2(p-l+1);
  while (sz <= ub) {
    FORS(i, l, p, sz) {
      int q = i;
      int r = min(i+sz-1, p);
      int s = i+pv-1;
      Merge2(a, q, r, s);
    }
    pv = sz;
    sz *= 2;
  }
}

void MSIPNoStack(VI &a) {
  int n = a.size()-1;
  if (n < 1) return;
  int p = ceil(n/2.0) + 1; 
  MSBNoStack(a, p, n);
  while (p-1 > 1) { 
    int l = ceil((p-1)/2.0) + 1; // ceil()
    MSBNoStack(a, l, p-1);
    Merge2(a, l, n, p-1);
    p = l;
  }
  Merge(a, 1, n, 1);
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  VI a{0,5,9,4,6,8,2,1,7,3};

  MSIPNoStack(a);

  //a[0] = INF;

  //(a);

  PrintVI(a.begin()+1, a.end());

  return 0;
}