# Conway's Game of Life

##Thought Process:

Initially I intended to work with a simple matrix representation represented by a 2D vector, and then dynamically push/pulling rows and columns based on which direction the life form propogation was "moving" towards as they approached the boundies of the 6x6 universe. In this, the 4 vectors for each outer boundary of the matrix would be saved to reduce retreival time. 

However, the problems with this approach I noticed were twofold:
1. Mock universe limitations. In events where the life form was expanding towards both the left&right and top&bottom instead of individually (left,right,top,bottom) or diagonally (left-top, left-bottom, right-top, right-bottom), the universe would be constantly expanding and would not be able to keep up.
2. The unpredictability and unrealiability of <vector> datatypes. As an example, my program has tested to meet each condition, however choosing the <vector> datatype introduced difficulties and loss associated with constant memory allocation, deallocation, and reassignment. Thus, 
