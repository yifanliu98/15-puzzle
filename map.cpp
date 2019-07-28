#include <utility> // std::pair, std::make_pair
#include <iostream>
#include <map>
#include <ctime>
#include <queue> // queue
#include <vector>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi

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

// display the puzzle
void display(const State& state) {
    cout << "The state of " << 15 << "-puzzle: " << endl;
    cout << "--------------------------------------------" << endl;
    for (int i=0; i<4; i++) {
        for (int j=0;j<4;j++) {
            if (state.board[i][j] == 0) cout << " * ";
            else {
                if (state.board[i][j] < 10) cout << " ";
                cout << state.board[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << "--------------------------------------------" << endl;
}

// int find_number(const State& state,int value) {
//     for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(state.board[i][j] == value) return 10*i+j;
// }

// int find_num2340(const State& state) {
//     return 100*(100*(100*find_number(state,2) + find_number(state,3)) + find_number(state,4))+find_number(state,0);
// }

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
    int length = 1;
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
                    length++;
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
                    length++;
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
                    length++;
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
                    length++;

                }
            }
            else {
                if(database15691013[move] > database15691013[parent]) {
                    myqueue.push(move);
                    database15691013[move] = make_pair(database15691013[parent].first + move234, true);                    
                }
            }
        }
        cout << length << endl;
    }

    // store the pattern database15691013 in a file    
    ofstream myfile;
    myfile.open ("database15691013.txt");
    int I = 1;
    for (auto it = database15691013.begin(); it != database15691013.end(); ++it) {
        if(i == 1) {
            myfile << it->first <<" " << it->second.first << '\n'; 
            i++;
        } else if(i == 10) i = 1;
        else i++;
    }
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

    // store the pattern database15691013 in a file    
    ofstream myfile;
    myfile.open ("database15691013.txt");
    int I = 1;
    for (auto it = database15691013.begin(); it != database15691013.end(); ++it) {
        if(i == 1) {
            myfile << it->first <<" " << it->second.first << '\n'; 
            i++;
        } else if(i == 10) i = 1;
        else i++;
    }
    myfile.close();
}

map<int,int> database_234;
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
}


int main() {
    // create pattern database for number 2, 3, 4 and store it in a file
    // bfs_234();
    
    // create pattern database for number 1, 5, 6, 9, 10, 13 and store it in a file
    bfs_15691013();

    // create pattern database for number 7, 8, 11, 12, 14, 15 and store it in a file
    //bfs_7811121415();


    //create_pattern_database_663();
    //for (auto it = database_234.begin(); it != database_234.end(); ++it) cout << it->first <<" " << it->second << '\n'; 



    return 0;
}


