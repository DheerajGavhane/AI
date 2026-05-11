#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

struct Node {

    vector<vector<int>> mat;

    int x, y;

    int cost;

    int level;
};

int row[] = {1, 0, -1, 0};

int col[] = {0, -1, 0, 1};

vector<vector<int>> goal = {

    {1,2,3},
    {4,5,6},
    {7,8,0}
};

int calculateCost(vector<vector<int>> initial) {

    int count = 0;

    for(int i=0;i<3;i++) {

        for(int j=0;j<3;j++) {

            if(initial[i][j] &&
               initial[i][j] != goal[i][j])

                count++;
        }
    }

    return count;
}

bool isSafe(int x,int y) {

    return (x>=0 && x<3 && y>=0 && y<3);
}

void printMatrix(vector<vector<int>> mat) {

    for(auto i:mat) {

        for(auto j:i)

            cout<<j<<" ";

        cout<<endl;
    }

    cout<<endl;
}

struct comp {

    bool operator()(Node a, Node b) {

        return (a.cost + a.level) >
               (b.cost + b.level);
    }
};

int main() {

    vector<vector<int>> initial = {

        {1,2,3},
        {4,0,6},
        {7,5,8}
    };

    priority_queue<Node,
                   vector<Node>,
                   comp> pq;

    Node root;

    root.mat = initial;

    root.x = 1;

    root.y = 1;

    root.level = 0;

    root.cost = calculateCost(initial);

    pq.push(root);

    while(!pq.empty()) {

        Node min = pq.top();

        pq.pop();

        printMatrix(min.mat);

        if(min.cost == 0) {

            cout<<"Goal State Reached";

            return 0;
        }

        for(int i=0;i<4;i++) {

            int newX = min.x + row[i];

            int newY = min.y + col[i];

            if(isSafe(newX,newY)) {

                Node child = min;

                swap(child.mat[min.x][min.y],
                     child.mat[newX][newY]);

                child.x = newX;

                child.y = newY;

                child.level = min.level + 1;

                child.cost =
                calculateCost(child.mat);

                pq.push(child);
            }
        }
    }

    return 0;
}

/*
Informed Search uses additional information (heuristics) to find the goal efficiently.
A* (A-Star) is one of the most efficient informed search algorithms used for:
    Path finding
    Graph traversal
    Puzzle solving
    A* selects the node having minimum:
    f(n)=g(n)+h(n)
What are the types of heuristics used in 8-puzzle?
    Misplaced tile heuristic
    Manhattan distance heuristic
What is Manhattan distance?
    It is the sum of horizontal and vertical distances of tiles from their goal positions.    
What is time complexity of A*?
    Depends on heuristic; worst case is exponential.
Features of A* Algorithm
    Uses heuristic function
    Finds optimal path
    Uses Open and Closed lists
    Avoids revisiting explored nodes
Algorithm of A*
    Create OPEN list.
    Create CLOSED list.
    Insert start node into OPEN.
    Select node with minimum f(n).
    If goal reached:
    Stop.
    Else:
    Expand node.
    Generate child nodes.
    Calculate heuristic values.
    Repeat process.
Advantages of A* Algorithm
    Fast searching
    Uses heuristics
    Avoids unnecessary paths
    Efficient for path finding
    Disadvantages of A* Algorithm
    High memory usage
    Depends on heuristic quality
    Not suitable for huge state spaces
    Applications of A* Algorithm
    GPS Navigation
    Game AI
    Robot Navigation
    Puzzle Solving
    Network Routing
*/