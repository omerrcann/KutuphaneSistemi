#include <iostream>
#include <string>
#include <limits>
#include <memory>

#include "services/KutuphaneServisi.hpp"
#include "repositories/Depo.hpp"
#include "utils/TarihUtils.h"
#include "entities/Kitap.hpp"
#include "entities/Yazar.hpp"
#include "entities/Kategori.hpp"
#include "entities/Yayinevi.hpp"
#include "entities/Uye.hpp"


void ekraniTemizle() {

    for (int i = 0; i < 5; i++) {
        std::cout << "\n";
    }
}

void baslikYaz(const std::string& baslik) {
    ekraniTemizle();
    std::cout << "==========================================" << "\n";
    std::cout << "   " << baslik << "\n";
    std::cout << "==========================================" << "\n\n";
}

void devamEtmekIcinBekle() {
    std::cout << "\n>> Devam etmek icin Enter'a basin...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}


void demoVeriYukle(KutuphaneServisi& servis,
                   Depo<Kitap>& , Depo<Yazar>& yDepo,
                   Depo<Kategori>& katDepo, Depo<Yayinevi>& yayDepo, Depo<Uye>& ) {

    std::cout << "Sistem baslatiliyor... Demo veriler yukleniyor...\n";

    // 1. Yazarlar
    auto yazar1 = std::make_shared<Yazar>(1, "J.K. Rowling", 1965, "Ingiltere");
    auto yazar2 = std::make_shared<Yazar>(2, "George Orwell", 1903, "Ingiltere");
    yDepo.ekle(yazar1);
    yDepo.ekle(yazar2);

    // 2. Kategoriler (ID: 1, 2)
    auto kat1 = std::make_shared<Kategori>(1, "Fantastik", "Buyu ve macera");
    auto kat2 = std::make_shared<Kategori>(2, "Distopya", "Karanlik gelecek");
    katDepo.ekle(kat1);
    katDepo.ekle(kat2);

    // 3. Yayınevleri (ID: 1)
    auto yay1 = std::make_shared<Yayinevi>(1, "Yapi Kredi", "Istanbul", "555-1234");
    yayDepo.ekle(yay1);

    // 4. Kitaplar
    try {
        servis.kitapEkle("978-1", "Harry Potter", yazar1->get_id(), kat1->get_id(), yay1->get_id(), 3, 350);
        servis.kitapEkle("978-2", "1984", yazar2->get_id(), kat2->get_id(), yay1->get_id(), 5, 200);

        // 5. Üyeler
        servis.uyeKaydet("11111111111", "Ahmet Yilmaz", "ahmet@mail.com", "555-9999");
        servis.uyeKaydet("22222222222", "Ayse Demir", "ayse@mail.com", "555-8888");

        std::cout << "Veriler basariyla yuklendi.\n";
    } catch (const std::exception& e) {
        std::cout << "Demo veri yukleme hatasi: " << e.what() << "\n";
    }
}

int main() {
    Depo<Kitap> kitapDepo;
    Depo<Yazar> yazarDepo;
    Depo<Kategori> kategoriDepo;
    Depo<Yayinevi> yayineviDepo;
    Depo<Uye> uyeDepo;
    Depo<OduncAlma> oduncDepo;
    Depo<Rezervasyon> rezervasyonDepo;

    KutuphaneServisi servis(
            kitapDepo, yazarDepo, kategoriDepo, yayineviDepo,
            uyeDepo, oduncDepo, rezervasyonDepo
    );

// Demo Veriler
    demoVeriYukle(servis, kitapDepo, yazarDepo, kategoriDepo, yayineviDepo, uyeDepo);

    int secim = 0;
    while (true) {
        ekraniTemizle();
        std::cout << "==========================================" << "\n";
        std::cout << "   KUTUPHANE YONETIM SISTEMI" << "\n";
        std::cout << "==========================================" << "\n";
        std::cout << " [1] Kitap Ekle\n";
        std::cout << " [2] Kitap Ara / Durum Sorgula\n";
        std::cout << " [3] Uye Kaydet\n";
        std::cout << " [4] Kitap Odunc Ver\n";
        std::cout << " [5] Kitap Iade Al\n";
        std::cout << " [6] Rezervasyon Yap\n";
        std::cout << " [7] Rezervasyon Iptal\n";
        std::cout << " [8] Gecikmis Kitaplar\n";
        std::cout << " [9] Uye Gecmisi\n";
        std::cout << " [10] Populer Kitaplar\n";
        std::cout << " [11] Uye Ceza Hesapla\n";
        std::cout << " [0] Cikis\n";
        std::cout << "==========================================" << "\n";
        std::cout << "Seciminiz: ";

        if (!(std::cin >> secim)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        try {
            switch (secim) {
                case 1: {
                    baslikYaz("KITAP EKLEME");
                    std::string isbn, baslik;
                    int yId, kId, yayId, stok, sayfa;
                    std::cout << "ISBN: "; std::cin >> isbn;
                    std::cin.ignore();
                    std::cout << "Baslik: "; std::getline(std::cin, baslik);
                    std::cout << "Yazar ID: "; std::cin >> yId;
                    std::cout << "Kategori ID: "; std::cin >> kId;
                    std::cout << "Yayinevi ID: "; std::cin >> yayId;
                    std::cout << "Stok: "; std::cin >> stok;
                    std::cout << "Sayfa: "; std::cin >> sayfa;

                    servis.kitapEkle(isbn, baslik, yId, kId, yayId, stok, sayfa);
                    std::cout << "\n[Basarili] Kitap eklendi.\n";
                    break;
                }
                case 2: {
                    baslikYaz("KITAP ARAMA");
                    std::string kelime;
                    std::cout << "Aranacak kelime (Baslik/ISBN): ";
                    std::cin >> kelime;
                    auto sonuclar = servis.kitapAra(kelime);

                    if (sonuclar.empty()) {
                        std::cout << "Hicbir kayit bulunamadi.\n";
                    } else {
                        std::cout << "\nBulunan Kitaplar:\n";
                        for (const auto& k : sonuclar) {
                            std::cout << "ID: " << k->get_id()
                                      << " | Baslik: " << k->get_baslik()
                                      << " | Stok: " << k->get_stok_adedi() << "\n";
                        }
                    }
                    break;
                }
                case 3: {
                    baslikYaz("UYE KAYIT");
                    std::string tc, ad, mail, tel;
                    std::cout << "TC No: "; std::cin >> tc;
                    std::cin.ignore();
                    std::cout << "Ad Soyad: "; std::getline(std::cin, ad);
                    std::cout << "Email: "; std::cin >> mail;
                    std::cout << "Telefon: "; std::cin >> tel;

                    servis.uyeKaydet(tc, ad, mail, tel);
                    std::cout << "\n[Basarili] Uye kaydedildi.\n";
                    break;
                }
                case 4: {
                    baslikYaz("ODUNC VERME");
                    int kId, uId;
                    std::cout << "Kitap ID: "; std::cin >> kId;
                    std::cout << "Uye ID: "; std::cin >> uId;
                    servis.kitapOduncVer(kId, uId);
                    std::cout << "\n[Basarili] Kitap odunc verildi. Iade suresi 14 gun.\n";
                    break;
                }
                case 5: {
                    baslikYaz("IADE ALMA");
                    int oId;
                    std::cout << "Odunc Islem ID: "; std::cin >> oId;
                    servis.kitapIadeAl(oId);
                    std::cout << "\n[Basarili] Kitap iade alindi ve stok guncellendi.\n";
                    break;
                }
                case 6: {
                    baslikYaz("REZERVASYON YAP");
                    int kId, uId;
                    std::cout << "Kitap ID: "; std::cin >> kId;
                    std::cout << "Uye ID: "; std::cin >> uId;
                    servis.rezervasyonYap(kId, uId);
                    std::cout << "\n[Basarili] Rezervasyon olusturuldu.\n";
                    break;
                }
                case 7: {
                    baslikYaz("REZERVASYON IPTAL");
                    int rId;
                    std::cout << "Rezervasyon ID: "; std::cin >> rId;
                    servis.rezervasyonIptal(rId);
                    std::cout << "\n[Basarili] Rezervasyon iptal edildi.\n";
                    break;
                }
                case 8: {
                    baslikYaz("GECIKMIS KITAPLAR");
                    auto liste = servis.gecikmisKitaplariGetir();
                    if (liste.empty()) {
                        std::cout << "Gecikmis kitap bulunmuyor.\n";
                    } else {
                        for (const auto& o : liste) {
                            std::cout << "Odunc ID: " << o->get_id()
                                      << " | Uye ID: " << o->get_uye_id()
                                      << " | Iade Tarihi: " << o->get_iade_tarihi() << "\n";
                        }
                    }
                    break;
                }
                case 9: {
                    baslikYaz("UYE GECMISI");
                    int uId;
                    std::cout << "Uye ID: "; std::cin >> uId;
                    auto gecmis = servis.uyeOduncGecmisiGetir(uId);
                    for (const auto& o : gecmis) {
                        std::string durum = o->get_gercek_iade_tarihi().empty() ? "Okuyor" : "Iade Etti";
                        std::cout << "Kitap ID: " << o->get_kitap_id()
                                  << " | Tarih: " << o->get_odunc_tarihi()
                                  << " | Durum: " << durum << "\n";
                    }
                    break;
                }
                case 10: {
                    baslikYaz("POPULER KITAPLAR");
                    int n;
                    std::cout << "Kac kitap listelensin: "; std::cin >> n;
                    auto populer = servis.enCokOkunanKitaplar(n);
                    for (const auto& k : populer) {
                        std::cout << "Kitap: " << k->get_baslik() << " (ISBN: " << k->get_isbn() << ")\n";
                    }
                    break;
                }
                case 11: {
                    baslikYaz("UYE CEZA SORGULAMA");
                    int uId;
                    std::cout << "Uye ID: "; std::cin >> uId;
                    double ceza = servis.uyeCezaHesapla(uId);
                    if (ceza > 0) {
                        std::cout << "\nToplam Gecikme Cezasi: " << ceza << " TL\n";
                    } else {
                        std::cout << "\nUyenin gecikme cezasi bulunmuyor.\n";
                    }
                    break;
                }
                case 0:
                    std::cout << "Cikis yapiliyor...\n";
                    return 0;
                default:
                    std::cout << "Gecersiz secim!\n";
            }
        } catch (const std::exception& e) {
            std::cout << "\n[HATA] " << e.what() << "\n";
        }

        devamEtmekIcinBekle();
    }

}