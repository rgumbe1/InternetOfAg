// ================================================================ 
// ===                         FORMAT                           === 
// ================================================================

// This files is the recommended place for placing wrappers for 
// functions to be called by the hub scripts.
// That is, the script calls these functions (as they have a known 
// type signature) which in turn translate those arguments and
// return to properly interface with existing or new functions that
// cannot be directly called by the script.
//
// If you function is not very complex and does not already exist
// elsewhere, your function need not be a wrapper and can just run
// the necessary code in itself.
//
// The wrappers / functions called by the scripts need to be added 
// to the 'strToFunc' function in 'loom_hub_scripts.h' so that as 
// script can turn as string of the wrapper name into a function 
// pointer.

// ================================================================ 
// ===                 WRAPPER TYPE SIGNATURE                   === 
// ================================================================

// Functions that are called by the script parser are expected to 
// have the following type signature:

// 		float example(float x, float y)


// ================================================================ 
// ===                       DEFINITIONS                        === 
// ================================================================
// Used to make function signatures easier to read 
// when returning function pointers
typedef float (*retFuncPtr)(float,float); 


// ================================================================ 
// ===                        STRUCTURES                        === 
// ================================================================ 



// ================================================================ 
// ===                   GLOBAL DECLARATIONS                    === 
// ================================================================




// ================================================================ 
// ===           REGISTER ACCESS FUNCTION PROTOTYPES            === 
// ================================================================

// Used for accessing the registers outside of the script
// Generally useful for if wrapper functions need more data that 
// the two floats as parameters can provide

// Returns the value in the rth register of the R (b=0), S (b=1), or T (b=2) bank
float load_reg(int b, int r); 			
// Sets the value in the rth register of the R (b=0), S (b=1), or T (b=2) bank to be val
void  store_reg(int b, int r, float val); 


// ================================================================ 
// ===                   FUNCTION PROTOTYPES                    === 
// ================================================================

float blink_ex(float x, float y);


// ================================================================
// ===                        FUNCTIONS                         ===
// ================================================================

// This function was used for testing and is left for example purposes
// A basic script to run it would be:
//
//		OSCMessage script = new OSCMessage("/script_name");
//		script.add(8.0).add(150.0).add("blink_ex");
//
float blink_ex(float x, float y)
{
	for (int i = 0; i < (int)x; i++)
	{
		digitalWrite(led, HIGH);  
		delay( (int)y ); 
		digitalWrite(led, LOW);  
		delay( (int)y ); 
	}
}



// --- CUSTOM STRING TO FUNCTION ---
//
// This function takes a string that matches or
// represents a function, and returns a pointer of 
// the corresponding function.
// 
// This function extends the functions/strings that strToFunc 
// checks against.
//
// This is called if a command in the script does not match any
// official functions.
//
// The separation from that function is to keep these comparisons 
// near the functions they go with, which are in this file.
//
// Refer to 'strToFunc' for examples on adding new functions
// Note that you can have multiple strings refer the same function
//  Ex: 'add' or '+' both mean to add the top two values on the stack  
//
retFuncPtr custom_strToFunc(char * str) {

	if (strcmp(str, "blink_ex") == 0)  return blink_ex;
	


	return NULL; // Return Null if no match found, do not change
}




