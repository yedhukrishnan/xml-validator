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

int is_alpha(char c) {
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || c == '-') {
    return 1;
  }
  return 0;
}

void show_token(struct Token *token) {
  printf("Token Type: %s\n", token->type);
  printf("Token Value: %s\n", token->value);
  printf("---\n");
}

/*
 * List of token types available in XML
 */
char *ANGLE_OPEN = "angle_open";
char *ANGLE_CLOSE = "angle_close";
char *DOUBLE_QUOTE = "double_quote";
char *LITERAL = "literal";

int main() {
  int token_count = 0, char_seen = 0, lit_counter;
  char c, literal[100];
  struct Token *token[1000]; // Token array

  /*
   * Open the sample XML file.
   * Later, change this to accept file name dynamically
   */
  FILE *xml_file = fopen("sample.xml", "r");

  lit_counter = 0;

  while((c = getc(xml_file)) != EOF) {
    /*
     * Check if we are iterating through string.
     * If yes, check if the next char is an alphabet.
     * If yes, continue updating the string, else terminate the string and
     * create a literal token.
     */
    if(char_seen == 1) {
      if(is_alpha(c) == 1) {
        literal[lit_counter++] = c;
        continue;
      } else {
        literal[lit_counter] = '\0';
        token[token_count] = malloc(sizeof(struct Token));

        token[token_count]->type = LITERAL;
        token[token_count]->value = literal;
        show_token(token[token_count]);
        char_seen = 0;
        lit_counter = 0;
        token_count++;
      }
    }

    token[token_count] = malloc(sizeof(struct Token));

    switch(c) {
      case ' ':
      case '\t':
      case '\n':
        break;
      case '<':
        token[token_count]->type = ANGLE_OPEN;
        token[token_count]->value = "<";
        show_token(token[token_count]);
        break;
      case '>':
        token[token_count]->type = ANGLE_CLOSE;
        token[token_count]->value = ">";
        show_token(token[token_count]);
        break;
      case '\"':
        token[token_count]->type = DOUBLE_QUOTE;
        token[token_count]->value = "\"";
        show_token(token[token_count]);
        break;
      default:
        if(is_alpha(c) == 1) {
          char_seen = 1;
          lit_counter = 0;
          literal[lit_counter++] = c;
          goto end_of_switch;
        }
        break;
    }

    token_count++;

    end_of_switch:

    continue;
  }

  return 0;
}
