------------------------------------|METODO DI SOSTITUZIONE|---------------------

Consiste nel risolvere la ricorrenza tentando di trovare una soluzione che, sostituita nell'equazione di ricorrenza, fornisca un risultato valido.
La soluzione viene trovata logicamente, deducendo l'andamento della ricorrenza, o provando ad indovinare la soluzione.

$T(n)=T(\frac{n}{2})+1$

MDS:
  1. Controllare il termine noto $f(n)$, che fornisce sempre un indizio per la risoluzione della ricorrenza
  2. Definire l'andamento generale dell'equazione di ricorrenza, per capire se la prima idea risolutiva era corretta
  3. Controllare se la soluzione trovata viene sostenuta da una $c>0$ tale che vale la sostituzione

----------------------------------
Nel nostro caso:

$f(n) = 1$ , che non fornisce una buona approssimazione.
Notiamo però che la ricorrenza ha forma simile a quella del **Merge-Sort**, e quindi possiamo supporre $T(n)=O(logn)$

Fatta questa supposizione, avremo:

$T(n) \le c* log(\frac{n}{2})+1$

$\le c* logn - c*log3 + 1$

$\implies -clog3+1\ge 0$

$\implies c\le \frac{1}{log3}$
