#Hidden in Plain Sight

Primeiro, baixamos o binário
wget -c https://play.icec.tf/problem-static/828644c3ad8ccfa14b86a69dccd36f2b-plain_sight_df5d2c1da50110458fa00d0db6586b23cd67317c7f7b95f4a092d645a4570296 -Oplain-sight

Nem me dei ao trabalho de executá-lo. Já abri direto no gdb:

```
gdb plain-sight

(gdb) disas main


   0x0804851b <+112>:	mov    $0x49,%al
   0x0804851d <+114>:	mov    $0x63,%al
   0x0804851f <+116>:	mov    $0x65,%al
   0x08048521 <+118>:	mov    $0x43,%al
   0x08048523 <+120>:	mov    $0x54,%al
   0x08048525 <+122>:	mov    $0x46,%al
   0x08048527 <+124>:	mov    $0x7b,%al
   0x08048529 <+126>:	mov    $0x6c,%al
   0x0804852b <+128>:	mov    $0x6f,%al
   0x0804852d <+130>:	mov    $0x6f,%al
   0x0804852f <+132>:	mov    $0x6b,%al
   0x08048531 <+134>:	mov    $0x5f,%al
   0x08048533 <+136>:	mov    $0x6d,%al
   0x08048535 <+138>:	mov    $0x6f,%al
   0x08048537 <+140>:	mov    $0x6d,%al
   0x08048539 <+142>:	mov    $0x5f,%al
   0x0804853b <+144>:	mov    $0x49,%al
   0x0804853d <+146>:	mov    $0x5f,%al
   0x0804853f <+148>:	mov    $0x66,%al
   0x08048541 <+150>:	mov    $0x6f,%al
   0x08048543 <+152>:	mov    $0x75,%al
   0x08048545 <+154>:	mov    $0x6e,%al
   0x08048547 <+156>:	mov    $0x64,%al
   0x08048549 <+158>:	mov    $0x5f,%al
   0x0804854b <+160>:	mov    $0x69,%al
   0x0804854d <+162>:	mov    $0x74,%al
   0x0804854f <+164>:	mov    $0x7d,%al

```

Bastava copiar esse trecho e colar num arquivo, nesse caso, chamado "file"

Então fazer essa função em bash:

```
hex2ascii(){
i=0
while (( $i < ${#1} )); do
echo -en "\x${1:$i:2}"
let i+=2;
done
echo;
}
```
e por fim:
```
for i in $(grep mov file | cut -f3 -dx | cut -f1 -d,) ; do hex2ascii $i; done | tr -d '\n'
```
IceCTF{look_mom_I_found_it}
