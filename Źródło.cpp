#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct node {
	int val;
	node* next;
	node* prev;
};


struct var {
	node* head;
	node* tail;
};

void init(var& H) {
	H.head = H.tail = NULL;
}

void add(var& H, int x) {
	node* p = new node;
	p->val = x;
	p->prev = NULL;
	p->next = H.head;
	H.head = p;
	if (p->next) {
		p->next->prev = p;
	}
	else {
		H.tail = p;
	}
}

void add2(var& H, int x)
{
	node* p = new node;
	p->val = x;
	p->next = NULL;
	p->prev = H.tail;
	H.tail = p;
	if (p->prev) {
		p->prev->next = p;
	}
	else {
		H.head = p;
	}
}

void del(node*& H) {
	if (H != NULL) {
		node* p = H;
		H = p->next;
		delete p;
	}
}

void show(var& H) {
	node* p = H.head;
	cout << "HEAD->";
	while (p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void copy(var& H, var& H2) {
	node* p = H.head;
	while (p != NULL) {
		add2(H2, p->val);
		p = p->next;
	}
}

int size(node*& H) {

	node* p = H;
	int i = 0;

	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

void Merge(var& H1, var& H2, var& H) {
	add(H, 0);
	node* T = H.head;
	while (H1.head && H2.head)
	{
		if (H1.head->val < H2.head->val)
		{
			T->next = H1.head;
			H1.head = H1.head->next;
			T = T->next;
		}
		else
		{
			T->next = H2.head;
			H2.head = H2.head->next;
			T = T->next;
		}
	}
	if (H1.head == NULL)
	{
		T->next = H2.head;
		H2.head = NULL;
	}
	else
	{
		T->next = H1.head;
		H1.head = NULL;
	}
	del(H.head);
}

void MergeSort(var& H) {
	if (H.head != NULL && (H.head->next) != NULL) {
		node* p = H.head;
		var H1;
		init(H1);
		var H2;
		init(H2);

		H1.head = H.head;
		int m = size(H.head);
		for (int i = 0; i < (m / 2 - 1); i++) {
			p = p->next;
		}
		H2.head = p->next;
		p->next->prev = NULL;
		p->next = NULL;
		H.head = NULL;

		MergeSort(H1);
		MergeSort(H2);

		Merge(H1, H2, H);
	}
}

void InsertSort(var& H2) {
	node* p = H2.head;
	node* k = NULL;
	node* last = NULL;
	for (p = H2.head->next; p != NULL;) {
		node* next = p->next;
		last = p;
		for (k = p->prev; k != NULL; k = k->prev) {
			if (p->val < k->val) {
				if (p->prev) {
					p->prev->next = p->next;
				}
				if (p->next) {
					p->next->prev = p->prev;
				}
				p->next = p->prev;
				p->prev = p->next->prev;
				p->next->prev = p;
				if (p->prev) {
					p->prev->next = p;
				}
			}
		}
		p = next;
	}
	while (last) {
		H2.head = last;
		last = last->prev;
	}
}

void SortowanieHybrydowe(var& H) {

	if (H.head != NULL && (H.head->next) != NULL) {
		if (size(H.head) <= 10) {
			InsertSort(H);
		}
		else {
			node* p = H.head;
			var H1;
			init(H1);
			var H2;
			init(H2);

			H1.head = H.head;
			int m = size(H.head);
			for (int i = 0; i < (m / 2 - 1); i++) {
				p = p->next;
			}

			H2.head = p->next;
			p->next->prev = NULL;
			p->next = NULL;
			H.head = NULL;


			SortowanieHybrydowe(H1);
			SortowanieHybrydowe(H2);

			Merge(H1, H2, H);
		}
	}
}

void pokaz_sortuj(var& H) {
	int czas_start = 0;
	int czas_stop = 0;

	var H1;
	init(H1);
	copy(H, H1);
	var H2;
	init(H2);
	copy(H, H2);

	//show(H);
	cout << endl << "MergeSort:  " << endl;
	czas_start = clock();
	MergeSort(H);
	czas_stop = clock();
	//show(H);
	cout << "Czas dzialania:  " << czas_stop - czas_start << " [ms]" << endl;

	cout << endl << "InsertSort:  " << endl;
	czas_start = clock();
	InsertSort(H1);
	czas_stop = clock();
	//show(H1);
	cout << "Czas dzialania:  " << czas_stop - czas_start << " [ms]" << endl;

	cout << endl << "Sortowanie Hybrydowe:  " << endl;
	czas_start = clock();
	SortowanieHybrydowe(H2);
	czas_stop = clock();
	//show(H2);
	cout << "Czas dzialania:  " << czas_stop - czas_start << " [ms]" << endl;
}

int main() {
	srand(time(NULL));

	var H100;
	init(H100);
	var H101;
	init(H101);
	var H102;
	init(H102);

	for (int i = 0; i < 100; i++) {
		add2(H100, i);
		add(H101, i);
		add(H102, rand() % 100);
	}

	cout << endl << "Lista 100 elementowa posortowana: " << endl;
	pokaz_sortuj(H100);
	cout << endl << "Lista 100 elementowa odwrotnie posortowana: " << endl;
	pokaz_sortuj(H101);
	cout << endl << "Lista 100 elementowa przypadkowa: " << endl;
	pokaz_sortuj(H102);


	var H1000;
	init(H1000);
	var H1001;
	init(H1001);
	var H1002;
	init(H1002);

	for (int i = 0; i < 1000; i++) {
		add2(H1000, i);
		add(H1001, i);
		add(H1002, rand() % 1000);
	}

	cout << endl << "Lista 1000 elementowa posortowana: " << endl;
	pokaz_sortuj(H1000);
	cout << endl << "Lista 1000 elementowa odwrotnie posortowana: " << endl;
	pokaz_sortuj(H1001);
	cout << endl << "Lista 1000 elementowa przypadkowa: " << endl;
	pokaz_sortuj(H1002);

	var H10000;
	init(H10000);
	var H10001;
	init(H10001);
	var H10002;
	init(H10002);

	for (int i = 0; i < 10000; i++) {
		add2(H10000, i);
		add(H10001, i);
		add(H10002, rand() % 10000);
	}

	cout << endl << "Lista 10000 elementowa posortowana: " << endl;
	pokaz_sortuj(H10000);
	cout << endl << "Lista 10000 elementowa odwrotnie posortowana: " << endl;
	pokaz_sortuj(H10001);
	cout << endl << "Lista 10000 e