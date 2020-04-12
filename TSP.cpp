#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
bool letezik(int* akt, int x, int i);
int koltseg(int** t, int* akt, int n);
void megoldasokhozad(int**& megoldasok, int m, int* b, int n);
bool egyforma(int* a, int* b, int n);
bool sor_letezik(int** a, int m, int* b, int n);
int fakt(int n);
int main()
{
	int n;
	ifstream in("be.txt");
	if (!in.is_open()) {
		cout << "Error opening in_file\n";
		return 0;
	}
	in >> n;
	int faktor = fakt(n);
	cout << faktor << endl;
	int** t = new int* [n+1];
	for (int i = 0; i <= n; ++i)
	{
		t[i] = new int[n+1];
	}
	cout << "A beolvasott matrix:" << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			in >> t[i][j];
			cout << t[i][j] << " ";
		}
		cout << endl;
	}

	int** megoldasok=new int*[500000];
	for (int i = 0; i < 500000; ++i)
	{
		megoldasok[i] = new int[n+2];
	}
	int* akt = new int[n+2];
	akt[0] = 1;
	akt[n] = 1;
	for (int i = 1; i < n; ++i)
	{
		bool figyelo = true;
		while (figyelo==true)
		{
			srand(time(NULL));
			int x = rand() % (n-1) + 2;
			if (letezik(akt, x,i) == false)
			{
				figyelo = false;
				akt[i] = x;
			}
		}
	}
	cout << endl<<"A kiindulo allapot:";
	for (int i = 0; i <= n; ++i)
	{
		cout << akt[i] << " ";
	}
	akt[n+1] = koltseg(t,akt,n);
	cout << " Koltsege:" << akt[n+1]<<endl;
	int m = 0;
	megoldasokhozad(megoldasok, m, akt, n);
	int min = 0;
	int szam = 0;
	float Tt = 1;
	while (Tt>0.001 && m<(faktor-1))
	{
		//cout << T << " "<<szam<<endl;
		int* akt2 = new int[n+2];
		for (int i = 0; i <= n + 1; ++i)
		{
			akt2[i] = akt[i];
		}
		bool figy2 = false;
		while(figy2==false)
		{
			int poz = rand() % (n - 2) + 1;
			int s = akt2[poz];
			akt2[poz] = akt2[poz + 1];
			akt2[poz + 1] = s;
			akt2[n+1] = koltseg(t, akt2, n);
			if (sor_letezik(megoldasok, m, akt2, n) == false)
			{
				figy2 = true;
			}
		}
		if (akt2[n+1] < akt[n+1])
		{
			for (int i = 0; i <= n + 1; ++i)
			{
				akt[i] = akt2[i];
			}
			m++;
			megoldasokhozad(megoldasok, m, akt2, n);
			if (akt2[n+1] < megoldasok[min][n+1])
			{
				min = m;
			}
		}
		else
		{
			float random = ((float)rand()) / (float)RAND_MAX;
			float kulonbseg = (float)akt[n+1] - akt2[n+1];
			float hatvany = kulonbseg / Tt;
			Tt -= 0.00001;
			float exp = pow(1.1, hatvany);
			if (exp > random)
			{
				for (int i = 0; i <= n + 1; ++i)
				{
					akt[i] = akt2[i];
				}
				m++;
				megoldasokhozad(megoldasok, m, akt2, n);
			}
		}
		szam++;
	}
	cout << endl<<endl<<"A legrovidebb ut: ";
	for (int i = 0; i <= n; ++i)
	{
		cout << megoldasok[min][i]<<" ";
	}
	cout<<endl<<"Ennek a koltsege: "<<megoldasok[min][n + 1];
	
}
int fakt(int n)
{
	int faktorialis = 1;
	for (int i = 1; i < n; ++i)
	{
		faktorialis *= i;
	}
	return faktorialis;
}
void megoldasokhozad(int** &megoldasok, int m, int* b, int n)
{
	for (int i = 0; i <= n + 1; ++i)
	{
		megoldasok[m][i] = b[i];
	}
}
bool egyforma(int* a, int* b,int n)
{
	for (int i = 0; i <= n; ++i)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
bool sor_letezik(int** a, int m, int* b, int n)
{
	for (int i = 0; i <= m; ++i)
	{
		if (egyforma(a[i], b, n) == true)
		{
			return true;
		}
	}
	return false;
}
int koltseg(int**t,int* akt,int n)
{
	int kolt = 0;
	for (int i = 0; i < n; ++i)
	{
		kolt += t[akt[i]][akt[i + 1]];
	}
	return kolt;
}
bool letezik(int* akt, int x,int i)
{
	bool figyelo = false;
	for (int j = 1; j < i; ++j)
	{
		if (akt[j] == x)
		{
			figyelo = true;
		}
	}
	return figyelo;
}