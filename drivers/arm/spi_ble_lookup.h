#pragma once

#include "hal.h"
#include "quantum.h"

#define BLE_PORT PAL_PORT(SPI_MOSI_PIN)
#define BLE_PAD PAL_PAD(SPI_MOSI_PIN)
// #define STM32F3xx_MCUCONF

void populateSPIConfig(SPIConfig* spicfg){
  spicfg->end_cb = NULL;
  spicfg->ssport = BLE_PORT;
  spicfg->sspad = BLE_PAD;

  #ifdef STM32F103_MCUCONF
    if(BLE_PORT == GPIOB && BLE_PAD == 15U){
      spicfg->cr1 = (SPI_CR1_BR_1|SPI_CR1_BR_0);
    } else if(BLE_PORT == GPIOA && BLE_PAD == 7U) {
      spicfg->cr1 = (SPI_CR1_BR_2);
    }
  #elif defined(STM32F3xx_MCUCONF)
    if(BLE_PORT == GPIOB && BLE_PAD == 15U){
      spicfg->cr1 = (SPI_CR1_BR_1|SPI_CR1_BR_0);
    } else if(BLE_PORT == GPIOA && BLE_PAD == 7U) {
      spicfg->cr1 = (SPI_CR1_BR_2);
    }
  #elif defined(STM32F303_MCUCONF)
    if(BLE_PORT == GPIOB && BLE_PAD == 15U){
      spicfg->cr1 = (SPI_CR1_BR_1|SPI_CR1_BR_0);
    } else if(BLE_PORT == GPIOA && BLE_PAD == 7U) {
      spicfg->cr1 = (SPI_CR1_BR_2);
    }
  #else
  #endif
}
