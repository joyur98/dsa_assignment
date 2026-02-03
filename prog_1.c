// to check if an expression has balanced number of parantheses or not

#include <stdio.h>
#include <string.h>

char stack[100]; //creating a stack of 100 size
int top = -1; //for now, the stack is empty

void push(char c){
    if(top < 99){ //checks if stack has space
        stack[++top] = c;
    }
    else{
        printf("Stack Overflow"); //prints when stack has no space
    }
}

char pop(){
    if(top >= 0){ //checks if stack is empty
        return stack[top--];
    }
    else{
        printf("Stack is empty"); //prints when stack is empty
        return '\0'; //returning something for safety
    }
}

int match(char x, char y){ //returns true if the parentheses match otherwise returns false
    if(x == '(' && y == ')')
        return 1;
    
    if (x== '{' && y == '}')
        return 1;
    
    if(x == '[' && y == ']')
        return 1;

    else
        return 0;
}


int isbalanced(char mathexp[]){ //to check if the expression is balanced or not
    top = -1;                   // stack is reset

    for(int i = 0; i < strlen(mathexp); i++){
        char ch = mathexp[i];

        if(ch == '(' || ch == '{' || ch == '['){
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            char topch = pop();
            if(!match(topch, ch)){
                return 0;
            }
        }

    }
    
    if (top == -1){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){

    char exp1[] = "a + (b-c) * (d";
    char exp2[] = " m+ [a − b ∗ (c + d ∗ {m)]";
    char exp3[] = "a + (b-c)";

    printf("Expression 1: %s\n", isbalanced(exp1) ? "balanced" : "not balanced");
    printf("Expression 2: %s\n", isbalanced(exp2) ? "balanced" : "not balanced");
    printf("Expression 3: %s\n", isbalanced(exp3) ? "balanced" : "not balanced");
        

    return 0;
}