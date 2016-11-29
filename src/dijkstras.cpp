// dijsktras.cpp

#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;
// Main Execution

struct Node {
    int cost;
    pair<int, int> target;
    pair<int, int> source;
    bool operator<(Node a)const {
        return a.cost < this->cost;
    }
}; 


int main(int argc, char *argv[]) {
    int i, j, num_tiles, tile_num;
    int mrow, mcol;
    int rstart_row, rstart_col;
    int rend_row, rend_col;
    string tile_name;
    map<string, int> tiles;
    cin >> num_tiles;
    for(i = 0; i < num_tiles; i++) {
        cin >> tile_name >> tile_num;
        tiles[tile_name] = tile_num;
    }
    cin >> mrow >> mcol;
    string tile_grid[mrow][mcol];
    for(i = 0; i < mrow; i++) {
        for(j = 0; j < mcol; j++) {
            cin >> tile_grid[i][j];    
        }
    }
    cin >> rstart_row >> rstart_col;
    cin >> rend_row >> rend_col;
    
    int costs = 0;
    Node v;
    priority_queue<Node> frontier;
    map<pair<int, int>, pair<int, int>> marked;
    frontier.push({0, {rend_row, rend_col}, {rend_row, rend_col}});
    while(frontier.size() != 0) {
        v = frontier.top();
        frontier.pop();
        if(marked.count(v.target))
            continue;
        marked[v.target] = v.source;
        costs = v.cost;
        /*cout << "Currently at " << v.target.first << ", " <<
            v.target.second << " with cost of " << endl;
        cout << "The cost is " << costs << endl;
        */
        if(v.target.first == rstart_row && v.target.second == rstart_col)
           break; 
        // u.name = new target
        // v.name = where i came from
        if((v.target.first+1) < mrow) {
            frontier.push({v.cost +
                    tiles[tile_grid[v.target.first+1][v.target.second]],
                    {v.target.first+1, v.target.second}, 
                    {v.target.first, v.target.second}}); 
            // vtarget is the vertex that it is at
            // vsource is the vertex that allowed us to get to vtarget 
        }
        if((v.target.first-1) >= 0) {
            frontier.push({v.cost +
                    tiles[tile_grid[v.target.first-1][v.target.second]],
                    {v.target.first-1, v.target.second},
                    {v.target.first, v.target.second}});
        }
        if((v.target.second+1) < mcol) {
            frontier.push({v.cost +
                    tiles[tile_grid[v.target.first][v.target.second+1]],
                    {v.target.first, v.target.second+1},
                    {v.target.first, v.target.second}});
        }
        if((v.target.second-1) >= 0) {
            frontier.push({v.cost +
                    tiles[tile_grid[v.target.first][v.target.second-1]],
                    {v.target.first, v.target.second-1},
                    {v.target.first, v.target.second}});
        }
    }    
    cout << costs << endl;
    pair<int, int> curr = v.target;
    while(curr.first != rend_row || curr.second != rend_col) {
        cout << curr.first << " " << curr.second << endl;
        curr = marked[curr];
    }
    cout << curr.first << " " << curr.second << endl;
    //return 0;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
