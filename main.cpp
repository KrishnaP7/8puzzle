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


int main()
{
    Puzzle p(2);
    
    Node* n = new Node(&p);
    n->get_p()->print();
    cout << endl;
    cout << "root's cost should be 0: ";
    n->get_g();
    cout << endl;
    
    //n->get_p()->print();
    
    //cout << n->get_g() << endl;
    
    Node* m = uniform_cost(n);
    if(m != 0)
    {
        vector<Node*> trace;
        traceback(m, trace);
        
            cout << trace.size() << endl;
            cout << "the solution is" << endl;
            cout << endl;
        for(int i = trace.size() - 1; i > -1; i--)
        {
            trace.at(i)->get_p()->print();
            cout << endl;
        }
    }
    else
    {
        cout << "didnt work homie" << endl;
    }
    
}
