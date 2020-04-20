#include <iostream>

using namespace std;

// Poczatek deklaracji klasy
class VectorInt 
{
public:
  int* tab;
  int maxSize; // na ile element�w zaalokowana jest pami��
  int currentSize; // indeks ostatniego elementu w tablicy
  
  VectorInt() // konstruktor bezargumentowy
  {
    // TODO: w tym miejscu trzeba dopisa� alokacje pami�ci na 16 liczb.
    // B�dzie to bardzo podobne do tego konstruktora poni�ej
  }
  
  // konstruktor z argumentem size. Oznacza liczb� element�w, 
  // dle kt�rych zaalokujemy pami��
  VectorInt(unsigned int size) 
  {
    tab = new int [size];
    maxSize = size;
    currentSize = 0;
  }
  
  void Insert(int index, int value)
  {
       // Wstawiamy warto�c tylko wtedy, gdy podany indeks nie przekracza maksymalnego rozmiaru tablicy
       if (index < maxSize)
       {
         tab[index] = value;
         
         // Je�eli indeks jest powy�ej naszego currentSize, to musimy zaktualizowa�
         // warto�c currentSize
         if (currentSize <= index)
         {
           currentSize = index + 1;
         }
       }
  }
  
  int Size ()
  {
      // TODO: tutaj trzeba dopisa� metod� size, kt�ra zwr�ci liczb� element�w
      // aktualnie przechowywanych w tablicy. B�dzie ona bardzo prosta. Musisz wykorzysta�
      // jedn� z zmiennych w tej klasie - tab, maxSize lub currentSize. Wybierz w�a�ciw�
  }
  
  // TODO: Tutaj trzeba dopisa� metod� Capacity. B�dzie ona r�wnie prosta jak 
  // metoda Size, ale dla ma�ego utrudnienia nie podaj� sygnatury tej metody
  // Sygnatura metody Size to "int Size ()", tak jak wy�ej.
  
  // Ta deklaracja przeci��enia operatora jest potrzebna, aby �atwo korzysta� z cout <<
  friend ostream & operator<< (ostream &outStream, VectorInt const& vector);
};

// Koniec deklaracji klasy

// To przeci��enie operatora jest nam porzebne aby �atwo korzysta� z cout <<
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

// W�a�ciwy program
int main ()
{
  // Tworzymy obiekt wektora
  VectorInt* vector1 = new VectorInt(8);
  
  // Wpisujemy warto�ci do naszej tablicy. Celowo nie s� one w kolejno�ci, 
  // �eby upewni� si�, �e metoda Insert dzia�a jak nale�y
  vector1->Insert(0, 2); // Wpisz liczbe 2 pod indeksem 0
  vector1->Insert(5,10);
  vector1->Insert(1,-5);
  vector1->Insert(3,4);
  vector1->Insert(4,26);
  vector1->Insert(2,40);
  
  // Wypisujemy tablic�
  cout << (*vector1);
  cout << endl; 
  // Uwaga: co� takiego jak cout << (*vector1) << endl nie zadzia�a w tej chwili.
  // Musi to by� w osobnych liniach, najpier cout << (*vector1), potem cout << endl.
  
  // Wypiszmy rozmiar tablicy. Na razie ten rozmiar jest nieprawid�owy, 
  // bo metoda Size nie zosta�a zaimplementowana
  cout << "Aktualny rozmiar tablicy to " << vector1->Size();
  
  getchar();
  return 0;
}
