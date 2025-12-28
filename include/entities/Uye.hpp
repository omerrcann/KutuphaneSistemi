#ifndef UYE_HPP
#define UYE_HPP

#include <string>

class Uye {
private:
    int _id;
    std::string _tc_no;
    std::string _ad_soyad;
    std::string _email;
    std::string _telefon;
    std::string _kayit_tarihi;

public:
    Uye();
    Uye(int id, const std::string& tc_no, const std::string& ad_soyad,
        const std::string& email, const std::string& telefon, const std::string& kayit_tarihi);
    Uye(const Uye& other);
    ~Uye();

    int get_id() const;
    std::string get_tc_no() const;
    std::string get_ad_soyad() const;
    std::string get_email() const;
    std::string get_telefon() const;
    std::string get_kayit_tarihi() const;
    void set_id(int id) { _id = id; }
};

#endif