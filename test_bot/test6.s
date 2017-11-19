.name "test6"
.comment  "I'M ALIIIIVE"
l2:
        sti r1, %:live, %1
        and r1,  %12223223233333333333333333333, r1
live:
        live     %1
        zjmp %:l2
live:
        live     %1
        and r1, %723453453, r1
        zjmp %:live
