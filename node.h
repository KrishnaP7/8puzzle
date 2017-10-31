#ifndef NODE_H
#define NODE_H

#include "puzzle.h"

class Node
{
private:
    Puzzle *puzzle_ref;
    vector<Node*> children;
    Node *parent;
    int g;
    
public:
    
    Node()
    {
        puzzle_ref = new Puzzle(0);
    }
    
    Node(Puzzle *p)
    {
        parent = 0;
        puzzle_ref = p;
        g = 0;
    }
    
    Node(Node* n)
    {
        parent = n;
        puzzle_ref = new Puzzle(0);
        *(puzzle_ref) = *(n->get_p());
        g = n->g + 1;
    }
    
    Puzzle* get_p()
    {
        return puzzle_ref;
    }
    
    int get_g()
    {
        return g;
    }
    
    void set_g(int n)
    {
        this->g = n;
    }
    
    Node* up()
    {
        if(!puzzle_ref->is_up())
        {
            return 0;
        }
        
        Node* n = new Node(this);
        n->puzzle_ref->up();
        
        return n;
    }
    
    Node* down()
    {
        if(!puzzle_ref->is_down())
        {
            return 0;
        }
        
        Node* n = new Node(this);
        n->puzzle_ref->down();
        
        return n;
    }
    
    Node* left()
    {
        if(!puzzle_ref->is_left())
        {
            return 0;
        }
        
        Node* n = new Node(this);
        n->puzzle_ref->left();
        
        return n;
    }
    
    Node* right()
    {
        if(!puzzle_ref->is_right())
        {
            return 0;
        }
        
        Node* n = new Node(this);
        n->puzzle_ref->right();
        
        return n;
    }
    
    Node* get_parent()
    {
        return parent;
    }
    
    void child(Node* n)
    {
        children.push_back(n);
    }
    
    int manhattan_distance()
    {
        return puzzle_ref->manhattan_distance() + g;
    }
    
    int misplaced_tiles()
    {
        return puzzle_ref->misplaced_tiles() + g;
    }
};
#endif
