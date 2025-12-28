# 📚 Kütüphane Yönetim Sistemi (Library Management System)

![C++](https://img.shields.io/badge/Language-C++17-blue)
![CMake](https://img.shields.io/badge/Build-CMake-orange)
![Architecture](https://img.shields.io/badge/Architecture-3--Tier-purple)
![License](https://img.shields.io/badge/License-MIT-green)

Bu proje, C++ ve Nesneye Dayalı Programlama (OOP) prensipleri kullanılarak geliştirilmiş, **Çok Katmanlı Mimari (3-Tier Architecture)** yapısına sahip kapsamlı bir kütüphane otomasyonudur.

## 🚀 Proje Tanımı ve Mimari

Sistem; kitap envanterini, üye kayıtlarını, ödünç/iade döngüsünü ve rezervasyon işlemlerini yönetir. Kod yapısı sürdürülebilirlik için üç ana katmana ayrılmıştır:

1.  **Entity (Varlık) Katmanı:** Veri modellerini temsil eder (`Kitap`, `Uye`, `Yazar` vb.).
2.  **Repository (Depo) Katmanı:** Veri erişim ve depolama işlemlerini soyutlar.
3.  **Service (Servis) Katmanı:** İş mantığını (ceza hesaplama, stok kontrolü vb.) yönetir.

---

## 📊 Varlıklar ve Örnek Demo Verileri

Proje çalıştırıldığında, sistemin yeteneklerini test etmek amacıyla aşağıdaki **Harry Potter** veri seti otomatik olarak kullanılır:

### 1. Kitap (Book)
| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | Benzersiz ID | `101` |
| isbn | string | ISBN No | `"9789750802942"` |
| baslik | string | Kitap Adı | `"Harry Potter ve Felsefe Taşı"` |
| yazar_id | int | Yazar Ref. | `201` (J.K. Rowling) |
| kategori_id | int | Kategori Ref. | `301` (Fantastik) |
| stok | int | Mevcut Stok | `5` |

### 2. Yazar (Author)
| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | Benzersiz ID | `201` |
| ad_soyad | string | Yazar Adı | `"J.K. Rowling"` |
| ulke | string | Ülke | `"İngiltere"` |

### 3. Üye (Member)
| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | Benzersiz ID | `1` |
| ad_soyad | string | Üye Adı | `"Ahmet Yılmaz"` |
| kayit_tarihi | string | Tarih | `"2025-10-01"` |

### 4. Ödünç Alma (Loan)
| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | İşlem ID | `5001` |
| kitap_id | int | Kitap Ref. | `101` |
| uye_id | int | Üye Ref. | `1` |
| durum | string | Durum | `"Devam Ediyor"` |

### 5. Rezervasyon (Reservation)
| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | İşlem ID | `6001` |
| kitap_id | int | Kitap Ref. | `101` |
| uye_id | int | Üye Ref. | `1` |
| durum | string | Durum | `"Aktif"` |

---

## ⚙️ Servis Yetenekleri

Sistem aşağıdaki 11 temel fonksiyonu yerine getirir:

1.  **`kitapEkle`**: ISBN kontrolü ile yeni kitap girişi yapar.
2.  **`uyeKaydet`**: TC Kimlik doğrulaması ile üye oluşturur.
3.  **`kitapOduncVer`**: Stok kontrolü yapar ve 14 günlük süre başlatır.
4.  **`kitapIadeAl`**: İade alır ve stok adedini günceller.
5.  **`rezervasyonYap`**: Stokta olmayan kitaplar için sıra oluşturur.
6.  **`rezervasyonIptal`**: Rezervasyon talebini siler.
7.  **`gecikmisKitaplariGetir`**: Süresi dolan iadeleri raporlar.
8.  **`uyeOduncGecmisiGetir`**: Üyenin tüm geçmiş işlemlerini listeler.
9.  **`kitapAra`**: Başlık veya ISBN ile arama yapar.
10. **`enCokOkunanKitaplar`**: Popüler kitapları istatistiksel olarak sıralar.
11. **`uyeCezaHesapla`**: Geciken her gün için otomatik ceza hesaplar.

---

## 💻 Kurulum ve Çalıştırma

Proje **CMake** tabanlıdır. macOS (ve Linux) terminalinde derlemek için aşağıdaki adımları izleyin:

```bash
mkdir build && cd build
cmake ..
make
./kutuphane_sistemi
