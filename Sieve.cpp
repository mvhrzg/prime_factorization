/* 
 * File:   Sieve.cpp
 * Author: Mariana Herzog
 * 
 * Created on April 20, 2015, 7:52 PM
 */

#include <vector>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdint.h>
#include "Sieve.h"

using namespace std;

Sieve::Sieve(uint_fast64_t n) {
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
    int uniqueCount = 0;
    while (thisN % 2 == 0) {
        prime[top] = 2;
        top++;
        uniqueCount++;
        thisN = thisN/2;
    }

    // n must be odd at this point. So skip every other element
    for (int i = 3; i <= sqrt(thisN) && uniqueCount <= 3 && top <= 7; i = i + 2) {
        while (thisN % i == 0) {
            prime[top] = i;
            top++;
            uniqueCount++;
            thisN = thisN / i;
        }
    }

    // This condition is to handle the case when n is a prime number
    // greater than 2
    if (thisN > 2){
        prime[top] = thisN;
        top++;
    }

    return prime;
}//primes

vector<int> Sieve::factor(){
    Sieve result(n);
    int factor = 0;
    int top = 0;
    
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
    return factorCount;
}//factor

bool Sieve::a7(vector<int> factor){
    bool a7 = false;
    int count7 = 0;
    
    for(int i = 1; i < n; i++){
        if(factor[i] != 0){
            if(factor[i] == 7){
                if(count7==1){
                    return false;
                }
                else{
                    count7 = 1;
                }
            }
            else{
                return false;
            }
        }
    }
    if(count7==1){
        return true;
    }else{
        return false;
    }
}//a7

bool Sieve::a3b(vector<int> factor){
    int count1 = 0;
    int count3 = 0;
    
    for(int i = 1; i < n; i++){//to n
//        vector<int> factor(this->factor());
        if(factor[i] != 0){
            if(factor[i] == 3){
                if(count3==1){
                    return false;
                }else{
                    count3 = 1;
                }
            }else if(factor[i] == 1){
                if(count1==1){
                    return false;
                }else{
                    count1 = 1;
                }
            }else{
                return false;
            }
        }
    }
    if(count1==1 && count3==1){
        return true;
    }else{
        return false;
    }
}//a3b

bool Sieve:: abc(vector<int> factor){
    int count = 0;
    
    bool visited = false;
    for(int i = 1; i < n; i++){
        if(factor[i] != 0){
            if(factor[i]==1){
                if(count==3){
                    return false;
                }else{
                    count++;
                }
            }else{
                return false;
            }
        }
    }
    if(count==3){
        return true;
    }else{
        return false;
    }
}//abc()

void Sieve::match(){
    int count = 0;
    
    vector<Sieve> v(n, 0);
    for(int i = 24; i < n; i++){
        v[i] = Sieve(i);
        vector<int> factor(v[i].factor());
        if(v[i].a3b(factor) || v[i].a7(factor) || v[i].abc(factor)){
            count++;
        }
    }
    printf("\n%d has [%d] numbers with exactly 8 divisors\n", n, count);

}
