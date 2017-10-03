# Dijkstrin algoritam
Projekt iz kolegija DSTG - Matija Sabolić, Marko Srnec, Mario Šelek

## Implementacija Dijkstrinog algoritma u programskom jeziku C++
Aplikacija radi na način da se na početku izvođenja korisnik unosi početan vrh za računanje dijkstrinog algoritma. Nakon toga se u matricu na za to predviđena mjesta zapisuju podaci red po red iz datoteke s ulaznim podacima. Zatim se pomoću petlje provjeravaju svi vrhovi koji su povezani s početnim i odabire se vrh s najmanjom udaljenosti i on se označuje kao posječeni i put do njega postavljamo kao put do prethodnog vrha + trenutni vrh. Zatim se kao početni vrh algoritma uzima zadnje posječeni vrh i za njega prvodi prije opisani algoritam. Petlja se prekida kada su posječeni svi vrhovi grafa ili kada naiđemo na vrh koji nije povezan niti s jednim drugim vrhom. Na kraju se za svaki vrh grafa ispisuje njegova udaljenost od početnog vrha te putanja do početnog vrha.

## Ulazni podaci
Ulazni podaci za računanje Dijkstrinog algoritma pohranjeni su u datoteci naziva data.txt

### Struktura datoteke s ulaznim podacima
U prvoj liniji je zapisan broj vrhova zadanog težinskog grafa.
Svaka sljedeća linija datoteke s podacima predstavlja jedan luk grafa.Svaki luk ima strukturu X Y U gdje X predstavlja početni vrh, Y predstavlja krajnji vrh, a U predstavlja dužinu luka između X i Y.
