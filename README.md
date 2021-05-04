# printf

libftprintf.a is a library that contains ft_printf, a function that will mimic the real printf function.<br />
This was originally a 42 school project.<br />

This work has been validated by the following tests:
* [42TESTERS-PRINTF&](https://github.com/Mazoise/42TESTERS-PRINTF)
* [pft](https://github.com/gavinfielder/pft)
* [printfTester](https://github.com/Tripouille/printfTester)
* [norminette v.3](https://github.com/alexandregv/norminette-action)

<p align="center">
  <img src="/screenshots/Mazoise_42TESTERS_PRINTF.png" width="70%" />
  <img src="/screenshots/gavinfielder_pft.png" width="70%" />
  <img src="/screenshots/Tripouille_printfTester.png" width="70%" />
</p>

### Description

* The function is declared as follows : 
  ```
  int ft_printf(const char *, ...);
  ```
* It does not do the buffer management like the real printf.
* Tt will manage the following conversions: cspdiouxX%.
* It will manage any combination of the following flags: '-0.*' and minimum fieldwidth with all conversions.
