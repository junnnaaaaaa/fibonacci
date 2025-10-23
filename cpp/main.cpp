#include <bits/stdc++.h>
#include <ctime>
#include <gmpxx.h>
#include <iostream>
using namespace std;
// comment
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
  cout << "clock speed: " << CLOCKS_PER_SEC << endl;
  double t = 0;
  int a;
  double max_t;
  mpz_class n = 0;
  double interval_S = 0;
  mpz_class sum;
  int entry = 1;
  int check;
  int variable_interval;
  cout << "\nenter method: ";
  cin >> a;
  cout << "\nenter max time (seconds): ";
  cin >> max_t;
  cout << "\nenter intervals between fibonacci to lower compute time "
          "(seconds): ";
  cin >> interval_S;
  cout << "\nvariable interval?: ";
  cin >> variable_interval;
  cout << "\nenter check interval as factor of interval: ";
  cin >> check;
  bool test = (a == 0);
  int interval_C = interval_S * CLOCKS_PER_SEC;

  if (test) {
    int n = 0;
    const double interval_recprical = 1 / interval_S;
    double sum = 0;
    double interval;
    while ((sum < max_t)) {
      n++;
      interval = max_t / (interval_recprical * n);
      sum += interval;
      if ((n % check) == 0) {
        cout << "\ninterval: " << interval;
        cout << "\nsum: " << sum;
      }
    }
    cout << "\ntest result: " << n;
  } else {
    mpz_class n = 0;
    while ((t < max_t)) {
      n++;
      if (n.get_ui() % interval_C == 0) {
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
        // cout << "\nfat number in scientific notation: ";
        // bigint3SF(sum);
        // interval_S = variable_interval ? max_t / interval_S : interval_S;
        interval_C = interval_S * CLOCKS_PER_SEC;
        // cout << "\nnew interval: " << interval_C;
        if ((n.get_ui() % check) == 0) {
          cout << "\nwhich fib: " << n;
          cout << "\ntime taken: " << t;
        }
      }
    }
    // cout << "\nbweh: " << fib_linear(1004);
    cout << "\nnth fibonacci below " << max_t << " seconds: " << n;

    gmp_printf("\nfinal value to an accuracy of +- %i: ", interval_C);

    bigint3SF(sum);
    while (entry) {
      cout << "\nenter entry you want to check compute time for, enter 0 to "
              "exit: ";
      cin >> entry;
      entry /= interval_C;
      // cout << "\ncompute time for " << entry << "th value: " << times[entry
      // - 1];
    }
  }
  return 0;
}
