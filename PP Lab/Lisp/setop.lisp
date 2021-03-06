(defun i(a b)
(let ((inter nil))
(dolist(x a inter)
(if (member x b)
(push x inter)
)
)
)
)

(defun u(a b)
(let ((union nil))
(dolist(x a union)
(unless (member x b)
(push x union)
)
)
(append union b)
)
)

(defun s(a b)
(format t "~%enter the elements to be searched:~%")
(setf x(read))
(if(member x a)
(format t "~%element in A ~%")
)
(if(member x b)
(format t "~%element in B ~%")
)
(when (and (not (member x a))(not (member x b))
(format t"~%element not found..~%")
)
)
)

(defun main(a b)
(princ "intersection is:")
(princ(i a b))
(format t "~%")
(princ "union is:")
(princ(u a b))
(s a b)
)

