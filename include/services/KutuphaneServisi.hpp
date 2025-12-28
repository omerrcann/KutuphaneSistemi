#ifndef KUTUPHANE_SERVISI_HPP
#define KUTUPHANE_SERVISI_HPP

#include <memory>
#include <vector>
#include <string>

#include "../repositories/Depo.hpp"
#include "../entities/Kitap.hpp"
#include "../entities/Yazar.hpp"
#include "../entities/Kategori.hpp"
#include "../entities/Yayinevi.hpp"
#include "../entities/Uye.hpp"
#include "../entities/OduncAlma.hpp"
#include "../entities/Rezervasyon.hpp"

class KutuphaneServisi {
private:
    Depo<Kitap>& _kitapDepo;
    Depo<Yazar>& _yazarDepo;
    Depo<Kategori>& _kategoriDepo;
    Depo<Yayinevi>& _yayineviDepo;
    Depo<Uye>& _uyeDepo;
    Depo<OduncAlma>& _oduncDepo;
    Depo<Rezervasyon>& _rezervasyonDepo;

public:
    KutuphaneServisi(
            Depo<Kitap>& kitapDepo,
            Depo<Yazar>& yazarDepo,
            Depo<Kategori>& kategoriDepo,
            Depo<Yayinevi>& yayineviDepo,
            Depo<Uye>& uyeDepo,
            Depo<OduncAlma>& oduncDepo,
            Depo<Rezervasyon>& rezervasyonDepo
    );

    ~KutuphaneServisi() = default;

    // --- TEMEL İŞLEMLER ---
    void kitapEkle(const std::string& isbn, const std::string& baslik,
                   int yazar_id, int kategori_id, int yayinevi_id,
                   int stok_adedi, int sayfa_sayisi);

    void uyeKaydet(const std::string& tc_no, const std::string& ad_soyad,
                   const std::string& email, const std::string& telefon);

    // --- ÖDÜNÇ İŞLEMLERİ ---
    void kitapOduncVer(int kitap_id, int uye_id);
    void kitapIadeAl(int odunc_id);

    // --- REZERVASYON İŞLEMLERİ ---
    void rezervasyonYap(int kitap_id, int uye_id);
    void rezervasyonIptal(int rezervasyon_id);

    // --- SORGULAMA VE RAPORLAMA ---
    std::vector<std::shared_ptr<OduncAlma>> gecikmisKitaplariGetir();
    std::vector<std::shared_ptr<OduncAlma>> uyeOduncGecmisiGetir(int uye_id);
    std::vector<std::shared_ptr<Kitap>> kitapAra(const std::string& anahtar_kelime);
    std::vector<std::shared_ptr<Kitap>> enCokOkunanKitaplar(int limit);
    double uyeCezaHesapla(int uye_id);
};

#endif