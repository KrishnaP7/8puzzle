#ifndef NODE_H
#define NODE_H

#include "puzzle.h"

class Node
{
    private:
        Puzzle *puzzle_ref;
        vector<Node*> children;
        Node *parent;
    
    public:
    
        Node(Puzzle* p)
        {
            puzzle_ref = p;
        }
    
        Puzzle* get()
        {
            return puzzle_ref;
        }
};
#endif
