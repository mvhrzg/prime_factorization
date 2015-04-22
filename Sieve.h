/* 
 * File:   Sieve.h
 * Author: MHerzog
 *
 * Created on April 20, 2015, 7:52 PM
 */

#ifndef SIEVE_H
#define	SIEVE_H

class Sieve {
public:
    Sieve(long int n);
    Sieve(const Sieve& orig);
    
    std::vector<int> primes();                              //returns all primes in sieve(n)
    std::vector<int> factor();                             //returns vector of factors in sieve(n)
    int divisor(int m);                      //returns number of divisors in n
    int pattern();                  //scans for 3 know patterns for 8 divisors
    friend std::ostream &operator << (std::ostream &output, const Sieve &op);
    
private:
    int n;

};

#endif	/* SIEVE_H */

