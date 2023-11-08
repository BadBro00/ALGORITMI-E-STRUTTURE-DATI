**ANALISI Insertion Sort**
---
*Codice*
```cpp
1. For j<-2 to A.length
2.    Key<-A[j]
3.    i<-j-1
4.    while(i>0 and A[i]>key)
5.       do A[i+1]<-A[i]
6.          i<-i-1
7.    A[i+1]<-key
```

**Costi istruzioni**
	1. $c_1n$
	2. $c_2(n-1)$
	3. $c_3(n-1)$
	4. $c_4$
	5. $c_5$
	6. $c_6$
	7. $c_7(n-1)$

**Caso Favorevole**
	Il caso favorevole si ha quando l’input **è gia ordinato**. In questo caso, il loop non viene eseguiro, e si esegue unicamente il for.
	Il tempo d’esecuzione è quindi:
	$T(n) = c_1n+(c_2+c_3+c_7)(n-1) = O(n)$

**Caso Peggiore**
	Il caso peggiore si ha quando l’input è ordinato **in modo decrescente**. In questo caso, sia il for che il while dovranno essere eseguiti fino alla fine dell’array.
	In questo caso, il tempo d’esecuzione dell’algoritmo è dato da:
	$T(n) = P(n)+c_4\sum_{j=2}^n(j)+(c_5+c_6)\sum_{j=2}^n(j-1)$
	Ma abbiamo che, per Gauss bambino:
	$\sum_{j=2}^nj = \sum_{j=1}^n j+1-1 =\\ \sum_{j=1}^n (j-1) = \frac{n(n+1)}{2}-1$
	Per lo stesso ragionamento:
	$\sum_{j=2}^n(j-1)=\sum_{j=2}^nj-\sum_{j=2}^n1 = \frac{n(n+1)}{2}-1-(n-1)=\frac{n(n-1)}{2}$
	Avremo quindi che:
	$T(n) = P(n)+\Theta(n^2)+\Theta(n^2) = \Theta(n^2)$

**Caso Medio**
	Il caso medio si ha quando l’input è ordinato in modo decrescente, ma non del tutto.
	In questo caso, il for opera su tutto l’array, mentre il while non dovrà svolgere tutte le iterazioni.
	Il tempo di esecuzione è quindi dato da:
	$T(n) = P(n) + c_4\sum_{j=2}^n\frac{j}{2} +(c_5+c_6)\sum_{j=2}^n\frac{j-1}{2}$
	Si ha che:
	$\sum_{j=2}^n\frac{j}{2} = \frac{1}{2}\frac{n(n+1)}{2}-1$
	$\frac{1}{2}\sum_{j=2}^n(j-1)=\frac{1}{2}\sum_{j=2}^nj-\sum_{j=2}^n1 = \frac{1}{2}[\frac{n(n+1)}{2}-1-(n-1)]=\frac{1}{2}\frac{n(n-1)}{2}$
	Quindi, il tempo d’esecuzione vale
	$T(n) = P(n)+\Theta(n^2)+\Theta(n^2)=\Theta(n^2)$
	Per questo motivo, l’Insertion sort è indicato solo per input di piccola taglia.

---
**Divide Et Impera**
	La tecnica di programmazione DEI ha i seguenti passi:
	1. **Divide (**il problema in sottoproblemi)
	2. **Impera** (i sottoproblemi vengono risolti)
	3. **Combina** (le soluzioni dei sottoproblemi vengono combinate)
	L’approccio DEI è **top-down**

**Merge Sort**
	Il merge sort è un algoritmo _stabile_, ovvero mantiene l’ordine iniziale di input degli elementi, uguale nel sottoarray ordinato di output. Non effettua scambi, e la complessità è
	$T(n) = \Theta(nlogn)$

**Funzionamento**
	L’algoritmo esegue i seguenti passaggi:
	1. Dividi l’array in due sottoarray di ca metà lunghezza (**DIVIDE**)
	2. **ORDINA**, mediante chiamate ricorsive alla funzione, i due sottoarray
	3. Esegui il _Merge_ dei due sottarray ordinati (**COMBINA**)
```c++
if p<q then
	r<-[(p+q)/2]
	MergeSort(A,p,r)
	MergeSort(A,r+1,q)
	Merge(A,p,q,r)

```

**Merge**
	L’algoritmo di merging può essere implementato in due modi:
	1. Merge **a due vie**
	2. **Astratto sul posto**
	*Cormen*
	Il cormen propone un merge sul posto con _sentinelle_.
	Utilizza una procedura ausiliaria **MERGE(A,p,q,r)** dove
	$p,q,r \in \R^+ \ | \ p\le q \le r$
	La procedura assume che A[p…q] e A[q+1,…r] sono ordinati, e impiega $T(n) = \Theta(n)$, con $n=r-p+1$
```c++
n1<-q-p+1
n2<-r-q
//Crea due array L[1,..,n1+1] e R[1...n2+1]
for i<-1 to n1
	L[i]<-A[p+i-1]
for j<-1 to n2
	R[j]<-A[q+j]
L[n1+1]<-+∞
R[n2+1]<-∞
i<-1
j<-1
for k<-p to r
	if L[i] <= R[j] then
		A[k]<-L[i]
		i<-i+1
	else
		A[k]<-R[j]
		j<-j+1
```

**Invariante di Ciclo**
	All’inizio di ogni iterazione del for, il sottoarray A[p,…,k-1] contiene, ordinati, i k-p elementi più piccoli di L[1,…,n1+1] e R[1,…,n2+1].
	Inoltre, L[i] ed R[j] sono i più piccoli elementi dei loro array non ancora copiati in A
	*Inizializzazione*
		Prima dell’iterazione di ogni ciclo, abbiamo $k=p$, quindi il sottoarray A[p,..,k-1] è vuoto, e contiene i $k-p=0$ elementi più piccoli di L ed R.
		Inoltre, poichè $i=j=1$, L[i] ed R[j] sono i più piccoli elementi degli array che non sono ancora stati copiati in A.
	*Conservazione*
		Supponiamo che $L[i]\le R[j]$, quindi L[i] è l’elemento più piccolo non ancora copiato in A.
		Poichè A[p,..,k-1] contiene i k-p elementi più piccolo, dopo aver copiato L[i] in A[k], il sottoarray A[p,..,k] conterrà i k-p+1 elementi più piccoli. Incrementando k e i, si ristabilisce l’invariante di ciclo per la prossima iterazione.
		Se è $L[i]>R[j]$, il ragionamento è simile al precedente. Sono le righe 16-17 che permettono di conservare l’invarianza di ciclo.
	*Conclusione*
		Alla fine del ciclo, $k=r+1$.
		Per l’invariante, il sottoarray A[p,..,k-1] contiene i $k-p=r-p+1$ elementi ordinati che sono più piccoli di L ed R.
		Insieme, gli array contengono $r-p+3$ elementi. Tutti gli elementi, tranne i due più grandi (le sentinelle),

**Complessità**
	Per verificare che la procedura **MERGE** viene eseguita in $\Theta(n)$, basta osservare che le rr 1-3 e 8-11 impiegano un tempo costante, ed i cicli in rr-4-7 impiegano un tempo $\Theta(n_1+n_2)=\Theta(n)$, e ci sono n iterazioni del ciclo for, rr 12-17

**MergeSort**
	La procedura ordina gli elementi nel sottoarray A[p,..,r]. Se $p\ge r$, il sottoarray ha al più un elemento; altrimenti, il passo divide calcola semplicamente un indice q che separa l’array A[p,…,r] in due sottoarray, che contengono rispettivamente $\lfloor\frac{n}{2}\rfloor \ e \ \lceil\frac{n}{2}\rceil$ elementi.

**Analisi algoritmi DEI**
---
**Ricorrenze DEI**
	Quando un algoritmo contiene una chiamata ricorsiva, il suo tempo d’esecuzione va espresso con una _ricorrenza_, ovvero un’equazione che esprime il tempo di esecuzione totale di un problema in funzione del tempo d’esecuzione per input più piccoli.
	Una ricorrenza per il tempo d’esecuzione di un algoritmo DEI si basa sui tre passi del paradigma:
	Se la dimensione del problema è sufficientemente piccola, ad es $n\ge c$, la soluzione richiede un tempo costante $\Theta(1)$
	Supponiamo che la suddivisione generi sottoproblemi di dimensione $\frac{1}{b}$ volte quella del problema originale. E’ quindi necessario $T(\frac{n}{b})$ per risolvere un sottoproblema di dimensione $\frac{n}{b}$, e quindi per risolverne a, si necessita di $a*T(\frac{n}{b})$. Infine, impieghiamo un tempo $D(n)$ per dividere il problema, ed è necessario un tempo $C(n)$ per combinare le soluzioni nella soluzione del problema originale
	Si ottiene così la ricorrenza:
	$$ T(n) = \begin{cases} \Theta(1) \ ,n\le c \\ aT(\frac {n}{b})+D(n)+C(n) \ else \end{cases} $$
**Analisi MergeSort**
	Nel caso del MergeSort, ogni passo divide genera due sottosequenze, di dimensione $\frac{n}{2}$
	L’algoritmo applicato ad un solo elemento ha un tempo costante pari a $\Theta(1)$
	Se abbiamo $n>1$ elementi, suddividiamo il tempo d’esecuzione nel modo seguente:
	Dividi:
		Questo passo calcola semplicemente il centro del sottoarray $\implies \Theta(1)$
	Impera:
		Risolviamo in modo ricorsivo i due sottoproblemi di dimensione $\frac{n}{2}$, con tempo totale d’esecuzione
	Combina
		La procedura merge impiega $\Theta(n)$
	Quando sommiamo $\Theta(n)+\Theta(1)=\Theta(n)$, quindi avremo che:
	$$ T(n) = \begin{cases}c \ , n=1 \\ 2T(\frac{n}{2})+cn \ , n>1\end{cases} $$

Per comodità, supporremo che $n=2^k$.

Andando man mano a _srotolare_ la ricorrenza, ovvero il tempo $2T(\frac{n}{2})$, otteniamo via dei nodi di tempo che simboleggiano il costo del nostro algoritmo. Da questi nodi si può ricavare un **albero di ricorsione**, in cui ciascun nodo è il costo di un sottoproblema, mentre le foglie sono le istanze base del problema, che costano $\Theta(1)$.

**Costi**
	Sommiamo i costi per ogni livello dell’albero.
	Il primo livello ha un costo $cn$.
	Il secondo livello ha costo $\frac{cn}{2} + \frac{cn}{2}=cn$, e così via.
	In generale, il livello i-simo ha $2^i$ nodi, ognuno con costo $c*\frac{n}{2^i}$, quindi il costo totale del livello è $c*n$.
	All’ultimo livello, abbiamo n nodi foglia, di costo $\Theta(1)$, quindi $n*\Theta(1) = \Theta(n) = c*n$.
	Il numero totale di livelli è $\log_2(n)+1$, dove n è la taglia dell’input.
	Per calcolare il costo totale della ricorrenza, va effettuato il calcolo $(c_n)_[\log_2(n)+1]=c*n(\log_2n+1)=\Theta(nlogn)$
	Tale risultato vale in tutti e tre i casi.

---

