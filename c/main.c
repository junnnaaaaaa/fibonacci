#include <gmp.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define PHI (1.0 + sqrt(5)) / 2
typedef unsigned _BitInt(512) uint512_t;
typedef unsigned _BitInt(1024) uint1024_t;

uint1024_t *fibLinear(uint64_t n) {
  uint1024_t overflowCount = pow(PHI, n);
  uint1024_t a[overflowCount];
  uint1024_t b[overflowCount];
  uint1024_t loops = n / 2 + (n % 2);
  for (int i = 0; i < loops; i++){
    //b += a;
    //a += b;
  }
  return n % 2 ? b : a;
}
void bigint3SF(const char s[]) {
  int exp = *(&s + 1) - s;
  printf("%c.%c%ce%i\n", s[0], s[1], s[2], exp);
}

int main() {
  mpf_t gwah, result;
  printf("phi constant: %f\n", PHI);
  mpf_set_default_prec(50000);
  mpf_init(result);
  mpf_init_set_d(gwah, PHI);
  mpf_pow_ui(result, gwah, 600000);
  gmp_printf("Result: %.10Fe\n", result);
  return 0;
}
