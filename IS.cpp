void insertionSort(int* table, int size)
{
    int temp, i, j;
    for (i = 1; i < size; i++)
    {
        temp = table[i];
        for (j = i - 1; j >= 0 && table[j] > temp; --j)
        {
            table[j + 1] = table[j];
        }
        table[j + 1] = temp;
    }
}

void insertionSortHybrid(int* table, int start, int end)
{
    int temp, i, j;
    // Zaczynamy pêtlê od wartoœci, która nas interesuje
    // Koñczymy j¹ na ostatniej wartoœci w tablicy
    for (i = start; i < end; i++)
    {
        temp = table[i];
        for (j = i - 1; j <= end && table[j] > temp; --j)
        {
            table[j + 1] = table[j];
        }
        table[j + 1] = temp;
    }
}