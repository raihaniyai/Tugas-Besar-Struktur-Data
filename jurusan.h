#ifndef JURUSAN_H_INCLUDED
#define JURUSAN_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;



#define info_jurusan(P) (P)->info_jurusan
#define next_jurusan(P) (P)->next_jurusan
#define prev_jurusan(P) (P)->prev_jurusan
#define first_jurusan(L) (L).first_jurusan
#define kejurusan(P) (P)->kejurusan

struct jurusan{
    string fakultas;
    string jurusan_kul;
    char akreditasi;
};

typedef struct elmList_jurusan *address_jurusan;

struct elmList_jurusan{
    jurusan info_jurusan;
    address_jurusan next_jurusan;
    address_jurusan prev_jurusan;
};

struct List_jurusan{
    address_jurusan first_jurusan;
};

void createList_jurusan(List_jurusan &L);
address_jurusan alokasi_jurusan(jurusan x);
void dealokasi_jurusan(address_jurusan &P);
void insertFirst_jurusan(List_jurusan &L, address_jurusan P);
void insertLast_jurusan(List_jurusan &L, address_jurusan P);
address_jurusan findElm_jurusan(List_jurusan L, string x);
void deleteFirst_jurusan(List_jurusan &L, address_jurusan &P);
void deleteLast_jurusan(List_jurusan &L, address_jurusan &P);
void printInfo_jurusan(List_jurusan L);
void insertAfter_jurusan(address_jurusan Prec, address_jurusan P);
void deleteAfter_jurusan(address_jurusan Prec, address_jurusan &P);
address_jurusan input_jurusan();
void editInfo_jurusan(List_jurusan L, address_jurusan &P);
void data_jurusan (List_jurusan &L);
void deleteSearch_jurusan(List_jurusan &L, address_jurusan &P);

#endif // JURUSAN_H_INCLUDED
