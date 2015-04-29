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
    Sieve(long long n);
    Sieve(const Sieve& orig);
    //returns all primes factors in sieve(n)
    std::vector<int> primes();
    //returns all factors from prime in the correct index
    //example, 2^3 = vector[2]=3
    std::vector<int> factor();
    //checks for pattern factor^7
    bool a7();
    //checks for pattern (factor1^3)*(factor2^1)
    bool a3b();
    //checks for pattern (factor1^1)*(factor2^1)*(factor3^1)
    bool abc();
    //checks if any of the above methods are true. if so, increments match count
    void match();
private:
    int n;

};

#endif	/* SIEVE_H */

