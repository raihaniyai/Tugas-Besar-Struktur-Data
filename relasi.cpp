#include "relasi.h"

void createList_relasi(List_relasi &L){
    first_relasi(L)=NULL;
}

address_relasi alokasi_relasi(address_maba PM, address_jurusan PJ){
    address_relasi P = new elmList_relasi;
    kejurusan(P)= PJ;
    kemaba(P)=PM;
    next_relasi(P)= NULL;
    return P;
}

void dealokasi_relasi(address_relasi &P){
    delete P;
}

void insertFirst_relasi(List_relasi &L, address_relasi P){
    if(first_relasi(L)==NULL){
        first_relasi(L)=P;
        next_relasi(first_relasi(L))=first_relasi(L);
        prev_relasi(first_relasi(L))=first_relasi(L);
    }
    else{
    	address_relasi Q=prev_relasi(first_relasi(L));
    	if(next_relasi(first_relasi(L))==first_relasi(L)){
            next_relasi(P)=first_relasi(L);
            prev_relasi(P)=Q;
            next_relasi(Q)=P;
            prev_relasi(Q)=P;
            first_relasi(L)=P;
    	}
        else{
            next_relasi(P)=first_relasi(L);
            prev_relasi(P)=Q;
            prev_relasi(first_relasi(L))=P;
            next_relasi(Q)=P;
            first_relasi(L)=P;
        }
    }
}

void insertLast_relasi(List_relasi &L, address_relasi P){
    if(first_relasi(L)==NULL){
        first_relasi(L)=P;
        next_relasi(first_relasi(L))=first_relasi(L);
        prev_relasi(first_relasi(L))=first_relasi(L);
    }
    else{
        address_relasi Q=prev_relasi(first_relasi(L));
        prev_relasi(P)=Q;
        prev_relasi(first_relasi(L))=P;
        next_relasi(P)=first_relasi(L);
        next_relasi(Q)=P;
    }
}

address_relasi findElm_relasi(List_relasi L, address_maba PM, address_jurusan PJ){
    address_relasi P = first_relasi(L);
    bool found = false;
    if (first_relasi(L) != NULL){
        while ((next_relasi(P)!=NULL)&&(found == false)){
            if (kemaba(P) == PM&& kejurusan(P) == PJ){
                found = true;
                return P;
            }else{
                P=next_relasi(P);
            }
        }
    }
    else{
        P=NULL;
    }
    return P;
}

void deleteFirst_relasi(List_relasi &L, address_relasi &P){
    if(first_relasi(L)!=NULL){
        P=first_relasi(L);
    	if(next_relasi(first_relasi(L))==first_relasi(L)){
    		first_relasi(L)=NULL;
		}
		else{
            address_relasi Q=prev_relasi(first_relasi(L));
	        first_relasi(L)=next_relasi(P);
	        prev_relasi(first_relasi(L))=Q;
	        next_relasi(Q)=first_relasi(L);
	        next_relasi(P)=NULL;
	        prev_relasi(P)=NULL;
        }
    }
    else{
        cout<<"Data kosong"<<endl;
    }
}

void deleteLast_relasi(List_relasi &L, address_relasi &P){
        if(first_relasi(L)!=NULL){
    	if(next_relasi(first_relasi(L))==first_relasi(L)){
    		P=first_relasi(L);
    		createList_relasi(L);
		}
		else{
		    address_relasi Q=prev_relasi(prev_relasi(first_relasi(L)));
	        P=next_relasi(Q);
	        next_relasi(Q)=first_relasi(L);
	        prev_relasi(first_relasi(L))=Q;
	        next_relasi(P)=NULL;
	        prev_relasi(P)=NULL;
    	}
    }
    else{
        cout<<"Data kosong"<<endl;
    }
}

void print_relasi(List_relasi L){
    address_relasi P;
    if (first_relasi(L) == NULL){
        cout << "=========================================================================" << endl;
        cout << "\t\t  Daftar Jurusan yang dipilih Mahasiswa" << endl;
        cout << "=========================================================================" << endl;
        cout<<endl;
        cout<<"\t      Belum Ada Mahasiswa Baru yang Memilih Jurusan\n"<<endl;
    }
    else{
        cout << "=========================================================================" << endl;
        cout << "\t\t  Daftar Jurusan yang dipilih Mahasiswa" << endl;
        cout << "=========================================================================" << endl;
        cout << "Nama Mahasiswa \t\t| Asal SMA \t\t| Jurusan \t\t|" << endl;
        cout << "=========================================================================" << endl;
        P = first_relasi(L);
        while (next_relasi(P) != first_relasi(L)){
            cout<<info_maba(kemaba(P)).nama<<" \t\t| "<<info_maba(kemaba(P)).asal_sma<<" "<<info_maba(kemaba(P)).alamat<<"\t| "<<info_jurusan(kejurusan(P)).jurusan_kul<<"\t|";
            cout<<endl;
            P = next_relasi(P);
        }
        cout<<info_maba(kemaba(P)).nama<<" \t\t| "<<info_maba(kemaba(P)).asal_sma<<" "<<info_maba(kemaba(P)).alamat<<"\t| "<<info_jurusan(kejurusan(P)).jurusan_kul<<"\t|";
        cout<<endl;
    }
}

void insertAfter_relasi(List_relasi &L, address_relasi prec, address_relasi &P){
    if (first_relasi(L) == NULL){
        first_relasi(L) = P;
     }
     else{
         next_relasi(P) = next_relasi(prec);
         next_relasi(prec) = P;
     }
}

void deleteAfter_relasi(address_relasi Prec, address_relasi &P){
    P=next_relasi(Prec);
    prev_relasi(next_relasi(P))=prev_relasi(P);
    next_relasi(Prec)=next_relasi(P);
    next_relasi(P)=NULL;
    prev_relasi(P)=NULL;
}

void delete_relasi(List_relasi &L, address_relasi &P){
    address_relasi Q, Prec;
    if(P!=NULL){
        Q=first_relasi(L);
        do{
            Q=next_relasi(Q);
        }while (next_relasi(Q)!= first_relasi(L));
        //Q=next_relasi(Q);
        if(P==first_relasi(L)){
             if(next_relasi(P)==first_relasi(L)){
                first_relasi(L)=NULL;
            }
            else{
                deleteFirst_relasi(L, P);
                //P=first_relasi(L);
            }
        }
        else if(P==Q){
            deleteLast_relasi(L, P);
            //P=Q;
        }
        else{
            Prec = prev_relasi(P);
            deleteAfter_relasi(Prec, P);
            //P=Prec;
        }
        //dealokasi_relasi(P);
    }
}

void deleteSearch_relasi(List_relasi &L, address_relasi &P){
    address_relasi Q, Prec;
    if(P!=NULL){
        Q=first_relasi(L);
        while (next_relasi(Q)!= first_relasi(L)){
            Q=next_relasi(Q);
        }
        Q=next_relasi(Q);
        if(P==first_relasi(L)){
            if(next_relasi(P)==first_relasi(L)){
                first_relasi(L)=NULL;
            }
            else{
                deleteFirst_relasi(L, P);
                P=first_relasi(L);
            }
        }
        else if(P==Q){
            deleteLast_relasi(L, P);
            P=Q;
        }
        else{
            Prec = prev_relasi(P);
            deleteAfter_relasi(Prec, P);
            P=Prec;
        }
        //dealokasi_relasi(P);
    }
}

void delete_maba(List_relasi &LR, List_maba &LM, address_maba &PM){
    address_relasi P=first_relasi(LR);
    if(first_relasi(LR)!=NULL){
       do{
            if(kemaba(P)==PM){
                deleteSearch_relasi(LR, P);
            }
            P=next_relasi(P);
        } while(next_relasi(P)!=first_relasi(LR));
        if(kemaba(P)==PM){
            deleteSearch_relasi(LR, P);
        }
    }
    deleteSearch_maba(LM, PM);

}

void delete_jurusan(List_relasi &LR, List_jurusan &LJ, address_jurusan &PJ){
    address_relasi P=first_relasi(LR);
    if(first_relasi(LR)!=NULL){
        do{
            if(kejurusan(P)==PJ){
                deleteSearch_relasi(LR, P);
            }
            P=next_relasi(P);
        }while(next_relasi(P)!=first_relasi(LR));
        if(kejurusan(P)==PJ){
            deleteSearch_relasi(LR, P);
        }
    }

    deleteSearch_jurusan(LJ, PJ);
}

void input_relasi(List_maba LM, List_jurusan LJ, List_relasi &LR){
    address_maba PM;
    address_jurusan PJ;
    address_relasi PR;
    maba mdicari;
    jurusan jdicari;
    printInfo_maba(LM);
    cout<<"Nama Mahasiswa : ";
    cin.ignore();
    getline(cin,mdicari.nama);
    PM=findElm_maba(LM,mdicari.nama);
    if (PM!=NULL){
        system("cls");
        printInfo_jurusan(LJ);
        cout<<"Nama Mahasiswa : "<<mdicari.nama<<endl;
         cout<<"Jurusan yang ingin dipilih : ";
        getline(cin, jdicari.jurusan_kul);
        PJ=findElm_jurusan(LJ, jdicari.jurusan_kul);
        if (PJ!=NULL){
            PR=alokasi_relasi(PM,PJ);
            insertLast_relasi(LR,PR);
            cout<<endl;
            cout<<"Mahasiswa Baru Berhasil Memilih Jurusan"<<endl;
        }
        else{
            cout<<endl;
            cout<<"Jurusan tersebut tidak tersedia dalam pilihan"<<endl;
        }
    }
    else{
        cout<<"Data Mahasiswa Baru tidak ditemukan"<<endl;
    }
}

address_relasi find_relasi(List_relasi L, string x, string y){
    bool cek;
    address_relasi P;
    if(first_relasi(L)!=NULL){
        cek=false;
        P=first_relasi(L);
        while((cek==false)&&(next_relasi(P)!=first_relasi(L))){
            if(info_maba(kemaba(P)).nama == x){
                if(info_jurusan(kejurusan(P)).jurusan_kul == y){
                    cek=true;
                    return P;
                }
            }
            else{
                P=next_relasi(P);
            }
        }
        if (cek == false){
            if(info_maba(kemaba(P)).nama == x){
                if(info_jurusan(kejurusan(P)).jurusan_kul == y){
                    cek=true;
                }
            }
        }
    }
    if(cek!=true){
        return P=NULL;
    }
    return P;
}

void menu (List_maba LM, List_jurusan LJ, List_relasi LR) {
    int pil;
    maba mdicari;
    jurusan jdicari;
    address_maba PM;
    address_jurusan PJ;
    address_relasi PR;
    data_maba (LM);
    data_jurusan (LJ);
    data_relasi(LR, LM, LJ);
    do {
        system("cls");
        cout << "==================================================" << endl;
        cout << "\tAplikasi Penerimaan Mahasiswa Baru" << endl;
        cout << "==================================================" << endl;
        cout << " -- INPUT -- " << endl;
        cout << "1.  Pendaftaran Mahasiswa Baru" << endl;
        cout << "2.  Tambah Jurusan Baru" << endl;
        cout << "3.  Pemilihan Jurusan Mahasiswa Baru" << endl;
        cout << " -- EDIT -- " << endl;
        cout << "4.  Ubah Data Mahasiswa" << endl;
        cout << "5.  Ubah Profile Jurusan" << endl;
        cout << " -- VIEW -- " << endl;
        cout << "6.  Lihat Mahasiswa yang telah terdaftar" << endl;
        cout << "7.  Lihat Jurusan" << endl;
        cout << "8.  Lihat Jurusan yang dipilih Mahasiswa Baru" << endl;
        cout << " -- DELETE -- " << endl;
        cout << "9.  Hapus Data Mahasiswa" << endl;
        cout << "10. Hapus Profile Jurusan" << endl;
        cout << "11. Hapus Pilihan Jurusan Mahasiswa" << endl;
        cout << " -- SEARCHING -- " << endl;
        cout << "12. Cari Data Mahasiswa" << endl;
        cout << "13. Cari Profile Jurusan" << endl;
        cout<<endl;
        cout << "0.  Exit " << endl;
        cout<<endl;
        cout << "Masukkan Pilihan : ";
        cin >> pil;
            switch(pil){
        case 1:
            system("CLS");
            cout << "==================================================" << endl;
            cout << "\tPendaftaran Mahasiswa Baru" << endl;
            cout << "==================================================" << endl;
            PM=input_maba();
            insertLast_maba(LM,PM);
            cout<<endl;
            cout<<"Mahasiswa Baru Berhasil terdaftar"<<endl;
            cout<<endl;
            system("pause");
            break;
        case 2:
            system("CLS");
            cout << "==================================================" << endl;
            cout << "\t\tTambah Jurusan Baru" << endl;
            cout << "==================================================" << endl;
            PJ=input_jurusan();
            insertLast_jurusan(LJ,PJ);
            cout<<endl;
            cout<<"Jurusan Berhasil ditambahkan"<<endl;
            cout<<endl;
            system("pause");
            break;
        case 3:
            system("cls");
            input_relasi(LM,LJ,LR);
            cout<<endl;
            system("pause");
            break;
        case 4:
            system("Cls");
            printInfo_maba(LM);
            cout<<"Masukkan Nama Mahasiswa yang ingin diubah: ";
            cin.ignore();
            getline(cin,mdicari.nama);
            PM=findElm_maba(LM,mdicari.nama);
            if(PM!=NULL){
                cout<<"Data Mahasiswa ditemukan"<<endl;
                system("PAUSE");
                system("CLS");
                editInfo_maba(LM,PM);
                cout<<"Data Mahasiswa Berhasil diubah"<<endl;
            }
            else{
                cout<<"Data Mahasiswa tidak ditemukan"<<endl;
            }
            system("PAUSE");
            break;
        case 5:
            system("cls");
            printInfo_jurusan(LJ);
            cout<<"Masukkan Jurusan yang ingin diubah: ";
            cin.ignore();
            getline(cin,jdicari.jurusan_kul);
            PJ=findElm_jurusan(LJ,jdicari.jurusan_kul);
            if(PM!=NULL){
                cout<<"Profile Jurusan ditemukan"<<endl;
                system("cls");
                editInfo_jurusan(LJ,PJ);
                cout<<"Profile Jurusan Berhasil diubah"<<endl;
            }
            else{
                cout<<"Tidak ada data jurusan tersebut"<<endl;
            }
            system("pause");
            break;
        case 6:
            system("CLS");
            printInfo_maba(LM);
            system("PAUSE");
            break;
        case 7:
            system("CLS");
            printInfo_jurusan(LJ);
            system("PAUSE");
            break;
        case 8:
            system("cls");
            print_relasi(LR);
            system("PAUSE");
            break;
        case 9:
            system("Cls");
            printInfo_maba(LM);
            cout<<"Masukkan Nama Mahasiswa yang ingin dihapus: ";
            cin.ignore();
            getline(cin,mdicari.nama);
            PM=findElm_maba(LM,mdicari.nama);
            if(PM!=NULL){
                delete_maba(LR, LM, PM);
                cout<<endl;
                cout<<"Data Mahasiswa Berhasil dihapus"<<endl;
                cout<<endl;
            }
            else{
                cout<<endl;
                cout<<"Data Mahasiswa tidak ditemukan"<<endl;
                cout<<endl;
            }
            system("PAUSE");
            break;
        case 10:
            system("cls");
            printInfo_jurusan(LJ);
            cout<<"Masukkan Jurusan yang ingin dihapus: ";
            cin.ignore();
            getline(cin,jdicari.jurusan_kul);
            PJ=findElm_jurusan(LJ,jdicari.jurusan_kul);
            if(PJ!=NULL){
                delete_jurusan(LR,LJ, PJ);
                cout<<endl;
                cout<<"Profile Jurusan Berhasil dihapus"<<endl;
                cout<<endl;
            }
            else{
                cout<<endl;
                cout<<"Profile Jurusan tidak ditemukan"<<endl;
                cout<<endl;
            }
            system("PAUSE");
            break;
        case 11:
            system("cls");
            print_relasi(LR);
            cout<<"Masukkan Nama Mahasiswa yang ingin dihapus: ";
            cin.ignore();
            getline(cin,mdicari.nama);
            cout<<"Masukkan Jurusan yang ingin dihapus: ";
            getline(cin,jdicari.jurusan_kul);
            PR = find_relasi(LR, mdicari.nama, jdicari.jurusan_kul);
            if(PR != NULL){
                delete_relasi(LR, PR);
                cout<<"Data berhasil dihapus"<<endl;
            }
            else{
                cout<<"Data tidak ditemukan"<<endl;
            }
            system("pause");
            break;
        case 12:
            system("cls");
            printInfo_maba(LM);
            cout<<"Masukkan Nama Mahasiswa yang dicari: ";
            cin.ignore();
            getline(cin,mdicari.nama);
            PM=findElm_maba(LM, mdicari.nama);
            if(PM!=NULL){
                cout<<endl;
                search_maba(LM, LR, PM);
                cout<<endl;
            }
            else{
                cout<<"\nMahasiswa Baru tidak ditemukan\n"<<endl;
            }
            system("pause");
            break;
        case 13:
            system("cls");
            printInfo_jurusan(LJ);
            cout<<"Masukkan Jurusan yang dicari: ";
            cin.ignore();
            getline(cin,jdicari.jurusan_kul);
            PJ=findElm_jurusan(LJ, jdicari.jurusan_kul);
            if(PM!=NULL){
                cout<<endl;
                cout<<"Mahasiswa Yang Memilih Jurusan "<<jdicari.jurusan_kul<<" : "<<endl;
                search_jurusan(LJ, LR, PJ);
                cout<<endl;
            }
            else{
                cout<<"\nJurusan tidak ditemukan\n"<<endl;
            }
            system("pause");
            break;
        case 0:
            cout<<"\nTerima Kasih Telah Menggunakan Aplikasi Penerimaan Mahasiswa Baru\n"<<endl;
            system("PAUSE");
            break;
        default:
            cout<<endl;
            cout << "Angka yang anda masukkan salah, silakan masukkan angka dari 0 - 13" << endl;
            cout<<endl;
            system("PAUSE");
            break;
        }
    }while (pil!=0);
}

void search_maba(List_maba LM, List_relasi LR, address_maba PM){
    address_relasi PR=first_relasi(LR);
    int i=0;
    while (next_relasi(PR) != first_relasi(LR)){
        if(info_maba(PM).nama == info_maba(kemaba(PR)).nama){
            i++;
            cout<<"Pilihan ke-"<<i<<" : "<<info_jurusan(kejurusan(PR)).jurusan_kul<<endl;
        }
        PR = next_relasi(PR);
    }
    if(info_maba(PM).nama == info_maba(kemaba(PR)).nama){
            i++;
            cout<<"Pilihan ke-"<<i<<" : "<<info_jurusan(kejurusan(PR)).jurusan_kul<<endl;
        }
    if(i==0){
        cout<<"Mahasiswa Ini Belum Memilih Jurusan"<<endl;
    }
}

void search_jurusan(List_jurusan LJ, List_relasi LR, address_jurusan PJ){
    address_relasi PR=first_relasi(LR);
    int i=0;
    while (next_relasi(PR) != first_relasi(LR)){
        if(info_jurusan(PJ).jurusan_kul == info_jurusan(kejurusan(PR)).jurusan_kul){
            i++;
            cout<<i<<". "<<info_maba(kemaba(PR)).nama<<endl;
        }
        PR = next_relasi(PR);
    }
    if(info_jurusan(PJ).jurusan_kul == info_jurusan(kejurusan(PR)).jurusan_kul){
            i++;
            cout<<i<<". "<<info_maba(kemaba(PR)).nama<<endl;
    }
    if(i==0){
        cout<<"Belum Ada Mahasiswa yang Memilih Jurusan Ini"<<endl;
    }
}

void data_relasi (List_relasi &L, List_maba LM, List_jurusan LJ){
    address_relasi P;

    address_maba PM;
    address_jurusan PJ;

    PM=findElm_maba(LM, "ANDREA HIRATA");
    PJ=findElm_jurusan(LJ, "S1 MANAJEMEN BISNIS");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "JOKO WIDODO");
    PJ=findElm_jurusan(LJ, "S1 TEKNIK INFORMATIKA");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "RADITYA DIKA");
    PJ=findElm_jurusan(LJ, "S1 ILMU KOMUNIKASI");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "TERE LIYE");
    PJ=findElm_jurusan(LJ, "S1 ILMU KOMUNIKASI");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "PIDI BAIQ");
    PJ=findElm_jurusan(LJ, "S1 TEKNIK ELEKTRO");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "OKI SETIANA");
    PJ=findElm_jurusan(LJ, "S1 SISTEM INFORMASI");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "RADITYA DIKA");
    PJ=findElm_jurusan(LJ, "S1 DESAIN PRODUK");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "JOKO WIDODO");
    PJ=findElm_jurusan(LJ, "S1 TEK TELEKOMUNIKASI");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "ASMA NADIA");
    PJ=findElm_jurusan(LJ, "S1 SISTEM INFORMASI");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "JOKO WIDODO");
    PJ=findElm_jurusan(LJ, "S1 TEKNIK INDUSTRI");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "NADIM MAKARIM");
    PJ=findElm_jurusan(LJ, "S1 MANAJEMEN BISNIS");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);

    PM=findElm_maba(LM, "TERE LIYE");
    PJ=findElm_jurusan(LJ, "S1 TEKNIK INFORMATIKA");
    P=alokasi_relasi(PM,PJ);
    insertLast_relasi(L,P);
}
