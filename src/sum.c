#include "sum.h"

int sum(int a[], int n) {
    // Min basecase er n = 0, altså et tomt array eller et array, hvor vi er
    // nået i bund.
    if (n == 0) {
        // Her returner jeg bare n, altås 0.
        return n;
        // Ellers returner jeg det tal på elementet + summen af arrayet fra
        // elementet(uden elementet) og til bund.
    } else {
        return a[n - 1] + sum(a, n - 1);
    }
}