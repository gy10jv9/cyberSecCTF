# RIP Transmissions

O desafio apresentava um binário ELF 64 bits com um arquivo zip dentro dele, extraindo esse zip era ainda necessário descobrir a senha do mesmo, na primeira tentativa utilizando o john-the-ripper conseguimos extrair a flag

```
greyhound//deadcow ~/fun/icectf/rip % file rip
rip: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=d25812cd846673ab364694e08d9adb83f38bb96f, stripped
greyhound//deadcow ~/fun/icectf/rip % foremost rip
Processing: rip
|foundat=rip.jpgUT
*|
greyhound//deadcow ~/fun/icectf/rip % cd output/zip
greyhound//deadcow ~/fun/icectf/rip/output/zip % zip2john 00000026.zip > pass
ver 14 efh 5455 efh 7875 00000026.zip->rip.jpg PKZIP Encr: 2b chk, TS_chk, cmplen=112199, decmplen=112190, crc=FB1DC293
greyhound//deadcow ~/fun/icectf/rip/output/zip % john --wordlist=~/rockyou.txt pass
Created directory: /home/deadcow/.john
Loaded 1 password hash (PKZIP [32/64])
Will run 4 OpenMP threads
Press 'q' or Ctrl-C to abort, almost any other key for status
bunny (00000026.zip)
1g 0:00:00:00 DONE (2016-08-16 21:58) 3.571g/s 58514p/s 58514c/s 58514C/s 123456..christal
Use the "--show" option to display all of the cracked passwords reliably
Session completed
greyhound//deadcow ~/fun/icectf/rip/output/zip % unzip 00000026.zip
Archive: 00000026.zip
[00000026.zip] rip.jpg password:
inflating: rip.jpg
greyhound//deadcow ~/fun/icectf/rip/output/zip % feh rip.jpg
```

