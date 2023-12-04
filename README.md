![plot.png](plot.png)

Zmodyfikować jedną wybraną implementację i dodać instrukcje zliczające dominujące operacje.
Obliczyć złożoność obliczeniową pesymistyczną, średnią i optymistyczną oraz w miarę możliwości
pesymistycznej. Sprawdzić dla losowych danych i tablicy posortowanej, czy liczba wykonanych oper-
acji dominujących zgadza się oszacowaniami.

Selction sort posiada 2 petle, pierwsza zewnetrzna ktora wykonuje sie n-1 razy orazz wewneetrzna ktora
dla kazdej  iteracji petli zewnetrznej wykonuje sie kolejno n-2, n-3 etc az do 1.
Z tego wynika ze ilosc operacji porownania dla selection sort mozna opisac wzorem:
(n-1) + (n-2) + ... + 1 co sprowadza sie z wzoru ciagu arytmetycznego do:
n(n-1)/2
SelectionSort dla 7 elementowego zbioru.

1. Pesymistycznie [7,1,2,3,4,5,6]
   ()
   Comparisions: 21 Swaps: 6
   
   n-1 swapow =>  O(n)
   
   n(n-1)/2 Comparisions => O(n^2)
2. Optymstycznie: Nasza tablica jest juz posortowana [1,2,3,4,5,6,7]

   Comparisions: 21 Swaps: 0

   0 swapow =>  O(1)

   n(n-1)/2 Comparisions => O(n^2)
3. Average case: Nasza tablica ma losowy uklad elementow:
  Tutaj testy przeprowadzilem kilka razy dla 100 000 losowych elementow, aby okreslic oczekiwana liczbe swapow i porownan.
   Comparisions: 704982704, zgadza sie z wzorem.
   Swapy: ~99988 w kilku probach z czego mozna wnioskowac ze ilosc swapow jest proporcjonalna do n dla average case.

