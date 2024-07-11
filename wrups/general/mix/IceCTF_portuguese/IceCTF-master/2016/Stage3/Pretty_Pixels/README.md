# Pretty Pixels

O desafio consistia em extrair um PNG de dentro de outro PNG defeituoso, utilizei a ferramenta zsteg que procura diversos tipos de esteganografia, neste caso especifico o PNG **extra** estava no LSB do canal RGB

```
greyhound//deadcow ~/fun/icectf/pretty_pixels % zsteg -a pretty_pixels.png | grep -i png
b8,rgb,lsb,xy .. file: PNG image data, 550 x 541, 8-bit/color RGBA, non-interlaced
zsteg -a pretty_pixels.png 5.13s user 0.05s system 74% cpu 6.973 total
grep --color=auto -i png 0.01s user 0.02s system 0% cpu 6.973 total
greyhound//deadcow ~/fun/icectf/pretty_pixels % zsteg -e b8,rgb,lsb,xy pretty_pixels.png > extracted.png
greyhound//deadcow ~/fun/icectf/pretty_pixels % feh extracted.png
```


