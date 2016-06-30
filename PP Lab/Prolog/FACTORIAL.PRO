domains
    N, X, R, F = integer.
predicates
    fact(N,F).
clauses
    fact(1,1) :- !.
    fact(N,F) :- X = N-1, fact(X,R), F = R * N.
     