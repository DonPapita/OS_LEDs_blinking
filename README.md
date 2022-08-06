# OS LED's blinking

Este ejmplo esta basado en el  [Arm Mbed OS Official Examples](https://os.mbed.com/code/) and is the [getting started example for Mbed OS](https://os.mbed.com/docs/mbed-os/latest/quick-start/index.html). It contains an application that repeatedly blinks an LED on supported [Mbed boards](https://os.mbed.com/platforms/).

## Respuesta esperada en la tarjeta de desarollo
Los tres LEDs de la tarjeta de desarrollo, integrados en el LED RGB, parpadean con periodos definidos en las directivas de preprocesador  

Para que se pueda realizar la ejecución multihilo de este ejemplo, fue necesario asignar la alocación de memoria para cada hilo.  

## Solución de problemas
1. El uso de unidades de tiempo para las pausas en los multiples hilos del ejemplo, mediante la instrucción "ThisThread::sleep_for()", sólo son válidas a partir de la versión 6 del sistema operativo Mbed. Si desea replicar algunas de las funciones de este ejemplo, por favor verifique la versión del sistema operativo.


## Links recomendados

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html).
* [Mbed OS Configuration](https://os.mbed.com/docs/latest/reference/configuration.html).
* [Mbed OS Serial Communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html).
* [Mbed OS bare metal](https://os.mbed.com/docs/mbed-os/latest/reference/mbed-os-bare-metal.html).
* [Mbed boards](https://os.mbed.com/platforms/).

### License and contributions

The software is provided under Apache-2.0 license. Contributions to this project are accepted under the same license. Please see [CONTRIBUTING.md](./CONTRIBUTING.md) for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
