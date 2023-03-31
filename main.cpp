//Realised by Machehin Grigory Alexandrovich

#include <iostream>
#include <conio.h>
#include <locale>
//#include "MainHeader.h"
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
        cout << "\r\n\n\n\n\n\n                  \t\t\t\t\t  << ÌÀÒĞÈÖÛ >>\n\n             \t\t\t\t\t\tÎÁÛÊÍÎÂÅÍÍÛÅ ÄĞÎÁÈ\n\n                            \t\t\t\t  ÊÎÌÁÈÍÀÒÎĞÈÊÀ\n\n                             \t\t\t\tÒÅĞ.ÂÅĞ. È ÑÒÀÒÈÑÒÈÊÀ\n\n                              \t\t\t\t    ÌÍÎÃÎ×ËÅÍÛ\n\n               \t\t\t\t\t\t     ÔÓÍÊÖÈÈ\n\n               \t\t\t\t\t\t      ÂÛÕÎÄ\n\n";
        break;
    case 2:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     ÌÀÒĞÈÖÛ   \n\n             \t\t\t\t\t     << ÎÁÛÊÍÎÂÅÍÍÛÅ ÄĞÎÁÈ >>\n\n                            \t\t\t\t  ÊÎÌÁÈÍÀÒÎĞÈÊÀ\n\n                              \t\t\t\tÒÅĞ.ÂÅĞ. È ÑÒÀÒÈÑÒÈÊÀ\n\n                              \t\t\t\t    ÌÍÎÃÎ×ËÅÍÛ\n\n               \t\t\t\t\t\t     ÔÓÍÊÖÈÈ\n\n               \t\t\t\t\t\t      ÂÛÕÎÄ\n\n";
        break;
    case 3:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     ÌÀÒĞÈÖÛ   \n\n             \t\t\t\t\t\tÎÁÛÊÍÎÂÅÍÍÛÅ ÄĞÎÁÈ\n\n                            \t\t\t       << ÊÎÌÁÈÍÀÒÎĞÈÊÀ >>\n\n                             \t\t\t\tÒÅĞ.ÂÅĞ. È ÑÒÀÒÈÑÒÈÊÀ\n\n                              \t\t\t\t    ÌÍÎÃÎ×ËÅÍÛ\n\n               \t\t\t\t\t\t     ÔÓÍÊÖÈÈ\n\n               \t\t\t\t\t\t      ÂÛÕÎÄ\n\n";
        break;
    case 4:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     ÌÀÒĞÈÖÛ   \n\n             \t\t\t\t\t\tÎÁÛÊÍÎÂÅÍÍÛÅ ÄĞÎÁÈ\n\n                            \t\t\t\t  ÊÎÌÁÈÍÀÒÎĞÈÊÀ\n\n                             \t\t\t     << ÒÅĞ.ÂÅĞ. È ÑÒÀÒÈÑÒÈÊÀ >>\n\n                              \t\t\t\t    ÌÍÎÃÎ×ËÅÍÛ\n\n               \t\t\t\t\t\t     ÔÓÍÊÖÈÈ\n\n               \t\t\t\t\t\t      ÂÛÕÎÄ\n\n";
        break;
    case 5:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     ÌÀÒĞÈÖÛ   \n\n             \t\t\t\t\t\tÎÁÛÊÍÎÂÅÍÍÛÅ ÄĞÎÁÈ\n\n                            \t\t\t\t  ÊÎÌÁÈÍÀÒÎĞÈÊÀ\n\n                             \t\t\t\tÒÅĞ.ÂÅĞ. È ÑÒÀÒÈÑÒÈÊÀ\n\n                              \t\t\t\t << ÌÍÎÃÎ×ËÅÍÛ >>\n\n               \t\t\t\t\t\t     ÔÓÍÊÖÈÈ\n\n               \t\t\t\t\t\t      ÂÛÕÎÄ\n\n";
        break;
    case 6:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     ÌÀÒĞÈÖÛ   \n\n             \t\t\t\t\t\tÎÁÛÊÍÎÂÅÍÍÛÅ ÄĞÎÁÈ\n\n                            \t\t\t\t  ÊÎÌÁÈÍÀÒÎĞÈÊÀ\n\n                             \t\t\t\tÒÅĞ.ÂÅĞ. È ÑÒÀÒÈÑÒÈÊÀ\n\n                              \t\t\t\t    ÌÍÎÃÎ×ËÅÍÛ\n\n               \t\t\t\t\t\t  << ÔÓÍÊÖÈÈ >>\n\n               \t\t\t\t\t\t      ÂÛÕÎÄ\n\n";
        break;
    case 7:
        cout << "\r\n\n\n\n\n\n                     \t\t\t\t\t     ÌÀÒĞÈÖÛ   \n\n             \t\t\t\t\t\tÎÁÛÊÍÎÂÅÍÍÛÅ ÄĞÎÁÈ\n\n                            \t\t\t\t  ÊÎÌÁÈÍÀÒÎĞÈÊÀ\n\n                             \t\t\t\tÒÅĞ.ÂÅĞ. È ÑÒÀÒÈÑÒÈÊÀ\n\n                              \t\t\t\t    ÌÍÎÃÎ×ËÅÍÛ\n\n               \t\t\t\t\t\t     ÔÓÍÊÖÈÈ\n\n               \t\t\t\t\t\t   << ÂÛÕÎÄ >>\n\n";
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
        if (switcher == 1) { system("cls"); MatrMenu(); MainMenu(1);}
        if (switcher == 2) { system("cls"); FractionsMenu(); MainMenu(1); }
        if (switcher == 3) { system("cls"); CombMenu(); MainMenu(1); }
        if (switcher == 4) { system("cls"); ProbStatCalcMenu(); MainMenu(1); }
        if (switcher == 5) { system("cls"); PolynomialCalcMenu(); MainMenu(1); }
        if (switcher == 6) { system("cls"); FunctionsMenu(); MainMenu(1); }
        if (switcher == 7)
        {
            _exit(0);
        }
    }
    else MainMenu(switcher);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    MainMenu(1);
    return 0;
}