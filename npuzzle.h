using namespace std;
fndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>

using namespace std;

const int psize = 3;

class Puzzle
{
    private:
    
        vector<int> puzzle_board(psize * psize);
    
    public:
    
        void set()
        {
            cout << "Enter your puzzle, use a zero to represent the blank" << endl;
            cout << "Enter the first row, use space or tabs between numbers" << endl;
            
            for(int i = 0; i < psize; i++)
            {
                cin >> puzzle_board.at(i);
            }
            
            cout << "Enter the second row, use space or tabs between numbers" << endl;
            
            for(int i = 3; i < psize; i++)
            {
                cin >> puzzle_board.at(i);
            }
            
            cout << "Enter the third row, use space or tabs between numbers" << endl;
            
            for(int i = 6; i < psize; i++)
            {
                cin >> puzzle_board.at(i);
            }
            
            for(int i = 0; i < (psize * psize); i++)
            {
                
            }
            
        }
        
        void print()
        {
            
        }
        
        void up()
        {
            
        }
        
        void down()
        {
            
        }
};

#endif
