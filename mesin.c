/*
    @Author             : Sekar Madu Kusumawardani
    @Email              : sekarmadu99@gmail.com / sekarmadu@upi.edu
    @Version            : V1.0
    @Created at         : 28 ‎May ‎2021, ‏‎16:39
    @Last Modified by   : Sekar Madu Kusumawardani
    @Last Modified at   : ‎04 ‎June ‎2021, ‏‎11:03
*/

#include "header.h"

/*-- Menampilkan Informasi DBMS --*/
void help(char pita[])
{
    if (EOP(pita) == 0)
    {
        incWord(pita);
        if (strcmp(getCWord(), "tables") == 0) //------------------> daftar tabel
        {
            printf("+------------------------+\n");
            printf("|      Daftar Tabel      |\n");
            printf("+------------------------+\n");
            printf("| transaksi              |\n");
            printf("| penonton               |\n");
            printf("| list_film              |\n");
            printf("+------------------------+\n");
        }
        else if (strcmp(getCWord(), "list_film") == 0) //----------> describe tabel list_film
        {
            printf("+------------------------+\n");
            printf("|       list_film        |\n");
            printf("+------------------------+\n");
            printf("| id(50) PK              |\n");
            printf("| judul_film(50)         |\n");
            printf("| sutradara(50)          |\n");
            printf("| harga(50)              |\n");
            printf("+------------------------+\n");
        }
        else if (strcmp(getCWord(), "penonton") == 0) //-----------> describe tabel penonton
        {
            printf("+------------------------+\n");
            printf("|        penonton        |\n");
            printf("+------------------------+\n");
            printf("| id(50) PK              |\n");
            printf("| nama(50)               |\n");
            printf("| id_film(50) FK         |\n");
            printf("| jumlah_tiket(50)       |\n");
            printf("+------------------------+\n");
        }
        else if (strcmp(getCWord(), "transaksi") == 0) //----------> describe tabel transaksi
        {
            printf("+------------------------+\n");
            printf("|       transaksi        |\n");
            printf("+------------------------+\n");
            printf("| id(50) PK              |\n");
            printf("| id_penonton(50) FK     |\n");
            printf("| total_harga(50)        |\n");
            printf("| keterangan(50)         |\n");
            printf("+------------------------+\n");
        }
        else if (strcmp(getCWord(), "queries") == 0) //------------> daftar query yang tersedia
        {
            printf("+------------------------------------+\n");
            printf("|            Daftar Query            |\n");
            printf("+------------------------------------+\n");
            printf("| > SHOW tables                      |\n");
            printf("| > SHOW queries                     |\n");
            printf("| > DESC table_name                  |\n");
            printf("| > INSERT table_name values         |\n");
            printf("| > UPDATE table_name values         |\n");
            printf("| > INSERT UPDATE table_name values  |\n");
            printf("| > DELETE table_name PK             |\n");
            printf("| > SELECT table_name                |\n");
            printf("| > SELECT JOIN tables_name (3)      |\n");
            printf("| > jangan lupa bahagia hari ini     |\n");
            printf("| > EXIT                             |\n");
            printf("+------------------------------------+\n");
        }
        else //----------------------------------------------------> kondisi salah
        {
            printf("[GAGAL] Query salah.\n");
        }
    }
}

/*-- Membaca Kata Pertama dari Pita (Query) --*/
void startWord(char pita[])
{
    idx = 0; //---------------------------> pembacaan dimulai dari karakter index ke-0
    wordLen = 0; //-----------------------> inisialisasi panjang kata awal (juga sbg penanda index cKata)
    while (pita[idx] == ' ') //-----------> selama bertemu karakter spasi
        idx++; //-------------------------> increment index sampai mencapai karakter bukan spasi
    while ((pita[idx] != ' ') && (EOP(pita) == 0))
    { //----------------------------------> selama bukan karakter spasi dan bukan akhir kalimat
        currWord[wordLen] = pita[idx]; //-> pindahkan karakter ke penampung kata
        idx++; //-------------------------> increment karakter kalimat
        wordLen++; //---------------------> increment index penampung kata
    }
    currWord[wordLen] = '\0'; //----------> akhiri kata
}

/*-- Memajukan Pembacaan Kata --*/
void incWord(char pita[])
{
    wordLen = 0; //------------------------> mulai dari index ke-0 penampung kata
    while (pita[idx] == ' ') //------------> selama bertemu karakter spasi
        idx++; //--------------------------> increment sampai bertemu karakter bukan spasi
    while ((pita[idx] != ' ') && (EOP(pita) == 0))
    { //-----------------------------------> selama bukan karakter spasi dan bukan akhir kalimat
        currWord[wordLen] = pita[idx]; //--> pindahkan karakter ke penampung kata
        idx++; //--------------------------> increment karakter kalimat
        wordLen++; //----------------------> increment index penampung kata
    }
    currWord[wordLen] = '\0'; //-----------> akhiri kata
}

/*-- Mengambil Kata yang Sedang Dibaca --*/
char *getCWord()
{
    return currWord; //-> kembalikan nilai variabel penampung kata saat ini
}

/*-- Membersihkan Kata yang Sedang Dibaca --*/
void resetWord()
{
    wordLen = 0; //--------------> index ke-0 penampung kata
    currWord[wordLen] = '\0'; //-> dibuat tanpa karakter atau diakhiri
}

/*-- Mengambil Panjang Kata yang Sedang Dibaca --*/
int getWordLen()
{
    return wordLen; // ambil panjang penampung kata saat ini
}

/*-- Lampu Penanda Akhir Pita (Query) --*/
int EOP(char pita[])
{
    if (pita[idx] == ';') //-> jika bertemu titik koma
        return 1; //---------> kembalikan 1 (penanda akhir kalimat)
    return 0; //-------------> jika tidak masuk ke if, kembalikan 0 (bukan akhir kalimat)
}

/*-- Menukar 2 Record Data --*/
void swap(myTable *awal, myTable *akhir)
{
    // digunakan dalam prosedur sorting
    myTable temp;   //------> penampung sementara
    temp = *awal;   //------> data awal ditampung
    *awal = *akhir; //------> data akhir dipindah ke data awal
    *akhir = temp;  //------> data tampungan dipindah ke data akhir
}

/*-- Mengurutkan Record Berdasarkan Id (Ascending) --*/
void quickSort(myTable table[], int left, int right)
{
    int i = left, j = right;
    //--^---------^inisalisasi nilai penanda i dan j dengan data paling kiri dan paling kanan
    char pivot[50];
    strcpy(pivot, table[(right + left) / 2].id);
    //-----^inisialisasi nilai pivot dengan data tengah
    do
    {
        while ((strcmp(table[i].id, pivot) < 0) && (i <= j))
            i++;
        //--^penanda i maju selama data ke-i kurang dari pivot dan nilai i kurang dari j
        while ((strcmp(table[j].id, pivot) > 0) && (i <= j))
            j--;
        //--^penanda j mundur selama data ke-j lebih dari pivot dan nilai i kurang dari j
        if (i < j)
        {
            swap(&table[i], &table[j]); //-> jika penanda i dan j sudah berhenti, tukar kedua data
            i++; j--; //-------------------> penanda maju/mundur lagi
        }
    } while (i < j);
    // membagi dua data yang diurutkan
    if ((left < j) && (j < right))
        quickSort(table, left, j); //------> bagian kiri
    if ((i < right) && (i > left))
        quickSort(table, i, right); //-----> bagian kanan
}

/*-- Mengidentifikasi Query Kata Pertama --*/
int query(char pita[])
{
    char check[][20] = {"jangan", "lupa", "bahagia", "hari", "ini"}; //-> query khusus untuk exit
    if (EOP(pita) == 0) //----------------------------------------------> jika kata pertama bukan ;
    {
        if ((strcmp(getCWord(), "SHOW") == 0) || (strcmp(getCWord(), "DESC") == 0))
            return 1; //------------------------------------------------> jika kata pertama DESC/SHOW kembalikan 1
        if ((strcmp(getCWord(), "INSERT") == 0) || (strcmp(getCWord(), "UPDATE") == 0))
            return 2; //------------------------------------------------> jika kata pertama INSERT/UPDATE kembalikan 2
        if (strcmp(getCWord(), "DELETE") == 0)
            return 3; //------------------------------------------------> jika kata pertama DELETE kembalikan 3
        if (strcmp(getCWord(), "SELECT") == 0)
            return 4; //------------------------------------------------> jika kata pertama SELECT kembalikan 4
        if (strcmp(getCWord(), check[0]) == 0)
            return bahagia(pita, check); //-----------------------------> jika kata pertama query khusus untuk exit
        return 0;
    }
    if (strcmp(getCWord(), "EXIT") == 0)
        return 5; //----------------------------------------------------> jika kata pertama EXIT kembalikan 5
    return -1; //-------------------------------------------------------> selain yang diatas, kembalikan -1
}

/*-- Mengecek Kelengkapan Query Khusus untuk Exit --*/
int bahagia(char pita[], char check[][20])
{
    int passed = 0, i = 1;
    while (EOP(pita) == 0)
    {
        incWord(pita);
        if (strcmp(getCWord(), check[i]) == 0) //-> jika kata yang dibaca = kata query khusus
            passed++; //--------------------------> increment penanda kondisi terpenuhi
        i++;
    }
    return (passed == 4) ? 5 : -1; //-------------> kembalikan nilai penanda
}

/*-- Mencari Data Foreign Key --*/
int binSearch(myTable table[], char search[], int left, int right)
{
    if (right >= left) //---------------------------------------> jika batas data terakhir >= batas data pertama
    {
        int mid = (right - left) / 2 + left; //-----------------> cari tengah-tengahnya, simpan di var mid
        if (strcmp(table[mid].id, search) == 0) //--------------> jika index tengah sama dengan index yg dicari
            return mid; //--------------------------------------> return data struct index yg dicari (karena sudah ketemu)
        else if (strcmp(table[mid].id, search) > 0) //----------> jika index tengah > index yg dicari
            return binSearch(table, search, left, mid - 1); //--> bagi dua array, fokus mencari di array bagian kiri
        else if (strcmp(table[mid].id, search) < 0) //----------> jika index tengah < index yg dicari
            return binSearch(table, search, mid + 1, right); //-> bagi dua array, fokus mencari di array bagian kanan
    }
    return -1; //-----------------------------------------------> jika data tidak ditemukan, kembalikan nilai -1
}

/*-- Membaca Data dari Sequential File --*/
int readTable(FILE *fileTbl, myTable table[], char tblName[])
{
    fileTbl = fopen(tblName, "r"); //---------------> buka file mode read
    int i = 0;
    //----------------------------------------------> baca data file baris pertama
    fscanf(fileTbl, "%s %s %s %s", table[i].id, table[i].field1, table[i].field2, table[i].field3);
    while (strcmp(table[i].id, "####") != 0) //-----> selama tidak menemukan EOF
    {
        i++;
        //------------------------------------------> baca data file sampai bertemu EOF
        fscanf(fileTbl, "%s %s %s %s", table[i].id, table[i].field1, table[i].field2, table[i].field3);
    }
    //----------------------------------------------> data file yang dibaca dipindahkan ke struct
    fclose(fileTbl); //-----------------------------> tutup file
    return i; //------------------------------------> kembalikan jumlah data yang berhasil dibaca
}

/*-- Menulis Data ke Sequential File --*/
void writeTable(FILE *fileTbl, myTable table[], int n, char tblName[])
{
    fileTbl = fopen(tblName, "w"); //----------------> buka file mode write
    for (int i = 0; i < n; i++)
        fprintf(fileTbl, "%s %s %s %s\n", table[i].id, table[i].field1, table[i].field2, table[i].field3);
    //-----------------------------------------------> masukkan data dari struct ke dalam file satu per satu
    fprintf(fileTbl, "#### #### #### ####\n"); //----> masukkan data EOF
    fclose(fileTbl); //------------------------------> tutup file
}

/*-- Mengatur Request Query --*/
void request(char pita[], myTable tFilm[], myTable tPenonton[], myTable tTransaksi[], int *f, int *p, FILE *Film, FILE *Penonton, FILE *Transaksi)
{
    char firstQuery[20];
    strcpy(firstQuery, getCWord()); //----------------------------> menampung kata query pertama
    int incorrectInsert = 0, insertUpdate = 0;
    //--------------------------^penanda jika query "hanya" INSERT
    //--^penanda jumlah value masukan melebihi jumlah kolom
    *f = readTable(Film, tFilm, "list_film.dat"); //--------------> baca file list_film.dat, simpan jumlah record
    *p = readTable(Penonton, tPenonton, "penonton.dat"); //-------> baca file penonton.dat, simpan jumlah record
    int t = readTable(Transaksi, tTransaksi, "transaksi.dat"); //-> baca file transaksi.dat, simpan jumlah record
    int tmp1 = *f, tmp2 = *p; //----------------------------------> pindahkan jumlah record ke variabel sementara
    quickSort(tFilm, 0, tmp1 - 1); //-----------------------------> urutkan data record list_film pada struct tFilm
    quickSort(tPenonton, 0, tmp2 - 1); //-------------------------> urutkan data record penonton pada struct tPenonton
    myTable temp; //----------------------------------------------> menyimpan data record baris terakhir
    if (EOP(pita) == 0)
    {
        incWord(pita); //------------------------------------------------> baca kata selanjutnya
        if ((strcmp(firstQuery, "INSERT") == 0) && (strcmp(getCWord(), "UPDATE") != 0))
            insertUpdate = 1; //-----------------------------------------> jika query ke-1 hanya INSERT
        if ((strcmp(firstQuery, "UPDATE") == 0) && (strcmp(getCWord(), "UPDATE") != 0))
            insertUpdate = 2; //-----------------------------------------> jika query ke-1 hanya UPDATE
        if (strcmp(getCWord(), "UPDATE") == 0)
            incWord(pita); //--------------------------------------------> jika query ke-2 UPDATE
        if (strcmp(getCWord(), "JOIN") == 0) //--------------------------> jika query ke-2 JOIN
        {
            int tables = 0; //-------------------------------------------> penanda jumlah tabel yang di join
            char table[3][50]; //----------------------------------------> penampung nama tabel
            if (EOP(pita) == 0)
            {
                incWord(pita);
                strcpy(table[0], getCWord()); //-------------------------> nama tabel pertama
                tables++;
                if (EOP(pita) == 0)
                {
                    incWord(pita);
                    strcpy(table[1], getCWord()); //---------------------> nama tabel kedua
                    tables++;
                    if (EOP(pita) == 0)
                    {
                        incWord(pita);
                        strcpy(table[2], getCWord()); //-----------------> nama tabel ketiga
                        tables++;
                        // kombinasi dari tabel 1 2 3 menghasilkan 6 kemungkinan di bawah
                        if (
                            (strcmp(table[0], "transaksi") == 0 && strcmp(table[1], "penonton") == 0 && strcmp(table[2], "list_film") == 0) ||
                            (strcmp(table[0], "transaksi") == 0 && strcmp(table[2], "penonton") == 0 && strcmp(table[1], "list_film") == 0) ||
                            (strcmp(table[1], "transaksi") == 0 && strcmp(table[0], "penonton") == 0 && strcmp(table[2], "list_film") == 0) ||
                            (strcmp(table[1], "transaksi") == 0 && strcmp(table[2], "penonton") == 0 && strcmp(table[0], "list_film") == 0) ||
                            (strcmp(table[2], "transaksi") == 0 && strcmp(table[1], "penonton") == 0 && strcmp(table[0], "list_film") == 0) ||
                            (strcmp(table[2], "transaksi") == 0 && strcmp(table[0], "penonton") == 0 && strcmp(table[1], "list_film") == 0))
                        {
                            // jika salah satu kemungkinan terpenuhi
                            char colName1[][20] = {"id_trans", "nama_penonton", "judul_film", "sutradara"}; // judul header bag-1
                            char colName2[][20] = {"harga_film", "jml_tiket", "total_bayar", "ket."}; // judul header bag-2
                            int w1[4] = {toArray(tTransaksi, t, 0), toArray(tPenonton, tmp2, 1), toArray(tFilm, tmp1, 1), toArray(tFilm, tmp1, 2)}; // isi record bagian 1 (4 kolom pertama)
                            int w2[4] = {toArray(tFilm, tmp1, 3), toArray(tPenonton, tmp2, 3), toArray(tTransaksi, t, 2), toArray(tTransaksi, t, 3)}; // isi record bagian 2 (4 kolom berikutnya)
                            for (int j = 0; j < 4; j++)
                            { // mencari string terpanjang dalam satu kolom untuk menentukan lebar kolom
                                if (strlen(colName1[j]) > w1[j])
                                    w1[j] = strlen(colName1[j]);
                                if (strlen(colName2[j]) > w2[j])
                                    w2[j] = strlen(colName2[j]);
                            }
                            // memanggil prosedur join table
                            joinProcess(colName1, colName2, w1, w2, tTransaksi, tPenonton, tFilm, t, tmp2, tmp1, 2);
                        }
                    }
                }
            }
            if (tables < 3)
            {
                printf("[GAGAL] Jumlah table yang dimasukkan tidak sesuai.\n");
            }
        }
        else if (strcmp(getCWord(), "list_film") == 0) //----------------> jika query ke-2 list_film
        {
            if ((strcmp(firstQuery, "INSERT") == 0) || (strcmp(firstQuery, "UPDATE") == 0)) //-> insert record
                temp = insertProcess(pita, tFilm, tFilm, tmp1, &tmp1, &incorrectInsert, insertUpdate, "list_film");
            else if (strcmp(firstQuery, "DELETE") == 0) //-------------------------------------> delete record
                deleteProcess(pita, tFilm, &tmp1);
            else if (strcmp(firstQuery, "SELECT") == 0) //-------------------------------------> menampilkan tabel
            {
                quickSort(tFilm, 0, tmp1 - 1); //----------------------------------------------> mengurutkan record
                char colName[][20] = {"id", "nama_film", "sutradara", "harga"}; //-------------> judul header
                int width[4];
                for (int j = 0; j < 4; j++)
                { // mencari string terpanjang pada setiap kolom untuk menentukan lebar kolom
                    width[j] = toArray(tFilm, tmp1, j); //-----------> mengubah data struct ke array, simpan nilai string terpanjang
                    if (strlen(colName[j]) > width[j]) //------------> jika judul headernya lebih panjang
                        width[j] = strlen(colName[j]);
                }
                selectProcess(colName, tFilm, tmp1, width, 1, 1); //-> prosedur menampilkan tabel
            }
            quickSort(tFilm, 0, tmp1 - 1); //----------------------------------------------> mengurutkan record
            writeTable(Film, tFilm, tmp1, "list_film.dat"); //-------> masukkan data tabel ke sequential file nya
        }
        else if (strcmp(getCWord(), "penonton") == 0) //-----------------> jika query ke-2 penonton
        {
            if ((strcmp(firstQuery, "INSERT") == 0) || (strcmp(firstQuery, "UPDATE") == 0))
            { //---------------------------------------------------------> INSERT / UPDATE record
                temp = insertProcess(pita, tPenonton, tFilm, tmp1, &tmp2, &incorrectInsert, insertUpdate, "penonton");
                // nilai record sebelumnya disimpan dalam struct temp untuk menangani kesalahan query
                if ((incorrectInsert == 0)) // jika value benar dan record penonton bertambah/berubah
                    triggerTrans(pita, tTransaksi, &t, tmp2, tFilm, tPenonton, tmp1, temp);
                    // trigger diaktifkan untuk menambah record ke tabel transaksi
                    // kondisi query error ditangani dalam prosedur trigger
            }
            else if (strcmp(firstQuery, "DELETE") == 0) //---------------> delete record
                deleteProcess(pita, tPenonton, &tmp2);
            else if (strcmp(firstQuery, "SELECT") == 0) //---------------> menampilkan tabel penonton
            {
                quickSort(tPenonton, 0, tmp2 - 1); //--------------------> mengurutkan record tabel penonton
                char colName[][20] = {"id", "nama", "id_film", "jumlah_tiket"}; // judul header
                int width[4];
                for (int j = 0; j < 4; j++)
                { // mencari string terpanjang pada setiap kolom untuk menentukan lebar kolom
                    width[j] = toArray(tPenonton, tmp2, j); //-----------> mengubah data struct ke array, simpan nilai string terpanjang
                    if (strlen(colName[j]) > width[j]) //----------------> jika judul header lebih panjang
                        width[j] = strlen(colName[j]);
                }
                selectProcess(colName, tPenonton, tmp2, width, 1, 1); //-> prosedur menampilkan tabel
            }
            quickSort(tPenonton, 0, tmp2 - 1); //--------------------> mengurutkan record tabel penonton
            writeTable(Penonton, tPenonton, tmp2, "penonton.dat"); //----> menuliskan record ke dalam file
            writeTable(Transaksi, tTransaksi, t, "transaksi.dat"); //---->              ''
        }
        else if (strcmp(getCWord(), "transaksi") == 0) //----------------> jika query ke-2 transaksi
        {
            // record pada log transaksi tidak dapat ditambah/diupdate/dihapus secara langsung (dgn primary key)
            // record akan bertambah/berubah secara otomatis jika terjadi perubahan pada tabel penonton
            // record tidak dapat dihapus meskipun ada record penonton yang dihapus
            if (strcmp(firstQuery, "INSERT") == 0 || strcmp(firstQuery, "UPDATE") == 0)
                printf("[GAGAL] Tidak dapat menginput/mengupdate record secara langsung.\n");
            else if (strcmp(firstQuery, "DELETE") == 0)
                printf("[GAGAL] Tidak dapat menghapus data log transaksi.\n");
            else if (strcmp(firstQuery, "SELECT") == 0) //---------------> menampilkan tabel transaksi
            {
                char colName[][20] = {"id", "id_penonton", "total_bayar", "keterangan"}; // judul header
                int width[4];
                for (int j = 0; j < 4; j++)
                { // mencari string terpanjang pada setiap kolom untuk menentukan lebar kolom
                    width[j] = toArray(tTransaksi, t, j); //-----------> mengubah data struct ke array, simpan nilai string terpanjang
                    if (strlen(colName[j]) > width[j]) //--------------> jika judul header lebih panjang
                        width[j] = strlen(colName[j]);
                }
                selectProcess(colName, tTransaksi, t, width, 1, 1); //-> prosedur menampilkan tabel
            }
            writeTable(Transaksi, tTransaksi, t, "transaksi.dat"); //--> menuliskan record ke sequential file
        }
        else
            printf("[GAGAL] Tabel salah atau tidak tersedia.\n"); //------> jika query ke-2 tidak terdefinisi
    }
    *f = tmp1; *p = tmp2; //---------------------------------------------> update jumlah record terbaru
}

/*-- Proses Menambahkan Record --*/
myTable insertProcess(char pita[], myTable tbl[], myTable tbl2[], int tbl2N, int *idx, int *incorrectInsert, int insertUpdate, char tblName[])
{
    myTable temp; //------------------------------------------> menyimpan data record sebelumnya
    int count = 0, found = -1, foundFKey = -1, overChar = 0;
    //-----------------------------------------^penanda apakah masukan karakter melebihi batas
    //-------------------------^penanda index foreign key ditemukan/tidak
    //-------------^penanda primary key ditemukan (update) atau tidak (insert)
    //--^menghitung value yang dimasukkan
    char currWordUpdate[20]; //-------------------------------> menyimpan primary key (update) untuk trigger transaksi
    while (EOP(pita) == 0) //---------------------------------> selama bukan akhir pita
    {
        incWord(pita);
        if (count == 0)
        {
            found = binSearch(tbl, getCWord(), 0, *idx); //---> mencari primary key (id)
            temp = tbl[found]; //-----------------------------> simpan record yg ditemukan (antisipasi query gagal)
        }
        // insert data baru
        if (found == -1 && (insertUpdate == 0 || insertUpdate == 1)) //jika primary key tidak ditemukan & bukan update
        {
            if (count == 0) //--------------------------------> kolom 1
            {
                temp = tbl[*idx - 1]; //----------------------> simpan record sebelumnya (antisipasi query gagal)
                overChar = (getWordLen() > 49) ? overChar + 1 : overChar; // apakah masukan melebihi batas char
                strcpy(tbl[*idx].id, getCWord()); //----------> masukkan kata saat ini sebagai primary key
            }
            else if (count == 1) //---------------------------> kolom 2
            {
                overChar = (getWordLen() > 49) ? overChar + 1 : overChar; // apakah masukan melebihi batas char
                strcpy(tbl[*idx].field1, getCWord()); //------> masukkan kata saat ini sebagai data kolom 2
            }
            else if (count == 2) //---------------------------> kolom 3
            {
                if (strcmp(tblName, "penonton") == 0) //------> jika insert data ke tabel penonton
                    foundFKey = binSearch(tbl2, getCWord(), 0, tbl2N);
                    //----------------------------------------> cek apakah fk (id_film) tersedia di tabel list_film
                else //---------------------------------------> jika insert data bukan ke tabel penonton
                    foundFKey = 0; //-------------------------> inisialisasi dengan 0
                overChar = (getWordLen() > 49) ? overChar + 1 : overChar; // apakah masukan melebihi batas char
                strcpy(tbl[*idx].field2, getCWord()); //------> masukkan kata saat ini sebagai data kolom 3
            }
            else if (count == 3) //---------------------------> kolom 4
            {
                overChar = (getWordLen() > 49) ? overChar + 1 : overChar; // apakah masukan melebihi batas char
                strcpy(tbl[*idx].field3, getCWord()); //------> masukkan kata saat ini sebagai data kolom 4
            }
        }
        // update data lama
        else if (found > -1 && (insertUpdate == 0 || insertUpdate == 2)) //> jika primary key ditemukan & bukan insert
        { // NOTE : alur sama dengan insert data baru, hanya berbeda pada index tabel yang menyimpan kata saat ini
          //        insert data -> index meneruskan dari sebelumnya | update data -> index data yang ingin diubah
            if (count == 0)
            {
                overChar = (getWordLen() > 49) ? overChar + 1 : overChar;
                strcpy(tbl[found].id, getCWord());
                strcpy(currWordUpdate, getCWord());
            }
            else if (count == 1)
            {
                overChar = (getWordLen() > 49) ? overChar + 1 : overChar;
                strcpy(tbl[found].field1, getCWord());
            }
            else if (count == 2)
            {
                overChar = (getWordLen() > 49) ? overChar + 1 : overChar;
                if (strcmp(tblName, "penonton") == 0)
                    foundFKey = binSearch(tbl2, getCWord(), 0, tbl2N);
                else
                    foundFKey = 0;
                strcpy(tbl[found].field2, getCWord());
            }
            else if (count == 3)
            {
                overChar = (getWordLen() > 49) ? overChar + 1 : overChar;
                strcpy(tbl[found].field3, getCWord());
            }
        }
        count++; //-------------------------------------------> menambah penanda kolom
    }
    if (overChar > 0) //--------------------------------------> jika karakter melebihi batas
    {
        printf("[GAGAL] Terdapat data yang melebihi batas karakter.\n");
        *incorrectInsert = 1;
    }
    if (count > 4) //-----------------------------------------> jika value yang dimasukkan > jumlah kolom pada tabel
    {
        printf("[GAGAL] Data yang dimasukkan melebihi jumlah kolom.\n");
        *incorrectInsert = 1; //---------------------------> penanda kesalahan jumlah value
    }
    if ((insertUpdate == 0 || insertUpdate == 2) || (insertUpdate == 1 && found < 0)) //---> jika (insert update) / (insert saja & id tidak ditemukan)
    {
        if ((insertUpdate == 2) && found < 0) //--------> jika update dan primary key tidak ditemukan
        {
            printf("[GAGAL] Data tidak ditemukan.\n");
            *incorrectInsert = 1;
        }
        if (foundFKey == -1) //-------------------------------> jika foreign key (di tabel penonton) tidak ditemukan
        {
            if (insertUpdate == 0 || insertUpdate == 1){
                printf("[GAGAL] Foreign Key tidak ditemukan.\n");
                *incorrectInsert = 1;
            }
            if (found > -1) //--------------------------------> jika posisi sedang mengupdate data
                tbl[found] = temp; //-------------------------> record yg di update = record sebelum di update
        }
        if (count < 4) //-------------------------------------> jika value yang dimasukkan < jumlah kolom pada tabel
        {
            if (found > -1) //--------------------------------> jika posisi sedang mengupdate data
                tbl[found] = temp; //-------------------------> record yg di update = record sebelum di update
            printf("[GAGAL] Data yang dimasukkan kurang dari jumlah kolom.\n");
            *incorrectInsert = 1; //-----------------------> penanda kesalahan jumlah value
        }
        if (found < 0 && count == 4 && foundFKey != -1 && overChar == 0 && insertUpdate != 2) // jika bukan update & jumlah value benar
        { //--------------------------------------------------> & foreign key ada & tidak melebihi batas karakter
            ++*idx; //----------------------------------------> tambah index penanda jumlah record
            printf("[SUKSES] Berhasil menambahkan 1 record data!\n");
            *incorrectInsert = 0;
        }
        else if (found >= 0 && count == 4 && foundFKey != -1 && overChar == 0) // jika update & jumlah value benar
        { //--------------------------------------------------> & foreign key ada & tidak melebihi batas karakter
            strcpy(getCWord(), currWordUpdate); //------------> kata saat ini = primary key (id) record yg di update
            printf("[SUKSES] Berhasil mengupdate data!\n");
            *incorrectInsert = 0;
        }
    }
    else if (insertUpdate == 1 && found >= 0) //------------------> jika hanya insert dan primary key (id) sudah ada
    { //------------------------------------------------------> gagal karena PK harus unique
        printf("[GAGAL] Primary Key yang dimasukkan sudah ada.\n");
        *incorrectInsert = 1;
    }
    return temp; //-------------------------------------------> kembalikan record sebelumnya
}

/*-- Trigger Tabel Transaksi --*/
void triggerTrans(char pita[], myTable tTransaksi[], int *t, int p, myTable tFilm[], myTable tPenonton[], int f, myTable prevRecord)
{
    int found = -1; //--------------------------------------------------> penanda index yang dicari (untuk update)
    found = binSearch(tPenonton, getCWord(), 0, p); //------------------> cek apakah tabel penonton di INSERT / UPDATE
    if (found == -1) //-------------------------------------------------> jika di tabel penonton INSERT data baru
    {
        int foundFK = -1;
        foundFK = binSearch(tFilm, tPenonton[p - 1].field2, 0, f); //---> cek apakah id_film nya ada di tabel list_film
        if (foundFK == -1) //-------------------------------------------> jika tidak ada, trigger dibatalkan
            tPenonton[p - 1] = prevRecord; //---------------------------> record dikembalikan ke semula
        else //---------------------------------------------------------> jika foreign key ada
        {
            char id[4];
            sprintf(id, "%d", *t + 1); //-------------------------------> ubah index menjadi string untuk dijadikan id_trans
            strcpy(tTransaksi[*t].id, id); //---------------------------> string index dimasukkan ke kolom ke-1 tTransaksi
            strcpy(tTransaksi[*t].field1, tPenonton[p - 1].id); //------> memasukkan id penonton ke kolom ke-2 tTransaski
            int price = atoi(tFilm[foundFK].field3); //-----------------> mengubah harga film ke integer (untuk kalkulasi)
            int total = (price + pajak) * atoi(tPenonton[p - 1].field3); // total = (harga film + pajak) x jumlah tiket
            char totalStr[20];
            sprintf(totalStr, "%d", total); //--------------------------> total bayar diubah ke string
            strcpy(tTransaksi[*t].field2, totalStr); //-----------------> total bayar dimasukkan ke kolom ke-3 tTransaksi
            if (strcmp(tPenonton[p - 1].field3, "1") > 0) //------------> jika jumlah tiket penonton lebih dari satu
                strcpy(tTransaksi[*t].field3, "Group"); //--------------> keterangan (kolom ke-4) = Group
            else if (strcmp(tPenonton[p - 1].field3, "1") == 0) //------> jika jumlah tiket penonton satu
                strcpy(tTransaksi[*t].field3, "Single"); //-------------> keterangan = Single
            else
                strcpy(tTransaksi[*t].field3, "NULL"); //---------------> jika < 1, keterangan = NULL
            ++*t; //----------------------------------------------------> penanda record tTransaksi bertambah
        }
    }
    else //-------------------------------------------------------------> jika jika di tabel penonton UPDATE data lama
    {
        // NOTE. alur sama dengan trigger INSERT, hanya berbeda di indexnya dan record tidak bertambah
        int foundFK = -1;
        foundFK = binSearch(tFilm, tPenonton[p - 1].field2, 0, f);
        if (foundFK == -1)
            tPenonton[found] = prevRecord;
        else
        {
            myTable temp[*t];
            for (int i = 0; i < *t; i++)
                strcpy(temp[i].id, tTransaksi[i].field1);
            int foundT = binSearch(temp, tPenonton[found].id, 0, *t - 1);
            char id[4];
            sprintf(id, "%d", found + 1);
            strcpy(tTransaksi[found].id, id);
            strcpy(tTransaksi[foundT].field1, tPenonton[found].id);
            int price = atoi(tFilm[binSearch(tFilm, tPenonton[found].field2, 0, f)].field3);
            int total = (price + pajak) * atoi(tPenonton[found].field3);
            char totalStr[20];
            sprintf(totalStr, "%d", total);
            strcpy(tTransaksi[foundT].field2, totalStr);
            if (strcmp(tPenonton[found].field3, "1") > 0)
                strcpy(tTransaksi[foundT].field3, "Group");
            else if (strcmp(tPenonton[found].field3, "1") == 0)
                strcpy(tTransaksi[foundT].field3, "Single");
            else
                strcpy(tTransaksi[foundT].field3, "NULL");
        }
    }
}

/*-- Prosedur Menghapus Record --*/
void deleteProcess(char pita[], myTable tbl[], int *idx)
{
    int count = 0, found = -1;
    //-------------^penanda primary key yang ingin dihapus ditemukan
    //--^penanda memajukan pembacaan pita
    while (EOP(pita) == 0)
    {
        incWord(pita);
        if (count == 0) //-----------------------------------> pembacaan pita pertama (id yang ingin dihapus)
            found = binSearch(tbl, getCWord(), 0, *idx); //--> cek apakah primary key (id) ditemukan
        if (found < 0 || found > *idx) //--------------------> jika primary key (id) tidak ditemukan
            printf("[GAGAL] Record yang ingin dihapus tidak ada.\n");
        else //----------------------------------------------> jika primary key (id) ditemukan
        {
            for (int i = found; i < *idx - 1; i++) //--------> memajukan data dari index yang ingin dihapus
            { //---------------------------------------------> sampai index terakhir - 1
                strcpy(tbl[i].id, tbl[i + 1].id);
                strcpy(tbl[i].field1, tbl[i + 1].field1);
                strcpy(tbl[i].field2, tbl[i + 1].field2);
                strcpy(tbl[i].field3, tbl[i + 1].field3);
            }
            printf("[SUKSES] 1 record data berhasil dihapus!\n");
        }
        count++;
    }
    --*idx; //----------------------------------------------> jumlah record dikurangi 1
}

/*-- Prosedur Menampilkan Tabel --*/
void selectProcess(char colName[][20], myTable tbl[], int n, int w[], int order, int part)
{
    getSeparator(colName, w, order, part); //---------------> prosedur menampilkan pembatas / border record
    getTHead(colName, w, order, part); //-------------------> prosedur menampilkan header tabel
    getSeparator(colName, w, order, part);
    for (int i = 0; i < n; i++) //--------------------------> diulang sebanyak jumlah record
        printRecord(colName, tbl, w, &i, order, part); //---> prosedur menampilkan record per baris
    getSeparator(colName, w, order, part);
    printf("[SUKSES] %d record berhasil ditampilkan!\n", n);
}

/*-- Prosedur Menggabungkan 3 Tabel --*/
void joinProcess(char colName1[][20], char colName2[][20], int w1[], int w2[], myTable a[], myTable b[], myTable c[], int nA, int nB, int nC, int tableJoining)
{
    // a = transaksi, b = penonton, c = list Film
    myTable first[nA], second[nA]; //------------------------> penampung data tabel bagian 1 dan 2
    //-------------------------------------------------------> bagian 1 = 4 kolom pertama, bagian 2 = 4 kolom berikutnya
    if (tableJoining == 2)
    {
        for (int i = 0; i < nA; i++) //----------------------> proses memindahkan record sebanyak jumlah transaksi
        {
            strcpy(first[i].id, a[i].id); //-----------------> id transaksi (kolom 1)
            int f1 = binSearch(b, a[i].field1, 0, nB); //----> mencari id penonton (FK di tTransaksi) di tPenonton
            if (f1 == -1) //---------------------------------> jika tidak ditemukan = NULL
            {
                strcpy(first[i].field1, "NULL");
                strcpy(second[i].field1, "NULL");
            }
            else //------------------------------------------> jika ditemukan
            {
                strcpy(first[i].field1, b[f1].field1); //----> nama penonton (kolom 2)
                strcpy(second[i].field1, b[f1].field3); //---> jumlah pembelian tiket (kolom 6)
            }
            int f2 = binSearch(c, b[f1].field2, 0, nC); //---> mencari id film (FK di tPenonton) di tFilm
            if (f2 == -1) //---------------------------------> jika tidak ditemukan = NULL
            {
                strcpy(first[i].field2, "NULL");
                strcpy(first[i].field3, "NULL");
                strcpy(second[i].id, "NULL");
            }
            else //------------------------------------------> jika ditemukan
            {
                strcpy(first[i].field2, c[f2].field1); //----> judul film (kolom 3)
                strcpy(first[i].field3, c[f2].field2); //----> sutradara (kolom 4)
                strcpy(second[i].id, c[f2].field3); //-------> harga per film (kolom 5)
            }
            strcpy(second[i].field2, a[i].field2); //--------> total bayar (kolom 7)
            strcpy(second[i].field3, a[i].field3); //--------> keterangan (kolom 8)
        }
        getSeparator(colName1, w1, 1, 2); //-----------------> pembatas atas header tabel bagian 1
        getSeparator(colName2, w2, 2, 2); //-----------------> pembatas atas header tabel bagian 2
        getTHead(colName1, w1, 1, 2); //---------------------> header tabel bagian 1
        getTHead(colName2, w2, 2, 2); //---------------------> header tabel bagian 2
        getSeparator(colName1, w1, 1, 2); //-----------------> pembatas bawah header tabel bagian 1
        getSeparator(colName2, w2, 2, 2); //-----------------> pembatas bawah header tabel bagian 2
        for (int j = 0; j < nA; j++) //----------------------> menampilkan record per baris
        {
            printRecord(colName1, first, w1, &j, 1, 2); //---> bagian 1
            printRecord(colName2, second, w2, &j, 2, 2); //--> bagian 2
        }
        getSeparator(colName1, w1, 1, 2); //-----------------> pembatas bawah bagian 1
        getSeparator(colName2, w2, 2, 2); //-----------------> pembatas bawah bagian 2
        printf("[SUKSES] Join tabel berhasil!\n");
    }
}

/*-- Menampilkan Pembatas Per Baris --*/
void separator(int width)
{
    printf("+"); //------------------------> pembatas antar kolom
    for (int i = 0; i < 2 + width; i++) //-> print sebanyak lebar kolom
        printf("-");
}

/*-- Menampilkan Header Per Kolom --*/
void thead(char colName[], int maxWidth)
{
    for (int i = 0; i < (maxWidth - strlen(colName)) / 2; i++) //----------------------------> (lebar - panjang string)/2
        printf(" ");
    printf("%s", colName); //----------------------------------------------------------------> isi kolom (string)
    for (int i = (maxWidth - strlen(colName)) / 2; i < (maxWidth - strlen(colName)); i++) //-> lanjutan sisa spasi
        printf(" ");
    printf(" | "); //------------------------------------------------------------------------> pembatas antar kolom
}

/*-- Mencari String Terpanjang per Kolom --*/
int Max(int arr[], int n)
{
    int max = arr[0]; //------------> inisialisasi max dengan panjang string pertama
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i]) //--------> jika array ke-i > dari max
            max = arr[i];
    }
    return max; //------------------> kembalikan nilai terbesar
}

/*-- Mengubah Data Kolom Struct menjadi Array --*/
int toArray(myTable tbl[], int n, int find)
{
    // NOTE. untuk mengubah data per kolom pada struct menjadi array panjang data tersebut
    // find = 0 - 3
    int arrTbl[4][n];
    for (int i = 0; i < n; i++) //----------------> proses memindahkan panjang string per kolom ke array
    {
        arrTbl[0][i] = strlen(tbl[i].id);
        arrTbl[1][i] = strlen(tbl[i].field1);
        arrTbl[2][i] = strlen(tbl[i].field2);
        arrTbl[3][i] = strlen(tbl[i].field3);
    }
    return Max(arrTbl[find], n); //---------------> mengembalikan panjang string terpanjang yang diminta oleh find
}

/*-- Mencari Panjang Fix Kolom --*/
void header(char colName[], int width)
{
    if (strlen(colName) > width) //--> cek jika panjang judul header lebih panjang dari panjang string data terpanjang
        width = strlen(colName); //--> simpan nilai yang terpanjang
    separator(width); //-------------> prosedur menampilkan batas per kolom (kirim nilai fix lebar kolom)
}

/*-- Menampilkan Pembatas Tabel --*/
void getSeparator(char colName[][20], int w[], int order, int part)
{
    //-----------------------------> mengirim data judul header dan string data terpanjang
    //-----------------------------> untuk menampilkan lebar kolom yang sesuai
    if (w[0] > 0) //---------------> kolom 1
        header(colName[0], w[0]);
    if (w[1] > 0) //---------------> kolom 2
        header(colName[1], w[1]);
    if (w[2] > 0) //---------------> kolom 3
        header(colName[2], w[2]);
    if (w[3] > 0) //---------------> kolom 4
        header(colName[3], w[3]);
    if (order == part)
        printf("+\n"); //----------> pembatas antar kolom
}

/*-- Menampilkan Judul Header --*/
void getTHead(char colName[][20], int w[], int order, int part)
{
    if (order == 1)
        printf("| "); //------------> jika kolom paling kiri
    if (w[0] > 0) //----------------> kolom 1
        thead(colName[0], w[0]); //-> isi header
    if (w[1] > 0) //----------------> kolom 2
        thead(colName[1], w[1]);
    if (w[2] > 0) //----------------> kolom 3
        thead(colName[2], w[2]);
    if (w[3] > 0) //----------------> kolom 4
        thead(colName[3], w[3]);
    if (order == part) //-----------> jika kolom paling kanan
        printf("\n"); //------------> buat baris baru
}

/*-- Menampilkan Isi Record per Baris --*/
void printRecord(char colName[][20], myTable table[], int w[], int *idx, int order, int part)
{
    if (order == 1)
        printf("| "); //-------------------> jika kolom paling kiri
    if (w[0] > 0) //-----------------------> record kolom 1
    {
        for (int i = 0; i < (w[0] - strlen(table[*idx].id)) / 2; i++)
            printf(" "); //----------------> print sisa spasi agar align center
        printf("%s", table[*idx].id); //---> print string data record
        for (int i = (w[0] - strlen(table[*idx].id)) / 2; i < (w[0] - strlen(table[*idx].id)); i++)
            printf(" "); //----------------> print sisa spasi
        printf(" | "); //------------------> pembatas antar kolom
    }
    // NOTE. alur kolom 2-4 sama dengan kolom 1
    if (w[1] > 0) // kolom 2
    {
        for (int i = 0; i < (w[1] - strlen(table[*idx].field1)) / 2; i++)
            printf(" ");
        printf("%s", table[*idx].field1);
        for (int i = (w[1] - strlen(table[*idx].field1)) / 2; i < (w[1] - strlen(table[*idx].field1)); i++)
            printf(" ");
        printf(" | ");
    }
    if (w[2] > 0) // kolom 3
    {
        for (int i = 0; i < (w[2] - strlen(table[*idx].field2)) / 2; i++)
            printf(" ");
        printf("%s", table[*idx].field2);
        for (int i = (w[2] - strlen(table[*idx].field2)) / 2; i < (w[2] - strlen(table[*idx].field2)); i++)
            printf(" ");
        printf(" | ");
    }
    if (w[3] > 0) // kolom 4
    {
        for (int i = 0; i < (w[3] - strlen(table[*idx].field3)) / 2; i++)
            printf(" ");
        printf("%s", table[*idx].field3);
        for (int i = (w[3] - strlen(table[*idx].field3)) / 2; i < (w[3] - strlen(table[*idx].field3)); i++)
            printf(" ");
        printf(" | ");
    }
    if (order == part) //------------------> jika kolom terakhir
        printf("\n"); //-------------------> print baris baru
}