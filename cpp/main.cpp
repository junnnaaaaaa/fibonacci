#include <bits/stdc++.h>
#include <cmath>
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
  mpz_class sum;
  int entry = 1;
  int check;
  int variable_interval;
  double interval_S;
  cout << "\nenter method: ";
  cin >> a;
  cout << "\nenter max time (seconds): ";
  cin >> max_t;
  cout << "\nenter intervals between fibonacci to lower compute time: ";
  cin >> interval_S;
  cout << "\nvariable interval?: ";
  cin >> variable_interval;
  cout << "\nenter check interval as factor of interval: ";
  cin >> check;
  bool test = (a == 0);
  int interval_C = interval_S * CLOCKS_PER_SEC;
  if (((interval_S / (1 - interval_S)) < max_t) && variable_interval) {
    cout << "\nnot gonna fucking work you monkey";
    return 0;
  }
  if (variable_interval) {
    uint64_t n = 1;
    long double sum = 0;
    long double interval = interval_S;
    while ((sum < max_t)) {
      n++;
      sum += interval;
      interval *= interval;
      if (interval == 0) {
        cout << "\n loop failed, dipping, n: " << n;
        break;
      }
      int times[n][2];
    }
    if (test) {
      uint64_t n = 1;
      long double sum = 0;
      long double interval = interval_S;
      while ((sum < max_t)) {
        n++;
        sum += interval;
        interval *= interval;
        if ((n % check) == 0) {
          cout << "\ninterval: " << interval;
          cout << "\nsum: " << sum;
        }
        if (interval == 0) {
          cout << "\n loop failed, dipping, n: " << n;
          break;
        }
      }
      cout << "\ntest result: " << n;
    } else {
      // non test loop
      mpz_class n = 0;
      long double interval = interval_S;
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
          interval *= interval;
          interval_C = variable_interval ? int(interval * CLOCKS_PER_SEC)
                                         : interval_S * CLOCKS_PER_SEC;

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
