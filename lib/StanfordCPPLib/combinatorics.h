/*
 * File: combinatorics.h
 * ----------------------
 * Hai. This cute little interface exports some cute little
 * functions for working with permutations and combinations.
 */

#ifndef COMBINATORICS_H
#define COMBINATORICS_H

/*
 * Function: permutations
 * Usage: permutations(int, int)
 * Example: permutations(5, 3) returns the permutation of 5 choose 3.
 * -----------------------------------------------------------------------
 * Computes the permutation of n choose k and returns it as a double type.
 */

double permutations(int n, int k);

/*
 * Function: combinations
 * Usage: combinations(int, int)
 * Example: combinations(4, 3) returns the combination of 4 choose 3.
 * -----------------------------------------------------------------------
 * Computes the combination of n choose k and returns it as a double type.
 */

double combinations(int n, int k);

#endif // COMBINATORICS_H
