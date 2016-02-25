//
//  Ingredient.hpp
//  hw4
//
//  Created by Christopher Chandler on 2/23/16.
//  Copyright © 2016 Christopher Chandler. All rights reserved.
//

#ifndef Ingredient_hpp
#define Ingredient_hpp
#include <iostream>
#include <list>
class Ingredient{
public:
    Ingredient(std::string n, int u);
    
    void changeQuantityBy(int q);
    
    std::string getName() const;
    
    int getUnits() const;
    
private:
    std::string name;
    int units;
};

bool ingSort(const Ingredient& ing1, const Ingredient&ing2);


#endif /* Ingredient_hpp */
