#include "puzzle.h"
#include "node.h"
using namespace std;

int main()
{
    cout << "Welcome to Krishna Pakalapati's 8-puzzle solver." << endl;
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
    int c = 0;
    cin >> c;
    Puzzle p1(c);
    Node n1(&p1);
    while(!n1.get()->goal_check())
    {
        cout << "-------------------"<< endl;
        string choice;
        cout << endl;
        n1.get()->print();
        cout << endl;
        n1.get()->print_blank();
        cout << "-------------------"<< endl;
        cout << "Enter command to move the blank" << endl;
        cin >> choice;
        
        bool works = true;
        
        if(choice == "up")
        {
            works = n1.get()->up();
        }
        else if(choice == "down")
        {
            works = n1.get()->down();
        }
        else if(choice == "left")
        {
            works = n1.get()->left();
        }
        else if(choice == "right")
        {
            works = n1.get()->right();
        }
        
        if(!works)
        {
            cout << "ya dun goofed" << endl;
        }
        
    }
    cout << "-------------------"<< endl;
    cout << endl;
    n1.get()->print();
    cout << endl;
    cout << "congrats u won" << endl;
}
