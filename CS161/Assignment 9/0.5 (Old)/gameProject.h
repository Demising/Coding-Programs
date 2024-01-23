#ifndef gameProj
#define gameProj

#include <string>
using namespace std;

struct School
{
    string name1;
    string name2;
};

struct Teams
{
    string School;
    string gameTitle;
    string division;
    int programming;
    int art;
    int gamedesign;
    int projmanagement;
    int theme;
};

string storeTeam(string);


#endif