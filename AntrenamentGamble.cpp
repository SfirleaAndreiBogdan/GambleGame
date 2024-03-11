#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string.h>

using namespace std;

void instructiuni()
{
	cout << "-----------------------------------------------------" << endl;
	cout << "| " << "                ANTRENAMENT GAMBLE                " << "|" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Salut, bine ai venit!" << endl;
	cout << "Acestea sunt cateva instructiuni pe care cred ca le stii deja:" << endl;
	cout << "------------Instructiuni------------" << endl;
	cout << "Trebuie sa ghicesti  daca urmatoarea carte este rosie sau neagra" << endl;
	cout << "Suma introdusa se va dubla daca ghicesti cartea" << endl;
	cout << "La intrebarile care vor urma incercati pe cat posibil sa nu adaugati litere la introducerea balantei si sumei." << endl;
	cout << "Cand ajungeti la intrebarea rosu sau negru nu introduceti numere ci doar literele R,N,r,n" << endl;
	cout << "Distractie sa ai :)" << endl;
}

void reset(char rb[])
{
	rb[1] = ' ';
}

int verificare(char rb[], int numar)
{
	if (numar % 2 == 0 && strcmp(rb, "R") == 0 || strcmp(rb, "r") == 0)
	{
		return 1;
	}
	else if (numar % 2 == 0 && strcmp(rb, "N") == 1 || strcmp(rb, "n") == 1)
	{
		return 0;
	}
	if (numar % 2 == 1 && strcmp(rb, "N") == 0 || strcmp(rb, "n") == 0)
	{
		return 1;
	}
	else if (numar % 2 == 1 && strcmp(rb, "R") == 1 || strcmp(rb, "r") == 1)
	{
		return 0;
	}
}

int main()
{
	instructiuni();
	cout << "--------------------------------------------------------------------------------" << endl;
	int Balanta = 0;
	int verif = 0;
	int verif1 = 0;
	char rb[100];

	while (1)
	{
		cout << "Introdu Suma pentru balanta: ";
		cin >> Balanta; cout << "Lei" << endl;
		if (Balanta <= 0)
		{
			cout << "nu se poate depune aceasta suma..." << endl;
			Balanta = NULL;
		}
		if (Balanta != 0)
		{
			break;
		}
	}

	int Suma = 0;
	while (1)
	{
		cout << "introdu suma care va fi extrasa din balanta: "; cin >> Suma; cout << " Lei" << endl;
		if (Suma <= 0)
		{
			cout << "Nu se poate paria suma asta..." << endl;
		}
		if (Suma > Balanta)
		{
			cout << "Suma introdusa este mai mare decat balanta..." << endl;
			continue;
		}
		else if (Balanta >= Suma)
		{
			break;
		}
	}
	while (1)
	{
		if (verif1 == 1)
		{
			while (1)
			{
				cout << "introdu suma care va fi extrasa din balanta: "; cin >> Suma; cout << "Lei" << endl;

				if (Suma == 0)
				{
					cout << "Nu se poate paria suma aceasta..." << endl;
				}
				if (Suma > Balanta)
				{
					cout << "Suma introdusa este mai mare decat balanta..." << endl;
					continue;
				}
				else if (Balanta >= Suma)
				{
					break;
				}
			}
		}
		while (verif == 0)
		{
			cout << "Rosu sau Negru?" << endl;
			cin >> rb;
			if (strcmp(rb, "R") == 0 || strcmp(rb, "r") == 0)
			{
				verif = 1;
				continue;
			}
			if (strcmp(rb, "N") == 0 || strcmp(rb, "n") == 0)
			{
				verif = 1;
				continue;
			}

			if (strcmp(rb, "R") != 1 || strcmp(rb, "r") != 1)
			{
				cout << "Litera invalida, incearca din nou" << endl;
			}
			else
			{
				if (strcmp(rb, "N") != 1 || strcmp(rb, "n") != 1)
				{
					cout << "Litera invalida, incearca din nou" << endl;
				}
			}
		}
		srand(time(0));
		int numar = 0;
		numar = (rand() % 12) + 2;

		if (verificare(rb, numar) == 1)
		{
			cout << "Win!" << endl;
			Balanta = Balanta + Suma;
			verif1 = 1;
		}
		else
		{
			cout << "Lose" << endl;
			Balanta = Balanta - Suma;
			verif1 = 1;
		}
		cout << "Balanta ta este acum: " << Balanta << " Lei" << endl;
		reset(rb);
		cout << endl;
		verif = 0;
		if (Balanta <= 0)
		{
			cout << "Nu mai ai bani..." << endl;
			cout << "Vrei sa joci din nou?" << endl;
			char rasp[10];
			cin >> rasp;
			if (strcmp(rasp, "Da") == 0 || strcmp(rasp, "da") == 0)
			{
				return main();
			}
			if (strcmp(rasp, "Nu") == 0 || strcmp(rasp, "nu") == 0)
			{
				return 0;
			}
		}
	}
	system("pause");
}