#include <vector>
#include <fstream>
#include <iostream>

#include "constants.h"
#include "pk_gen.h"
#include "operations.h"

using namespace std;

// Crée une clé publique à partir de la clé secrète et l'écrit dans le fichier pk.txt
int pk_gen(int cryptSize)
{
	cout << "publicKey()" << endl;

	srand(time(NULL));	// Initialise le générateur de nombres aléatoires avec l'horloge du système

	int n = randomNumber(10, 20);
//	cout << "number of secret key additions : " << n << endl;

	bool negativ = false;
	bool add = false;
	bool sk_flag = false;
	vector<int> alea;
	vector<int> publicKey;
	vector<int> secretKey;

	ifstream sk(sk_path);
	if(sk.is_open())
	{
		int a = 0;
		char b;
		while(sk >> b)
		{
			if(add)
			{
				if(b == '.')
				{
					add = false;
					a++;
				}
				else
				{
					if(secretKey[a] < 0)
					{
						secretKey[a] = (secretKey[a] * 10) - (b - '0');
					}
					else
					{
						secretKey[a] = (secretKey[a] * 10) + (b - '0');
					}
				}
			}
			else if(negativ)
			{
				negativ = false;
				add = true;
				secretKey.push_back((b - '0') * -1);
			}
			else
			{
				if(b == '-')
				{
					negativ = true;
				}
				else
				{
					add = true;
					secretKey.push_back(b - '0');
				}
			}
		}
		sk_flag = true;
	}
	else
	{
		cout << "Unable to open sk.txt !\nLe fichier sk.txt n'a pas pu etre charge.\nVerifiez la presence du dossier \"files\".\n" << endl;
	}
	sk.close();

	if(sk_flag)
	{
		publicKey = secretKey;

		for(int i = 0 ; i < n ; i++)
		{
//			cout << "\taddition : " << i + 1 << endl;
			alea = secretKey;
			alea = rotation(cryptSize, alea);
			alea = changeSign(cryptSize, alea);
			publicKey = addition(cryptSize, publicKey, alea);
		}

		ofstream pk(pk_path);
		if(pk.is_open()) {
		  for(int j = 0 ;  j < (cryptSize * 4) ; j++)
			{
				pk << publicKey[j];
                if(j < (cryptSize * 4) - 1)
				{
					pk << ".";
				}
			}

			cout << "public key success !\n| Le fichier pk.txt a ete genere avec succes.\n" << endl;
		}
		else
		{
			cout << "Unable to open pk.txt !\nLe fichier pk.txt n'a pas pu etre cree.\nVerifiez la presence du dossier \"files\".\n" << endl;
		}
		pk << endl;
		pk.close();
    }

	return 0;
}