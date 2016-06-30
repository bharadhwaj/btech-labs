domains
    A, Q, QN = integer.
    Num, Rest = integer*.
predicates
    D(integer,integer,integer).
    F(integer).
    accept(integer, Num).
clauses
    F(2) :- !.
    D(0,1,0).
    D(0,0,1).
    D(1,0,1).
    D(1,1,2).
    D(2,1,0).
    D(2,0,1).
    accept(Q, [A|Rest]) :- D(Q, A, QN), accept(QN, Rest).
    accept(X,[]) :- F(X).
