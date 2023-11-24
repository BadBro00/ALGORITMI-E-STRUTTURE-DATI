
**Ricorrenze**
---
**Derivazione della ricorrenza**
	Per derivare le relazioni di ricorrenza per la complessità di un algoritmo $T(n)$ è necessario:
	1. Determinare le dimensioni di un input
	2. Determinato quale valore di n, indicato con $n_0$, viene usato come caso base della ricorsione
	3. Determinare la complessità $T(n_0)$ del caso base della ricorsione (solitamente è $O(1)$)

**Metodi di Risoluzione**
	Esistono quattro metodi:
	1. Metodo di **Sostituzione**
	    Si basa sul fare una supposizione della soluzione, e verificare se esiste una costante per cui è vera tale supposizione
	2. Metodo **dell’Albero**
	    Si srotola la ricorrenza formando un albero di ricorsione, e si calcola il costo totale dell’albero (somma dei costi di ciascun livello)
	3. **Master Theorem**
	    Fornisce il costo dell’algoritmo, quindi la soluzione della ricorrenza, se vengono soddisfatte alcune condizioni
	4. Metodo **Iterativo**
	    Si riconduce la ricorrenza ad una serie numerica nota, e si ottiene così la soluzione

### Metodo Iterativo

$$ T(n) = T(n-1)+\Theta(1) \\ = T(n-2)+\Theta(1)+\Theta(1) \\ = ... \\ T(n) = \sum_{i=1}^n \Theta(1) = \Theta(n) $$

### Metodo di Sostituzione

$$ T(n) = 3T(\lfloor\frac{n}{3}\rfloor)+n $$
*Soluzione*
	La ricorrenza ricorda quella del merge sort, quindi possiamo ipotizzare che sia
	$T(n) = O(n\log_2n)$
	Ipotizzando che sia vera per $\frac{n}{3}$:
	$T(\lfloor\frac{n}{3}\rfloor)\le c\lfloor\frac{n}{3}\rfloor\log_2\lfloor\frac{n}{3}\rfloor$
	Sostituendo, abbiamo quindi:
	$T(n) \le c\lfloor\frac{n}{3}\rfloor\log_2\lfloor\frac{n}{3}\rfloor \\ \le cn\log_2\frac{n}{3}+n\\ \le cn\log_2n-cn\log_23+n\\ \le cn\log_2n-n(c\log_23-1) \\ \le cn\log_2n \ , c\ge\frac{1}{\log_23}$
	Un aiuto a questo metodo è sicuramente quello di ipotizzare una soluzione di una ricorrenza simile vista in passato.

---

**FINEZZE**
*Ordine Minore*
	Alcune volte, è possibile ipotizzare correttamente un limite asintotico per la nostra ricorrenza, ma in qualche modo i calcoli non tornano.
	Normalmente, l’ipotesi induttiva non è abbastanza forte, ed in tal caso va _corretta_, sottraendo un termine **di ordine inferiore** per verificare l’ipotesi
	$T(n) = T(\lfloor\frac{n}{2}\rfloor)+T(\lceil\frac{n}{2}\rceil)+1$
	Supponiamo $T(n) = O(n)$
$$ T(n) \le c\lfloor\frac{n}{2}\rfloor+c\lceil\frac{n}{2}\rceil+1 \\ \le cn+1 $$
	Ciò però non implica che $T(n)\le cn \ , \forall c$
	La nostra ipotesi non funziona, _per la presenza della costante 1_
	La nuova ipotesi è $T(n) \le cn-d \ , d\ge 0$
	$T(n) \le (c\lfloor\frac{n}{2}\rfloor)-d)+(c\lceil\frac{n}{2}\rceil-d)+1 \\ \le cn-2d+1\le cn-d \ , \forall d\ge 1$

*Sostituzione di Variabili*
	Consideriamo la ricorrenza
	$T(n) = 2T(\sqrt n)+\log_2n$
	Se operiamo $\log_2n=m$:
	$T(2^m)=2T(2^\frac{m}{2})+m$
	Se poniamo:
	$S(m) = 2S(\frac{m}{2})+m$, che ha come soluzione $S(m) = O(m\log m)$, sostituendo abbiamo:
	$T(n) = O(\log n \log\log n)$

**Master Theorem**
---
*Definizione*
	Il MT fornisce i limiti per ricorrenze della forma:
		$T(n) = aT(\frac{n}{b})+f(n)$
		con $a\ge 1, b>1$, e $f(n)$ è nota
	Il MT fo$T(n) = \Theta(f(n))$rnisce tre casi con le relative soluzioni. Se la ricorrenza è di una di queste forme, possiamo dire a quanto equivale $T(n)$

**PRIMO CASO**
	$Se \ f(n) = O(n^{\log_ba-\epsilon}) \ , \epsilon>0$ $\implies T(n) = \Theta(n^{\log_ba})$

---

**SECONDO CASO**
	$Se \ f(n) = \Theta(n^{\log_ba}) \implies$ $T(n) = \Theta(\log n*n^{\log_ba})$

---

**TERZO CASO**
	$Se \ f(n)=\Omega(n^{\log_ba+\epsilon}), \epsilon>0\\ \land \ af(\frac{n}{b})\le cf(n) \ c<1 \land n\ge n_0 \implies T(n) = \Theta(f(n))$

---
Esiste anche un *caso bonus*, che in realtà è l'estensione del primo caso:

**CASO BONUS**
	$Se \ f(n)=\Theta(n^{\log_ba}*(\log n)^k) \ k>0 \implies$
	$T(n) = \Theta(n^{\log_ba}*(\log n)^{k+1})$

---
**Albero di Ricorsione**
	Data la ricorrenza:
	$T(n) = 3T(\frac{n}{4})+\Theta(n^2)$
	Cerchiamo una soluzione.
	Supponiamo per semplicità che $n = 4^k$
	Srotolando l’albero, avremo una figura pari a :
	![[Pasted image 20231124092451.png]]
	Poichè le dimensioni dei sottoproblemi diminuiscono di un fattore 4 ogni volta che scendiamo di un livello, alla fine troveremo foglie con il caso base.
	_A quale distanza dalla radice troveremo una foglia?_
		La dimensione del sottoproblema per un nodo alla profondità i è $\frac{n}{4^i}$
		Quindi la radice ha profondità i tale che
		$\frac{n}{4^i}=1 \implies i=\log_4n$
		L’albero ha quindi $\log_4n+1$ livelli (**ALTEZZA**)
		![[Pasted image 20231124092512.png]]
		Il costo del livello finale è $T(n)=(\frac{3}{16})^i*cn^2$.
		L'ultimo livello si trova a profondità $\log_4(n)$, ed ha costo:
		$(\frac{3}{16})^i*cn^2$ con $i=\log_4n$, quindi $$(\frac{3}{16})^{\log_4 n}*cn^2=\\ \frac{3^{\log_4 n}}{16^{\log_4 n}}*cn^2 \\ = 3^{\log_4 n}/4^{2*\log_4 n}*cn^2 \\ = 3^{\log_4 n}/4^{{\log_4 n}^2}*cn^2 \\ = 3^{\log_4 n}*c*\frac{n^2}{n^2} \\ = c*3^{\log_4 n} \\ = c*n^{\log_4 3} \\ =\Theta(n^{\log_4 3})$$
	**Costo Totale**
	Sommando il costo di ogni livello:
	$T(n) = \sum_{i=0}^{\log_4n-1}(\frac{3}{16})^i*cn^2+\Theta(n^{\log_43}) = \frac{(\frac{3}{16})^{\log_4n}-1}{\frac{3}{16}-1}cn^2+\Theta(n^{\log_43})$
	Ma è troppo complessa per ottenere un’ipotesi per il nostro metodo di sostituzione, per cui usiamo un’approssimazione:
	$$T(n) = \sum_{i=0}^{\log_4n-1} (\frac{3}{16})^icn^2+\Theta(n^{\log_43}) \\ < \sum_{i=0}^\infty (\frac{3}{16})^icn^2+\Theta(n^{\log_43})\\ < \frac{1}{1-\frac{3}{16}}cn^2+\Theta(n^{\log_43}) \\ < cn^2$$
	Quindi $T(n) = O(n^2)$

Tale ipotesi va comunque **verificata**:
	$$ T(n) \le 3T(\frac{n}{4})+cn^2 \\ \le3d\frac{n^2}{4}+cn^2\\ \le \frac{3}{16}dn^2+cn^2\\ \le \frac{3}{16}dn^2+\frac{13}{16}dn^2-\frac{13}{16}dn^2+cn^2 \\ \le dn^2 $$
	Basta scegliere $d \ | \ c \le \frac{13}{16}d$

**ALBERO BILANCIATO**
	Se dividendo il sottoproblema in N parti, avremo N figli da ciascun nodo,
	In questo caso, il costo è $T(n)=O(f(n)*\log n)$

**ALBERO NON BILANCIATO**
	Se dividendo il sottoproblema in N parti, avremo M figli ($M\ne  N$) da ciascun nodo.
	In questo caso, il costo è $T(n)=O(f(n))$

---
