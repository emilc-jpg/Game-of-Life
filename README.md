# Conway's Game of Life

## How to Run:
  1a. Download and navigate to .cpp file folder, and type "g++ conway.cpp -o application.exe" into terminal
  1b. Open "application.exe" that has been generated
  or:
  2a) Compile and run conway.cpp in IDE of choice

## Thought Process:
Initially I intended to work with a simple matrix representation represented by a 2D vector, and then dynamically push/pulling rows and columns based on which direction the life form propogation was "moving" towards as they approached the boundies of the 6x6 universe. In this, the 4 vectors for each outer boundary of the matrix would be saved to reduce retreival time. 

## Problems With This Approach
  1. Mock universe limitations. In events where the life form was expanding towards both the left&right and top&bottom instead of individually (left,right,top,bottom) or diagonally (left-top, left-bottom, right-top, right-bottom), the universe would be constantly expanding and would not be able to keep up.
  2. The unpredictability and unrealiability of <vector> datatypes. As an example, my program has tested to meet each condition, however choosing the <vector> datatype introduced difficulties and loss associated with constant memory allocation, deallocation, and reassignment. Thus, even a simple push to dynamically add new nodes into a vector introduced incorrect results even when conditions were correctly triggered. As an example: through test with a row "0 0 1 1 0 0" for the basic "block" type lifeform, the algorithm correctly assesses "0 0 1 1 0 0" for the new generation, but the vector through push_back method ends with "1 1 1 1 1 1". Being used to Python arraylists functionality, this behavior I found to be rather peculiar and threw a wrench in the algorithm completely.
  
## Final Thoughts
Overall even though I did not succeed in implementing  solution with the given 2-3 hour timeframe, the Game of Life is an interesting challenge that reflects the current limitations that we face with data volume and computation demands. Admittedly, I spent a portion of the time refamiliarizing myself with C++ after being accustomed to high-level languages like Python and R and utilizing their C++ based libraries for neural network fine-tuning and data analysis. More time in exploring the enticacies in C++ memory allocation and utilization could prove to yield additional avenues to explore in solving and improving the the Game of Life, like stitching together the boundaries to be "continuous", or even discarding the matrix view and instead working strictly with one-dimentional parallel arrays to reduce computation/memory load.
