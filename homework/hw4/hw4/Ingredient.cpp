//
//  Ingredient.cpp
//  hw4
//
//  Created by Christopher Chandler on 2/23/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#include "Ingredient.h"


Ingredient::Ingredient(std::string ing, int quant){
    name = ing;
    units = quant;
}

void Ingredient::changeQuantityBy(int q){
    units += q;
}

int Ingredient::getUnits() const{
    return units;
}

std::string Ingredient::getName() const{
    return name;
}

bool ingSort(const Ingredient& ing1, const Ingredient& ing2){
    return ing1.getName() < ing2.getName();
}