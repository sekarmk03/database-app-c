/*
    @Author             : Sekar Madu Kusumawardani
    @Email              : sekarmadu99@gmail.com / sekarmadu@upi.edu
    @Version            : V1.0
    @Created at         : 28 ‎May ‎2021, ‏‎16:39
    @Last Modified by   : Sekar Madu Kusumawardani
    @Last Modified at   : ‎04 ‎June ‎2021, ‏‎11:03
*/

/*
    Saya [Sekar Madu Kusumawardani_2007703] mengerjakan Tugas Masa Depan (TMD)
    dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya maka saya
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

/*== LIBRARY ==*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*== Macro ==*/
#define pajak 3500 //----> pajak per orang (per tiket)

/*== STRUCT PENAMPUNG DATA TABEL ==*/
typedef struct{
    char id[50], field1[50], field2[50], field3[50];
    //---^id-----^kolom2----^kolom3-----^kolom4
} myTable; // inisialisasi struct

/*== GLOBAL VARIABEL ==*/
int idx; //-------------> penanda index pita (query)
int wordLen; //---------> panjang per kata dalam pita (query)
char currWord[50]; //---> penampung kata yang sedang dibaca

/*== FUNGSI & PROSEDUR ==*/
void help(char pita[]); //--------------------> Menampilkan Informasi DBMS
void startWord(char pita[]); //---------------> Membaca Kata Pertama dari Pita (Query)
void incWord(char pita[]); //-----------------> Memajukan Pembacaan Kata
char *getCWord(); //--------------------------> Mengambil Kata yang Sedang Dibaca
void resetWord(); //--------------------------> Membersihkan Kata yang Sedang Dibaca
int getWordLen(); //--------------------------> Mengambil Panjang Kata yang Sedang Dibaca
int EOP(char pita[]); //----------------------> Lampu Penanda Akhir Pita (Query)
void swap(myTable *awal, myTable *akhir); //--> Menukar 2 Record Data
void quickSort(myTable table[], int left, int right); //---------------------------------------------> Mengurutkan Record Berdasarkan Id (Ascending)
int query(char pita[]); //--------------------> Mengidentifikasi Query Kata Pertama
int bahagia(char pita[], char check[][20]); //> Mengecek Kelengkapan Query Khusus untuk Exit
int binSearch(myTable table[], char search[], int left, int right); //-------------------------------> Mencari Data Foreign Key
int readTable(FILE *fileTbl, myTable table[], char tblName[]); //------------------------------------> Membaca Data dari Sequential File
void writeTable(FILE *fileTbl, myTable table[], int n, char tblName[]); //---------------------------> Menulis Data ke Sequential File
void request(char pita[], myTable tFilm[], myTable tPenonton[], myTable tTransaksi[], int *f, int *p, FILE *Film, FILE *Penonton, FILE *Transaksi); //--------------> Mengatur Request Query
myTable insertProcess(char pita[], myTable tbl[], myTable tbl2[], int tbl2N, int *idx, int *incorrectValInsert, int isInsert, char tblName[]); //-------------------> Proses Menambahkan Record
void triggerTrans(char pita[], myTable tTransaksi[], int *t, int p, myTable tFilm[], myTable tPenonton[], int f, myTable prevRecord); //----------------------------> Trigger Tabel Transaksi
void deleteProcess(char pita[], myTable tbl[], int *idx); //-----------------------------------------> Prosedur Menghapus Record
void selectProcess(char colName[][20], myTable tbl[], int n, int w[], int order, int part); //-------> Prosedur Menampilkan Tabel
void joinProcess(char colName1[][20], char colName2[][20], int w1[], int w2[], myTable a[], myTable b[], myTable c[], int nA, int nB, int nC, int tableJoining); //-> Prosedur Menggabungkan 3 Tabel
void separator(int width); //-----------------> Menampilkan Pembatas Per Baris
void thead(char colName[], int maxWidth); //--> Menampilkan Header Per Kolom
int Max(int arr[], int n); //-----------------> Mencari String Terpanjang per Kolom
int toArray(myTable tbl[], int n, int find); // Mengubah Data Kolom Struct menjadi Array
void header(char colName[], int width); //----> Mencari Panjang Fix Kolom
void getSeparator(char colName[][20], int w[], int order, int part); //------------------------------> Menampilkan Pembatas Tabel
void getTHead(char colName[][20], int w[], int order, int part); //----------------------------------> Menampilkan Judul Header
void printRecord(char colName[][20], myTable table[], int w[], int *idx, int order, int part); //----> Menampilkan Isi Record per Baris