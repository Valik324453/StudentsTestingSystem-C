
#include <fstream>
#include <vector>
#include <list>
using namespace std;


//---------------------string-------------------------

ofstream& operator << (ofstream& , const string& str);

ifstream& operator >> (ifstream&,  string& str);



//---------------------vector-------------------------

ofstream& operator << (ofstream&, const vector<int> &arr);

ifstream& operator >> (ifstream&, vector<int>& arr);


//---------------------list-------------------------

ofstream& operator << (ofstream&, const list<string>& lst);

ifstream& operator >> (ifstream&, list<string>& lst);