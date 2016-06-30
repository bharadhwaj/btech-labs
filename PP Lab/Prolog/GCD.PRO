domains
I, J, R, L=integer.
predicates
gcd(integer,integer).
clauses
gcd(0,0):-write("Invalid entry"),nl.
gcd(I,0):-write("GCD:",I),nl.
gcd(I,J):-R=I mod J,
gcd(J,R).