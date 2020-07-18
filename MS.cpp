#include <iostream>

using namespace std;

void merge(int*, int, int, int);

void mergeSort(int* table, int H1, int H2)
{
    int H;
    if (H1 < H2)
    {
        H = (H1 + H2) / 2;
        mergeSort(table, H1, H);
        mergeSort(table, H + 1, H2);
        merge(table, H1, H, H2);
    }
    return;
}

void merge(int* table, int H1, int H, int H2)
{
    int midTable[100005];

    int i = H1; 
    int j = H + 1; 
    int k = H1; 

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

