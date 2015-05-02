/* 
 * File:   EDMain.cpp
 * Author: Mariana Herzog
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
    Sieve goal = Sieve(100000);
    goal.match();
    
    return 0;
}