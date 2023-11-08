# ALGORITMI DEI



**QuickSort**
	Il quicksort è l’algoritmo di ordinamento che generalmente ha _prestazioni migliori tra quelli basati su confronto_. Gli svantaggi sono dati dal fatto che **non è stabile**, e nel caso peggiore ha $T(n) = \Theta(n^2)$
	Il quicksort ha come input un vettore
	$A_p,A_{p+1},...,A_r$
	e restituisce una **permutazione** del vettore tale che
	$A_p^1 \le ... \le A_r^1$
	L’algoritmo consta di tre passi:
	1. **Divide** nel quale il vettore di ingresso $A(p,r)$ viene diviso in due sottovettori $A(p,q) \ \land \ A(q+1,r)$ tali che:
	2. **Impera** nel quale i due sottovettori vengono ordinati _con chiamate ricorsive_
	3. **Combina** nel quale i due sottovettori ordinati vengono fusi, producendo l’output desiderato
```c++
QuickSort(A,p,r)
1. if p<r then
2.    q<-Partition(A,p,r)
3.    QuickSort(A,p,q)
4.    QuickSort(A,q+1,r)

Partition(A,p,r) //HOARE
1. x<-A[p]
2. i<-p-1
3. j<-r+1
4. while true do
5-    repeat j<-j-1
6.    until A[j] <= x
7.    
```

Un’altra partition è la seguente:
```c++
Partition(A,p,r)
1 x<-A[r]
2 i<-p-1
3 for j<-p to r-1
4	do if A[j] <= x
5		then i<-i+1
6			scambia A[i]<=>A[i+1]
7 scambia A[i+1]<=>A[r]
8 return i+1
```

**Invariante di Ciclo**
	All’inizio di ogni iterazione del ciclo, _per qualsiasi indice k dell’array_, si ha:
	1. Se $p\le k \le i \implies A[k] \le x$
	2. Se $i+1\le k \le j-1 \implies A[k] > x$
	3. Se $k=r \implies A[k] = x$
	Gli indici $j$ ed $r-1$ **non rientrano in alcuno dei tre casi**, e i corrispondinti valori in queste posizioni _non hanno una particolare relazione col pivot x_

**Inizializzazione**
	Prima della prima iterazione, $i=p-1 \ \land \ j=p$. **Non ci sono valori fra p ed i**, **nè fra i+1 e j-1**, quindi le prime due condizioni sono verificate. _La terza condizione è assicurata dalla riga 1_

**Conservazione**
	Quando $A[j]>x$, si ricade nel _caso in cui stiamo considerando gli elementi fra i e j_
	L’unica azione è _incrementare j, e dopo il suo incremento, la condizione 2 è soddisfatta per $A[j-1]$_, e tutte le altre posizioni non cambiano
	Nell’altro caso, **viene incrementato i, scambiati $A[i] \ e \ A[j]$, e poi viene incrementato j**. Dopo lo scambio, notiamo che $A[i] \le x$ e la condizione 1 è soddisfatta. Inoltre, abbiamo che $A[j-1] > x$, in quanto **l’elemento spostato è più grande di x**.

**Conclusione**
	Alla fine del ciclo, $j=r$. Pertanto, **ogni posizione dell’array si trova in uno dei tre insiemi** descritti dall’invariante, e noi _abbiamo ripartito i valori dell’array in tre insiemi_ distinti:
	1. Quello contenente gli elementi $\le x$
	2. Quello contenente gli elementi $> x$
	3. L’insieme di un solo elemento pari a $x$

**Analisi Quicksort**
	*Caso peggiore*
		Il caso peggiore si ha quando gli elementi sono ordinati _in modo crescente o decrescente._ In tal caso la **Partition()** produrra sempre un secondo vettore costituito da un solo elemento.
	In questo caso, il tempo richiesto è $T(n) = \Theta(n^2)$
		$$ T(n) = T(n-1)+\Theta(n) \\ = T(n-2)+\Theta(n)+\Theta(n-1) \\ T(n) = T(n-3)+\Theta(n)+\Theta(n-1)+\Theta(n-2) \\ ... \\ T(n) = \sum_{i=1}^n \Theta(i) = \Theta(\sum_{i=1}^n i= \Theta(\frac{n(n+1)}{2}) = \Theta(n^2) $$

**Caso Peggiore : MDS**
	Per semplicità, riscriviamo la ricorrenza come:
	$T(n) = T(n-1) + c*n$
	Verifichiamo prima che è $O(n^2)$ . Dimostriamo che $T(n)\le d(n^2)$.
	Sostituendo :
	Verifichiamo ora che è $\Omega(n^2)$. Dimostriamo che è $T(n)\ge e*n^2$.
	Sostituendo:
	$e(n-1)^2+c_n = e(n^2-2n+1)+c_n$
		$T(n)\ge e_n^2-e(2_n-1) + c_n \ge e_n^2 \ \forall e \ | \ c_n-e(2_n-1)\le \implies e<\frac{c_n}{e(2_n-1)}$
	Poichè abbiamo verificato che è $T(n) = \Omega(n^2)$ ed è anche $T(n) = O(n^2)$, si ha che $T(n) = \Theta(n^2)$

**Caso Migliore**
	Nel caso migliore, **Partition()** produce due sottoproblemi, ciascuno con dimensione non maggiore di $\frac{n}{2}$. La ricorrenza per il tempo di esecuzione diventa $T(n) = 2T(\frac{n}{2})+\Theta(n)$, che per il M.T. ha soluzione $\Theta(nlogn)$

**Partizionamento Bilanciato**
	Supponiamo che l’algoritmo di Partizionamento produca **sempre una ripartizione proprorzionale** **9:1**. In questo caso, si ha la ricorrenza:
	$T(n) \le T(\frac{9n}{10}) + T(\frac{n}{10}) + cn$
	Ogni livello ha costo $cn$ sino a quando non si raggiunge una profondità **p** tale che $(\frac{1}{10})^p*n=1 \implies p=\log_{10}(n)$.
	A partire da quel livello, i livelli hanno un costo $\le c*n$, ossia $O(n)$
	La ricorsione termina alla profondità **h** tale che $(\frac{9}{10})^h *n = 1 \implies h=\log_{\frac{9}{10}}(n) = \Theta(logn)$
	Pertanto, il costo totale del quicksort è $O(nlogn)$
	Anche una ripartizione **99:1** determina una complessità $O(nlogn)$
	La ragione è che **qualsiasi ripartizione con proporzionalità costante produce un albero di ricorsione di profondità** $\Theta(nlogn)$, dove il costo di ogni livello è $O(n)$
	Le prestazioni del Quicksort _dipendono dal perno_, poichè $x=A[r]$.
	Pertanto, una buona pratica può essere quella di scambiare, **prima di eseguire la partition**, il primo elemento con uno scelto a caso.
In questo caso si ha

**Randomized Quicksort**
```c++
RANDOMIZED_qUICKSORT(A,p,r)
if p<r
	q<-Randomized_Partition(A,p,r)
	Randomized_Quicksort(A,p,q)
	Randomized_Quicksort(A,q+1,r)

RANDOMIZED_PARTITION(A,p,r)
i<-Random(p,r)
//Scambia A[i] con A[r]
Partition(A,p,r)

```

**Analisi Random_Quicksort**
---
**Caso Peggiore**
	Dimostriamo che nel caso peggiore si ha un tempo $T(n) = \Theta(n^2)$.
	Utilizziamo il metodo di sostituzione per dimostrare che il tempo d’esecuzione è $O(n^2)$
		Sia T(n) il tempo nel caso peggiore per la procedura QUICKSORT con input di dimensione n. Allora la ricorrenza è:
		$T(n) = max_{0\le q\le n-1} (T(q) +T(n-q-1)) + \Theta(n) \le c*max_{0\le q\le n-1} (q^2+(n-q-1)^2) + \Theta(n)$
		Ora, l’espressione $q^2+(n-q-1)^2$ è **massima nei due estremi dell’intervallo** $[0,n-1]$, perchè **la derivata rispetto a q si annulla in un solo punto**, che è un minimo.
		Sostituendo al posto di $q(n-1)$ abbiamo:
		$T(n)\le c*(n-1)^2+c*(n-(n-1)-1^2 +\Theta(n)\le c*(n-1)^2)+\Theta(n)\le cn^2-c(2n-1)+\Theta(n)\le c*n^2$
		Basta scegliere un $c \ | \ c(2n-1)-\Theta(n) > 0$
	Utilizziamo il MDS per dimostrare che il tempo d’esecuzione è $\Omega(n^2)$.
		I calcoli sono analoghi, ottenendo:
		$T(n)\ge c(n-1)^2+\Theta(n)\\ \ge cn^2 -c(2n-1)+\Theta(n) \\ \ge cn^2$
		Basta scegliere un $c \ | \ \Theta(n)-c(2n-1)>0$
	Quindi, $T(n) = O(n^2) \land T(n) = \Omega(n^2) \implies T(n) = \Theta(n^2)$

**Valore Atteso**
	In teroia delle probabilità, il valore atteso di una variabile aleatoria (**casuale**) è un numero, indicato con $E[x]$. Formalizza il concetto di _valore medio di un fenomeno aleatorio_.

**Variabili Aleatorie Continue**
	Il valore atteso di una variabile aleatoria è dato **dalla somma dei possibili valori di tale variabile, ciascuno moltiplicato per la probabilità di essere assunto,** cioè _la media ponderata dei possibili risultati_.
	Nel caso di una variabile aleatoria **continua** che ammette come _funzione di probabilità_ $f(x)$ , il valore atteso è
	$$ E[x] = \int_{-\infty}^{+\infty} x*f(x) dx $$

**Variabili Aleatorie Discrete**
	Nel caso di una variabile discreta, che ha _funzione di probabilità_ $p_i$ allora:
	$E[x] = \sum_{i=1}^{+\infty} x_i*p_i$
	La media è **un caso particolare** del valore atteso, quando il numero dei valori è N, e la probabilità per ogni valore è $p_i=\frac{1}{N}$

**Proprietà del valore atteso**
	*Valore Atteso di una Costante*
		Il valore atteso di una variabile aleatoria costante **è ancora la costante stessa** $E[c]=c$
	*Linearità*
		$E[aX+bY] = a_E[X]+b_E[Y] \ a,b \ cost \land X,Y$ var. Aleatorie

**Tempo d’Esecuzione Atteso**
	Quicksort e Randomized Quicksort differiscono solo nel modo in cui **viene scelto il pivot,** per il resto sono identiche.
	Analizzeremo le procedure **Partition()** e **Quicksort()** assumendo che ogni volta il perno **sia scelto in modo casuale**
	Il tempo d’esecuzione di Quicksort è dominato dal tempo che impiega la procedura **partition.** Una chiamata di Partition impiega $O(1)$ **più una quantità di tempo proporzionale al numero di iterazioni del for**, rr 3-6
```c++
Partition(A,p,r)
1.x<-A[r]
2.i<-p-1 
3.for j<-p to r-1
4.  do if A[j]<=x
5.    then i<-i+1
6.       scambia A[i],A[j]
7.scambia A[i+1],A[r]
8.return i+1
```
Ogni iterazione di questo for effettua un confronto tra il **pivot** ed un elemento qualunque dell’array, pertanto vale il seguente **LEMMA**:

**T(n) del Quicksort**
---
Se X è il numero di confronti svolti dalla riga 4 di Partition, nell’intera esecuzione del Quicksort su un array di n elementi, allora:
	$T(n) = O(n+X)$

*Calcolare X*
	Non calcoleremo **esattamente** X, ma _deriveremo un limite superiore sul numero globale dei confronti_. Abbiamo pertanto necessità di capire **quando viene effettuato un confronto** fra due elementi dell’array
	Rinominiamo $z_1,z_2,...,z_n$ gli elementi dell’array, dove $z_i$ è l’i-simo elemento **più piccolo**.
	Definiamo $Z_{i,j} = \{z_i,z_{i+1},...,z_j\}$ l’insieme degli elementi compresi tra $z_i \ e \ z_j$
	Utilizzando una variabile indicatrice, definiamo $X_{i,j}=I\{z_i$ è confrontato con $z_j\}$
	Stiamo considerando **tutti** i confronti fatti dall’algoritmo, _non solo durante un’iterazione o chiamata di partition ._
	Poichè una coppia viene confrontata _al più_ una sola volta, il numero **totale** dei confronti è dato da:
	$X = \sum_{i=1}^{n-1}\sum_{j=i+1}^nX_{ij}$
	Prendendo i valori attesi da entrambi i lati, otteniamo
	$E[X] = E[\sum_{i=1}^{n-1}\sum_{j=i+1}^nX_{ij}] = \sum_{i=1}^{n-1}\sum_{j=i+1}^nE[X_{ij}]$
	$E[X_{ij}]$ è dato dalla probabilità con cui $z_i$ è confrontato con $z_j$.
	La nostra analisi suppone che ogni pivot **sia scelto in modo casuale ed infipendente**. E’ utile riflettere su quando _due elementi non sono confrontati_
	In generale, una volta che viene scelto un **pivot** x, con $z_i<x<z_j$, sappiamo che $z_i$ e $z_j$ _non potranno essere confrontati in un istante successivo_.
	Se viene scelto $z_i$ come pivot, prima di qualsiasi elemento di $Z_{ij}$, verrà confrontato con tutti gli elementi **tranne che con se stesso**
	Il tutto è _analogo se si sceglie come perno $z_j$._ Quindi, i due elementi sono confrontanti **se e solo se il primo termine ad essere scelto sarà uno dei due**.
	Poiche l’insieme ha $j-i+1$ elementi, _la probabilità che qualsiasi elemento sia scelto per primo come pivot è $\frac{1}{j-i+1}$._ Pertanto, la probabilità di confronto tra $z_i$ e $z_j$ è $E[X_{ij}]=\frac{2}{j-i+1}$
	Sostituendo, otteniamo:
	$E[X] = \sum_{i=1}^{n-1}\sum_{j=i+1}^nE[X_{ij}] = \sum_{i=1}^{n-1}\sum_{j=i+1}^n\frac{2}{j-i+1}=\sum_{i=1}^{n-1}\sum_{k=1}^n\frac{2}{k+1} \\ < \sum_{i=1}^{n-1}\sum_{k=1}^n\frac{2}{k}<\sum_{i=1}^{n-1}\sum_{k=1}^nlog(n)$
	$E[X]=\sum_{i=1}^{n-1}O(logn) = O(nlogn)$
	Pertanto, il **Randomized Quicksort** ha un tempo d’esecuzione atteso di $E[T(n)]=O(nlogn)$, quando **i valori degli elementi attesi sono distinti**

**Heapsort**
	L’idea di base dell’Heapsort è quella di usare **una nuova struttura dati**, detta _heap_. per ordinare un array.
	Il suo costo computazionale è $O(nlogn)$, e il concetto di Heap **può essere usato per implementare le Priority Queue**

**Albero Binario**
	Un albero binario T è definito come
> 	Un insieme finito di nodi che può essere **vuoto**, o composto da **tre insiemi disgiunti di nodi** :
		1. Un nodo da cui parte l’albero, e viene detto **radice**
		2. Un albero binario, ovvero **il sottoalbero binario destro**
		3. Un albero binario, ovvero **il sottoalbero biario sinistro**

*Profondità*
	La **Profondità** di un nodo è **la lunghezza del percorso partendo dalla radice ed arrivando al nodo**, ovvero _il numero degli archi attraversati_.
	L’ **Altezza** di un nodo è _l’inverso della profondità_
	Il _Livello_ in cui si trova un nodo è **l’insieme dei nodi alla stessa altezza**
	L’altezza dell’albero è dunque **l’altezza della radice**
	Il numero di figli è detto **grado** del nodo

*Albero Binario Perfetto*
	E’ un albero in cui tutte le foglie hanno la stessa altezza h, e tutti i nodi interni hanno grado 2.
	L’altezza dell’ABP è $\lfloor\log_2(n)\rfloor$, con n numero di nodi. Se l’altezza è h, il numero di nodi dell’albero sarà $2^{h+1}-1$

*Albero Binario Completo*
	Un albero avente tutte le foglie a profondità $h \ \lor \ (h-1)$, ed il numero dei nodi al livello $h-1$ dev’essere $2^{h-1}$.
	Tutti i nodi a livello h **sono accatastati a sinistra**, mentre tutti i nodi interni hanno grado 2.

**Alberi Binari Heap**
	Un albero è un **Max-Heap** se e solo se:
	$A[parent(i)]\ge A[i]$
	L’albero è un Albero Binaio Completo
	Viceversa, sarà un **Min-Heap** se e solo se:
	$A[parent(i)] \le A[i]$
	L’albero è un Albero Binario Completo
	Un albero Heap implementa un **ordinamento parziale**:
		1. **Riflessivo**
		2. **Asimmetrico**
		3. **Transitivo**

**Ordinamento Parziale**
	Utile per modellare gerarchie complesse, o mantenere informazioni parziali. E’ più **debole** dell’ordinamento totale, ma **più facile da costruire**.

**Array Heap**
	Dato un array $A[length]$, costruiamo un heap di dimensione $heapsize\le length$.
		1. $A[1]$ è la radice, dunque $parent(i)\leftarrow[\frac{i}{2}]$
		2. $Left(i)\leftarrow2_i \ \land \ Right(i) \leftarrow 2_i+1$
	Avendo dunque
		$A[i]\ge A[2i] \ \land \ A[i]\ge A[2i+1]$

**Procedure Heap**
---
Abbiamo tre procedure per la gestione di un Heap:
	1. **Max-Heapify** :
	    Complessità $O(logn)$, serve a **mantenere la proprietà dell’Heap**
	2. **Build-Max-Heap** :
	    Complessità $O(n)$, **costruisce un Heap da zero**
	3. **Heapsort** :
	    Complessità $O(nlogn)$, **ordina sul posto un array**

**Max-Heapify**
```c++
Max_Heapify(A,i)
1. l<-Left[i]
2. r<-Right[i]
3. if A[i]<A[l] and l <= A.heapsize
4.      then max<-l
5. else max<-i
6. if A[max] < A[r] and r <= A.heapsize
7.      then max<-r
8. if max != i
9.      then scambia A[i]<->A[max]
10.          Max_Heapify(A,max)

```
In entrambi i casi, la procedura crea un Albero Binario in cui vale la proprietà che $A[i] \ge A[2i] \implies$ Il figlio sinistro avrà valore minore del nodo considerato
	$A[i] \le A[2i+1] \implies$Il figlio destro avrà valore maggiore del nodo considerato

**Tempo Esecuzione Max-Heapify**
	Il tempo d’esecuzione della procedura Max-Heapify in un sottoalbero di dimensione n è pari a $\Theta(1)$ per le prime istruzioni, più il tempo necessarie per eseguire la **Max-Heapify** in un sottoalbero con radice in uno dei figli del nodo considerato.
	I sottoalberi dei figli hanno ciascuno una dimensione che non supera, **nel caso peggiore** i $\frac{2}{3}$ dell’intero albero
	*Caso Peggiore*
		Il caso peggiore si ha quando **il sottoalbero sinistro è completo al livello h**, ma il sottoalbero destro **è completo al livello h-1**. Pertanto, il sottoalbero sinistro ha $2^{h+1}-1$ nodi.
		Ma i nodi totali sono pari a $\#nodi\_sottoalb\_dx+\#nodi\_sottoalb\_sx+1$
		Ovvero:
			$N = (2^{h+1}-1)+(2^h-1)+1=3*2^h-1$
		Quindi, il rapporto fra i nodi del sottoalbero sinistro e quelli totali è dato da:
			$\frac{2*(2^h-1)}{3*(2^h-1)}\le\frac{2}{3}$

**Complessità Max-Heapify**
	E’ descritta dalla **ricorrenza** $T(n)\le T(\frac{2n}{3})+\Theta(1)$, che è risolvibile mediante il secondo caso del M.T. come $T(n) = \Theta(nlogn)$

---
