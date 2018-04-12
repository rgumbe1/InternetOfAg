#define FAMILY "LOOM"     // Should always be "LOOM", you can change this if you are setting up your own network
#define DEVICE "Ishield"  // The device name, should begin with a slash followed by an unbroken string with no more slashes i.e. "RelayShield" or "IShield"
#define INIT_INST 2


//--OPTIONS--//
#define DEBUG 1   // Set to 1 if you want Serial statements from various functions to print

#define is_ishield
#define num_servos 0
//#define is_relay
#define is_wifi
//#define is_lora
#define is_analog 2


 

#ifdef is_wifi
	#define DEFAULT_MODE      WPA_CLIENT_MODE //AP_MODE, WPA_CLIENT_MODE or WEP_CLIENT_MODE
	#define DEFAULT_NETWORK   "OPEnS"
	#define DEFAULT_PASSWORD  "Replace_with_your_wifi_password"
	#define INIT_PORT 9422
#endif



// LoRa Device Type
// 0: Hub, 1: Node, 2 = Repeater
#define lora_device_type 0

#ifdef is_lora
  #define SERVER_ADDRESS 0					//Use 0-9 for SERVER_ADDRESSes
  #define RF95_FREQ 915.0           //Hardware specific, Tx must match Rx
  
  #if lora_device_type == 1
    #define CLIENT_ADDRESS 10       //10 CLIENT_ADDRESSes belong to each SERVER_ADDRESS, 
  #endif														//10-19 for 0, 20 - 29 for 1, etc.
  
  #if lora_device_type == 0
    #define NUM_FIELDS 16			      //Maximum number of fields accepted by the PushingBox Scenario
  #endif
#endif



#ifdef is_ishield
  #define is_neopixel       // Toggle based on whether Neopixels are being used

  #define is_mpu6050
  #define is_i2c 0x86       // For MPU6050

  #ifdef is_neopixel
    #define NEO_0 false
    #define NEO_1 false
    #define NEO_2 true
  #endif  

#endif



//#define is_sleep_period 50          // Uncomment to use SleepyDog to transmit at intervals up to 16s and sleep in between. Change the value according to the length of your desired transmission interval
//#define is_sleep_interrupt 11       // Uncomment to use Low-Power library to sit in idle sleep until woken by pin interrupt, parameter is pin to interrupt




