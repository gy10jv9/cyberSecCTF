#Corrupt Transmission

O challenge fornecia um arquivo com headers quebrados:
```
00000000: 90 50 4e 47 0e 1a 0a 1b .PNG....
```
Como a dica óbvia já deixava claro ser um png, foi só copiar os headers de um png que tinha no meu computador e editar com xxd

```
00000000: 89 50 4e 47 0d 0a 1a 0a .PNG...
```

e a imagem abriu.
