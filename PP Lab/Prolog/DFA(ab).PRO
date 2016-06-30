domains
    A, Q, QN = integer.
    Num, Rest = char*.
predicates
    D(integer,integer,integer).
    F(integer).
    accept(integer, Num).
clauses
    F(2) :- !.
    D(0,'b',0).
    D(0,'a',1).
    D(1,'a',1).
    D(1,'b',2).
    D(2,'a',2).
    D(2,'b',2).
    accept(Q, [A|Rest]) :- D(Q, A, QN), accept(QN, Rest).
    accept(X,[]) :- F(X).
