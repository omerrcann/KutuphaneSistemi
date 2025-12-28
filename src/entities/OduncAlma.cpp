#include "OduncAlma.hpp"

OduncAlma::OduncAlma() : _id(0), _kitap_id(0), _uye_id(0) {}

OduncAlma::OduncAlma(int id, int kitap_id, int uye_id,
                     const std::string& odunc_tarihi, const std::string& iade_tarihi,
                     const std::string& gercek_iade_tarihi)
        : _id(id), _kitap_id(kitap_id), _uye_id(uye_id),
          _odunc_tarihi(odunc_tarihi), _iade_tarihi(iade_tarihi), _gercek_iade_tarihi(gercek_iade_tarihi) {}

OduncAlma::OduncAlma(const OduncAlma& other)
        : _id(other._id), _kitap_id(other._kitap_id), _uye_id(other._uye_id),
          _odunc_tarihi(other._odunc_tarihi), _iade_tarihi(other._iade_tarihi),
          _gercek_iade_tarihi(other._gercek_iade_tarihi) {}

OduncAlma::~OduncAlma() {}

int OduncAlma::get_id() const { return _id; }
int OduncAlma::get_kitap_id() const { return _kitap_id; }
int OduncAlma::get_uye_id() const { return _uye_id; }
std::string OduncAlma::get_odunc_tarihi() const { return _odunc_tarihi; }
std::string OduncAlma::get_iade_tarihi() const { return _iade_tarihi; }
std::string OduncAlma::get_gercek_iade_tarihi() const { return _gercek_iade_tarihi; }

void OduncAlma::set_gercek_iade_tarihi(const std::string& tarih) { _gercek_iade_tarihi = tarih; }