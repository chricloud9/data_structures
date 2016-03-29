#ifndef __recipe_h_
#define __recipe_h_
#include <iostream>
#include <list>
#include "Ingredient.h"
#include "Kitchen.h"
class Recipe{
public:
    
    Recipe(std::string r);
    
    std::string addIngredient(std::string name, int quantity);
    
    std::string getName() const;
    
    std::list<Ingredient> getIngredients() const;
    
    void printRecipe(std::ostream& output) const;
    
    void makeRecipe(std::string recipeName, std::ostream& output, Kitchen &kitchen) const;
    
    bool suggestRecipe(std::ostream& output, Kitchen kitchen) const;
    
    int getIngredientCount();

private:
    std::string name;
    int units;
    std::list<Ingredient> ingredients;
    int ingredientCount;

    
};
bool alpha(const Recipe& rec1, const Recipe& rec2);
bool quantSort(const Recipe& rec1, const Recipe& rec2);

#endif