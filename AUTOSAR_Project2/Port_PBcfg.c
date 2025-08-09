/*
 * Port_PBcfg.c
 *
 *  Created on: 29 Apr 2025
 *  Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 *  Author: Youssef Tamer
 */


#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with PORT_Init API */
const Port_ConfigType Port_Configuration = {
    .Pin = {
        /* PORTA */
        {PORTA_ID, PIN0_ID, PORTA_PIN1_DIR,   PORTA_PIN0_InternalResistor, PORTA_PIN0_DigitalEnable, PORTA_PIN0_initial_value,
         PORTA_PIN0_PinMode, PORTA_PIN0_DirectionChangeable, PORTA_PIN0_ModeChangeable},
         {PORTA_ID, PIN1_ID, PORTA_PIN1_DIR,   PORTA_PIN1_InternalResistor, PORTA_PIN1_DigitalEnable, PORTA_PIN1_initial_value,
                  PORTA_PIN1_PinMode, PORTA_PIN1_DirectionChangeable, PORTA_PIN1_ModeChangeable},
                 {PORTA_ID, PIN2_ID, PORTA_PIN2_DIR,   PORTA_PIN2_InternalResistor, PORTA_PIN2_DigitalEnable, PORTA_PIN2_initial_value,
                  PORTA_PIN2_PinMode, PORTA_PIN2_DirectionChangeable, PORTA_PIN2_ModeChangeable},
                 {PORTA_ID, PIN3_ID, PORTA_PIN3_DIR,   PORTA_PIN3_InternalResistor, PORTA_PIN3_DigitalEnable, PORTA_PIN3_initial_value,
                  PORTA_PIN3_PinMode, PORTA_PIN3_DirectionChangeable, PORTA_PIN3_ModeChangeable},
                 {PORTA_ID, PIN4_ID, PORTA_PIN4_DIR,   PORTA_PIN4_InternalResistor, PORTA_PIN4_DigitalEnable, PORTA_PIN4_initial_value,
                  PORTA_PIN4_PinMode, PORTA_PIN4_DirectionChangeable, PORTA_PIN4_ModeChangeable},
                 {PORTA_ID, PIN5_ID, PORTA_PIN5_DIR,   PORTA_PIN5_InternalResistor, PORTA_PIN5_DigitalEnable, PORTA_PIN5_initial_value,
                  PORTA_PIN5_PinMode, PORTA_PIN5_DirectionChangeable, PORTA_PIN5_ModeChangeable},
                 {PORTA_ID, PIN6_ID, PORTA_PIN6_DIR,   PORTA_PIN6_InternalResistor, PORTA_PIN6_DigitalEnable, PORTA_PIN6_initial_value,
                  PORTA_PIN6_PinMode, PORTA_PIN6_DirectionChangeable, PORTA_PIN6_ModeChangeable},
                 {PORTA_ID, PIN7_ID, PORTA_PIN7_DIR,   PORTA_PIN7_InternalResistor, PORTA_PIN7_DigitalEnable, PORTA_PIN7_initial_value,
                  PORTA_PIN7_PinMode, PORTA_PIN7_DirectionChangeable, PORTA_PIN7_ModeChangeable},

                 /* PORTB */
                 {PORTB_ID, PIN0_ID, PORTB_PIN0_DIR,   PORTB_PIN0_InternalResistor, PORTB_PIN0_DigitalEnable, PORTB_PIN0_initial_value,
                  PORTB_PIN0_PinMode, PORTB_PIN0_DirectionChangeable, PORTB_PIN0_ModeChangeable},
                 {PORTB_ID, PIN1_ID, PORTB_PIN1_DIR,   PORTB_PIN1_InternalResistor, PORTB_PIN1_DigitalEnable, PORTB_PIN1_initial_value,
                  PORTB_PIN1_PinMode, PORTB_PIN1_DirectionChangeable, PORTB_PIN1_ModeChangeable},
                 {PORTB_ID, PIN2_ID, PORTB_PIN2_DIR,   PORTB_PIN2_InternalResistor, PORTB_PIN2_DigitalEnable, PORTB_PIN2_initial_value,
                  PORTB_PIN2_PinMode, PORTB_PIN2_DirectionChangeable, PORTB_PIN2_ModeChangeable},
                 {PORTB_ID, PIN3_ID, PORTB_PIN3_DIR,   PORTB_PIN3_InternalResistor, PORTB_PIN3_DigitalEnable, PORTB_PIN3_initial_value,
                  PORTB_PIN3_PinMode, PORTB_PIN3_DirectionChangeable, PORTB_PIN3_ModeChangeable},
                 {PORTB_ID, PIN4_ID, PORTB_PIN4_DIR,   PORTB_PIN4_InternalResistor, PORTB_PIN4_DigitalEnable, PORTB_PIN4_initial_value,
                  PORTB_PIN4_PinMode, PORTB_PIN4_DirectionChangeable, PORTB_PIN4_ModeChangeable},
                 {PORTB_ID, PIN5_ID, PORTB_PIN5_DIR,   PORTB_PIN5_InternalResistor, PORTB_PIN5_DigitalEnable, PORTB_PIN5_initial_value,
                  PORTB_PIN5_PinMode, PORTB_PIN5_DirectionChangeable, PORTB_PIN5_ModeChangeable},
                 {PORTB_ID, PIN6_ID, PORTB_PIN6_DIR,   PORTB_PIN6_InternalResistor, PORTB_PIN6_DigitalEnable, PORTB_PIN6_initial_value,
                  PORTB_PIN6_PinMode, PORTB_PIN6_DirectionChangeable, PORTB_PIN6_ModeChangeable},
                 {PORTB_ID, PIN7_ID, PORTB_PIN7_DIR,   PORTB_PIN7_InternalResistor, PORTB_PIN7_DigitalEnable, PORTB_PIN7_initial_value,
                  PORTB_PIN7_PinMode, PORTB_PIN7_DirectionChangeable, PORTB_PIN7_ModeChangeable},

                 /* PORTC */ //Skipped over the JTag pins (PC0 -> PC3)
                 {PORTC_ID, PIN4_ID, PORTC_PIN4_DIR,   PORTC_PIN4_InternalResistor, PORTC_PIN4_DigitalEnable, PORTC_PIN4_initial_value,
                  PORTC_PIN4_PinMode, PORTC_PIN4_DirectionChangeable, PORTC_PIN4_ModeChangeable},
                 {PORTC_ID, PIN5_ID, PORTC_PIN5_DIR,   PORTC_PIN5_InternalResistor, PORTC_PIN5_DigitalEnable, PORTC_PIN5_initial_value,
                  PORTC_PIN5_PinMode, PORTC_PIN5_DirectionChangeable, PORTC_PIN5_ModeChangeable},
                 {PORTC_ID, PIN6_ID, PORTC_PIN6_DIR,   PORTC_PIN6_InternalResistor, PORTC_PIN6_DigitalEnable, PORTC_PIN6_initial_value,
                  PORTC_PIN6_PinMode, PORTC_PIN6_DirectionChangeable, PORTC_PIN6_ModeChangeable},
                 {PORTC_ID, PIN7_ID, PORTC_PIN7_DIR,   PORTC_PIN7_InternalResistor, PORTC_PIN7_DigitalEnable, PORTC_PIN7_initial_value,
                  PORTC_PIN7_PinMode, PORTC_PIN7_DirectionChangeable, PORTC_PIN7_ModeChangeable},

                 /* PORTD */
                 {PORTD_ID, PIN0_ID, PORTD_PIN0_DIR,   PORTD_PIN0_InternalResistor, PORTD_PIN0_DigitalEnable, PORTD_PIN0_initial_value,
                  PORTD_PIN0_PinMode, PORTD_PIN0_DirectionChangeable, PORTD_PIN0_ModeChangeable},
                 {PORTD_ID, PIN1_ID, PORTD_PIN1_DIR,   PORTD_PIN1_InternalResistor, PORTD_PIN1_DigitalEnable, PORTD_PIN1_initial_value,
                  PORTD_PIN1_PinMode, PORTD_PIN1_DirectionChangeable, PORTD_PIN1_ModeChangeable},
                 {PORTD_ID, PIN2_ID, PORTD_PIN2_DIR,   PORTD_PIN2_InternalResistor, PORTD_PIN2_DigitalEnable, PORTD_PIN2_initial_value,
                  PORTD_PIN2_PinMode, PORTD_PIN2_DirectionChangeable, PORTD_PIN2_ModeChangeable},
                 {PORTD_ID, PIN3_ID, PORTD_PIN3_DIR,   PORTD_PIN3_InternalResistor, PORTD_PIN3_DigitalEnable, PORTD_PIN3_initial_value,
                  PORTD_PIN3_PinMode, PORTD_PIN3_DirectionChangeable, PORTD_PIN3_ModeChangeable},
                 {PORTD_ID, PIN4_ID, PORTD_PIN4_DIR,   PORTD_PIN4_InternalResistor, PORTD_PIN4_DigitalEnable, PORTD_PIN4_initial_value,
                  PORTD_PIN4_PinMode, PORTD_PIN4_DirectionChangeable, PORTD_PIN4_ModeChangeable},
                 {PORTD_ID, PIN5_ID, PORTD_PIN5_DIR,   PORTD_PIN5_InternalResistor, PORTD_PIN5_DigitalEnable, PORTD_PIN5_initial_value,
                  PORTD_PIN5_PinMode, PORTD_PIN5_DirectionChangeable, PORTD_PIN5_ModeChangeable},
                 {PORTD_ID, PIN6_ID, PORTD_PIN6_DIR,   PORTD_PIN6_InternalResistor, PORTD_PIN6_DigitalEnable, PORTD_PIN6_initial_value,
                  PORTD_PIN6_PinMode, PORTD_PIN6_DirectionChangeable, PORTD_PIN6_ModeChangeable},
                 {PORTD_ID, PIN7_ID, PORTD_PIN7_DIR,   PORTD_PIN7_InternalResistor, PORTD_PIN7_DigitalEnable, PORTD_PIN7_initial_value, //PD7
                  PORTD_PIN7_PinMode, PORTD_PIN7_DirectionChangeable, PORTD_PIN7_ModeChangeable},

                 /* PORTE */
                 {PORTE_ID, PIN0_ID, PORTE_PIN0_DIR,   PORTE_PIN0_InternalResistor, PORTE_PIN0_DigitalEnable, PORTE_PIN0_initial_value,
                  PORTE_PIN0_PinMode, PORTE_PIN0_DirectionChangeable, PORTE_PIN0_ModeChangeable},
                 {PORTE_ID, PIN1_ID, PORTE_PIN1_DIR,   PORTE_PIN1_InternalResistor, PORTE_PIN1_DigitalEnable, PORTE_PIN1_initial_value,
                  PORTE_PIN1_PinMode, PORTE_PIN1_DirectionChangeable, PORTE_PIN1_ModeChangeable},
                 {PORTE_ID, PIN2_ID, PORTE_PIN2_DIR,   PORTE_PIN2_InternalResistor, PORTE_PIN2_DigitalEnable, PORTE_PIN2_initial_value,
                  PORTE_PIN2_PinMode, PORTE_PIN2_DirectionChangeable, PORTE_PIN2_ModeChangeable},
                 {PORTE_ID, PIN3_ID, PORTE_PIN3_DIR,   PORTE_PIN3_InternalResistor, PORTE_PIN3_DigitalEnable, PORTE_PIN3_initial_value,
                  PORTE_PIN3_PinMode, PORTE_PIN3_DirectionChangeable, PORTE_PIN3_ModeChangeable},
                 {PORTE_ID, PIN4_ID, PORTE_PIN4_DIR,   PORTE_PIN4_InternalResistor, PORTE_PIN4_DigitalEnable, PORTE_PIN4_initial_value,
                  PORTE_PIN4_PinMode, PORTE_PIN4_DirectionChangeable, PORTE_PIN4_ModeChangeable},

                 /* PORTF */
                 {PORTF_ID, PIN0_ID, PORTF_PIN0_DIR,   PORTF_PIN0_InternalResistor, PORTF_PIN0_DigitalEnable, PORTF_PIN0_initial_value,
                  PORTF_PIN0_PinMode, PORTF_PIN0_DirectionChangeable, PORTF_PIN0_ModeChangeable},
                 {PORTF_ID, PIN1_ID, PORTF_PIN1_DIR,   PORTF_PIN1_InternalResistor, PORTF_PIN1_DigitalEnable, PORTF_PIN1_initial_value, //PF1 LED1
                  PORTF_PIN1_PinMode, PORTF_PIN1_DirectionChangeable, PORTF_PIN1_ModeChangeable},
                 {PORTF_ID, PIN2_ID, PORTF_PIN2_DIR,   PORTF_PIN2_InternalResistor, PORTF_PIN2_DigitalEnable, PORTF_PIN2_initial_value,
                  PORTF_PIN2_PinMode, PORTF_PIN2_DirectionChangeable, PORTF_PIN2_ModeChangeable},
                 {PORTF_ID, PIN3_ID, PORTF_PIN3_DIR,   PORTF_PIN3_InternalResistor, PORTF_PIN3_DigitalEnable, PORTF_PIN3_initial_value,
                  PORTF_PIN3_PinMode, PORTF_PIN3_DirectionChangeable, PORTF_PIN3_ModeChangeable},
                 {PORTF_ID, PIN4_ID, PORTF_PIN4_DIR,   PORTF_PIN4_InternalResistor, PORTF_PIN4_DigitalEnable, PORTF_PIN4_initial_value, //PF4 Switch 1
                  PORTF_PIN4_PinMode, PORTF_PIN4_DirectionChangeable, PORTF_PIN4_ModeChangeable}
             }
         };







