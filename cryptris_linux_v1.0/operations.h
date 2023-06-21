#ifndef OPERATIONS_H
#define OPERATIONS_H

using namespace std;

string concatenatePaths(string directory, string file);
int randomNumber(int min, int max);
vector<int> rotation(int cryptSize, vector<int> alea);
vector<int> rotation(int cryptSize, vector<int> code, vector<int> alea);
vector<int> changeSign(int cryptSize, vector<int> message);
vector<int> changeSign(int cryptSize, vector<int> code, vector<int> alea);
vector<int> addition(int cryptSize, vector<int> a, vector<int> b);

#endif // OPERATIONS_H