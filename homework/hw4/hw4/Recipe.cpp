#include "Recipe.h"
#include "Ingredient.h"
#include "Kitchen.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cctype>

Recipe::Recipe(std::string r){
    name =r ;
}

std::string Recipe::addIngredient(std::string ing, int quant){
    //we want to create an ingredient object with a name and a quantity
    //we want these ingredients to be recipe specific so we will create a private list of ingredients
    //within our recipe class
    Ingredient ingredient(ing,quant);
    ingredients.push_back(ingredient);
    ingredients.sort(ingSort);
    return "recipe added";
}

std::string Recipe::getName()const{
    return name;
}

std::list<Ingredient> Recipe::getIngredients()const{
    return ingredients;
}

void Recipe::printRecipe(std::ostream &output) const {
    output << "To make "<< name <<", mix together:\n";
    std::list<Ingredient>::const_iterator p = ingredients.begin();
    for(;p!=ingredients.end(); p++){
        if((*p).getUnits() <2){
            output<<"  1 unit of "<<(*p).getName()<<std::endl;
        }
        else
            output<<"  "<<(*p).getUnits()<<" units of "<<(*p).getName()<<"\n";
    }
}

void Recipe::makeRecipe(std::string recipeName, std::ostream &output, Kitchen &kitchen)const {
    int difference;
    bool needIngredients = false;
    std::list<Ingredient> ingredientsNeeded;
    std::list<Ingredient> ingredientsUsed;
    std::list<Ingredient> kitchenIngredients = kitchen.getIngredients();
//    for(std::list<Ingredient>::const_iterator ingitr = ingredients.begin(); ingitr!=ingredients.end(); ingitr++){
//        std::cout<<(*ingitr).getName()<<std::endl;
//    }
//    for(std::list<Ingredient>::iterator kitr = kitchenIngredients.begin(); kitr!=kitchenIngredients.end(); kitr++){
//        std::cout<<(*kitr).getName()<<std::endl;
//    }
    for(std::list<Ingredient>::const_iterator ingitr = ingredients.begin(); ingitr!=ingredients.end(); ingitr++){
        bool foundIngredient = false;
        for(std::list<Ingredient>::iterator kitr = kitchenIngredients.begin(); kitr!=kitchenIngredients.end(); kitr++){
            if(kitr->getName() == ingitr->getName()){ // if element kitchen ingredients iterator
                // is equal to name of recipe ingredient iterator
                foundIngredient = true;
                if((*kitr).getUnits() >= (*ingitr).getUnits()){
                    ingredientsUsed.push_back((*ingitr));
                    
                }
                else{
                    difference = (*ingitr).getUnits() - (*kitr).getUnits(); // how many units are needed
                    Ingredient ingredient((*kitr).getName(),difference);
                    ingredientsNeeded.push_back(ingredient); // make a new ingredient, which includes a name and units, and push it to our ingredients needed list
                    needIngredients = true; // we will do some more functionality later based on thisboolean
                }
            }
        }
        if (foundIngredient == false){
            needIngredients = true;
            Ingredient ingredient((*ingitr).getName(),(*ingitr).getUnits());
            ingredientsNeeded.push_back(ingredient);
        }
    }


    if(needIngredients){
        output << "Cannot make " << recipeName <<", need to buy:\n";
        for(std::list<Ingredient>::iterator needitr = ingredientsNeeded.begin(); needitr!=ingredientsNeeded.end(); needitr++){
            if((*needitr).getUnits() <2){
                output << "  1 unit of " << (*needitr).getName() << std::endl;
            }
            else
                output <<"  "<< (*needitr).getUnits() <<" units of "<< (*needitr).getName() <<std::endl;
        }
    }
    else {
        output << "Made " << recipeName <<std::endl;
        for(std::list<Ingredient>::iterator useditr = ingredientsUsed.begin(); useditr!=ingredientsUsed.end(); useditr++){
            kitchen.addKitchenIngredient(useditr->getName(),-useditr->getUnits());
            std::cout<<"removed "<<useditr->getUnits()<<std::endl;
        }
    }
}


    
    
    //make a boolean needIngredients = false
    //make a std::list<Ingredient> ingredientsNeeded
    //make a s
    //
    //iterate through the recipes list, compare the const_iterator.getName() to name //
    //now iterate through that recipe's ingredients list ingitr //
    //within that iteration loop, iterate through the kitchen's ingredients list kitr //
    //when you find the two ingredients with the same name //
    
    
    //check to see if recipe ingredients list const_iterator.getQuantity < kitchen.getQuantity //
    //if it is
    //output, could not make recipe const_iterator.getName(), need
    //if(itr.getQuantity() <2)
    // ostr << 1 unit of << itr.getName()
    //else
    //ostr << itr.getQuantity() << units of << itr.getName()
    //(kitchen ingredients list const_iterator.getQuantity - recipe ingredients list const_iterator.getQuantity)
    // (*itr).getName()
    //this will continue for all of the items in the list since it is a multi line output
    //needIngredients = true;
    //otherwise
    //add that const_iterator object to the ingredientsNeeded list
    // use kitchen.incrementQuantity(-(*const_iterator).getQuantity())
    // but what if we subtract the quantity we needed from the kitchen and the next ingredient we need more of?
    //would ordering the items in the ingredients list by quantity in both kitchen and recipe list solve this problem?
    //not necessarily, because what if there are a lot of ingredients in the kitchen of one ingredient
    //but we need a small amount of that ingredient in our recipe, while we need a lot of
    //another ingredient that there isn't as much of
    //this means we need to loop twice. once to check if there are enough ingredients, and once more
    //to subtract those ingredients from the kitchen
    //
    // so, lastly... if(needIngredients == False), iterate through ingredientsNeeded, within that iteration
    //iterate through kitchen ingredients
    //if ingredientsNeeded.getName() == kitchenIngredients.getName()
    // (kitchen_list_const_iterator).iterateQuantity(-(*ktr).getQuantity())
    // ostr << "made" << recipe.getName()
    
//}

bool alpha(const Recipe& rec1, const Recipe& rec2){
    return rec1.getName() < rec2.getName();
}

bool Recipe::suggestRecipe(std::ostream& output, Kitchen kitchen) const {
    int count =0;
    int matchCount = 0; //when this equals items in recipe ingredients, return a recipe
    std::list<Ingredient> kitchenIngredients = kitchen.getIngredients();
    for(std::list<Ingredient>::const_iterator ingitr = ingredients.begin(); ingitr!=ingredients.end(); ingitr++){
        count ++;
    }
    for(std::list<Ingredient>::const_iterator ingitr1 = ingredients.begin(); ingitr1!=ingredients.end(); ingitr1++){
        for(std::list<Ingredient>::const_iterator kitchitr = kitchenIngredients.begin(); kitchitr!=kitchenIngredients.end(); kitchitr++){
            if(count == matchCount)
                break;
            else if(ingitr1->getName() == kitchitr->getName()){
                if(kitchitr->getUnits() >= ingitr1->getUnits())
                    matchCount ++;
                    break;
            }
        }
    }
    if(matchCount == count){
        return true;
    }
    return false;
    
}

bool quantSort(const Recipe& rec1, const Recipe& rec2 ){
    std::list<Ingredient> rec1Ingredients = rec1.getIngredients();
    std::list<Ingredient> rec2Ingredients = rec2.getIngredients();
    int rec2Quant = 0;
    int rec1Quant = 0;
    for(std::list<Ingredient>::iterator itr1 = rec1Ingredients.begin(); itr1!= rec1Ingredients.end(); itr1++){
        rec1Quant+= itr1 -> getUnits();
    }
    for(std::list<Ingredient>::iterator itr2 = rec2Ingredients.begin(); itr2!= rec2Ingredients.end(); itr2++){
        rec2Quant+= itr2 -> getUnits();
    }
    return rec1Quant < rec2Quant;
}

int Recipe::getIngredientCount(){
    int counter = 0;
    std::list<Ingredient> ourIngredients = ingredients;
    for(std::list<Ingredient>::iterator oing = ourIngredients.begin(); oing!= ourIngredients.end(); oing++){
        counter ++;
    }
    return counter;
}















