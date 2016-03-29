#include "Kitchen.h"
#include <string>
#include <iostream>

Kitchen::Kitchen(){
    
}

std::string  Kitchen::addKitchenIngredient(std::string ing, int quantity){
    bool exists = false;
    std::string out;
    
    for(std::list<Ingredient>::iterator kitch = ingredients.begin();kitch!=ingredients.end(); kitch++){
        if((*kitch).getName() == ing){
            exists = true;
            Ingredient ingredient = (*kitch);
            (*kitch).changeQuantityBy(quantity);
            if((*kitch).getUnits() == 0)
                ingredients.remove(ingredient);
            break;
        }
        
    }
    if(exists == false){
        Ingredient ingredient(ing, quantity);
        ingredients.push_back(ingredient);
    }
    if(quantity == 1){
        return "1 ingredient added";
        
    }
    else
        out= (quantity + " ingredients added");
        return out;
}

void Kitchen::incrementQuantity(int q){
    quantity +=q;
}

void Kitchen::printIngredients(std::ostream &stream){
    ingredients.sort(alphaNumeric);
    stream << "In the kitchen:\n";
    for(std::list<Ingredient>::iterator king = ingredients.begin(); king!=ingredients.end(); king++){
        if(king->getUnits() ==1)
            stream << "  1 unit of " << king->getName() <<std::endl;
        else
            stream <<"  " << king->getUnits() << " units of " << king->getName() << std::endl;
    }
  
}

std::list<Ingredient> Kitchen::getIngredients() {
    return ingredients;
}