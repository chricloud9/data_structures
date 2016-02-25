#ifndef __kitchen_h_
#define __kitchen_h_
#include <iostream>
#include <list>
#include "Ingredient.h"
class Kitchen{
    

public:
    Kitchen();
    
    std::string addIngredient(std::string ing, int quantity);
    
    void printIngredients(std::ostream &ostr);
    
    void incrementQuantity(int q);
    
    std::list<Ingredient> getIngredients();
    
    
    
private:
    std::string ingredient;
    int quantity;
    std::list<Ingredient> ingredients;

};

#endif