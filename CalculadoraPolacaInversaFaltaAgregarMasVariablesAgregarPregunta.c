#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
int RealizoPregunta=0;
/* reverse Polish calculator */
main()
{
    int type, letra_encontrada=0, asignacion=0, preguntar=1, numero_encontrado=0, error_en_respuesta = 0, valor_temporal_de_asignacion=0, question=0, respuesta=0; //A cada letra le corresponde un valor
    double op2, a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, i=0, j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, r=0, sn=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0; /*Op2 y variables */
    int na=0, nb=0, nc=0, nd=0, ne=0, nf=0,ng=0, nh=0, ni=0, nj=0, nk=0, nl=0, nm=0, no=0, np=0, nq=0, nr=0, ns=0, nt=0, nu=0, nv=0, nw=0, nx=0, ny=0, nz=0; /*Contador de asignaciones */
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
        switch (tolower(type)) {
            RealizoPregunta=1;
            case 'a':
            letra_encontrada=1;
            push(a);
            break;
            case 'b':
            letra_encontrada=2;
            push(b);
            break;
            case 'c':
            letra_encontrada=3;
            push(c);
            break;
            case 'd':
            letra_encontrada=4;
            push(d);
            break;
            case 'e':
            letra_encontrada=5;
            push(e);
            break;
            case 'f':
            letra_encontrada=6;
            push(f);
            break;
            case 'g':
            letra_encontrada=7;
            push(g);
            break;
            case 'h':
            letra_encontrada=8;
            push(h);
            break;
            case 'i':
            letra_encontrada=9;
            push(i);
            break;
            case 'j':
            letra_encontrada=10;
            push(j);
            break;
            case 'k':
            letra_encontrada=11;
            push(k);
            break;
            case 'l':
            letra_encontrada=12;
            push(l);
            break;
            case 'm':
            letra_encontrada=13;
            push(m);
            break;
            case 'n':
            letra_encontrada=14;
            push(n);
            break;
            case 'o':
            letra_encontrada=15;
            push(o);
            break;
            case 'p':
            letra_encontrada=16;
            push(p);
            break;
            case 'q':
            letra_encontrada=17;
            push(q);
            break;
            case 'r':
            letra_encontrada=18;
            push(r);
            break;
            case 's':
            letra_encontrada=19;
            push(sn);
            break;
            case 't':
            letra_encontrada=20;
            push(t);
            break;
            case 'u':
            letra_encontrada=21;
            push(u);
            break;
            case 'v':
            letra_encontrada=22;
            push(v);
            break;
            case 'w':
            letra_encontrada=23;
            push(w);
            break;
            case 'x':
            letra_encontrada=24;
            push(x);
            break;
            case 'y':
            letra_encontrada=25;
            push(y);
            break;
            case 'z':
            letra_encontrada=26;
            push(z);
            break;
            case '=':
            asignacion=1;
            break;
            case ':':
            preguntar=0; // No preguntar para los casos de sobreescribir
            break;
            case NUMBER:
            if (asignacion==0){ // Si no esta una asignacion
            push(atof(s));
            }
            if (asignacion==1){
            valor_temporal_de_asignacion=atof(s);
            numero_encontrado=1;
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
            respuesta=0;
            // Si se encontro una letra &&  Si se encontro el signo de igual && Si se encontro un numero para la asignacion && si hay que preguntar
            if (letra_encontrada==0 && asignacion==1 &&  numero_encontrado==1 && preguntar==1){ // Caso 1
              printf("No se hizo la asignacion\n", pop());
            }
            if (letra_encontrada==0 && asignacion==1 &&  numero_encontrado==0 && preguntar==1){ // Caso 2
              printf("No se hizo la asignacion\n", pop());
            }
            if (letra_encontrada==0 && asignacion==1 &&  numero_encontrado==1 && preguntar==0){ // Caso 3
              printf("No se hizo la asignacion\n", pop());
            }
            if (letra_encontrada!=0 && asignacion==1 &&  numero_encontrado==1 && preguntar==0){ // Caso 4
                if (letra_encontrada==1){  // Si la letra es A
                a=valor_temporal_de_asignacion;
                na++;
                // Volvemos a los valores iniciales
                letra_encontrada=0;
                asignacion=0;
                preguntar=1;
                numero_encontrado=0;
                valor_temporal_de_asignacion=0;
                question=0;
                printf("Asignacion hecha\n", pop());
                }
                /*Aqui termina la letra A*/

            }  //////////////////////////////////////////////////////////////////////////// TERMINA CASO 4

            if (letra_encontrada!=0 && asignacion==1 &&  numero_encontrado==1 && preguntar==1){ //  CASO 5
                /*Preguntar y luego asignar */
                if (letra_encontrada==1){ // Si la letra es A
                    if (na!=0){ /////////Aqui deberia ir la pregunta
                        a=valor_temporal_de_asignacion;
                        na++;
                        // Volvemos a los valores iniciales
                        letra_encontrada=0;
                        asignacion=0;
                        preguntar=1;
                        numero_encontrado=0;
                        valor_temporal_de_asignacion=0;
                        question=0;
                        printf("Aqui deberia preguntar Asignacion hecha\n", pop());

                    }
                    if (na==0){
                        a=valor_temporal_de_asignacion;
                        na++;
                        // Volvemos a los valores iniciales
                        letra_encontrada=0;
                        asignacion=0;
                        preguntar=1;
                        numero_encontrado=0;
                        valor_temporal_de_asignacion=0;
                        question=0;
                        printf("Asignacion hecha\n", pop());
                    }

                }

                /*Aqui termina la letra A*/
            }
            else{
                printf("\t%.8g\n", pop());
            }
            break;
            default:
            printf("error: unknown command %s\n", s);
            break;
        }
        }     //////////////////////////////////////////////////////////////////////////// TERMINA CASO 4





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
