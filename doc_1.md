a) The program uses a simple stack implemented using:

    Below is the main data structure used in this program
    char stack[100];
    int top = -1;

    stack[100]: A character array that can store up to 100 characters.
    It is used to keep track of opening parentheses (, {, [ as they appear in the expression.

    top: always points to the top of the stack.

    top = -1 means the stack is empty.

    When an element is pushed, top increases by +1.

    When an element is popped, top decreases by -1.

