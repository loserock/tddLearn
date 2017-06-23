
TTD TRAINING @ NNG
==================

## DAY 1: Bevezetés

_Tollas jegyzetek naptárban_

kovacs.attila@inf.elte.hu

### TTD Cycle

 - red
 - green
 - refactor

#### Red

_ld. jegyzetek_

#### Green

_ld. jegyzetek_

#### Refactor

(_ld. jegyzetek is)

 - legnehezebb :)

 - mindig **kell** csinálni!
    - dokumentáció
    - clean code
    - maintenance
    - nem fogsz tudni hozzányúlni később különben! :)

 - tanácsok
    - design és _anti patternek_ figyelembevétele
    - _DRY_ Don't repeat yourself!
    - _KISS_ Keep it simple stupid
    - _YAGNI_ You aren't going to need it
    - _SRP_ Single responsibility principle
        - one responsibility -> one class
        - **ne** a kód mérete számítson! persze a kohézió fontos, de lényeg az egybe tartozó dolgok egybetartozása
    
### TDD Benefits

 - a tesztek miatti nagyobb kódmennyiség _tapasztalat szerint_ nem növeli valósan a költségeket
 - _mérések szerint_ kevesebb debuggal jár
    80% redukciót is emlegetnek cikkekben
 - rákényszerít a tervezésre, **ez a lényeg**
 - small steps iterations, hatékonyabb gondolkodásmód
 - az early test az quality növelő, meredeken növekszik a költség, minél később kell megejteni a változtatást, a TTD elég korai fázisban észleli a hibákat
 - a kód eleve modulárisabb lesz (az kell legyen, kikényszeríti a módszer), átgondoltabb interfészek lesznek
 - autotesztelés lehetővé tétele, folyamatos regresszió

### TDD Shortcomings

 - tesztesetek problematikája, a unit test **nem mindenttudó**!
    - rengeteg a unit test, kevesebb az integrációs teszt, és nagyon kevés az acceptance test
    - régen ez a piramis fordítva nézett ki, magasabb szintű tesztekből volt sok, alacsony szintüből kevés
    - a jövő valószínűleg a több API test felé megy
 - a sok mocking visszaüthet a cső végén
 - a management partner kell hogy legyen a folyamatokban, őket meggyőzni a hosszútávú hasznok miatt nehéz
 - pair programming elviheti a fókuszt (?)
 - tesztek **karbantartása** költséges (az írás még nem, de maintenance viszont igen)
 - _overtesting_ minden kis változás is túl sok szálat megmozgathat, pl. több teszt hasal el az indokoltnál, amiket ezért ellenőrizni kell
 - az emberi kreatív hülyeség: cég szállítja le a tesztek írását, és a jobb hatásfok miatt csak a zöldeket szállítják le :lol:

### Pair programming

 - XP másik nagy ajánlott előnye
 - Kovács Attila szerint nagyon jó gyöngyszem, erősen ajánlott
 - lehetőleg ne mindenki mindenkivel, hanem egy tapasztalt és egy kezdő legyen egy párban
 - a termékkel kapcsolatos tudás átadása a legfontosabb!
 - _nem_ full time, hanem pair time a hatékonyabb, pl. a tervezést a nap elején közösen, de aztán néha lehet párhuzamosítani a taskot, aztán átnézni egymás kódját
 - tapasztalat szerint 20-30% a munkában review-val telik, érdemes nyomni a pair review-t

### PSP Personal Sofrware Process

 - a CMI kitalálója találta ki
 - a hibák számát vállalati szinten csökkenteni tudja a módszer (hogy egymillió sorban se legyen összesen túl sok hiba, ami utólag derül ki)
 - personal, tehát a programozóval magával foglalkozik
 - kb. két évnyi munka és állandó könyvelés kell hozzá per fő, amivel elérhető az egymillió sor / tíz hiba
 - de jó programozó kell hozzá (tehát aki már nem a nyelv dolgaival ismerkedik), inkább architekturális hibák javításával foglalkozik
 - van még: TSP, Team Software Process, ez már a fejlettebb emberekből áll össze
 - ami a PSP & TSP ügyét illeti (két évente van egy ilyen hallgató), ott már a _cost of change_ görbe teljesen más, és a kódolás törvényszerűségei is teljesen mások

### Traceability

 - egy hasznos fogalom :)
 - ha van egy modulom, programom, bármi entitásom egy vállalatnál, bármikor nyomonkövethetők az információi
 - ki készítette, mik a tesztesetek, miért, mik az előzmények, mik a tervek vele
 - persze ez költséges, ezért általában nincs ilyen
 - katonai vagy nagyon nagy kockázatú területeken kötelező ez

### Mocking

 - a mock objektum valamennyire okos (pl. nem mindig ugyanazt adja vissza egy mockolt függvény)
 - a stab objektum tök hülye

### Testability

 - a TTD business oriented, tehát a business felől is behozzuk a várható teszteseteket, amik relevánsak lehetnek
 - use case vs user story
    - egy use case az egy eset, egy business eset
    - sok user story rendelődik majd egy use case-hez
 - the triple A method, AAA: Arrange, Any, Assert. Ez pl. egy lehetőség, lehet ezt is követni, vagy mást is.
 - Given When Then format: ez is egy lehetőség

### Risk management

 - vannak _driven_ fejlesztési módszerek, meg vannak _based_ módszerek
    - pl TDD vs TBD
 - _Risk Based Test_ módszerek
    - kockázatok szerint teszik sorrendbe az issue-kat
    - ez alapján írják a teszteket
    - resource és money optimalizáció

### Large systems

 - a kicsi felskálázása a nagyra, kb. egy külön terület
 - **nagyon fontos** fulcsfogalom: a **complexity**
 - _culture follows the structure_
 - _Lehman's Law_: a szoftver, a dev team és a vállalat minősége egymásra hatni fog
 - ha sikert akarsz egy vállalatban, azt jól meg kell tervezni előre és kellenek hozzá a jó emberek
    - megyjegyzés: alulról érdemes nyomni a változásokat, felül harc megy
 - a **complexity** és a **RISK** nagyon fontos, átdefiniálhatja a használt módszerek alkalmazhatóságát

### ATDD Acceptance TDD

 - ez egy olyan TDD alfaj, ahol az orientáltság az acceptance
 - Cycle:
    - discuss
    - distill
    - develop
    - demo
 - kell definiáni az acceptance kritériumot, még a user story összerakásánál
 - ez már csapatos fejlesztői munka
 - a TDD és az ATDD inkább _code oriented_

### BDD Behaviour Driven Development

 - az ATTD-hez hasonló alapokkal játszik
 - olyankor érdemes használni, ha az _ügyfél_ is képes lenne megérteni a teszteseteket
 - keyword testing
    - szó szerint, egy szöveges fájlba vagy excel-be (vagy GUI-ba) a _nem_ programozó képes lehetne begépelni a kéréseket
    - a német államigazgatás ezt csinálta évekig, mert költséghatékony
 - GWT syntax:
    - Given: az adott context
    - When: az event
    - Then: a kért outcome
 - ez a módszer a _tesztelési piramis_ legfelső fokát emeli ki
 - viszont, c++-ra így hirtelen nem tudunk mondani kész frameworköt
 - ez tehát _customer oriented_

### Test Quadrants

 - ehhez van egy ábra, ezt érdemes begyűjteni
 - _első kvadráns_: technology & supports
    - unit & integration tests
 - _második kvadráns_: business/customer & supports
    - functional & customer tests
    - itt a struktúra dominál, blackbox tesztek
 - _harmadik kvadráns_: business/customer & critiques
    - user acceptance & usability & exploratory tests
    - itt a rutin és a tapasztalat is előkerül
 - _negyedik kvadráns_: critiques & technology
    - performance & load tests
    - itt érünk körbe, teszt analízis és szkripting

### Vegyes tanácsok és infók

 - ha az ügyfélnél kint lévő kód mér, általában kiderül, hogy melyik az a néhány száz sornyi kód, ahol a futás sokat tartózkodik Ezekben érdemes lemenni pl. egy szinttel lentebb! (pl. C++-ról Asembly-re)
 - _grooming_: a backlog aljának finomítása
 - _`ISO/IEC 25010:2011`_ ha a vállalat termékeit fel kell mérni, hogy mire érdemes jobban figyelni, ehhez támpont
 - a TDD önmagában nem elég
    - kell a tervezést, amit segít is
    - kell architktúra, pl. SAFE
        - Scaled Agile Framework
        - csak a vállalat egészére működik, egy-egy részre nem
        - profi és elszánt vállalat kell hozzá :lol:
        - nem tesz elég hangsúly Dev Ops és Test Ops-ra
        - a complexity hiányzik belőle
 - ha nem minden részt lehet autotesztelni, a TDD attól még bevezethető
 - agilis vállalatnál az egész vállalat agilis, a vezetés is! Feudális management esetén az a vállalat soha sem lesz agilis.
 - az IT jövőjére erősen hatni fog az AI
 - valószínűleg a legnagyobb probléma a jövőben az IT security lesz
 - _bug hunting_ és _bug safary_ van játék változatban is :) és hasznos, párban csinálható vagy teamben
 - hibajegyek és reportok rendszerezéséhez vannak jó módszerek, pl. a Google és az Apple is csinál olyat, hogy callstackek olyan hash-be íródnak át, ami azért kb. megőrzi az adat struktúráját, így a hasonló hibák a nagy kupac adatban is fellelhetők lehetnek (de kell hozzá egy jó hashing algoritmus, a többi gyerekjáték)
 - tanács: jobb, ha minden kódrésznek van egy hivatalos felelőse, ennek az ellentéte lenne a _collective code ownership_
 - fejelsztési időbecslés:
    - alapból ökölszabály: egy munkanap igazából 6 óra (és nem 8)
    - agilis fejlesztésnél viszont ez _kevesebb_, nincs rá szabály, akár 3-4 órára is lemehet per nap
    - a TDD _mérések szerint_ szellemileg megerőltető, szépen kifárasztja az embert, tehát nem érdemes vele túlórázni, és _vissza is üt_!
 - ha meglévő projektet kéne átteni TDD like kóddá, akkor érdemes profile felvétellel kezdeni, és a kulcsfontosságú részek TDD típusú újraírására ráfeküdni
 - egyébként a TDD mint módszer, Kovács Attila szerint egy jó út, fejleszti a gondolkodásmódot tervező jellegűvé
 - _nem vagyunk egyformák_, ha sebességet mérünk, a velocitás a csapatot kell jelelmezze, ez kb. minden agile módszerre igaz (SCRUM, Mob, TDD)
 - nemzetközi mérés csapatmunkáról:
    - nem kultúra függő volt az eredmény elsősorban
    - ahol a team választott főnököt, általában azok a csapatok működtek
        - japánoknál a legidősebb, németeknél a legmagasabb végzettésgő lett az általában
        - működött mindegyik főnök típus valahogy
        - amerikaiak a ráérzéses csapatmunkát követték, ad'hoc főnökök ott is voltak, de nekik ez az oktatásuk alapját képezi

### Örökzöld mejegyzések

 - „a SCRUM arra való, hogy webshopot építs”
 - 1 magyar > 10 német, 10 német > 100 magyar
 - „Egy ilyen szintű vállalatnál, amiben ti vagytok, a SAFE az kuka!”
 - „Az agilitás nem más, mint a manifesto négy pontjának kielégítése. Hogy azt hogyan csinálod, az rád van bízva.”
 - a jövő megoldása nem a bombázás, hanem az oktatás
 - az ELTE egyébként már rég megszűnt, csak nem szóltak róla

## DAY 2

Porkoláb Zoltán, gyakorlati előadás várható egy fél napos bevezető után.

### Tesztírási alapelvek

 - **nem** írom meg az összes tesztet előre!
    - rossz filozófia, hogy először kell megírni az összes elképzelhető tesztesetet, és aztán a kód majd valamikor elkészül. Ilyenkor tipikusan marad egy csomó TODO és néhány forever failed test és hacked workaround.
    - mire a munka elkészülne, lehet hogy meg is változik a spec
    - párhuzamosan kell csinálni: néhány teszt, néhány implementálás
    - _small steps_, _small cycles_
 - nem valós tesztesetet írni, csak hogy legyenek, **nem** szabad
    - nem arra kell írni a tesztet, hogy az átmeneti mock sajátosságait teszteljük, hanem a valós eset kell nekünk
 - a teszt is kód
    - maradjon olvasható az utókornak
    - ne legyen benne triviális komment
    - ne rejtse el a fontos dolgokat, pl a contextet
    - fölöslegesen ne használjon a teszt bonyolult fécsöröket (_KISS_ elv)
        - pl. just for fun nem érdemes a teszt osztályokat származtatni, amikor két sorral is elérhető ugyanez
 - maradjon a teszt a logikus történetvezetésnél:
    - setup
    - action
    - conclusion
 - a nagyon triviális eseteket nem érdemes tömegesen tesztelni (lehet, hogy ezekre hekkel a kód)
    - pl. egy számoló függvénynél (faktoriális, hatvány...), nézzük meg pl...
        - max integerre, min limitre
        - nullára
        - statikus analyzer által generált mintára
        - sarok esetekre
        - overflow-ra
 - a teszteset speficikus
    - ha egy vektor alapú adatstruktúra egy feature függvényét ellenőrizzük, akkor azt kell abban az esetben letesztelni
    - mást fécsöröket, például hogy jó-e a vektor `push_back`-je, ott **nem** teszteljük fölöslegesen
    - másik tesztesetben, ami pl az initért felel, már tesztelhetjük, viszont ott akkor részletesen és valósan
 - a teszt vezesse az implementációt, és ne az implementáció a tesztírást

### Általános szabályok tesztíráshoz

 - a teszteset hatással lehet a library-t tanuló userre
    - ilyenkor érdemes a veszélyes eseteket kommenttel jelezni: "ez csak teszteset, nem use case"
 - a test kedvéért sem érdemes hack megoldásokat használni
    - pl. kerülendő a `#define public private`
    - ezek az objektumok bináris képét is megváltoztathatják, tehát nem a valós esetet fogjuk tesztelni, csak egy hasonlót
 - a tesztek legyenek autonómok
    - ne függjenek egymástól
    - ne függjön a tesztek lefuttatási sorendjétől
 - a teszt legyen univerzális, ahogy lehet
    - pl. std lib konténer objektumokra írjuk, és ne speciálisan vektorra
 - ne függjön a teszt a gép sebességétől
    - a `sleep(500); // should be enough` jelleg kerülendő!
 - gyakorlati dolgokra figyelni
    - a timestamp jó lesz-e, ha éjfél után is fut a process?
    - 32 vs 64 bit
    - több példány fut-e a processzből? (pl. tesztgépen)
    - ezek sokszor nem egyszerű dolgok, fontos megállni gondolkozni
    - és persze tapasztalat
 - beégetett adatsorok veszélyére figyelni
    - pl. hash táblába írt adatok sorrendje, kódsor explicit loggolása
    - az erre való feature-ök használata ajánlott (pl. gtest-ben)
 - a tesztek lehetőleg állapotmentesek legyenek
    - hell's circles: globális változók, futtatási sorrend felállítása

### Test goals summary

 - nincs tökéletes teszt, kompromisszumok kellenek
 - de érdemes a szabályokat felhasználni az optimális eredményért

### Google Test gyakorlat

 - makró mágia
 - a `RUN_ALL_TESTS` dolgokat egyszer hívjuk, ebbe nem tanácsos belenyúlni
 - compile mágia: a gtest hátrébb kell álljon a frodítási listában pl. g++ esetén
 - ASSERT és EXPECT különbésgek
 - parancssori argumentumok:
    - `--gtest_filter=TestGroup.TestName` vagy akár regex segítségével futtatni
    - `--gtest_repeat=3`
    - `--gtest_output="xml:test1-report.xml"`
 - floating point
    - `*_DOUBLE_EQ`, `*_FLOAT_EQ`
    - vagy `ASSERT_NEAR(a, b, precision)`
 - death tests
    - utasítás folyamot is írtahok bele, pl. `exit(0)`-ra lehet tesztelni
    - `std::cerr` várható kimenetére is lehet nézni, hogy az az elvást-e (üres string itt bármitelfogad)
    - `ASSERT_EXIT( mm.factorial(-1), ::testing::ExitedWithCode(1), "Negative input")`
    - lehet unix alatt szignálra is: `::testing::KilledBySignal(SIGUSR1)`
 - exception test
    - `ASSERT_THROW`, `ASSERT_ANY_THROW`, `ASSERT_NO_THROW`
 - lehet prediktálva kikérni a futási ereményt (nem fv return value megy mint `ASSERT_TRUE` esetén, hanem ott a sorban jönnek be és értékelődnek ki a paraméterek is)
 - `::testing::*` dolgokban vannak származtatható dolgok is, pl. testzes exceptionök, így bele lehet hekkelni mindenféle pluszt a rendszerbe
 - test fixtures
    - a `SetUp` előtt kiírja a runt és a `TearDown` után írja ki a resultöt
    - ami éthető, mert ezek is failelhetnek
 - async teszt timeout checkkel
    - nincs ilyen alapból a googletestben, de githubon hekkeltek ilyet C++11 lambdával
    - van egy BEGIN és egy END predefined makrója, cpp11 promise segítségével dolgozik
    - megadható a timeout, és hogy azon belül vagy azon kívül kell-e befejeződnie
    - illetve a törzsben magadható maga a futtatni kívánt teszt is
    - mindez aszinkron fut

## DAY 3

Porkoláb Zoltán, ma folytatjuk a kódolást, és mockkolás lesz főleg.

### Coding notes

 - megint előjött: `const_cast` is evin (undefined behaviour)
    - pointeres értéket const caatoljuk, elvész az érték
    - ismétlés: ilyenkor `volatile` a barátunk (nem fog rá optimalizálni a compiler, jó lesz az érték `const_cast` után is)
 - gyakorlatban csináltunk assertion result elkapó függvényt exceptionhöz
 - _félhivatalos_ de szabványba beférő módszer `private` adattagokhoz :)
    - [link to presentation](https://www.meetup.com/Hungarian-Cpp-Community/events/227145136/)
    - szerintem ez egy batár nagy leak, de mindegy :lol:
