#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */
main()
{
    int type, flagA=0, error=0;
    double op2, a=0, an=0;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (tolower(type)) {
            case 'a':
            error=0;
            push(a);
            flagA++;
            break;
            case '=':
            error=0;
            flagA++;
            break;
            case ':':
            flagA++;
            break;
            case NUMBER:
            if (flagA < 2){
            push(atof(s));
            flagA = 0;
            }
            if (flagA >= 2){
            an=atof(s);
            flagA+=4;
            }
            break;
            case '+':
            push(pop() + pop());
            break;
            case '*':
            push(pop() * pop());
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
                printf("error: zero divisor\n");
            break;
            case '\n':
            if (flagA<2){
            flagA=0;
            printf("\t%.8g\n", pop());
            }
            if (error==1){
            printf("\n", pop());
            flagA=0;
            }
            if (flagA==2&&error==0||flagA==3&&error==0){
            printf("No se a hecho ninguna asignacion debido a que falta un numero\n");
            printf("\n", pop()); /*Elimina todo */
            flagA=0;
            }
            if (flagA == 6&&error==0){
            a=an;
            printf("Asignacion Exitosa");
            printf("\n", pop()); /*Elimina todo */
            flagA=0;
            }
            if (flagA == 7&&error==0){
            a=an;
            printf("Asignacion Exitosa");
            printf("\n", pop()); /*Elimina todo */
            flagA=0;
            }
            break;
            default:
            printf("error: unknown command %s\n", s);
            error=1;
            break;
        }
    }
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';

    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }

    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;

    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
