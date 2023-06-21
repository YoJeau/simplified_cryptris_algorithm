#include <iostream>
#include <string>
#include <sstream>

#include "sk_gen.h"
#include "pk_gen.h"
#include "encrypt.h"
#include "decrypt.h"

using namespace std;

int main(void)
{
	bool flag = false;
	char c;
	string d;
	string message_file;
	string encrypted_file;
	int cryptSize;
	
	cout << "Taille du chiffrement ?" << endl;
	cin >> d;
//	if(d.find_first_not_of("0123456789") == string::npos)
//	{ 
//		cryptSize = int(d);
//	}
//	else
//	{
//		cout << "Saisie non valide, 2 par defaut.\n" << endl;
//	}
	istringstream iss(d);
	if (!(iss >> cryptSize) || !iss.eof())
	{
		cout << "Saisie non valide, 2 par defaut.\n" << endl;
        cryptSize = 2;
	}

	do
	{
		cout << "Quelle action realiser ?\n1 : generer des cles de chiffrement\n2 : chiffrer un message\n3 : dechiffrer un message\n4 : quitter" << endl;
		cin >> c;
		cout << endl;
		switch(c)
		{
			case '1':
				sk_gen(cryptSize);
				pk_gen(cryptSize);
				break;
			case '2':
				cout << "Dans quel fichier se trouve le message ? (exemple : message.txt)" << endl;
				cin >> message_file; 
				if(message_file != "")
				{ 
					encrypt(cryptSize, message_file);
					break;
				}
				else
				{
					cout << "Le nom du fichier n'est pas valide.\n" << endl;
					break;
				}
			case '3':
				cout << "Dans quel fichier se trouve le message a dechiffrer ? (exemple : encrypted_message.txt)" << endl;
				cin >> encrypted_file; 
				if(encrypted_file != "")
				{ 
					decrypt(cryptSize, encrypted_file);
					break;
				}
				else
				{
					cout << "Le nom du fichier n'est pas valide.\n" << endl;
					break;
				}
			case '4':
				flag = true;
				break;
			default:
				cout << "La saisie n'est pas bonne.\n" << endl;
				break;
		}
	}
	while(!flag);

	return 0;
}
