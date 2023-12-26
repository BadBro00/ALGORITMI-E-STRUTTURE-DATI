-------------------------------------|Master Theorem|--------------------------

Il Master Thorem fornisce una soluzione (**già verificata**) per una ricorrenza del tipo:

$T(n) = a*T(\frac{n}{b})+f(n)$

Il M.T. si basa sul distinguere in quale dei 3 (+1) casi siamo.

----------------
Caso 1:

$f(n) = O(n^{log_b(a)-\epsilon}), \epsilon > 0$

$\implies T(n) = \Theta(n^{log_b(a)})$

----------------
Caso 2:
$f(n) = \Theta(n^{log_b(a)}) \implies T(n) = \Theta[logn * log_b(a)]$

---------------
Caso 3: 

$f(n)=\Omega(n^{\log_ba+\epsilon}), \epsilon>0 \ \land$

$\exists c<1 | af(\frac{n}{b})\le cf(n) \ c<1 \land n\ge n_0 \\ \implies T(n) = \Theta(n^{\log_ba}*(\log n)^{k+1})$
