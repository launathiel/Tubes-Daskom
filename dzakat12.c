#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i,j,n,f,duit,x,a;
char cari[50],milih[50];

struct login{
    char id[100],passu[100];
    int saldo,acc;
}reg,lg,sort[100],tempp;

struct inputtempat{
    char tempat[100];
    char deskripsi[100];
    int totdon;
} jen;

struct saldo{
	char id[100];
	int paket;
}temp;

struct accept{
	char id[100];
	int uang;
}acc;

FILE *file_inputtempat;
FILE *file_inputtempat2;
FILE *f_saldo;
FILE *f_saldo2;
FILE *f_login;
FILE *f_saldoacc;
FILE *f_temp;
FILE *f_ceksaldo;

void ceksaldo();
void admin();
void menu_admin();
void input_tempat();
void hapus_tempat();
void acc_saldo();
void regis();
void login();
void menu_user();
void saldo();
void lihat_tempat();
void berdonasi();
void sorting();
main()
{
    int pil;
    system("cls");
	printf("\t\t\t==========================================\n");
	printf("\t\t\t|              HAYU SEDEKAH              |\n");
	printf("\t\t\t==========================================\n");
	printf("\nMenu :\n");
    printf("1.Registrasi\n2.Login\n3.Admin\n4.Exit\n");
    printf("Pilihan (1/2/3/4): ");
    scanf("%d",&pil); getchar();
    switch(pil)
    {
    case 1 :regis();break;
    case 2 :login();break;
    case 3 :admin();break;
    case 4 :return 0;break;
    default:main();break;
    }
}

void admin()
{
	system("cls");
    char passad[10],usad[10];
    int pila;
    printf("Masukan Username : ");
    gets(usad);
    printf("Masukan Password : ");
    gets(passad);
    if(strcmp(passad,"admin")==0&&strcmp(usad,"admin")==0)
    {
        menu_admin();
    }
    else
    {
        printf("Kamu Bukan Admin !\n");
        main();
    }
}

void menu_admin()
{
    int pilad;
    system("cls");
    printf("Ngapain Min ?\n");
    printf("1.Masukin Daftar Tempat\n2.Hapus Tempat\n3.Acc Saldo\n4.List User\n5.Exit: ");
    printf("\npilihan :");scanf("%d",&pilad);getchar();
    switch(pilad)
    {
    case 1 : input_tempat();break;
    case 2 : hapus_tempat();break;
    case 3 : acc_saldo();break;
    case 4 : sorting();break;
    case 5 : main();break;
    default: menu_admin();break;
    }
}

void input_tempat()//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
{
  FILE *file_inputtempat;
	system("cls");
	printf("Input Tempat\n");
	file_inputtempat=fopen("panti.dat","ab"); 
		printf("Masukkan jumlah tempat : ");
		scanf("%d", &n); getchar();
	  for (i=1;i<=n;i++)
  		{
			printf("\n============================\n\n");
			printf("Tempat %d :\n",i);
			printf("Jenis Tempat       : ");gets(jen.tempat);
			printf("Deskripsi Tempat   : ");gets(jen.deskripsi);
			fwrite(&jen,sizeof(jen),1,file_inputtempat);
  		}
	fclose(file_inputtempat);
	system("pause");
	menu_admin();
}

void hapus_tempat()//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
{
 	FILE *file_inputtempat;
 	FILE *file_inputtempat2;
 	system("cls");
 	file_inputtempat = fopen("panti.dat", "rb");
  	while (fread(&jen,sizeof (jen),1, file_inputtempat)!=1)
    {
        printf("\nBelum ada tempat yang input.\n\n");
     	system("pause");
        menu_admin();
    }      
    rewind (file_inputtempat); //rewind untuk memundurkan pointer

    i=1; 
 	printf("\n===HAPUS TEMPAT===\n\n");
    while(fread(&jen,sizeof(jen),1,file_inputtempat)==1) //menampilkan tempat
    {
        printf("Tempat %d :\n",i);
        printf("Jenis Tempat      : %s\n",jen.tempat);
        printf("Deskripsi Tempat  : %s\n",jen.deskripsi);
        printf("_________________\n");
        i++;
    }
    fclose(file_inputtempat);
  	getchar();
  
    file_inputtempat = fopen("panti.dat", "rb");
    file_inputtempat2 = fopen("panti2.dat", "wb");

	printf("\nSilahkan masukkan nama yang ingin dihapus: "); gets(cari);
    
	int flag=0;
	while (fread(&jen,sizeof (jen),1, file_inputtempat)==1)
	{
		if(strcmp(jen.tempat,cari)!=0)
		{
			fwrite(&jen, sizeof(jen), 1, file_inputtempat2);
   		} 
  		else if(strcmp(jen.tempat,cari)==0)
  		{
   			flag=1; 
  		}  
	}
 	if(flag==0)
	{
		printf("\n\nTempat tidak ditemukan, Program akan kembali ke menu awal.\n\n");
		fclose(file_inputtempat);
		fclose(file_inputtempat2);
		remove("panti2.dat");
		rewind (file_inputtempat);
		system("pause");
        menu_admin();
	}
 	else
	{
 		printf("Tempat berhasil dihapus!!...\n");
 		fclose(file_inputtempat);
 		fclose(file_inputtempat2);
 		remove("panti.dat");
 		rename("panti2.dat","panti.dat");
 		system("pause");
 		menu_admin();
	}
 }
            
void acc_saldo()//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
{ 
 	system("cls");
    f_saldo=fopen("saldo.dat","rb");
   	if(fread(&temp,sizeof(temp),1,f_saldo)!=1) //dieksekusi jika saldo.dat tidak terbaca
    {
     	printf("\nBelum ada saldo yang diinput untuk di acc.\n\n");
        system("pause");
        menu_admin();
    }      
    rewind (f_saldo);
    
 	printf("\n==== ACC SALDO! ====\n");
 	while(fread(&temp,sizeof(temp),1,f_saldo)==1)	//menampilkan saldo.dat yang mau di acc
 	{
  		printf("\nID User : %s\n",temp.id);
  		printf("Paket yang dipilih %d\n",temp.paket);
 	}    
 	rewind(f_saldo);
 
 	char accid[50];
 	int accpaket, flag=0, count=0;
 	printf("\n===KONFIRMASI MENGISI SALDO===\n");
 
 	printf("ID : "); gets(accid); // masukkan id yang mau di acc
  	while (fread(&temp,sizeof (temp),1, f_saldo)==1)
   	{
    	if(strcmp(temp.id,accid)==0)
      	{
   			flag=1; //sbg pendanda true/false
      	}  
    } 
  	if(flag==0)// false artinya accid tidak sama dgn temp.id di saldo.dat
 	{
  		printf("\nID User tidak ditemukan!\n");
  		fclose(f_saldo);
  		fclose(f_saldoacc);
   		system("pause");
   		menu_admin();
 	}
	   
  	else
 	{
 		printf("Paket dipilih : "); scanf("%d",&accpaket); //masukkan paket yang mau di acc
  		rewind(f_saldo);
  		while(fread(&temp,sizeof(temp),1,f_saldo)==1)
     	{
     		if(accpaket==temp.paket) //jika paket yg dipilih = paket di saldo.dat
   			{
    			count = 1; 
       			switch (accpaket)
    			{
        		case 1 :
          			strcpy(acc.id, temp.id);
           			acc.uang = acc.uang + 50000;
           			break;     			
          		case 2 :
           			strcpy(acc.id, temp.id);
           			acc.uang = acc.uang + 100000; 
           			break;
         		case 3 :
           			strcpy(acc.id, temp.id);
           			acc.uang = acc.uang + 300000; 
     				break;
          		case 4 :
           			strcpy(acc.id, temp.id);
           			acc.uang = acc.uang + 500000; 
           			break;
    			}
    		break;
   			}
    	}   
  		//KONFIRMASI PEMBAYARAN
  		if(count == 1) //jika paket yg dipilih = paket di saldo.dat dan sudah proses switch case
		{
   			char x[10];
   			int z=0;
      		printf("Sudah Membayar?(y/n):");
      		scanf("%s",x);
     		fflush(stdin);
     		
      		if(x[0]=='y')
      		{
       			f_saldoacc=fopen("saldoacc.dat","ab");
       			fseek(f_saldoacc, (long)-sizeof(acc), SEEK_CUR);          
       			fwrite(&acc, sizeof(acc), 1, f_saldoacc); //nulis saldo yg ditambah di accsaldo.dat
       			fclose (f_saldoacc);
      			rewind(f_saldo);
    			f_temp=fopen("temp.dat","wb");
    			
       			while(fread(&temp, sizeof(temp), 1, f_saldo)==1)
       			{     
        			  
           			if(strcmp(temp.id,accid)==0) //jika idnya sama
           			{
            			if(temp.paket==accpaket)
						{
             				z++; //hitung jumlah paket yang sama dari id yang sama 
      					}
      					if(temp.paket!=accpaket || z>1) //apabila ada lebih dari 1 paket yg sama tulis sisanya
						{
            				fwrite(&temp, sizeof(temp), 1, f_temp);
           				}
           			}
           			else if(strcmp(temp.id,accid)!=0)//jika id berbeda
					{ 
           				fwrite(&temp, sizeof(temp), 1, f_temp);
     				}
       			}  
       			fclose(f_saldo);
       			fclose(f_temp);
       			remove("saldo.dat");
        		rename("temp.dat","saldo.dat");
        		printf("\nSaldo berhasil ditambahkan !\n");
       			system("pause");
       			menu_admin();
     		}
    		else if(x[0]=='n')
     		{
       			fclose(f_saldo);
       			fclose(f_saldoacc);
       			fclose(f_temp);
       			printf("Acc Saldo dibatalkan!\n");
       			system("pause");
       			menu_admin();
     		}
    	}
    	else //jika count == 0, accpaket yg diinput tidak sama dgn temp.paket pada saldo.dat
		{
     		fclose(f_saldo);
   			fclose(f_saldoacc);
   			fclose(f_temp);
   			printf("\nPaket tidak ditemukan!\n"); 
   			system("pause");     
    		menu_admin(); 
  		}
  	}
}

void regis()//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
{
	system("cls");
	f_login=fopen("login.dat","ab");
	printf("ID        : "); gets(reg.id);
 	printf("Password  : "); gets(reg.passu);
 	fwrite(&reg,sizeof(reg),1,f_login); //nulis registrasi id dan pass di login.dat
	fclose(f_login);
	printf("Registrasi berhasil!\n\n");
	system("pause");
	main();
}

void login(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
	system("cls");
 	printf("SELAMAT DATANG !! SILAHKAN LOGIN TERLEBIH DAHULU\n\n");
 	f_login=fopen("login.dat","rb");
 	printf("ID       : "); gets(lg.id);
 	printf("Password : "); gets(lg.passu);
 	while(fread(&reg,sizeof(reg),1,f_login)==1)
 	{
  		if(strcmp(reg.id,lg.id)==0&&strcmp(reg.passu,lg.passu)==0)
  		{
   			printf("Berhasil!\n\n");
   			fclose(f_login);
  			system("pause");
  			menu_user();
  		}
 	}
 	
 	if(strcmp(reg.id,lg.id)!=0||strcmp(reg.passu,lg.passu)!=0)
 	{
  	printf("Login Gagal\n");
  	fclose(f_login);
  	system("pause");
  	main();
 	}
}
    
void menu_user()
{
	system("cls");
    int pilus;
    printf("Selamat datang !\n\nSilahkan panen pahala\n");
    printf("1.Isi Saldo\n2.Lihat Daftar Tempat\n3.MAU SEDEKAH SEKARANG\n4.Cek Saldo\n5.Exit\n");
    printf("Pilihan:");scanf("%d",&pilus);getchar();
    switch(pilus)
    {
    case 1 : saldo();break;
    case 2 : lihat_tempat();break;
    case 3 : berdonasi();break;
    case 4 : ceksaldo();break;
    case 5 : main();break;
    default: menu_admin();break;
    }
}

void lihat_tempat()
{
	system("cls");
    file_inputtempat=fopen("panti.dat","rb");
    printf("\n\n==========LIST TEMPAT ==========\n\n");
    i=1;
    while(fread(&jen,sizeof(jen),1,file_inputtempat)==1)
    {
        printf("\n__________\n");
        printf("Tempat %d :",i);
        printf("\nJenis Tempat : %s\n",jen.tempat);
        printf("Deskripsi Tempat: %s\n",jen.deskripsi);
        i++;
    }
    fclose(file_inputtempat);
	printf("\nTekan Enter untuk balik ke menu user....\n");
    system("pause");
    menu_user();
}

void saldo(){
    system("cls");
    f_login=fopen("login.dat","rb");
    f_saldo = fopen("saldo.dat","ab");
    printf("====PAKET SALDO====");
    printf("\n1. Rp 50.000 Saldo, Harga Rp 48.000");
    printf("\n2. Rp 100.000 Saldo, Harga Rp 95.000");
    printf("\n3. Rp 300.000 Saldo, Harga Rp 280.000");
    printf("\n4. Rp 500.000 Saldo, Harga Rp 450.000");
    printf("\nPilih : ");scanf("%d",&x);getchar();
    switch(x){
    case 1 :
        strcpy(temp.id,lg.id);
        temp.paket=1;
        fwrite(&temp,sizeof(temp),1,f_saldo);
        fclose(f_saldo);
        fclose(f_login);
        break;
    case 2 :
        strcpy(temp.id,lg.id);
        temp.paket=2;
        fwrite(&temp,sizeof(temp),1,f_saldo);
        fclose(f_saldo);
        fclose(f_login);
        break;
    case 3 :
        strcpy(temp.id,lg.id);
        temp.paket=3;
        fwrite(&temp,sizeof(temp),1,f_saldo);
        fclose(f_saldo);
        fclose(f_login);
        break;
    case 4 :
        strcpy(temp.id,lg.id);
        temp.paket=4;
        fwrite(&temp,sizeof(temp),1,f_saldo);
        fclose(f_saldo);
        fclose(f_login);
        break;
    default :
        printf("Paket Tidak Tersedia, Silahkan Masukan lagi");
        fclose(f_saldo);fclose(f_login);saldo();
        break;
    }
    printf("\nPaket Berhasil di order, silahkan membayar ke admin lalu admin akan konfirmasi.");
    getch();
	fclose(f_saldo);
	fclose(f_login);
	menu_user();
}

void ceksaldo(){
	//USER CEK SALDO YANG DIMILIKINYA//
	f_ceksaldo=fopen("saldoacc.dat","rb");
	while(fread(&acc,sizeof(acc),1,f_ceksaldo)==1 && strcmp(acc.id,lg.id)==0)
	{
		printf("Saldo Anda: %d\n",acc.uang);
		fclose(f_ceksaldo);
		getch();system("cls");
		menu_user();
	}
}

void berdonasi(){//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
 	system("cls");
 	file_inputtempat=fopen("panti.dat","rb");//pointer
 	f_ceksaldo=fopen("saldoacc.dat","ab");//pointer
 	f_temp=fopen("tempdonasi.dat","wb");//pointer
 	char accid[50];
  	int accpaket, flag=0, count=0;
  	char pilihan[50];
 	printf("Gunakan Huruf Kapital\n");getchar();
 	printf("Masukan Nama Tempat : ");gets(accid);
 	while(fread(&jen,sizeof(jen),1,file_inputtempat)==1)//membaca file_inputtempat
 	{
  		if(strcmp(jen.tempat,accid)==0)//membandingkan jen.tempat dengan accid
  		{
  		flag=1; //jika true
  		}
 	}
 	
  	if(flag==0) //jika false
  	{
   		printf("Nama tempat tidak ada!\n");
   		system("pause");
   		menu_user();
  	}
  	else //jika flag 1 (jen.tempat == accid
  	{
   		printf("Nama tempat ditemukan!\n"); 
    	printf("Saldo Anda : %d\n",acc.uang);
    	printf("Donasi yang diberikan : ");scanf("%d",&duit);
    	
    	if(duit < acc.uang)
    	{
     		printf("Saldo anda cukup!\n");
     		printf("Apakah anda ingin melanjutkan donasi (y/n)\n");
     		printf("Pilihan : ");getchar();gets(pilihan);
     		if(pilihan[0]=='Y'||pilihan[0]=='y')//jika memilih y
	     	{
	     		acc.uang=acc.uang-duit;
      			printf("Donasi berhasil!\n");
      			printf("Sisa Saldo Anda : %d\n\n",acc.uang);
      			fseek(f_saldoacc, (long)-sizeof(acc), SEEK_CUR);
      			fwrite(&acc, sizeof(acc), 1, f_saldoacc);
      			fclose(f_ceksaldo);
      			fclose(file_inputtempat);
      			system("pause");
      			menu_user();
     		}
     		else //jika diinput selain y/Y
     		{
      			printf("Transaksi dibatalkan!\n");
      			system("pause");
      			menu_user();
     		}
    	}
    	else
    	{
     		printf("Saldo anda tidak cukup!\n");
     		fclose(f_ceksaldo);
     		system("pause");
     		menu_user();
    	} 
   } 
}

void sorting()
{//bagian ini sudah dihapus dan harus kalian isi lagi sesuai dengan file.exe
 	system("cls");
 	f_login=fopen("login.dat","rb");
 	f_ceksaldo=fopen("saldoacc.dat","rb");
 	int t=0;
 	char nama[100][100];
 	
  	while(fread(&reg,sizeof(reg),1,f_login)==1)
  	{
   		strcpy(nama[t],reg.id); //pindahin id reg ke array nama yang mau disorting
   		t++;  
 	}
 
 	int i=0;
 	int count;
 	while(i<t) //proses selection sort ascending
 	{
        int j,bd; 
       	j=i;
       	int k=i+1;
        while(k<t)
        {
         	bd=strcmp(nama[j],nama[k]);
         	if(bd==1) 
      		j=k; 
   			k++;     
        }
        
        if(j!=i)
 	 	{
         	char temp[1][30]; /* Swapping */
       		strcpy(temp[0],nama[j]);
         	strcpy(nama[j],nama[i]);
         	strcpy(nama[i],temp[0]);      
  		}   
  	i++; //meneruskan sorting hingga sesuai        
 	}
 /* MENAMPILKAN HASIL SORTING */ 
 	i=0;
    while(i<t) 
 	{ 
    	puts(nama[i]);
        while(fread(&acc,sizeof(acc),1,f_ceksaldo)==1 )
   		{
    		if(strcmp(acc.id,nama[i])==0)
    		{
     			printf("%d\n", acc.uang); //menampilkan saldo sesuai nama yang disorting
   			}
  		}
        rewind(f_ceksaldo);
        printf("+++++++++++++++++++++++++++++++++++++++++\n\n");
    i++;
 	}

 	fclose(f_ceksaldo);
 	fclose(f_login);
 	rewind(f_login);
 
 	system("pause");
 	menu_admin();
}





