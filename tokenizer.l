digit     [0-9]
letter    [A-Za-z]

%{
  #include <stdio.h>
%}

%%
{letter}+ printf("Letter group\n");
{digit}+ printf("Digit group\n");
%%
