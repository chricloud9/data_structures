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
    std::list<Recipe>::iterator p = recipes.begin();
    for(;p!=recipes.end();p++){ //iterators allow us to use this alternate for loop syntax
        if((*p).getName() == name){
            ostr<<name<<" already exists"<<std::endl;
            
            exists = true;
            break;
        }
    }
    // build the new recipe
    if(exists == false){
        std::cout<<"name"<<name<<std::endl;
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
//    std::list<Ingredient>::iterator p =
    while (1) {
        istr >> units;
        if (units == 0) break;
        assert (units > 0);
        istr >> name;
        // add the ingredients to the kitchen
        kitchen.addIngredient(name,units);
        count++;
    }
    ostr << count << " ingredients added to kitchen" << std::endl;
}


void printRecipe(std::istream &istr, std::ostream &ostr,const std::list<Recipe> &recipes) {
    std::string name;
    
    istr >> name;
    
    std::list<Recipe>::const_iterator p = recipes.begin();
    for(;p!=recipes.end();p++){
        if((*p).getName() == name){
            (*p).printRecipe(ostr);
        }
    }
    if (p==recipes.end())
        ostr << "No recipe for "<<name<<"\n";

}


void makeRecipe(std::istream &istr, std::ostream &ostr, const std::list<Recipe> &recipes, Kitchen &kitchen) {
    std::string name;
    istr >> name;
    for(std::list<Recipe>::const_iterator ritr = recipes.begin(); ritr!=recipes.end(); ritr++){
        if ( (*ritr).getName() == name){
            (*ritr).makeRecipe(name, ostr, kitchen);
            break;
        }
        if (ritr == recipes.end()){
            ostr << "No recipe for " <<name<<"\n";
        }
        
    }
    //make a boolean needIngredients = false
    //make a std::list<Ingredient> ingredientsNeeded
    //make a s
    //
    //iterate through the recipes list, compare the iterator.getName() to name
    //now iterate through that recipe's ingredients list itr
    //within that iteration loop, iterate through the kitchen's ingredients list jtr
    //when you find the two ingredients with the same name
    //check to see if recipe ingredients list iterator.getQuantity < kitchen.getQuantity
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
}
