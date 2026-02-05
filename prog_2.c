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
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0';i++){
        ch = infix[i];

        if(isalnum(ch)){
            postfix[j++] = ch;
        }

        else if ( ch == '('){
            pushOP(ch);
        }

        else if (ch == ')'){
            while (topOP != -1 && stackOP[topOP] != '('){
                postfix[j++] = popOP();
            }
            popOP();
        }

        else{
            while(topOP != -1 && precendece(stackOP[topOP]) >= precendece(ch)){
                postfix[j++] = popOP;
            }
            pushOP(ch);
        }
    }

    while (topOP != -1){
    postfix[j++]
    }
}

