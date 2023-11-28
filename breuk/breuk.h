#ifndef _HR_BroJZ_Breuk_
#define _HR_BroJZ_Breuk_

typedef struct
{
    int teller;
    int noemer;
} Breuk;

extern Breuk add(Breuk b1, Breuk b2);
extern Breuk mul(Breuk b1, Breuk b2);

#endif
