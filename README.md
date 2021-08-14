# 🐚 Minishell
A personal shell, made with rorozco- ✨

![minishell test](https://user-images.githubusercontent.com/74905890/129444770-69e35ff8-0c4c-4bb6-b515-3a8062d3fc61.gif)

## Features
- Parser and tokenizer mimics bash
- Builtins:
	- echo
	- cd
	- pwd
	- export
	- unset
	- env
	- exit
- Pipes, semicolon, $? and simple/double quotes work like in bash
- Redirections: > >> < <<
- Environment variables
- Signals: ctrl-C, ctrl-D and ctrl-\
- History
- Auto-complete with Tab key
- Compatible with linux and MacOS

## How to use
1. Run make in the root directory.
2. Run ./minishell

![minishell make](https://user-images.githubusercontent.com/74905890/129443775-e41d93a5-0724-4435-8289-254476cfcf7b.gif)

## Extra
This shell was made using readline and mimicking the way bash tokenize and parse the input.

