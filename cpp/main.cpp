#include <bits/stdc++.h>
#include <ctime>
#include <gmpxx.h>
#include <iostream>
using namespace std;

mpz_class fib_recursion(mpz_class x) {
  uint n = x.get_ui();
  if (n <= 1) {
    return n;
  }
  return fib_recursion(n - 1) + fib_recursion(n - 2);
}

mpz_class fib_linear(mpz_class x) {
  uint n = x.get_ui();
  mpz_class a = 0;
  mpz_class b = 1;
  int loops = n / 2 + (n % 2);
  for (int i = 0; i < loops; i++) {
    b += a;
    a += b;
    // cout << "\nloop iteration: " << i << "\na value: " << a
    //<< "\nb value: " << b;
  }
  return n % 2 ? b : a;
}
void bigint3SF(const mpz_class num) {
  string s = num.get_str();
  int exp = s.length() - 1;
  printf("%c.%c%ce%i\n", s[0], s[1], s[2], exp);
}
int main() {
  double t = 0;
  int a;
  double max_t;
  mpz_class n = 0;
  int interval;
  mpz_class sum;
  cout << "enter method\n";
  cin >> a;
  cout << "enter max time (default 1s) \n";
  cin >> max_t;
  cout << "enter intervals between checks to lower compute time\n";
  cin >> interval;
  bool test = (a == 0);
  while ((t < max_t) && !test) {
    n++;
    if (n.get_ui() % interval == 0) {
      clock_t start, end;
      start = clock();
      switch (a) {
      case 1:
        sum = fib_recursion(n);
        break;
      case 2:
        sum = fib_linear(n);
        break;
      }
      end = clock();
      t = double(end - start) / double(CLOCKS_PER_SEC);
      cout << "\nwhich fib: " << n;
      cout << "\ntime taken: " << t;
      cout << "\nfat number in scientific notation: ";
      bigint3SF(sum);
    }
  }
  // cout << "\nbweh: " << fib_linear(1004);
  cout << "\nnth fibonacci below " << max_t << " seconds: " << n;

  gmp_printf("\nfinal value to an accuracy of +- %i: ", interval);

  bigint3SF(sum);
  return 0;
}
