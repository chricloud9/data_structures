//
// PROVIDED CODE FOR HOMEWORK 4: GROCERY LISTS
//
// You may use none, a little, or all of this, as you choose, but we
// strongly urge you to examine it carefully.  You may modify this
// code as you wish to complete the assignment.
//


#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <list>

#include "Recipe.h"
#include "Kitchen.h"


// Helper functions
void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes);
void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen);
void printRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes);
void makeRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes, Kitchen &kitchen);
void recipeSuggestions(std::ostream &ostr, const std::list<Recipe> &recipes, const Kitchen &kitchen);

// The main loop parses opens the files for I/O & parses the input
int main(int argc, char* argv[]) {
    
    // Check the number of arguments.
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " in-file out-file\n";
        return 1;
    }
    // Open and test the input file.
    std::ifstream istr(argv[1]);
    if (!istr) {
        std::cerr << "Could not open " << argv[1] << " to read\n";
        return 1;
    }
    // Open and test the output file.
    std::ofstream ostr(argv[2]);
    if (!ostr) {
        std::cerr << "Could not open " << argv[2] << " to write\n";
        return 1;
    }
    
    // the kitchen & recipe list
    Kitchen kitchen;
    std::list<Recipe> recipes;
    
    // some variables to help with parsing
    char c;
    while (istr >> c) {
        if (c == 'r') {
            // READ A NEW RECIPE
            readRecipe(istr,ostr,recipes);
            
        } else if (c == 'a') {
            // ADD INGREDIENTS TO THE KITCHEN
            addIngredients(istr,ostr,kitchen);
            
        } else if (c == 'p') {
            // PRINT A PARTICULAR RECIPE
            printRecipe(istr,ostr,recipes);
            
        } else if (c == 'm') {
            // MAKE SOME FOOD
            makeRecipe(istr,ostr,recipes,kitchen);
            
        } else if (c == 'k') {
            // PRINT THE CONTENTS OF THE KITCHEN
            kitchen.printIngredients(ostr);
            //pretty straightforward
            //first make a sort algorithm for quantity then for alphabetical
            //can reference tennis statistics
            //then simply place ingredients into ostr
            // In the kitchen
            // 1 units of tomatoes
            // 3 unit of lettuce
            
        } else if (c == 's') {
            // SUGGEST ALL RECIPES THAT CAN BE MADE INDIVIDUALLY FROM THE
            //   CURRENT CONTENTS OF THE KITCHEN
            recipeSuggestions(ostr,recipes,kitchen);
            
        } else if (c == 'd') {
            // EXTRA CREDIT: SUGGEST THE COLLECTION OF RECIPES THAT CAN BE
            // MADE TOGETHER THAT USE THE MAXIMUM NUMBER OF UNITS OF
            // INGREDIENTS
        } else {
            std::cerr << "unknown character: " << c << std::endl;
            exit(0);
        }
    }
}


void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes) {
    int units;
    bool exists = false;
    std::string name, name2;
    istr >> name;
    for(std::list<Recipe>::iterator p = recipes.begin();p!=recipes.end();p++){ //iterators allow us to use this alternate for loop syntax
        if((*p).getName() == name){
            ostr<<"Recipe for "<<name<<" already exists"<<std::endl;
            
            exists = true;
            break;
        }
    }
    // build the new recipe
    if(exists == false){
            Recipe r(name);
            while (1) {
                istr >> units;
                if (units == 0) break;
                assert (units > 0);
                istr >> name2;
                r.addIngredient(name2,units);
            }
            // add it to the list
            recipes.push_back(r);
        recipes.sort(alpha);
            ostr << "Recipe for " << name << " added" << std::endl;
        }
        else{
            while(1){
                istr >> units;
                if (units == 0) break;
                std::cout<<units<<std::endl;
                istr >> name2;
                std::cout<<name2<<std::endl;
            }
        }
    
    
}


void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen) {
    int units;
    std::string name;
    int count = 0;
    while (1) {
        istr >> units;
        if (units == 0) break;
        assert (units > 0);
        istr >> name;
        // add the ingredients to the kitchen
        kitchen.addKitchenIngredient(name,units);
        count++;
    }
    if(count == 1)
        ostr << "1 ingredient added to kitchen" <<std::endl;
    else
        ostr << count << " ingredients added to kitchen" << std::endl;
}


void printRecipe(std::istream &istr, std::ostream &ostr,const std::list<Recipe> &recipes) {
    std::string name;
    
    istr >> name;
    
    std::list<Recipe>::const_iterator p = recipes.begin();
    for(;p!=recipes.end();p++){
        if((*p).getName() == name){
            break;
        }
    }
    if (p==recipes.end())
        ostr << "No recipe for "<<name<<"\n";
    else
        (*p).printRecipe(ostr);

}


void makeRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes, Kitchen &kitchen){
    std::string name;
    istr >> name;
    for(std::list<Recipe>::const_iterator ritr = recipes.begin(); ritr!=recipes.end(); ritr++){
        if ( (*ritr).getName() == name){
            (*ritr).makeRecipe(name, ostr, kitchen);
            return;
        }
    
    }
    ostr << "Don't know how to make " <<name<<"\n";
}


void recipeSuggestions(std::ostream &ostr, const std::list<Recipe> &recipes, const Kitchen &kitchen) {
    //outputs what can individually be made
    // similar algorithm to make recipe
    // create std::list<std::string> possible
    // create int matchCount = 0
    // first iterate through recipe
    // then iterate through ingredients list in recipe object denoted as rilitr
    // within that iteration, iterate through kitchen ingredients list denoted as kilitr
    // if rilitr.getName() == kilitr.getName() && kilitr.getQuantity() > rilitr.getQuantity()
    // matchCount ++
    // else
    // matchCount = 0
    // break inner loop
    // this should continue to the next item in the outer recipe list
    //
    int count = 0;
    for(std::list<Recipe>::const_iterator ritr = recipes.begin(); ritr!=recipes.end(); ritr++){
        if((*ritr).suggestRecipe(ostr, kitchen)){
            count++;
        }
    }
    if( count == 0)
        ostr << "No recipes can be prepared\n";
    else if( count == 1)
        ostr << "Recipe that can be prepared:\n";
    else
        ostr << "Recipes that can be prepared:\n";
    for(std::list<Recipe>::const_iterator ritr = recipes.begin(); ritr!=recipes.end(); ritr++){
        if((*ritr).suggestRecipe(ostr, kitchen)){
            ostr <<"  "<< (*ritr).getName() <<std::endl;
        }
    }
    
}

void menuSugeestions(std::ostream &stream, const std::list<Recipe> &recipes, Kitchen &kitchen){
    //suggest a possible menu of items that can be made with the ingredients available
    //std::list<Recipe> canMake;
    //std::list<Ingredient> subtracted;
    std::list<Ingredient> inTheKitchen;
    inTheKitchen = kitchen.getIngredients();
    std::list<Ingredient> clonedKitchen;
    std::list<Recipe> mightUse;
    std::list<Recipe> willUse;
    for(std::list<Recipe>::const_iterator ritr = recipes.begin(); ritr!=recipes.end(); ritr++){//loop through recipes
        if((*ritr).suggestRecipe(stream, kitchen)){
            mightUse.push_back(*ritr);
        }
    
    }
    
    mightUse.sort(quantSort);
    for(std::list<Ingredient>::iterator kitch = inTheKitchen.begin(); kitch!=inTheKitchen.end(); kitch++){
        clonedKitchen.push_back((*kitch));
    }
    for(std::list<Ingredient>::iterator clone = clonedKitchen.begin(); clone!=clonedKitchen.end(); clone++){std::list<Ingredient> ingList; //iterates through all ingredients in cloned kitchen for clone
        for(std::list<Recipe>::iterator sub = mightUse.begin(); sub!=mightUse.end(); sub++){ //iterates through all recipes in mightuse for sub
            int count = 0;
            ingList = (*sub).getIngredients(); // creates a new ingredient list of  recipe ingredients from might use
            for(std::list<Ingredient>::iterator ingSub = ingList.begin(); ingSub!=ingList.end(); ingSub++){ // iterates through recipe ingredients in might use
                if(clone->getName() == ingSub ->getName()){ // compares them to kitchen ingredients
                    // we are trying to see if our recipe count is the same as the number of ingredients
                    //iterated through and we will use the Recipe.getIngredientCount() to verify
                    int cloneUnits = clone->getUnits();
                    int subUnits = ingSub->getUnits();
                    int diff = cloneUnits-subUnits;
                    if(diff>0){
                        count++;
                        if(sub->getIngredientCount() == count){
                            willUse.push_back((*sub));
                        }
                    }
                }
            }
            //we have our list of possible recipes we will use
            //now we need to subtract from kitchen as many ingredients from the ordered by quantity list might use without going into negative numbers
            // if subtracting from the kitchen will lead to a negative number, don't push that recipe to the list
            //otherwise push it to the willUse list and then spit that out
            
        }
    }
    stream << "Menu suggestion for dinner:\n";
    for(std::list<Recipe>::iterator yes = willUse.begin(); yes!=willUse.end(); yes++){
        stream<<"  "<<(*yes).getName()<<",";
    }
    //first sort recipe list by quantity of ingredients in the recipe
    //instantiate ints recipecount and match count
    //loop through recipe.getIndredients()
    //recipe counter++
    //within that, loop through kitchen.getIngredients()
    //and if the names are the same
    //check to see if (the quantities for that item are the same){
    //and if the quantities are the same
    //check to see if(matchCounter == recipeCounter){
    //return (or break I forget which)}
    //matchCounter++
    //}
    // and if all of this is true, create an ingredient
    //and push that ingredient to willUse
    //for each recipe in the list
    //run a Recipe function that compares items ingredients in the particular recipe
    //to the ingredients in the kitchen ingredients list
    //if an ingredient in the recipe book is not present in the kitchen
    //return (to get out of loop and go to next item)
    //otherwise, check the next item until you are at the end of the recipe list ingredients or at the end of the kitchen in

    
    
    //use the suggest recipe function in recipe to first find a list of recipes you can make with the ignredients you have
            // push these into might use
    //then sort these ingredients with the quant sort
    // then iterate through these and subtract ingredients a copy of the kitchen ingredients list as you go
    
    
    
    
    
    

    
    
}
