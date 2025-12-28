#include "Kitap.hpp"

Kitap::Kitap() : _id(0), _yazar_id(0), _kategori_id(0), _yayinevi_id(0), _stok_adedi(0), _sayfa_sayisi(0) {}

Kitap::Kitap(int id, const std::string& isbn, const std::string& baslik,
             int yazar_id, int kategori_id, int yayinevi_id,
             int stok_adedi, int sayfa_sayisi)
        : _id(id), _isbn(isbn), _baslik(baslik),
          _yazar_id(yazar_id), _kategori_id(kategori_id), _yayinevi_id(yayinevi_id),
          _stok_adedi(stok_adedi), _sayfa_sayisi(sayfa_sayisi) {}

Kitap::Kitap(const Kitap& other)
        : _id(other._id), _isbn(other._isbn), _baslik(other._baslik),
          _yazar_id(other._yazar_id), _kategori_id(other._kategori_id), _yayinevi_id(other._yayinevi_id),
          _stok_adedi(other._stok_adedi), _sayfa_sayisi(other._sayfa_sayisi) {}

Kitap::~Kitap() {}

int Kitap::get_id() const { return _id; }
std::string Kitap::get_isbn() const { return _isbn; }
std::string Kitap::get_baslik() const { return _baslik; }
int Kitap::get_yazar_id() const { return _yazar_id; }
int Kitap::get_kategori_id() const { return _kategori_id; }
int Kitap::get_yayinevi_id() const { return _yayinevi_id; }
int Kitap::get_stok_adedi() const { return _stok_adedi; }
int Kitap::get_sayfa_sayisi() const { return _sayfa_sayisi; }

void Kitap::set_stok_adedi(int stok) { _stok_adedi = stok; }