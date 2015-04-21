/* 
 * File:   EDMain.cpp
 * Author: MHerzog
 *
 * Created on April 20, 2015, 7:51 PM
 */

#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "Sieve.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Sieve s = Sieve(100);
    Sieve s2 = Sieve(24);
    Sieve s3 = Sieve(16);
    s.divisor();
    
    s2.divisor();
    
    s3.divisor();
    return 0;
}

