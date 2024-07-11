#Rotated!

O desafio informava ter rotacionado a flag em cinco posições, e depois
rotacionado novamente em mais oito posições. Assim, ele entregava o texto
"VprPGS{jnvg_bar_cyhf_1_vf_3?}" e pedia para recuperar a flag. Como a soma
dessas duas rotações é igual a famosa cifra de substituição
[ROT13](https://en.wikipedia.org/wiki/ROT13), bastava um simples script em bash
para recuperar a flag.

```
jeremias@tardis:~/Rotated!$ echo 'VprPGS{jnvg_bar_cyhf_1_vf_3?}' | tr '[A-Za-z]' '[N-ZA-Mn-za-m]'
IceCTF{wait_one_plus_1_is_3?}
```
