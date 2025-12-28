#ifndef YAYINEVI_HPP
#define YAYINEVI_HPP

#include <string>

class Yayinevi {
private:
    int _id;
    std::string _ad;
    std::string _adres;
    std::string _telefon;

public:
    Yayinevi();
    Yayinevi(int id, const std::string& ad, const std::string& adres, const std::string& telefon);
    Yayinevi(const Yayinevi& other);
    ~Yayinevi();

    int get_id() const;
    std::string get_ad() const;
    std::string get_adres() const;
    std::string get_telefon() const;
    void set_id(int id) { _id = id; }
};

#endif