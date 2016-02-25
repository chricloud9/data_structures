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
            output<<"  1 unit of "<<(*p).getName();
        }
        else
            output<<"  "<<(*p).getUnits()<<" units of "<<(*p).getName()<<"\n";
    }
}

void Recipe::makeRecipe(std::string recipeName, std::ostream &output, Kitchen &kitchen) const{
    int difference;
    bool needIngredients = false;
    std::list<Ingredient> ingredientsNeeded;
    std::list<Ingredient> ingredientsUsed;
    for(std::list<Ingredient>::const_iterator ingitr = ingredients.begin(); ingitr!=ingredients.end(); ingitr++){
        for(std::list<Ingredient>::iterator kitr; kitr!=kitchen.getIngredients().end(); kitr++){
            if((*kitr).getName() == (*ingitr).getName()){
                if((*kitr).getUnits() >= (*ingitr).getUnits()){
                    ingredientsUsed.push_back((*ingitr));
                }
            else
                difference = (*ingitr).getUnits() - (*kitr).getUnits(); // how many units are needed
                ingredientsNeeded.push_back(Ingredient((*kitr).getName(),difference)); // make a new ingredient, which includes a name and units, and push it to our ingredients needed list
                needIngredients = true; // we will do some more functionality later based on thisboolean
            }
        }
    }

        if(needIngredients){
            output << "Cannot make " << recipeName <<", need to buy\n";
            for(std::list<Ingredient>::iterator needitr = ingredientsNeeded.begin(); needitr!=ingredientsNeeded.end(); needitr++){
                if((*needitr).getUnits() <2){
                    output << "  1 unit of " << (*needitr).getName() << std::endl;
                }
                else
                    output << (*needitr).getUnits() <<" units of "<< (*needitr).getName() <<std::endl;
            }
        }
        else{
            output << "Made " << recipeName <<std::endl;
            for(std::list<Ingredient>::iterator useditr = ingredientsUsed.begin(); useditr!=ingredientsUsed.end(); useditr++){
                kitchen.addIngredient((*useditr).getName(),(*useditr).getUnits());
            }
        }

    
    
    
    //make a boolean needIngredients = false
    //make a std::list<Ingredient> ingredientsNeeded
    //make a s
    //
    //iterate through the recipes list, compare the iterator.getName() to name //
    //now iterate through that recipe's ingredients list ingitr //
    //within that iteration loop, iterate through the kitchen's ingredients list kitr //
    //when you find the two ingredients with the same name //
    
    
    //check to see if recipe ingredients list iterator.getQuantity < kitchen.getQuantity //
    //if it is
    //output, could not make recipe iterator.getName(), need
    //if(itr.getQuantity() <2)
    // ostr << 1 unit of << itr.getName()
    //else
    //ostr << itr.getQuantity() << units of << itr.getName()
    //(kitchen ingredients list iterator.getQuantity - recipe ingredients list iterator.getQuantity)
    // (*itr).getName()
    //this will continue for all of the items in the list since it is a multi line output
    //needIngredients = true;
    //otherwise
    //add that iterator object to the ingredientsNeeded list
    // use kitchen.incrementQuantity(-(*iterator).getQuantity())
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
    // (kitchen_list_iterator).iterateQuantity(-(*ktr).getQuantity())
    // ostr << "made" << recipe.getName()
    
}