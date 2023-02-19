#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 _ _ _
|     |
|     O
|    /|\
|    / \
|

*/


void printer(int n)
{
    switch (n)
    {
        case 0:
            printf(" _ _ _\n|     |\n|\n|\n|\n|\n");
            break;
        case 1:
            printf(" _ _ _\n|     |\n|     O\n|\n|\n|\n");
            break;
        case 2:
            printf(" _ _ _\n|     |\n|     O\n|     |\n|\n|\n");
            break;
        case 3:
            printf(" _ _ _\n|     |\n|     O\n|    /|\\ \n|\n|\n");
            break;
        case 4:
            printf(" _ _ _\n|     |\n|     O\n|    /|\\ \n|    / \\ \n|\n");
            break;
        
    }
}

char *input()
{
    char *p=malloc(sizeof(char)),q;
    int i=1;
    while((q=getchar())!='\n')
    {
        p=realloc(p,sizeof(char)*(i+1));
        p[i-1]=q;
        p[i]=0;
        i++;
    }
    return p;
}

int length_finder(char *p)
{
    int i;
    for(i=0;*p;p++,i++);
    return i;
}

char *control_word_creator(int length)
{
    int i;
    char *ptr=malloc(sizeof(char)*(length+1));
    for(i=0;i<length;i++)
    {
        ptr[i]='_';
    }
    ptr[i+1]=0;
    return ptr;
}

int in_string(char *word,char c)
{   
    for(;*word;word++)
    {
        if(c==*word)
            return 1;
    }
    return 0;
}

void *placer(char *control_string,char *word,char c)
{
    for(;*control_string && *word;control_string++,word++)
    {
        if(*word==c)
            *control_string=c;   
    }
}

int if_full(char *control)
{
    for(;*control;control++)
    {
        if(*control=='_')
            return 1;
    }
    return 0;
}

int main()
{
    int length,k=1;
    char *word,*hint,*control_word,c;
    printf("enter the word you want your friend to guess!\n");
    word=input();
    printf("enter a hint!\n");
    hint=input();
    length=length_finder(word);
    control_word=control_word_creator(length);
    printer(k-1);
    while(k<5)
    {
        scanf(" %c",&c);
        if(in_string(word,c))
        {
            placer(control_word,word,c);
            printf("%s\n",control_word);
            if(!if_full(control_word))
            {
                break;
            }
        }
        else
        {
            printf("**********\n\n");
            printer(k);
            printf("***********\n");
            printf("you have %d try left!\n",4-k);
            k++;
        }
    }
    if(!if_full(control_word))
    {
        printf("THE WORD WAS %s\n",word);
        printf("YOU WON THE GAME!\n");
    }
    else
    {
        printf("THE MAN WAS HUNG, YOU LOST THE GAME!\n");
    }
    return 0;
}
