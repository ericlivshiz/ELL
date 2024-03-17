#pragma once

#include <iostream>
#include <vector>
#include <functional>

enum class FunctionState
{
    update_every_frame,
    conditional,
    priority
};

template <typename T>
class FancyFunction
{
public:
    static void ConstantUpdates()
    {
        for (auto& func : updateFunctions)
        {
            func();
        }
    }

    // ConditionFunc is a boolean function that checks if condition is true
    static void ConditionalUpdates(std::function<bool()> conditionFunc)
    {
        bool condition = conditionFunc();
        for (auto& func : conditionalFunctions)
        {
            if (condition)
            {
                func();
            }
        }
    }

    static void PriorityUpdates()
    {
        std::cout << "Not built yet, sorry :)" << std::endl;
    }

    //// Arbitrary vector
    //template <typename K>
    //static void AddFunction(T func)
    //{
    //    K.push_back(func);
    //}

    static void AddUpdateFunction(T func)
    {
        updateFunctions.push_back(func);
    }

    static void AddConditionalFunction(T func)
    {
        conditionalFunctions.push_back(func);
    }

    static void AddPriorityFunctions(T func)
    {
        priorityFunctions.push_back(func);
    }

private:
    // Static vectors to hold function pointers or lambdas
    static std::vector<std::function<void()>> updateFunctions;
    static std::vector<std::function<void()>> conditionalFunctions;
    static std::vector<std::function<void()>> priorityFunctions;
};

// Initialize static member variables
template <typename T>
std::vector<std::function<void()>> FancyFunction<T>::updateFunctions;

template <typename T>
std::vector<std::function<void()>> FancyFunction<T>::conditionalFunctions;

template <typename T>
std::vector<std::function<void()>> FancyFunction<T>::priorityFunctions;