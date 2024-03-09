preprocessor: preprocessor.o remove_comment.o replace_macro.o include_header.o
	cc preprocessor.o remove_comment.o replace_macro.o include_header.o -o preprocessor

preprocessor.o: preprocessor.c
	cc -c preprocessor.c
remove_comment.o: remove_comment.c
	cc -c remove_comment.c
replace_macro.o: replace_macro.c
	cc -c replace_macro.c
include_header.o: include_header.c
	cc -c include_header.c
