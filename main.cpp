#include <iostream>
#include <conio.h>
#include "Game.h"
#include "list.h"
using namespace std;
int main()
{
    list<Game> score(5);
    for (int i = 1;i <= 5;i++) {
        Game game(i);
        int ch;
        while (game.getChances() > 0) {
            cout<<"\t\tS Q U I D \t G A M E"<<endl<<endl;
            cout << "\tLevel: " << i << "\t\t\tChances: " << game.getChances() << endl << endl;
            cout << "\t\t~~~~~\t\t~~~~~" << endl;
            cout << "\t\t| 1 |\t\t| 2 |" << endl;
            cout << "\t\t~~~~~\t\t~~~~~" << endl;
            cout << "\n\tChoose One Glass: ";
            cin >> ch;
            cout<<endl;
            switch (ch) {
                case 1: game.selectGlass(0);break;
                case 2: game.selectGlass(1);break;
                default: break;
            }
            cout << "\tPress any key to continue...";
            getch();
            system("cls");
        }
        score.insert(game);
        if(i!=5){
            cout << "\tLevel Completed!" << endl << endl;
        }
        cout << "\tScore: " << score.getSum() << endl << endl;
        if (game.getChances() == 0) {
            cout << "\tGame Over!" << endl;
            break;
        }
        cout << "\tPress any key to continue...";
        getch();
        system("cls");
    }
    return 0;
}
