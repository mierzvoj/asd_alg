#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//te definicje tablic o ma³ym rozmiarze s³uz¹ do przegl¹dania poprawnoœci dzia³ania algorytmów
#define ROZMIAR 10000           
int TabWe[ROZMIAR+1];			//dane wejsciowe do sortowania sa przepisywane do tablicy TabSort tu¿ przed sortowaniem
int TabSort[ROZMIAR+1];			
int TabBin[7] = {0,1,1,0,1,0,1}; //tablica z zadania

//-----------------------------------------------------------------------------------------------------

void  WyswietlTablice (int *t, int rozmiar) 
{
int i;
	for(i=0; i<rozmiar; i++) printf(" %d", t[i]);
	printf("\n");
}

//s³uzy do przepisania zród³a danych czyli tablicy wejsciowej, do tablicy na której zostanie wykonane sortowanie tych danych
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
//sortowanie tablicy która posiada zmienne tylko o dwoch wartoœciach
//O(n)	-	Algorytm o liniowej zale¿noœci czasu wykonania od liczby danych przechodzi tylko raz po wszystkich indeksach
// tab tablica do sortowania
// N rozmiar;
void BinarnySort(int *tab,  int N)  
{
	int i,j;
	int vmax; 
    i=N-2; //przedostatni indeks
	j=N-1; //ostatni indeks
	//badanie tablicy od ostatnich indeksow w górê
	while(i>=0) {
		if(tab[i]==tab[j]) i--; // zmien i, j zostaw, rob tak dlugo az bedzie zmiana. Na pocz¹tku w ogole nie wiadomo, która liczba jest wiêksza kontynuuj dopoki nie ma zmian
		else {
			if(tab[i]>tab[j]) { //jezeli to tab[i] jest wiêksza przestaw w tablicy na poz j
				vmax=tab[i];     //tab[i] jest wieksz¹ liczb¹ 
				tab[i]=tab[j]; 
				tab[j]=vmax;
			}
			else vmax=tab[j];   //tzn  tab[j] by³o wieksza 
			j--;
     		while((j>=0) && (tab[j]==vmax)) { //teraz kontynuuj po j sprawdzaj¹c w gorê jak d³ugo w kolejnych malale¹cych indeksach utrzymuje siê max
			    j--;  //dopoki indeks nie przekroczy zakresu lub wartoœæ tab[j] siê nie zmieni, wartosc "j" w wielu wypadkacjh mo¿e przekroczyæ "i" szczególnie jak pod rz¹d w górê s¹ maksy 
			}
			i=j; //jak nie zosta³y przekroczone indeksy to w tab[j] jest minimalnna liczba, korekta indeksu "i"
			i--; // kontynuuj (while(i>=0) i musi byæ mniejsze od j
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

//teraz liczmy czas  dla du¿ej liczby elementow

	printf("\nZadanie nr 3\n");
	N=7;
	PrzepiszTablice( TabBin, TabSort, N); //0-6 i=3,k=4,5,6, 0-7 i=3 k=4,5,6,7
	printf("Dane wejsciowe:    ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	BinarnySort(TabSort,  N);
	printf("fun. BinarnySort:  ");
	WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	
	N=20;
	//sprawdzenie dla innej dwuwartoœciowej tablicy
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


