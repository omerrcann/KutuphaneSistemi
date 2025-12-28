#ifndef KATEGORI_HPP
#define KATEGORI_HPP

#include <string>

class Kategori {
private:
    int _id;
    std::string _ad;
    std::string _aciklama;

public:
    Kategori();
    Kategori(int id, const std::string& ad, const std::string& aciklama);
    Kategori(const Kategori& other);
    ~Kategori();

    int get_id() const;
    std::string get_ad() const;
    std::string get_aciklama() const;
    void set_id(int id) { _id = id; }
};

#endif