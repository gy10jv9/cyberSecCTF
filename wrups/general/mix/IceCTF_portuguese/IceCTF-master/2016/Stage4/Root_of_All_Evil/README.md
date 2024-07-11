#Root of All Evil

Depois de descompactar o zip fornecido pelo challenge e analisar a estrutura de diretorios, encontramos na pasta root/bin um binário com o nome ```evilcat```
O comando strings revela um base64, que após análise se mostrou um .wav

o áudio contém sinais DTMF (https://en.wikipedia.org/wiki/Dual-tone_multi-frequency_signaling).
então, vamos detonar:
```
strings -100 root/bin/evilcat | base64 -d > dtmf.wav
```
Para decodificar o DTMF, usamos multimon:

```
multimon -t wav -a DTMF dtmf.wav
```


o output nos retorna o seguinte: 
```
6412673822*2192146998
```

Após algumas horas de palpites, chegamos a conclusão de que se tratavam de coordenadas para a universidade de Reykjavik, na Islândia, no formato lat*-long

lat 64.12673822 e long -21.92146998

Depois disso foi só abrir um ticket para a organização para comprovar que estamos fora do país e receber a flag.
Os residentes no país deveriam se locomover até a universidade :(
IceCTF{what_am_i_doing_1n_the_w00ds_s3nd_h4lp}
