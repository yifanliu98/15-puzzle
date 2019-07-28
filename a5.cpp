#include <iostream>
#include <climits>
#include <iterator>
#include <set>
#include <stack>
#include <algorithm> //random_shuffle
#include <vector>
#include <queue> //queue
#include <map> //map
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <utility> // pair and make_pair
#include <ctime>
using namespace std;
typedef vector<int> vecint;


struct State {
    int board[4][4];
    int x, y; // location of blank
};

// operator<< overloading for vector<int>
ostream& operator<<(ostream& os, const vecint& dt)
{
    for(int i=0;i<dt.size()-1;i++) {
        if(dt[i] < 10) os << 0;
        os << dt[i];
    }
    return os;
}


int myrandom(int);
vecint randPuzzle();
int findBlank(vecint);
int numInversion(vecint);
bool isSolvable(vecint);
void display(const State&);


// -----------------------------------------------------------------------
// create the 663 pattern database for 15 puzzle
// -----------------------------------------------------------------------

void bfs_234() {
    map<vecint,pair<int,bool>> database234;
    queue<vecint> myqueue;
    vecint goal;
    goal.push_back(01);
    goal.push_back(02);
    goal.push_back(03);
    goal.push_back(33);

    myqueue.push(goal);
    database234[goal] = make_pair(0,true);
    while(!myqueue.empty()) {
        vecint parent = myqueue.front();
        myqueue.pop();

        int position0 = parent.back();
        int row = position0 / 10, column = position0 % 10;
        // move up
        if(row != 0) {
            int new_position0 = position0 - 10;
            vecint move(parent);
            move[3] = new_position0;
            int move234 = 0;
            for(int i=0;i<3;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database234[move].first == 0) {
                if(!database234[move].second) {
                    myqueue.push(move);
                    database234[move] = make_pair(database234[parent].first + move234, true);
                }
            }
            else {
                if(database234[move] > database234[parent]) {
                    myqueue.push(move);
                    database234[move] = make_pair(database234[parent].first + move234, true);                    
                }
            }
        }

        // move left
        if(column != 0) {
            int new_position0 = position0 - 1;
            vecint move(parent);
            move[3] = new_position0;
            int move234 = 0;
            for(int i=0;i<3;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database234[move].first == 0) {
                if(!database234[move].second) {
                    myqueue.push(move);
                    database234[move] = make_pair(database234[parent].first + move234, true);
                }
            }
            else {
                if(database234[move] > database234[parent]) {
                    myqueue.push(move);
                    database234[move] = make_pair(database234[parent].first + move234, true);                    
                }
            }
        }


        // move right
        if(column != 3) {
            int new_position0 = position0 + 1;
            vecint move(parent);
            move[3] = new_position0;
            int move234 = 0;
            for(int i=0;i<3;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database234[move].first == 0) {
                if(!database234[move].second) {
                    myqueue.push(move);
                    database234[move] = make_pair(database234[parent].first + move234, true);
                }
            }
            else {
                if(database234[move] > database234[parent]) {
                    myqueue.push(move);
                    database234[move] = make_pair(database234[parent].first + move234, true);                    
                }
            }    
        }

        // move down
        if(row != 3) {
            int new_position0 = position0 + 10;
            vecint move(parent);
            move[3] = new_position0;
            int move234 = 0;
            for(int i=0;i<3;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database234[move].first == 0) {
                if(!database234[move].second) {
                    myqueue.push(move);
                    database234[move] = make_pair(database234[parent].first + move234, true);
                }
            }
            else {
                if(database234[move] > database234[parent]) {
                    myqueue.push(move);
                    database234[move] = make_pair(database234[parent].first + move234, true);                    
                }
            }
        }
    }
    
    // store the pattern database234 in a file    
    ofstream myfile;
    myfile.open ("database234.txt");
    int i = 1;
    for (auto it = database234.begin(); it != database234.end(); it++) {
        if(i == 1) {
            myfile << it->first <<" " << it->second.first << '\n'; 
            i++;
        } else if(i == 13) i = 1;
        else i++;
    }
    myfile.close();
}

void bfs_15691013() {
    map<vecint,pair<int,bool>> database15691013;
    queue<vecint> myqueue;
    vecint goal;
    goal.push_back(00);
    goal.push_back(10);
    goal.push_back(11);
    goal.push_back(20);
    goal.push_back(21);
    goal.push_back(30);
    goal.push_back(33);

    myqueue.push(goal);
    database15691013[goal] = make_pair(0,true);
    while(!myqueue.empty()) {
        vecint parent = myqueue.front();
        myqueue.pop();

        int position0 = parent.back();
        int row = position0 / 10, column = position0 % 10;
        // move up
        if(row != 0) {
            int new_position0 = position0 - 10;
            vecint move(parent);
            move[6] = new_position0;
            int move234 = 0;
            for(int i=0;i<6;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database15691013[move].first == 0) {
                if(!database15691013[move].second) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);
                }
            }
            else {
                if(database15691013[move] > database15691013[parent]) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);                    
                }
            }
        }

        // move left
        if(column != 0) {
            int new_position0 = position0 - 1;
            vecint move(parent);
            move[6] = new_position0;
            int move234 = 0;
            for(int i=0;i<6;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database15691013[move].first == 0) {
                if(!database15691013[move].second) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);
                }
            }
            else {
                if(database15691013[move] > database15691013[parent]) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);                    
                }
            }
        }


        // move right
        if(column != 3) {
            int new_position0 = position0 + 1;
            vecint move(parent);
            move[6] = new_position0;
            int move234 = 0;
            for(int i=0;i<6;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database15691013[move].first == 0) {
                if(!database15691013[move].second) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);
                }
            }
            else {
                if(database15691013[move] > database15691013[parent]) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);                    
                }
            }
        }


        // move down
        if(row != 3) {
            int new_position0 = position0 + 10;
            vecint move(parent);
            move[6] = new_position0;
            int move234 = 0;
            for(int i=0;i<6;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database15691013[move].first == 0) {
                if(!database15691013[move].second) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);
                }
            }
            else {
                if(database15691013[move] > database15691013[parent]) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);                    
                }
            }
        }
    }

    // store the pattern database15691013 in a file    
    ofstream myfile;
    myfile.open ("database15691013.txt");
    for (auto it = database15691013.begin(); it != database15691013.end(); ++it) myfile << it->first <<" " << it->second.first << '\n'; 
    myfile.close();
}

void bfs_7811121415() {
    map<vecint,pair<int,bool>> database7811121415;
    queue<vecint> myqueue;
    vecint goal;
    goal.push_back(12);
    goal.push_back(13);
    goal.push_back(22);
    goal.push_back(23);
    goal.push_back(31);
    goal.push_back(32);
    goal.push_back(33);

    myqueue.push(goal);
    database7811121415[goal] = make_pair(0,true);
    while(!myqueue.empty()) {
        vecint parent = myqueue.front();
        myqueue.pop();

        int position0 = parent.back();
        int row = position0 / 10, column = position0 % 10;
        // move up
        if(row != 0) {
            int new_position0 = position0 - 10;
            vecint move(parent);
            move[6] = new_position0;
            int move234 = 0;
            for(int i=0;i<6;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database7811121415[move].first == 0) {
                if(!database7811121415[move].second) {
                    myqueue.push(move);
                    database7811121415[move] = make_pair(database7811121415[parent].first + move234, true);
                }
            }
            else {
                if(database7811121415[move] > database7811121415[parent]) {
                    myqueue.push(move);
                    database7811121415[move] = make_pair(database7811121415[parent].first + move234, true);                    
                }
            }
        }

        // move left
        if(column != 0) {
            int new_position0 = position0 - 1;
            vecint move(parent);
            move[6] = new_position0;
            int move234 = 0;
            for(int i=0;i<6;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database7811121415[move].first == 0) {
                if(!database7811121415[move].second) {
                    myqueue.push(move);
                    database7811121415[move] = make_pair(database7811121415[parent].first + move234, true);
                }
            }
            else {
                if(database7811121415[move] > database7811121415[parent]) {
                    myqueue.push(move);
                    database7811121415[move] = make_pair(database7811121415[parent].first + move234, true);                    
                }
            }
        }


        // move right
        if(column != 3) {
            int new_position0 = position0 + 1;
            vecint move(parent);
            move[6] = new_position0;
            int move234 = 0;
            for(int i=0;i<6;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database7811121415[move].first == 0) {
                if(!database7811121415[move].second) {
                    myqueue.push(move);
                    database7811121415[move] = make_pair(database7811121415[parent].first + move234, true);
                }
            }
            else {
                if(database7811121415[move] > database7811121415[parent]) {
                    myqueue.push(move);
                    database7811121415[move] = make_pair(database7811121415[parent].first + move234, true);                    
                }
            }      
        }


        // move down
        if(row != 3) {
            int new_position0 = position0 + 10;
            vecint move(parent);
            move[6] = new_position0;
            int move234 = 0;
            for(int i=0;i<6;i++) {
                if(parent[i] == new_position0) {
                    move234 = 1;
                    move[i] = position0;
                    break;
                }
            }
            if(database7811121415[move].first == 0) {
                if(!database7811121415[move].second) {
                    myqueue.push(move);
                    database7811121415[move] = make_pair(database7811121415[parent].first + move234, true);
                }
            }
            else {
                if(database7811121415[move] > database7811121415[parent]) {
                    myqueue.push(move);
                    database7811121415[move] = make_pair(database7811121415[parent].first + move234, true);                    
                }
            }
        }
    }

    // store the pattern database7811121415 in a file    
    ofstream myfile;
    myfile.open ("database7811121415.txt");
    for (auto it = database7811121415.begin(); it != database7811121415.end(); ++it) myfile << it->first <<" " << it->second.first << '\n'; 
    myfile.close();
}

void create_pattern_database_663() {
    // create pattern database for number 2, 3, 4 and store it in a file
    bfs_234();
    
    // create pattern database for number 1, 5, 6, 9, 10, 13 and store it in a file
    bfs_15691013();

    // create pattern database for number 7, 8, 11, 12, 14, 15 and store it in a file
    bfs_7811121415();
}

// -----------------------------------------------------------------------
// load the 663 pattern database
// -----------------------------------------------------------------------

map<int,int> database_234; // 2, 3, 4
map<int,int> database_156; // 1, 5, 6, 9, 10, 13
map<int,int> database_78; // 7, 8, 11, 12, 14, 15

void create_pattern_database_663() {
    ifstream myfile ("database234.txt");
    if (myfile.is_open())
    {
        string line;
        while(getline(myfile,line)) {
            istringstream ss(line);
            int position, distance;
            string pos, dis;        
            getline(ss, pos, ' ');
            getline(ss, dis, ' ');
            position = atoi(pos.c_str());
            distance = atoi(dis.c_str());
            database_234[position] = distance;
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    ifstream myfile ("database15691013.txt");
    if (myfile.is_open())
    {
        string line;
        while(getline(myfile,line)) {
            istringstream ss(line);
            int position, distance;
            string pos, dis;        
            getline(ss, pos, ' ');
            getline(ss, dis, ' ');
            position = atoi(pos.c_str());
            distance = atoi(dis.c_str());
            database_156[position] = distance;
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    ifstream myfile ("database7811121415.txt");
    if (myfile.is_open())
    {
        string line;
        while(getline(myfile,line)) {
            istringstream ss(line);
            int position, distance;
            string pos, dis;        
            getline(ss, pos, ' ');
            getline(ss, dis, ' ');
            position = atoi(pos.c_str());
            distance = atoi(dis.c_str());
            database_78[position] = distance;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

// -----------------------------------------------------------------------

State goal, nongoal;
set<State> nongoals;
map<pair<int, int>, char> moves;

bool operator==(const State& lhs, const State& rhs) {
    if (!(lhs.x == rhs.x && lhs.y == rhs.y)) return false;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) if (lhs.board[i][j] != rhs.board[i][j]) return false;
    return true;
}

bool operator<(const State& lhs, const State& rhs) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (lhs.board[i][j] < rhs.board[i][j]) return true;
            else if (lhs.board[i][j] > rhs.board[i][j]) return false;
        }
    }
    if (lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y)) return true;
    return false;
}

int find_number(const State& state,int value) {
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(state.board[i][j] == value) return 10*i+j;
}

int find_num234(const State& state) {
    return 100*(100*find_number(state,2) + find_number(state,3)) + find_number(state,4);
}

int find_num15(const State& state) {
    return 100*(100*(100*(100*(100*find_number(state,1) + find_number(state,5)) + find_number(state,6)) + find_number(state,9)) + find_number(state,10)) + find_number(state,13);
}

int find_num78(const State& state) {
    return 100*(100*(100*(100*(100*find_number(state,7) + find_number(state,8)) + find_number(state,11)) + find_number(state,12)) + find_number(state,14)) + find_number(state,15);

}


// int h(State &s) {
//     int ret = 0;
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             if (s.x == i && s.y == j) continue;
//             int v = s.board[i][j];
//             int x = (v - 1)/4, y = (v - 1)%4;
//             ret += abs(x-i) + abs(y-j);
//         }    
//     }
//     return ret;
// }

int h(State& s) {
    return find_num234(s) + find_num15(s) + find_num78(s);
}


bool solvable;
vector<char> prefix;
int exceed, costbound;
set<State> visited;
State node;

bool dfs(int depth) {
    int currcost = depth + h(node);
    if (currcost > costbound) {
        exceed = min(exceed, currcost);
        return false;
    }
    if (node == goal || nongoals.count(node) > 0) {
        solvable = (node == goal);
        return true;
    }

    visited.insert(node);

    for (map<pair<int, int>, char>::iterator it = moves.begin(); it != moves.end(); it++) {
        int dx = it->first.first, dy = it->first.second;
        if (0 <= node.x + dx && node.x + dx < 4 && 0 <= node.y + dy && node.y + dy < 4) {
            swap(node.board[node.x][node.y], node.board[node.x + dx][node.y + dy]);
            node.x += dx; node.y += dy;
            if (visited.count(node) == 0) {
                prefix.push_back(it->second);
                if (dfs(depth + 1)) return true;
                else prefix.pop_back();
            }
            node.x -= dx; node.y -= dy;
            swap(node.board[node.x][node.y],
            node.board[node.x + dx][node.y + dy]);
        }
    }
    visited.erase(node);
    return false;
}

void solve_idastar(State &start) {
    costbound = h(start);
    bool success;
    do {
        exceed = INT_MAX;
        prefix.clear();
        visited.clear();
        node = start;
        success = dfs(0);
        costbound = exceed;
        // cerr << "deepening to " << costbound << endl;
    } while (!success);
    if (solvable) {
        copy(prefix.begin(), prefix.end(), ostream_iterator<char>(cout, ""));
        cout << endl;
    }
    else cout << "This puzzle is not solvable." << endl;
}

// State rand_puzzle() {
//     srand(unsigned(time(0)));
//     State puzzle;
//     for(int i=0;i<4;i++) for(int j=0;j<4;j++) puzzle.board[i][j] = 4*i+j;
//     puzzle.x = 0;
//     puzzle.y = 0;
//     for(int i=0;i<4;i++) {
//         for(int j=0;j<4;j++) {
//             int row = rand()%4;
//             int column = rand()%4;
//             int temp = puzzle.board[i][j];
//             puzzle.board[i][j] = puzzle.board[row][column];
//             puzzle.board[row][column] = temp;
//             if (row == puzzle.x) puzzle.x = row;
//             if (column == puzzle.y) puzzle.y = column;
//         }
//     }
//     if(!is_solvable(puzzle)) return rand_puzzle();
//     else return puzzle;
// }

// bool is_solvable(const State& state) { // 15 puzzle
//     int line = 4 - state.x; // line number from bottom
//      if n is even, puzzle instance is solvable if 
//      * 1. the blank is on an even row counting from the bottom and number of inversions is odd.
//      * 2. the blank is on an odd row counting from the bottom and number of inversions is even.
      
//     if (line%2==0 && num_inversion(state)%2==1) return true;
//     else if (line%2==1 && num_inversion(state)%2==0) return true;
//     return false;
// }

// int num_inversion(const State& state) {
//     int num = 0, row = 0, column = 0;
//     while(row+column < 7) {
//         int value = state.board[row][column];
//         int i = row, j = column+1;
//         if (column == 3) {
//             i++;
//             j = 0;
//         }
//         while(i<4) {
//             while(j<4) {
//                 if(state.board[i][j] < value) num++;
//             }
//             i++;
//             j = 0;
//         }
//     }
//     return num;
// }

int myrandom(int i) { return rand()%i; }

vecint randPuzzle() {
    srand(unsigned(time(0)));
    vecint state;
    for (int i=0; i<16; i++) state.push_back(i);
    random_shuffle(state.begin(),state.end(),myrandom);
    return state;
    while (true) {
        random_shuffle(state.begin(),state.end(),myrandom);
        if (isSolvable(state)) return state;
    }
}

bool isSolvable(vecint state) { // 15 puzzle
    int blank = findBlank(state);
    int line = 4 - blank/4; // line number from bottom
    /* if n is even, puzzle instance is solvable if 
     * 1. the blank is on an even row counting from the bottom and number of inversions is odd.
     * 2. the blank is on an odd row counting from the bottom and number of inversions is even.
     */ 
    if (line%2==0 && numInversion(state)%2==1) return true;
    else if (line%2==1 && numInversion(state)%2==0) return true;
    return false;
}

int numInversion(vecint state) {
    int size = state.size();
    int num = 0;
    for (int i=0; i<size-1; i++) {
        if (state[i] == 0) continue;
        for (int j=i+1; j<size; j++) {
            if (state[j] == 0) continue;
            if (state[i] > state[j]) num++;
        }
    }
    return num;
}

int findBlank(vecint state) {
    for(int i=0;i<state.size();i++) if(state[i] == 0) return i;
}

State rand_state() {
    vecint puzzle = randPuzzle();
    State state;
    for(int i=0;i<puzzle.size();i++) {
        int row = i/4, column = i%4;
        if(puzzle[i] == 0) {
            state.x = row;
            state.y = column;
        }
        state.board[row][column] = puzzle[i];
    }
    return state;
} 


// display the puzzle
void display(const State& s) {
    cout << "The state of " << 15 << "-puzzle: " << endl;
    cout << "--------------------------------------------" << endl;
    for (int i=0; i<4; i++) {
        for (int j=0;j<4;j++) {
            if (s.board[i][j] == 0) cout << " * ";
            else {
                if (s.board[i][j] < 10) cout << " ";
                cout << s.board[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "--------------------------------------------" << endl;

}

int main() {
    moves[make_pair(0, -1)] = 'L'; moves[make_pair(0, +1)] = 'R';
    moves[make_pair(-1, 0)] = 'U'; moves[make_pair(+1, 0)] = 'D';
    State start = rand_state();

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            goal.board[i][j] = nongoal.board[i][j] = 4*i + j + 1;
        }
    }

    display(start);
    
    goal.board[3][3] = nongoal.board[3][3] = 0;
    goal.x = nongoal.x = 3; goal.y = nongoal.y = 3;

    swap(nongoal.board[3][2], nongoal.board[3][1]);
    nongoals.insert(nongoal);
    swap(nongoal.board[3][2], nongoal.board[3][1]);

    swap(nongoal.board[0][0], nongoal.board[0][1]);
    nongoals.insert(nongoal);
    swap(nongoal.board[0][0], nongoal.board[0][1]);
    
	const clock_t begin_time = clock();
    solve_idastar(start);
	cout << "Running time(seconds): " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;


    return 0;
}