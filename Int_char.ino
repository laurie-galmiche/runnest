#include "stdlib.h"
#include "stdio.h"



int divise(float chiffre) {
  while (chiffre >=1) {
    chiffre = chiffre -1;
  }
  return int(10*chiffre);
}

char * change(int number) {
  int nb_2 = number;
  int len = 1;
  char *tab;
  int i = 0;

  if (nb_2 < 0) {
    len++;
    nb_2 = -nb_2;
  }
  while (nb_2 > 9) {
    nb_2 /= 10;
    len++;
  }
  if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
    return (0);
  if (number < 0) {
    number = -number;
    tab[0] = '-';
  }
  while (number > 0) {
    nb_2 = number % 10;
    tab[len - 1 - i] = nb_2 + '0';
    number /= 10;
    i++;
  }
  tab[len] = '\0';
  free(tab);
  return (tab);
}
