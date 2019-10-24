;;;;Function which checks if a list is linear - A
(DEFUN isLinearList(L)
      (COND
      ((NULL L) t)
      ((listp (car L)) NIL)
      (t (isLinearList (cdr L)))
       )
)

;;;;Function which change the value of an element with another (only first time) (B)

(defun change(l e1 e2)
    (COND
      ((null l) nil)
      ((equal (car l) e1) (cons e2 (cdr l)))
      ((and (listp (car l))(not (equal (car l) (change (car l) e1 e2)))) (cons (change (car l) e1 e2) (cdr l)))
      (t (cons (car l) (change (cdr l) e1 e2)))
    )
)


;;;(D)

;;;;Function which inverts a list
(defun invers_aux(l col)
 (COND
   ((NULL l) col)
   ((invers_aux (cdr l) (cons (car l) col)))
  )
  )

;;; Wrapper function for invers_aux
(defun invers(l)
  (invers_aux l nil)
  )


;;;Function for merging two sorted lists

(defun merge_aux(l a col)
  (cond
    ((and (NULL l) (NULL a)) (invers col))
    ((equal (car l) (car col)) (merge_aux (cdr l) a col))
    ((equal (car a) (car col)) (merge_aux l (cdr a) col))
    ((NULL l) (merge_aux l (cdr a) (cons (car a) col)))
    ((NULL a) (merge_aux (cdr l) a  (cons (car l) col)))
    ((<=(car a) (car l)) (merge_aux l (cdr a) (cons (car a) col)))
    ((< (car l) (car a)) (merge_aux (cdr l) a (cons (car l) col)))
    )
  )

;;;Wrapper function for merge_aux
(defun merge_lists(l a)
  (merge_aux l a nil)
  )


;;; Solving task (C)

;;Function which returns the last element of a list

(defun last_elem(l)
 (cond
  ((equal (cdr l) nil) (car l))
  (t (last_elem (cdr l)))
   )
  )

;;Function which change every sublist with the last element of that sublist
;;;Only 1 level

(defun change_sublist(l)
 (cond
  ((NULL l) nil)
  ((listp (car l)) (cons (last_elem (car l)) (change_sublist (cdr l))))
  (t (cons (car l) (change_sublist (cdr l))))
   )
  )

;;Function to change every sublist  at all levels
(defun change_all_sublists(l)
  (cond
   ((isLinearList l) l)
   (t (change_all_sublists (change_sublist l)))
    )
  )
