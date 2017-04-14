#include "mahasiswabaru.h"

void createList_maba(List_maba &L){
    first_maba(L)=NULL;
}

address_maba alokasi_maba(maba x){
    address_maba P=new elmList_maba;
    info_maba(P)=x;
    next_maba(P)=NULL;
    prev_maba(P)=NULL;
    return P;
}

void dealokasi_maba(address_maba &P){
    delete P;
}

void insertFirst_maba(List_maba &L, address_maba P){
    address_maba Q;
    if(first_maba(L)==NULL){
        first_maba(L)=P;
        next_maba(P)=first_maba(L);
    }
    else{
        Q=first_maba(L);
        while(next_maba(Q)!=first_maba(L)){
            Q=next_maba(Q);
        }
        next_maba(P)=first_maba(L);
        first_maba(L)=P;
        prev_maba(first_maba(L))=P;
        next_maba(Q)=P;
        prev_maba(P)=Q;
    }
}

void insertLast_maba(List_maba &L, address_maba P){
    address_maba Q;
    if(first_maba(L)==NULL){
        first_maba(L)=P;
        next_maba(P)=first_maba(L);
    }
    else{
        Q=first_maba(L);
        while(next_maba(Q)!=first_maba(L)){
            Q=next_maba(Q);
        }
        next_maba(Q)=P;
        next_maba(P)=first_maba(L);
        prev_maba(P)=Q;
        prev_maba(first_maba(L))=P;
    }
}

address_maba findElm_maba(List_maba L, string x){
    bool cek;
    address_maba P;
    if(first_maba(L)!=NULL){
        cek=false;
        P=first_maba(L);
        while((cek==false)&&(next_maba(P)!=first_maba(L))){
            if(info_maba(P).nama == x){
                cek=true;
            }
            else{
                P=next_maba(P);
            }
        }
        if (cek == false){
            if(info_maba(P).nama == x){
                cek=true;
            }
        }
    }
    if(cek!=true){
        return P=NULL;
    }
    return P;
}

void deleteFirst_maba(List_maba &L, address_maba &P){
    address_maba Q;
    if(first_maba(L)!=NULL){
        Q=first_maba(L);
        while(next_maba(Q)!=first_maba(L)){
            Q=next_maba(Q);
        }
        P=first_maba(L);
        first_maba(L)=next_maba(first_maba(L));
        next_maba(P)=NULL;
        prev_maba(first_maba(L))=Q;
        next_maba(Q)=first_maba(L);
    }
}

void deleteLast_maba(List_maba &L, address_maba &P){
    address_maba Prec;
    if(first_maba(L)!=NULL){
        P=first_maba(L);
        do{
            Prec=P;
            P=next_maba(P);
        }while(next_maba(P)!=first_maba(L));
        next_maba(Prec)=first_maba(L);
        prev_maba(first_maba(L))=Prec;
    }
}

void printInfo_maba(List_maba L){
    address_maba P;
    if(first_maba(L)==NULL){
        cout << "========================================================================================================================" << endl;
        cout << "\t\t\t\t\t\t  Daftar Mahasiswa Baru" << endl;
        cout << "========================================================================================================================" << endl;
        cout<<endl;
        cout<<"\t\t\t\t\tBelum Ada Mahasiswa Baru yang Terdaftar\n"<<endl;
    }
    else{
        cout << "========================================================================================================================" << endl;
        cout << "\t\t\t\t\t\t  Daftar Mahasiswa Baru" << endl;
        cout << "========================================================================================================================" << endl;
        cout << "ID \t| Nama \t\t| Asal SMA\t| Kota\t\t| Jurusan SMA\t| Jenis Kelamin\t| Jalur Masuk\t| Sumbangan" << endl;
        cout << "========================================================================================================================" << endl;
        P=first_maba(L);
        while(next_maba(P)!=first_maba(L)){
            cout<<info_maba(P).id_siswa<<"\t| "<<info_maba(P).nama<<"\t| ";
            cout<<info_maba(P).asal_sma<<"\t| "<<info_maba(P).alamat<<"\t| ";
            cout<<info_maba(P).jurusan_sma<<"\t\t| "<<info_maba(P).jkelamin<<"\t\t| ";
            cout<<info_maba(P).jalur_masuk<<"\t\t| Rp"<<info_maba(P).sumbangan;
            cout<<endl;
            P=next_maba(P);

        }
        cout<<info_maba(P).id_siswa<<"\t| "<<info_maba(P).nama<<"\t| ";
        cout<<info_maba(P).asal_sma<<"\t| "<<info_maba(P).alamat<<"\t| ";
        cout<<info_maba(P).jurusan_sma<<"\t\t| "<<info_maba(P).jkelamin<<"\t\t| ";
        cout<<info_maba(P).jalur_masuk<<"\t\t| Rp"<<info_maba(P).sumbangan;
        cout<<"\n\n";
    }
}

void insertAfter_maba(address_maba Prec, address_maba P){
        next_maba(P)=next_maba(Prec);
        prev_maba(next_maba(Prec))=P;
        next_maba(Prec)=P;
        prev_maba(P)=Prec;
}

void deleteAfter_maba(address_maba Prec, address_maba &P){
        P=next_maba(Prec);
        prev_maba(next_maba(P))=prev_maba(P);
        next_maba(Prec)=next_maba(P);
        next_maba(P)=NULL;
        prev_maba(P)=NULL;
}

void deleteSearch_maba(List_maba &LM, address_maba &P){
    address_maba Q, Prec;
    Q=first_maba(LM);
    do{
        Q=next_maba(Q);
    }while (next_maba(Q)!=first_maba(LM));
    //Q=next_maba(Q);
    if(P!=NULL){
        if(P==first_maba(LM)){
            if(next_maba(P)==first_maba(LM)){
                first_maba(LM)=NULL;
            }
            else{
                deleteFirst_maba(LM, P);
                //P=first_maba(LM);
            }
        }else if(P==Q){
            deleteLast_maba(LM, P);
            //P=Q;
        }else{
            Prec = prev_maba(P);
            deleteAfter_maba(Prec, P);
            //P=Prec;
        }
        //dealokasi_maba(P);
    }
}

void editInfo_maba(List_maba L, address_maba &P){
    cout<<"Nomor ID \t\t: ";
    cin>>info_maba(P).id_siswa;
    cin.ignore();
    cout<<"Nama \t\t\t: ";
    getline(cin,info_maba(P).nama);
    cout<<"Asal SMA \t\t: ";
    getline(cin,info_maba(P).asal_sma);
    cout<<"Kota \t\t\t: ";
    getline(cin,info_maba(P).alamat);
    cout<<"Jurusan SMA \t\t: ";
    getline(cin,info_maba(P).jurusan_sma);
    cout<<"Jenis Kelamin (L/P)\t: ";
    getline(cin,info_maba(P).jkelamin);
    cout<<"Jalur Masuk \t\t: ";
    getline(cin,info_maba(P).jalur_masuk);
    cout<<"Sumbangan  \t\t: ";
    cin>>info_maba(P).sumbangan;
}

address_maba input_maba(){
    maba x;
    cout<<"Nomor ID \t\t: ";
    cin>>x.id_siswa;
    cin.ignore();
    cout<<"Nama \t\t\t: ";
    getline(cin,x.nama);
    cout<<"Asal SMA \t\t: ";
    getline(cin,x.asal_sma);
    cout<<"Kota \t\t\t: ";
    getline(cin,x.alamat);
    cout<<"Jurusan SMA \t\t: ";
    getline(cin,x.jurusan_sma);
    cout<<"Jenis Kelamin (L/P)\t: ";
    getline(cin,x.jkelamin);
    cout<<"Jalur Masuk \t\t: ";
    getline(cin,x.jalur_masuk);
    cout<<"Sumbangan  \t\t: ";
    cin>>x.sumbangan;

    return alokasi_maba(x);
}

void data_maba (List_maba &L){
    maba mb;
    address_maba P;

    mb.id_siswa = 1;
    mb.nama = "ANDREA HIRATA";
    mb.asal_sma = "SMAN 1";
    mb.jurusan_sma = "IPS";
    mb.alamat = "BELITUNG";
    mb.jalur_masuk = "UTG";
    mb.jkelamin = "L";
    mb.sumbangan = 1000000;
    P = alokasi_maba(mb);
    insertLast_maba(L,P);

    mb.id_siswa = 2;
    mb.nama = "TERE LIYE";
    mb.asal_sma = "SMAN 5";
    mb.jurusan_sma = "IPA";
    mb.alamat = "LAMPUNG";
    mb.jalur_masuk = "JPA";
    mb.jkelamin = "L";
    mb.sumbangan = 1000000;
    P = alokasi_maba(mb);
    insertLast_maba(L,P);

    mb.id_siswa = 3;
    mb.nama = "PIDI BAIQ";
    mb.asal_sma = "SMAN 5";
    mb.jurusan_sma = "IPA";
    mb.alamat = "BANDUNG";
    mb.jalur_masuk = "UTG";
    mb.jkelamin = "L";
    mb.sumbangan = 2000000;
    P = alokasi_maba(mb);
    insertLast_maba(L,P);

    mb.id_siswa = 4;
    mb.nama = "OKI SETIANA";
    mb.asal_sma = "SMAN 1";
    mb.jurusan_sma = "IPA";
    mb.alamat = "DEPOK  ";
    mb.jalur_masuk = "JPA";
    mb.jkelamin = "P";
    mb.sumbangan = 1500000;
    P = alokasi_maba(mb);
    insertLast_maba(L,P);

    mb.id_siswa = 5;
    mb.nama = "NADIM MAKARIM";
    mb.asal_sma = "SMAN 1";
    mb.jurusan_sma = "IPS";
    mb.alamat = "JAKARTA";
    mb.jalur_masuk = "JPA";
    mb.jkelamin = "L";
    mb.sumbangan = 1500000;
    P = alokasi_maba(mb);
    insertLast_maba(L,P);

    mb.id_siswa = 6;
    mb.nama = "ASMA NADIA";
    mb.asal_sma = "SMAN 1 ";
    mb.jurusan_sma = "IPA";
    mb.alamat = "JAKARTA";
    mb.jalur_masuk = "UTG";
    mb.jkelamin = "P";
    mb.sumbangan = 1000000;
    P = alokasi_maba(mb);
    insertLast_maba(L,P);

    mb.id_siswa = 7;
    mb.nama = "JOKO WIDODO";
    mb.asal_sma = "SMAN 4";
    mb.jurusan_sma = "IPA";
    mb.alamat = "SURABAYA";
    mb.jalur_masuk = "JPA";
    mb.jkelamin = "L";
    mb.sumbangan = 2500000;
    P = alokasi_maba(mb);
    insertLast_maba(L,P);

    mb.id_siswa = 8;
    mb.nama = "RADITYA DIKA";
    mb.asal_sma = "SMAN 70";
    mb.jurusan_sma = "IPA";
    mb.alamat = "JAKARTA";
    mb.jalur_masuk = "JPU";
    mb.jkelamin = "L";
    mb.sumbangan = 0;
    P = alokasi_maba(mb);
    insertLast_maba(L,P);
}
