/* XML Validator
 *
 * A tokenizer and parser for XML in C which checks if an XML input is valid or
 * invalid. Writing this as part of learning tokenizing and parsing process and
 * will eventually make it into a Ruby gem to be used in Ruby/Rails applications.
 *
 * */

#include <stdio.h>

void print_blank_line() {
  printf("\n");
}

int main() {
  char c;
  FILE *xml_file = fopen("sample.xml", "r");

  while((c = getc(xml_file)) != EOF) {
    switch(c) {
      case '<':
        printf("ANGLE_OPEN");
        print_blank_line();
        break;
      case '>':
        printf("ANGLE_CLOSE");
        print_blank_line();
        break;
      case ' ':
      case '\t':
      case '\n':
        break;
    }
  }

  return 0;
}
