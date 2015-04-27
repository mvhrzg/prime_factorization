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

Sieve::Sieve(long int n) {
    this->n = n;
}

Sieve::Sieve(const Sieve& orig) {
    n = orig.n;
}

vector<int> Sieve::primes(){  
    // number of 2s that divide n
    vector<int> prime(n);
    int top = 0;
    int thisN = n;
    while (thisN % 2 == 0) {
        prime[top] = 2;
        top++;
        thisN = thisN/2;
    }

    // n must be odd at this point. So skip every other element
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

vector<int> Sieve::factor(){
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
    //printf("%d: ", n);

//    for (int i = 1; i<factorCount.size(); i++){ //stay away from position 0 in factorCount
//        if(factorCount[i] != 0){
//            printf("%d^%d ", i, factorCount[i]);
//        }
//    }
//    printf("\n");
    return factorCount;
}//factor

int Sieve::pattern(){
    bool a = false;
    bool a3 = false;
    bool a7 = false;
    bool b = false;
    bool c = false;
    bool rest = false;
    Sieve result(n);
    vector<int> factor(result.factor());        //clones result.factor() into factor
    
    for(int i = 1; i < factor.size(); i++){
        if(factor[i] != 0){
            if(factor[i] == 3){
                a3=true;
            }
            if(a3 && factor[i]==1){
                    b=true;
//                if(a3 && b && factor[i] == 0){
                    
            }
            if(a3 && b){
                printf("%d has 8 divisors", factor[i]);
            }
        }
//        for(int j = 1; j <= i; j++){
//            if(factor[j] != 0){
//                if(factor[j]==3){
//                    a3 = true;
//                    if(a3 && factor[j]==1){
//                        b = true;
//                    }
//                }
//            }
//        }
//            printf("%d^%d, ", i, factor[i]);
//            printf("\n");
//        if(a3 && b){
//        printf("%d has 8 divisors\n", n);
//    }
    }
            
        
    
//
//    //count a, count b, countc
//    //if index = 7, counta++
//    //if other indexes in same array = 0 size-counta number of times, this is a match
//    //same with others
//    return count;
    return 0;
}//pattern

//may not be needed
int Sieve::divisor(int m){
    //Sieve result(list);
    //vector<int> factor = result.factor();
    int div = 0;
    int count = 0;
    for(int i = 1; i <= m; i++){
        if(m%i == 0){
            div++;
        }
    }
    return div; //return number of divisors for n
}//divisor

std::ostream &operator << (std::ostream &output, const Sieve &op){
    output << op.n << "." << endl;
    
    return output;
}//friend


