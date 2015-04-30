/* 
 * File:   Sieve.h
 * Author: Mariana Herzog
 *
 * Created on April 20, 2015, 7:52 PM
 */

#ifndef SIEVE_H
#define	SIEVE_H
#include <stdint.h>
#include <inttypes.h>
typedef unsigned long long   uint_fast64_t;

class Sieve {
public:
    Sieve(uint_fast64_t n);
    Sieve(const Sieve& orig);
    /**
     * @return Returns all primes factors in sieve(n)
     * Code found here
     * (http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/)
     * and slightly modified
     */
    std::vector<int> primes();
    /**
     * 
     * @return Returns all factors from prime in the correct index. Example:
     * 2^3-> vector[2]=3
     */
    std::vector<int> factor();
    /**
     * Checks for pattern a^7.
     * @return Returns true if pattern matches; false otherwise
     */
    bool a7(std::vector<int> factor);
    /**
     * Checks for pattern (a^3)*(b).
     * @return Returns true if pattern matches; false otherwise
     */
    bool a3b(std::vector<int> factor);
    /**
     * Checks for pattern (a)*(b)*(c).
     * @return Returns true if pattern matches; false otherwise
     */
    bool abc(std::vector<int> factor);
    /**
     * Checks if any of above methods return true.
     * @return Increments count every time a pattern matches.
     */
    void match();
private:
    int n;
};

#endif	/* SIEVE_H */

