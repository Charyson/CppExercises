#include <iostream>

using namespace std;

// Poczatek deklaracji klasy
class VectorInt 
{
public:
  int* tab;
  int maxSize; // na ile elementów zaalokowana jest pamiêæ
  int currentSize; // indeks ostatniego elementu w tablicy
  
  VectorInt() // konstruktor bezargumentowy
  {
    // TODO: w tym miejscu trzeba dopisaæ alokacje pamiêci na 16 liczb.
    // Bêdzie to bardzo podobne do tego konstruktora poni¿ej
  }
  
  // konstruktor z argumentem size. Oznacza liczbê elementów, 
  // dle których zaalokujemy pamiêæ
  VectorInt(unsigned int size) 
  {
    tab = new int [size];
    maxSize = size;
    currentSize = 0;
  }
  
  void Insert(int index, int value)
  {
       // Wstawiamy wartoœc tylko wtedy, gdy podany indeks nie przekracza maksymalnego rozmiaru tablicy
       if (index < maxSize)
       {
         tab[index] = value;
         
         // Je¿eli indeks jest powy¿ej naszego currentSize, to musimy zaktualizowaæ
         // wartoœc currentSize
         if (currentSize <= index)
         {
           currentSize = index + 1;
         }
       }
  }
  
  int Size ()
  {
      // TODO: tutaj trzeba dopisaæ metodê size, która zwróci liczbê elementów
      // aktualnie przechowywanych w tablicy. Bêdzie ona bardzo prosta. Musisz wykorzystaæ
      // jedn¹ z zmiennych w tej klasie - tab, maxSize lub currentSize. Wybierz w³aœciw¹
  }
  
  // TODO: Tutaj trzeba dopisaæ metodê Capacity. Bêdzie ona równie prosta jak 
  // metoda Size, ale dla ma³ego utrudnienia nie podajê sygnatury tej metody
  // Sygnatura metody Size to "int Size ()", tak jak wy¿ej.
  
  // Ta deklaracja przeci¹¿enia operatora jest potrzebna, aby ³atwo korzystaæ z cout <<
  friend ostream & operator<< (ostream &outStream, VectorInt const& vector);
};

// Koniec deklaracji klasy

// To przeci¹¿enie operatora jest nam porzebne aby ³atwo korzystaæ z cout <<
ostream& operator<< (ostream &outStream, VectorInt const& vector)
  {
    if (vector.currentSize <= 0)
    {
        outStream << "Tablica jest pusta";
    }
    else
    {
        for (int i = 0; i < vector.currentSize; i++)
        {
            outStream << vector.tab[i] << " ";
        }
    }
  }

// W³aœciwy program
int main ()
{
  // Tworzymy obiekt wektora
  VectorInt* vector1 = new VectorInt(8);
  
  // Wpisujemy wartoœci do naszej tablicy. Celowo nie s¹ one w kolejnoœci, 
  // ¿eby upewniæ siê, ¿e metoda Insert dzia³a jak nale¿y
  vector1->Insert(0, 2); // Wpisz liczbe 2 pod indeksem 0
  vector1->Insert(5,10);
  vector1->Insert(1,-5);
  vector1->Insert(3,4);
  vector1->Insert(4,26);
  vector1->Insert(2,40);
  
  // Wypisujemy tablicê
  cout << (*vector1);
  cout << endl; 
  // Uwaga: coœ takiego jak cout << (*vector1) << endl nie zadzia³a w tej chwili.
  // Musi to byæ w osobnych liniach, najpier cout << (*vector1), potem cout << endl.
  
  // Wypiszmy rozmiar tablicy. Na razie ten rozmiar jest nieprawid³owy, 
  // bo metoda Size nie zosta³a zaimplementowana
  cout << "Aktualny rozmiar tablicy to " << vector1->Size();
  
  getchar();
  return 0;
}
