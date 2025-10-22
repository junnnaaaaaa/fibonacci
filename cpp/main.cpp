#include <bits/stdc++.h>
#include <ctime>
#include <iostream>
using namespace std;
typedef unsigned _BitInt(256) u256;
string u256_to_string(u256 value) {
  string result = "";
  while (value) {
    result += value % 10;
    value /= 10;
  }
  reverse(result.begin(), result.end());
  return result;
}
int fib_recursion(int n) {
  if (n <= 1) {
    return n;
  }
  return fib_recursion(n - 1) + fib_recursion(n - 2);
}
u256 fib_linear(int n) {
  u256 a = 0;
  u256 b = 1;
  int loops = n / 2 + (n % 2);
  for (int i = 0; i < loops; i++) {
    b += a;
    a += b;
    // cout << "\nloop iteration: " << i << "\na value: " << a
    //<< "\nb value: " << b;
  }
  return n % 2 ? b : a;
}
int main() {
  double t = 0;
  int a;
  double max_t;
  int n = 0;
  cout << "enter method\n";
  cin >> a;
  cout << "enter max time (default 1s) \n";
  cin >> max_t;
  bool test = (a == 0);
  while ((t < max_t) && !test) {
    n++;
    clock_t start, end;
    start = clock();
    switch (a) {
    case 1:
      printf("%dth of fib(recursive sequence): %d\n", n, fib_recursion(n));
      break;
    case 2:
      cout << n << "nth of fib(linear) sequnecs"
           << u256_to_string(fib_linear(n)) << "\n";
      break;
    }
    end = clock();
    t = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "time taken: " << t << "\n";
  }
  // cout << "\nbweh: " << fib_linear(1004);
  cout << "\nnth fibonacci below 1s: " << n - 1;
  return 0;
}
