# 📚 Kütüphane Yönetim Sistemi


## 🚀 Proje Tanımı

Bu proje, C++ ve Nesneye Dayalı Programlama (OOP) prensipleri kullanılarak geliştirilmiş, sürdürülebilir ve ölçeklenebilir bir kütüphane otomasyon sistemidir. Sistem; kitap envanterini, üye hareketlerini ve ödünç/iade döngüsünü yönetmektedir.

Proje, **Çok Katmanlı Mimari (3-Tier Architecture)** yapısında tasarlanmıştır:
1.  **Entity (Varlık) Katmanı:** Veri modellerini temsil eder.
2.  **Repository (Depo) Katmanı:** Veri erişim ve saklama işlemlerini soyutlar.
3.  **Service (Servis) Katmanı:** İş mantığını ve kuralları (ceza hesaplama, stok kontrolü vb.) yönetir.

---

## 💾 Varlık Tanımları ve Demo Verileri

Aşağıdaki tablolar, sistemdeki 7 temel varlığı ve proje çalıştırıldığında yüklenen **örnek "Harry Potter" veri setini** göstermektedir.

### 📖 1. Kitap (Book)
Kütüphane envanterindeki kitapların tutulduğu temel varlıktır.

| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | Benzersiz ID | `101` |
| isbn | string | ISBN No | `"9789750802942"` |
| baslik | string | Kitap Adı | `"Harry Potter ve Felsefe Taşı"` |
| yazar_id | int | Yazar Ref. | `201` (J.K. Rowling) |
| kategori_id | int | Kategori Ref. | `301` (Fantastik) |
| yayinevi_id | int | Yayınevi Ref. | `401` (YKY) |
| stok_adedi | int | Mevcut Stok | `5` |
| sayfa_sayisi | int | Sayfa Sayısı | `276` |

### ✍️ 2. Yazar (Author)
Kitap ile ilişkilendirilen yazar bilgileridir.

| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | Benzersiz ID | `201` |
| ad_soyad | string | Yazar Adı | `"J.K. Rowling"` |
| dogum_yili | int | Doğum Yılı | `1965` |
| ulke | string | Ülke | `"İngiltere"` |

### 🏷️ 3. Kategori (Category)
Kitabın türünü belirtir.

| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | Benzersiz ID | `301` |
| ad | string | Kategori Adı | `"Fantastik Kurgu"` |
| aciklama | string | Açıklama | `"Büyü ve hayali evrenleri konu alır."` |

### 🏢 4. Yayinevi (Publisher)
Kitabı basan kurum bilgisidir.

| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | Benzersiz ID | `401` |
| ad | string | Yayınevi Adı | `"Yapı Kredi Yayınları"` |
| adres | string | Adres | `"Levent, İstanbul"` |
| telefon | string | Telefon | `"0212 123 45 67"` |

### 👥 5. Uye (Member)
Kütüphane hizmetlerinden yararlanan kullanıcılar.

| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | Benzersiz ID | `1` |
| tc_no | string | TC Kimlik No | `"12345678901"` |
| ad_soyad | string | Üye Adı | `"Ahmet Yılmaz"` |
| email | string | E-posta | `"ahmet@ornek.com"` |
| telefon | string | Telefon | `"0555 111 22 33"` |
| kayit_tarihi | string | Kayıt Tarihi | `"2025-10-01"` |

### 🔄 6. OduncAlma (Loan)
Aktif veya tamamlanmış ödünç işlemleri.

| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | İşlem ID | `5001` |
| kitap_id | int | Kitap Ref. | `101` (Harry Potter) |
| uye_id | int | Üye Ref. | `1` (Ahmet Yılmaz) |
| odunc_tarihi | string | Veriliş Tarihi | `"2025-12-01"` |
| iade_tarihi | string | Son Tarih | `"2025-12-15"` |
| durum | string | Durum | `"Devam Ediyor"` |

### 📅 7. Rezervasyon (Reservation)
İstenen kitap stokta yoksa sıraya girmek için oluşturulan kayıttır.

| Alan | Tip | Açıklama | Örnek Veri (Demo) |
|------|-----|----------|-------------------|
| id | int | İşlem ID | `6001` |
| kitap_id | int | Kitap Ref. | `101` (Harry Potter) |
| uye_id | int | Üye Ref. | `1` (Ahmet Yılmaz) |
| rezervasyon_tarihi | string | Talep Tarihi | `"2025-12-18"` |
| durum | string | Durum | `"Aktif"` |

---

## 🔗 Varlık İlişkileri

Sistemdeki ilişkisel yapı aşağıdaki gibidir:
* Bir **Yazar** birden fazla **Kitap** yazabilir (1-n).
* Bir **Kategori** altında birden fazla **Kitap** olabilir (1-n).
* Bir **Yayınevi** birden fazla **Kitap** basabilir (1-n).
* Bir **Üye** birden fazla kez **Ödünç Alma** işlemi yapabilir (1-n).
* **Kitap**, ödünç verildiğinde stok adedi servis katmanında dinamik olarak düşülür.

---

## ⚙️ Servis İşlemleri

Sistem, iş mantığını yöneten 11 temel fonksiyon üzerine kurulmuştur:

1.  **Kitap Ekleme:** `kitapEkle` fonksiyonu, ISBN benzersizliğini kontrol ederek yeni kitapları envantere dahil eder.
2.  **Üye Kaydı:** `uyeKaydet` ile TC kimlik numarası validasyonu yapılarak yeni üye kaydı oluşturulur.
3.  **Ödünç Verme:** `kitapOduncVer`, stok kontrolü yapar ve kitabı üyeye tanımlayarak 14 günlük iade süresini başlatır.
4.  **İade Alma:** `kitapIadeAl`, kitabı geri alır, stoku günceller ve olası gecikmeleri kontrol eder.
5.  **Rezervasyon Yapma:** `rezervasyonYap`, stokta bulunmayan kitaplar için üye adına rezervasyon sırası oluşturur.
6.  **Rezervasyon İptali:** `rezervasyonIptal`, daha önce oluşturulmuş bir rezervasyon talebini sistemden kaldırır.
7.  **Gecikme Raporu:** `gecikmisKitaplariGetir`, iade tarihi geçmiş olan tüm aktif işlemleri listeler.
8.  **Üye Geçmişi:** `uyeOduncGecmisiGetir`, belirli bir üyenin geçmişte aldığı ve iade ettiği tüm kitapları raporlar.
9.  **Kitap Arama:** `kitapAra`, girilen anahtar kelimeye göre kitap başlığı veya ISBN üzerinden hızlı erişim sağlar.
10. **Popüler Kitaplar:** `enCokOkunanKitaplar`, işlem hacmine göre en çok ödünç alınan kitapları sıralar.
11. **Ceza Hesaplama:** `uyeCezaHesapla`, iadesi geciken kitaplar için günlük 1 TL üzerinden toplam ceza tutarını hesaplar.

---

## 💻 Derleme ve Çalıştırma

Proje, macOS ve Linux ortamlarında terminal üzerinden kolayca derlenebilir.

```bash
mkdir build && cd build
cmake ..
make
./kutuphane_sistemi
