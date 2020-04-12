Utazó ügynök problémaja, szimulált hűtéssel

A program létrehozásához az alap könyvtárakon kívül nem volt szükséges más könyvtárakat deklarálni.
Szükségünk van egy bemeneti fájlra "be.txt" néven, amely az első sorban tartalmazza, hogy hány csomópontból áll a feladatunk.
Ezután egy két dimenziós mátrix kell szerepeljen, amelyben adottak a csomópontok közti távolságok, a főátlón természetesen nullásokkal.
Ezután véletlenszerűen kigenerálódik egy kiinduló állapot, ezt vesszük alapul amikor ennél optimálisabb megoldásokat keresünk.
Eltárolódik az összes aktuális megoldás is, hogy a kétszereződés kiküszöbölődjön.
