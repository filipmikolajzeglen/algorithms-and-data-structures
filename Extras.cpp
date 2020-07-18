#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MS.hpp"
#include "IS.hpp"
#include "HS.hpp"

using namespace std;

// Funkcja tworz¹ca tablicê posortowan¹
int* createSortedTable(int numbers)
{
	// Tworzymy dynamiczn¹ tablicê
	int* table = new int[numbers];

	for (int i = 0; i < numbers; i++)
	{
		// Uzupe³niamy tablicê wartoœciami 
		// posortowanymi rosn¹co
		table[i] = i + 1;
	}
	return table;
}

// Funkcja tworz¹ca tablicê odwrotnie posortowan¹
int* createReverseSortedTable(int numbers)
{
	// Tworzymy dynamiczn¹ tablicê
	int* table = new int[numbers];

	for (int i = 0; i < numbers; i++)
	{
		// Uzupe³niamy tablicê wartoœciami 
		// posortowanymi malej¹co (odwrotnie)
		table[i] = numbers - i;
	}
	return table;
}

// Funkcja tworz¹ca tablicê losowo "posortowan¹"
int* createRandomSortedTable(int numbers)
{
	// Tworzymy dynamiczn¹ tablicê
	int* table = new int[numbers];
	srand(time(NULL));

	for (int i = 0; i < numbers; i++)
	{
		// Uzupe³niamy tablicê wartoœciami od 1 do x
		// posortowanymi losowo
		table[i] = (rand() % numbers) + 1;
	}
	return table;
}

// Funkcja do kopiowania zawartoœci alokowanej pamiêci
// typ size_t zamiast unsigned int
int* copy(int* table, size_t size) {
   int* tab = new int[size];
   for (size_t i = 0; i < size; ++i) {
      tab[i] = table[i];
   }
   return tab;
}

void bestTime(double t1, double t2, double t3)
{
	if (t1 < t2)
	{
		if (t1 < t3)
		{
			cout << t1 << "ms SORTED ELEMENTS" << endl;
		}
		else
		{
			cout << t3 << "ms RANDOM SORTED ELEMENTS" << endl;
		}
	}
	else
	{
		if (t2 < t3)
		{
			cout << t2 << "ms REVERSE SORTED ELEMENTS" << endl;
		}
		else
		{
			cout << t3 << "ms RANDOM SORTED ELEMENTS" << endl;
		}
	}
}

void bestOfBest(double merge, double insertion, double hybrid)
{
	if (merge < insertion)
	{
		if (merge < hybrid)
		{
			cout << merge << "ms FOR MERGE SORT (BEST)" << endl;
		}
		else
		{
			cout << hybrid << "ms FOR HYBRID SORT (BEST)" << endl;
		}
	}
	else
	{
		if (insertion < hybrid)
		{
			cout << insertion << "ms FOR INSERTION SORT (BEST)" << endl;
		}
		else
		{
			cout << hybrid << "ms FOR HYBRID SORT (BEST)" << endl;
		}
	}
}

void worstOfWorst(double merge, double insertion, double hybrid)
{
	if (merge > insertion)
	{
		if (merge > hybrid)
		{
			cout << merge << "ms FOR MERGE SORT (WORST)" << endl;
		}
		else
		{
			cout << hybrid << "ms FOR HYBRID SORT (WORST)" << endl;
		}
	}
	else
	{
		if (insertion > hybrid)
		{
			cout << insertion << "ms FOR INSERTION SORT (WORST)" << endl;
		}
		else
		{
			cout << hybrid << "ms FOR HYBRID SORT (WORST)" << endl;
		}
	}
}

double averageTime(double t1, double t2, double t3)
{
	return (t1 + t2 + t3) / 3;
}

void showTable(int* table, int numbers)
{
	for (int i = 0; i < numbers; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << "\t" << table[i];
	}
	cout << "\n\t" << " ---------------- " << endl;
}

void compareResultsOfSortedData(int numbers, string name)
{
	double t1, t2, t3, best; // Zmienne ogólne
	double mt1, mt2, mt3, mbest; // Zmienne dla Merge Sort
	double it1, it2, it3, ibest; // Zmienne dla Insertion Sort
	double ht1, ht2, ht3, hbest; // Zmienne dla Hybrid Sort

	int* tab1 = createSortedTable(numbers);
	int* tab2 = createReverseSortedTable(numbers);
	int* tab3 = createRandomSortedTable(numbers);

	// Wartoœci dla MS
	int* tableSortedMS = copy(tab1, numbers);
	int* tableReverseSortedMS = copy(tab2, numbers);
	int* tableRandomSortedMS = copy(tab3, numbers);

	// Wartoœci dla IS
	int* tableSortedIS = copy(tab1, numbers);
	int* tableReverseSortedIS = copy(tab2, numbers);
	int* tableRandomSortedIS = copy(tab3, numbers);

	// Wartoœci dla HS
	int* tableSortedHS = copy(tab1, numbers);
	int* tableReverseSortedHS = copy(tab2, numbers);
	int* tableRandomSortedHS = copy(tab3, numbers);

	delete tab1;
	delete tab2;
	delete tab3;

	cout << "\n " << name << " - " << numbers << endl;

	cout << "\n\tSORTED ELEMENTS: ----------------------------------------------------" << endl;
	clock_t startMS = clock();
	mergeSort(tableSortedMS, 0, numbers);
	clock_t stopMS = clock();
	mt1 = 1000 * (stopMS - startMS) / CLOCKS_PER_SEC;
	cout << "\n\tMerge Sort: " << mt1 << "ms\n";

	clock_t startIS = clock();
	insertionSort(tableSortedIS, numbers);
	clock_t stopIS = clock();
	it1 = 1000 * (stopIS - startIS) / CLOCKS_PER_SEC;
	cout << "\tInserion Sort: " << it1 << "ms\n";

	clock_t startHS = clock();
	hybridSort(tableSortedHS, 0, numbers);
	clock_t stopHS = clock();
	ht1 = 1000 * (stopHS - startHS) / CLOCKS_PER_SEC;
	cout << "\tHybrid Sort: " << ht1 << "ms\n\n";


	cout << "\tREVERSE SORTED ELEMENTS: --------------------------------------------" << endl;
	clock_t startRMS = clock();
	mergeSort(tableReverseSortedMS, 0, numbers);
	clock_t stopRMS = clock();
	mt2 = 1000 * (stopRMS - startRMS) / CLOCKS_PER_SEC;
	cout << "\n\tMerge Sort: " << mt2 << "ms\n";

	clock_t startRIS = clock();
	insertionSort(tableReverseSortedIS, numbers);
	clock_t stopRIS = clock();
	it2 = 1000 * (stopRIS - startRIS) / CLOCKS_PER_SEC;
	cout << "\tInserion Sort: " << it2 << "ms\n";

	clock_t startRHS = clock();
	hybridSort(tableReverseSortedHS, 0, numbers);
	clock_t stopRHS = clock();
	ht2 = 1000 * (stopRHS - startRHS) / CLOCKS_PER_SEC;
	cout << "\tHybrid Sort: " << ht2 << "ms\n\n";


	cout << "\tRANDOM SORTED ELEMENTS: ---------------------------------------------" << endl;
	clock_t startRaMS = clock();
	mergeSort(tableRandomSortedMS, 0, numbers);
	clock_t stopRaMS = clock();
	mt3 = 1000 * (stopRaMS - startRaMS) / CLOCKS_PER_SEC;
	cout << "\n\tMerge Sort: " << mt3 << "ms\n";

	clock_t startRaIS = clock();
	insertionSort(tableRandomSortedIS, numbers);
	clock_t stopRaIS = clock();
	it3 = 1000 * (stopRaIS - startRaIS) / CLOCKS_PER_SEC;
	cout << "\tInserion Sort: " << it3 << "ms\n";

	clock_t startRaHS = clock();
	hybridSort(tableRandomSortedHS, 0, numbers);
	clock_t stopRaHS = clock();
	ht3 = 1000 * (stopRaHS - startRaHS) / CLOCKS_PER_SEC;
	cout << "\tHybrid Sort: " << ht3 << "ms\n\n";


	cout << "\tANALYSIS EFFICIENCY FOR " << numbers << " ELEMENTS --------------------------------" << endl;
	cout << "\n\tTHE BEST TIME: " << endl;
	cout << "\t1) Merge sort: "; bestTime(mt1, mt2, mt3);
	cout << "\t2) Insertion sort: "; bestTime(it1, it2, it3);
	cout << "\t3) Hybrid sort: "; bestTime(ht1, ht2, ht3);

	cout << "\n\tAVERAGE TIME: " << endl;
	cout << "\t1) Merge sort: " << averageTime(mt1, mt2, mt3) << "ms" << endl;
	cout << "\t2) Insertion sort: " << averageTime(it1, it2, it3) << "ms" << endl;
	cout << "\t3) Hybrid sort: " << averageTime(ht1, ht2, ht3) << "ms" << endl;

	cout << "\n\tTHE BEST OF THE BEST: " << endl;
	cout << "\t1) Sorted elements "; bestOfBest(mt1, it1, ht1);
	cout << "\t2) Reverse sorted "; bestOfBest(mt2, it2, ht2);
	cout << "\t3) Random sorted "; bestOfBest(mt3, it3, ht3);

	cout << "\n\tTHE WORST OF THE WORST: " << endl;
	cout << "\t1) Sorted elements "; worstOfWorst(mt1, it1, ht1);
	cout << "\t2) Reverse sorted "; worstOfWorst(mt2, it2, ht2);
	cout << "\t3) Random sorted "; worstOfWorst(mt3, it3, ht3);

	cout << "v 2.8";
}