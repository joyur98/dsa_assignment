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
        return '\0'; //returning something for safetl
    }
}

int main(){

    return 0;
}