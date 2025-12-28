#ifndef YAZAR_HPP
#define YAZAR_HPP

#include <string>

class Yazar {
private:
    int _id;
    std::string _ad_soyad;
    int _dogum_yili;
    std::string _ulke;

public:
    Yazar();
    Yazar(int id, const std::string& ad_soyad, int dogum_yili, const std::string& ulke);
    Yazar(const Yazar& other);
    ~Yazar();

    int get_id() const;
    std::string get_ad_soyad() const;
    int get_dogum_yili() const;
    std::string get_ulke() const;
    void set_id(int id) { _id = id; }
};

#endif