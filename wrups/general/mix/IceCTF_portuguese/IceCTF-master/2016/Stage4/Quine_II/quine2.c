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
.
