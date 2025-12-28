#include "KutuphaneServisi.hpp"
#include "../utils/TarihUtils.h"
#include <stdexcept>
#include <algorithm>
#include <map>
#include <iostream>


KutuphaneServisi::KutuphaneServisi(
        Depo<Kitap>& kitapDepo,
        Depo<Yazar>& yazarDepo,
        Depo<Kategori>& kategoriDepo,
        Depo<Yayinevi>& yayineviDepo,
        Depo<Uye>& uyeDepo,
        Depo<OduncAlma>& oduncDepo,
        Depo<Rezervasyon>& rezervasyonDepo
) : _kitapDepo(kitapDepo),
    _yazarDepo(yazarDepo),
    _kategoriDepo(kategoriDepo),
    _yayineviDepo(yayineviDepo),
    _uyeDepo(uyeDepo),
    _oduncDepo(oduncDepo),
    _rezervasyonDepo(rezervasyonDepo)
{
}

// ==================== TEMEL İŞLEMLER ====================

void KutuphaneServisi::kitapEkle(const std::string& isbn, const std::string& baslik,
                                 int yazar_id, int kategori_id, int yayinevi_id,
                                 int stok_adedi, int sayfa_sayisi) {
    auto mevcut = _kitapDepo.ara([&isbn](const std::shared_ptr<Kitap>& k) {
        return k->get_isbn() == isbn;
    });

    if (!mevcut.empty()) {
        throw std::runtime_error("Bu ISBN numarasina sahip kitap zaten kayitli!");
    }

    try {
        _yazarDepo.getir(yazar_id);
        _kategoriDepo.getir(kategori_id);
        _yayineviDepo.getir(yayinevi_id);
    } catch (...) {
        throw std::runtime_error("Gecersiz Yazar, Kategori veya Yayinevi ID'si!");
    }

    auto yeniKitap = std::make_shared<Kitap>(0, isbn, baslik, yazar_id, kategori_id, yayinevi_id, stok_adedi, sayfa_sayisi);
    _kitapDepo.ekle(yeniKitap);
}

void KutuphaneServisi::uyeKaydet(const std::string& tc_no, const std::string& ad_soyad,
                                 const std::string& email, const std::string& telefon) {
    auto mevcut = _uyeDepo.ara([&tc_no](const std::shared_ptr<Uye>& u) {
        return u->get_tc_no() == tc_no;
    });

    if (!mevcut.empty()) {
        throw std::runtime_error("Bu TC numarasina sahip uye zaten kayitli!");
    }

    std::string bugun = TarihUtils::bugunTarihi();
    auto yeniUye = std::make_shared<Uye>(0, tc_no, ad_soyad, email, telefon, bugun);
    _uyeDepo.ekle(yeniUye);
}

// ==================== ÖDÜNÇ İŞLEMLERİ ====================

void KutuphaneServisi::kitapOduncVer(int kitap_id, int uye_id) {

    auto kitap = _kitapDepo.getir(kitap_id);
    auto uye = _uyeDepo.getir(uye_id);


    if (kitap->get_stok_adedi() <= 0) {
        throw std::runtime_error("Kitap stokta yok! Odunc verilemez.");
    }


    kitap->set_stok_adedi(kitap->get_stok_adedi() - 1);
    _kitapDepo.guncelle(kitap);


    std::string bugun = TarihUtils::bugunTarihi();
    std::string iadeTarihi = TarihUtils::gunEkle(bugun, 14);

    auto odunc = std::make_shared<OduncAlma>(0, kitap_id, uye_id, bugun, iadeTarihi, "");
    _oduncDepo.ekle(odunc);
}

void KutuphaneServisi::kitapIadeAl(int odunc_id) {
    auto odunc = _oduncDepo.getir(odunc_id);

    if (odunc->get_gercek_iade_tarihi() != "") {
        throw std::runtime_error("Bu kitap zaten iade edilmis!");
    }

    std::string bugun = TarihUtils::bugunTarihi();
    odunc->set_gercek_iade_tarihi(bugun);
    _oduncDepo.guncelle(odunc);

    try {
        auto kitap = _kitapDepo.getir(odunc->get_kitap_id());
        kitap->set_stok_adedi(kitap->get_stok_adedi() + 1);
        _kitapDepo.guncelle(kitap);
    } catch (...) {

    }
}

// ==================== REZERVASYON İŞLEMLERİ ====================

void KutuphaneServisi::rezervasyonYap(int kitap_id, int uye_id) {
    _kitapDepo.getir(kitap_id);
    _uyeDepo.getir(uye_id);

    std::string bugun = TarihUtils::bugunTarihi();
    auto rezervasyon = std::make_shared<Rezervasyon>(0, kitap_id, uye_id, bugun, "Aktif");
    _rezervasyonDepo.ekle(rezervasyon);
}

void KutuphaneServisi::rezervasyonIptal(int rezervasyon_id) {
    auto rez = _rezervasyonDepo.getir(rezervasyon_id);
    rez->set_durum("Iptal");
    _rezervasyonDepo.guncelle(rez);
}

// ==================== SORGULAMA VE RAPORLAMA ====================

std::vector<std::shared_ptr<OduncAlma>> KutuphaneServisi::gecikmisKitaplariGetir() {
    std::string bugun = TarihUtils::bugunTarihi();

    return _oduncDepo.ara([&bugun](const std::shared_ptr<OduncAlma>& o) {

        if (o->get_gercek_iade_tarihi() != "") return false;

        int fark = TarihUtils::gunFarki(bugun, o->get_iade_tarihi());
        return fark < 0;
    });
}

std::vector<std::shared_ptr<OduncAlma>> KutuphaneServisi::uyeOduncGecmisiGetir(int uye_id) {
    return _oduncDepo.ara([uye_id](const std::shared_ptr<OduncAlma>& o) {
        return o->get_uye_id() == uye_id;
    });
}

std::vector<std::shared_ptr<Kitap>> KutuphaneServisi::kitapAra(const std::string& anahtar_kelime) {
    return _kitapDepo.ara([&anahtar_kelime](const std::shared_ptr<Kitap>& k) {
        std::string baslik = k->get_baslik();
        std::string isbn = k->get_isbn();

        return (baslik.find(anahtar_kelime) != std::string::npos) ||
               (isbn.find(anahtar_kelime) != std::string::npos);
    });
}

std::vector<std::shared_ptr<Kitap>> KutuphaneServisi::enCokOkunanKitaplar(int limit) {
    std::map<int, int> sayac;
    auto tumOduncler = _oduncDepo.tumunu();

    for (const auto& o : tumOduncler) {
        sayac[o->get_kitap_id()]++;
    }

    std::vector<std::pair<int, int>> sirali(sayac.begin(), sayac.end());

    std::sort(sirali.begin(), sirali.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    std::vector<std::shared_ptr<Kitap>> sonuc;
    int count = 0;
    for (const auto& p : sirali) {
        if (count >= limit) break;
        try {
            sonuc.push_back(_kitapDepo.getir(p.first));
            count++;
        } catch (...) {
        }
    }
    return sonuc;
}

double KutuphaneServisi::uyeCezaHesapla(int uye_id) {
    double toplamCeza = 0.0;
    std::string bugun = TarihUtils::bugunTarihi();
    double gunlukCeza = 1.0;

    auto uyeOduncleri = uyeOduncGecmisiGetir(uye_id);

    for (const auto& o : uyeOduncleri) {
        if (o->get_gercek_iade_tarihi() == "") {
            int gecikmeGun = TarihUtils::gunFarki(o->get_iade_tarihi(), bugun);

            if (gecikmeGun > 0) {
                toplamCeza += (gecikmeGun * gunlukCeza);
            }
        }
    }
    return toplamCeza;
}