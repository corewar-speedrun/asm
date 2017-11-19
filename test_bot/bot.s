.name "fafa1"
.comment  "I'M ALIIIIVE"
l2:
        sti r1, %:live, %1
        and r1,  %0, r1
live:
        live     %1
        zjmp %:l2
live:
        live     %1
        and r1, %723453453, r1
        zjmp %:live
