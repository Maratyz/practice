/*
(/) Exercise 4-3. Given the basic framework, it’s straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.

Exercise 4-4. 
Add commands to print the top element of the stack without popping, 
to duplicate it, and 
to swap the top two elements. 
Add a command to clear the stack.

Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.

Exercise 4-6. Add commands for handling variables. 
(It’s easy to provide twenty-six variables with single-letter names.) 
Add a variable for the most recently printed value.

Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input. 
Should ungets know about buf and bufp, or should it just use ungetch?

Exercise 4-8. Suppose that there will never be more than one character of pushback. 
Modify getch and ungetch accordingly.

Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. 
Decide what their properties ought to be if an EOF is pushed back, then implement your design.

Exercise 4-10. An alternate organization uses getline to read an entire input line[…]”
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int gettop(char []);
void push(double);
double pop(void);
double top(void);
void dupTop(void);
void printTop(void);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = gettop(s)) != EOF ) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case 't':
                printf("top: %f\n",top());
                break;
            case 'd':
                dupTop();
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor \n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero moduler \n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s \n", s);
                break;
        }
    }


    return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL) {
        // printf("push %g\n", f);
        val[sp++] = f;
    }
    else {
        printf("error: stack full, can't push %g, current position %d\n", f, sp);
    }
}

double pop() {
    if (sp > 0 ) {
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double top() {
    if (sp > 0 ) {
        return val[sp-1];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void dupTop() {
    double t;
    if (sp + 1 < MAXVAL ) {
        printf("current val pos: %d, value: %g\n", sp, val[sp]);
        t = val[sp-1] ;
        val[sp] = t;
        printf("current val pos: %d, value: %g\n", sp, val[sp]);
    }
    else {
        printf("error: stack full, can't duplicate %g, current position %d\n", val[sp], sp);
    }
}
#include <ctype.h>

int getch(void);
void ungetch(int);

int gettop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c=='.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    // printf("current top s: %s\n", s);
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE];
char bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar() ;
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void printTop(void) {
    int i, t, c ;
    t = bufp ;
    printf("current buf position: %d\n", t);
    char s[MAXVAL];
    while ((s[0] = c = buf[t--]) == ' ' || c == '\t' || c == '!')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        s[0] = c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c=='.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    printf("current top %s\n", s);
}