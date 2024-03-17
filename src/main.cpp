// THIS FILE IS USED TO TEST IMPLEMENTATIONS OF OTHER FILES
// THIS PROGRAM SHOULD BUILD BUT SHOULDN'T DO ANYTHING
// Also, each file is not related to each other in the slightest!
// For instance I make my own vector class (which I'll use for game programming)
// But in other files like fancyfunction I include std::vector, it serves a 
// different purpose. I'm just making headers that I think can be useful for me
// This project is making my own library! :)

#include "FancyFunction.h"
#include <cstdlib>
#include <ctime>

bool ConditionFunc()
{
    srand(static_cast<unsigned int>(time(NULL)));
    bool conditionState = rand() % 2 == 0;
    // return conditionState;
    return true;
}

void UpdateFunction1() {
    std::cout << "Update Function1 called!" << std::endl;
}

void ConditionalFunction1() {
    std::cout << "Conditional Function1 called!" << std::endl;
}

int main() {
    FancyFunction<void()>::AddUpdateFunction(UpdateFunction1);
    FancyFunction<void()>::AddConditionalFunction(ConditionalFunction1);

    // Should be called in loop and all functions passed ^ (to FancyFunction<void()>) 
    // will update accordingly
    FancyFunction<void()>::ConstantUpdates(); 
    FancyFunction<void()>::ConditionalUpdates(ConditionFunc);

    return 0;
}


