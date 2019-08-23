//****************************************************************************
//**                            SAKARYA ÜNÝVERSÝTESÝ
//**                 BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
//**                      BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
//**                        Programlamaya Giriþ Dersi
//**                           2015 - 2016 GÜZ DÖNEMÝ
//**
//**                 ÖDEV NUMARASI.......... : Proje Ödevi
//**                 ÖÐRENCÝ ADI............ : Taylan Umut Tokoðlu
//**				 ÖÐRENCÝ NUMARASI....... : b151210077
//**                 DERSÝN ALINDIÐI GRUP... : C Grubu
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
//deðiþkenler global olarak tanýmlanýyor.
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
	string Ýlaclar;
	string Tahliller;
}randevu;

int main()
{
	setlocale(LC_ALL, "turkish");



	do		//Döngü baþlangýcý(0 seçilene kadar döner)
	{

		cout << "1)Hasta kaydý" << endl;
		cout << "2)Hasta kaydý güncelleme " << endl;
		cout << "3)Hasta silme" << endl;
		cout << "4)Randevu alma" << endl;
		cout << "5)Randevu silme" << endl;
		cout << "6)Randevu güncelleme" << endl;
		cout << "7)Hasta sorgulama" << endl;
		cout << "8)Hasta listesi alma" << endl;
		cout << "9)Hasta muayene kaydý" << endl;
		cout << "0)Çýkýþ" << endl;
		cout << "Seçiminiz:";
		cin >> secim;



		switch (secim)
		{
		case '1':            //Hasta kaydý seçeneði
		{
			ofstream DosyaAc;
			DosyaAc.open("Hasta.txt", ios::app);
			string TC;                                      //Eklenecek Tc yi kontrol etmek için önce baþka bir deðiþken tanýmlanýyor.
			do
			{
				cout << "\nEklenecek Hasta TC:"; cin >> TC;
				ifstream DosyaOku("Hasta.txt", ios::app);   // Hasta.txt  Dosyasýný ekleme modunda açýlýyor
				while (!DosyaOku.eof())                     //Dosya sonunu görene kadar devam etmesi için sonsuz döngü baþlangýcý
				{
					DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar; //Dosyadan okuma yapýlýyor.
					if (TC == hasta.Tc)                             //Hasta Tc daha önceki Tc'ler ile eþleþiyor mu diye kontol ediliyor.
					{
						cout << "Bu Hasta daha önce eklenmiþ." << endl; break;
					}
					else                                      //Hasta Tc dosyaya daha önce eklenmemiþ ise diðer bilgileri giriyoruz
					{
						hasta.Tc = TC;                              //Kontrol etmek için girdiðimiz Tc asýl tc'ye atanýyor.
						cout << "\nHasta Tc: " << hasta.Tc;
						cout << "\nHasta Adý:"; cin >> hasta.Adi;
						cout << "\nHasta Soyadý:"; cin >> hasta.Soyadi;
						cout << "\nHasta Telefon(11 Hane):"; cin >> hasta.Tel; cin.ignore();
						cout << "\nHasta Doðum Tarihi(Gün/Ay/Yýl): "; cin >> hasta.Dogum_Tar;
						DosyaAc << hasta.Tc << ' ' << hasta.Adi << ' ' << hasta.Soyadi << ' ' << hasta.Tel << ' ' << hasta.Dogum_Tar << "\n";
						//Dosyaya yazým iþlemi yapýlýyor.
						break;
					}
				}
				cout << "Baþka kayýt yapacak mýsýn?(e/h):";   //Baþka kayýt yapýlacak mý kontrolu yapýlýyor.
				cin >> cevap;
			} while (!(cevap == 'h'));  //Cevap h deðil ise programýn devam etmesi saðlanýyor.                       

			break;
		}
		case '2':    //Hasta güncelleme seçeneði
		{
			string TC;
			ifstream DosyaOku;
			ofstream DosyaYaz;
			DosyaOku.open("Hasta.txt");
			DosyaYaz.open("Düzenleme.txt", ios::app);
			cout << "Hasta TC:"; cin >> TC;

			while (true)
			{
				DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;  //Hasta.txt ten okuöa yapýlýyor.
				if (DosyaOku.eof())	break;      //Dosya sonuna geldiyse iki kez okumamasý için çýkýþ yapmasý saðlanýyor.
				if (TC == hasta.Tc)                   //Tc dosyadaki bir Tc ile eþit ise
				{

					cout << "\nHasta TC......: " << TC << "\nHasta adý soyadý.....: " << hasta.Adi << " " << hasta.Soyadi << "\nTelefon.......: " << hasta.Tel << "\nDoðum tarihi..: " << hasta.Dogum_Tar << "\n\nYeni Bilgiler;\n";
					//Güncellenecek hastanýn bilgilerini ekrana yazýlýp
					cout << "Hasta TC......: "; cin >> hasta.Tc;   cin.ignore();             //Yeni bilgiler alýnýyor.
					cout << "Hasta adý.....: "; cin >> hasta.Adi;
					cout << "Hasta soyadý..: "; cin >> hasta.Soyadi; cin.ignore();
					cout << "Telefon.......: "; cin >> hasta.Tel; cin.ignore();
					cout << "Doðum tarihi..: "; cin >> hasta.Dogum_Tar;

					cout << "\t~~Hasta bilgileri güncellendi!~~\n";


					DosyaYaz << hasta.Tc << " " << hasta.Adi << " " << hasta.Soyadi << " " << hasta.Tel << " " << hasta.Dogum_Tar << "\n";
					//Düzenleme.txt'e yenibilgiler yazýlýyor.
				}
				else //Tc dosyadakilerle uyuþmuyorsa
				{

					cout << "Hasta aranýyor\n";
					//Tüm diðer deðerleri yeni düzenleme dosyasýna yazýlýyor.
					DosyaYaz << hasta.Tc << " " << hasta.Adi << " " << hasta.Soyadi << " " << hasta.Tel << " " << hasta.Dogum_Tar << "\n";

					if (DosyaOku.eof())
					{
						cout << "Hasta bulunamadý."; break;
					}
				}

			}
			DosyaOku.close();
			DosyaYaz.close();



			remove("Hasta.txt");     //Hasta.txt i siliniyor
			rename("Düzenleme.txt", "Hasta.txt"); //Düzenleme adlý dosyasýnýn adý hasta olarak deðiþtiriliyor
			remove("Düzenleme.txt"); //düzenleme.txt siliniyor
			break;


		}
		case '3':  //Hasta silme seçeneði
		{

			string TC;          //Kontrol için Tc

			ifstream DosyaOku;
			ofstream DosyaYaz;
			ifstream Dosyaoku;
			ofstream Dosyayaz;

			Dosyaoku.open("Randevu.txt");
			Dosyayaz.open("Düzen.txt", ios::app);  //Randevularý kopyalamak için yeni dosya
			DosyaOku.open("Hasta.txt");            //Hastalarý okumak için açýlýyor.
			DosyaYaz.open("Silme.txt", ios::app);  //Silinmeyecek hastalarý kopyalamak için dosya

			cout << "Hasta TC: "; üç harfli >> TC;
			while (!Dosyaoku.eof())
			{
				Dosyaoku >> hasta.Tc >> randevu.Tarih >> randevu.Saat >> randevu.DK_Adi >> randevu.Teshis >> randevu.Ýlaclar >> randevu.Tahliller;
				//Randevu dosyasýndan bilgileri okunuyor.


				DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				if (DosyaOku.eof())	break; //Dosya sonuna geldiðinde çýkmasý saðlanýyor.


				if (TC == hasta.Tc)        //Eðer silinecek Tc var ise
				{
					cout << "\nHasta TC......: " << TC << "\nHasta adý soyadý.....: " << hasta.Adi << " " << hasta.Soyadi << "\nTelefon.......: " << hasta.Tel << "\nDoðum tarihi..: " << hasta.Dogum_Tar;

					cout << "\n\nHasta TC......: " << TC << "\nRandevu Tarih.....: " << randevu.Tarih << "\nRandevu Saati....:" << randevu.Saat << "\nDoktor Adý......: " << randevu.DK_Adi << "\nTeþhis...: " << randevu.Teshis << "\nÝlaçlar..: " << randevu.Ýlaclar << "\nTahliller...:" << randevu.Tahliller << "\n";

					cout << "\n\nKayýt silindi!\n";

					if (DosyaOku.eof()) break;		//	En son kaydý 2 kere okumamasý için..
				}
				else
				{
					//Eðer Tc ler uyuþmadýysa(Diðer hastalarýn bilgileri) hepsini diðer kopya dosyalara yazýlýyor
					DosyaYaz << hasta.Tc << " " << hasta.Adi << " " << hasta.Soyadi << " " << hasta.Tel << " " << hasta.Dogum_Tar << "\n";

					Dosyayaz << hasta.Tc << " " << randevu.Tarih << " " << randevu.Saat << " " << randevu.DK_Adi << " " << randevu.Teshis << " " << randevu.Ýlaclar << " " << randevu.Tahliller << "\n";

					cout << "Hasta bulunamadý.\n"; break;
				}

			}

			DosyaOku.close();
			DosyaYaz.close();
			Dosyaoku.close();
			Dosyayaz.close();


			remove("Hasta.txt");             //Orjinal dosyalarý silip kopyalarýn adlarý düzenleniyor
			rename("Silme.txt", "Hasta.txt");
			remove("Randevu.txt");
			rename("Düzen.txt", "Randevu.txt");


			break;
		}
		case '4':  //Randevu kayýt seçeneði
		{

			string TC;
			cout << "Hasta TC:";  cin >> TC;

			ifstream DosyaOku("Hasta.txt");

			while (!DosyaOku.eof())
			{
				//Hasta.txt ten bilgiler alýnýyor
				DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				if (TC == hasta.Tc)  //Aradýðýmýz Tc dosyadakiyle eþit ise 
				{
					cout << "Hasta Bilgileri\n";
					cout << "TC no: " << hasta.Tc << endl;
					cout << "Hastanýn Adý Soyadý: " << hasta.Adi << ' ' << hasta.Soyadi << endl;
					cout << "Hastanýn Telefon: " << hasta.Tel << endl;
					cout << "Hasta randevu istiyor mu?(e/h)"; cin >> cevap; cout << endl;
					//Randevu alýp almama kontrolü yapýlýyor
					if (cevap == 'e')
					{
						DosyaOku.close();
						ofstream DosyaYaz;
						DosyaYaz.open("Randevu.txt", ios::app); //Muayene dosyasýný açýlýp
						cout << "\nRandevu Bilgileri" << endl;                     //Randevu bilgileri giriliyor
						cout << "\nRandevu Tarihi (Gün/Ay/Yýl olarak) :  "; cin >> randevu.Tarih;
						cout << "\nRandevu Saati (<__:__> olarak) : "; cin >> randevu.Saat;
						cout << "\nDoktor Adý: "; cin >> randevu.DK_Adi;
						cout << "\nTeþhis: ";  cin >> randevu.Teshis;  cin.ignore();
						cout << "\nÝlaçlar(',' ile ayýrýnýz.) :"; cin >> randevu.Ýlaclar;
						cout << "\nTahliller :"; cin >> randevu.Tahliller;   cin.ignore();

						DosyaYaz << hasta.Tc << ' ' << randevu.Tarih << ' ' << randevu.Saat << ' ' << randevu.DK_Adi << ' ' << randevu.Teshis << ' ' << randevu.Ýlaclar << ' ' << randevu.Tahliller << "\n";
						//Veriler dosyaya yazýlýp ardýndan kapatýlýyorr
						DosyaYaz.close();
						break;
					}
					else //cevap h ise döngüden çýkýlýyor.
					{
						break;
					}
				}
				else
				{


					cout << "... \nHasta aranýyor." << endl; //Tek tek kontrol edilirken verilecek ekran çýktýsý

					cout << "Hasta bulunamadý.\n";
					break;

				}

			}


			break;
		}
		case '5':      //Randevu silme seçeneði
		{

			string TC;
			ifstream DosyaOku;
			ofstream DosyaYaz;
			DosyaOku.open("Randevu.txt");
			DosyaYaz.open("Düzen.txt", ios::app);
			cout << "Hasta TC:"; cin >> TC;

			while (true)
			{
				if (DosyaOku.eof())
				{
					cout << "Dosya sonu.\n"; break;
				}
				DosyaOku >> hasta.Tc >> randevu.Tarih >> randevu.Saat >> randevu.DK_Adi >> randevu.Teshis >> randevu.Ýlaclar >> randevu.Tahliller;
				//Dosyadan Randevu bilgileri okunuyot

				if (TC == hasta.Tc)
				{

					cout << "\nHasta TC......: " << TC << "\nRandevu Tarih.....: " << randevu.Tarih << "\nRandevu Saati....:" << randevu.Saat << "\nDoktor Adý......: " << randevu.DK_Adi << "\nTeþhis...: " << randevu.Teshis << "\nÝlaçlar..: " << randevu.Ýlaclar << "\nTahliller...:" << randevu.Tahliller << "\n";

					cout << "\n\t~~Randevu bilgileri güncellendi!~~\n";

				}
				else  //Eþit tc yi bulamazsa Düzen.txt e yazýyor
				{
					DosyaYaz << hasta.Tc << " " << randevu.Tarih << " " << randevu.Saat << " " << randevu.DK_Adi << " " << randevu.Teshis << " " << randevu.Ýlaclar << " " << randevu.Tahliller << "\n";

					cout << "Randevu bulunamadý.\n";
					break;

				}

			}

			DosyaOku.close();
			DosyaYaz.close();

			remove("Randevu.txt");    //Asýl dosya silinip yedeðin adý deðiþtiriliyor
			rename("Düzen.txt", "Randevu.txt");

			break;
		}
		case '6':   //Randevu düzenleme seçeneði
		{
			string TC;

			ifstream DosyaOku;
			ofstream DosyaYaz;

			DosyaOku.open("Randevu.txt");
			DosyaYaz.open("Düzen.txt", ios::app); //Düzenlenirken kullanýlacak kopya dosya

			cout << "Hasta TC:"; cin >> TC;

			while (true)
			{
				DosyaOku >> hasta.Tc >> randevu.Tarih >> randevu.Saat >> randevu.DK_Adi >> randevu.Teshis >> randevu.Ýlaclar >> randevu.Tahliller;
				//Dosyadan bilgiler okunuyor
				if (DosyaOku.eof())	break; //Eðer dosya sonuna geldiyse iki kere okumasýn diye çýkýþ

				if (TC == hasta.Tc)
				{

					cout << "\nHasta TC......: " << TC << "\nRandevu Tarih.....: " << randevu.Tarih << "\nRandevu Saati....:" << randevu.Saat << "\nDoktor Adý......: " << randevu.DK_Adi << "\nTeþhis...: " << randevu.Teshis << "\nÝlaçlar..: " << randevu.Ýlaclar << "\nTahliller...:" << randevu.Tahliller << "\n";
					//Dosyadan sileceðimiz randevu ekrana yazdýrýlýp
					//Yeni bilgiler isteniyor
					cout << "\n ~~Yeni Bilgiler~~ \n";
					cout << "Randevu Tarih.....: "; cin >> randevu.Tarih;
					cout << "Randevu Saati....:"; cin >> randevu.Saat;
					cout << "Doktor Adý......: "; cin >> randevu.DK_Adi;
					cout << "Teþhis...: "; cin >> randevu.Teshis;
					cout << "Ýlaçlar..: "; cin >> randevu.Ýlaclar;
					cout << "Tahliller...:"; cin >> randevu.Tahliller;
					cout << "\n\t~~Randevu bilgileri güncellendi!~~\n";

					DosyaYaz << hasta.Tc << " " << randevu.Tarih << " " << randevu.Saat << " " << randevu.DK_Adi << " " << randevu.Teshis << randevu.Ýlaclar << randevu.Tahliller << "\n";
					//Yeni bilgilerimizi kopya dosyaya(Düzen.txt) yazýyoruz
				}
				else
				{		//Tc'si tutmayan diðer randevular yedek dosyaya yazýlýyor
					DosyaYaz << hasta.Tc << " " << randevu.Tarih << " " << randevu.Saat << " " << randevu.DK_Adi << " " << randevu.Teshis << randevu.Ýlaclar << randevu.Tahliller << "\n";
				}
			}
			DosyaOku.close();
			DosyaYaz.close();

			remove("Randevu.txt");        //Dosyalarý kapatýp isimleri deðiþtiriliyor
			rename("Düzen.txt", "Randevu.txt");

			break;
		}
		case '7':  //Hasta sorgulama seçeneði
		{

			string TC;
			cout << "Hasta TC:";  cin >> TC;

			ifstream DosyaOku("Hasta.txt");

			while (!DosyaOku.eof())
			{
				DosyaOku >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				//Dosyadan bilgiler okunuyor

				if (TC == hasta.Tc)  //Hasta bulunursa ekrana yazdýrýyoruz
				{
					cout << "\n---====Hasta Bilgileri====---\n";
					cout << "\nTC no: " << setw(25) << hasta.Tc << endl;
					cout << "Hastanýn Adý Soyadý: " << setw(2) << hasta.Adi << ' ' << hasta.Soyadi << endl;
					cout << "Hastanýn Telefon: " << setw(14) << hasta.Tel << endl;
					cout << "Doðum Tarihi: " << setw(17) << hasta.Dogum_Tar << endl;
					break;
				}

				else
				{
					cout << "Hasta bulunamadý.\n";
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
				if (Dosyaoku.eof())  //Dosya sonuna geldiyse son satýr iki kere okunmasýn diye çýkýþ
				{
					break;
				}
				cout << "\n\n---====Hasta Bilgileri====---\n";
				cout << "\nTC no: " << setw(25) << hasta.Tc << endl;
				cout << "Hastanýn Adý Soyadý: " << setw(2) << hasta.Adi << ' ' << hasta.Soyadi << endl;
				cout << "Hastanýn Telefon: " << setw(14) << hasta.Tel << endl;

			}
			Dosyaoku.close();
			cout << endl;
			break;
		}
		case '9': //Randevu arama seçeneði
		{

			string TC;
			cout << " Hasta TC no giriniz:"; cin >> TC;
			ifstream DosyaAc("Hasta.txt");

			while (!(DosyaAc.eof()))  //Hasta dosyasýnýn sonuna kadar dönüyor
			{
				DosyaAc >> hasta.Tc >> hasta.Adi >> hasta.Soyadi >> hasta.Tel >> hasta.Dogum_Tar;
				//Dosyadan bilgiler okunuyor
				if (TC == hasta.Tc)  //Eðer Tc uyuþursa bilgiler ekrana yazdýrýlýyor
				{
					cout << "\nHasta Bilgileri\n\n";
					cout << "TC no: " << hasta.Tc << endl;
					cout << "Hastanýn Adý Soyadý: " << hasta.Adi << ' ' << hasta.Soyadi << endl;
					cout << "Hastanýn Telefon: " << hasta.Tel << endl;
					cout << "Hasta Doðum Tarihi: " << hasta.Dogum_Tar << endl;

					DosyaAc.close();  //Hasta dosyasý kullanýlmayacaðý için kapatýlýyor
					ofstream DosyaYaz;
					DosyaAc.open("Randevu.txt", ios::in);  //Muayene dosyasýný açýlýyor

					cout << "\n Randevu Bilgileri  \n" << endl;

					cout << setw(8) << "      TC       " << setw(6) << " Tarih" << setw(12) << "Saat" << setw(18) << "Doktor Adý" << setw(12) << " Teþhis " << setw(17) << "Ýlaçlar" << setw(18) << "Tahliller" << endl;
					while (!DosyaAc.eof())  //Döngü baþlangýcý randevu dosyasý için
					{
						//Dosyadan veriler okunuyor
						DosyaAc >> hasta.Tc >> randevu.Tarih >> randevu.Saat >> randevu.DK_Adi >> randevu.Teshis >> randevu.Ýlaclar >> randevu.Tahliller;
						if (hasta.Tc == TC) //Eðer Hastanýn randevusu varsa ekrana yazdýrýlýyor
						{

							cout << setw(13) << hasta.Tc << setw(7) << '  ' << randevu.Tarih << setw(9) << randevu.Saat << setw(15) << randevu.DK_Adi << setw(16) << randevu.Teshis << setw(14) << randevu.Ýlaclar << setw(17) << randevu.Tahliller << endl;

						}
					}
					DosyaYaz.close();
					break;
				}
				else
				{

					cout << "Randevu bulunamadý.\n";
					break;

				}

			}

		}
		break;

		case '0':  //Menü Çýkýþ seçeneði
		{
			return 0;//Çýkýþ
		}break;

		default:
		{
			cout << "Hatalý seçenek!" << endl;
		}break;
		}
	} while (secim !=0); //Menü do while döngüsünün sonu
	system("pause");
	return 0;
}