#include "Yazar.hpp"

Yazar::Yazar() : _id(0), _dogum_yili(0) {}

Yazar::Yazar(int id, const std::string& ad_soyad, int dogum_yili, const std::string& ulke)
        : _id(id), _ad_soyad(ad_soyad), _dogum_yili(dogum_yili), _ulke(ulke) {}

Yazar::Yazar(const Yazar& other)
        : _id(other._id), _ad_soyad(other._ad_soyad), _dogum_yili(other._dogum_yili), _ulke(other._ulke) {}

Yazar::~Yazar() {}

int Yazar::get_id() const { return _id; }
std::string Yazar::get_ad_soyad() const { return _ad_soyad; }
int Yazar::get_dogum_yili() const { return _dogum_yili; }
std::string Yazar::get_ulke() const { return _ulke; }