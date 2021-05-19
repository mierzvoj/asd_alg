#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//definicje tablic 
#define ROZMIAR 10000          
int TabWe[ROZMIAR+1];			//dane wejsciowe do sortowania sa przepisywane do tablicy TabSort tu¿ przed sortowaniem
int TabSort[ROZMIAR+1];			//tablica do przesortowania wiêksza o 1 dla algorytmu heapsort
int TabBin[7] = {0,1,1,0,1,0,1}; //tablica z zadania

//-----------------------------------------------------------------------------------------------------
//funkcje pomocnicze
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
unsigned zakres_losowy=rozmiar<100 ? 100: 16000; //zakres zmian liczby losowej

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
//=============================== BubbleSort  =========================================

void BubbleSort(int *tab,  int ik)
{
int i,j,vtabmp;

	for(j = 0; j < ik; j++) {
		for(i = 0; i < ik; i++) {
			if(tab[i] > tab[i + 1]) {
				vtabmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = vtabmp;
			}
		}
	}
}

//=============================== QuickSort  =========================================
//tab - tablica z danymi 
//ip  - indeks pierwszego elementu
//ik  - indeks ostatniego elementu

void QuickSort(int *tab, int ip, int ik)
{
	int i,j,v,vtabmp;   //v-wartosc srodkowa do porownania         
	i=ip;
	j=ik;
	v=tab[(ip+ik)/2];  
	do
	{
		while (tab[i]<v) {
			i++;
		}
		while (v<tab[j]) {
			j--;
		}
		if (i<=j)
		{
			vtabmp=tab[i];
			tab[i]=tab[j];
			tab[j]=vtabmp;
			i++;
			j--;
		}
	}
	while (i<=j);
	if (ip<j) QuickSort(tab,ip,j);
	if (i<ik) QuickSort(tab,i,ik);
}

//=============================== HeapSort  =========================================
//indeksy tablicy danych do posortowania musz¹ zaczynac siê od 1, 
//tab - tablica z danymi do posortowania sortowania, dane rozpoczynaja  sie od indeksu 1 
//ik  - indeks ostatniego elementu

void HeapSort(int *tab, int  ik) 
{
	int j, i, k, x, m;
	int vtmp;					//zmiena pomocnicza do przestawiania elementow
	//tworzenie kopca
	for(i = 2; i <= ik; i++)
	{
		j = i; k = j / 2;
		x = tab[i];
		while((k > 0) && (tab[k] < x))
		{
			tab[j] = tab[k];
			j = k; k = j / 2;
		}
		tab[j] = x;
	}
	// rozbieranie kopca
	for(i = ik; i > 1; i--)
	{
		vtmp=tab[1];
		tab[1]=tab[i];
		tab[i]=vtmp;
		j = 1; k = 2;
		while(k < i)
		{
			if((k + 1 < i) && (tab[k + 1] > tab[k]))
				m = k + 1;
			else
				m = k;
			if(tab[m] <= tab[j]) break;
			
			vtmp=tab[j];
			tab[j]=tab[m];
			tab[m]=vtmp;

			j = m; k = j + j;
		}
	}
}

int main()
{
int i,k;
int   N;      //liczba danych wejsciowych
clock_t start, finish;
float  czasQS[3]; // czasy w milisekundach wykonania operacji QuickSort dla tab. losowej, posortowanej i odwrotnie posotrowanej
float  czasHS[3]; // to samo dla heapsort
float  czasBS[3]; // to samo dla bubblesort
int liczbaPowtorzen; //liczba powtorzen

    N=10;
	for(k=0; k<3; k++) {
		switch(k) {
			case 0: 
				printf("\nDane wejsciowe - zmienne losowe\n");
				PodstawLosoweDane(TabWe, N);

				break;
			case 1:
				printf("\nDane wejsciowe - posegregowana tablica \n");
				PodstawPosegregowaneDane(TabWe, N);
				break;
			case 2:
				printf("\nDane wejsciowe - odwrotnie posegregowana tablica\n");
				PodstawOdwrotniePosegregowaneDane(TabWe, N);
				break;
		}

		printf("Dane wejsciowe:  ");
		WyswietlTablice (TabWe, N); 
		

		//metoda Quicksort
		PrzepiszTablice( TabWe, TabSort, N); //w tab sort znajda sie dane z tablicy wejsciowej
		QuickSort(TabSort, 0, N-1);			 //N-1? bo do sortowania podajemy ostatni indeks tablicy
		printf("fun. Quicksort:  ");
		WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy

		//metoda HeapSort
		PrzepiszTablice( TabWe, TabSort+1, N); //w tab sort znajda sie dane z tablicy wejsciowej ale dane s¹ wstawiane od indeksu nr 1(TabSort+1),tego wymaga ten algorytm
		HeapSort(TabSort,N);				   //N ? bo to  ostatni indeks tablicy gdzie dane by³y ustawiane od indeksu nr 1
		printf("fun. HeapSort:   ");
		WyswietlTablice (TabSort+1, N);			//pokaze na ekranie zawartosc tablicy posortowanej

		//metoda BubbleSort
		PrzepiszTablice( TabWe, TabSort, N); //w tab sort znajda sie dane z tablicy wejsciowej
		BubbleSort(TabSort, N-1);		     //N-1? bo do sortowania podajemy ostatni indeks tablicy
		printf("fun. BubbleSort: ");
		WyswietlTablice (TabSort, N); //pokaze na ekranie zawartosc tablicy
	}

//teraz liczê czas dla du¿ej liczby elementow

    //ROZMIAR TABLICY=10000
	
	printf("\nLiczenie czasow\n");
    N=ROZMIAR;
	for(k=0; k<3; k++) {
		switch(k) {
			case 0: 
				printf("\nDane wejsciowe - zmienne losowe\n");
				PodstawLosoweDane(TabWe, N);
				break;
			case 1:
				printf("\nDane wejsciowe - posegregowana tablica \n");
				PodstawPosegregowaneDane(TabWe, N);
				break;
			case 2:
				printf("\nDane wejsciowe - odwrotnie posegregowana tablica\n");
				PodstawOdwrotniePosegregowaneDane(TabWe, N);
				break;
		}
		//QS
		liczbaPowtorzen=100;
		start = clock();
		for( i=0; i<liczbaPowtorzen; i++) {
			PrzepiszTablice( TabWe, TabSort, N); 
			QuickSort(TabSort, 0, N-1);			 
		}
		finish=clock();
		czasQS[k] =((float)(finish-start)/(float)CLOCKS_PER_SEC )*(float)1000.0 /(float)liczbaPowtorzen; //œredni czas wykonania jednego sortowania 
		printf("QuickSort  czas %.3fms \n", czasQS[k]);
		
		//HS
		liczbaPowtorzen=100;
		start = clock();
		for( i=0; i<liczbaPowtorzen; i++) {
			PrzepiszTablice( TabWe, TabSort+1, N); 
			HeapSort(TabSort,N);
		}
		finish=clock();
		czasHS[k] =((float)(finish-start)/(float)CLOCKS_PER_SEC )*(float)1000.0 /(float)liczbaPowtorzen; //œredni czas wykonania jednego sortowania 
		printf("HeapSort   czas %.3fms \n", czasHS[k]);

		//BS
		liczbaPowtorzen=10; 
		start = clock();
		for( i=0; i<liczbaPowtorzen; i++) {
			PrzepiszTablice( TabWe, TabSort, N); 
			BubbleSort(TabSort, N-1);		    
		}
		finish=clock();
		czasBS[k] =((float)(finish-start)/(float)CLOCKS_PER_SEC )*(float)1000.0 /(float)liczbaPowtorzen; //œredni czas wykonania jednego sortowania 
		printf("BubbleSort czas %.3fms \n", czasBS[k]);
	}
 
	printf("\nZestawienie czasow wykonywania operacji sortowania\n");
	printf("Rozmiar tablicy = %d liczb do posortowania\n\n",ROZMIAR);
 	printf("-------------------------------------------------------\n");
    printf("czas [ms]        | QuickSort |  HeapSort | BubbleSort |\n");
	printf("-------------------------------------------------------\n");
    printf("losowy           | %9.3f | %9.3f | %9.3f  |\n", czasQS[0],czasHS[0],czasBS[0]);
	printf("-------------------------------------------------------\n");
    printf("uporzadkowany    | %9.3f | %9.3f | %9.3f  |\n", czasQS[1],czasHS[1],czasBS[1]);
	printf("-------------------------------------------------------\n");
    printf("odwrotny         | %9.3f | %9.3f | %9.3f  |\n", czasQS[2],czasHS[2],czasBS[2]);
	printf("-------------------------------------------------------\n");


	
}


