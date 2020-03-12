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

void Heapify(VI &a, int p, int r) {
  //zachodzi kopiec (p+1,r) ; po wykonaniu PoprawKopiec(p,r)  
  //ma zachodzić kopiec(p,r)  
  int s = p, v = a[s];
  while (2*s <= r) { //dopoki s ma conajmniej 1 syna
    int t = 2*s;
    if (t < r && a[t+1] > a[t]) 
      t++; //wybieramy wiekszego z synow jesli jest prawy
    if (v >= a[t]) { //jezeli wiekszy z synow jest nie wiekszy od v to mozemy 
      a[s] = v;
      s = r+1;
    } else {
      a[s] = a[t];
      s = t;
    } 
  }
  if (s <= r) 
    a[s] = v;
}

void MakeHeap(VI &a) {
  //zawsze zachodzi kopiec(floor(n/2)+1, n)
  //dla kazdego 1<=i<n jesli kopiec(i+1, n) oraz Heapify(i, n) to kopiec(i,)
  //kopiec(p-1, r), jesli tylko p >= 1
  int n = a.size()-1;
  FORD(i, n/2, 1) 
    Heapify(a, i, n); //dokladna analiza daje 4n porownan, 2n przemieszczen
}

void HeapSort(VI &a) {
  int n = a.size()-1;
  MakeHeap(a);
  FORD(i, n, 2) {
    swap(a[1], a[i]);
    Heapify(a, 1, i-1);
  }
}

class MaxHeap {
public:

  VI a;
  int n;
  int ub; //gorne ograniczenie na liczbe elementow zbioru S
  int root;

  int Parent(int i) {
    return i/2;
  }

  int Left(int i) {
    return 2*i;
  }

  int Right(int i) {
    return 2*i+1;
  }

  MaxHeap(int n = 0, int ub = 1'000'000) {
    this->n = n;
    a = VI(ub+1);
    a[0] = -INF;
    root = 1;
  }

  int Max() {
    if (n > 0) return a[1];
    else return -INF;
  }

  void DeleteMax() {
    if (n > 0) return;
    a[1] = a[n];
    n--;
    Heapify(a, 1, n);
  }

  void IncreaseKey(int i, int f) {
    //zmiana elementu e=S[i] na większy f 
    while (i > 1 && a[i/2] < f) { // e != root && a[parent(e)] < f
      a[i] = a[i/2];
      i /= 2;
    }
    a[i] = f;
  }

  void Insert(int e) {
    n++;
    IncreaseKey(n, e);
  }

};

int main() {
  // std::ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  VI a{0,5,4,6,9,2,8,1,7,3};

  HeapSort(a);

  //a[0] = INF;

  //(a);

  PrintVI(a);

  MaxHeap h(0, 500'000);

  h.Insert(5);
  h.Insert(1);
  h.Insert(3);
  h.Insert(4);
  h.Insert(7);

  cout << h.Max() << endl;

  return 0;
}