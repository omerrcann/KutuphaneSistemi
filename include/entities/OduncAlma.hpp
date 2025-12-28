#ifndef ODUNCALMA_HPP
#define ODUNCALMA_HPP

#include <string>

class OduncAlma {
private:
    int _id;
    int _kitap_id;
    int _uye_id;
    std::string _odunc_tarihi;
    std::string _iade_tarihi;
    std::string _gercek_iade_tarihi;

public:
    OduncAlma();
    OduncAlma(int id, int kitap_id, int uye_id,
              const std::string& odunc_tarihi, const std::string& iade_tarihi,
              const std::string& gercek_iade_tarihi = "");
    OduncAlma(const OduncAlma& other);
    ~OduncAlma();

    int get_id() const;
    int get_kitap_id() const;
    int get_uye_id() const;
    std::string get_odunc_tarihi() const;
    std::string get_iade_tarihi() const;
    std::string get_gercek_iade_tarihi() const;

    void set_gercek_iade_tarihi(const std::string& tarih);
    void set_id(int id) { _id = id; }
};

#endif