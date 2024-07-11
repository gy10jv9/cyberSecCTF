# Complacent

O desafio era bem simples, a flag estava no certificado SSL do endereço https://complacent.vuln.icec.tf

```
greyhound//deadcow ~/fun/icectf/Complacent % openssl s_client -connect complacent.vuln.icec.tf:443 | grep -oE 'IceCTF{.*}'
depth=0 C = IS, ST = Kingdom of IceCTF, L = IceCTF city, O = Secret IceCTF Buisness Corp, OU = Flag: IceCTF{this_1nformation_wasnt_h1dd3n_at_a11}, CN = complacent.icec.tf
verify error:num=18:self signed certificate
verify return:1
depth=0 C = IS, ST = Kingdom of IceCTF, L = IceCTF city, O = Secret IceCTF Buisness Corp, OU = Flag: IceCTF{this_1nformation_wasnt_h1dd3n_at_a11}, CN = complacent.icec.tf
verify return:1
IceCTF{this_1nformation_wasnt_h1dd3n_at_a11}
IceCTF{this_1nformation_wasnt_h1dd3n_at_a11}
IceCTF{this_1nformation_wasnt_h1dd3n_at_a11}
IceCTF{this_1nformation_wasnt_h1dd3n_at_a11}
^C
greyhound//deadcow ~/fun/icectf/Complacent %
```
