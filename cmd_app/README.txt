Tegu on käsureal töötava kalkulaatoriga. Saab pikki ja lühikesi matemaatilisi võrrandeid sisestada ning programm väljastab õige vastuse.

Kompileerimine ja programmi käivitamine:
Programm läheb tööle, kui avada main.exe. Kui teha koodis muudatusi, siis kompileerida saab 'make' käsuga.

Mida saab sisestada:
Programm aksepteerib järgmisi sisendeid:
* arvud, nii täisarvud kui ka kümnendmurrud;
* +, -, *, /, ^, %, (, );
* pi ja e;
* exp(x), kus x on mingi arv. Funktsiooni väärtus on e^x;
* exp10(x), kus x on mingi arv. Funktsiooni väärtus on 10^x;
* ln(x), kus x on mingi mittenegatiivne arv. Tagastab naturaallogaritmi;
* log(x), kus x on mingi mittenegatiivne arv. Tagastab logaritmi alusega 10;
* sqrt(x), kus x on mingi mittenegatiivne arv. Tagastab ruutjuure;
Neid tehteid saab omavahel kombineerida, nt 3+4*5-sqrt(49)/ln(e).

Programm suudab käsitleda ka valesid sisendeid, visates vastava errori, nt kui tahetakse nulliga jagada või sulud pole tasakaalustatud.


Edasiareng:
Lõppversioonis implementeerime ka graafilise liidese, et saaks seda kasutada kui tavalist kalkulaatorit. Samuti lisame veel funktsioone, nt trigonomeetrilised funktsioonid.