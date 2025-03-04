#include "methods.h"
#include <fstream>
#include <iomanip>
using namespace std; 

string trash;

Item createItem(int age, int type, int origin, double rarityScore)
{
    Item item;
    item.age = age;
    item.type = type;
    item.origin = origin;
    item.rarityScore = rarityScore;
    return item;
}


std::vector<Item> readItemsFromFile(const std::string &filename)
{
    std::vector<Item> items;

    ifstream file(filename);
    if (file.fail())
    {
        cout << "File is not open" << endl;
        return items;
    }
    if (file.is_open())
    {

        getline(file, trash); // Read the first line and put it into trash
        int age; 
        int type;  
        int origin;
        double rarityScore;

        while (!file.eof()) // End of the file = true
        {

            string ageStr, typeStr, originStr, rarityScoreStr;
            getline(file, ageStr, ',');
            getline(file, typeStr, ',');
            getline(file, originStr, ',');
            getline(file, rarityScoreStr, '\n');

            if (ageStr == "" || typeStr == "" || originStr == "" || rarityScoreStr =="") // If any of the strings are empty, break the loop
            {
                break;
            }

            age = stoi(ageStr); // stoi = string to integer, stod = string to double

            type = stoi(typeStr);

            origin = stoi(originStr);

            rarityScore = stod(rarityScoreStr); 

            // Create a Item object and add it to the vector

            items.push_back(createItem(age, type, origin, rarityScore));
        }
    }
    file.close();

    return items;
}

void writeItemsToFile(const std::string &filename, const std::vector<Item> &items)
{
    ofstream file(filename);
    if (file.fail())
    {
        cout << "File is not open" << endl;
    }
    if (file.is_open())
        file << trash << endl;
    {
        for (int i = 0; i < items.size(); i++)
        {
            file << items[i].age << "," << items[i].type << "," << items[i].origin << ","  << items[i].rarityScore; // << fixed << setprecision(1)
            if (i != items.size() - 1) // We don't want to add a new line at the end of the file
            {
                file << "\n";
            }
        }
    }
    trash.clear();
    file.close();
}
