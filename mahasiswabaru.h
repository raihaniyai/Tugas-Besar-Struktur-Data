#ifndef MAHASISWABARU_H_INCLUDED
#define MAHASISWABARU_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;


#define info_maba(P) (P)->info_maba
#define next_maba(P) (P)->next_maba
#define prev_maba(P) (P)->prev_maba
#define first_maba(L) (L).first_maba
#define jurusan(P) (P)->jurusan
#define kemaba(P) (P)->kemaba

struct maba{
    string nama;
    string asal_sma;
    string jurusan_sma;
    int id_siswa;
    string alamat;
    string jkelamin;
    string jalur_masuk;
    long int sumbangan;
};

typedef struct elmList_maba *address_maba;

struct elmList_maba{
    maba info_maba;
    address_maba next_maba;
    address_maba prev_maba;
};

struct List_maba{
    address_maba first_maba;
};

void createList_maba(List_maba &L);
address_maba alokasi_maba(maba x);
void dealokasi_maba(address_maba &P);
void insertFirst_maba(List_maba &L, address_maba P);
void insertLast_maba(List_maba &L, address_maba P);
address_maba findElm_maba(List_maba L, string x);
void deleteFirst_maba(List_maba &L, address_maba &P);
void deleteLast_maba(List_maba &L, address_maba &P);
void printInfo_maba(List_maba L);
void insertAfter_maba(address_maba Prec, address_maba P);
void deleteAfter_maba(address_maba Prec, address_maba &P);
void editInfo_maba(List_maba L, address_maba &P);
address_maba input_maba();
void deleteSearch_maba(List_maba &LM, address_maba &P);
void data_maba (List_maba &L);

#endif // MAHASISWABARU_H_INCLUDED
