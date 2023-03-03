# Conway's Game of Life

## Thought Process:
Initially I intended to work with a simple matrix representation represented by a 2D vector, and then dynamically push/pulling rows and columns based on which direction the life form propogation was "moving" towards as they approached the boundies of the 6x6 universe. In this, the 4 vectors for each outer boundary of the matrix would be saved to reduce retreival time. 

## Problems With This Approach
  1. Mock universe limitations. In events where the life form was expanding towards both the left&right and top&bottom instead of individually (left,right,top,bottom) or diagonally (left-top, left-bottom, right-top, right-bottom), the universe would be constantly expanding and would not be able to keep up.
  2. The unpredictability and unrealiability of <vector> datatypes. As an example, my program has tested to meet each condition, however choosing the <vector> datatype introduced difficulties and loss associated with constant memory allocation, deallocation, and reassignment. Thus, even a simple push to dynamically add new nodes into a vector introduced incorrect results even when conditions were correctly triggered. As an example: through test with a row "0 0 1 1 0 0" for the basic "block" type lifeform, the algorithm correctly assesses "0 0 1 1 0 0" for the new generation, but the vector through push_back method ends with "1 1 1 1 1 1". Being used to Python arraylists functionality, this behavior I found to be rather perculiar.
  
## Final Thoughts
Though 
