/*
  Lists limits of C Programming Language Types.

  NOTE: Must compile with -std=c99 in gcc.

  Steven Schronk
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
  printf("\nThis Program Displays The Limits of Datatypes on this System.\n\n");
  printf("Bits in a Single Char: %d\n", CHAR_BIT);
  printf("Max Bytes in Multibyte Char (Any Locale): %d\n", MB_LEN_MAX);
  printf("\n");
  printf("Char Min:\t\t%+d\n", CHAR_MIN);
  printf("Char Max:\t\t%+d\n", CHAR_MAX);
  printf("Signed Char Min:\t%+d\n", SCHAR_MIN);
  printf("Signed Char Max:\t%+d\n", SCHAR_MAX);
  printf("Unsigned Char Max:\t%+d\n", UCHAR_MAX);
  printf("\n");
  printf("Short Min:\t\t%+d\n", SHRT_MIN);
  printf("Short Max:\t\t%+d\n", SHRT_MAX);
  printf("Unsigned Short Max:\t%+d\n", USHRT_MAX);
  printf("\n");
  printf("Integer Min:\t\t%+ld\n", INT_MIN);
  printf("Integer Max:\t\t%+ld\n", INT_MAX);
  printf("Unsigned Integer Max:\t%+ld\n", UINT_MAX);
  printf("\n");
  printf("Long Min:\t\t%+ld\n", LONG_MIN);
  printf("Long Max:\t\t%+ld\n", LONG_MAX);
  printf("Unsigned Long Max:\t+%llu\n", ULONG_MAX);
  printf("\n");
  printf("Long Long Min:\t\t%+ld\n", LLONG_MIN);
  printf("Long Long Max:\t\t%+ld\n", LLONG_MAX);
  printf("Unsigned Long Long Max: +%llu\n", ULLONG_MAX);
  printf("\n");
  return EXIT_SUCCESS;
}
