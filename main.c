/* XML Validator
 *
 * A tokenizer and parser for XML in C which checks if an XML input is valid or
 * invalid. Writing this as part of learning tokenizing and parsing process and
 * will eventually make it into a Ruby gem to be used in Ruby/Rails applications.
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Structure to store tokens
 */
struct Token {
  char *type;
  char *value;
};

void print_blank_line() {
  printf("\n");
}

/*
 * List of token types available in XML
 */
char *ANGLE_OPEN = "angle_open";
char *ANGLE_CLOSE = "angle_close";
char *DOUBLE_QUOTE_OPEN = "double_quote_open";
char *DOUBLE_QUOTE_CLOSE = "double_quote_close";
char *ATTRIBUTE_NAME = "attribute_name";
char *ATTRIBUTE_VALUE = "attribute_value";

int main() {
  int token_count = 0;
  char c;                    // A single char in the file
  struct Token *token[1000]; // Token array

  /*
   * Open the sample XML file.
   * Later, change this to accept file name dynamically
   */
  FILE *xml_file = fopen("sample.xml", "r");

  while((c = getc(xml_file)) != EOF) {
    token[token_count] = malloc(sizeof(struct Token));
    switch(c) {
      case '<':
        token[token_count]->type = ANGLE_OPEN;
        token[token_count]->value = "<";

        printf("ANGLE_OPEN");
        print_blank_line();

        break;
      case '>':
        token[token_count]->type = ANGLE_CLOSE;
        token[token_count]->value = ">";

        printf("ANGLE_CLOSE");
        print_blank_line();

        break;
      case ' ':
      case '\t':
      case '\n':
        break;
    }

    token_count++;
  }

  printf("%i", token_count);
  printf("%s", ANGLE_OPEN);

  return 0;
}
