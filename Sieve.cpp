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

int Sieve::multiples(vector<bool> &array, int a, int n) {
    int i = 2, num;
    while ((num = i * a) <= n) {
        array[ num - 1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
    return a;
}

vector<int> Sieve::primes(){  
    // Print the number of 2s that divide n
    vector<int> prime(n);
    int top = 0;
    int thisN = n;
    while (thisN % 2 == 0) {
        prime[top] = 2;
        top++;
//        printf("%d ", prime[top]);
        //n = n / 2;
        thisN = thisN/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(thisN); i = i + 2) {
        // While i divides n, print i and divide n
        while (thisN % i == 0) {
            prime[top] = i;
            top++;
//            printf("%d ", prime[top]);
            thisN = thisN / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (thisN > 2){
        prime[top] = thisN;
        top++;
//        printf("%d ", prime[top]);
    }
    printf("Prime Factors of %d: ", n);
    for(int i = 0; i < prime.size(); i++){
        if(prime[i]!=0){
            printf("%d ", prime[i]);
        }
    }
    return prime;
}

vector<int> Sieve::divisor(){
    int count = 0;
    vector<int> isDiv = this->primes();
    vector<int> factorCount(n, 0);
    int i, j;
    
    for(i = 0; i <= n; i++){
        factorCount[isDiv[i]]++;
    }
    printf("\nFactorCount: ");
    for(i = 1; i < factorCount.size(); i++){
        if(factorCount[i] != 0){
            printf("%d:%d ", i, factorCount[i]);
        }
            
//            if(factorCount[i]%3==0 & ){
//                
//            }
        
    }
    
    
    for(i = 1; i <= n; i++){
        if(n%i==0){
            count++;
        }
    }

    printf("\n%d has %d divisors\n", n, count);
//    return factorCount;
    return isDiv;
}



std::ostream &operator << (std::ostream &output, const Sieve &op){
    output << "Upper Bound is " << op.n << "." << endl;
    
    return output;
}//friend


