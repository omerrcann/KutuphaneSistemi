#include "Uye.hpp"

Uye::Uye() : _id(0) {}

Uye::Uye(int id, const std::string& tc_no, const std::string& ad_soyad,
         const std::string& email, const std::string& telefon, const std::string& kayit_tarihi)
        : _id(id), _tc_no(tc_no), _ad_soyad(ad_soyad),
          _email(email), _telefon(telefon), _kayit_tarihi(kayit_tarihi) {}

Uye::Uye(const Uye& other)
        : _id(other._id), _tc_no(other._tc_no), _ad_soyad(other._ad_soyad),
          _email(other._email), _telefon(other._telefon), _kayit_tarihi(other._kayit_tarihi) {}

Uye::~Uye() {}

int Uye::get_id() const { return _id; }
std::string Uye::get_tc_no() const { return _tc_no; }
std::string Uye::get_ad_soyad() const { return _ad_soyad; }
std::string Uye::get_email() const { return _email; }
std::string Uye::get_telefon() const { return _telefon; }
std::string Uye::get_kayit_tarihi() const { return _kayit_tarihi; }