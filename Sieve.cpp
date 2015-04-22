/* 
 * File:   Sieve.cpp
 * Author: MHerzog
 * 
 * Created on April 20, 2015, 7:52 PM
 */

#include <vector>
#include <algorithm>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <math.h>
#include <iostream>
#include "Sieve.h"

using namespace std;

Sieve::Sieve(int n) {
    this->n = n;
}

Sieve::Sieve(const Sieve& orig) {
    n = orig.n;
}

vector<int> Sieve::primes(){  
    // Print the number of 2s that divide n
    vector<int> prime(n);
    int top = 0;
    int thisN = n;
    while (thisN % 2 == 0) {
        prime[top] = 2;
        top++;
        thisN = thisN/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(thisN); i = i + 2) {
        // While i divides n, print i and divide n
        while (thisN % i == 0) {
            prime[top] = i;
            top++;
            thisN = thisN / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (thisN > 2){
        prime[top] = thisN;
        top++;
    }
    //Print prime factors of each n
//    printf("Prime Factors of %d: ", n);
//    for(int i = 0; i < prime.size(); i++){
//        if(prime[i]!=0){
//            printf("%d ", prime[i]);
//        }
//    }
    return prime;
}

vector<int> Sieve::divisor(){
    int count = 0;
    Sieve result(n);
    vector<bool> matches(n, false);
    int factor = 0;
    
    for(int i  = 0; i < result.primes().size(); i++){
        if(result.primes()[i] != 0){
            factor++;
        }
    }
    vector<int> isDiv(factor);
    vector<int> factorCount(result.primes().size(), 0);

    
    for(int i = 0; i < isDiv.size(); i++){
        if(result.primes()[i] != 0){
            isDiv[i] = result.primes()[i];
        }
    }
    
    for(int i = 0; i < isDiv.size(); i++){
        factorCount[isDiv[i]]++;       
    }
    printf("%d: ", n);
    for (int i = 1; i<factorCount.size(); i++){ //stay away from position 0 in factorCount
        if(factorCount[i] != 0){
            printf("%d^%d ", i, factorCount[i]);
        }
    }
    printf("\n");
    
    
    
//    counts number of divisors in n (unrelated to sieve)
//    for(int i = 1; i <= n; i++){
//        if(n%i==0){
//            count++;
//        }
//    }
//    printf("\n%d has %d divisors\n", n, count);
    return factorCount;
}

int pattern(vector<int> thisDiv){
    int counta;
    int countb;
    int countc;
    
    
    //finding pattern up to n
//    for(int i = 1; i < factorCount.size(); i++){
//        if(factorCount[i] == 3){
//            matches[i] = true;  //mark a^3 as true
//        }
//    }
    
    
    //for 
            
            
            //count a, count b, countc
            //if index = 7, counta++
            //if other indexes in same array = 0 size-counta number of times, this is a match
            //same with others
}

std::ostream &operator << (std::ostream &output, const Sieve &op){
    output << "Upper Bound is " << op.n << "." << endl;
    
    return output;
}//friend


