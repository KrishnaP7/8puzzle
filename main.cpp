#include "puzzle.h"
#include "node.h"
#include <queue>

using namespace std;
vector<Puzzle*> visited;
int max_queue = 0;

bool unique(Node* n)
{
    for(int i = 0; i < visited.size(); i++)
    {
        if(*(n->get_p()) == *(visited.at(i)))
        {
            return false;
        }
    }
    return true;
}

void add_kids(Node* n, vector<Node*> &v)
{
    Node* temp;
    bool check = true;
    
    temp = n->up();
    if(temp == n->get_parent())
    {
        check = false;
    }
    
    if((((temp != 0) && check)) && (unique(temp)))
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
    
    if((((temp != 0) && check)) && (unique(temp)))
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
    if((((temp != 0) && check)) && (unique(temp)))
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
    if((((temp != 0) && check)) && (unique(temp)))
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

Node* retrieve_smallest_cost(vector<Node*> &v)
{
    Node* smallest = v.at(0);
    int pop_ind = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v.at(i)->get_g() < smallest->get_g())
        {
            smallest = v.at(i);
            pop_ind = i;
        }
    }
    v.erase(v.begin() + pop_ind);
    
    return smallest;
}

Node* search(Node* root, int choice)
{
    if(root->get_p()->goal_check())
    {
        return root;
    }
    visited.push_back(root->get_p());
    vector<Node*> kyu;
    add_kids(root, kyu);
    max_queue = kyu.size();
    //cout << "root has " << kyu.size() << " children" << endl;
    cout << "Expanding state" << endl;
    root->get_p()->print();
    cout << endl;
    bool goal = false;
    Node* goal_node = 0;
    
    while(kyu.size() > 0 && !goal)
    {
	if(max_queue < kyu.size())
	{
		max_queue = kyu.size();
	}
        Node* curr = 0;
        if(choice == 1)
        {
            curr = retrieve_smallest_cost(kyu);
        }
        else if(choice == 2)
        {
            curr = retrieve_smallest_tile(kyu);
        }
        else if(choice == 3)
        {
            curr = retrieve_smallest_dist(kyu);
        }
        visited.push_back(curr->get_p());
        
        if(curr->get_p()->goal_check())
        {
            goal_node = curr;
        }
        
        cout << endl;
        cout << "The best state to expand with a g(n) = " << curr->get_g() << endl;
	if(choice == 2)
	{
		cout << " and h(n) = " << curr->get_p()->misplaced_tiles() << endl;
	}
	else if(choice == 3)
	{
		cout << " and h(n) = " << curr->get_p()->manhattan_distance() << endl;
	}
        curr->get_p()->print();
        cout << endl;
        
        add_kids(curr, kyu);
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
    
    v.push_back(n);
    traceback(n->get_parent(), v);
}

int main()
{
    Puzzle p(2);
    
    Node* n = new Node(&p);
    n->get_p()->print();
    cout << endl;
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* Misplaced Tile" << endl;
    cout << "3. A* Manhattan Distance" << endl;
    
    int search_choice = 1;
    cin >> search_choice;
    
    Node* m = 0;
    m = search(n, search_choice);
    
    if(m != 0)
    {
	cout << "Goal!!" << endl;
	cout << "To solve this problem the search algorithm expanded a total of " << visited.size() << " nodes." << endl;
	cout << "The maximum number of nodes in the queue at any one time was " << max_queue << "." << endl;
	cout << "The depth of the goal node was " << m->get_g() << "." << endl;
        vector<Node*> trace;
        traceback(m, trace);
        
        cout << endl;
        
        /*if(search_choice == 1)
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
        }*/
	
    }
    else
    {
        cout << "sorry homie, didn't work" << endl;
    }
}
