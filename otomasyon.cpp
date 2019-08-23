//****************************************************************************
//**                            SAKARYA �N�VERS�TES�
//**                 B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
//**                      B�LG�SAYAR M�HEND�SL��� B�L�M�
//**                        Programlamaya Giri� Dersi
//**                           2015 - 2016 G�Z D�NEM�
//**
//**                 �DEV NUMARASI.......... : Proje �devi
//**                 ��RENC� ADI............ : Taylan Umut Toko�lu
//**				 ��RENC� NUMARASI....... : b151210077
//**                 DERS�N ALINDI�I GRUP... : C Grubu
//*****************************************************************************/

#include "stdafx.h"
#include <fstream>		   
#include <iostream>        
#include <string>          
#include <clocale>         
#include <iomanip>         

using namespace std;

int  i = 1;
char cevap, secim;
//de�i�kenler global olarak tan�mlan�yor.
struct Hasta_verileri
{
	string Adi;
	string Soyadi;
	string Tc;
	string Tel;
	string Dogum_Tar;
}hasta;

struct Randevu_verileri
{
	string Tarih;
	string Saat;
	string DK_Adi;
	string Teshis;
	string �laclar;
	string Tahliller;
}randevu;

int main()
{
	setlocale(LC_ALL, "turkish");



	do		//D�ng� ba�lang�c�(0 se�ilene kadar d�ner)
	{

		cout << "1)Hasta kayd�" << endl;
		cout << "2)Hasta kayd� g�ncelleme " << endl;
		cout << "3)Hasta silme" << endl;
		cout << "4)Randevu alma" << endl;
		cout << "5)Randevu silme" << endl;
		cout << "6)Randevu g�ncelleme" << endl;
		cout << "7)Hasta sorgulama" << endl;
		cout << "8)Hasta listesi alma" << endl;
		cout << "9)Hasta muayene kayd�" << endl;
		cout << "0)��k��" << endl;
		cout << "Se�iminiz:";
		cin >> secim;



		switch (secim)
		{
		case '1':            //Hasta kayd� se�ene�i
		{
			ofstream DosyaAc;
			DosyaAc.open("Hasta.txt", ios::app);
			string TC;                                      //Eklenecek Tc yi kontrol etmek i�in �nce ba�ka bir de�i�ken tan�mlan�yor.
			do
			{
				cout << "\nEklenecek Hasta TC:"; cin >> TC;
				ifstream DosyaOku("Hasta.txt", ios::app);   // Hasta.txt  Dosyas�n� ekleme modunda a��l�yor
				while (!DosyaOku.eof())                     //Dosya sonunu g�rene kadar devam etmesi i�in sonsuz d�ng� ba�lang�c�
				{
					DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar; //Dosyadan okuma yap�l�yor.
					if (TC == hasta.Tc)                             //Hasta Tc daha �nceki Tc'ler ile e�le�iyor mu diye kontol ediliyor.
					{
						cout << "Bu Hasta daha �nce eklenmi�." << endl; break;
					}
					else                                      //Hasta Tc dosyaya daha �nce eklenmemi� ise di�er bilgileri giriyoruz
					{
						hasta.Tc = TC;                              //Kontrol etmek i�in girdi�imiz Tc as�l tc'ye atan�yor.
						cout << "\nHasta Tc: " << hasta.Tc;
						cout << "\nHasta Ad�:"; cin >> hasta.Adi;
						cout << "\nHasta Soyad�:"; cin >> hasta.Soyadi;
						cout << "\nHasta Telefon(11 Hane):"; cin >> hasta.Tel; cin.ignore();
						cout << "\nHasta Do�um Tarihi(G�n/Ay/Y�l): "; cin >> hasta.Dogum_Tar;
						DosyaAc << hasta.Tc << ' ' << hasta.Adi << ' ' << hasta.Soyadi << ' ' << hasta.Tel << ' ' << hasta.Dogum_Tar << "\n";
						//Dosyaya yaz�m i�lemi yap�l�yor.
						break;
					}
				}
				cout << "Ba�ka kay�t yapacak m�s�n?(e/h):";   //Ba�ka kay�t yap�lacak m� kontrolu yap�l�yor.
				cin >> cevap;
			} while (!(cevap == 'h'));  //Cevap h de�il ise program�n devam etmesi sa�lan�yor.                       

			break;
		}
		case '2':    //Hasta g�ncelleme se�ene�i
		{
			string TC;
			ifstream DosyaOku;
			ofstream DosyaYaz;
			DosyaOku.open("Hasta.txt");
			DosyaYaz.open("D�zenleme.txt", ios::app);
			cout << "Hasta TC:"; cin >> TC;

			while (true)
			{
				DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;  //Hasta.txt ten oku�a yap�l�yor.
				if (DosyaOku.eof())	break;      //Dosya sonuna geldiyse iki kez okumamas� i�in ��k�� yapmas� sa�lan�yor.
				if (TC == hasta.Tc)                   //Tc dosyadaki bir Tc ile e�it ise
				{

					cout << "\nHasta TC......: " << TC << "\nHasta ad� soyad�.....: " << hasta.Adi << " " << hasta.Soyadi << "\nTelefon.......: " << hasta.Tel << "\nDo�um tarihi..: " << hasta.Dogum_Tar << "\n\nYeni Bilgiler;\n";
					//G�ncellenecek hastan�n bilgilerini ekrana yaz�l�p
					cout << "Hasta TC......: "; cin >> hasta.Tc;   cin.ignore();             //Yeni bilgiler al�n�yor.
					cout << "Hasta ad�.....: "; cin >> hasta.Adi;
					cout << "Hasta soyad�..: "; cin >> hasta.Soyadi; cin.ignore();
					cout << "Telefon.......: "; cin >> hasta.Tel; cin.ignore();
					cout << "Do�um tarihi..: "; cin >> hasta.Dogum_Tar;

					cout << "\t~~Hasta bilgileri g�ncellendi!~~\n";


					DosyaYaz << hasta.Tc << " " << hasta.Adi << " " << hasta.Soyadi << " " << hasta.Tel << " " << hasta.Dogum_Tar << "\n";
					//D�zenleme.txt'e yenibilgiler yaz�l�yor.
				}
				else //Tc dosyadakilerle uyu�muyorsa
				{

					cout << "Hasta aran�yor\n";
					//T�m di�er de�erleri yeni d�zenleme dosyas�na yaz�l�yor.
					DosyaYaz << hasta.Tc << " " << hasta.Adi << " " << hasta.Soyadi << " " << hasta.Tel << " " << hasta.Dogum_Tar << "\n";

					if (DosyaOku.eof())
					{
						cout << "Hasta bulunamad�."; break;
					}
				}

			}
			DosyaOku.close();
			DosyaYaz.close();



			remove("Hasta.txt");     //Hasta.txt i siliniyor
			rename("D�zenleme.txt", "Hasta.txt"); //D�zenleme adl� dosyas�n�n ad� hasta olarak de�i�tiriliyor
			remove("D�zenleme.txt"); //d�zenleme.txt siliniyor
			break;


		}
		case '3':  //Hasta silme se�ene�i
		{

			string TC;          //Kontrol i�in Tc

			ifstream DosyaOku;
			ofstream DosyaYaz;
			ifstream Dosyaoku;
			ofstream Dosyayaz;

			Dosyaoku.open("Randevu.txt");
			Dosyayaz.open("D�zen.txt", ios::app);  //Randevular� kopyalamak i�in yeni dosya
			DosyaOku.open("Hasta.txt");            //Hastalar� okumak i�in a��l�yor.
			DosyaYaz.open("Silme.txt", ios::app);  //Silinmeyecek hastalar� kopyalamak i�in dosya

			cout << "Hasta TC: "; �� harfli >> TC;
			while (!Dosyaoku.eof())
			{
				Dosyaoku >> hasta.Tc >> randevu.Tarih >> randevu.Saat >> randevu.DK_Adi >> randevu.Teshis >> randevu.�laclar >> randevu.Tahliller;
				//Randevu dosyas�ndan bilgileri okunuyor.


				DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				if (DosyaOku.eof())	break; //Dosya sonuna geldi�inde ��kmas� sa�lan�yor.


				if (TC == hasta.Tc)        //E�er silinecek Tc var ise
				{
					cout << "\nHasta TC......: " << TC << "\nHasta ad� soyad�.....: " << hasta.Adi << " " << hasta.Soyadi << "\nTelefon.......: " << hasta.Tel << "\nDo�um tarihi..: " << hasta.Dogum_Tar;

					cout << "\n\nHasta TC......: " << TC << "\nRandevu Tarih.....: " << randevu.Tarih << "\nRandevu Saati....:" << randevu.Saat << "\nDoktor Ad�......: " << randevu.DK_Adi << "\nTe�his...: " << randevu.Teshis << "\n�la�lar..: " << randevu.�laclar << "\nTahliller...:" << randevu.Tahliller << "\n";

					cout << "\n\nKay�t silindi!\n";

					if (DosyaOku.eof()) break;		//	En son kayd� 2 kere okumamas� i�in..
				}
				else
				{
					//E�er Tc ler uyu�mad�ysa(Di�er hastalar�n bilgileri) hepsini di�er kopya dosyalara yaz�l�yor
					DosyaYaz << hasta.Tc << " " << hasta.Adi << " " << hasta.Soyadi << " " << hasta.Tel << " " << hasta.Dogum_Tar << "\n";

					Dosyayaz << hasta.Tc << " " << randevu.Tarih << " " << randevu.Saat << " " << randevu.DK_Adi << " " << randevu.Teshis << " " << randevu.�laclar << " " << randevu.Tahliller << "\n";

					cout << "Hasta bulunamad�.\n"; break;
				}

			}

			DosyaOku.close();
			DosyaYaz.close();
			Dosyaoku.close();
			Dosyayaz.close();


			remove("Hasta.txt");             //Orjinal dosyalar� silip kopyalar�n adlar� d�zenleniyor
			rename("Silme.txt", "Hasta.txt");
			remove("Randevu.txt");
			rename("D�zen.txt", "Randevu.txt");


			break;
		}
		case '4':  //Randevu kay�t se�ene�i
		{

			string TC;
			cout << "Hasta TC:";  cin >> TC;

			ifstream DosyaOku("Hasta.txt");

			while (!DosyaOku.eof())
			{
				//Hasta.txt ten bilgiler al�n�yor
				DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				if (TC == hasta.Tc)  //Arad���m�z Tc dosyadakiyle e�it ise 
				{
					cout << "Hasta Bilgileri\n";
					cout << "TC no: " << hasta.Tc << endl;
					cout << "Hastan�n Ad� Soyad�: " << hasta.Adi << ' ' << hasta.Soyadi << endl;
					cout << "Hastan�n Telefon: " << hasta.Tel << endl;
					cout << "Hasta randevu istiyor mu?(e/h)"; cin >> cevap; cout << endl;
					//Randevu al�p almama kontrol� yap�l�yor
					if (cevap == 'e')
					{
						DosyaOku.close();
						ofstream DosyaYaz;
						DosyaYaz.open("Randevu.txt", ios::app); //Muayene dosyas�n� a��l�p
						cout << "\nRandevu Bilgileri" << endl;                     //Randevu bilgileri giriliyor
						cout << "\nRandevu Tarihi (G�n/Ay/Y�l olarak) :  "; cin >> randevu.Tarih;
						cout << "\nRandevu Saati (<__:__> olarak) : "; cin >> randevu.Saat;
						cout << "\nDoktor Ad�: "; cin >> randevu.DK_Adi;
						cout << "\nTe�his: ";  cin >> randevu.Teshis;  cin.ignore();
						cout << "\n�la�lar(',' ile ay�r�n�z.) :"; cin >> randevu.�laclar;
						cout << "\nTahliller :"; cin >> randevu.Tahliller;   cin.ignore();

						DosyaYaz << hasta.Tc << ' ' << randevu.Tarih << ' ' << randevu.Saat << ' ' << randevu.DK_Adi << ' ' << randevu.Teshis << ' ' << randevu.�laclar << ' ' << randevu.Tahliller << "\n";
						//Veriler dosyaya yaz�l�p ard�ndan kapat�l�yorr
						DosyaYaz.close();
						break;
					}
					else //cevap h ise d�ng�den ��k�l�yor.
					{
						break;
					}
				}
				else
				{


					cout << "... \nHasta aran�yor." << endl; //Tek tek kontrol edilirken verilecek ekran ��kt�s�

					cout << "Hasta bulunamad�.\n";
					break;

				}

			}


			break;
		}
		case '5':      //Randevu silme se�ene�i
		{

			string TC;
			ifstream DosyaOku;
			ofstream DosyaYaz;
			DosyaOku.open("Randevu.txt");
			DosyaYaz.open("D�zen.txt", ios::app);
			cout << "Hasta TC:"; cin >> TC;

			while (true)
			{
				if (DosyaOku.eof())
				{
					cout << "Dosya sonu.\n"; break;
				}
				DosyaOku >> hasta.Tc >> randevu.Tarih >> randevu.Saat >> randevu.DK_Adi >> randevu.Teshis >> randevu.�laclar >> randevu.Tahliller;
				//Dosyadan Randevu bilgileri okunuyot

				if (TC == hasta.Tc)
				{

					cout << "\nHasta TC......: " << TC << "\nRandevu Tarih.....: " << randevu.Tarih << "\nRandevu Saati....:" << randevu.Saat << "\nDoktor Ad�......: " << randevu.DK_Adi << "\nTe�his...: " << randevu.Teshis << "\n�la�lar..: " << randevu.�laclar << "\nTahliller...:" << randevu.Tahliller << "\n";

					cout << "\n\t~~Randevu bilgileri g�ncellendi!~~\n";

				}
				else  //E�it tc yi bulamazsa D�zen.txt e yaz�yor
				{
					DosyaYaz << hasta.Tc << " " << randevu.Tarih << " " << randevu.Saat << " " << randevu.DK_Adi << " " << randevu.Teshis << " " << randevu.�laclar << " " << randevu.Tahliller << "\n";

					cout << "Randevu bulunamad�.\n";
					break;

				}

			}

			DosyaOku.close();
			DosyaYaz.close();

			remove("Randevu.txt");    //As�l dosya silinip yede�in ad� de�i�tiriliyor
			rename("D�zen.txt", "Randevu.txt");

			break;
		}
		case '6':   //Randevu d�zenleme se�ene�i
		{
			string TC;

			ifstream DosyaOku;
			ofstream DosyaYaz;

			DosyaOku.open("Randevu.txt");
			DosyaYaz.open("D�zen.txt", ios::app); //D�zenlenirken kullan�lacak kopya dosya

			cout << "Hasta TC:"; cin >> TC;

			while (true)
			{
				DosyaOku >> hasta.Tc >> randevu.Tarih >> randevu.Saat >> randevu.DK_Adi >> randevu.Teshis >> randevu.�laclar >> randevu.Tahliller;
				//Dosyadan bilgiler okunuyor
				if (DosyaOku.eof())	break; //E�er dosya sonuna geldiyse iki kere okumas�n diye ��k��

				if (TC == hasta.Tc)
				{

					cout << "\nHasta TC......: " << TC << "\nRandevu Tarih.....: " << randevu.Tarih << "\nRandevu Saati....:" << randevu.Saat << "\nDoktor Ad�......: " << randevu.DK_Adi << "\nTe�his...: " << randevu.Teshis << "\n�la�lar..: " << randevu.�laclar << "\nTahliller...:" << randevu.Tahliller << "\n";
					//Dosyadan silece�imiz randevu ekrana yazd�r�l�p
					//Yeni bilgiler isteniyor
					cout << "\n ~~Yeni Bilgiler~~ \n";
					cout << "Randevu Tarih.....: "; cin >> randevu.Tarih;
					cout << "Randevu Saati....:"; cin >> randevu.Saat;
					cout << "Doktor Ad�......: "; cin >> randevu.DK_Adi;
					cout << "Te�his...: "; cin >> randevu.Teshis;
					cout << "�la�lar..: "; cin >> randevu.�laclar;
					cout << "Tahliller...:"; cin >> randevu.Tahliller;
					cout << "\n\t~~Randevu bilgileri g�ncellendi!~~\n";

					DosyaYaz << hasta.Tc << " " << randevu.Tarih << " " << randevu.Saat << " " << randevu.DK_Adi << " " << randevu.Teshis << randevu.�laclar << randevu.Tahliller << "\n";
					//Yeni bilgilerimizi kopya dosyaya(D�zen.txt) yaz�yoruz
				}
				else
				{		//Tc'si tutmayan di�er randevular yedek dosyaya yaz�l�yor
					DosyaYaz << hasta.Tc << " " << randevu.Tarih << " " << randevu.Saat << " " << randevu.DK_Adi << " " << randevu.Teshis << randevu.�laclar << randevu.Tahliller << "\n";
				}
			}
			DosyaOku.close();
			DosyaYaz.close();

			remove("Randevu.txt");        //Dosyalar� kapat�p isimleri de�i�tiriliyor
			rename("D�zen.txt", "Randevu.txt");

			break;
		}
		case '7':  //Hasta sorgulama se�ene�i
		{

			string TC;
			cout << "Hasta TC:";  cin >> TC;

			ifstream DosyaOku("Hasta.txt");

			while (!DosyaOku.eof())
			{
				DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				//Dosyadan bilgiler okunuyor

				if (TC == hasta.Tc)  //Hasta bulunursa ekrana yazd�r�yoruz
				{
					cout << "\n---====Hasta Bilgileri====---\n";
					cout << "\nTC no: " << setw(25) << hasta.Tc << endl;
					cout << "Hastan�n Ad� Soyad�: " << setw(2) << hasta.Adi << ' ' << hasta.Soyadi << endl;
					cout << "Hastan�n Telefon: " << setw(14) << hasta.Tel << endl;
					cout << "Do�um Tarihi: " << setw(17) << hasta.Dogum_Tar << endl;
					break;
				}

				else
				{
					cout << "Hasta bulunamad�.\n";
				}
			}

		}
		break;
		case '8':   //Hasta listeleme modu
		{


			ifstream Dosyaoku("Hasta.txt");

			while (true)
			{
				Dosyaoku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				//Dosyadan bilgiler okunuyor
				if (Dosyaoku.eof())  //Dosya sonuna geldiyse son sat�r iki kere okunmas�n diye ��k��
				{
					break;
				}
				cout << "\n\n---====Hasta Bilgileri====---\n";
				cout << "\nTC no: " << setw(25) << hasta.Tc << endl;
				cout << "Hastan�n Ad� Soyad�: " << setw(2) << hasta.Adi << ' ' << hasta.Soyadi << endl;
				cout << "Hastan�n Telefon: " << setw(14) << hasta.Tel << endl;

			}
			Dosyaoku.close();
			cout << endl;
			break;
		}
		case '9': //Randevu arama se�ene�i
		{

			string TC;
			cout << " Hasta TC no giriniz:"; cin >> TC;
			ifstream DosyaAc("Hasta.txt");

			while (!(DosyaAc.eof()))  //Hasta dosyas�n�n sonuna kadar d�n�yor
			{
				DosyaAc >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				//Dosyadan bilgiler okunuyor
				if (TC == hasta.Tc)  //E�er Tc uyu�ursa bilgiler ekrana yazd�r�l�yor
				{
					cout << "\nHasta Bilgileri\n\n";
					cout << "TC no: " << hasta.Tc << endl;
					cout << "Hastan�n Ad� Soyad�: " << hasta.Adi << ' ' << hasta.Soyadi << endl;
					cout << "Hastan�n Telefon: " << hasta.Tel << endl;
					cout << "Hasta Do�um Tarihi: " << hasta.Dogum_Tar << endl;

					DosyaAc.close();  //Hasta dosyas� kullan�lmayaca�� i�in kapat�l�yor
					ofstream DosyaYaz;
					DosyaAc.open("Randevu.txt", ios::in);  //Muayene dosyas�n� a��l�yor

					cout << "\n Randevu Bilgileri  \n" << endl;

					cout << setw(8) << "      TC       " << setw(6) << " Tarih" << setw(12) << "Saat" << setw(18) << "Doktor Ad�" << setw(12) << " Te�his " << setw(17) << "�la�lar" << setw(18) << "Tahliller" << endl;
					while (!DosyaAc.eof())  //D�ng� ba�lang�c� randevu dosyas� i�in
					{
						//Dosyadan veriler okunuyor
						DosyaAc >> hasta.Tc >> randevu.Tarih >> randevu.Saat >> randevu.DK_Adi >> randevu.Teshis >> randevu.�laclar >> randevu.Tahliller;
						if (hasta.Tc == TC) //E�er Hastan�n randevusu varsa ekrana yazd�r�l�yor
						{

							cout << setw(13) << hasta.Tc << setw(7) << '  ' << randevu.Tarih << setw(9) << randevu.Saat << setw(15) << randevu.DK_Adi << setw(16) << randevu.Teshis << setw(14) << randevu.�laclar << setw(17) << randevu.Tahliller << endl;

						}
					}
					DosyaYaz.close();
					break;
				}
				else
				{

					cout << "Randevu bulunamad�.\n";
					break;

				}

			}

		}
		break;

		case '0':  //Men� ��k�� se�ene�i
		{
			return 0;//��k��
		}break;

		default:
		{
			cout << "Hatal� se�enek!" << endl;
		}break;
		}
	} while (secim !=0); //Men� do while d�ng�s�n�n sonu
	system("pause");
	return 0;
}