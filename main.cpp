//Realised by Machehin Grigory Alexandrovich

#include <iostream>
#include <conio.h>
#include "MatrixCalc.h"
#include "FractionsCalc.h"
#include "FunctionsCalc.h"
#include "PolynomialCalc.h"
#include "ProbStatCalc.h"
#include "CombFormulCalc.h"

using namespace std;

void MainMenu(int switcher)
{
    int key;
    system("cls");

    switch (switcher)
    {
    case 1:
        cout << "\r\n\n\n\n\n\n                  \t\t\t\t\t  << MATRIX >>\n\n             \t\t\t\t\t\tORDINARY DELENIE\n\n                            \t\t\t\t COMBINATORICA\n\n                              \t\t\t\t VEROYATN I STAT\n\n                              \t\t\t\t    POLINOM\n\n               \t\t\t\t\t\t    FUNCTIONS\n\n               \t\t\t\t\t\t      EXIT\n\n";
        break;
    case 2:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     MATRIX   \n\n             \t\t\t\t\t     << ORDINARY DELENIE >>\n\n                            \t\t\t\t COMBINATORICA\n\n                              \t\t\t\t VEROYATN I STAT\n\n                              \t\t\t\t    POLINOM\n\n               \t\t\t\t\t\t    FUNCTIONS\n\n               \t\t\t\t\t\t      EXIT\n\n";
        break;
    case 3:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     MATRIX   \n\n             \t\t\t\t\t\tORDINARY DELENIE\n\n                            \t\t\t      << COMBINATORICA >>\n\n                              \t\t\t\t VEROYATN I STAT\n\n                              \t\t\t\t    POLINOM\n\n               \t\t\t\t\t\t    FUNCTIONS\n\n               \t\t\t\t\t\t      EXIT\n\n";
        break;
    case 4:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     MATRIX   \n\n             \t\t\t\t\t\tORDINARY DELENIE\n\n                            \t\t\t\t COMBINATORICA\n\n                              \t\t\t      << VEROYATN I STAT >>\n\n                              \t\t\t\t    POLINOM\n\n               \t\t\t\t\t\t    FUNCTIONS\n\n               \t\t\t\t\t\t      EXIT\n\n";
        break;
    case 5:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     MATRIX   \n\n             \t\t\t\t\t\tORDINARY DELENIE\n\n                            \t\t\t\t COMBINATORICA\n\n                              \t\t\t\t VEROYATN I STAT\n\n                              \t\t\t\t << POLINOM >>\n\n               \t\t\t\t\t\t    FUNCTIONS\n\n               \t\t\t\t\t\t      EXIT\n\n";
        break;
    case 6:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     MATRIX   \n\n             \t\t\t\t\t\tORDINARY DELENIE\n\n                            \t\t\t\t COMBINATORICA\n\n                              \t\t\t\t VEROYATN I STAT\n\n                              \t\t\t\t    POLINOM\n\n               \t\t\t\t\t\t << FUNCTIONS >>\n\n               \t\t\t\t\t\t      EXIT\n\n";
        break;
    case 7:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     MATRIX   \n\n             \t\t\t\t\t\tORDINARY DELENIE\n\n                            \t\t\t\t COMBINATORICA\n\n                              \t\t\t\t VEROYATN I STAT\n\n                              \t\t\t\t    POLINOM\n\n               \t\t\t\t\t\t    FUNCTIONS\n\n               \t\t\t\t\t\t   << EXIT >>\n\n";
        break;
    default: MainMenu(1);
    }

    key = _getch();
    if (key == 27)
    {
        _exit(0);
    }
    if (key == 72)
        if (switcher != 1)
            MainMenu(switcher - 1);
        else
            MainMenu(7);
    if (key == 80)
    {
        if (switcher != 7)
            MainMenu(switcher + 1);
        else
            MainMenu(1);
    }
    if (key == 13 || key == 32)
    {
        if (switcher == 1)
            //
        if (switcher == 2)
            //
        if (switcher == 3)
            //
        if (switcher == 4)
            //
        if (switcher == 5)
            //
        if (switcher == 6)
            //
        if (switcher == 7)
        {
            _exit(0);
        }
    }
    else MainMenu(switcher);
}

int main()
{
    MainMenu(1);
    return 0;
}