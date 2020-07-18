#include <iostream>
#include "IS.hpp"

using namespace std;

void hybrid(int*, int, int, int);

void hybridSort(int* table, int H1, int H2)
{
    if (H1 < H2)
    {
        int H = (H1 + H2) / 2;
        if (H - H1 <= 10)
        {
            insertionSortHybrid(table, H1, H);
        }
        else if (H2 - (H + 1) <= 10)
        {
            insertionSortHybrid(table, H + 1, H2);
        }
        else
        {
            hybridSort(table, H1, H);
            hybridSort(table, H + 1, H2);
            hybrid(table, H1, H, H2);
        }
    }
    return;
}

// int* table, int left, int middle, int right
void hybrid(int* table, int H1, int H, int H2)
{
    int midTable[100005];

    int i = H1;
    int j = H + 1;
    int k = H1;

    // Jeœli otrzymamy ma³y podzbiór <= 10, odpalamy
    // Insertion Sort. Idea jest taka, ¿e dzielimy
    // zbiór do momentu a¿ otrzymamy na tyle ma³o elementów
    // aby sortowanie szybkie jak w³aœnie IS mog³o wykonaæ
    // operacjê dla ma³ego zbioru.

        while (i <= H && j <= H2)
        {
            if (table[i] <= table[j])
            {
                midTable[k] = table[i];
                i++;
            }
            else
            {
                midTable[k] = table[j];
                j++;
            }
            k++;
        }

        while (i <= H)
        {
            midTable[k] = table[i];
            i++;
            k++;
        }

        while (j <= H2)
        {
            midTable[k] = table[j];
            j++;
            k++;
        }

        for (i = H1; i <= H2; i++)
        {
            table[i] = midTable[i];
        }

}