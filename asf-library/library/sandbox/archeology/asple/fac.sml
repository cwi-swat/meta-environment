es[
lao x;
s-read;
ldci 1;
sro y;
ldci 1;
sro z;
block(ldo x;
      ldci 0;
      !=;
      fjp 1;
      block(lbl 1;
            ldo z;
            ldo x;
            !=;
            fjp 2;
            ldo z;
            ldci 1;
            +;
            sro z;
            ldo y;
            ldo z;
            *;
            sro y;
            ujp 1;
            lbl 2);
      lbl 1);
ldo y;
s-write
]
with input(3)
