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
    Sieve(int n);
    Sieve(const Sieve& orig);
    
    std::vector<int> primes();                              //returns all primes in sieve(n)
    std::vector<int> divisor();                             //returns number of divisors in sieve(n)
    int multiples(std::vector<bool> &array, int a, int n);
    
    friend std::ostream &operator << (std::ostream &output, const Sieve &op);
    
private:
    int n;

};

#endif	/* SIEVE_H */

