/*WAP to convert an infix expression into its equivalent postfix notation*/
// eg ((a+b)*c)-d
// o/p ab+c*d-
#include <stdio.h>
#include <stdlib.h>
#define EXPLEN 20
#define STKLEN 30

char stackExp[STKLEN];
int topE = -1;

int isOperator(char ch){
    if(ch >= 'a' && ch <= 'z')
        return 1;
    return 0;
}

void pushE(char c){
    if(topE < STKLEN-1){
        stackExp[++topE] = c;
    }else{
        printf("OVERFLOW\n");
    }
}

char popE(){
    if(topE!=-1){
        char c = stackExp[topE];
        topE--;
        return c;
    }
    return '#';
}

char peekE(){
    if(topE!=-1){
        return stackExp[topE];
    }
    return '#';
}

int OrderOfPrecendence(char ch){
    switch(ch){
        case '^': return 1;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 3;
    }
}

int isValidExpression(char *str){
    // if the string entered by user is more than 
    // the length of arr assigned
    if(*(str+EXPLEN-1) == '\0'){
        //valid
        int noBrackets=0;
        int k=0;
        while(*(str+k)){
            if(*(str+k) == '('){
                noBrackets -= 1;
            }
            else if(*(str+k) == ')'){
                noBrackets += 1;
            }
            k++;
        }
        return (!noBrackets)? 1 : 0;
    }
    else{
        return 0;
    }
}

int main(int argc, char **argv){
    char exp[EXPLEN]={0};
    printf("Enter a valid Expression: ");
    scanf("%s",exp);
    if(!isValidExpression(exp))
    {
        fprintf(stderr, "INVALID! expression\n");
        exit(EXIT_FAILURE);
    }
    printf("Inorder expression: %s\n",exp);

    char expPostfix[EXPLEN]={0};
    ///// convert to postfix /////
    // if operand then print
    // if the operator is * + ) ( -
    int k=-1;
    int i=0;
    while(exp[i]){
        if(!isOperator(exp[i])){
            //then perform operations
            if(exp[i]=='('){
                pushE(exp[i]);
                i++;
                continue;
            }
            if(exp[i]==')'){
                //loop through till we get the '('
                while(peekE() != '#' && peekE()!='('){
                    expPostfix[++k] = popE();
                }
                popE();// removed '('
                i++;
                continue;
            }
            int op1 = OrderOfPrecendence(exp[i]);
            int op2 = OrderOfPrecendence(peekE());
            if(op1 < op2){
                // higher precedence simplly push it
                pushE(exp[i]);
            }else if(op1 > op2){
                // comming operator is of lower precedence
                // then pop the top element and then check whether it is higher of not
                while(topE!=-1 && peekE()!='(' && op1 > OrderOfPrecendence(peekE())){
                    expPostfix[++k] = popE();
                }
                if(peekE() == '('){
                    i++;
                    continue;
                }
                pushE(exp[i]);
            }else{
                //associavity
                expPostfix[++k] = popE();
                // check for pushing it
            }
        }
        else{
            // printf("\t\t\toperand: \t%c\n",exp[i]);
            //oprand is just pushed
            expPostfix[++k] = exp[i];
        }
        // printf("iteration val -> %c || %s\n",exp[i], expPostfix);
        i++;
    }
    while(peekE()!='#'){
        expPostfix[++k] = popE();
    }
    printf("postfix expression: %s\n",expPostfix);
    remove(argv[0]);
    return 0;
}