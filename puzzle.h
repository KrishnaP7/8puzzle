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
    int psize;
    vector< vector<int> > puzzle_board;
    pair<int, int> blank;
    
    
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
            return;
        }
        
        int val_set = 1;
        vector<int> temp_vecs(3);
        for(int i = 0; i < psize; i++)
        {
            for(int j = 0; j < psize; j++)
            {
                if((i == psize - 1) && (j == psize - 2))
                {
                    temp_vecs.at(j) = 0;
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
        puzzle_board = p.puzzle_board;
        blank = p.blank;
        return *this;
    }
    
    void print_blank()
    {
        cout << "blank: (" << 1 + blank.first << ", " << 1 + blank.second << ")" << endl;
    }
    
    void set()
    {
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
    
    void print()
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
                cout << puzzle_board.at(i).at(j);
            }
            cout << endl;
        }
        
        //cout << "total manhattan distance is " << manhattan_distance() << endl;
    }
    
    bool is_up()
    {
        if(blank.first == 0)
        {
            return false;
        }
        
        /*int temp = puzzle_board.at(blank.first - 1).at(blank.second);
         puzzle_board.at(blank.first - 1).at(blank.second) = puzzle_board.at(blank.first).at(blank.second);
         puzzle_board.at(blank.first).at(blank.second) = temp;
         blank.first = blank.first - 1;*/
        return true;
    }
    
    void up()
    {
        int temp = puzzle_board.at(blank.first - 1).at(blank.second);
        puzzle_board.at(blank.first - 1).at(blank.second) = puzzle_board.at(blank.first).at(blank.second);
        puzzle_board.at(blank.first).at(blank.second) = temp;
        blank.first = blank.first - 1;
    }
    
    bool is_down()
    {
        if(blank.first == psize - 1)
        {
            return false;
        }
        
        /*int temp = puzzle_board.at(blank.first + 1).at(blank.second);
         puzzle_board.at(blank.first + 1).at(blank.second) = puzzle_board.at(blank.first).at(blank.second);
         puzzle_board.at(blank.first).at(blank.second) = temp;
         blank.first = blank.first + 1;*/
        return true;
    }
    
    void down()
    {
        int temp = puzzle_board.at(blank.first + 1).at(blank.second);
        puzzle_board.at(blank.first + 1).at(blank.second) = puzzle_board.at(blank.first).at(blank.second);
        puzzle_board.at(blank.first).at(blank.second) = temp;
        blank.first = blank.first + 1;
    }
    
    bool is_left()
    {
        if(blank.second == 0)
        {
            return false;
        }
        
        /*int temp = puzzle_board.at(blank.first).at(blank.second - 1);
         puzzle_board.at(blank.first).at(blank.second - 1) = puzzle_board.at(blank.first).at(blank.second);
         puzzle_board.at(blank.first).at(blank.second) = temp;
         blank.second = blank.second - 1;*/
        return true;
    }
    
    void left()
    {
        int temp = puzzle_board.at(blank.first).at(blank.second - 1);
        puzzle_board.at(blank.first).at(blank.second - 1) = puzzle_board.at(blank.first).at(blank.second);
        puzzle_board.at(blank.first).at(blank.second) = temp;
        blank.second = blank.second - 1;
    }
    
    bool is_right()
    {
        if(blank.second == psize - 1)
        {
            return false;
        }
        
        /*int temp = puzzle_board.at(blank.first).at(blank.second + 1);
         puzzle_board.at(blank.first).at(blank.second + 1) = puzzle_board.at(blank.first).at(blank.second);
         puzzle_board.at(blank.first).at(blank.second) = temp;
         blank.second = blank.second + 1;*/
        return true;
    }
    
    void right()
    {
        int temp = puzzle_board.at(blank.first).at(blank.second + 1);
        puzzle_board.at(blank.first).at(blank.second + 1) = puzzle_board.at(blank.first).at(blank.second);
        puzzle_board.at(blank.first).at(blank.second) = temp;
        blank.second = blank.second + 1;
    }
    
    bool goal_check()
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
    
    vector< vector<int> > * get_v()
    {
        return &puzzle_board;
    }
    
    bool operator==(const Puzzle *p)
    {
        if(puzzle_board == p->puzzle_board)
        {
            if(blank == p->blank)
            {
                return true;
            }
        }
        
        return false;
    }
    
    int misplaced_tiles()
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
    
    int manhattan_distance()
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
                    //cout << "man_dist for " << val_set << " is " << man_dist << endl;
                    total_dist += man_dist;
                }
                val_set++;
            }
        }
        return total_dist;
    }
    
    pair<int, int> find(int val)
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
