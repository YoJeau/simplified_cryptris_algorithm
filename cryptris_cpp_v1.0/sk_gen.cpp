#include <vector>
#include <fstream>
#include <iostream>

#include "constants.h"
#include "sk_gen.h"
#include "operations.h"

using namespace std;

// Crée une clé secrète et l'écrit dans le fichier sk.txt
int sk_gen(int cryptSize)
{
	cout << "secretKey()" << endl;

	srand(time(NULL));	// Initialise le générateur de nombres aléatoires avec l'horloge du système

	vector<int> secretKey;

	secretKey.push_back(randomNumber(10, 30));
	for(int i = 1 ; i < (cryptSize * 4) ; i++)
	{
		secretKey.push_back(randomNumber(-1, 1));
	}
	secretKey = rotation(cryptSize, secretKey);
	secretKey = changeSign(cryptSize, secretKey);

	ofstream sk (sk_path);
	if(sk.is_open())
	{
		for(int j = 0 ;  j < (cryptSize * 4) ; j++)
		{
			sk << secretKey[j];
			if(j < (cryptSize * 4) - 1)
			{
				sk << ".";
			}
		}

        cout << "secret key success !\n| Le fichier sk.txt a ete genere avec succes.\n" << endl;
	}
	else
	{
		cout << "Unable to open sk.txt !\nLe fichier sk.txt n'a pas pu etre cree.\nVerifiez la presence du dossier \"files\".\n" << endl;
	}
	sk << endl;
	sk.close();
	
	return 0;
}