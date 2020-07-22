# Wanager

Project manager for the C programming language

![GitHub pull requests](https://img.shields.io/github/issues-pr/Wafelack/wanager?label=Pull%20requests) ![GitHub issues](https://img.shields.io/github/issues/Wafelack/wanager?color=%23ff5522&label=Issues) ![GitHub top language](https://img.shields.io/github/languages/top/Wafelack/wanager?color=%23aaaaaa&label=C) ![GitHub stars](https://img.shields.io/github/stars/Wafelack/wanager?label=Stars) ![GitHub](https://img.shields.io/github/license/Wafelack/wanager?color=%2300afff&label=License) ![Status](https://img.shields.io/badge/Status-Working_for_Windows_only-%2300ff00) ![GitHub release (latest by date)](https://img.shields.io/github/v/release/Wafelack/wanager?label=Latest%20release)

## How to use

### Setup

First download the latest release of wanager, put it in `C:\Program Files` and add `C:\Program Files\` to Path.

### Create a new project

Open the command prompt and run :

```
$ wanager new <project_name>
$ cd project_name/
```

Two folders have been created, `src/` and `build/`

In `src/`, you'll find file `main.c` that contains a basic hello world program.

### Compile and Run

```
$ wanager build

$ wanager run
Hello World
```

### Features

#### To reinitialize a project

```
$ wanager reinit
Really want to reinit ? Y/N : Y
Project renitialized !
```

#### To create a header file

```
$ wanager header foo
$ cat foo.h
#ifndef _FOO_H_
#define _FOO_H_


#endif /*_FOO_H*/
```
