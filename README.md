# printf

libftprintf.a is a library that contains ft_printf,
  a function that will mimic the real printf function.<br />

This work has been validated by the following tests:
* [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
* [pft](https://github.com/gavinfielder/pft)
* [printfTester](https://github.com/Tripouille/printfTester)
* [norminette v.3](https://github.com/alexandregv/norminette-action)

<p align="center">
  <img src="/screenshots/Mazoise_42TESTERS_PRINTF.png" width="50%" />
  <img src="/screenshots/gavinfielder_pft.png" width="50%" />
  <img src="/screenshots/Tripouille_printfTester.png" width="50%" />
</p>

### Install
```
git clone git@github.com:daisvke/printf_linux.git --recursive
```

### Description

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
