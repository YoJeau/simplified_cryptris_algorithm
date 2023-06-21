#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "constants.h"
#include "decrypt.h"
#include "operations.h"
#include "ascii_trits.h"

using namespace std;

int decrypt(int cryptSize, string encrypted_file)
{
	cout << "decrypt()" << endl;

	srand(time(NULL));	// Initialise le générateur de nombres aléatoires avec l'horloge du système

	bool negativ = false;
	bool add = false;
	bool sk_flag = false;
	bool ec_flag = false;
	vector<int> secretKey;
	vector<int> code;
	vector<int> encrypted;
	vector<int> trits;
	vector<char> decrypted;
	vector<int> alea;
	vector<bool> flag;
	string file_path = concatenatePaths(dir_path, encrypted_file);

// Initialise à true un nombre de booléen du vecteur flag définie par cryptSize
	for(int i = 0 ; i < cryptSize * 4 ; i++)
	{
		flag.push_back(true);
	}

// Place la clé secrète dans un vecteur d'entiers
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
		cout << "Unable to open sk.txt !\nLe fichier sk.txt n'a pas pu etre charge.\nVerifiez la presence du fichier dans le dossier \"files\".\n" << endl;
	}
	sk.close();

	negativ = false;
	add = false;

// Place le contenu de encrypted.txt dans un vecteur d'entiers
	ifstream ec(file_path.c_str());
	if(ec.is_open())
	{
		int a = 0;
		char b;
		while(ec >> b)
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
					if(encrypted[a] < 0)
					{
						encrypted[a] = (encrypted[a] * 10) - (b - '0');
					}
					else
					{
						encrypted[a] = (encrypted[a] * 10) + (b - '0');
					}
				}
			}
			else if(negativ)
			{
				negativ = false;
				add = true;
				encrypted.push_back((b - '0') * -1);
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
					encrypted.push_back(b - '0');
				}
			}
		}
		ec_flag= true;
	}
	else
	{
		cout << "Unable to open " << encrypted_file << " !\nLe fichier " << encrypted_file << " n'a pas pu etre charge.\nVerifiez la presence du fichier dans le dossier \"files\".\n" << endl;
	}
	ec.close();

	if(sk_flag && ec_flag)
	{
	//int n = encrypted.size() / (cryptSize * 4);
		int m = (cryptSize * 4);
		int i = 0;

// Déchiffrement de l'ensemble du message chiffré sous forme de trits, lot par lot, en fonction du nombre d'éléments définie par lot dans cryptSize
		while(m <= encrypted.size())
		{
		
		// Transfert un lot de trits chiffrés dans le vecteur code
			for(i ; i < m ; i++)
			{
				code.push_back(encrypted[i]);
			}

		// Utilise les fonctions de déchiffrement tant que le vecteur code n'est pas entierement déchiffré
			while(find(flag.begin(), flag.end(), true) != flag.end())
			{
				alea = secretKey;
				alea = rotation(cryptSize, code, alea);
				alea = changeSign(cryptSize, code, alea);
				code = addition(cryptSize, code, alea);
				for(int j = 0 ; j < (cryptSize * 4) ; j++)
				{
					if(code[j] == 0 || code[j] == -1 || code[j] == 1)
					{
						flag[j] = false;
					}
					else
					{
						flag[j] = true;
				 }
				}
			}
		
			// Tranfert le code déchiffré dans le vecteur trits
			for(int k = 0 ; k < (cryptSize * 4) ; k++)
			{
				trits.push_back(code[k]);
				flag[k] = true;
			}

			// Remet à zéro le vecteur code pour qu'il reçoit un autre lot
			code.clear();
			m += (cryptSize * 4);
		}

// Appel de la fonction tritsToAscii afin de traduire les trits en symboles ASCII (définie dans operationscpp)
		decrypted = tritsToAscii(trits);

// Ecrit le message déchiffré dans le fichier decrypted.txt
		ofstream dc (dc_path);
		if(dc.is_open())
		{
			for(int l = 0 ;  l < decrypted.size() ; l++)
			{
				dc << decrypted[l];
			}

			cout << "decrypt success !\n| Le fichier decrypted_message.txt a ete genere avec succes.\n" << endl;
		}
		else
		{
			cout << "Unable to open decrypted_message.txt !\nLe fichier decrypted_message.txt n'a pas pu etre cree.\nVerifiez la presence du dossier \"files\".\n" << endl;
		}
		dc << endl;
		dc.close();
	}
	
	return 0;
}