
(defun quicksort(list)
	(when(<= (length list) 1) 
		(return-from quicksort list))
	(let 
		((pivot (car list))
		(to-be-sorted (cdr list))
		(less nil)
		(greater nil)
	)
	(loop for i in to-be-sorted do
		(if(< i pivot) 
			(push i less)
		(push i greater))
	)
	(append (quicksort less) (list pivot) (quicksort greater))
)
)

