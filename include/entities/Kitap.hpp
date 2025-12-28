#ifndef KITAP_HPP
#define KITAP_HPP

#include <string>

class Kitap {
private:
    int _id;
    std::string _isbn;
    std::string _baslik;
    int _yazar_id;
    int _kategori_id;
    int _yayinevi_id;
    int _stok_adedi;
    int _sayfa_sayisi;

public:
    Kitap();
    Kitap(int id, const std::string& isbn, const std::string& baslik,
          int yazar_id, int kategori_id, int yayinevi_id,
          int stok_adedi, int sayfa_sayisi);
    Kitap(const Kitap& other);
    ~Kitap();

    int get_id() const;

    std::string get_isbn() const;
    std::string get_baslik() const;
    int get_yazar_id() const;
    int get_kategori_id() const;
    int get_yayinevi_id() const;
    int get_stok_adedi() const;
    int get_sayfa_sayisi() const;

    void set_stok_adedi(int stok);
    void set_id(int id) { _id = id; }
};

#endif