#include "Kategori.hpp"

Kategori::Kategori() : _id(0) {}

Kategori::Kategori(int id, const std::string& ad, const std::string& aciklama)
        : _id(id), _ad(ad), _aciklama(aciklama) {}

Kategori::Kategori(const Kategori& other)
        : _id(other._id), _ad(other._ad), _aciklama(other._aciklama) {}

Kategori::~Kategori() {}

int Kategori::get_id() const { return _id; }
std::string Kategori::get_ad() const { return _ad; }
std::string Kategori::get_aciklama() const { return _aciklama; }