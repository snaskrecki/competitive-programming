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

void CountingSort(VI &a, int m) {
  int n = a.size()-1;
  VI t(m);
  //zliczanie wystąpień poszczególnych wartości w tablicy a 
  FOR(i, 1, n) 
    t[a[i]]++;
  //obliczenie dla każdego i liczby elementów nie większych od i 
  FOR(i, 1, m-1) 
    t[i] += t[i-1];
  VI b(n+1);
  //w tablicy posortowanej elementy o wartości i znajdują się 
  //na pozycjach od t[i-1]+1 do  t[i], jeśli tylko przyjmiemy, że t[0] =  0 
  //w sortowaniu wykorzystujemy pomocniczą tablicę b
  //sortowane elementy umieszczamy w tablicy b na ich docelowych pozycjach 
  FORD(j, n, 1) {
    b[t[a[j]]] = a[j];
    t[a[j]]--; // t[a[j]] jest ostatnią wolną pozycją dla 
    //kolejnego (od końca) elementu o wartości a[j]  
  }
  a = b; //przepisanie posortowanej tablicy b do a 
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  VI a{-INF,5,9,4,5,8,2,1,7,3};

  CountingSort(a, 10);

  //a[0] = INF;

  //(a);

  PrintVI(a);

  return 0;
}