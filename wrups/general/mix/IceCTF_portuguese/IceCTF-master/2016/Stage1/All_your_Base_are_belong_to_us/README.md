#All your Base are belong to us

O enunciado informava já possuir a flag no arquivo
[flag.txt](https://play.icec.tf/problem-static/flag_63c24d48595eae318c9a174f37ffb0f128758e5c16fea0ffebf12b0ba5f5b26a.txt),
mas que estava uma bangunça e não era possível submeter assim. Observando o
conteúdo do arquivo, não era muito difícil perceber que se tratava de valores
binários para a codificação [ASCII](https://en.wikipedia.org/wiki/ASCII).
Assim, removemos os espaços e as quebras de linha para poder converter todo o
conteúdo em texto legível, por meio da biblioteca binascii do python. 

```
import binascii

text=int('0b01001001011000110110010101000011010101000100011001111011011000010110110000110001010111110110110101111001010111110110001001100001011100110110010101110011010111110110000101110010011001010101111101111001011011110111010101110010011100110101111101100001011011100110010001011111011000010110110001101100010111110111100100110000011101010111001001011111011000100110000101110011011001010111001101011111011000010111001001100101010111110110110101101001011011100110010101111101',
        2)

print binascii.unhexlify('%x' % text)
```

A conversão retornava diretamente a flag a ser submetida.

IceCTF{al1_my_bases_are_yours_and_all_y0ur_bases_are_mine}
