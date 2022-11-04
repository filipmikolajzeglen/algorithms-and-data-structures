# Algorytmy i struktury danych - ćwiczenia laboratoryjne
Program został stworzony jako doświadczenie w ramach zajęć na studiach z algorytmów i struktur danych. Celem programu było sprawdzenie wydajności algorytmów sortowania: Merge Sort, Insertion Sort oraz Hybrid sort, który powinien być połączeniem poprzedenich dwóch algorytmów. Program podaje wynik działania w milisekundach (ms). 

## Wnioski z obserwacji
Insertion Sort zalicza się do prostych metod sortowania. Sprawdza się najlepiej dla małych zbiorów lub zbiorów, które są mniej więcej posortowane.

### Sposób działania sortowania przez wstawianie (insertion sort)
- **Krok pierwszy: podział zbioru na część posortowaną i nieposortowaną**
  - pusta i cała tabluca LUB,
  - pierwszy rekord i reszta LUB,
  - pewna naturalnie posortowana część i reszta.
- **Krok drugi --> pętla:**
  - pobranie rekordu (pierwszego lepszego) i wstawienie go do posortowanej części tablicy. 
- **Sposób przeglądania posortowanej części:**
  - sekwencyjne przeglądanie posortowanej części od prawej strony czego rezultatem jest stabilność oraz natychmiastowe przestawienie rekordu,
  - przeszukiwanie binarne.
- **Zalety:**
  - wydajny dla danych wstępnie posortowanych: O(n + d), gdzie d oznacza ilość inwersji,
  - dobry dla małych zbiorów do 10 elementów,
  - stabilny.

...

Hybrid Sort został stworzony tak aby wykorzystywać sortowanie przez scalanie (Merge Sort) do momentu aż w zbiorze zostanie tylko 10 elementów lub mniej. Wtedy uruchamiany jest algorytm sortowania przez wstawianie co pozwala usprawnić mechanizm sortowania dla wielkich zbiorów elementów.
