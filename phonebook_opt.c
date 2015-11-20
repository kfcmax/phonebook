#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

int Index[26]= {0,23406,45568,73678,91240,103587,115768,128779,142481,152410,156612,166539,179156,202470,213029,222674,248661,250100,264117,298188,316404,330926,336619,344722,345721,347698};

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{
    /* TODO: implement */
    int i = 0;
    while(i <= Index[lastname[0]-'a']) {
        pHead = pHead->pNext;
        i++;
    }
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}