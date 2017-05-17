/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */
extern u8 G_au8DebugScanfBuffer[];  /* From debug.c */
extern u8 G_u8DebugScanfCharCount; 

/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 

*/
void UserApp1Initialize(void)
{
 
 /* If good initialization, set state to Idle */
  if( 1 )
  {
   
    UserApp1_StateMachine =Debug_serial_port;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_FailedInit;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
//end Debug Interface 

void Debug_serial_port(void)
{   u8 u8_temp = 0;
    static u8 u8_temp_counter=0;
	static u8 u8_temp_counter1=0;
	static u8 u8_temp_bit     =0;
    u8 u8_name[] ="yangyang";
	static u8 u8_bit_set      =0;
	u8 u8_character[] = "*********";
    u8 string_u8[]="\n\rCharacters in buffer: ";
	static u8 u8NumCharsMessage[] = "\n\rCharacters in buffer: ";
	static bool send_port = FALSE;
	if(WasButtonPressed(BUTTON0))
		{ButtonAcknowledge(BUTTON0);
	     DebugPrintf(string_u8);
		 DebugLineFeed();
		   if(send_port == FALSE)
		   	send_port= TRUE;
		   else 
		   	send_port= FALSE;
		  }
        
  
  /* Print message with number of characters in scanf buffer */
  if(WasButtonPressed(BUTTON3))
  {
	   ButtonAcknowledge(BUTTON3);
	   
	    u8_temp_counter1=0;//重新计算
	   
	 
	  for(u8_temp=0;u8_temp<=G_u8DebugScanfCharCount;u8_temp++)
	  	
	          { 
	            if(G_au8DebugScanfBuffer[u8_temp]== u8_name[u8_temp_counter])
	          	{
	          	u8_temp_counter++;
					if(u8_temp_counter>=6)
						{
						u8_temp_counter = 0;
						u8_temp_counter1++;
						}
	          	  
	          	  //send_port= TRUE;
	          	}
	          
			  	///again back
	  	}
  	}
  if(WasButtonPressed(BUTTON2))
	  	{
	  	   DebugPrintf("\r\n***\r\n");
			ButtonAcknowledge(BUTTON2);
			DebugPrintNumber(u8_temp_counter1);
			DebugPrintf("\r\n***");
			DebugPrintf("\r\n");
			DebugPrintf("your name:\r\n");
			//DebugPrintf(u8_name);
			DebugPrintf("******\r\n");
			//DebugPrintf(G_au8DebugScanfBuffer);
	  	}
  if(WasButtonPressed(BUTTON1))
	  	{
		  	ButtonAcknowledge(BUTTON1);
		  	for(u8_temp_counter=0;u8_temp_counter<=4;u8_temp_counter++)
			  	{
			  	  if(u8_temp_counter1%(10^u8_temp_counter)==0)//求出多少位
				  	continue;
				  else
				  	u8_bit_set++;  
			  	}
		  	
		  	 for(u8_temp_counter=0;u8_temp_counter<=u8_bit_set;u8_temp_counter++)
		  	 	{
		  	 	   u8_character[u8_temp_counter]='*';
		  	 	}
	                   DebugPrintf("\r\n");
		  	   DebugPrintf(u8_character);
			   DebugPrintf("\r\n");
			   DebugPrintf("*");
			   DebugPrintNumber(u8_temp_counter1);
			   DebugPrintf("*");
			   DebugPrintf("\r\n");
	                   
	                  DebugPrintf(u8_character);
	                  DebugPrintf("\r\n");
				//DebugPrintf(G_au8DebugScanfBuffer);
	  	}
	


}




static void UserApp1SM_Idle(void)
{ 
  static u32 COUNTER_LIMIT_MS=1;
  static u32 u32Counter = 0;
  static bool bLightIsOn = FALSE;
  
  /*Increment u32Counter every 1ms cycle*/
  u32Counter++;
  if(COUNTER_LIMIT_MS==500)
  {
     u32Counter = 0;
     if(bLightIsOn)
    {
      HEARTBEAT_OFF();
      
    }
    else
    {
      HEARTBEAT_ON();
    }
    return;
  }
  /*Check and roll over*/
  if(u32Counter == COUNTER_LIMIT_MS)
  {
     u32Counter = 0;
    
    if(bLightIsOn)
    {
      HEARTBEAT_OFF();
      COUNTER_LIMIT_MS= COUNTER_LIMIT_MS*2;
    }
    else
    {
      HEARTBEAT_ON();
    }
    
    bLightIsOn = !bLightIsOn;
  }
 /* end UserApp1SM_Idle() */
    
https://github.com/zhanggangcheng526/Razor_Atmel/tree/firmware-assignment-frequence-decrease
} /* end UserApp1SM_Idle() */  
#if 0
/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */
#endif


/*-------------------------------------------------------------------------------------------------------------------*/
/* State to sit in if init failed */
static void UserApp1SM_FailedInit(void)          
{
    
} /* end UserApp1SM_FailedInit() */


/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
