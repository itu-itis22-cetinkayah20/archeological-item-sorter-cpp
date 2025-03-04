#include "methods.h"

int getMax(std::vector<Item> &items, const std::string &attribute)
{
    int max = 0;
    if (attribute == "age")
    {
        max = items[0].age;
        for (int i = 1; i < items.size(); i++)
        {
            if (items[i].age > max)
            {
                max = items[i].age;
            }
        }
    }
    else if (attribute == "type")
    {
        max = items[0].type;
        for (int i = 1; i < items.size(); i++)
        {
            if (items[i].type > max)
            {
                max = items[i].type;
            }
        }
    }
    else if (attribute == "origin")
    {
        max = items[0].origin;
        for (int i = 1; i < items.size(); i++)
        {
            if (items[i].origin > max)
            {
                max = items[i].origin;
            }
        }
    }
    else if (attribute == "rarity") // I give it rarity but not sure for rarityScore
    {
        double maxd = items[0].rarityScore;
        for (int i = 1; i < items.size(); i++)
        {
            if (items[i].rarityScore > maxd)
            {
                maxd = items[i].rarityScore;
            }
        }
        return static_cast<int>(maxd);
    }
    else
    {
        std::cout << "Invalid attribute: " << attribute << std::endl;
    }

    return max;
}

// min = age - ageWindow
// max = age + ageWindow
// rarityScore = (1 - probability) * (1 + item.age/ageMax)
void calculateRarityScores(std::vector<Item> &items, int ageWindow)
{
    int ageMax = getMax(items, "age");
    for (int i = 0; i < items.size(); i++)
    {
        int min = items[i].age - ageWindow;
        int max = items[i].age + ageWindow;
        int countSimilar = 0;
        int countTotal = 0;
        double probability;

        for (int j = 0; j < items.size(); j++)
        {
            if (items[j].age >= min && items[j].age <= max)
            {
                countTotal++;  // The number of elements in the ageWindow including element itself 
                if (items[j].type == items[i].type && items[j].origin == items[i].origin)
                {
                    countSimilar++; // The number of similar elements including element itself
                }
            }
        }
        
        if (countTotal > 0)
        {
            probability = static_cast<double>(countSimilar) / countTotal;
        }
        else{
            probability = 0.0;
        }
        
        items[i].rarityScore = (1 - probability) * (1 + static_cast<double>(items[i].age) / ageMax);
    }
}