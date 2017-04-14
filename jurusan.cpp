#include "jurusan.h"

void createList_jurusan(List_jurusan &L){
    first_jurusan(L)=NULL;
}

address_jurusan alokasi_jurusan(jurusan x){
    address_jurusan P=new elmList_jurusan;
    info_jurusan(P)=x;
    next_jurusan(P)=NULL;
    prev_jurusan(P)=NULL;
    return P;
}

void dealokasi_jurusan(address_jurusan &P){
    delete P;
}

void insertFirst_jurusan(List_jurusan &L, address_jurusan P){
    address_jurusan Q;
    if(first_jurusan(L)==NULL){
        first_jurusan(L)=P;
        next_jurusan(P)=first_jurusan(L);
    }
    else{
        Q=first_jurusan(L);
        while(next_jurusan(Q)!=first_jurusan(L)){
            Q=next_jurusan(Q);
        }
        next_jurusan(P)=first_jurusan(L);
        first_jurusan(L)=P;
        prev_jurusan(first_jurusan(L))=P;
        next_jurusan(Q)=P;
        prev_jurusan(P)=Q;
    }
}

void insertLast_jurusan(List_jurusan &L, address_jurusan P){
    address_jurusan Q;
    if(first_jurusan(L)==NULL){
        first_jurusan(L)=P;
        next_jurusan(P)=first_jurusan(L);
    }
    else{
        Q=first_jurusan(L);
        while(next_jurusan(Q)!=first_jurusan(L)){
            Q=next_jurusan(Q);
        }
        next_jurusan(Q)=P;
        next_jurusan(P)=first_jurusan(L);
        prev_jurusan(P)=Q;
        prev_jurusan(first_jurusan(L))=P;
    }
}

address_jurusan findElm_jurusan(List_jurusan L, string x){
    bool cek;
    address_jurusan P;
    if(first_jurusan(L)!=NULL){
        cek=false;
        P=first_jurusan(L);
        while((cek==false)&&(next_jurusan(P)!=first_jurusan(L))){
            if(info_jurusan(P).jurusan_kul == x){
                cek=true;
            }
            else{
                P=next_jurusan(P);
            }
        }
        if (cek == false){
            if(info_jurusan(P).jurusan_kul == x){
                cek=true;
            }
        }
    }
    if(cek==false){
        return P=NULL;
    }
    return P;
}

void deleteFirst_jurusan(List_jurusan &L, address_jurusan &P){
    address_jurusan Q;
    if(first_jurusan(L)!=NULL){
        Q=first_jurusan(L);
        while(next_jurusan(Q)!=first_jurusan(L)){
            Q=next_jurusan(Q);
        }
        P=first_jurusan(L);
        first_jurusan(L)=next_jurusan(first_jurusan(L));
        next_jurusan(P)=NULL;
        prev_jurusan(first_jurusan(L))=Q;
        next_jurusan(Q)=first_jurusan(L);
    }
}

void deleteLast_jurusan(List_jurusan &L, address_jurusan &P){
    address_jurusan Prec;
    if(first_jurusan(L)!=NULL){
        P=first_jurusan(L);
        do{
            Prec=P;
            P=next_jurusan(P);
        }while(next_jurusan(P)!=first_jurusan(L));
        next_jurusan(Prec)=first_jurusan(L);
        prev_jurusan(first_jurusan(L))=Prec;
    }
}

void deleteSearch_jurusan(List_jurusan &L, address_jurusan &P){
    address_jurusan Q, Prec;
    Q=first_jurusan(L);
    do{
        Q=next_jurusan(Q);
    }while (next_jurusan(Q)!=first_jurusan(L));
    //Q=next_jurusan(Q);
    if(P!=NULL){
        if(P==first_jurusan(L)){
            if(next_jurusan(P)==first_jurusan(L)){
                first_jurusan(L)=NULL;
            }
            else{
                deleteFirst_jurusan(L, P);
            //P=first_jurusan(L);
            }
        }else if(P==Q){
            deleteLast_jurusan(L, P);
           // P=Q;
        }else{
            Prec = prev_jurusan(P);
            deleteAfter_jurusan(Prec, P);
            //P=Prec;
        }
        //dealokasi_jurusan(P);
    }

}

void printInfo_jurusan(List_jurusan L){
    address_jurusan P;
    if(first_jurusan(L)==NULL){
        cout << "=================================================================" << endl;
        cout << "\t\t  Daftar Jurusan Telkom University" << endl;
        cout << "=================================================================" << endl;
        cout<<endl;
        cout<<"\t\t  Belum Ada Jurusan yang Terdaftar\n"<<endl;
    }
    else{
        system("cls");
        cout << "=================================================================" << endl;
        cout << "\t\t  Daftar Jurusan Telkom University" << endl;
        cout << "=================================================================" << endl;
        cout << "Fakultas \t\t| Jurusan\t\t|   Akreditasi\t|" << endl;
        cout << "=================================================================" << endl;
        P=first_jurusan(L);
        while(next_jurusan(P)!=first_jurusan(L)){
            cout<<info_jurusan(P).fakultas<<"\t| "<<info_jurusan(P).jurusan_kul<<"\t| \t["<<info_jurusan(P).akreditasi<<"]\t|";
            cout<<endl;
            P=next_jurusan(P);

        }
        cout<<info_jurusan(P).fakultas<<"\t| "<<info_jurusan(P).jurusan_kul<<"\t| \t["<<info_jurusan(P).akreditasi<<"]\t|";
        cout<<"\n\n";
    }
}

void insertAfter_jurusan(address_jurusan Prec, address_jurusan P){
        next_jurusan(P)=next_jurusan(Prec);
        prev_jurusan(next_jurusan(Prec))=P;
        next_jurusan(Prec)=P;
        prev_jurusan(P)=Prec;
}

void deleteAfter_jurusan(address_jurusan Prec, address_jurusan &P){
        P=next_jurusan(Prec);
        prev_jurusan(next_jurusan(P))=next_jurusan(P);
        next_jurusan(Prec)=next_jurusan(P);
        next_jurusan(P)=NULL;
        prev_jurusan(P)=NULL;
}

void editInfo_jurusan(List_jurusan L, address_jurusan &P){
    cout<<"Fakultas \t: ";
    cin.ignore();
    getline(cin,info_jurusan(P).fakultas);
    cout<<"Jurusan \t: ";
    getline(cin,info_jurusan(P).jurusan_kul);
    cout<<"Akreditasi \t: ";
    cin>>info_jurusan(P).akreditasi;
}

address_jurusan input_jurusan(){
    jurusan x;
    cin.ignore();
    cout<<"Fakultas \t: ";
    getline(cin,x.fakultas);
    cout<<"Jurusan \t: ";
    getline(cin,x.jurusan_kul);
    cout<<"Akreditasi \t: ";
    cin>>x.akreditasi;

    return alokasi_jurusan(x);
}

void data_jurusan (List_jurusan &L){
    jurusan jur;
    address_jurusan P;

    jur.fakultas = "FAKULTAS TEKNIK ELEKTRO";
    jur.jurusan_kul = "S1 TEK TELEKOMUNIKASI";
    jur.akreditasi = 'A';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS TEKNIK ELEKTRO";
    jur.jurusan_kul = "S1 TEKNIK ELEKTRO";
    jur.akreditasi = 'A';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS TEKNIK ELEKTRO";
    jur.jurusan_kul = "S1 TEKNIK FISIKA";
    jur.akreditasi = 'B';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAK REKAYASA INDUSTRI";
    jur.jurusan_kul = "S1 TEKNIK INDUSTRI";
    jur.akreditasi = 'A';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAK REKAYASA INDUSTRI";
    jur.jurusan_kul = "S1 SISTEM INFORMASI";
    jur.akreditasi = 'B';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS INFORMATIKA";
    jur.jurusan_kul = "S1 TEKNIK INFORMATIKA";
    jur.akreditasi = 'A';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS INFORMATIKA";
    jur.jurusan_kul = "S1 ILMU KOMPUTASI";
    jur.akreditasi = 'B';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS ILMU TERAPAN";
    jur.jurusan_kul = "D3 TEK TELEKOMUNIKASI";
    jur.akreditasi = 'A';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS ILMU TERAPAN";
    jur.jurusan_kul = "D3 TEKNIK INFORMATIKA";
    jur.akreditasi = 'A';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS ILMU TERAPAN";
    jur.jurusan_kul = "D3 TEKNIK KOMPUTER";
    jur.akreditasi = 'C';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS EKONOMI";
    jur.jurusan_kul = "S1 MANAJEMEN BISNIS";
    jur.akreditasi = 'A';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAKULTAS KOMUNIKASI";
    jur.jurusan_kul = "S1 ILMU KOMUNIKASI";
    jur.akreditasi = 'B';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAK INDUSTRI KREATIF";
    jur.jurusan_kul = "S1 DESAIN INTERIOR";
    jur.akreditasi = 'B';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);

    jur.fakultas = "FAK INDUSTRI KREATIF";
    jur.jurusan_kul = "S1 DESAIN PRODUK";
    jur.akreditasi = 'B';
    P = alokasi_jurusan(jur);
    insertLast_jurusan(L,P);
}
