// ================================================================
// ===              INCLUDE CONFIGURATION FILE                  ===
// ===    INCLUDE DECLARATIONS, STRUCTS, AND FUNCTIONS FROM     ===
// ===            OTHER FILES AS SET IN CONFIG.H                ===
// ================================================================

// Config has to be first has it hold all user specified options
#include "config.h"


// Preamble includes any relevant subroutine files based 
// on options specified in the above config
#include "loom_preamble.h"


// ================================================================ 
// ===                           SETUP                          ===
// ================================================================ 
void setup() 
{


	// LOOM_begin calls any relevant (based on config) LOOM device setup functions
	Loom_begin();	

	// Any custom setup code
}


// ================================================================ 
// ===                        MAIN LOOP                         ===
// ================================================================ 
void loop() 
{
	OSCBundle send_bndl;  		// Declare bundles to hold incoming and outgoing data

	measure_sensors();					// Read sensors, store data in sensor state struct
	package_data(&send_bndl);			// Copy sensor data from state to provided bundle
	

	int analog0 = state_analog.a0;    	// directly access analog state struct
	int analog4 = read_analog(4);		// read analog 4 as you would if not integrated into Loom 
											// (you should just enable A4 in the config though)
	float f     = 4.56;
	char* c_str = "test";
	String str  = String("test2");

	append_to_bundle_key_value(&send_bndl, "analog0", analog0);
	append_to_bundle_key_value(&send_bndl, "analog4", analog4);
	append_to_bundle_key_value(&send_bndl, "float", f);
	append_to_bundle_key_value(&send_bndl, "c-str", c_str);
	append_to_bundle_key_value(&send_bndl, "String", str);


	print_bundle(&send_bndl);

	additional_loop_checks();			// Miscellaneous checks
	// --- End Example ---



	// // --- LoRa Hub Example ---
	// OSCBundle bndl;  		// Declare bundles to hold incoming and outgoing data

	// receive_bundle(&bndl, LORA);		// Read sensors, store data in sensor state struct
	// print_bundle(&bndl);
	// log_bundle(&bndl, PUSHINGBOX);

	// additional_loop_checks();			// Miscellaneous checks
	// // --- End Example ---



	// // --- LoRa Node Example ---
	// OSCBundle bndl, send_bndl;  		// Declare bundles to hold incoming and outgoing data

	// measure_sensors();					// Read sensors, store data in sensor state struct
	// package_data(&send_bndl);			// Copy sensor data from state to provided bundle
	
	// print_bundle(&send_bndl);

	// log_bundle(&send_bndl, SDCARD, "savefile.csv");
	// send_bundle(&send_bndl, LORA);

	// delay(1000);

	// additional_loop_checks();			// Miscellaneous checks
	// // --- End Example ---



	// // --- Common Example ---
	// OSCBundle bndl, send_bndl;  		// Declare bundles to hold incoming and outgoing data

	// receive_bundle(&bndl, WIFI);		// Receive messages
	// if (bndl.size()) {
	// 	print_bundle(&bndl);			// Print bundle if LOOM_DEBUG enabled
	// }
	// process_bundle(&bndl);				// Dispatch message to correct handling functions

	// measure_sensors();					// Read sensors, store data in sensor state struct
	// package_data(&send_bndl);			// Copy sensor data from state to provided bundle
	
	// send_bundle(&send_bndl, WIFI);		// Send bundle of packaged data
	// log_bundle(&send_bndl, PUSHINGBOX);	// Send bundle to Google Sheet

	// additional_loop_checks();			// Miscellaneous checks
	// // --- End Example ---
}


// ================================================================ 
// ===                 High-Level API Functions                 === 
// ================================================================ 

// void receive_bundle(OSCBundle *bndl, CommPlatform platform);
// void process_bundle(OSCBundle *bndl);
// void measure_sensors();
// void package_data(OSCBundle *send_bndl);
// void send_bundle(OSCBundle *send_bndl, CommPlatform platform, int port);
// void send_bundle(OSCBundle *send_bndl, CommPlatform platform);
// void log_bundle(OSCBundle *send_bndl, LogPlatform platform, char* file); // filename required for SD files
// void log_bundle(OSCBundle *send_bndl, LogPlatform platform);
// bool bundle_empty(OSCBundle *bndl);
// void additional_loop_checks();
// void sleep_for(int amount, TimeUnits units, SleepMode mode);
// void sleep_until_time(SleepMode mode, int hour, int min, int sec);

// CommPlatforms: WIFI, LORA, NRF
// LogPlatforms:  PUSHINGBOX, SDCARD, OLED
// TimeUnits: MINUTES, SECONDS
// SleepMode: STANDBY, SLEEPYDOG
