#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

#define MAX 100
#define LEN 80
char text[MAX][LEN];

int func_localstatic(void)
{
    static int var;
    var = var + 10;
    return var;
}

int func_localstatic2(void)
{
    static int var = 100;
    var = var + 10;
    return var;
}

void func_forloop1()
{
    int x, y;

    for (x = 0, y = 0; x + y < 10; ++x)
    {
        y = getchar();
        y = y - '0'; /* subtract the ASCII code for 0
                        from y */
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "x+y: " << x + y << endl;

        /*if(y<0){
            break;
        }*/
    }
}

void converge(char *targ, char *src)
{
    int i, j;
    printf("%s\n", targ);
    for (i = 0, j = strlen(src) - 1; i <= j; i++, j--)
    {
        printf("targ: %c, src: %c", targ[i], src[i]);
        printf("%s %ld\n", targ, strlen(targ));
        targ[i] = src[i];
        printf("targ: %c, src: %c", targ[j], src[j]);
        targ[j] = src[j];
        printf("targ: %c, src: %c", targ[j], src[j]);
        printf("%s\n", targ);
    }
}

void sign_on(void)
{
    char str[20] = "";
    int x;
    for (x = 0; x < 3 && strcmp(str, "password"); ++x)
    {
        printf("Enter password please:");
        scanf("%s", str);
    }
    if (x == 3)
        return;
    else
        printf("logged in");
    /* else log user in ... */
}


int array_func1(void)
{
    register int t, i, j;
    printf("Enter an empty line to quit.\n");
    for (t = 0; t < MAX; t++)
    {
        printf("%d: ", t);
        fgets(text[t], LEN, stdin);
        if (!*text[t])
            break; /* quit on blank line */
    }
    for (i = 0; i < t; i++)
    {
        for (j = 0; text[i][j]; j++)
            putchar(text[i][j]);
        putchar('\n');
    }
    return 0;
}

int main()
{

    // For Loop testing
    // char target[100] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXYYYYYYYY";
    // converge(target, "This is a test of converge().");
    // printf("Final string: %s\n", target);

    // To Understand Local Static Variables
    /*
    cout<<func_localstatic()<<endl;
    cout<<func_localstatic()<<endl;
    cout<<func_localstatic2()<<endl;
    cout<<func_localstatic2()<<endl;
    */

    // For Loop testing
    // func_forloop1(); //Understand again

    // For Loop Testing
    // sign_on();

    //For array testing
    array_func1();

    return 0;
}
