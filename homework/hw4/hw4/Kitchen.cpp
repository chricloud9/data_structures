#include "Kitchen.h"
#include <iostream>

Kitchen::Kitchen(){
    
}

std::string  Kitchen::addIngredient(std::string ing, int quantity){
    bool exists = false;
    std::string s = std::to_string(quantity);
    std::string out;
    std::list<Ingredient>::iterator p = ingredients.begin();
    for(;p!=ingredients.end(); p++){
        if((*p).getName() == ing){
            exists = true;
            (*p).changeQuantityBy(quantity);
            break;
        }
        
    }
    if(exists == false){
        Ingredient ingredient(ing, quantity);
        ingredients.push_back(ingredient);
    }
    else if(quantity <2){
        return "1 ingredient added";
        
    }
    else
        out= (s + " ingredients added");
        return out;
}

void Kitchen::incrementQuantity(int q){
    quantity +=q;
}

void Kitchen::printIngredients(std::ostream &stream){
  
}

std::list<Ingredient> Kitchen::getIngredients() {
    return ingredients;
}