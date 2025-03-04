#include "methods.h"
#include <algorithm>

std::vector<Item> ascendingCountingSort(std::vector<Item> &items, const std::string &attribute)
{
    int k = items.size();
    std::vector<Item> sortedArray(k);

    int max = 0;

    if (attribute == "age")
    {
        // max yaşı bulduk
        for (int i = 0; i < k; i++)
        {
            if (items[i].age > max)
            {
                max = items[i].age;
            }
        }
        // count arrayin uzunluğunu max +1 olacak şekilde ve tamamına 0 vererek başlattık.
        std::vector<int> count(max + 1, 0);
        // count arraydeki 0 olarak başlattığımız değerleri items arrayinde ilgili yaşı buldukça arttırdık. Yani o yaşa indexledik.
        for (int i = 0; i < k; i++)
        {
            count[items[i].age]++;
        }
        // count arraydeki değerleri bir önceki değerle topladık. pre sum yaptık.
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }
        // tersten başlayarak items arrayini count arraydeki değerlere göre sıraladık. count arraydeki değerleri de her seferinde 1 azalttık.
        for (int i = k - 1; i >= 0; i--)
        {
            sortedArray[count[items[i].age] - 1] = items[i];
            count[items[i].age]--;
        }
    }
    else if (attribute == "type")
    {
        for (int i = 0; i < k; i++)
        {
            if (items[i].type > max)
            {
                max = items[i].type;
            }
        }

        std::vector<int> count(max + 1, 0);

        for (int i = 0; i < k; i++)
        {
            count[items[i].type]++;
        }

        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = k - 1; i >= 0; i--)
        {
            sortedArray[count[items[i].type] - 1] = items[i];
            count[items[i].type]--;
        }
    }
    else if (attribute == "origin")
    {
        for (int i = 0; i < k; i++)
        {
            if (items[i].origin > max)
            {
                max = items[i].origin;
            }
        }

        std::vector<int> count(max + 1, 0);

        for (int i = 0; i < k; i++)
        {
            count[items[i].origin]++;
        }

        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = k - 1; i >= 0; i--)
        {
            sortedArray[count[items[i].origin] - 1] = items[i];
            count[items[i].origin]--;
        }
    }

    return sortedArray;
}

std::vector<Item> descendingCountingSort(std::vector<Item> &items, const std::string &attribute)
{
    int k = items.size();
    std::vector<Item> sortedArray(k);

    if (attribute == "age")
    {
        int max = 0;
        // Find the maximum age
        for (int i = 0; i < k; i++)
        {
            if (items[i].age > max)
            {
                max = items[i].age;
            }
        }
        // Initialize count array with zeros
        std::vector<int> count(max + 1, 0);
        // Count the occurrences of each age
        for (int i = 0; i < k; i++)
        {
            count[items[i].age]++;
        }
        // Calculate the prefix sums
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }
        // Sort the items in descending order
        for (int i = 0; i < k; i++)
        {
            sortedArray[k - count[items[i].age]] = items[i];
            count[items[i].age]--;
        }
    }
    else if (attribute == "type")
    {
        int max = 0;
        // Find the maximum type
        for (int i = 0; i < k; i++)
        {
            if (items[i].type > max)
            {
                max = items[i].type;
            }
        }
        // Initialize count array with zeros
        std::vector<int> count(max + 1, 0);
        // Count the occurrences of each type
        for (int i = 0; i < k; i++)
        {
            count[items[i].type]++;
        }
        // Calculate the prefix sums
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }
        // Sort the items in descending order
        for (int i = 0; i < k; i++)
        {
            sortedArray[k - count[items[i].type]] = items[i];
            count[items[i].type]--;
        }
    }
    else if (attribute == "origin")
    {
        int max = 0;
        // Find the maximum origin
        for (int i = 0; i < k; i++)
        {
            if (items[i].origin > max)
            {
                max = items[i].origin;
            }
        }
        // Initialize count array with zeros
        std::vector<int> count(max + 1, 0);
        // Count the occurrences of each origin
        for (int i = 0; i < k; i++)
        {
            count[items[i].origin]++;
        }
        // Calculate the prefix sums
        for (int i = 1; i <= max; i++)
        {
            count[i] += count[i - 1];
        }
        // Sort the items in descending order
        for (int i = 0; i < k; i++)
        {
            sortedArray[k - count[items[i].origin]] = items[i];
            count[items[i].origin]--;
        }
    }

    return sortedArray;
}

std::vector<Item> countingSort(std::vector<Item> &items, const std::string &attribute, bool ascending)
{
    if (ascending)
    {
        items = ascendingCountingSort(items, attribute);
    }
    else
    {
        items = descendingCountingSort(items, attribute);
    }
    return items;
}

void heapifyMax(std::vector<Item> &items, int n, int i)
{
    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && items[l].rarityScore > items[largest].rarityScore)
    {
        largest = l;
    }
    // If right child is larger than largest so far
    if (r < n && items[r].rarityScore > items[largest].rarityScore)
    {
        largest = r;
    }
    // If largest is not root
    if (largest != i)
    {
        std::swap(items[i], items[largest]);

        // Recursively heapify the affected sub-tree
        heapifyMax(items, n, largest);
    }
}

void heapifyMin(std::vector<Item> &items, int n, int i)
{
    // Initialize smallest as root
    int smallest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is smaller than root
    if (l < n && items[l].rarityScore < items[smallest].rarityScore)
    {
        smallest = l;
    }
    // If right child is smaller than smallest so far
    if (r < n && items[r].rarityScore < items[smallest].rarityScore)
    {
        smallest = r;
    }
    // If smallest is not root
    if (smallest != i)
    {
        std::swap(items[i], items[smallest]);

        // Recursively heapify the affected sub-tree
        heapifyMin(items, n, smallest);
    }
}

// Function to heapify a subtree rooted with node i in the array of items
void heapify(std::vector<Item> &items, int n, int i, bool descending)
{
    if (descending)
    {
        heapifyMin(items, n, i);
    }
    else
    {
        heapifyMax(items, n, i);
    }
}

// Function to perform heap sort on rarityScore scores of items
std::vector<Item> heapSortByRarity(std::vector<Item> &items, bool descending)
{
    int n = items.size();

    // Build heap (rearrange vector)
    for(int i = n / 2 - 1; i >= 0; i--) {  // n/2 -1 non leaf olan son elemanın indexi 
    // bundan başlayarak diğer non leaf elemanlara gidiyoruz ve sırayla heapify ediyoruz
        heapify(items, n, i, descending);
    }

    // One by one extract an element from heap
    for (int i = n -1 ; i > 0; i--)
    {
        // Move current root to end
        std::swap(items[0], items[i]);

        //Call max heapify on the reduced heap 
        heapify(items, i, 0, descending); // i = n-1 durumunda yani son elemanı ki şuanda bu 
                    // ilk durumdaki root değerini tutuyor, devre dışı bıraktık ve kalan diziyi heapify edip durduk.
    }
    return items;
}
