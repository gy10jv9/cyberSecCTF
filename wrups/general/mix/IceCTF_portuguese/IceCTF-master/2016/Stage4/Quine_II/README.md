# Quine II

O desafio consistia em criar um [quine](https://en.wikipedia.org/wiki/Quine_(computing)) e enviar para o servidor de forma que a flag fosse exibida:

```
greyhound//deadcow ~/fun/icectf/quine2 % cat quine.c | nc quine.vuln.icec.tf 5501
Please provide source file (up to 2048 bytes), ending with a dot by itself on a line
[INFO] Sat 20 Aug 2016 13:42:09 File upload complete!
[INFO] Sat 20 Aug 2016 13:42:11 Echoing surviving source back
/* IceCTF{my_f1x3d_p0inT_br1nGs_alL_th3_n00bs_t0_th3_y4rD} */
#include<stdio.h>
char *a[] = {"\"};\n\n",
  "int main() {\n",
  "  int i=0; char *b;\n",
  "  char flag[64];\n",
  "  FILE *fp;\n",
  "  fp = fopen (\"/flag.txt\", \"r\");\n",
  "  while (fscanf(fp, \"%%s\\n\", flag)!=EOF);\n",
  "  printf(\"/* %%s */\\n\", flag);\n",
  "  printf(\"#include<stdio.h>\\nchar *a[] = {\\\"\");\n",
  "  while(*a[i]) {\n",
  "    for(b=a[i];*b;b++)\n",
  "      switch(*b) {\n",
  "         case '\\n': printf(\"\\\\n\"); break;\n",
  "         case '\\\\': case '\\\"': putchar('\\\\'); \n",
  "         default: putchar(*b);\n",
  "      } \n",
  "    printf(\"\\\",\\n\\t\\\"\"); \n",
  "    i++;\n",
  "  }\n",
  "  i=0;\n",
  "  while(*a[i]) {printf(a[i]);i++;}\n",
  "}\n",
  ""};

int main() {
  int i=0; char *b;
  char flag[64];
  FILE *fp;
  fp = fopen ("/flag.txt", "r");
  while (fscanf(fp, "%s\n", flag)!=EOF);
  printf("/* %s */\n", flag);
  printf("#include<stdio.h>\nchar *a[] = {\"");
  while(*a[i]) {
    for(b=a[i];*b;b++)
      switch(*b) {
         case '\n': printf("\\n"); break;
         case '\\': case '\"': putchar('\\');
         default: putchar(*b);
      }
    printf("\",\n\t\"");
    i++;
  }
  i=0;
  while(*a[i]) {printf(a[i]);i++;}
}
greyhound//deadcow ~/fun/icectf/quine2 %
```

Para quem não sabe, uma explicação simples do que é um quine, seria um programa que consegue se reproduzir durante sua execução, ou seja, um programa que consegue ser replicado através do seu output.

