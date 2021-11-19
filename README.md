# PRG1-matrix-calculator
Projekt zaliczeniowy na przedmiot PRG1

## Funkcjonalność
Program pozwala na wykonywanie następujących obliczeń na macierzach:
- dodawanie
- odejmowanie
- mnożenie (przez macierz i skalar)
- transponowanie
- obliczanie wyznacznika
- odwracanie macierzy 2x2 i 3x3

Przy wykorzystaniu lini poleceń do wprowadzania danych wejściowych w postaci pliku. Wynik jest podawany na standardowym wyjściu (std::cout) oraz opcjonalnie zapisywany jest w pliku.

## Uruchomienie projektu
1. W folderze ```code-blocks-project``` znajduje się wyeksportowany projekt do środowiska code::blocks. Testowany pod ubuntu 20.04 z kompilatorem gcc/g++. Program kompiluje się do folderu ```code-blocks-project/PRG/bin/Debug/```,  Przed uruchomieniem trzeba wziąć pod uwagę to iż architektura programu wymaga podania argumentów w wierszu poleceń, opisanych dalej w tym dokumencie.
2. W głównym folderze znajduje się skrypt wykorzystywany podczas dewelopment-u - ```buildAndRun.sh``` - zawiera on komendę budowania oraz wielokrotnego uruchomienia z różnymi parametrami w celu weryfikacji poprawności danych wyjściowych. Jego działanie było testowane pod systemami osx 11.06 i ubuntu 20.04.

## Format pliku wejściowego oraz wyjściowego
macierz.txt
```
-1 2 3 4
5 -6 7 8
0.9 10 0.11 12
-13 14 15 -16
```
Poszczególne elementy macierzy przechowywane są oddzielone od siebie białym znakiem (spacja, tab etc), nowa linia symbolizuje przejście do następnego wiersza. Przykładowe pliki są przechowywane w głównym katalogu repozytorium.

## Składnia
```
./main [komenda] [skalar?] [macierz1] [macierz2?] [-s [nazwaPliku]?]
```
```[komenda]```: element obowiązkowy, definiuje wykonywane działanie na macierz(y/ach).
```[macierz1]```: ścieżka do pliku z macierzą - pierwszy parametr działania.
```[macierz2]```: ścieżka do pliku z macierzą.

### Lista komend z przykładami
#### Transpozycja macierzy  ```transpose``` 
```
./main transpose macierz.txt
```
#### Odwracanie macierzy 2x2 i 3x3  ```inverse``` 
```
./main inverse macierz.txt
```
#### Dodawanie macierzy  ```add``` 
```
./main add macierz1.txt macierz2.txt
```
#### Odejmowanie macierzy ```subtract``` 
```
./main subtract macierz1.txt macierz2.txt
```
#### Mnożenie macierzy ```multiply``` 
1. Przez skalar
	```
	./main multiply 3.14 macierz1.txt
	```
2. Przez drugą macierz
	```
	./main subtract macierz1.txt macierz2.txt
	```
#### Obliczanie wyznacznika
```
./main determinant macierz.txt
```
### Zapis do pliku
Dokonywany jest przy dodaniu do lini komend parametru s ```-s [nazwa pliku]```
```
./main determinant macierz.txt -s plik_wyjsciowy.txt
```