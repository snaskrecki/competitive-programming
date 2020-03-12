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
  PrintVI(a.begin()+1, a.end());
}

int Partition(VI &a, int l, int r) {
  int v = a[l], i = l, j = r+1;
  do {
    //Niezmiennik: dla każdego k=l,l+1,...,i  a[k] <= v, 
    //             dla każdego k=j,j+1,...,r+1,  a[k] => v, 
    //    
    do i++; while (a[i] <= v);
    do j--; while (a[j] >= v);
    if (i < j) swap(a[i], a[j]);
  } while (i <= j);
  a[l] = a[j];
  a[j] = v;
  return j;
}

void QS(VI &a, int l, int r) {
  if (l >= r) return;
  int j = Partition(a, l, r);
  QS(a, l, j-1);
  QS(a, j+1, r);
}

void QuickSort(VI &a) {
  int n = a.size()-1;
  QS(a, 1, n);
}

void QuickSortNoReccurence(VI &a) {
  int n = a.size()-1;
  stack<PII> st;
  st.push({1,n});
  do {
    PII itv = st.top(); st.pop(); //pobranie parametrów kolejnej podtablicy do 
    //sortowania chcemy posortować a[l..r] 
    int l = itv.ST, r = itv.ND;
    //chcemy posortować a[l..r]
    while (l < r) { //dopóki sortowana podtablica ma co najmniej 2 elementy
      //krótszą podtablicę przetwarzamy iteracyjnie, końce dłuższej 
      //odkładamy na stos  
      int j = Partition(a,l,r);
      if (j-l+1 <= r-j+1) {
        st.push({j+1,r});
        r = j-1;
      } else {
        st.push({l,j-1});
        l = j+1;
      }
    }
  } while (!st.empty());
}

int main() {
  // std::ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  VI a{-INF,5,9,4,6,8,2,1,7,3};

  QuickSortNoReccurence(a);

  //a[0] = INF;

  //(a);

  PrintVI(a);

  return 0;
}