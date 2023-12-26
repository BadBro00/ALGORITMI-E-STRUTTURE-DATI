$T(n)=T(n-1)+n$

$T(n-1)=T(n-2)+(n-1)$

$\implies T(n)=T(n-2)+(n-1)+n$
$\implies T(n-k) = T(n-k-1) + (n-k)$

$\implies T(n) = \sum_{k=1}^n i$

$\implies T(n) = \frac{n(n+1)}{2} = O(n^2)$
