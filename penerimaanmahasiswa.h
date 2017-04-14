#ifndef PENERIMAANMAHASISWA_H_INCLUDED
#define PENERIMAANMAHASISWA_H_INCLUDED

#include <iostream>
using namespace std;

#define info_jurusan(P) (P)->info_jurusan
#define next_jurusan(P) (P)->next_jurusan
//#define prev_maba(P) (P)->prev_maba
#define first_jurusan(L) (L).first_jurusan
//#define last_maba(L) (L).last_maba
#define info_maba(P) (P)->info_maba
#define next_maba(P) (P)->next_maba
//#define prev_maba(P) (P)->prev_maba
#define first_maba(L) (L).first_maba
//#define last_maba(L) (L).last_maba
#define jurusan(P) (P)->jurusan
#define next_relasi(P) (P)->next_relasi
//#define prev_relasi(P) (P)->prev_relasi
#define first_relasi(L) (L).first_relasi
//#define last_relasi(L) (L).last_relasi



struct maba{
    string nama;
    string asal_sma;
    string jurusan_sma;
};

typedef struct elmList_maba *address_maba;

struct elmList_maba{
    maba info_maba;
    address_maba next_maba;
    //address_maba prev_maba;
};

struct List_maba{
    address_maba first_maba;
    //address_maba last_maba;
};

struct jurusan{
    string fakultas;
    string jurusan;
};

typedef struct elmList_jurusan *address_jurusan;

struct elmList_jurusan{
    jurusan info_jurusan;
    address_jurusan next_jurusan;
    //address_jurusan prev_jurusan;'
};

struct List_jurusan{
    address_jurusan first_jurusan;
    //address_jurusan last_jurusan;
};

typedef struct elmList_relasi *address_relasi;

struct elmList_relasi{
    address_relasi next_relasi;
    //address_relasi prev_relasi;
    address_jurusan next_jurusan;
    //address_jurusan prev_jurusan;
    address_maba next_maba;
};

struct List_relasi{
    address_relasi first_relasi;
    //address_relasi last_relasi;
};

//mahasiswabaru
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

//jurusan
void createList_jurusan(List_jurusan &L);
address_jurusan alokasi_jurusan(jurusan x);
void dealokasi_jurusan(address_jurusan &P);
void insertFirst_jurusan(List_jurusan &L, address_jurusan P);
void insertLast_jurusan(List_jurusan &L, address_jurusan P);
address_jurusan findElm_jurusan(List_jurusan L, string x);
void deleteFirst_jurusan(List_jurusan &L, address_jurusan &P);
void deleteLast_jurusan(List_jurusan &L, address_jurusan &P);
void printInfo_jurusa(List_jurusan L);
void insertAfter_jurusan(address_jurusan Prec, address_jurusan P);
void deleteAfter_jurusan(address_jurusan Prec, address_jurusan &P);

//relasi
void createList_relasi(List_relasi &L);
address_relasi alokasi_relasi();
void dealokasi_relasi(address_relasi &P);
void insertFirst_relasi(List_relasi &L, address_relasi P);
void insertLast_relasi(List_relasi &L, address_relasi P);
address_relasi findElm_relasi(List_relasi L,  string x);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void printInfo(List_relasi L);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteAfter(address_relasi Prec, address_relasi &P);


#endif // PENERIMAANMAHASISWA_H_INCLUDED
