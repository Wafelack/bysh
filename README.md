# wManager

Project manager for the C programming language

![GitHub pull requests](https://img.shields.io/github/issues-pr/Wafelack/wmanager?label=Pull%20requests) ![GitHub issues](https://img.shields.io/github/issues/Wafelack/wmanager?color=%23ff5522&label=Issues) ![GitHub top language](https://img.shields.io/github/languages/top/Wafelack/wmanager?color=%23aaaaaa&label=C) ![GitHub stars](https://img.shields.io/github/stars/Wafelack/wmanager?label=Stars&style=plastic) ![GitHub](https://img.shields.io/github/license/Wafelack/wmanager?color=%2300afff&label=License) ![Status](https://img.shields.io/badge/Status-Working_for_Windows_only-%2300ff00) ![GitHub release (latest by date)](https://img.shields.io/github/v/release/Wafelack/wmanager?label=Latest%20release)

## How to use

### Setup

First download the latest release of wmanager, put it in `C:\Program Files` and add `C:\Program Files\` to Path.

Open the command prompt and run :

### Create a new project

```
$ wmanager new <project_name>
$ cd project_name/
```

You'll find two folders, `src/` and `build/`

In `src/`, you'll find file `main.c` that contains a basic hello world program.

### Compile and Run

```
$ wmanager build

$ wmanager run
Hello World
```

### Features

#### To reinitialize a project

```
$ wmanager reinit
Really want to reinit ? Y/N : Y
Project renitialized !
```

#### To create a header file

```
$ wmanager header foo
$ cat foo.h
#ifndef _FOO_H_
#define _FOO_H_


#endif /*_FOO_H*/
```
