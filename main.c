/*
    @Author             : Sekar Madu Kusumawardani
    @Email              : sekarmadu99@gmail.com / sekarmadu@upi.edu
    @Version            : V1.0
    @Created at         : 28 ‎May ‎2021, ‏‎16:39
    @Last Modified by   : Sekar Madu Kusumawardani
    @Last Modified at   : ‎04 ‎June ‎2021, ‏‎11:03
*/

#include "header.h"

int main()
{
    system("cls"); //--------------------------------------------> membersihkan konsol
    FILE *Film, *Penonton, *Transaksi; //------------------------> variabel penghubung ke sequential file
    //---------------------^tabel transaksi : transaksi.dat : berisi log pembelian tiket
    //----------^tabel penonton : penonton.dat : berisi daftar penonton
    //---^tabel list_film : list_film.dat : berisi daftar film
    int film = 0, penonton = 0, q = 0;
    //--------------------------^penanda query
    //------------^jumlah record penonton
    //--^jumlah record film
    char pita[200]; //------------------------------------------> pita query
    myTable tListFilm[200], tPenonton[200], tTransaksi[200]; //-> penampung data tabel dari squential file
    printf("<< Selamat Datang di DBMS Terjemahan Sekar >>\n");
    printf("Versi 1.0\n");
    do
    {
        printf("\ndbms sekar> ");
        scanf(" %199[^\n]s", pita); //--------------------------> meminta masukan pita query
        startWord(pita); //-------------------------------------> memulai pembacaan pita kata pertama
        q = query(pita); //-------------------------------------> menentukan query berdasarkan kata pertama
        if (q == -1) //-----------------------------------------> kondisi ketika kata pertama berisi ;
            printf("[GAGAL] Query tidak lengkap.\n");
        else if (q == 0) //-------------------------------------> kondisi ketika query yg dimasukkan salah
            printf("[GAGAL] Query salah atau tidak tersedia.\n");
        else if (q == 1) //-------------------------------------> kondisi ketika memasukkan query DESC atau SHOW
            help(pita); //--------------------------------------> panggil prosedur help
        else if (q == 2 || q == 3 || q == 4) //-----------------> kondisi ketika query INSERT / UPDATE / DELETE / SELECT
            request(pita, tListFilm, tPenonton, tTransaksi, &film, &penonton, Film, Penonton, Transaksi); //-> memproses query
        resetWord(); //-----------------------------------------> membersihkan penampung kata
        //------------------------------------------------------> query 5 : EXIT / jangan lupa bahagia hari ini
    } while (q != 5); //----------------------------------------> diulang selama q bukan 5
    printf("[BYE]\n\n<< Terima Kasih sudah menggunakan DBMS Terjemahan Sekar >>\n");
    if (q == 5) //----------------------------------------------> jika q = 5, keluar dari program
        system("exit");
    return 0;
}