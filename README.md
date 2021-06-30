# printf_linux

libftprintf.a is a library that contains ft_printf,
  a function that will mimic the real printf function.<br />

## Install
```
git clone --recursive git@github.com:daisvke/printf_linux.git
make
```

## Description

* The difference with the mac version of printf is how 'null' values are printed
* The function is declared as follows : 
  ```
  int ft_printf(const char *, ...);
  ```
* the __attribute__ mechanism in the header allows us to attach
  characteristics to function declarations to allow the compiler to perform
  more error checking:
  ```
  __attribute__((format (printf, 1, 2)));
  ```
  <p align="center">
  <img src="/screenshots/attribute.png" width="70%" />
  </p>
* It does not take care of the buffer management like the real printf.<br />
* It will manage the following conversions: cspdiouxX%n.<br />
* It will manage any combination of the following flags: '-0.*#' and 
  minimum fieldwidth with all conversions.
