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
//    Sieve s4 = Sieve(1000);
//    Sieve s5 = Sieve(10000);
//    Sieve s6 = Sieve(100000);
//    Sieve goal = Sieve(1000000000000);
    s.match();
    
    return 0;
}

