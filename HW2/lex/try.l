%{
#include <stdio.h>
// record the tap in every line
int count = 0;
%}

%%
\n {  // next line
	// print next line
	printf("\n");  
}

^[[:space:]]*\{ {
	for(int i = 0; i < count; i++){
		printf("\t");   // print tab
	}
	count++;
	printf("{");
}

\{ {  // left bracket
	printf("{");
	count++;;
}

\} {  // right bracket
	count--;
	for(int i = 0; i < count;i++){
		printf("\t");  // print tab
	}
	printf("}");  // print right bracket and next line
}

[^{}\n]+ {  // match other characters except next line and brackets
	if(yytext[0] == '\t'){
		int length = strlen(yytext);
		for(int j = 0; j < length; j++){
			yytext[j] = yytext[j+1];   // move character toward in order
		}
	}
	for(int i = 0; i < count; i++){
		printf("\t");  // print tab
	}
	printf("%s", yytext);  // print content
}

\".*\"|'.*' {  // sting or characters that are enclose in double or single quotes
	for(int i = 0; i < count; i++){
		printf("\t");  // print tab
	}
	printf("%s\n", yytext);  // print content including quotes
}

%%
int yywrap(){
	return 1;
}

int main(){
	yylex();
	return 0;
}
