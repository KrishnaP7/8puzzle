#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>

using namespace std;


//for a bigger puzzle, you can set psize to a larger number and just do two nested..
//..for loops to assign values to the puzzle (only did with 3 seperate loops for 8 puzzle..
//..because there is required text to be printed between rows)

class Puzzle
{
private:
    int psize; 						//change to change puzzle size
    vector< vector<int> > puzzle_board;			//holds the matrix of the actual puzzle
    pair<int, int> blank;				//location of the blank
    
    
public:
    Puzzle(int o)
    {
        psize = 3;
        if(o == 2)                                      //manual puzzle construction
        {
            set();
            return;
        }                                               //defualt puzzle construction
        else if(o == 3)
        {
            return;					//testing
        }
        
        int val_set = 1;
        vector<int> temp_vecs(3);
        for(int i = 0; i < psize; i++)
        {
            for(int j = 0; j < psize; j++)
            {
                if((i == psize - 1) && (j == psize - 2))
                {
                    temp_vecs.at(j) = 0;		//default puzzle board
                }
                else
                {
                    temp_vecs.at(j) = val_set;
                    val_set++;
                }
            }
            puzzle_board.push_back(temp_vecs);
        }
        blank.first = psize - 1;
        blank.second = psize - 2;
    }
    
    Puzzle & operator=(const Puzzle &p)
    {
        puzzle_board = p.puzzle_board;			//equals operator overload
        blank = p.blank;
        return *this;
    }
    
    void print_blank()					//prints blank's location (testing)
    {
        cout << "blank: (" << 1 + blank.first << ", " << 1 + blank.second << ")" << endl;
    }
    
    void set()						//sets user puzzle, doesn't error check at all.
    {							//takes each row with three for loops (change to change puzzle size)
        cout << "Enter your puzzle, use a zero to represent the blank" << endl;
        cout << "Enter the first row, use space or tabs between numbers" << endl;
        
        int inp = -1;
        vector<int> temp_vec(psize);
        
        for(int i = 0; i < psize; i++)
        {
            cin >> inp;
            if(inp == 0)
            {
                blank.first = 0;
                blank.second = i;
            }
            temp_vec.at(i) = inp;
        }
        puzzle_board.push_back(temp_vec);
        
        cout << "Enter the second row, use space or tabs between numbers" << endl;
        inp = -1;
        
        for(int i = 0; i < psize; i++)
        {
            cin >> inp;
            if(inp == 0)
            {
                blank.first = 1;
                blank.second = i;
            }
            temp_vec.at(i) = inp;
        }
        puzzle_board.push_back(temp_vec);
        
        cout << "Enter the third row, use space or tabs between numbers" << endl;
        inp = -1;
        
        for(int i = 0; i < psize; i++)
        {
            cin >> inp;
            if(inp == 0)
            {
                blank.first = 2;
                blank.second = i;
            }
            temp_vec.at(i) = inp;
        }
        puzzle_board.push_back(temp_vec);
        cout << "Your puzzle looks like this: " << endl;
        
    }
    
    void print()					//prints the puzzle
    {
        if(puzzle_board.empty())
        {
            cout << "its empty you animal" << endl;
            return;
        }
        for(int i = 0; i < psize; i++)
        {
            for(int j = 0; j < psize; j++)
            {
		int c = puzzle_board.at(i).at(j);
		if(c == 0)
		{
		   cout << "b";
		}
		else
		{
                   cout << c;
		}
		cout << " ";
            }
            cout << endl;
        }
    }
    
    bool is_up()						//checks if up is a possible direction) ^1
    {
        if(blank.first == 0)
        {
            return false;
        }
        return true;
    }
    
    void up()						//moves blank up on puzzle board ^2
    {
        int temp = puzzle_board.at(blank.first - 1).at(blank.second);
        puzzle_board.at(blank.first - 1).at(blank.second) = puzzle_board.at(blank.first).at(blank.second);
        puzzle_board.at(blank.first).at(blank.second) = temp;
        blank.first = blank.first - 1;
    }
    
    bool is_down()					//^1
    {
        if(blank.first == psize - 1)
        {
            return false;
        }
        return true;
    }
    
    void down()						//^2
    {
        int temp = puzzle_board.at(blank.first + 1).at(blank.second);
        puzzle_board.at(blank.first + 1).at(blank.second) = puzzle_board.at(blank.first).at(blank.second);
        puzzle_board.at(blank.first).at(blank.second) = temp;
        blank.first = blank.first + 1;
    }
    
    bool is_left()					//^1
    {
        if(blank.second == 0)
        {
            return false;
        }
        return true;
    }
    
    void left()						//^2
    {
        int temp = puzzle_board.at(blank.first).at(blank.second - 1);
        puzzle_board.at(blank.first).at(blank.second - 1) = puzzle_board.at(blank.first).at(blank.second);
        puzzle_board.at(blank.first).at(blank.second) = temp;
        blank.second = blank.second - 1;
    }
    
    bool is_right()					//^1
    {
        if(blank.second == psize - 1)
        {
            return false;
        }
        return true;
    }
    
    void right()					//^2
    {
        int temp = puzzle_board.at(blank.first).at(blank.second + 1);
        puzzle_board.at(blank.first).at(blank.second + 1) = puzzle_board.at(blank.first).at(blank.second);
        puzzle_board.at(blank.first).at(blank.second) = temp;
        blank.second = blank.second + 1;
    }
    
    bool goal_check()					//checks if current puzzleboard is the goal
    {
        if(puzzle_board.at(psize - 1).at(psize - 1) != 0)
        {
            return false;
        }
        int val_set = 1;
        for(int i = 0; i < psize; i++)
        {
            for(int j = 0; j < psize; j++)
            {
                if((i == psize - 1) && (j == psize - 1))
                {
                    break;
                }
                if(puzzle_board.at(i).at(j) != val_set)
                {
                    return false;
                }
                val_set++;
            }
        }
        return true;
    }
    
    vector< vector<int> > * get_v()			//returns pointer to puzzleboard vector
    {
        return &puzzle_board;
    }
    
    bool operator==(const Puzzle &p)			//equivalence operator overload
    {
        if(puzzle_board == p.puzzle_board)
        {
            if(blank == p.blank)
            {
                return true;
            }
        }
        
        return false;
    }
    
    int misplaced_tiles()				//# of misplaced tiles
    {
        int tiles = 0;
        int val_set = 1;
        for(int i = 0; i < psize; i++)
        {
            for(int j = 0; j < psize; j++)
            {
                if((i == psize - 1) && (j == psize - 1))
                {
                    break;
                }
                if(puzzle_board.at(i).at(j) != val_set)
                {
                    tiles++;
                }
                val_set++;
            }
        }
        return tiles;
    }
    
    int manhattan_distance()				//distance of each misplaced tile from its goal state
    {
        int total_dist = 0;
        int val_set = 1;
        for(int i = 0; i < psize; i++)
        {
            for(int j = 0; j < psize; j++)
            {
                if((i == psize - 1) && (j == psize - 1))
                {
                    break;
                }
                if(puzzle_board.at(i).at(j) != val_set)
                {
                    pair<int,int> found_index = find(val_set);
                    int man_dist = abs(found_index.first - i) + abs(found_index.second - j);
                    total_dist += man_dist;
                }
                val_set++;
            }
        }
        return total_dist;
    }
    
    pair<int, int> find(int val)			//returns location of searched value on the puzzleboard
    {
        pair<int,int> index;
        index.first = -1;
        index.second = -1;
        for(int i = 0; i < psize; i++)
        {
            for(int j = 0; j < psize; j++)
            {
                if(val == puzzle_board.at(i).at(j))
                {
                    index.first = i;
                    index.second = j;
                }
            }
        }
        return index;
    }
};
#endif
