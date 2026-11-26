<div align="center">

<!-- Header Banner -->
<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0F172A,50:334155,100:38BDF8&height=210&section=header&text=Car%20Gallery%20Automation&fontSize=42&fontColor=F8FAFC&fontAlignY=38&desc=C%20Console%20Dealership%20Management%20%E2%80%A2%20Ara%C3%A7%20Galerisi%20Otomasyonu&descSize=16&descAlignY=62&animation=fadeIn" width="100%" alt="Car Gallery Automation Header Banner" />

<!-- Typing Animation -->
<a href="https://github.com/yorukokan/car-gallery-automation-system-in-c">
  <img src="https://readme-typing-svg.demolab.com?font=JetBrains+Mono&weight=600&size=18&duration=2600&pause=900&color=38BDF8&center=true&vCenter=true&width=780&lines=C+Console+App+%E2%80%A2+Dynamic+Memory+%28malloc%29+%E2%80%A2+Nested+Structs;Vehicle+CRUD+%E2%80%A2+Price+Range+Filter+%E2%80%A2+Brand+Search;Ara%C3%A7+Galerisi+Otomasyonu+%E2%80%A2+Dinamik+Bellek+ve+Struct+Yap%C4%B1s%C4%B1;Ekle+%E2%80%A2+Listele+%E2%80%A2+G%C3%BCncelle+%E2%80%A2+Sil+%E2%80%A2+Fiyat+ve+Marka+Arama" alt="Typing Animation" />
</a>

<br/>

<!-- Quick Action Pills -->
<p>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white&labelColor=0B0F19" alt="C Language" />
  <a href="https://github.com/yorukokan">
    <img src="https://img.shields.io/badge/GitHub-yorukokan-181717?style=for-the-badge&logo=github&logoColor=white&labelColor=0B0F19" alt="GitHub" />
  </a>
  <a href="https://linkedin.com/in/okanyoruk">
    <img src="https://img.shields.io/badge/LinkedIn-okanyoruk-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white&labelColor=0B0F19" alt="LinkedIn" />
  </a>
  <a href="mailto:okanyoruk.tr@gmail.com">
    <img src="https://img.shields.io/badge/Email-Contact-EA4335?style=for-the-badge&logo=gmail&logoColor=white&labelColor=0B0F19" alt="Email" />
  </a>
</p>

</div>

---

## 🎯 Overview · Proje Özeti

<table>
  <tr>
    <td width="50%" valign="top">
      <h3>🇬🇧 English</h3>
      <p>
        <strong>Car Gallery Automation System</strong> is a menu-driven C console application built for managing a car dealership's vehicle inventory in memory. Developed as a 1st-year Computer Engineering final project at Necmettin Erbakan University, it demonstrates nested <code>struct</code> modeling, dynamic heap allocation with <code>malloc</code>/<code>free</code>, array-shifting deletion, field-level updates, and price/brand filtering.
      </p>
      <ul>
        <li><strong>In-Memory Storage:</strong> All dealership and vehicle records are held in RAM during the active session (no external file I/O).</li>
        <li><strong>Interactive CLI:</strong> Continuous <code>while</code> menu loop with 6 vehicle operations plus clean exit.</li>
        <li><strong>Zero Dependencies:</strong> Built purely with standard C headers (<code>stdio.h</code>, <code>stdlib.h</code>).</li>
      </ul>
    </td>
    <td width="50%" valign="top">
      <h3>🇹🇷 Türkçe</h3>
      <p>
        <strong>Araç Galerisi Otomasyonu</strong>, bir araç galerisinin envanterini bellek üzerinde yönetmek için C diliyle geliştirilmiş menü tabanlı bir konsol uygulamasıdır. Necmettin Erbakan Üniversitesi Bilgisayar Mühendisliği 1. sınıf final projesi olarak hazırlanan uygulama; iç içe <code>struct</code> yapılarını, <code>malloc</code>/<code>free</code> ile dinamik bellek yönetimini, dizi kaydırmalı silmeyi, alan bazlı güncellemeyi ve fiyat/marka filtrelemeyi uygular.
      </p>
      <ul>
        <li><strong>Bellek İçi Depolama:</strong> Tüm firma ve araç kayıtları oturum süresince RAM'de tutulur (harici dosya I/O kullanılmaz).</li>
        <li><strong>Etkileşimli CLI:</strong> 6 farklı araç işlemi ve güvenli çıkış sunan sürekli <code>while</code> menü döngüsü.</li>
        <li><strong>Sıfır Bağımlılık:</strong> Yalnızca standart C kütüphaneleriyle (<code>stdio.h</code>, <code>stdlib.h</code>) çalışır.</li>
      </ul>
    </td>
  </tr>
</table>

---

## ✨ Key Features · Öne Çıkan Özellikler

<table>
  <tr>
    <td width="50%" valign="top">
      <h4>1️⃣ Dealership Setup &amp; Vehicle Registration</h4>
      <b>EN:</b> Initializes dealership name and city inside <code>struct Firma</code>, then allocates <code>struct Araba</code> records dynamically via <code>malloc</code>.<br/>
      <b>TR:</b> <code>struct Firma</code> içinde firma adı ve şehrini tanımlar, ardından <code>malloc</code> ile dinamik olarak araç kayıtları oluşturur.<br/><br/>
      <code>main.c</code> · <code>aracKayitEkle()</code>
    </td>
    <td width="50%" valign="top">
      <h4>2️⃣ Sequential Vehicle Listing</h4>
      <b>EN:</b> Displays all registered vehicles in order with brand, model, color, production year, and price.<br/>
      <b>TR:</b> Sisteme kayıtlı tüm araçları marka, model, renk, üretim yılı ve fiyat bilgileriyle sırayla listeler.<br/><br/>
      <code>main.c</code> · <code>aracKaydiListele()</code>
    </td>
  </tr>
  <tr>
    <td width="50%" valign="top">
      <h4>3️⃣ Gap-Free Record Deletion</h4>
      <b>EN:</b> Validates the selected vehicle index, shifts subsequent elements left to avoid empty slots, and decrements <code>arabaSayisi</code>.<br/>
      <b>TR:</b> Seçilen araç numarasını doğrular, arada boşluk kalmaması için sonraki kayıtları sola kaydırır ve <code>arabaSayisi</code> değerini azaltır.<br/><br/>
      <code>main.c</code> · <code>aracKaydiSil()</code>
    </td>
    <td width="50%" valign="top">
      <h4>4️⃣ Field-Level Vehicle Update</h4>
      <b>EN:</b> Opens an interactive <code>do-while</code> / <code>switch-case</code> sub-menu to edit brand, model, color, year, or price individually.<br/>
      <b>TR:</b> Marka, model, renk, üretim yılı veya fiyat alanlarını tek tek güncelleyebilen <code>do-while</code> / <code>switch-case</code> alt menüsü sunar.<br/><br/>
      <code>main.c</code> · <code>aracKaydiGuncelle()</code>
    </td>
  </tr>
  <tr>
    <td width="50%" valign="top">
      <h4>5️⃣ Price Range Filtering</h4>
      <b>EN:</b> Queries the inventory for vehicles whose <code>fiyat</code> falls inclusively between user-supplied minimum and maximum values.<br/>
      <b>TR:</b> Kullanıcıdan alınan en düşük ve en yüksek fiyat aralığında kalan araçları filtreleyerek ekrana getirir.<br/><br/>
      <code>main.c</code> · <code>aracFiyatAraligi()</code>
    </td>
    <td width="50%" valign="top">
      <h4>6️⃣ Brand-Based Search</h4>
      <b>EN:</b> Compares each vehicle's <code>marka</code> field against the target brand using <code>strcmp</code> and lists all matching records.<br/>
      <b>TR:</b> Her aracın <code>marka</code> alanını <code>strcmp</code> ile karşılaştırarak aranan markaya ait tüm araçları listeler.<br/><br/>
      <code>main.c</code> · <code>arabaBulma()</code>
    </td>
  </tr>
</table>

---

## 🏗️ Architecture · Mimari

### Data Structures · Veri Yapıları (`main.c`)

| Struct | Fields · Alanlar | Description · Açıklama |
| :--- | :--- | :--- |
| `struct Firma` | `char firmaAdi[50]`, `char sehir[20]`, `int arabaSayisi`, `struct Araba *arabalar` | Root dealership record holding a dynamically allocated pointer to the vehicle array. |
| `struct Araba` | `char marka[20]`, `char model[20]`, `char renk[20]`, `int yil`, `long int fiyat` | Individual vehicle record storing core attributes. |

### Application Flow · Uygulama Akışı

```text
main() [main.c]
 ├── malloc(sizeof(struct Firma)) ──► Read firmaAdi & sehir
 └── while (secim != 0) ◄── menu()
      ├── [1] aracKayitEkle()     ──► malloc(arabaSayisi * sizeof(struct Araba))
      ├── [2] aracKaydiListele()  ──► Iterate 0..arabaSayisi-1 & print
      ├── [3] aracKaydiSil()      ──► Validate index ──► shift left ──► arabaSayisi--
      ├── [4] aracKaydiGuncelle() ──► do-while switch (1:marka 2:model 3:renk 4:yil 5:fiyat 0:exit)
      ├── [5] aracFiyatAraligi()  ──► Filter minFiyat <= fiyat <= maxFiyat
      ├── [6] arabaBulma()        ──► Exact match via strcmp(marka, arananMarka)
      └── [0] Exit                ──► free(firma) & return 0
```

> **Note · Not:** In `aracKayitEkle()`, memory is allocated fresh via `malloc` (not `realloc`), so vehicle registration is intended to be performed first; calling option `1` again replaces the previous vehicle array in memory.

---

## 🛠️ Tech Stack · Teknoloji Yığını

<div align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white&labelColor=0D1117" alt="C" />
  <img src="https://img.shields.io/badge/GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white&labelColor=0D1117" alt="GCC" />
  <img src="https://img.shields.io/badge/Stdlib%20%E2%80%A2%20malloc%2Ffree-334155?style=for-the-badge&logoColor=white&labelColor=0D1117" alt="Dynamic Memory" />
  <img src="https://img.shields.io/badge/CLI-Console%20App-0F172A?style=for-the-badge&logo=gnubash&logoColor=38BDF8&labelColor=0D1117" alt="CLI Console App" />
</div>

---

## 📂 Project Structure · Proje Yapısı

```text
car-gallery-automation-system-in-c/
├── main.c                 # Core C source: structs, menu loop & 6 vehicle operations (367 lines)
├── automation-info.pdf    # University project specification document (TR)
├── .gitignore             # Standard C compiler & executable ignore rules
├── .gitattributes         # Git line-ending configuration
└── README.md              # Bilingual project documentation (EN · TR)
```

---

## 🚀 Getting Started · Kurulum ve Çalıştırma

### 1. Clone the Repository · Depoyu Klonlayın

```bash
git clone https://github.com/yorukokan/car-gallery-automation-system-in-c.git
cd car-gallery-automation-system-in-c
```

### 2. Compile with GCC · GCC ile Derleyin

**Windows (MinGW / GCC):**

```bash
gcc main.c -o car-gallery.exe
./car-gallery.exe
```

**Linux / macOS:**

```bash
gcc main.c -o car-gallery
./car-gallery
```

> **Compiler & Platform Notes · Derleyici ve Platform Notları:**
> - **GCC 14+:** `main.c` calls `strcmp` without explicitly including `<string.h>`. On GCC 14 and newer where implicit function declarations are treated as errors, compile with:
>   ```bash
>   gcc -Wno-implicit-function-declaration main.c -o car-gallery
>   ```
> - **Screen Clearing:** `main.c` uses `system("cls")` to clear the console between menu actions, which is native to Windows Command Prompt (on Linux/macOS, `cls` prints a harmless command-not-found message while the program continues running normally).
> - **Input Format:** String inputs use `scanf("%s", ...)`, so enter single-word values (e.g., `Toyota`, `Corolla`, `Ankara`) without spaces.

---

<div align="center">

<!-- Footer Banner -->
<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0F172A,50:334155,100:38BDF8&height=100&section=footer" width="100%" alt="Footer Wave" />

<sub>⚡ <b>Okan Yörük</b> · Car Gallery Automation System in C · <a href="https://github.com/yorukokan">github.com/yorukokan</a></sub>

</div>
