#include "search.h"

#include <stdbool.h>

bool search(int a[], int n, int x) {
    // Her er vores ene basecase n = 0. Det betyder, at vi har været hele
    // arrayet igennem uden at finde x. Derfor returner vi false.
    if (n == 0) {
        return false;
        // Den anden basecase er, at n > 0 og at det element vi er ved er = x.
        // Det betyder at vi har fundet x. Derfor returner vi true.
    } else if (n > 0 && a[n - 1] == x) {
        return true;
        // Hvis ikke n = 0 eller vi har fundet x, så skal vi søge videre. Dog
        // fra en plads før i arrayet. Altså n-1.
    } else {
        search(a, n - 1, x);
    }
}