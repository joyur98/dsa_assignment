#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

//stack initiated for operators
char stackOP[SIZE];
int topOP = -1;

//stack initiated for integers
int stackINT[SIZE];
int topINT = -1;

//push operators
void pushOP(char x){
    stackOP[++topOP] = x;
}

//pop operators
char popOP(){
    return stackOP[topOP--];
}

//push integers
void pushINT(int x){
    stackINT[++topINT] = x;
}

//pop integers
int popINT(){
    return stackINT[topINT--];
}

//function to check precedence
int precendece(char op){  //higher the number, higher the priority
    if ( op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if(op=='^') return 3;
    return 0;
}

//function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]){
    int i, j = 0; // i is to go thru infix and j is to make postfix
    char ch; //holds character

    for (i = 0; infix[i] != '\0';i++){
        ch = infix[i];

        if(isalnum(ch)){
            postfix[j++] = ch; //if it is operand then it adds it in postfix asap
        }

        else if ( ch == '('){
            pushOP(ch);
        }

        else if (ch == ')'){
            while (topOP != -1 && stackOP[topOP] != '('){ //goes thru stack until ( is  found
                postfix[j++] = popOP(); // adds every operator before it to the postfix
            }
            popOP(); //removes the (
        }

        else{
            while(topOP != -1 && precendece(stackOP[topOP]) >= precendece(ch)){ //positioning of operators in postfix
                postfix[j++] = popOP;
            }
            pushOP(ch);
        }
    }

    while (topOP != -1){ //leftover operators added to postfix if any
        postfix[j++] = popOP();
    }
}

//function to evaluate the postfix
int evaluatePostfix(char postfix[]){
    int i;
    char ch;

    for (i = 0; postfix[i] != '\0';i++){
        ch = postfix[i];

        if(isdigit(ch)) {
            pushINT(ch - '0');
        }

        else {
            int b = popINT();
            int a = popINT();

            switch(ch){
                case '+' :
                    pushINT(a + b);
                    break;
                case '-':
                    pushINT(a - b);
                    break;
                case '*':
                    pushINT(a * b);
                    break;
                case '/':
                    pushINT(a / b);
                    break;
                case '^':
                    pushINT(pow(a,b));
                    break;
            }
        }
    }

    return popINT();
}

int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix Expression: %s\n", postfix);
    printf("\nEvaluation Result: %d\n", evaluatePostfix(postfix));

    return 0;
}