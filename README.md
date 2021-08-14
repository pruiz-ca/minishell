# 🐚 Minishell
A personal shell, made with rorozco- ✨

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
- Pipes, ";", $? and simple/double quotes work like in bash
- Redirections: > >> < <<
- Environment variables
- Signals: ctrl-C, ctrl-D and ctrl-\
- History
- Compatible with linux and MacOS

## How to use
1. Run make in the root directory.
2. Run ./minishell

## Extra
This shell was made using readline and mimicking the way bash tokenize and parse the input.

