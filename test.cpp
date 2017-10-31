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
    while(!n1.get_p()->goal_check())
    {
        cout << "-------------------"<< endl;
        string choice;
        cout << endl;
        n1.get_p()->print();
        cout << endl;
        n1.get_p()->print_blank();
        cout << "-------------------"<< endl;
        cout << "Enter command to move the blank" << endl;
        cin >> choice;
        
        bool works = true;
        
        if(choice == "up")
        {
            works = n1.get_p()->up();
        }
        else if(choice == "down")
        {
            works = n1.get_p()->down();
        }
        else if(choice == "left")
        {
            works = n1.get_p()->left();
        }
        else if(choice == "right")
        {
            works = n1.get_p()->right();
        }
        
        if(!works)
        {
            cout << "ya dun goofed" << endl;
        }
        
    }
    cout << "-------------------"<< endl;
    cout << endl;
    n1.get_p()->print();
    cout << endl;
    cout << "congrats u won" << endl;
    
    Node *n2 = new Node(&n1);
    
    n2->get_p()->print();
    cout << endl;
    
    n1.get_p()->get_v()->at(2).at(2) = -1;
    
    cout << endl;
    
    n1.get_p()->print();
    
    cout << endl;
    
    //*n2 = n1;
    
    n2->get_p()->print();
    
}
