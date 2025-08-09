 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Youssef Tamer
 ******************************************************************************/

#include "Port.h"
#include "tm4c123gh6pm_registers.h"
#include "Port_Regs.h"
//#include <stdbool.h> //addition1 to fix errors

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif


STATIC const Port_ConfigPin * Port_Pins = NULL_PTR; //pointer to structure configPin (individual pin configurations)

STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin by default
*              - Setup the direction of the GPIO pin
*              - Provide initial value for o/p pin
*              - Setup the internal resistor for i/p pin
*              - Setup the DirectionChangeable feature of a pin
*              - Setup the ModeChangeable feature of a pin
************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr ){ //setting different modes still remains
#if (PORT_DEV_ERROR_DETECT == STD_ON && PORT_CONFIG_VARIANT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == ConfigPtr)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_Init_SID,
                        PORT_E_PARAM_CONFIG);
    }
    else
#endif
    {
        Port_Pins = ConfigPtr->Pin; //Point to first element in the array of ConfigPin struct (so point to array of all tiva pins)
        volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */

        volatile uint8 i;
        for (i = 0; i<PORT_CONFIGURED_PINS; i++){
            switch(Port_Pins[i].port_num) //since we dereference the address, we are using a struct object, thereby (.) not (->)
            {
                case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                         break;
                case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                         break;
                case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                         break;
                case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                         break;
                case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                         break;
                case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                         break;
            }



            if( ((Port_Pins[i].port_num == 3) && (Port_Pins[i].pin_num == 7)) || ((Port_Pins[i].port_num == 5) && (Port_Pins[i].pin_num == 0)) ) /* PD7 or PF0 */
                {
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , Port_Pins[i].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
                }
                else if( (Port_Pins[i].port_num == 2) && (Port_Pins[i].pin_num <= 3) ) /* PC0 to PC3 */
                {
                    continue;
                    /* These are the JTAG pins */
                }
                else
                {
                    /* Do Nothing ... No need to unlock the commit register for this pin */
                }

            /* Need to set up different modes, not just GPIO, Copy code from mode set pins, with few modifications */

            /* UART Setting*/
             if (Port_Pins[i].PinMode == PORT_PIN_MODE_UART) {
                 boolean ok = FALSE;

                 /* all UART-capable (port, Port_Pins[i]) pairs on TM4C123GH6PM */
                 if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS &&
                      (Port_Pins[i].pin_num == 0 || Port_Pins[i].pin_num == 1) ) {
                      ok = TRUE;
                 }
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 0 || Port_Pins[i].pin_num == 1) ) {
                     ok = TRUE;
                 }
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 6 || Port_Pins[i].pin_num == 7) ) {
                     ok = TRUE;
                 }
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 6 || Port_Pins[i].pin_num == 7) ) {
                     ok = TRUE;
                 }
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 4 || Port_Pins[i].pin_num == 5) ) {
                     ok = TRUE;
                 }
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 4 || Port_Pins[i].pin_num == 5) ) {
                     ok = TRUE;
                 }
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 4 || Port_Pins[i].pin_num == 5) ) {
                     ok = TRUE;
                 }
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 0 || Port_Pins[i].pin_num == 1) ) {
                     ok = TRUE;
                 }

                 if (ok) {
                     /* Disable analog */
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),
                               Port_Pins[i].pin_num);
                     /* Enable alt function */
                     SET_BIT  (*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET),
                               Port_Pins[i].pin_num);
                     /* Set PCTL to UART function (PMCx) */
                     *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET)
                         |= (0x00000001 << (Port_Pins[i].pin_num * 4));
                     /* Enable digital */
                     SET_BIT  (*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),
                               Port_Pins[i].pin_num);
                 }
                 else {
                     /* Report invalid mode/change */
                     Det_ReportError(PORT_MODULE_ID,
                                     PORT_INSTANCE_ID,
                                     Port_Init_SID,
                                     PORT_E_PARAM_CONFIG);
                     /* return immediately */
                     return;
                 }
             }
             else if (Port_Pins[i].PinMode == PORT_PIN_MODE_SSI) {
                 boolean ok = FALSE;

                 if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS &&
                      (Port_Pins[i].pin_num >= 2 && Port_Pins[i].pin_num <= 5) ) {
                     ok = TRUE;
                 }

                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS &&
                           (/*Port_Pins[i].pin_num >= 0 &&*/ Port_Pins[i].pin_num <= 3) ) {
                     ok = TRUE;
                 }

                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num >= 4 && Port_Pins[i].pin_num <= 7) ) {
                     ok = TRUE;
                 }

                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS &&
                           (/*Port_Pins[i].pin_num >= 0 && */Port_Pins[i].pin_num <= 3) ) {
                     ok = TRUE;
                 }

                 if (!ok) {
                     Det_ReportError(PORT_MODULE_ID,
                                     PORT_INSTANCE_ID,
                                     Port_Init_SID,
                                     PORT_E_MODE_UNCHANGEABLE);
                     return;
                 }
                 else{
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[i].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this Port_Pins[i] */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[i].pin_num);             /* Enable Alternative function for this Port_Pins[i] by clear the corresponding bit in GPIOAFSEL register */
                     *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000002 << (Port_Pins[i].pin_num * 4));     /* Set the PMCx bits for this Port_Pins[i] */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[i].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this Port_Pins[i] */
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input Port_Pins[i] */

                 }
             }
             else if (Port_Pins[i].PinMode == PORT_PIN_MODE_ADC ){
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[i].pin_num);      /* Set the corresponding bit in the GPIOAMSEL register to disable analog functionality on this Port_Pins[i] */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[i].pin_num);             /* Enable Alternative function for this Port_Pins[i] by clear the corresponding bit in GPIOAFSEL register */
                     *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[i].pin_num * 4));     /* Clear the PMCx bits for this Port_Pins[i] */
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[i].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this Port_Pins[i] */
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input Port_Pins[i] */
             }
             else if (Port_Pins[i].PinMode ==  PORT_PIN_MODE_DIO){
                 CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input Port_Pins[i] */
                 CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[i].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this Port_Pins[i] */
                 CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[i].pin_num);             /* Disable Alternative function for this Port_Pins[i] by clear the corresponding bit in GPIOAFSEL register */
                 *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_Pins[i].pin_num * 4));     /* Clear the PMCx bits for this Port_Pins[i] */
                 SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[i].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this Port_Pins[i] */
             }
             else if (Port_Pins[i].PinMode == PORT_PIN_MODE_I2C) {
                 boolean ok = FALSE;

                 /* I2C0: PB2/PB3 */
                 if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS &&
                      (Port_Pins[i].pin_num == 2 || Port_Pins[i].pin_num == 3) ) {
                     ok = TRUE;
                 }
                 /* I2C1: PA6/PA7 */
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 6 || Port_Pins[i].pin_num == 7) ) {
                     ok = TRUE;
                 }
                 /* I2C2: PE4/PE5 */
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 4 || Port_Pins[i].pin_num == 5) ) {
                     ok = TRUE;
                 }
                 /* I2C3: PD0/PD1 */
                 else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS &&
                           (Port_Pins[i].pin_num == 0 || Port_Pins[i].pin_num == 1) ) {
                     ok = TRUE;
                 }

                 if (!ok) {
                     Det_ReportError(PORT_MODULE_ID,
                                     PORT_INSTANCE_ID,
                                     Port_Init_SID,
                                     PORT_E_MODE_UNCHANGEABLE);
                     return;
                 }
                 else{
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[i].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this Port_Pins[i] */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[i].pin_num);             /* Enable Alternative function for this Port_Pins[i] by clear the corresponding bit in GPIOAFSEL register */
                     *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000003 << (Port_Pins[i].pin_num * 4));     /* Set the PMCx bits for this Port_Pins[i] */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[i].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this Port_Pins[i] */
                     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input Port_Pins[i] */

                 }
             }
             else if (Port_Pins[i].PinMode == PORT_PIN_MODE_CAN) {
                 boolean ok = FALSE;
                 if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS &&
                          (Port_Pins[i].pin_num == 0 || Port_Pins[i].pin_num == 3) ) {
                         ok = TRUE;
                     }
                     /* CAN0Rx/Tx alt: PB4/PB5 */
                     else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS &&
                               (Port_Pins[i].pin_num == 4 || Port_Pins[i].pin_num == 5) ) {
                         ok = TRUE;
                     }
                     /* CAN0Rx/Tx alt2: PE4/PE5 */
                     else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS &&
                               (Port_Pins[i].pin_num == 4 || Port_Pins[i].pin_num == 5) ) {
                         ok = TRUE;
                     }
                     /* CAN1Rx/Tx: PA0/PA1 */
                     else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS &&
                               (Port_Pins[i].pin_num == 0 || Port_Pins[i].pin_num == 1) ) {
                         ok = TRUE;
                     }

                     if (!ok) {
                         Det_ReportError(PORT_MODULE_ID,
                                         PORT_INSTANCE_ID,
                                         Port_Init_SID,
                                         PORT_E_MODE_UNCHANGEABLE);
                         return;
                     }
                     else{
                         CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[i].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this Port_Pins[i] */
                         SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[i].pin_num);             /* Enable Alternative function for this Port_Pins[i] by clear the corresponding bit in GPIOAFSEL register */
                         *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000008 << (Port_Pins[i].pin_num * 4));     /* Set the PMCx bits for this Port_Pins[i] */
                         SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[i].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this Port_Pins[i] */
                         //CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input Port_Pins[i] */

                     }
             }

            if(Port_Pins[i].direction == OUTPUT)
                       {

                           if(Port_Pins[i].initial_value == STD_HIGH)
                           {
                               SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[i].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                           }
                           else
                           {
                               CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[i].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                           }
                           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);               /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                       }
                       else if(Port_Pins[i].direction == INPUT)
                       {
                           if(Port_Pins[i].resistor == PULL_UP)
                           {
                               SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[i].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                           }
                           else if(Port_Pins[i].resistor == PULL_DOWN)
                           {
                               SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[i].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                           }
                           else
                           {
                               CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[i].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                               CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[i].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                           }
                           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[i].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                       }
                       else
                       {
                           /* Do Nothing */
                       }
        }
        Port_Status = PORT_INITIALIZED;
    }

}


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
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if(NULL_PTR == versioninfo)
    {
        /* Report to DET  */
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_Get_Version_Info_SID, PORT_E_PARAM_POINTER);
    }
    else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
    }
}
#endif


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
void Port_SetPinDirection(Port_PinType Pin_ID, Port_PinDirectionType Direction){
   // to ensure re-entrancy
//    Disable_Exceptions(); //Disable interrupts
    const Port_ConfigPin* pin = &(Port_Configuration.Pin[Pin_ID]);
    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    boolean error = FALSE;


#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_Set_Pin_Direction_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* Check if the used channel is within the valid range */
    if (PORT_CONFIGURED_PINS <= Pin_ID)
    {

        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_Set_Pin_Direction_SID, PORT_E_PARAM_PIN);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }
    /* Check if port pin is direction changeable */
    if ( pin->DirectionChangeable == PORT_DIR_Not_Changeable){
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_Set_Pin_Direction_SID, PORT_E_DIRECTION_UNCHANGEABLE);
                error = TRUE;
    }
#endif

    /* In-case there are no errors */
        if(FALSE == error)
        {
            switch(pin->port_num) //since we dereference the address, we are using a struct object, thereby (.) not (->)
                        {
                            case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                                     break;
                            case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                                     break;
                            case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                                     break;
                            case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                                     break;
                            case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                                     break;
                            case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                                     break;
                        }
            if ((pin->port_num == 2) && (pin->pin_num <= 3)) /* PC0 to PC3 */
            {
                /* Return ...  this is the JTAG pins */
                return;
            }
            if (pin->direction == INPUT && pin->direction == OUTPUT){
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin->pin_num); //set as input
            }
            else if (pin->direction == OUTPUT && pin->direction == INPUT){
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin->pin_num); //set as output
            }
            else{
                /* Do nothing */
            }
        }
        else{
            /* Do nothing */
        }
//    Enable_Exceptions(); //enable back the interrupts
}
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
void Port_RefreshPortDirection(void){

    boolean error = FALSE;
    volatile uint32 *PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */

#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Driver is initialized before using this function */
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                        Port_Refresh_Port_Direction_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else{
        /* Do Nothing */
    }
#endif
    if (FALSE == error){
        volatile uint8 i;
        for (i = 0; i<PORT_CONFIGURED_PINS; i++){
            if ((Port_Configuration.Pin[i].port_num == 2) && (Port_Configuration.Pin[i].pin_num <= 3)) /* PC0 to PC3 */
            {
                continue;
                /* Do Nothing ...  this is the JTAG pins */
            }
            else{
                /* Do nothing */
            }
            if (Port_Configuration.Pin[i].DirectionChangeable == PORT_DIR_Changeable){
                continue;
            }
            else {
                switch(Port_Configuration.Pin[i].port_num) //since we dereference the address, we are using a struct object, thereby (.) not (->)
                        {
                            case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                                     break;
                            case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                                     break;
                            case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                                     break;
                            case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                                     break;
                            case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                                     break;
                            case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                                     break;
                        }
                if(Port_Configuration.Pin[i].direction == OUTPUT) {
                    /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Configuration.Pin[i].pin_num);
                }
                else{
                    /* Set the corresponding bit in the GPIODIR register to configure it as input pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , Port_Configuration.Pin[i].pin_num);
                }
            }
        }
    }
    else{
        /* Do nothing */
    }
}


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
void Port_SetPinMode(Port_PinType Pin_ID, Port_PinModeType Mode){
    // to ensure re-entrancy
//        Disable_Exceptions(); //Disable interrupts
        const Port_ConfigPin* pin = &(Port_Configuration.Pin[Pin_ID]);
        volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
        boolean error = FALSE;
//        Port_PinModeTypeEnum modeEnum;


    #if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* Check if the Driver is initialized before using this function */
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                            Port_Set_Pin_Mode_SID, PORT_E_UNINIT);
            error = TRUE;
        }
        else
        {
            /* No Action Required */
        }
        /* Check if the used channel is within the valid range */
        if (PORT_CONFIGURED_PINS <= Pin_ID)
        {

            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                            Port_Set_Pin_Mode_SID, PORT_E_PARAM_PIN);
            error = TRUE;
        }
        else
        {
            /* No Action Required */
        }
        /* Check if port pin is direction changeable */
        if ( pin->ModeChangeable == PORT_Mode_Not_Changeable){
            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                            Port_Set_Pin_Mode_SID, PORT_E_MODE_UNCHANGEABLE);
                    error = TRUE;
        }
        if ( Mode != PORT_PIN_MODE_DIO &&
                Mode != PORT_PIN_MODE_ADC &&
                Mode != PORT_PIN_MODE_UART &&
                Mode != PORT_PIN_MODE_SSI &&
                Mode != PORT_PIN_MODE_I2C &&
                Mode != PORT_PIN_MODE_CAN)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
                                        Port_Set_Pin_Mode_SID, PORT_E_PARAM_INVALID_MODE);
                                error = TRUE;
        }
        else
        {
                   /* No Action Required */
        }
    #endif

        if (error == FALSE){
            switch(pin->port_num) //since we dereference the address, we are using a struct object, thereby (.) not (->)
            {
                case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                     break;
                case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                     break;
                case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                     break;
                case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                     break;
                case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                     break;
                case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                     break;
            }
            /* UART Setting*/
            if (Mode == PORT_PIN_MODE_UART) {
                boolean ok = FALSE;

                /* all UART-capable (port, pin) pairs on TM4C123GH6PM */
                if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS &&
                     (pin->pin_num == 0 || pin->pin_num == 1) ) {
                     ok = TRUE;
                }
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS &&
                          (pin->pin_num == 0 || pin->pin_num == 1) ) {
                    ok = TRUE;
                }
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS &&
                          (pin->pin_num == 6 || pin->pin_num == 7) ) {
                    ok = TRUE;
                }
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS &&
                          (pin->pin_num == 6 || pin->pin_num == 7) ) {
                    ok = TRUE;
                }
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS &&
                          (pin->pin_num == 4 || pin->pin_num == 5) ) {
                    ok = TRUE;
                }
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS &&
                          (pin->pin_num == 4 || pin->pin_num == 5) ) {
                    ok = TRUE;
                }
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS &&
                          (pin->pin_num == 4 || pin->pin_num == 5) ) {
                    ok = TRUE;
                }
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS &&
                          (pin->pin_num == 0 || pin->pin_num == 1) ) {
                    ok = TRUE;
                }

                if (ok) {
                    /* Disable analog */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET),
                              pin->pin_num);
                    /* Enable alt function */
                    SET_BIT  (*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET),
                              pin->pin_num);
                    /* Set PCTL to UART function (PMCx) */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET)
                        |= (0x00000001 << (pin->pin_num * 4));
                    /* Enable digital */
                    SET_BIT  (*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET),
                              pin->pin_num);
                }
                else {
                    /* Report invalid mode/change */
                    Det_ReportError(PORT_MODULE_ID,
                                    PORT_INSTANCE_ID,
                                    Port_Set_Pin_Mode_SID,
                                    PORT_E_PARAM_INVALID_MODE);
                    /* return immediately */
                    return;
                }
            }
            else if (Mode == PORT_PIN_MODE_SSI) {
                boolean ok = FALSE;

                if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS &&
                     (pin->pin_num >= 2 && pin->pin_num <= 5) ) {
                    ok = TRUE;
                }

                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS &&
                          (/*pin->pin_num >= 0 &&*/ pin->pin_num <= 3) ) {
                    ok = TRUE;
                }

                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS &&
                          (pin->pin_num >= 4 && pin->pin_num <= 7) ) {
                    ok = TRUE;
                }

                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS &&
                          (/*pin->pin_num >= 0 && */pin->pin_num <= 3) ) {
                    ok = TRUE;
                }

                if (!ok) {
                    Det_ReportError(PORT_MODULE_ID,
                                    PORT_INSTANCE_ID,
                                    Port_Set_Pin_Mode_SID,
                                    PORT_E_PARAM_INVALID_MODE);
                    return;
                }
                else{
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin->pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , pin->pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000002 << (pin->pin_num * 4));     /* Set the PMCx bits for this pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , pin->pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin->pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

                }
            }
            else if (Mode == PORT_PIN_MODE_ADC ){
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin->pin_num);      /* Set the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , pin->pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (pin->pin_num * 4));     /* Clear the PMCx bits for this pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , pin->pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin->pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
            }
            else if (Mode ==  PORT_PIN_MODE_DIO){
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin->pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin->pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , pin->pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (pin->pin_num * 4));     /* Clear the PMCx bits for this pin */
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , pin->pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
            }
            else if (Mode == PORT_PIN_MODE_I2C) {
                boolean ok = FALSE;

                /* I2C0: PB2/PB3 */
                if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS &&
                     (pin->pin_num == 2 || pin->pin_num == 3) ) {
                    ok = TRUE;
                }
                /* I2C1: PA6/PA7 */
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS &&
                          (pin->pin_num == 6 || pin->pin_num == 7) ) {
                    ok = TRUE;
                }
                /* I2C2: PE4/PE5 */
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS &&
                          (pin->pin_num == 4 || pin->pin_num == 5) ) {
                    ok = TRUE;
                }
                /* I2C3: PD0/PD1 */
                else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS &&
                          (pin->pin_num == 0 || pin->pin_num == 1) ) {
                    ok = TRUE;
                }

                if (!ok) {
                    Det_ReportError(PORT_MODULE_ID,
                                    PORT_INSTANCE_ID,
                                    Port_Set_Pin_Mode_SID,
                                    PORT_E_PARAM_INVALID_MODE);
                    return;
                }
                else{
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin->pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , pin->pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000003 << (pin->pin_num * 4));     /* Set the PMCx bits for this pin */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , pin->pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin->pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

                }
            }
            else if (Mode == PORT_PIN_MODE_CAN) {
                boolean ok = FALSE;
                if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS &&
                         (pin->pin_num == 0 || pin->pin_num == 3) ) {
                        ok = TRUE;
                    }
                    /* CAN0Rx/Tx alt: PB4/PB5 */
                    else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS &&
                              (pin->pin_num == 4 || pin->pin_num == 5) ) {
                        ok = TRUE;
                    }
                    /* CAN0Rx/Tx alt2: PE4/PE5 */
                    else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS &&
                              (pin->pin_num == 4 || pin->pin_num == 5) ) {
                        ok = TRUE;
                    }
                    /* CAN1Rx/Tx: PA0/PA1 */
                    else if ( PortGpio_Ptr == (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS &&
                              (pin->pin_num == 0 || pin->pin_num == 1) ) {
                        ok = TRUE;
                    }

                    if (!ok) {
                        Det_ReportError(PORT_MODULE_ID,
                                        PORT_INSTANCE_ID,
                                        Port_Set_Pin_Mode_SID,
                                        PORT_E_PARAM_INVALID_MODE);
                        return;
                    }
                    else{
                        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , pin->pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , pin->pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000008 << (pin->pin_num * 4));     /* Set the PMCx bits for this pin */
                        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , pin->pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
                        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , pin->pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

                    }
            }
        }
//        Enable_Exceptions();
}
#endif


