<h1 align="center">Wanager</h1>
<br>
<br>

<div align="center">

![GitHub pull requests](https://img.shields.io/github/issues-pr/Wafelack/wanager?label=Pull%20requests)
![GitHub issues](https://img.shields.io/github/issues/Wafelack/wanager?color=%23ff5522&label=Issues)
![GitHub stars](https://img.shields.io/github/stars/Wafelack/wanager?label=Stars)
![GitHub](https://img.shields.io/github/license/Wafelack/wanager?color=%2300afff&label=License)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/Wafelack/wanager?label=Latest%20release)
![GitHub All Releases](https://img.shields.io/github/downloads/Wafelack/wanager/total?color=%2300ff00&label=Downloads)

</div>
<br>
<br>

---

<br>
<br>

<table border="1" align="center">
    <thead>
    <tr>
    <th>
    </th>
    <th>
                <center><img alt="Linux" src="https://www.screenconnect.com/Images/LogoLinux.png" align="center" height="30" width="30" /></center>
                <center>Linux</center>
    </th>
    <th>
                <center><img alt="Windows" src="https://upload.wikimedia.org/wikipedia/commons/thumb/7/76/Windows_logo_-_2012_%28dark_blue%2C_lines_thinner%29.svg/414px-Windows_logo_-_2012_%28dark_blue%2C_lines_thinner%29.svg.png" align="center" height="30" width="30" /></center>
                <center>Windows</center>
    </th>
    <th>
                <center><img alt="MacOS" src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/fa/Apple_logo_black.svg/245px-Apple_logo_black.svg.png" align="center" height="30"width="25" /></center>
                 <center>MacOS</center>
    </th>
    </tr>
    </thead>
    <tbody>
    <tr>
    <th align="center">
    C Version
</th>
    <td align="center">
        <img src="https://img.shields.io/badge/Status-Not_Working-%23ff0000" align="center">
    </td>
    <td align="center">
        <img src="https://img.shields.io/badge/Status-Working-%2300ff00">
    </td>
    <td align="center">
        <img src="https://img.shields.io/badge/Status-Not_Tested-%23aaaa00">
    </td>
    </tr>
    <tr>
    <th align="center" width="100">
    Rust Version
    </th>
    <td align="center">
        <img src="https://img.shields.io/badge/Status-Not_Tested-%23aaaa00">
    </td>
    <td align="center">
        <img src="https://img.shields.io/badge/Status-Not_Tested-%23aaaa00">
    </td>
    <td align="center">
        <img src="https://img.shields.io/badge/Status-Not_Tested-%23aaaa00">
    </td>
    </tr>
    </tbody>

</table>
<br>
<br>
<br>

---

<br>
<br>
<br>

# How to use

## Setup

First download the latest release of wanager, put it in `C:\Program Files` and add `C:\Program Files\` to Path.

<br>

## Create a new project

Open the command prompt and run :

```
$ wanager new <project_name>
$ cd project_name/
```

Two folders have been created, `src/` and `build/`

In `src/`, you'll find file `main.c` that contains a basic hello world program.

<br>

## Compile and Run

```
$ wanager build

$ wanager run
Hello World
```

NOTE : `wanager build` will build a debug executable, with flags -W -Wall -Werror -Wextra. To disable this build in release mode with : `wanager build --release`

<br>

## Features

### To reinitialize a project

```
$ wanager reinit
Really want to reinit ? Y/N : Y
Project renitialized !
```

### To create a header file

```
$ wanager header foo
$ cat foo.h
#ifndef _FOO_H_
#define _FOO_H_


#endif /*_FOO_H*/
```
