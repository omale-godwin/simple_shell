#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>


int main(int argc, char *argv[]);
extern char **environ;
void _putttind(char *strg);
void prompttin(void);
char *read_lines(void);
int _stringlen(char *s);
char *_strcattings(char *dest, char *src);
char **_strtotokenised(char *strg);
int _executting(char **tokenised, char *args);
void _printtingenv(void);
int _puttingchar(char c);
int _stringcmp(char *str1, char *s2);
int _executeBuiltIncmd(char **tokenised);
int _isBuiltIncmd(char *str);
int c_atois(char *s);
void _killing(char *lineptr, char *tmp, char **tok);
void _exitSimpleShellcode(char **tokenised, char *line);
void controlc(int signum);
int is_delimed(char c, const char *delim);
char *_stringtok(char *src, const char *delim);
char *_stringcpy(char *destnt, char *src);
ssize_t getting_line(char **str);
int handlling_path(char **tokenised);
int if_file_in_exists(char *s);
char *builder_of_path(char **tokenised);
int second_execute(char **tokenised, char *path, char *args);
char *variable_build(char *variable_name, char *variable_value);
int _settingenv(char *variable_name, char *variable_value);
int _unsettingenv(char *variable_name);
char *_stringdup(char *str);

#endif
