// ================================================================
// ===              INCLUDE CONFIGURATION FILE                  ===
// ===    INCLUDE DECLARATIONS, STRUCTS, AND FUNCTIONS FROM     ===
// ===            OTHER FILES AS SET IN CONFIG.H                ===
// ================================================================

// Config has to be first has it hold all user specified options
#include "config.h"

// Preamble includes any relevant subroutine files based on options
// specified in the above config
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
	OSCBundle bndl, send_bndl; 

	// Receive bundles, takes bundle to be filled and wireless platforms [WIFI, LORA, NRF]
	receive_bundle(&bndl, WIFI);


//
//	// Single to multi test
//	if (get_bundle_bytes(&bndl)) {
//		LOOM_DEBUG_Println("Got a bundle");
//		convert_OSC_singleMsg_to_multiMsg(&bndl, &send_bndl);
//
//		bndl.send(Serial);
//		Serial.println();
//		send_bndl.send(Serial);
//		Serial.println();
//
//		LOOM_DEBUG_Println("\nOUT OLD");
//		print_bundle(&bndl);
//		LOOM_DEBUG_Println("\nOUT NEW");
//		print_bundle(&send_bndl);
//		
//		while(1);
//	}


	// Multi to single test
//	if (get_bundle_bytes(&bndl)) {
//		LOOM_DEBUG_Println("Got a bundle");
//		convert_OSC_multiMsg_to_singleMsg(&bndl, &send_bndl);
//
//		bndl.send(Serial);
//		Serial.println();
//		send_bndl.send(Serial);
//		Serial.println();
//
//		LOOM_DEBUG_Println("\nOUT OLD");
//		print_bundle(&bndl);
//		LOOM_DEBUG_Println("\nOUT NEW");
//		print_bundle(&send_bndl);
//		
//		while(1);
//	}

//	// Bundle to key_value array test
//	if (get_bundle_bytes(&bndl)) {
//		LOOM_DEBUG_Println("Got a bundle");
//		String key_values[20];
//		convert_OSC_to_array_key_value(&bndl, key_values);
//
//		for (int i = 0; i < 20; i++) {
//			LOOM_DEBUG_Print("i=");
//			LOOM_DEBUG_Print(i);
//			LOOM_DEBUG_Println2(": ", key_values[i]); 
//		}
//		
//		while(1);
//	}


	// Bundle to key_value array test
	if (get_bundle_bytes(&bndl)) {
		LOOM_DEBUG_Println("Got a bundle");
		String keys[10], values[10];
		convert_OSC_to_arrays_assoc(&bndl, keys, values);

		for (int i = 0; i < 10; i++) {
			LOOM_DEBUG_Print("i=");
			LOOM_DEBUG_Print(i);
			LOOM_DEBUG_Print(": ");
			LOOM_DEBUG_Print(keys[i]);
			LOOM_DEBUG_Print(", ");
			LOOM_DEBUG_Println(values[i]);
		}
		
		while(1);
	}

	// Process bundle (nothing will happen if bndl is empty), bundle is emptied after processing
//	process_bundle(&bndl);

	// Update stored readings from sensors
//	measure_sensors();

	// Populate bundle to send with sensor values
//	package_data(&send_bndl);

	// Send the bundle, takes bundle to be filled and platform to send it over [WIFI, LORA, NRF, SDCARD, PUSHINGBOX]
//	send_bundle(&send_bndl, PUSHINGBOX);
//
//	if (get_bundle_bytes(&bndl)){
//		send_bundle(&bndl, SDCARD, "test2.txt");
//		read_all_from_file("test2.txt");
////		while(1);
//	}
	
	// Loop checks and sleep between iterations if enabled
	additional_loop_checks();
	
} // End loop section




















































