#include <vector>
#include <iostream>

#include "constants.h"
#include "operations.h"

using namespace std;

// Renvoie le chemin complet du fichier
string concatenatePaths(string directory, string file)
{
	string concatenatedPath = directory;
	concatenatedPath += file;
    return concatenatedPath;
}

// Renvoie un nombre aléatoire entre deux bornes passées en paramètre
int randomNumber(int min, int max)
{
//	cout << "randomNumber(" << min << ", " << max << ")" << endl;
	return min + (rand() % (max - min + 1));
}

// Renvoie un vecteur d'entiers égale au vecteur d'entiers passé en paramètre avec n rotation vers la droite de ses valeurs (12345678 -> 81234567)
// n aléatoire de 0 à "cryptSize * 4"
vector<int> rotation(int cryptSize, vector<int> alea)
{
//	cout << "rotation(vector<int>)" << endl;
	vector<int> r;
	r.resize(cryptSize * 4);
	int n = randomNumber(0, (cryptSize * 4) - 1);
	if(n != 0)
	{
		for(int i = 0 ; i < (cryptSize * 4) ; i ++)
		{
			r[(i + n) % (cryptSize * 4)] = alea[i];
		}
		return r;
	}
	else
	{
		return alea;
	}
}

// Renvoie un vecteur d'entiers contenant une clé secrète passée en paramètre
// Les valeurs de la clé secrète sont décalées de façon à aligner la plus grande valeur absolue de code et de alea passés en paramètre
vector<int> rotation(int cryptSize, vector<int> code, vector<int> alea)
{
//	cout << "rotation(vector<int>, vector<int>)" << endl;
	vector<int> r;
	r.resize(cryptSize * 4);
	int n;
	int distance1 = 0;
	int distance2 = 0;
	for(int i = 1 ; i < (cryptSize * 4) ; i ++)
	{
		if(abs(code[i]) > abs(code[distance1]))
		{
			distance1 = i;
		}
		if(abs(alea[i]) > abs(alea[distance2]))
		{
			distance2 = i;
		}
	}
	if(distance1 != distance2)
	{
		n = (distance1 + (cryptSize * 4) - distance2) % (cryptSize * 4);
		for(int i = 0 ; i < (cryptSize * 4) ; i ++)
		{
			r[(i + n) % (cryptSize * 4)] = alea[i];
		}
		return r;
	}
	else
	{
		return alea;
	}
}

// Tire un nombre aléatoire entre 0 et 1 puis renvoie le vecteur d'entiers passé en paramètre
// Si 1, inverse le signe des entiers du vecteur en paramètre
// Si 0, ne fait rien de plus
vector<int> changeSign(int cryptSize, vector<int> message)
{
//	cout << "changeSign(vector<int>)" << endl;
	if(randomNumber(0, 1) == 1)
	{
		for(int i = 0 ; i <(cryptSize * 4) ; i ++)
		{
			message[i] *= -1;
		}
//		cout << "signs changed" << endl;
	}
//	else
//	{
//		cout << "signs not changed" << endl;
//	}
	return message;
}

// Renvoie un vecteur d'entiers contenant l'alea passé en paramètre
// Si la plus grande valeur absolue des deux vecteurs passés en paramètre sont de même signe
// Alors, inverse les signes des valeurs du vecteur alea passé en paramètre
vector<int> changeSign(int cryptSize, vector<int> code, vector<int> alea)
{
//	cout << "changeSign(vector<int>, vector<int>)" << endl;
	int distance = 0;
	for(int i = 1 ; i < (cryptSize * 4) ; i ++)
	{
		if(abs(alea[i]) > abs(alea[distance]))
		{
			distance = i;
		}
	}
	if(code[distance] < 0 == alea[distance] < 0)
	{
		for(int j = 0 ; j < (cryptSize * 4) ; j++)
		{
			alea[j] *= -1;
		}
//		cout << "signs changed" << endl;
	}
//	else
//	{
//		cout << "signs not changed" << endl;
//	}
	return alea;
}

// Renvoie l'addition des valeurs des vecteurs d'entiers passés en paramètre
vector<int> addition(int cryptSize, vector<int> a, vector<int> b)
{
//	cout << "addition(vector<int>, vector<int>)" << endl;
	for(int i = 0 ; i < (cryptSize * 4) ; i ++)
	{
		a[i] += b[i];
	}
	return a;
}