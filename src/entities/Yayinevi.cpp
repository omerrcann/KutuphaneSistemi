#include "Yayinevi.hpp"

Yayinevi::Yayinevi() : _id(0) {}

Yayinevi::Yayinevi(int id, const std::string& ad, const std::string& adres, const std::string& telefon)
        : _id(id), _ad(ad), _adres(adres), _telefon(telefon) {}

Yayinevi::Yayinevi(const Yayinevi& other)
        : _id(other._id), _ad(other._ad), _adres(other._adres), _telefon(other._telefon) {}

Yayinevi::~Yayinevi() {}

int Yayinevi::get_id() const { return _id; }
std::string Yayinevi::get_ad() const { return _ad; }
std::string Yayinevi::get_adres() const { return _adres; }
std::string Yayinevi::get_telefon() const { return _telefon; }