# Quine

The hard way, a principio eu não sabia do que se tratava um quine, então por ser um challenge pwn, imaginei que deveria entrar no servidor, criei um socket em C que executado conectava remotamente em um IP em um servidor, desta forma eu tinha acesso ao shell, porém na primeira tentativa usando apenas builtins shell nao conseguia ler a flag, na segunda tentativa fiz um fopen e enviava o conteudo para meu socket.

```
greyhound//deadcow ~/fun/icectf/quine % cat quine.c|nc quine.vuln.icec.tf 5500
Please provide source file (up to 2048 bytes), ending with a dot by itself on a line
[INFO]  server.c:161  (4466) Sun 28 Aug 2016 07:37:27 File upload complete!
[INFO]  server.c:436  (4466) Sun 28 Aug 2016 07:37:27 Survived iteration #1!
...
nc -vlp 22044
IceCTF{the_flags_of_our_quines}
...
greyhound//deadcow ~/fun/icectf/quine %
```

Validando depois o desafio, o código do Quine II também funcionaria neste.


