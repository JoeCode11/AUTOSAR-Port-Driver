 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Youssef Tamer
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Dio Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macro for defining the build variant
 */
#define PORT_VARIANT_POST_BUILD  (STD_ON)

/*
 * Macros for Dio Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

///*******************************************************************************
// *                              Module Definitions                             * Find them in Port_Regs.h now
// *******************************************************************************/
//
/* GPIO Registers base addresses */
//#define GPIO_PORTA_BASE_ADDRESS           0x40004000
//#define GPIO_PORTB_BASE_ADDRESS           0x40005000
//#define GPIO_PORTC_BASE_ADDRESS           0x40006000
//#define GPIO_PORTD_BASE_ADDRESS           0x40007000
//#define GPIO_PORTE_BASE_ADDRESS           0x40024000
//#define GPIO_PORTF_BASE_ADDRESS           0x40025000
//
///* GPIO Registers offset addresses */
//#define PORT_DATA_REG_OFFSET              0x3FC
//#define PORT_DIR_REG_OFFSET               0x400
//#define PORT_ALT_FUNC_REG_OFFSET          0x420
//#define PORT_PULL_UP_REG_OFFSET           0x510
//#define PORT_PULL_DOWN_REG_OFFSET         0x514
//#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
//#define PORT_LOCK_REG_OFFSET              0x520
//#define PORT_COMMIT_REG_OFFSET            0x524
//#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
//#define PORT_CTL_REG_OFFSET               0x52C



/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define Port_Init_SID           (uint8)0x00

/* Service ID for DIO read Port */
#define Port_Set_Pin_Direction_SID              (uint8)0x01

/* Service ID for DIO write Port */
#define Port_Refresh_Port_Direction_SID             (uint8)0x02

/* Service ID for DIO read Channel Group */
#define Port_Get_Version_Info_SID     (uint8)0x03

/* Service ID for DIO write Channel Group */
#define Port_Set_Pin_Mode_SID    (uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define PORT_E_PARAM_PIN (uint8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define PORT_E_DIRECTION_UNCHANGEABLE             (uint8)0x0B

/* DET code to report Invalid Port */
#define PORT_E_PARAM_CONFIG    (uint8)0x0C

/* DET code to report Invalid Channel Group */
#define PORT_E_PARAM_INVALID_MODE      (uint8)0x0D

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define PORT_E_MODE_UNCHANGEABLE             (uint8)0x0E

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define PORT_E_UNINIT                   (uint8)0x0F

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define PORT_E_PARAM_POINTER                   (uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/*Data type for the symbolic name of a port pin. */
typedef uint8 Port_PinType;

/*Data type for the symbolic name of a port pin mode. */
typedef uint8 Port_PinModeType;

//typedef uint8 Port_PinDirectionType;


/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}Port_PinDirectionType; //from port_PinDirection to Port_PinDirectionType
/*********************************VERY IMPORTANT (check if this caused errors), I CHANGED NAME OF THE ENUM******************************/

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;


typedef enum
{
    LOW, HIGH
}Port_InitialValue;


#define PORT_DIR_Changeable                 (0x1)
#define PORT_DIR_Not_Changeable                 (0x0)

#define PORT_Mode_Changeable                 (0x1)
#define PORT_Mode_Not_Changeable                 (0x0)

//typedef enum {
//} Port_PinModeTypeEnum;

#define PORT_PIN_MODE_DIO (uint8)0
#define PORT_PIN_MODE_ADC (uint8)1
#define PORT_PIN_MODE_UART (uint8)2
#define PORT_PIN_MODE_SSI (uint8)3
#define PORT_PIN_MODE_I2C (uint8)4
#define PORT_PIN_MODE_CAN (uint8)5

//#define PORT_PIN_INTERNAL_PULL_UP    (1U)
//#define PORT_PIN_INTERNAL_PULL_DOWN  (2U)
//#define PORT_PIN_NO_PULL             (0U)

//#define PORT_LED_PIN   {PORTF_ID, PIN1_ID, OUTPUT, PORT_PIN_NO_PULL, LOW, PORT_PIN_MODE_DIO, PORT_DIR_Changeable, PORT_Mode_Changeable}
//#define PORT_BUTTON_PIN {PORTF_ID, PIN4_ID, INPUT, PORT_PIN_NO_PULL, LOW, PORT_PIN_MODE_DIO, PORT_DIR_Changeable, PORT_Mode_Changeable}
/* Description: Structure to configure each individual PIN:
 *  1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *  2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 */
typedef struct Port_ConfigPin
{
    uint8 port_num; 
    uint8 pin_num; 
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    /*My additions*/
    uint8 DigitalEnable;
    #if (PORT_PIN_LEVEL_VALUE == STD_ON)
        uint8 initial_value;
    #endif
    #if (PORT_PIN_INITIAL_MODE == STD_ON)
        uint8 PinMode;
    #endif
    #if (PORT_PIN_DIRECTION_CHANGEABLE == STD_ON)
        uint8 DirectionChangeable;
    #endif /* (PORT_PIN_DIRECTION_CHANGEABLE == STD_ON) */
    #if (PORT_PIN_MODE_CHANGEABLE == STD_ON)
        uint8 ModeChangeable;
    #endif
}Port_ConfigPin;

typedef struct Port_ConfigType
{
    Port_ConfigPin Pin[PORT_CONFIGURED_PINS];
} Port_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
 * Service Name: Port_Init
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Setup the pin configuration:
 *              - Setup the pin as Digital GPIO pin
 *              - Setup the direction of the GPIO pin
 *              - Setup the internal resistor for i/p pin
 ************************************************************************************/
void Port_Init(const Port_ConfigType *ConfigPtr);


/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number , Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Sets the port pin direction.
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin_ID, Port_PinDirectionType Direction);
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection(void);

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin_ID, Port_PinModeType Mode);
#endif




/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
