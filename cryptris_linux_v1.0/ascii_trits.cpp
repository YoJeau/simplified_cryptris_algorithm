#include <vector>
#include <fstream>
#include <iostream>

#include "constants.h"
#include "ascii_trits.h"

using namespace std;

// Renvoie dans un vecteur d'entiers la traduction des symboles ASCII du vecteur de caractères passé en paramètre en Trits (-1, 0, 1)
vector<int> asciiToTrits(vector<char> ascii)
{
//	cout << "asciiToTrits(vector<char>)" << endl;

	vector<int> trits;

	for(int i = 0 ; i < ascii.size() ; i++)
	{
		switch(ascii[i])
		{
			case ' ' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '0' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '1' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '2' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '3' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '4' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '5' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '6' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '7' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				break;
			case '8' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case '9' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case 'a' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case 'b' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case 'c' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case 'd' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case 'e' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case 'f' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case 'g' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				break;
			case 'h' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'i' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'j' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'k' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'l' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'm' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'n' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'o' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'p' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				break;
			case 'q' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 'r' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 's' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 't' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 'u' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 'v' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 'w' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 'x' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 'y' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				break;
			case 'z' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'A' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'B' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'C' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'D' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'E' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'F' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'G' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'H' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				break;
			case 'I' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'J' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'K' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'L' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'M' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'N' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'O' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'P' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'Q' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				break;
			case 'R' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case 'S' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case 'T' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case 'U' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case 'V' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case 'W' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case 'X' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case 'Y' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case 'Z' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				break;
			case '.' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case ',' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case '!' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case '?' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case ':' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case ';' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case '*' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case '+' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case '-' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				break;
			case '/' :
				trits.push_back( 0 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break;
			case '=' :
				trits.push_back( 1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break;
			case '<' :
				trits.push_back( -1 );
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break;
			case '>' :
				trits.push_back( 0 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break;
			case '@' :
				trits.push_back( 1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break;
			case '#' :
				trits.push_back( -1 );
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break;
			case '$' :
				trits.push_back( 0 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break;
			case '%' :
				trits.push_back( 1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break;
			case '&' :
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				trits.push_back( -1 );
				break ;
		}
	}

	ofstream att (asciiToTrits_path);
	if(att.is_open())
	{
		att << "ascii :" << endl;
		for(int j = 0 ;  j < ascii.size() ; j++)
		{
			att << ascii[j];
		}
		att << "\ntrits :" << endl;
		for(int k = 0 ;  k < trits.size() ; k++)
		{
			att << trits[k];
			if(k < trits.size() - 1)
			{
				if((k + 1) % 4 == 0)
				{
					att << " .";
				}
				att << " ";
			}
		}
	}
	else
	{
		cout << "Unable to open asciiToTrits.txt !\nLe fichier asciiToTrits.txt n'a pas pu etre cree.\nVerifiez la presence du dossier \"files\".\n" << endl;
	}
	att << endl;
	att.close();

	return trits;
}

// Renvoie dans un vecteur de caractères la traduction des trits (-1, 0, 1) passés en paramètres en symboles ASCII.
vector<char> tritsToAscii(vector<int> trits)
{
//	cout << "tritsToAscii(vector<int>)" << endl;

	vector<char> ascii;
	ascii.resize(trits.size()/4);
	int n = 0;

	for(int i = 0 ; i < (trits.size()/4) ; i++)
	{
		if(trits[3 + n] == 0)
		{
			if(trits[2 + n] == 0)
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = ' ';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = '0';
					}
					else
					{
						ascii[i] = '1';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '2';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = '3';
					}
					else
					{
						ascii[i] = '4';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '5';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = '6';
					}
					else
					{
						ascii[i] = '7';
					}
				}
			}
			else if(trits[2 + n] == 1)
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '8';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = '9';
					}
					else
					{
						ascii[i] = 'a';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'b';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'c';
					}
					else
					{
						ascii[i] = 'd';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'e';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'f';
					}
					else
					{
						ascii[i] = 'g';
					}
				}
			}
			else
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'h';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'i';
					}
					else
					{
						ascii[i] = 'j';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'k';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'l';
					}
					else
					{
						ascii[i] = 'm';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'n';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'o';
					}
					else
					{
						ascii[i] = 'p';
					}
				}
			}
		}
		else if(trits[3 + n] == 1)
		{
			if(trits[2 + n] == 0)
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'q';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'r';
					}
					else
					{
						ascii[i] = 's';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 't';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'u';
					}
					else
					{
						ascii[i] = 'v';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'w';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'x';
					}
					else
					{
						ascii[i] = 'y';
					}
				}
			}
			else if(trits[2 + n] == 1)
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'z';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'A';
					}
					else
					{
						ascii[i] = 'B';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'C';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'D';
					}
					else
					{
						ascii[i] = 'E';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'F';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'G';
					}
					else
					{
						ascii[i] = 'H';
					}
				}
			}
			else
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'I';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'J';
					}
					else
					{
						ascii[i] = 'K';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'L';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'M';
					}
					else
					{
						ascii[i] = 'N';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'O';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'P';
					}
					else
					{
						ascii[i] = 'Q';
					}
				}
			}
		}
		else
		{
			if(trits[2 + n] == 0)
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'R';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'S';
					}
					else
					{
						ascii[i] = 'T';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'U';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'V';
					}
					else
					{
						ascii[i] = 'W';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = 'X';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = 'Y';
					}
					else
					{
						ascii[i] = 'Z';
					}
				}
			}
			else if(trits[2 + n] == 1)
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '.';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = ',';
					}
					else
					{
						ascii[i] = '!';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '?';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = ':';
					}
					else
					{
						ascii[i] = ';';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '*';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = '+';
					}
					else
					{
						ascii[i] = '-';
					}
				}
			}
			else
			{
				if(trits[1 + n] == 0)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '/';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = '=';
					}
					else
					{
						ascii[i] = '<';
					}
				}
				else if(trits[1 + n] == 1)
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '>';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = '@';
					}
					else
					{
						ascii[i] = '#';
					}
				}
				else
				{
					if(trits[0 + n] == 0)
					{
						ascii[i] = '$';
					}
					else if(trits[0 + n] == 1)
					{
						ascii[i] = '%';
					}
					else
					{
						ascii[i] = '&';
					}
				}
			}
		}
		n += 4;
	}

	ofstream tta(tritsToAscii_path);
	if(tta.is_open())
	{
		tta << "trits : ";
		for(int j = 0 ;  j < trits.size() ; j++)
		{
			tta << trits[j];
			if(j < trits.size() - 1)
			{
				if((j + 1) % 4 == 0)
				{
					tta << " .";
				}
				tta << " ";
			}
		}
		tta << "\nascii : ";
		for(int k = 0 ;  k < ascii.size() ; k++)
		{
			tta << ascii[k];
		}
	}
	else
	{
		cout << "Unable to open tritsToAscii.txt !\nLe fichier tritsToAscii.txt n'a pas pu etre cree.\nVerifiez la presence du dossier \"files\".\n" << endl;
	}
	tta << endl;
	tta.close();

	return ascii;
}