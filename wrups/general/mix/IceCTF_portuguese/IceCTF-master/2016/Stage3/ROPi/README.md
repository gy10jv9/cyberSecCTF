# ROPi

O desafio consistia em explorar um buffer overflow e **pular** entre funções para exibir corretamente, o workflow necessário para isto era, seguindo os nomes das funções:

1. ret (configurava o filedescriptor para flag.txt)
2. ori (realizada o read() no fd configurado anteriormente)
3. pro (finalmente exibia a flag)

Apesar de parecer simples, as duas primeiras funções exigiam chaves para a executar, ou seja, alguns valores predeterminados deviam estar na memoria, além disso, o espaço era diminuto então você deveria encaixar perfeitamente cada chamada para a funçao:

```
./ropi-exploit.py | nc ropi.vuln.icec.tf 6500        
Benvenuti al convegno RetOri Pro!
Vuole lasciare un messaggio?
[+] aperto
[+] leggi
[+] stampare
IceCTF{italiano_ha_portato_a_voi_da_google_tradurre}
```

Analise o código fonte do exploit para maiores explicações.
