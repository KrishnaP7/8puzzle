#ifndef NODE_H
#define NODE_H

#include "puzzle.h"

class Node
{
private:
    Puzzle *puzzle_ref;						//reference to puzzle object
    vector<Node*> children;					//vector of children (pretty much unused and useless)
    Node *parent;						//reference to parent node
    int g;							//g(n) value and depth (same thing when cost of each move is uniform)
    
public:
    
    Node()
    {
        puzzle_ref = new Puzzle(0);				//default constructor
    }
    
    Node(Puzzle *p)						//makes root node when given a puzzle reference
    {
        parent = 0;
        puzzle_ref = p;
        g = 0;
    }
    
    Node(Node* n)						//makes a potential child copy of current node 
    {
        parent = n;
        puzzle_ref = new Puzzle(0);
        *(puzzle_ref) = *(n->get_p());
        g = n->g + 1;
    }
    
    Puzzle* get_p()						//returns puzzle reference
    {
        return puzzle_ref;
    }
    
    int get_g()							//return g(n)
    {
        return g;
    }
    
    void set_g(int n)						//sets g
    {
        this->g = n;
    }
   
    Node* up()							//returns node reference of using up on current node ^1
    {
        if(!puzzle_ref->is_up())
        {
            return 0;
        }
        
        Node* n = new Node(this);
        n->puzzle_ref->up();
        
        return n;
    }
    
    Node* down()						//^1
    {
        if(!puzzle_ref->is_down())
        {
            return 0;
        }
        
        Node* n = new Node(this);
        n->puzzle_ref->down();
        
        return n;
    }
    
    Node* left()						//^1
    {
        if(!puzzle_ref->is_left())
        {
            return 0;
        }
        
        Node* n = new Node(this);
        n->puzzle_ref->left();
        
        return n;
    }
    
    Node* right()						//^1
    {
        if(!puzzle_ref->is_right())
        {
            return 0;
        }
        
        Node* n = new Node(this);
        n->puzzle_ref->right();
        
        return n;
    }
    
    Node* get_parent()						//returns parent pointer
    {
        return parent;
    }
    
    void child(Node* n)						//adds to child vector
    {
        children.push_back(n);
    }
    
    int manhattan_distance()					//returns manhattan distance + g(n)
    {
        return puzzle_ref->manhattan_distance() + g;
    }
    
    int misplaced_tiles()					//returns misplaced tiles + g(n)
    {
        return puzzle_ref->misplaced_tiles() + g;
    }
};
#endif
