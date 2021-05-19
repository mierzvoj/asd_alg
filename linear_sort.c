#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//te definicje tablic o ma�ym rozmiarze s�uz� do przegl�dania poprawno�ci dzia�ania algorytm�w
#define ROZMIAR 10000           
int TabWe[ROZMIAR+1];			//dane wejsciowe do sortowania sa przepisywane do tablicy TabSort tu� przed sortowaniem
int TabSort[ROZMIAR+1];			
int TabBin[7] = {0,1,1,0,1,0,1}; //tablica z zadania

//-----------------------------------------------------------------------------------------------------

void  WyswietlTablice (int *t, int rozmiar) 
{
int i;
	for(i=0; i<rozmiar; i++) printf(" %d", t[i]);
	printf("\n");
}

//s�uzy do przepisania zr�d�a danych czyli tablicy wejsciowej, do tablicy na kt�rej zostanie wykonane sortowanie tych danych
void PrzepiszTablice( int *tabDane, int* tabSort, int rozmiar)
{
int i;
	for (i=0; i<rozmiar;i++) {
		tabSort[i]=tabDane[i];
	}
}
//generowanie danych;
void PodstawLosoweDane(int *tabDane, int rozmiar) 
{
int i;
unsigned zakres_losowy=rozmiar<100 ? 100: 16000; 

	srand( (unsigned)time( NULL ) ); 
	for(i=0; i<rozmiar; i++) {
		tabDane[i]=rand()%(zakres_losowy); 
	
	}
}
void PodstawPosegregowaneDane(int *tabDane, int rozmiar) 
{
int i;
	for(i=0; i<rozmiar; i++) {
		tabDane[i]=i+1; 
	}
}
void PodstawOdwrotniePosegregowaneDane(int *tabDane, int rozmiar) 
{
int i;
	for(i=0; i<rozmiar; i++) {
		tabDane[i]=rozmiar-i; 
	}
}
//===============================================================================	
//sortowanie tablicy kt�ra posiada zmienne tylko o dwoch warto�ciach
//O(n)	-	Algorytm o liniowej zale�no�ci czasu wykonania od liczby danych przechodzi tylko raz po wszystkich indeksach
// tab tablica do sortowania
// N rozmiar;
void BinarnySort(int *tab,  int N)  
{
	int i,j;
	int vmax; 
    i=N-2; //przedostatni indeks
	j=N-1; //ostatni indeks
	//badanie tablicy od ostatnich indeksow w g�r�
	while(i>=0) {
		if(tab[i]==tab[j]) i--; // zmien i, j zostaw, rob tak dlugo az bedzie zmiana. Na pocz�tku w ogole nie wiadomo, kt�ra liczba jest wi�ksza kontynuuj dopoki nie ma zmian
		else {
			if(tab[i]>tab[j]) { //jezeli to tab[i] jest wi�ksza przestaw w tablicy na poz j
				vmax=tab[i];     //tab[i] jest wieksz� liczb� 
				tab[i]=tab[j]; 
				tab[j]=vmax;
			}
			else vmax=tab[j];   //tzn  tab[j] by�o wieksza 
			j--;
     		while((j>=0) && (tab[j]==vmax)) { //teraz kontynuuj po j sprawdzaj�c w gor� jak d�ugo w kolejnych malale�cych indeksach utrzymuje si� max
			    j--;  //dopoki indeks nie przekroczy zakresu lub warto�� tab[j] si� nie zmieni, wartosc "j" w wielu wypadkacjh mo�e przekroczy� "i" szczeg�lnie jak pod rz�d w g�r� s� maksy 
			}
			i=j; //jak nie zosta�y przekroczone indeksy to w tab[j] jest minimalnna liczba, korekta indeksu "i"
			i--; // kontynuuj (while(i>=0) i musi by� mniejsze od j
		}
	}
}

//===============================================================================

int main()
{
int i,k;
int   N;      //liczba danych wejsciowych
clock_t start, finish;
int liczbaPowtorzen; //liczba powtorzen

//teraz liczmy czas  dla du�ej liczby elementow

	printf("\nZadanie nr 3\n");
	N=7;
	PrzepiszTablice( TabBin, TabSort, N); //0-6 i=3,k=4,5,6, 0-7 i=3 k=4,5,6,7
	printf("Dane wejsciowe:    ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	BinarnySort(TabSort,  N);
	printf("fun. BinarnySort:  ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	
	N=20;
	//sprawdzenie dla innej dwuwarto�ciowej tablicy
	printf("\ntest na innych danych\n");
	
	for(i=0; i<N; i++) TabSort[i]= rand()%2? 8:4;
	printf("Dane wejsciowe:    ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	BinarnySort(TabSort,  N);
	printf("fun. BinarnySort:  ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	
	
	for(i=0; i<N; i++) TabSort[i]= i<N/2? 1:2;
	printf("Dane wejsciowe:    ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	BinarnySort(TabSort,  N);
	printf("fun. BinarnySort:  ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy

	for(i=0; i<N; i++) TabSort[i]= i<N/2? 2:1;
	printf("Dane wejsciowe:    ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	BinarnySort(TabSort,  N);
	printf("fun. BinarnySort:  ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	

	
}


