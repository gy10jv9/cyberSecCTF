#Thor
Era um hexdump de um arquivo lzip, bem simples:

Primeiro, baixar o arquivo
```
wget -qO- https://play.icec.tf/problem-static/thor_7101f3b9690d5dc6c3afefa49d82e0526b278ec1c564139369ad22c28721d4cf.txt | cut -f2-9 -d" " | tr -d ' \n' | xxd -r -p > arq
```
Depois, determinar o tipo do arquivo
```
$ file arq
arq: lzip compressed data, version: 1
```

Então, descompactar o arquivo e verificar seu tipo.
```
$ lzip -d arq
$ file arq.out
arq.out: JPEG image data, JFIF standard 1.01
```

JPG? Só abrir a imagem e copiar a flag
```
$ feh arq.out
```
IceCTF{h3XduMp1N9_l1K3_A_r341_B14Ckh47}
