#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "jurusan.h"
#include "mahasiswabaru.h"
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;



#define next_relasi(P) (P)->next_relasi
#define prev_relasi(P) (P)->prev_relasi
#define first_relasi(L) (L).first_relasi

typedef struct elmList_relasi *address_relasi;

struct elmList_relasi{
    address_relasi next_relasi;
    address_relasi prev_relasi;
    address_jurusan kejurusan;
    address_maba kemaba;
};

struct List_relasi{
    address_relasi first_relasi;
};

void createList_relasi(List_relasi &L);
address_relasi alokasi_relasi();
void dealokasi_relasi(address_relasi &P);
void insertFirst_relasi(List_relasi &L, address_relasi P);
void insertLast_relasi(List_relasi &L, address_relasi P);
address_relasi find_relasi(List_relasi L, string x, string y);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void print_relasi(List_relasi L);
void insertAfter_relasi(address_relasi Prec, address_relasi P);
void deleteAfter_relasi(address_relasi Prec, address_relasi &P);
void menu(List_maba LM, List_jurusan LJ, List_relasi LR);
void input_relasi(List_maba LM, List_jurusan LJ, List_relasi &LR);
void deleteSearch_relasi(List_relasi &L, address_relasi &P);
void delete_maba(List_relasi &LR, List_maba &LM, address_maba &PM);
void delete_jurusan(List_relasi &LR, List_jurusan &LJ, address_jurusan &PJ);
void search_maba(List_maba LM, List_relasi LR, address_maba P);
void search_jurusan(List_jurusan LJ, List_relasi LR, address_jurusan PJ);
void data_relasi (List_relasi &L, List_maba LM, List_jurusan LJ);
void delete_relasi(List_relasi &L, address_relasi &P);

#endif // RELASI_H_INCLUDED
