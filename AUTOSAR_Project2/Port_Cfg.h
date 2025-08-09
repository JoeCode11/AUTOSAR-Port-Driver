/*
 * Port_Cfg.h
 *
 *  Created on: 29 Apr 2025
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Youssef Tamer
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif


/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Pre-compile option for presence of PORT_SET_PIN_DIRECTION API */
#define PORT_SET_PIN_DIRECTION_API                (STD_ON)

/* Pre-compile option for presence of PORT_SET_PIN_MODE API */
#define PORT_SET_PIN_MODE_API                (STD_ON)


/* Precompile and Post Build option for setting the Pin direction,
   according to its mode E.g. a pin used for an ADC must be configured
   to be an in port. */
#define PORT_PIN_DIRECTION                    (STD_ON)

/* Precompile and Post Build option for changing a Pin
   direction during runtime */
#define PORT_PIN_DIRECTION_CHANGEABLE         (STD_ON)

/* Precompile and Post Build option for setting initial Pin mode
   to be ADC, DIO, LIN, .. */
#define PORT_PIN_INITIAL_MODE                 (STD_ON)

/* Precompile and Post Build option for setting
   Port Pin Level value from Port pin list. */
#define PORT_PIN_LEVEL_VALUE                  (STD_ON)

/* Precompile and Post Build option for setting Pin mode
to be ADC, DIO, LIN, .. */
#define PORT_PIN_MODE                         (STD_ON)

/* Precompile and Post Build option for Port pin mode changeability */
#define PORT_PIN_MODE_CHANGEABLE              (STD_ON)

/* Number of the configured Port Pins */
#define PORT_CONFIGURED_PINS (43U)

/*Define Ports*/
#define PORTA_ID    (0U)
#define PORTB_ID    (1U)
#define PORTC_ID    (2U)
#define PORTD_ID    (3U)
#define PORTE_ID    (4U)
#define PORTF_ID    (5U)

/*Define Pins*/
#define PIN0_ID    (0U)
#define PIN1_ID    (1U)
#define PIN2_ID    (2U)
#define PIN3_ID    (3U)
#define PIN4_ID    (4U)
#define PIN5_ID    (5U)
#define PIN6_ID    (6U)
#define PIN7_ID    (7U)

#define PORTA_PIN0_DIR INPUT
#define PORTA_PIN1_DIR INPUT
#define PORTA_PIN2_DIR INPUT
#define PORTA_PIN3_DIR INPUT
#define PORTA_PIN4_DIR INPUT
#define PORTA_PIN5_DIR INPUT
#define PORTA_PIN6_DIR INPUT
#define PORTA_PIN7_DIR INPUT

#define PORTB_PIN0_DIR INPUT
#define PORTB_PIN1_DIR INPUT
#define PORTB_PIN2_DIR INPUT
#define PORTB_PIN3_DIR INPUT
#define PORTB_PIN4_DIR INPUT
#define PORTB_PIN5_DIR INPUT
#define PORTB_PIN6_DIR INPUT
#define PORTB_PIN7_DIR INPUT

#define PORTC_PIN0_DIR INPUT
#define PORTC_PIN1_DIR INPUT
#define PORTC_PIN2_DIR INPUT
#define PORTC_PIN3_DIR INPUT
#define PORTC_PIN4_DIR INPUT
#define PORTC_PIN5_DIR INPUT
#define PORTC_PIN6_DIR INPUT
#define PORTC_PIN7_DIR INPUT

#define PORTD_PIN0_DIR INPUT
#define PORTD_PIN1_DIR INPUT
#define PORTD_PIN2_DIR INPUT
#define PORTD_PIN3_DIR INPUT
#define PORTD_PIN4_DIR INPUT
#define PORTD_PIN5_DIR INPUT
#define PORTD_PIN6_DIR INPUT
#define PORTD_PIN7_DIR INPUT

#define PORTE_PIN0_DIR INPUT
#define PORTE_PIN1_DIR INPUT
#define PORTE_PIN2_DIR INPUT
#define PORTE_PIN3_DIR INPUT
#define PORTE_PIN4_DIR INPUT
#define PORTE_PIN5_DIR INPUT

#define PORTF_PIN0_DIR INPUT
#define PORTF_PIN1_DIR OUTPUT  //LED
#define PORTF_PIN2_DIR INPUT
#define PORTF_PIN3_DIR INPUT
#define PORTF_PIN4_DIR INPUT  //Switch 1


#define PORTA_PIN0_InternalResistor OFF
#define PORTA_PIN1_InternalResistor OFF
#define PORTA_PIN2_InternalResistor OFF
#define PORTA_PIN3_InternalResistor OFF
#define PORTA_PIN4_InternalResistor OFF
#define PORTA_PIN5_InternalResistor OFF
#define PORTA_PIN6_InternalResistor OFF
#define PORTA_PIN7_InternalResistor OFF

#define PORTB_PIN0_InternalResistor OFF
#define PORTB_PIN1_InternalResistor OFF
#define PORTB_PIN2_InternalResistor OFF
#define PORTB_PIN3_InternalResistor OFF
#define PORTB_PIN4_InternalResistor OFF
#define PORTB_PIN5_InternalResistor OFF
#define PORTB_PIN6_InternalResistor OFF
#define PORTB_PIN7_InternalResistor OFF

#define PORTC_PIN0_InternalResistor OFF
#define PORTC_PIN1_InternalResistor OFF
#define PORTC_PIN2_InternalResistor OFF
#define PORTC_PIN3_InternalResistor OFF
#define PORTC_PIN4_InternalResistor OFF
#define PORTC_PIN5_InternalResistor OFF
#define PORTC_PIN6_InternalResistor OFF
#define PORTC_PIN7_InternalResistor OFF

#define PORTD_PIN0_InternalResistor OFF
#define PORTD_PIN1_InternalResistor OFF
#define PORTD_PIN2_InternalResistor OFF
#define PORTD_PIN3_InternalResistor OFF
#define PORTD_PIN4_InternalResistor OFF
#define PORTD_PIN5_InternalResistor OFF
#define PORTD_PIN6_InternalResistor OFF
#define PORTD_PIN7_InternalResistor OFF

#define PORTE_PIN0_InternalResistor OFF
#define PORTE_PIN1_InternalResistor OFF
#define PORTE_PIN2_InternalResistor OFF
#define PORTE_PIN3_InternalResistor OFF
#define PORTE_PIN4_InternalResistor OFF
#define PORTE_PIN5_InternalResistor OFF

#define PORTF_PIN0_InternalResistor OFF
#define PORTF_PIN1_InternalResistor OFF  //LED
#define PORTF_PIN2_InternalResistor OFF
#define PORTF_PIN3_InternalResistor OFF
#define PORTF_PIN4_InternalResistor PULL_UP  //Switch 1, why PULL_UP? Implementation checks if readChannel returns std_low, then press count increments


#define PORTA_PIN0_DigitalEnable STD_ON
#define PORTA_PIN1_DigitalEnable STD_ON
#define PORTA_PIN2_DigitalEnable STD_ON
#define PORTA_PIN3_DigitalEnable STD_ON
#define PORTA_PIN4_DigitalEnable STD_ON
#define PORTA_PIN5_DigitalEnable STD_ON
#define PORTA_PIN6_DigitalEnable STD_ON
#define PORTA_PIN7_DigitalEnable STD_ON

#define PORTB_PIN0_DigitalEnable STD_ON
#define PORTB_PIN1_DigitalEnable STD_ON
#define PORTB_PIN2_DigitalEnable STD_ON
#define PORTB_PIN3_DigitalEnable STD_ON
#define PORTB_PIN4_DigitalEnable STD_ON
#define PORTB_PIN5_DigitalEnable STD_ON
#define PORTB_PIN6_DigitalEnable STD_ON
#define PORTB_PIN7_DigitalEnable STD_ON

#define PORTC_PIN0_DigitalEnable STD_ON
#define PORTC_PIN1_DigitalEnable STD_ON
#define PORTC_PIN2_DigitalEnable STD_ON
#define PORTC_PIN3_DigitalEnable STD_ON
#define PORTC_PIN4_DigitalEnable STD_ON
#define PORTC_PIN5_DigitalEnable STD_ON
#define PORTC_PIN6_DigitalEnable STD_ON
#define PORTC_PIN7_DigitalEnable STD_ON

#define PORTD_PIN0_DigitalEnable STD_ON
#define PORTD_PIN1_DigitalEnable STD_ON
#define PORTD_PIN2_DigitalEnable STD_ON
#define PORTD_PIN3_DigitalEnable STD_ON
#define PORTD_PIN4_DigitalEnable STD_ON
#define PORTD_PIN5_DigitalEnable STD_ON
#define PORTD_PIN6_DigitalEnable STD_ON
#define PORTD_PIN7_DigitalEnable STD_ON

#define PORTE_PIN0_DigitalEnable STD_ON
#define PORTE_PIN1_DigitalEnable STD_ON
#define PORTE_PIN2_DigitalEnable STD_ON
#define PORTE_PIN3_DigitalEnable STD_ON
#define PORTE_PIN4_DigitalEnable STD_ON
#define PORTE_PIN5_DigitalEnable STD_ON

#define PORTF_PIN0_DigitalEnable STD_ON
#define PORTF_PIN1_DigitalEnable STD_ON  //LED
#define PORTF_PIN2_DigitalEnable STD_ON
#define PORTF_PIN3_DigitalEnable STD_ON
#define PORTF_PIN4_DigitalEnable STD_ON  //Switch 1


#define PORTA_PIN0_initial_value LOW
#define PORTA_PIN1_initial_value LOW
#define PORTA_PIN2_initial_value LOW
#define PORTA_PIN3_initial_value LOW
#define PORTA_PIN4_initial_value LOW
#define PORTA_PIN5_initial_value LOW
#define PORTA_PIN6_initial_value LOW
#define PORTA_PIN7_initial_value LOW

#define PORTB_PIN0_initial_value LOW
#define PORTB_PIN1_initial_value LOW
#define PORTB_PIN2_initial_value LOW
#define PORTB_PIN3_initial_value LOW
#define PORTB_PIN4_initial_value LOW
#define PORTB_PIN5_initial_value LOW
#define PORTB_PIN6_initial_value LOW
#define PORTB_PIN7_initial_value LOW

#define PORTC_PIN0_initial_value LOW
#define PORTC_PIN1_initial_value LOW
#define PORTC_PIN2_initial_value LOW
#define PORTC_PIN3_initial_value LOW
#define PORTC_PIN4_initial_value LOW
#define PORTC_PIN5_initial_value LOW
#define PORTC_PIN6_initial_value LOW
#define PORTC_PIN7_initial_value LOW

#define PORTD_PIN0_initial_value LOW
#define PORTD_PIN1_initial_value LOW
#define PORTD_PIN2_initial_value LOW
#define PORTD_PIN3_initial_value LOW
#define PORTD_PIN4_initial_value LOW
#define PORTD_PIN5_initial_value LOW
#define PORTD_PIN6_initial_value LOW
#define PORTD_PIN7_initial_value LOW

#define PORTE_PIN0_initial_value LOW
#define PORTE_PIN1_initial_value LOW
#define PORTE_PIN2_initial_value LOW
#define PORTE_PIN3_initial_value LOW
#define PORTE_PIN4_initial_value LOW
#define PORTE_PIN5_initial_value LOW

#define PORTF_PIN0_initial_value LOW
#define PORTF_PIN1_initial_value LOW  //LED
#define PORTF_PIN2_initial_value LOW
#define PORTF_PIN3_initial_value LOW
#define PORTF_PIN4_initial_value LOW  //Switch 1


#define PORTA_PIN0_PinMode PORT_PIN_MODE_DIO
#define PORTA_PIN1_PinMode PORT_PIN_MODE_DIO
#define PORTA_PIN2_PinMode PORT_PIN_MODE_DIO
#define PORTA_PIN3_PinMode PORT_PIN_MODE_DIO
#define PORTA_PIN4_PinMode PORT_PIN_MODE_DIO
#define PORTA_PIN5_PinMode PORT_PIN_MODE_DIO
#define PORTA_PIN6_PinMode PORT_PIN_MODE_DIO
#define PORTA_PIN7_PinMode PORT_PIN_MODE_DIO

#define PORTB_PIN0_PinMode PORT_PIN_MODE_DIO
#define PORTB_PIN1_PinMode PORT_PIN_MODE_DIO
#define PORTB_PIN2_PinMode PORT_PIN_MODE_DIO
#define PORTB_PIN3_PinMode PORT_PIN_MODE_DIO
#define PORTB_PIN4_PinMode PORT_PIN_MODE_DIO
#define PORTB_PIN5_PinMode PORT_PIN_MODE_DIO
#define PORTB_PIN6_PinMode PORT_PIN_MODE_DIO
#define PORTB_PIN7_PinMode PORT_PIN_MODE_DIO

#define PORTC_PIN0_PinMode PORT_PIN_MODE_DIO
#define PORTC_PIN1_PinMode PORT_PIN_MODE_DIO
#define PORTC_PIN2_PinMode PORT_PIN_MODE_DIO
#define PORTC_PIN3_PinMode PORT_PIN_MODE_DIO
#define PORTC_PIN4_PinMode PORT_PIN_MODE_DIO
#define PORTC_PIN5_PinMode PORT_PIN_MODE_DIO
#define PORTC_PIN6_PinMode PORT_PIN_MODE_DIO
#define PORTC_PIN7_PinMode PORT_PIN_MODE_DIO

#define PORTD_PIN0_PinMode PORT_PIN_MODE_DIO
#define PORTD_PIN1_PinMode PORT_PIN_MODE_DIO
#define PORTD_PIN2_PinMode PORT_PIN_MODE_DIO
#define PORTD_PIN3_PinMode PORT_PIN_MODE_DIO
#define PORTD_PIN4_PinMode PORT_PIN_MODE_DIO
#define PORTD_PIN5_PinMode PORT_PIN_MODE_DIO
#define PORTD_PIN6_PinMode PORT_PIN_MODE_DIO
#define PORTD_PIN7_PinMode PORT_PIN_MODE_DIO

#define PORTE_PIN0_PinMode PORT_PIN_MODE_DIO
#define PORTE_PIN1_PinMode PORT_PIN_MODE_DIO
#define PORTE_PIN2_PinMode PORT_PIN_MODE_DIO
#define PORTE_PIN3_PinMode PORT_PIN_MODE_DIO
#define PORTE_PIN4_PinMode PORT_PIN_MODE_DIO
#define PORTE_PIN5_PinMode PORT_PIN_MODE_DIO

#define PORTF_PIN0_PinMode PORT_PIN_MODE_DIO
#define PORTF_PIN1_PinMode PORT_PIN_MODE_DIO  //LED
#define PORTF_PIN2_PinMode PORT_PIN_MODE_DIO
#define PORTF_PIN3_PinMode PORT_PIN_MODE_DIO
#define PORTF_PIN4_PinMode PORT_PIN_MODE_DIO  //Switch 1


#define PORTA_PIN0_DirectionChangeable PORT_DIR_Changeable
#define PORTA_PIN1_DirectionChangeable PORT_DIR_Changeable
#define PORTA_PIN2_DirectionChangeable PORT_DIR_Changeable
#define PORTA_PIN3_DirectionChangeable PORT_DIR_Changeable
#define PORTA_PIN4_DirectionChangeable PORT_DIR_Changeable
#define PORTA_PIN5_DirectionChangeable PORT_DIR_Changeable
#define PORTA_PIN6_DirectionChangeable PORT_DIR_Changeable
#define PORTA_PIN7_DirectionChangeable PORT_DIR_Changeable

#define PORTB_PIN0_DirectionChangeable PORT_DIR_Changeable
#define PORTB_PIN1_DirectionChangeable PORT_DIR_Changeable
#define PORTB_PIN2_DirectionChangeable PORT_DIR_Changeable
#define PORTB_PIN3_DirectionChangeable PORT_DIR_Changeable
#define PORTB_PIN4_DirectionChangeable PORT_DIR_Changeable
#define PORTB_PIN5_DirectionChangeable PORT_DIR_Changeable
#define PORTB_PIN6_DirectionChangeable PORT_DIR_Changeable
#define PORTB_PIN7_DirectionChangeable PORT_DIR_Changeable

#define PORTC_PIN0_DirectionChangeable PORT_DIR_Changeable
#define PORTC_PIN1_DirectionChangeable PORT_DIR_Changeable
#define PORTC_PIN2_DirectionChangeable PORT_DIR_Changeable
#define PORTC_PIN3_DirectionChangeable PORT_DIR_Changeable
#define PORTC_PIN4_DirectionChangeable PORT_DIR_Changeable
#define PORTC_PIN5_DirectionChangeable PORT_DIR_Changeable
#define PORTC_PIN6_DirectionChangeable PORT_DIR_Changeable
#define PORTC_PIN7_DirectionChangeable PORT_DIR_Changeable

#define PORTD_PIN0_DirectionChangeable PORT_DIR_Changeable
#define PORTD_PIN1_DirectionChangeable PORT_DIR_Changeable
#define PORTD_PIN2_DirectionChangeable PORT_DIR_Changeable
#define PORTD_PIN3_DirectionChangeable PORT_DIR_Changeable
#define PORTD_PIN4_DirectionChangeable PORT_DIR_Changeable
#define PORTD_PIN5_DirectionChangeable PORT_DIR_Changeable
#define PORTD_PIN6_DirectionChangeable PORT_DIR_Changeable
#define PORTD_PIN7_DirectionChangeable PORT_DIR_Changeable

#define PORTE_PIN0_DirectionChangeable PORT_DIR_Changeable
#define PORTE_PIN1_DirectionChangeable PORT_DIR_Changeable
#define PORTE_PIN2_DirectionChangeable PORT_DIR_Changeable
#define PORTE_PIN3_DirectionChangeable PORT_DIR_Changeable
#define PORTE_PIN4_DirectionChangeable PORT_DIR_Changeable
#define PORTE_PIN5_DirectionChangeable PORT_DIR_Changeable

#define PORTF_PIN0_DirectionChangeable PORT_DIR_Changeable
#define PORTF_PIN1_DirectionChangeable PORT_DIR_Changeable  //LED
#define PORTF_PIN2_DirectionChangeable PORT_DIR_Changeable
#define PORTF_PIN3_DirectionChangeable PORT_DIR_Changeable
#define PORTF_PIN4_DirectionChangeable PORT_DIR_Changeable  //Switch 1


#define PORTA_PIN0_ModeChangeable PORT_Mode_Changeable
#define PORTA_PIN1_ModeChangeable PORT_Mode_Changeable
#define PORTA_PIN2_ModeChangeable PORT_Mode_Changeable
#define PORTA_PIN3_ModeChangeable PORT_Mode_Changeable
#define PORTA_PIN4_ModeChangeable PORT_Mode_Changeable
#define PORTA_PIN5_ModeChangeable PORT_Mode_Changeable
#define PORTA_PIN6_ModeChangeable PORT_Mode_Changeable
#define PORTA_PIN7_ModeChangeable PORT_Mode_Changeable

#define PORTB_PIN0_ModeChangeable PORT_Mode_Changeable
#define PORTB_PIN1_ModeChangeable PORT_Mode_Changeable
#define PORTB_PIN2_ModeChangeable PORT_Mode_Changeable
#define PORTB_PIN3_ModeChangeable PORT_Mode_Changeable
#define PORTB_PIN4_ModeChangeable PORT_Mode_Changeable
#define PORTB_PIN5_ModeChangeable PORT_Mode_Changeable
#define PORTB_PIN6_ModeChangeable PORT_Mode_Changeable
#define PORTB_PIN7_ModeChangeable PORT_Mode_Changeable

#define PORTC_PIN0_ModeChangeable PORT_Mode_Changeable
#define PORTC_PIN1_ModeChangeable PORT_Mode_Changeable
#define PORTC_PIN2_ModeChangeable PORT_Mode_Changeable
#define PORTC_PIN3_ModeChangeable PORT_Mode_Changeable
#define PORTC_PIN4_ModeChangeable PORT_Mode_Changeable
#define PORTC_PIN5_ModeChangeable PORT_Mode_Changeable
#define PORTC_PIN6_ModeChangeable PORT_Mode_Changeable
#define PORTC_PIN7_ModeChangeable PORT_Mode_Changeable

#define PORTD_PIN0_ModeChangeable PORT_Mode_Changeable
#define PORTD_PIN1_ModeChangeable PORT_Mode_Changeable
#define PORTD_PIN2_ModeChangeable PORT_Mode_Changeable
#define PORTD_PIN3_ModeChangeable PORT_Mode_Changeable
#define PORTD_PIN4_ModeChangeable PORT_Mode_Changeable
#define PORTD_PIN5_ModeChangeable PORT_Mode_Changeable
#define PORTD_PIN6_ModeChangeable PORT_Mode_Changeable
#define PORTD_PIN7_ModeChangeable PORT_Mode_Changeable

#define PORTE_PIN0_ModeChangeable PORT_Mode_Changeable
#define PORTE_PIN1_ModeChangeable PORT_Mode_Changeable
#define PORTE_PIN2_ModeChangeable PORT_Mode_Changeable
#define PORTE_PIN3_ModeChangeable PORT_Mode_Changeable
#define PORTE_PIN4_ModeChangeable PORT_Mode_Changeable
#define PORTE_PIN5_ModeChangeable PORT_Mode_Changeable

#define PORTF_PIN0_ModeChangeable PORT_Mode_Changeable
#define PORTF_PIN1_ModeChangeable PORT_Mode_Changeable  //LED
#define PORTF_PIN2_ModeChangeable PORT_Mode_Changeable
#define PORTF_PIN3_ModeChangeable PORT_Mode_Changeable
#define PORTF_PIN4_ModeChangeable PORT_Mode_Changeable  //Switch 1



#define PORT_CONFIG_VARIANT (PORT_VARIANT_POST_BUILD)

#endif /* PORT_CFG_H_ */
