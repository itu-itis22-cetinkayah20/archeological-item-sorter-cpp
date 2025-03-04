#include "methods.h"
#include <chrono>
using namespace std;
int main() 
{
  
  std::vector<Item> items = readItemsFromFile("data/items_s.csv");
  // std::cout << getMax(items, "age") << std::endl;
  
  // auto start = chrono::high_resolution_clock::now();
  std::vector<Item> sorted = countingSort(items, "age", true);
  // auto end = chrono::high_resolution_clock::now();
  // auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end - start);
  // cout << "Elapsed time for counting sort algorithm: " << elapsed_time.count() << " microseconds" << endl;

  

  // auto start = chrono::high_resolution_clock::now();
  calculateRarityScores(sorted, 50);
  // auto end = chrono::high_resolution_clock::now();
  // auto elapsed_time = chrono::duration_cast<chrono::milliseconds>(end - start);
  // cout << "Elapsed time for counting sort algorithm: " << elapsed_time.count() << " milliseconds" << endl;

  auto start = chrono::high_resolution_clock::now();
  std::vector<Item> sorted2 = heapSortByRarity(sorted, true);
  auto end = chrono::high_resolution_clock::now();
  auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end - start);
  cout << "Elapsed time for counting sort algorithm: " << elapsed_time.count() << " milliseconds" << endl;

  writeItemsToFile("data/items_l_sorted.csv", sorted2);
   
  // writeItemsToFile("data/items_l_rarity.csv", sorted);
  // sorted = heapSortByRarity(sorted, true);
  // writeItemsToFile("data/items_l_rarity_sorted.csv", sorted);

  return 0;
}