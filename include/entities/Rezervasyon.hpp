#ifndef REZERVASYON_HPP
#define REZERVASYON_HPP

#include <string>

class Rezervasyon {
private:
    int _id;
    int _kitap_id;
    int _uye_id;
    std::string _rezervasyon_tarihi;
    std::string _durum;

public:
    Rezervasyon();
    Rezervasyon(int id, int kitap_id, int uye_id,
                const std::string& rezervasyon_tarihi, const std::string& durum);
    Rezervasyon(const Rezervasyon& other);
    ~Rezervasyon();

    int get_id() const;
    int get_kitap_id() const;
    int get_uye_id() const;
    std::string get_rezervasyon_tarihi() const;
    std::string get_durum() const;

    void set_durum(const std::string& durum);
    void set_id(int id) { _id = id; }
};

#endif