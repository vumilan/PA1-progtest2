# PA1-progtest2

Úkolem je vytvořit program, který bude plánovat půdorys koupelny v rodinném domu.

Předpokládáme, že již máme rozmyšlené veškeré vybavení koupelny, proto potřebujeme, aby koupelna měla měla určité minimální rozměry, aby se do ní veškeré vybavení pohodlně vešlo. Zároveň však nechceme na koupelnu obětovat zbytečně velkou část domu, tedy velikost koupelny má být nejmenší možná.

Komplikace je v tom, že koupelna má být vydlážděna. Předpokládáme, že máme vytipováno několik druhů dlaždic, ale stále není jasno, které budou nakonec v koupelně použité. Jednotlivé dlaždice se liší nejenom velikostí, ale i použitým materiálem, proto se u různých dlaždic musí dodržet i specifická šířka spáry mezi dlaždicemi (viz obrázek). Podlaha tedy musí být čtvercového či obdélníkového tvaru, musí být celá z jednoho typu dlaždic a nesmí být použita žádná řezaná dlaždice (to by kazilo celkový estetický dojem).

Vstupem programu jsou desetinná čísla, všechna čísla udávají rozměry v centimetrech s přesností na desetiny (tedy efektivně je přesnost 1 mm). Nejprve je zadaná dvojice čísel udávající minimální požadovaný rozměr koupelny (šířka a délka). Následuje zadání libovolného počtu dvojic desetinných čísel. První číslo každé dvojice udává velikost dlaždice (dlaždice je čtvercová), druhé číslo udává požadovanou velikost spáry mezi dlaždicemi. Zadávání dlaždic končí po dosažení konce vstupu (EOF).

Výstupem programu je nejmenší možný rozměr koupelny takový, že je větší nebo rovný minimu a lze jej vydláždit libovolnou zadanou dlažbou (se zadanou velikostí spáry). Pro některé kombinace velikosti dlažby toho nelze docílit, toto program musí detekovat případně oznámit uživateli.


Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:
* zadané rozměry nejsou platná desetinná čísla,
* nějaký zadaný rozměr je záporný,
* nějaký rozměr je zadaný s přesností větší než 1 mm,
* nějaký rozměr překračuje 10000000 cm,
* nebyl zadaný žádný rozměr dlažby,
* minimální šířka koupelny, minimální délka koupelny nebo velikost dlažby je nulová,
* velikost spáry může být nulová.

### Ukázka práce programu:
```
Minimalni velikost:
200 300
Dlazdicky:
24 0
18 0
Velikost: 216.0 x 360.0
```
```
Minimalni velikost:
200 300
Dlazdicky:
7.0 0
16.1 0
10.5 0
Velikost: 483.0 x 483.0
```
```
Minimalni velikost:
200 50000
Dlazdicky:
7.0 0.5
16.0 0.3
10.1 0.2
Velikost: 23700.5 x 149618.0
```
```
Minimalni velikost:
200 50000.5
Dlazdicky:
7.0 0.5
16.0 0.3
10.8 0.2
Reseni neexistuje.
```
```
Minimalni velikost:
10 1000000
Dlazdicky:
24.6 0.2
15.8 0.2
16.2 0.4
Velikost: 28768.2 x 1016800.2
```
```
Minimalni velikost:
10 1000000000
Nespravny vstup.
```
```
Minimalni velikost:
100 100
Dlazdicky:
57.0 abcd
Nespravny vstup.
```
### Poznámky:
* Ukázkové běhy zachycují očekávané výpisy Vašeho programu (tučné písmo) a vstupy zadané uživatelem (základní písmo). Zvýraznění tučným písmem je použité pouze zde na stránce zadání, aby byl výpis lépe čitelný. Váš program má za úkol pouze zobrazit text bez zvýrazňování (bez HTML markupu).
* Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
* Pro načítání rozměrů může být vhodný datový typ double, pro další výpočty ale už vhodný být nemusí.
* Úlohu lze vyřešit bez použití funkcí. Pokud ale správně použijete funkce, bude program přehlednější a bude se snáze ladit.
* Základní řešení úlohy vyžaduje použití cyklů a podmínek. Není potřeba používat pole.
* Úloha nabízí bonus, kterého lze dosáhnout, pokud je řešení časově efektivní. Časové efektivity lze dosáhnout zejména volbou vhodného algoritmu, který rovnou přeskočí neperspektivní rozměry koupelny. Začínajícím programátorům doporučujeme řešit základní variantu bez bonusu. I zkušeným programátorům doporučujeme nejprve zpracovat a odevzdat pouze základní jednodušší řešení a pomocí něj odladit efektivnější variantu.
* Bonusový test vede k velkým rozměrům koupelny, tyto rozměry se nevejdou do datového typu int ani float. Pokud chcete zvládnout bonusový test, musíte použít větší datový typ (např. long long int, jeho správné použití nezpůsobí varování, kompilátor používá přepínač -Wno-long-long). Pokud Vaše implementace neprovádí aritmetické operace rozumně úsporně, může rozsah datových typů působit problémy i v ostatních testech.
* Při programování si dejte pozor na přesnou podobu výpisů. Výstup Vašeho programu kontroluje stroj, který požaduje přesnou shodu výstupů Vašeho programu s výstupy referenčními. Za chybu je považováno, pokud se výpis liší. I chybějící nebo přebývající mezera/odřádkování je považováno za chybu. Abyste tyto problémy rychle vyloučili, použijte přiložený archiv se sadou vstupních a očekávaných výstupních dat. Podívejte se na videotutoriál (edux -> výuková videa), jak testovací data použít a jak testování zautomatizovat.
* Platné rozměry jsou například 10.5, 17 nebo 24.0. Neplatný rozměr je například 25.06 (přesnost vyšší než na milimetry). Vstup typu 12.00 považujte za platný, přestože obsahuje dvě desetinná místa. Progtest takové hodnoty při testování nezadává, z hlediska implementace je trochu jednodušší takový vstup přijímat (odmítnutí takového vstupu by bylo implementačně pracnější, museli byste realizovat vlastní převod vstupu na desetinné číslo).
* Slovní popis struktury platných vstupních dat není zcela exaktní. Proto připojujeme i formální popis vstupního jazyka v 
```
EBNF:
    input      ::= { whiteSpace } minSize { whiteSpace } tile 
                   { whiteSpace } { tile { whiteSpace } }
    whiteSpace ::= ' ' | '\t' | '\n' | '\r'
    minSize    ::= decimal { whiteSpace } decimal
    tile       ::= decimal { whiteSpace } decimal
    decimal    ::= [ '+' ] integer [ '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ] ]  |
                   [ '+' | '-'  ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ]
    integer    ::= digit { digit }
    digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
 ```
