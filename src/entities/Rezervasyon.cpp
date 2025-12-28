#include "Rezervasyon.hpp"

Rezervasyon::Rezervasyon() : _id(0), _kitap_id(0), _uye_id(0) {}

Rezervasyon::Rezervasyon(int id, int kitap_id, int uye_id,
                         const std::string& rezervasyon_tarihi, const std::string& durum)
        : _id(id), _kitap_id(kitap_id), _uye_id(uye_id),
          _rezervasyon_tarihi(rezervasyon_tarihi), _durum(durum) {}

Rezervasyon::Rezervasyon(const Rezervasyon& other)
        : _id(other._id), _kitap_id(other._kitap_id), _uye_id(other._uye_id),
          _rezervasyon_tarihi(other._rezervasyon_tarihi), _durum(other._durum) {}

Rezervasyon::~Rezervasyon() {}

int Rezervasyon::get_id() const { return _id; }
int Rezervasyon::get_kitap_id() const { return _kitap_id; }
int Rezervasyon::get_uye_id() const { return _uye_id; }
std::string Rezervasyon::get_rezervasyon_tarihi() const { return _rezervasyon_tarihi; }
std::string Rezervasyon::get_durum() const { return _durum; }

void Rezervasyon::set_durum(const std::string& durum) { _durum = durum; }