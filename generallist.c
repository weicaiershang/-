/* *
 * http://data.biancheng.net/view/190.html
 * */
#include <stdio.h>
#include <string.h>

/* *
 * tag == 0; atom
 * tag == 1; Glist
 * */

typedef struct GLNode{
    int tag;
    union{
        char atom;
        struct{
            struct GLNode *hp, *tp;
        }ptr;
    };
}*Glist;

/**
 * @brief createGlist   {a, {b, c, d}}
 * @param C
 * @return
 */
Glist createGlist(Glist C){
    C = (Glist)malloc(sizeof (Glist));
    C->tag = 1;

    //head 'a'
    C->ptr.hp = (Glist)malloc(sizeof (Glist));
    C->ptr.hp->tag = 0;
    C->ptr.hp->atom = 'a';

    //tail {b, c, d}
    C->ptr.tp = (Glist)malloc(sizeof (Glist));
    C->ptr.tp->tag = 1;
    C->ptr.tp->ptr.hp = (Glist)malloc(sizeof (Glist));
    C->ptr.tp->ptr.tp = NULL;

    //b {c, d}
    C->ptr.tp->ptr.hp->tag = 1;
    C->ptr.tp->ptr.hp->ptr.hp = (Glist)malloc(sizeof (Glist));
    C->ptr.tp->ptr.hp->ptr.hp->tag = 0;
    C->ptr.tp->ptr.hp->ptr.hp->atom = 'b';
    C->ptr.tp->ptr.hp->ptr.tp = (Glist)malloc(sizeof (Glist));

    //c {d}
    C->ptr.tp->ptr.hp->ptr.tp->tag = 1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp = (Glist)malloc(sizeof (Glist));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag = 0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom = 'c';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp = (Glist)malloc(sizeof (Glist));

    //{d}
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag = 1;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp = (Glist)malloc(sizeof (Glist));
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag = 0;
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom = 'd';
    C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp = NULL;

    return C;
}
