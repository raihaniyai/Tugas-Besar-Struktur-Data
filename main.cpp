#include <iostream>
#include "relasi.h"

using namespace std;

int main()
{
    List_maba LM;
    List_jurusan LJ;
    List_relasi LR;
    address_maba PM;
    address_jurusan PJ;
    address_relasi PR;
    createList_maba(LM);
    createList_jurusan(LJ);
    createList_relasi(LR);
    menu(LM,LJ,LR);


    return 0;
}

