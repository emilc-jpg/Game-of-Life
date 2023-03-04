// Game of Life - ML Compiler Interview 
// DESCRIPTION: 
//      Cellular automation algorithm that applies a set of rules to each cell in the 2D cell universe. 
//      Each cell is either in alive [1] or dead [0] states.
// HOW TO RUN: 
//      1a) Navigate to .cpp file folder, and type "g++ conway.cpp -o application.exe" into terminal
//      1b) Open "application.exe" that has been generated
//  or:
//      2a) Compile and run conway.cpp in IDE of choice
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <windows.h>
#include <iostream>
using namespace std;


/////////////////////////////////////////////////////
// HELPER FUNCTIONS: display, terminate, clearScreen
/////////////////////////////////////////////////////
void display(vector<vector<int>> curr_state)
{
    // Display results
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            cout << curr_state[i][j] << ' ';
        }
        cout << endl;
    }
}

void clearScreen(int characterLength){
    // Clears the screen for next display
    for(int i = 0; i < characterLength; i++){
        cout << "\b";
    }
}

bool terminate(vector<vector<int>> curr_state, vector<vector<int>> next_state) {
    // Terminates the loop when there is no change in the universe
    if(curr_state == next_state){ 
        return true;
    }
    else{
        return false;
    }
}


//////////////////////////////////////////////////////
// FUNCTION: automation 
// DESCRIPTION: iterate through each node in universe subsection
// and update the node in the new state.
/////////////////////////////////////////////////////
vector<vector<int>> automaton(vector<vector<int>> curr_state, vector<vector<int>> next_state)
{
    // Traverse and condition check each node
    vector<int> v2;
    int i = 0; int j = 0;
    int node = 0;


    for(i = 0; i < 6; i++) {
        v2.clear();
        for(j = 0; j < 6; j++) 
        {
            int live_count = 0;
            if(i > 0 && j > 0 && (curr_state[i-1][j-1] == 1)) { live_count++; }         // top left
            if(j > 0 && (curr_state[i][j-1] == 1)) { live_count++; }                    // top middle
            if(i < 7 && j > 0 && (curr_state[i+1][j-1] == 1)) { live_count++; }         // top right
            if(i > 0 && curr_state[i-1][j] == 1) { live_count++; }                      // middle left
            if(i < 7 && (curr_state[i+1][j] == 1)) { live_count++; }                    // middle right
            if(i > 0 && j < 7 && (curr_state[i-1][j+1] == 1)) { live_count++; }         // bottom left
            if(j < 7 && (curr_state[i][j+1] == 1)) { live_count++; }                    // bottom middle
            if(i < 7 && j < 7 && (curr_state[i+1][j+1] == 1)) { live_count++; }         // bottom right

            
            // 1) Survival - Any live cell with 2 or 3 live neighbors survives       
            if((curr_state[i][j] == 1) && live_count > 1 && live_count < 4) {
                v2.push_back(1);
                //cout << "trigger1 " << node << endl;
            }

            // 2) Birth - Any dead cell with 3 live neighbors becomes a live cell
            else if((curr_state[i][j] == 0) && (live_count >= 3)) {
                v2.push_back(1);
                //cout << "trigger2 " << node << endl;
            }

            // 3) Death - All other live cells die in the next generation; All other dead cells stay dead
            else {
                v2.push_back(0);
                //cout << "trigger " << node << endl;
            }
            //node++;
        }
        //cout << "v2 ";
        //for(int b=0; b < v2.size(); b++)
        //cout << v2.at(i) << ' ';
        //cout << endl;
        next_state.push_back(v2);
    }

    cout << "does it ever get here" << endl;
    return curr_state, next_state;
}

/////////////////////////////////////////////////////
// FUNCTION: main
/////////////////////////////////////////////////////
int main() {
    // Beginning
    cout << "Welcome to Conrad's Game of Life 2!" << endl;

    // Set initial state "block" - stable, finite, nonempty
    // 0 0 0 0 0 0
    // 0 0 0 0 0 0
    // 0 0 1 1 0 0
    // 0 0 1 1 0 0
    // 0 0 0 0 0 0
    // 0 0 0 0 0 0
    vector<vector<int>> curr_state
    {
        {0,0,0,0,0,0},
        {0,1,1,1,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };
    display(curr_state);

    vector<vector<int>> next_state;

    bool end  = false;
    // Loop through -- if the states are unchanged, terminate
    while(end == false){ 
        curr_state, next_state = automaton(curr_state, next_state);
        display(next_state);                    

        end = terminate(curr_state, next_state); 

        curr_state = next_state;	// Next state becomes new current state
        next_state.clear();		// Clear next state for new generation

        end = true;

    };


    return 0;
}

/* Animating the display
clearScreen(100)
Sleep(1000);


}
*/