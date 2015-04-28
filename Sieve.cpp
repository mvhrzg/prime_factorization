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
//            printf("i:%d[i]:%d, ",i , prime[i]);//does not matter what i is
//        }
//    }
//    printf("\n");
    return prime;
}

vector<int> Sieve::factor(){
    int count = 0;
    Sieve result(n);
    int factor = 0;
    int top = 0;
    
    for(int i  = 0; i < result.primes().size(); i++){
        if(result.primes()[i] != 0){
            factor++;
        }
    }
    printf("factor: %d\n", factor);
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
    printf("factorCount.size: %d\n", factorCount.size());
    for(int i = 1; i < factorCount.size(); i++){
        printf("%d:[%d] ",i , factorCount[i]);
    }
    printf("\n");
    return factorCount;
}//factor

bool Sieve::a7(){
    bool a7 = false;
    int count7 = 0;
    int matches = 0;
    for(int i = 1; i <n; i++){
        //Sieve result(i);
        vector<int> factor(this->factor()); //makes size of factor = n
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
        matches++;
        printf("%d ", matches);
        return true;
    }else{
        return false;
    }
}//a7

bool Sieve::a3b(){
    int count1 = 0;
    int count3 = 0;
    int matches = 0;
    for(int i = 1; i <n; i++){//to n
        vector<int> factor(this->factor());
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
        matches++;
        printf("%d ", matches);
        return true;
    }else{
        return false;
    }
}

bool Sieve:: abc(){
    int counta = 0;
    int countb = 0;
    int countc = 0;
    int matches = 0;
    for(int i = 1; i < n ; i++){//to n
        vector<int> factor(this->factor());
        if(factor[i] != 0){
            if(factor[i]==1){
                if(counta==1){
                    return false;
                }else{
                    counta=1;
                }
            }else if(factor[i]==1){
                if(countb==1){
                    return false;
                }else{
                    countb=1;
                }
            }else if(factor[i]==1){
                if(countc==1){
                    return false;
                }else{
                    countc=1;
                }
            }else{
                return false;
            }
        }
    }
    if(counta==1 && countb==1 && countc==1){
        matches++;
        printf("%d ", matches);
        return true;
    }else{
        return false;
    }
}

void Sieve::match(){
    int count = 0;
    //for(int i = 1; i < n; i++){
        if(this->a3b() || this->a7() || this->abc()){
            count++;
        }
    //}
    printf("%d numbers with exactly 8 divisors\n", count);    
}
std::ostream &operator << (std::ostream &output, const Sieve &op){
    output << op.n << "." << endl;
    return output;
}//friend


