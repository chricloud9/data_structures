#include <cstdio>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <stdint.h>
#include <vector>
#include <iomanip>
#include <string>
#include "Time.h"


// NOTE: For this lab we'll use "uintptr_t", a specially defined
// integer type that is the same size in memory as a pointer.  We'll
// use this type everywhere, instead of "int".  On 32 bit
// machines/compilers, this type is probably 4 bytes, and on 64 bit
// machines/compilers, this is probably 8 bytes.


// GLOBAL VARIABLES used by print_stack, label_stack, and clear_stack
std::vector<uintptr_t*> GLOBAL_addresses;
std::vector<std::string> GLOBAL_labels;


// ==============================================================================
//
// This function does a limited print of the data stored on the stack
// in the range of the addresses currently "labeled" and stored in the
// global variables above.
//
// To make the output more readable, the function assumes that integer
// "values" will be between -1000 & 1000 and addresses will be within
// +/- 1000*4 (or *8) bytes from any of the labeled addresses.
// Anything else is assumed to be "garbage"
//
void print_stack() {
    
    assert (GLOBAL_addresses.size() == GLOBAL_labels.size());
    if (GLOBAL_addresses.size() == 0) {
        std::cerr <<  "No labeled addresses to print" << std::endl;
        return;
    }
    
    // Identify the range of stack data to print
    uintptr_t* min_address = GLOBAL_addresses[0];
    uintptr_t* max_address = GLOBAL_addresses[0];
    int max_label_width = GLOBAL_labels[0].size();
    for (int i = 1; i < GLOBAL_addresses.size(); i++) {
        if (GLOBAL_addresses[i] > max_address) { max_address = GLOBAL_addresses[i]; }
        if (GLOBAL_addresses[i] < min_address) { min_address = GLOBAL_addresses[i]; }
        if (GLOBAL_labels[i].size() > max_label_width) { max_label_width = GLOBAL_labels[i].size(); }
    }
    
    // double check that my uintptr_t is actually the size of a pointer
    assert (sizeof(uintptr_t) == sizeof(void*));
    // double check that the start and end address are aligned
    assert ((((uintptr_t)min_address) & (sizeof(uintptr_t)-1)) == 0);
    assert ((((uintptr_t)max_address) & (sizeof(uintptr_t)-1)) == 0);
    
    // double check that the range of address is reasonable
    if (max_address-min_address > 1000) {
        std::cerr << "WARNING: trying to print too much" << std::endl;
        return;
    }
    
    // loop over all addresses in the range (plus some above & below)
    std::cout << "-----------------------------------------" << std::endl;
    for (uintptr_t* address = max_address+5; address >= min_address-5; address--) {
        std::string label = "";
        for (int i = 0; i < GLOBAL_addresses.size(); i++) {
            if (address == GLOBAL_addresses[i]) { label = GLOBAL_labels[i]; }
        }
        std::cout << std::setw(max_label_width) << label << " location: " << address;
        
        // this location might store a value (we assume all values are integers)
        int an_int = (int)(*address);
        // or it might store an address (so we cast it to a pointer)
        uintptr_t* an_address = (uintptr_t*)(*address);
        
        // if it's a value
        if (an_int > -1000 && an_int < 1000) {
            std::cout << "  VALUE:   " << an_int << std::endl;
        }
        // if it's an address
        else if (an_address >= min_address-1000 && an_address <= max_address+1000) {
            std::cout << "  POINTER: " << an_address << std::endl;
        }
        // otherwise it's probably garbage
        else {
            std::cout << "  garbage? " << std::endl;
        }
    }
    std::cout << "-----------------------------------------" << std::endl;
}


// add a label to a particular address in the stack
// NOTE: We use global variables for simplicity for this exercise
void label_stack(uintptr_t* address, const std::string& tag) {
    for (int i = 0; i < GLOBAL_addresses.size(); i++) {
        // check to see if that address is already labeled
        if (address == GLOBAL_addresses[i]) {
            // add additional labels
            GLOBAL_labels[i] += ", " + tag;
            return;
        }
    }
    GLOBAL_addresses.push_back(address);
    GLOBAL_labels.push_back(tag);
}


// clear all previous labels
// NOTE: We use global variables for simplicity for this exercise
void clear_stack_labels() {
    GLOBAL_addresses.clear();
    GLOBAL_labels.clear();
}


// ==============================================================================

void change_times(Time& t1,Time t2){
    uintptr_t sec = 30;
    uintptr_t min = 15;
    uintptr_t hr = 2;
    t1.setSecond(t1.getSecond()+sec);
    t1.setMinute(t1.getMinute()+min);
    t1.setHour(t1.getHour()+hr);
    t2.setSecond(t2.getSecond()+sec);
    t2.setMinute(t2.getMinute()+min);
    t2.setHour(t2.getHour()+hr);
    label_stack((uintptr_t*)&t2,"t2changed");
    label_stack((uintptr_t*)&t1,"t1changed");
}
int main() {
    
    // ------------------------------
    // Example code using print_stack
    // ------------------------------
    std::cout << "size of uintptr_t: " << sizeof(uintptr_t) << std::endl;
    uintptr_t x = 72;
    uintptr_t a[5] = {10, 11, 12, 13, 14};
    uintptr_t *y = &x;
    uintptr_t z = 98;
    std::cout << "x address: " << &x << std::endl;
    std::cout << "a address: " << &a << std::endl;
    std::cout << "y address: " << &y << std::endl;
    std::cout << "z address: " << &z << std::endl;
    
    // label the addresses you want to examine on the stack
    label_stack(&x,"x");
    label_stack(&a[0],"a[0]");
    label_stack(&a[4],"a[4]");
    label_stack((uintptr_t*)&y,"y");
    label_stack(&z,"z");
    
    // print the range of the stack containing these addresses
//    print_stack();
    
    // clear the previous labels
//    clear_stack_labels();
    
    Time t1;
    std::cout<<"size of Time: " <<sizeof(Time) << std::endl;
    std::cout<<"size of t1: " <<sizeof(t1)<< std::endl;
    t1.setHour(6);
    
    std::cout <<"size of modified t1: " << sizeof(t1) << endl;
    t1.setMinute(8);
    std::cout <<"size of modified t1(2): " << sizeof(t1) << endl;
    // continue with lab exercises
    Time t47(0,47,47);
    Time t48(1,48,48);
    label_stack((uintptr_t*)&t47,"t47");
    label_stack((uintptr_t*)&t48,"t48");
    std::cout <<"size of t47: " << sizeof(t47) << endl;
    std::cout <<"size of t48: " << sizeof(t48) << endl;
    change_times(t47, t48);
    std::cout <<"size of modified t47: " << sizeof(t47) << endl;
    std::cout <<"size of modified t48: " << sizeof(t48) << endl;
    print_stack();
    
    
}