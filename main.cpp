#include "puzzle.h"
#include "node.h"
#include <queue>

using namespace std;
//vector<Node*> visited;

void add_kids(Node* n, queue<Node*> &v)
{
    Node* temp;
    bool check = true;
    
    temp = n->up();
    /*for(int i = 0; i < visited.size(); i++)
     {
     if(n->get_p()->get_v() == visited.at(i)->get_p()->get_v())
     {
     check = false;
     }
     }*/
    if(temp == n->get_parent())
    {
        check = false;
    }
    
    if((temp != 0) && check)
    {
        v.push(temp);
        n->child(temp);
    }
    
    check = true;
    temp = n->down();
    /*for(int i = 0; i < visited.size(); i++)
     {
     if(n->get_p()->get_v() == visited.at(i)->get_p()->get_v())
     {
     check = false;
     }
     }*/
    
    if(temp == n->get_parent())
    {
        check = false;
    }
    
    if((temp != 0) && check)
    {
        v.push(temp);
        n->child(temp);
    }
    
    check = true;
    temp = n->left();
    /*for(int i = 0; i < visited.size(); i++)
     {
     if(n->get_p()->get_v() == visited.at(i)->get_p()->get_v())
     {
     check = false;
     }
     }*/
    
    if(temp == n->get_parent())
    {
        check = false;
    }
    if((temp != 0) && check)
    {
        v.push(temp);
        n->child(temp);
    }
    
    check = true;
    temp = n->right();
    /*for(int i = 0; i < visited.size(); i++)
     {
     if(n->get_p()->get_v() == visited.at(i)->get_p()->get_v())
     {
     check = false;
     }
     }*/
    
    if(temp == n->get_parent())
    {
        check = false;
    }
    if((temp != 0) && check)
    {
        v.push(temp);
        n->child(temp);
    }
}

Node* uniform_cost(Node* root)
{
    if(root->get_p()->goal_check())
    {
        return root;
    }
    //visited.push_back(root);
    queue<Node*> kyu;
    add_kids(root, kyu);
    cout << "root has " << kyu.size() << " children" << endl;
    //cout << root->get_g() << endl;
    bool goal = false;
    Node* goal_node = 0;
    
    
    while(kyu.size() > 0 && !goal)
    {
        Node* curr = kyu.front();
        kyu.pop();
        //visited.push_back(curr);
        
        if(curr->get_p()->goal_check())
        {
            goal_node = curr;
        }
        
        cout << endl;
        
        curr->get_p()->print();
        //cout << curr->get_g() << endl;
        
        cout << endl;
        
        add_kids(curr, kyu);
        
        /*cout << "the front child's cost is "<< curr->get_g() << endl;
         cout << "the front child looks like: " << endl; */
        
        //curr->get_p()->print();
        
        //curr->get_p()->print();
        //curr->get_p()->print_blank();
        
        //curr = kyu.front();
        //kyu.pop();
        
        //cout << curr->get_g() << endl;
        
        //curr->get_p()->print();
        //curr->get_p()->print_blank();
        //break;
        goal = curr->get_p()->goal_check();
        /*int thing;
         cin >> thing;*/
        if(goal)
        {
            goal_node = curr;
        }
    }
    
    return goal_node;
}

void add_kids_a(Node* n, vector<Node*> &v)
{
    Node* temp;
    bool check = true;
    
    temp = n->up();
    
    if(temp == n->get_parent())
    {
        check = false;
    }
    
    if((temp != 0) && check)
    {
        v.push_back(temp);
        n->child(temp);
    }
    
    check = true;
    temp = n->down();
    
    if(temp == n->get_parent())
    {
        check = false;
    }
    
    if((temp != 0) && check)
    {
        v.push_back(temp);
        n->child(temp);
    }
    
    check = true;
    temp = n->left();
    
    if(temp == n->get_parent())
    {
        check = false;
    }
    if((temp != 0) && check)
    {
        v.push_back(temp);
        n->child(temp);
    }
    
    check = true;
    temp = n->right();
    
    if(temp == n->get_parent())
    {
        check = false;
    }
    if((temp != 0) && check)
    {
        v.push_back(temp);
        n->child(temp);
    }
}

Node* retrieve_smallest_tile(vector<Node*> &v)
{
    Node* smallest = v.at(0);
    int pop_ind = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v.at(i)->misplaced_tiles() < smallest->misplaced_tiles())
        {
            smallest = v.at(i);
            pop_ind = i;
        }
    }
    v.erase(v.begin() + pop_ind);
    
    return smallest;
}

Node* a_misplaced_tile(Node* root)
{
    if(root->get_p()->goal_check())
    {
        return root;
    }
    
    vector<Node*> kyu;
    add_kids_a(root, kyu);
    cout << "root has " << kyu.size() << " children" << endl;
    
    bool goal = false;
    Node* goal_node = 0;
    
    
    while(kyu.size() > 0 && !goal)
    {
        Node* curr = retrieve_smallest_tile(kyu);
        
        if(curr->get_p()->goal_check())
        {
            goal_node = curr;
        }
        
        cout << endl;
        
        curr->get_p()->print();
        
        cout << endl;
        
        add_kids_a(curr, kyu);
        
        goal = curr->get_p()->goal_check();
        
        if(goal)
        {
            goal_node = curr;
        }
    }
    
    return goal_node;
}

void traceback(Node* n, vector<Node*> &v)
{
    if(n->get_parent() == 0)
    {
        v.push_back(n);
        return;
    }
    cout << endl;
    
    v.push_back(n);
    traceback(n->get_parent(), v);
}

Node* retrieve_smallest_dist(vector<Node*> &v)
{
    Node* smallest = v.at(0);
    int pop_ind = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v.at(i)->manhattan_distance() < smallest->manhattan_distance())
        {
            smallest = v.at(i);
            pop_ind = i;
        }
    }
    v.erase(v.begin() + pop_ind);
    
    return smallest;
}

Node* a_manhattan_dist(Node* root)
{
    if(root->get_p()->goal_check())
    {
        return root;
    }
    
    vector<Node*> kyu;
    add_kids_a(root, kyu);
    cout << "root has " << kyu.size() << " children" << endl;
    
    bool goal = false;
    Node* goal_node = 0;
    
    
    while(kyu.size() > 0 && !goal)
    {
        Node* curr = retrieve_smallest_dist(kyu);
        
        if(curr->get_p()->goal_check())
        {
            goal_node = curr;
        }
        
        cout << endl;
        
        curr->get_p()->print();
        
        cout << endl;
        
        add_kids_a(curr, kyu);
        
        goal = curr->get_p()->goal_check();
        
        if(goal)
        {
            goal_node = curr;
        }
    }
    
    return goal_node;
}


int main()
{
    Puzzle p(2);
    
    Node* n = new Node(&p);
    n->get_p()->print();
    cout << endl;
    /*cout << "root's cost should be 0: ";
     n->get_g();
     cout << endl;*/
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* Misplaced Tile" << endl;
    cout << "3. A* Manhattan Distance" << endl;
    
    int search_choice = 1;
    cin >> search_choice;
    
    //n->get_p()->print();
    
    //cout << n->get_g() << endl;
    Node* m = 0;
    if(search_choice == 1)
    {
        cout << "You've chosen Uniform Cost Search" << endl;
        m = uniform_cost(n);
    }
    else if(search_choice == 2)
    {
        cout << "You've chosen A* Search with the Misplaced Tile Heuristic" << endl;
        m = a_misplaced_tile(n);
    }
    else if(search_choice == 3)
    {
        cout << "You've chosen A* Search with the Manhattan Distance Heuristic" << endl;
        m = a_manhattan_dist(n);
    }
    else
    {
        cout << "your choice is bad and the rest won't work" << endl;
    }
    
    if(m != 0)
    {
        vector<Node*> trace;
        traceback(m, trace);
        
        cout << trace.size() << endl;
        cout << "the solution is" << endl;
        cout << endl;
        
        if(search_choice == 1)
        {
            for(int i = trace.size() - 1; i > -1; i--)
            {
                trace.at(i)->get_p()->print();
                cout << "current node cost: "<<trace.at(i)->get_g() << endl;
                cout << endl;
            }
        }
        else if(search_choice == 2)
        {
            for(int i = trace.size() - 1; i > -1; i--)
            {
                trace.at(i)->get_p()->print();
                cout << "current # of misplaced_tiles: "<< trace.at(i)->get_p()->misplaced_tiles()<< endl;
                cout << endl;
            }
        }
        else if(search_choice == 3)
        {
            for(int i = trace.size() - 1; i > -1; i--)
            {
                trace.at(i)->get_p()->print();
                cout << "current manhattan_distance: "<< trace.at(i)->get_p()->manhattan_distance()<< endl;
                cout << endl;
            }
        }
    }
    else
    {
        cout << "sorry homie, didn't work" << endl;
    }
    
}
