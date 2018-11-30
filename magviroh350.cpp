#include <iostream>
#include <windows.h>
using namespace std;
typedef struct{
string pemain[10]; string posisi[10];
int bos=1, tos=0;
}stack_pemain;

stack_pemain pemain;

bool emptyStack(stack_pemain X){
if(X.tos==0){
    return true;
}
    else{
        return false;
    }
}

bool fullStack(stack_pemain X){
if(X.tos==10){
    return true;
}
    else{
        return false;
    }
}

void Push_Stack(stack_pemain &X){
    cout<<"Menambahkan pemain"<<endl;
    X.tos++;
    cout<<"Masukkan nama pemain : "; cin>>X.pemain[X.tos];
    cout<<"Masukkan posisi pemain : "; cin>>X.posisi[X.tos];
    cout<<"Pemain sudah dimasukkan kedalam tim"<<endl;
}
void Pop_Stack(stack_pemain &X){
    cout<<"Mengurangi Pemain"<<endl;
    cout<<"pemain yang diambil "<<endl;
    cout<<"nama pemain : "; cin>>X.pemain[X.tos];
    cout<<"posisi pemain : "; cin>>X.posisi[X.tos];
    X.tos--;
    cout<<"pemain sudah dikelarkan"<<endl;
}

void Print_Stack(stack_pemain &X){
    cout<<"ini adalah daftar pemain saat ini"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Nomor       Nama Pemain     Posisi"<<endl;
    cout<<"-------------------------------------"<<endl;
    for(int i=X.tos;i>=X.bos;i--){
    cout<<" "<<i<<"	 	"<<X.pemain[i]<<"    	"<<X.posisi[i]<<endl;
    cout<<"-------------------------------------"<<endl;
    }
    cout<<"saat ini terdapat"<<X.tos<<"pemain di nomor"<<endl;
    }

void Find_Stack(stack_pemain &X){
    string caripemain,cariposisi;
    bool ada=false;
    cout<<"masukkan jenis pemain yang dicari : "; cin>>caripemain;
    cout<<"masukkan posisi yang diinginkan : "; cin>>cariposisi;
    for(int i=X.bos;i<=X.tos;i++){
        if((X.pemain[i]==caripemain)&&(X.posisi[i]==cariposisi)){
            ada=true;
            cout<<"pemain "<<caripemain<<"dengan nama "<<cariposisi<<"ada di nomor"<<i<<endl;
            }
        if(not ada){cout<<"pemain dengan nama "<<caripemain<<"posisi "<<cariposisi<<"tidak ditemukan"<<endl;}
    }
}

int main(){
    int pilih=0;
    do{
        system("cls");
        cout<<"pilih menu"<<endl;
        cout<<"1. Tambah pemain"<<endl;
        cout<<"2. Cetak daftar pemain"<<endl;
        cout<<"3. Keluarkan pemain"<<endl;
        cout<<"4. Cari pemain"<<endl;
        cout<<"0. Selesai"<<endl;
        cout<<"pilih menu : ";cin>>pilih;
        switch(pilih){
        case 1:{if(fullStack(pemain)){cout<<"Pemain penuh "<<endl;}else{Push_Stack(pemain);}break;}
        case 2:{if(emptyStack(pemain)){cout<<"pemain kosong "<<endl;}else{Print_Stack(pemain);}break;}
        case 3:{if(emptyStack(pemain)){cout<<"pemain kosong "<<endl;}else{Pop_Stack(pemain);}break;}
        case 4:{if(emptyStack(pemain)){cout<<"pemain kosong "<<endl

		;}else{Find_Stack(pemain);}break;}
        case 0:{cout<<"Terimakasih"<<endl;break;}
        default:cout<<"salah pilih menu"<<endl;

        }system("pause");
    }
        while(pilih!=0);

}

