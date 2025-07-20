/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           MY_DNS2              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/

// -- MQTT - Domoticz -----------------------------
#undef  USE_DOMOTICZ                           // Enable Domoticz (+6k code, +0.3k mem)

// -- Wireguard VPN support ------------------------
// VPN support since v14.6.1
#undef  USE_UFILESYS
#undef  USE_WIREGUARD                            // Enable Wireguard VPN support (ESP8266: +28k code +0.9k mem, ESP32: +22k code +0.9k mem)

// -- Telegram Protocol ---------------------------
//#define USE_TELEGRAM                             // Support for Telegram protocol (+49k code, +7.0k mem and +4.8k additional during connection handshake)
  #define USE_TELEGRAM_FINGERPRINT "\x4E\x7F\xF5\x6D\x1E\x29\x40\x58\xAB\x84\xDE\x63\x69\x7B\xCD\xDF\x44\x2E\xD2\xF6" // Telegram api.telegram.org TLS public key fingerpring

// -- KNX IP Protocol -----------------------------
#undef  USE_KNX                                  // Enable KNX IP Protocol Support (+9.4k code, +3k7 mem)
  #undef  USE_KNX_WEB_MENU                       // Enable KNX WEB MENU (+8.3k code, +144 mem)

// -- Telnet --------------------------------------
#define USE_TELNET                             // Add support for telnet (+2k code)
  #define TELNET_BUF_SIZE        256             // [TelnetBuffer] Size of input buffer (default 256)
  #define TELNET_START           1               // [Telnet] Start telnet on network connection (default 0 - No start)
  #define TELNET_PORT            23              // [Telnet] Telnet port (default 23)
//  #define TELNET_COL_DISABLE     1               // [TelnetColor] Disable colors (default 0 - Enable colors)
  #define TELNET_COL_PROMPT      33              // [TelnetColor] ANSI color escape code (default 33 - Yellow)
  #define TELNET_COL_RESPONSE    32              // [TelnetColor] ANSI color escape code (default 32 - Green)
  #define TELNET_COL_LOGGING     36              // [TelnetColor] ANSI color escape code (default 36 - Cyan)

#define USE_WEB_STATUS_LINE_WIFI               // Enable upper left wifi indicator in main page (+0k5 code)
#define USE_WEB_STATUS_LINE_HEAP               // Enable upper left display of free heap memory (+0k1 code)
#define USE_WEBSEND_RESPONSE                   // Enable command WebSend response message (+1k code)
#define USE_WEBGETCONFIG                       // Enable restoring config from external webserver (+0k6)
#define USE_WEBRUN                             // Enable executing a tasmota command file from external web server (+0.4 code)
#define USE_GPIO_VIEWER                        // Enable GPIO Viewer to see realtime GPIO states (+6k code)
#undef  USE_EMULATION_HUE                      // Enable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
#undef  USE_EMULATION_WEMO                     // Enable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)

// -- Ping ----------------------------------------
#define USE_PING                                 // Enable Ping command (+2k code)

/*
// -- Time ----------------------------------------
#define USE_TIMERS                               // Add support for up to 16 timers (+2k2 code)
  #define USE_TIMERS_WEB                         // Add timer webpage support (+4k5 code)
  #define USE_SUNRISE                            // Add support for Sunrise and sunset tools (+16k)
    #define SUNRISE_DAWN_ANGLE DAWN_NORMAL       // Select desired Dawn Angle from (DAWN_NORMAL, DAWN_CIVIL, DAWN_NAUTIC, DAWN_ASTRONOMIC)

// -- Compression ---------------------------------
#define USE_UNISHOX_COMPRESSION                  // Add support for string compression in Rules or Scripts

// -- Rules or Script  ----------------------------
// Select none or only one of the below defines USE_RULES or USE_SCRIPT
#define USE_RULES                                // Add support for rules (+13k code, +768 bytes mem)
  #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+1k8 code)
  #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+1k7 code)
    #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+2k7)
//  #define USER_RULE1 "<Any rule1 data>"          // Add rule1 data saved at initial firmware load or when command reset is executed
//  #define USER_RULE2 "<Any rule2 data>"          // Add rule2 data saved at initial firmware load or when command reset is executed
//  #define USER_RULE3 "<Any rule3 data>"          // Add rule3 data saved at initial firmware load or when command reset is executed

//#define USE_SCRIPT                               // Add support for script (+36k code, +1k mem)
//  #define USE_SCRIPT_FATFS 4                     // Script: Add FAT FileSystem Support
//  #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+3k5 code)

//#define USER_BACKLOG "<Any command separated by a semicolon (;)>"  // Add commands executed at firmware load or when command reset is executed
*/

// -- Optional modules ----------------------------
#undef  ROTARY_V1                                // Add support for Rotary Encoder as used in MI Desk Lamp (+0k8 code)
#undef  USE_SONOFF_RF                            // Add support for Sonoff Rf Bridge (+3k2 code)
  #undef  USE_RF_FLASH                           // Add support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB (+2k7 code)
#undef  USE_SONOFF_SC                            // Add support for Sonoff Sc (+1k1 code)
#undef  USE_TUYA_MCU                             // Add support for Tuya Serial MCU
#undef  USE_ARMTRONIX_DIMMERS                    // Add support for Armtronix Dimmers (+1k4 code)
#undef  USE_PS_16_DZ                             // Add support for PS-16-DZ Dimmer (+2k code)
#undef  USE_SONOFF_IFAN                          // Add support for Sonoff iFan02 and iFan03 (+2k code)
// #define USE_BUZZER                               // Add support for a buzzer (+0k6 code)
#undef  USE_ARILUX_RF                            // Add support for Arilux RF remote controller (+0k8 code, 252 iram (non 2.3.0))
#undef  USE_SHUTTER                              // Add Shutter support for up to 4 shutter with different motortypes (+11k code)
#undef  USE_EXS_DIMMER                           // Add support for ES-Store Wi-Fi Dimmer (+1k5 code)
//  #define EXS_MCU_CMNDS                          // Add command to send MCU commands (+0k8 code)
//#define USE_HOTPLUG                              // Add support for sensor HotPlug
#undef  USE_DEVICE_GROUPS                        // Add support for device groups (+5k5 code)
  #undef  USE_DEVICE_GROUPS_SEND                 // Add support for the DevGroupSend command (+0k6 code)
#undef  USE_PWM_DIMMER                           // Add support for MJ-SD01/acenx/NTONPOWER PWM dimmers (+2k3 code, DGR=0k7)
  #undef  USE_PWM_DIMMER_REMOTE                  // Add support for remote switches to PWM Dimmer (requires USE_DEVICE_GROUPS) (+0k6 code)
#undef  USE_SONOFF_D1                            // Add support for Sonoff D1 Dimmer (+0k7 code)
#undef  USE_SHELLY_DIMMER                        // Add support for Shelly Dimmer (+3k code)
  #undef  SHELLY_CMDS                            // Add command to send co-processor commands (+0k3 code)
  #undef  SHELLY_FW_UPGRADE                      // Add firmware upgrade option for co-processor (+3k4 code)
//  #define SHELLY_VOLTAGE_MON                     // Add support for reading voltage and current measurment (-0k0 code)
//#define USE_MAGIC_SWITCH                         // Add Sonoff MagicSwitch support as implemented in Sonoff Basic R4 (+612B flash, +64B IRAM for intr)
//  #define MAGICSWITCH_MIN_PULSE  4000            // Overridable minimum pulse, also overridable by command MagicSwitchPulse (not saved to flash)
//  #define MAGICSWITCH_MASKING_WINDOW_LEN  5      // Overridable masking window (in number of 50ms loops)

// -- Optional light modules ----------------------
#undef  USE_LIGHT                                // Add support for light control
#undef  USE_MY92X1                               // Add support for MY92X1 RGBCW led controller as used in Sonoff B1, Ailight and Lohas
#undef  USE_SM16716                              // Add support for SM16716 RGB LED controller (+0k7 code)
#undef  USE_SM2135                               // Add support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
#undef  USE_SM2335                               // Add support for SM2335 RGBCW led control as used in SwitchBot Color Bulb (+0k7 code)
#undef  USE_BP1658CJ                             // Add support for BP1658CJ RGBCW led control as used in Orein OS0100411267 Bulb
#undef  USE_BP5758D                              // Add support for BP5758D RGBCW led control as used in some Tuya lightbulbs (+0k8 code)
#undef  USE_SONOFF_L1                            // Add support for Sonoff L1 led control
#undef  USE_ELECTRIQ_MOODL                       // Add support for ElectriQ iQ-wifiMOODL RGBW LED controller (+0k3 code)
#undef  USE_LIGHT_PALETTE                        // Add support for color palette (+0k7 code)
#undef  USE_LIGHT_VIRTUAL_CT                     // Add support for Virtual White Color Temperature (+1.1k code)
#undef  USE_DGR_LIGHT_SEQUENCE                   // Add support for device group light sequencing (requires USE_DEVICE_GROUPS) (+0k2 code)
//#define USE_LSC_MCSL                             // Add support for GPE Multi color smart light as sold by Action in the Netherlands (+1k1 code)

// -- Optional adressable leds ----------------------
#undef  USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
// #define USE_LIGHT_ARTNET                         // Add support for DMX/ArtNet via UDP on port 6454 (+3.5k code)

// -- Counter input -------------------------------
// #define USE_COUNTER                              // Enable inputs as counter (+0k8 code)

// -- Internal Analog input -----------------------
#define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices

// -- One wire sensors ----------------------------
#undef  USE_DS18x20                              // Add support for DS18x20 sensors with id sort, single scan and read retry (+2k6 code)
//  #define W1_PARASITE_POWER                      // Optimize for parasite powered sensors
//  #define DS18x20_USE_ID_AS_NAME                 // Use last 3 bytes for naming of sensors
//  #define DS18x20_USE_ID_ALIAS                   // Add support aliasing for DS18x20 sensors. See comments in xsns_05 files (+0k5 code)

// -- I2C sensors ---------------------------------
#undef  USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)
#define I2CDRIVERS_0_31        0xFFFFFFFF          // Enable I2CDriver0  to I2CDriver31
#define I2CDRIVERS_32_63       0xFFFFFFFF          // Enable I2CDriver32 to I2CDriver63
#define I2CDRIVERS_64_95       0xFFFFFFFF          // Enable I2CDriver64 to I2CDriver95

#ifdef USE_I2C
//  #define USE_I2C_BUS2                           // Add experimental support for second I2C bus on ESP8266 (+0k6k code)
//  #define USE_SHT                                // [I2cDriver8] Enable SHT1X sensor (+1k4 code)
//  #define USE_HTU                                // [I2cDriver9] Enable HTU21/SI7013/SI7020/SI7021 sensor (I2C address 0x40) (+1k5 code)
//  #define USE_BMP                                // [I2cDriver10] Enable BMP085/BMP180/BMP280/BME280 sensors (I2C addresses 0x76 and 0x77) (+4k4 code)
//    #define USE_BME68X                           // Enable support for BME680/BME688 sensor using Bosch BME68x library (+6k9 code)
  #undef  USE_BH1750                             // [I2cDriver11] Enable BH1750 sensor (I2C address 0x23 or 0x5C) (+0k5 code)
//  #define USE_ADS1115                            // [I2cDriver13] Enable ADS1115 16 bit A/D converter (I2C address 0x48, 0x49, 0x4A or 0x4B) based on Adafruit ADS1x15 library (no library needed) (+0k7 code)
  #undef  USE_ADE7953                            // [I2cDriver7] Enable ADE7953 Energy monitor as used on Shelly 2.5 (I2C address 0x38) (+1k5)
//  #define USE_DHT12                              // [I2cDriver41] Enable DHT12 humidity and temperature sensor (I2C address 0x5C) (+0k7 code)
//  #define USE_DS1624                             // [I2cDriver42] Enable DS1624, DS1621 temperature sensor (I2C addresses 0x48 - 0x4F) (+1k2 code)
//  #define USE_AHT1x                              // [I2cDriver43] Enable AHT10/15 humidity and temperature sensor (I2C address 0x38, 0x39) (+0k8 code)
//  #define USE_AHT2x                              // [I2cDriver43] Enable AHT20/AM2301B instead of AHT1x humidity and temperature sensor (I2C address 0x38) (+0k8 code)
//  #define USE_HDC1080                            // [I2cDriver45] Enable HDC1080 temperature/humidity sensor (I2C address 0x40) (+1k5 code)

//  #define USE_RTC_CHIPS                          // Enable RTC chip support and NTP server - Select only one
//    #define USE_DS3231                           // [I2cDriver26] Enable DS3231 RTC - used by Ulanzi TC001 (I2C address 0x68) (+1k2 code)
//    #define DS3231_ENABLE_TEMP                   //   In DS3231 driver, enable the internal temperature sensor
//    #define USE_BM8563                           // [I2cDriver59] Enable BM8563 RTC - used by M5Stack - support both I2C buses on ESP32 (I2C address 0x51) (+2.5k code)
//    #define USE_PCF85363                         // [I2cDriver66] Enable PCF85363 RTC - used by Shelly 3EM (I2C address 0x51) (+0k7 code)
//    #define USE_RX8010                           // [I2cDriver90] Enable RX8010 RTC - used by IOTTIMER - support both I2C buses on ESP32 (I2C address 0x32) (+0k7 code)
//    #define USE_PCF85063                         // [I2cDriver92] Enable PCF85063 RTC support (I2C address 0x51)

  #undef  USE_DISPLAY                            // Add I2C/TM1637/MAX7219 Display Support (+2k code)
//    #define USE_DISPLAY_MODES1TO5                // Enable display mode 1 to 5 in addition to mode 0
    // #define USE_DISPLAY_LCD                      // [DisplayModel 1] [I2cDriver3] Enable Lcd display (I2C addresses 0x27 and 0x3F) (+6k code)
    // REMOVED - #define USE_DISPLAY_SSD1306                  // [DisplayModel 2] [I2cDriver4] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
    #undef  USE_DISPLAY_MATRIX                   // [DisplayModel 3] [I2cDriver5] Enable 8x8 Matrix display (I2C adresseses see below) (+11k code)
    #undef  USE_DISPLAY_SEVENSEG                 // [DisplayModel 11] [I2cDriver47] Enable sevenseg display (I2C 0x70-0x77) (<+11k code)
//      #define USE_DISPLAY_SEVENSEG_COMMON_ANODE  // Enable support for common anode sevenseg displays
                                                 // Multiple sevenseg displays are logically arranged vertically with MTX_ADDRESS1 at y=0,
                                                 // MTX_ADDRESS2 at y=1, up to MTX_ADDRESS8 at y=7
                                                 // Command: DisplayText [yn]8888
                                                 // will display 8888 at sevenseg display at I2C address MTX_ADDRESS(n-1)
                                                 // Each segment may be address Command: DisplayText [xn]m
                                                 //  where n is 0..4 (4 digits and middle :) and m is decimal for bitmap of which segment to turn on.
                                                 // Reference: https://cdn-learn.adafruit.com/downloads/pdf/adafruit-led-backpack.pdf
//      #define SEVENSEG_ADDRESS1     0x70         // No longer used.  Use MTX_ADDRESS1 - MTX_ADDRESS8 instead to specify I2C address of sevenseg displays
    #undef  USE_DISPLAY_SH1106                   // [DisplayModel 7] [I2cDriver6] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
    #undef  USE_DISPLAY_TM1650                   // [DisplayModel 20] [I2cDriver74] Enable TM1650 display (I2C addresses 0x24 - 0x27 and 0x34 - 0x37)
    #undef  USE_DT_VARS                          // Display variables that are exposed in JSON MQTT strings e.g. in TelePeriod messages.
//    #define MAX_DT_VARS     16                   // Defaults to 7
//    #define USE_GRAPH                            // Enable line charts with displays
//    #define NUM_GRAPHS     4                     // Max 16

#endif  // USE_I2C

//#define USE_DISPLAY                              // Add I2C/TM1637/MAX7219 Display Support (+2k code)
//  #define USE_DISPLAY_TM1637                     // [DisplayModel 15] Enable TM1637 Seven Segment Display Module (4-6 digits)
//  #define USE_DISPLAY_MAX7219                    // [DisplayModel 15] Enable MAX7219 Seven Segment Display Module (8 digits)
//  #define USE_DISPLAY_MAX7219_MATRIX             // [DisplayModel 19] Enable MAX7219 8x8 Matrix Display
//  #define USE_DISPLAY_TM1640                     // [DisplayModel 13] Enable TM1640 module  Seven Segment Display Module (stub)
//    #define USE_IOTTIMER                         // Enable TM1640 based IotTimer

// -- Universal Display Driver ---------------------------------
#undef  USE_UNIVERSAL_DISPLAY                   // New universal display driver for both I2C and SPI
    #undef  MAX_TOUCH_BUTTONS 16                 // Virtual touch buttons

// -- SPI sensors ---------------------------------
#undef  USE_SPI                                  // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)

#ifdef USE_SPI
//  #define USE_NRF24                              // Add SPI support for NRF24L01(+) (+2k6 code)
    #undef  USE_MIBLE                            // BLE-bridge for some Mijia-BLE-sensors (+4k7 code)
//  #define USE_DISPLAY                            // Add SPI Display support for 320x240 and 480x320 TFT
    // REMOVED -- #define USE_DISPLAY_ILI9341                  // [DisplayModel 4] Enable ILI9341 Tft 480x320 display (+19k code)
//    #define USE_DISPLAY_EPAPER_29                // [DisplayModel 5] Enable e-paper 2.9 inch display (+19k code)
//    #define USE_DISPLAY_EPAPER_42                // [DisplayModel 6] Enable e-paper 4.2 inch display
    // REMOVED -- #define USE_DISPLAY_SSD1351                  // [DisplayModel 9] Enable SSD1351 module
//    #define USE_DISPLAY_RA8876                   // [DisplayModel 10] [I2cDriver39] (Touch)
//    #define USE_DISPLAY_ST7789                   // [DisplayModel 12] Enable ST7789 module
    // REMOVED -- #define USE_DISPLAY_SSD1331                  // [DisplayModel 14] Enable SSD1331 module
//  #define USE_SPI_LORA                           // Add support for LoRaSend and LoRaCommand (+4k code)
//    #define USE_LORA_SX126X                      // Add driver support for LoRa on SX126x based devices like LiliGo T3S3 Lora32 (+16k code)
//    #define USE_LORA_SX127X                      // Add driver support for LoRa on SX127x based devices like M5Stack LoRa868, RFM95W (+5k code)
//    #define USE_LORAWAN_BRIDGE                   // Add support for LoRaWan bridge (+8k code)

#endif  // USE_SPI

// -- One wire sensors ----------------------------
// #define USE_HDMI_CEC                              // Add support for HDMI CEC bus (+7k code, 1456 bytes IRAM)

// -- Serial sensors ------------------------------
// #define USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+2k code)
//  #define SERIAL_BRIDGE_BUFFER_SIZE 256          // Serial Bridge receive buffer size (Default ESP8266 = 256, ESP32 = 800)
// #define USE_MODBUS_BRIDGE                        // Add support for software Modbus Bridge (+4.5k code)
// #define USE_MODBUS_BRIDGE_TCP                    // Add support for software Modbus TCP Bridge (also enable Modbus TCP Bridge) (+2k code)
// #define MODBUS_BRIDGE_TCP_DEFAULT_PORT 502       // Add support for software Modbus TCP Bridge (start the TCP bridge automatically at PORT 502)
#define USE_TCP_BRIDGE                           //  Add support for Serial to TCP bridge (+1.3k code)

//#define USE_OPENTHERM                            // Add support for OpenTherm (+15k code)
//#define USE_LD2402                               // Add support for HLK-LD2402 24GHz human presence sensor module (+10k9 code, 320 RAM)
#undef  USE_LD2410                               // Add support for HLK-LD2410 24GHz smart wave motion sensor (+3k7 code, 88 RAM)
//#define USE_LD2410S                              // Add support for HLK-LD2410S Ultra Low-power 24GHz smart wave motion sensor (+4k7 code, 144 RAM)

// -- Power monitoring sensors --------------------
#undef  USE_ENERGY_SENSOR                        // Add support for Energy Monitors (+14k code)
#undef  USE_ENERGY_MARGIN_DETECTION              // Add support for Energy Margin detection (+1k6 code)
#undef  USE_ENERGY_DUMMY                         // Add support for dummy Energy monitor allowing user values (+0k7 code)
#undef  USE_HLW8012                              // Add support for HLW8012, BL0937 or HJL-01 Energy Monitor for Sonoff Pow and WolfBlitz
#undef  USE_CSE7766                              // Add support for CSE7766 Energy Monitor for Sonoff S31 and Pow R2
#undef  USE_PZEM004T                             // Add support for PZEM004T Energy monitor (+2k code)
#undef  USE_PZEM_AC                              // Add support for PZEM014,016 Energy monitor (+1k1 code)
#undef  USE_PZEM_DC                              // Add support for PZEM003,017 Energy monitor (+1k1 code)
#undef  USE_MCP39F501                            // Add support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)

// -- Low level interface devices -----------------
#undef  USE_DHT                                  // Add support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor (1k6 code)

// -- IR Remote features - all protocols from IRremoteESP8266 --------------------------
// IR Full Protocols mode is now activated through USE_IR_REMOTE_FULL
//
// Code impact of IR full protocols is +90k code, 3k mem

// -- IR Remote features - subset of IR protocols --------------------------
#undef  USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 (+4k3 code, 0k3 mem, 48 iram)
//  #define IR_SEND_INVERTED          false        // Invert the output. (default = false) e.g. LED is illuminated when GPIO is LOW rather than HIGH.
                                                 // Setting inverted to something other than the default could easily destroy your IR LED if you are overdriving it.
                                                 // Unless you REALLY know what you are doing, don't change this.
//  #define IR_SEND_USE_MODULATION    true         // Do we do frequency modulation during transmission? i.e. If not, assume a 100% duty cycle.

  // ====> IR Full protocols are enabled with the line below
  // #define USE_IR_REMOTE_FULL                     // Support all IR protocols from IRremoteESP8266
  //
  // WARNING: if you change any IR configuration, you need to clear Platform.io cache
  //          currently the include change detection does not work for these parameters
  //          This is not an issue if you compile with gitpod or pre-compiled binaries
  //          since there is no cache of previously compiled libraries
  // ====>
  //
  // You can also disable specific protocols in user_config_override
  // Example: disable some HVAC protocols to reduce flash size
  // #define DECODE_WHIRLPOOL_AC  false
  // #define SEND_WHIRLPOOL_AC    false
  // #define DECODE_SAMSUNG_AC    false
  // #define SEND_SAMSUNG_AC      false
  // ...

  // When using 'USE_IR_REMOTE_FULL', parameters below
  // (USE_IR_REMOTE, USE_IR_RECEIVE, USE_IR_HVAC...) are IGNORED.
  #undef  DECODE_ELECTRA_AC true
  #undef  SEND_ELECTRA_AC   true
  /*
  #define USE_IR_SEND_NEC                        // Support IRsend NEC protocol
  #define USE_IR_SEND_RC5                        // Support IRsend Philips RC5 protocol
  #define USE_IR_SEND_RC6                        // Support IRsend Philips RC6 protocol

  // Enable IR devoder via GPIO `IR Recv` - always enabled if `USE_IR_REMOTE_FULL`
  #define USE_IR_RECEIVE                         // Support for IR receiver (+7k2 code, 264 iram)
    #define IR_RCV_BUFFER_SIZE      100          // Max number of packets allowed in capture buffer (default 100 (*2 bytes ram))
    #define IR_RCV_TIMEOUT          15           // Number of milli-Seconds of no-more-data before we consider a message ended (default 15)
    #define IR_RCV_MIN_UNKNOWN_SIZE 6            // Set the smallest sized "UNKNOWN" message packets we actually care about (default 6, max 255)
    #define IR_RCV_WHILE_SENDING    0            // Turns on receiver while sending messages, i.e. receive your own. This is unreliable and can cause IR timing issues
    #define IR_RCV_TOLERANCE        25           // Base tolerance percentage for matching incoming IR messages (default 25, max 100)
  */

// -- SD Card support -----------------------------
// #define USE_SDCARD                               // mount SD Card, requires configured SPI pins and setting of `SDCard CS` gpio
//  #define SDC_HIDE_INVISIBLES                    // hide hidden directories from the SD Card, which prevents crashes when dealing SD created on MacOS

// -- Other sensors/drivers -----------------------

#undef  USE_SHIFT595                             // Add support for 74xx595 8-bit shift registers (+0k7 code)
//  #define SHIFT595_INVERT_OUTPUTS false            // [SetOption133] Don't invert outputs of 74x595 shift register
//  #define SHIFT595_DEVICE_COUNT  1                 // [Shift595DeviceCount] Set the number of connected 74x595 shift registers

//#define USE_TM1638                               // Add support for TM1638 switches copying Switch1 .. Switch8 (+1k code)
//  #define TM1638_USE_AS_BUTTON                   // Add support for buttons
//  #define TM1638_USE_AS_SWITCH                   // Add support for switches (default)
//  #define TM1638_MAX_DISPLAYS    8               // Add support for power control 8 displays
//  #define TM1638_MAX_KEYS        8               // Add support for 8 keys
//  #define TM1638_MAX_LEDS        8               // Add support for 8 leds
//#define USE_HX711                                // Add support for HX711 load cell (+1k5 code)
//  #define USE_HX711_M5SCALES                     // [I2cDriver89] Enable support for M5Unit (Mini)Scales (I2C address 0x26) (+0k4 code)
//  #define USE_HX711_GUI                          // Add optional web GUI to HX711 as scale (+1k8 code)
//  #define HX711_CAL_PRECISION     1              // When HX711 calibration is to course, raise this value

#define USE_RC_SWITCH                            // Add support for RF transceiver using library RcSwitch (+2k7 code, 460 iram)

#define USE_RF_SENSOR                            // Add support for RF sensor receiver (434MHz or 868MHz) (+0k8 code)
//  #define USE_THEO_V2                            // Add support for decoding Theo V2 sensors as documented on https://sidweb.nl using 434MHz RF sensor receiver (+1k4 code)
//  #define USE_ALECTO_V2                          // Add support for decoding Alecto V2 sensors like ACH2010, WS3000 and DKW2012 weather stations using 868MHz RF sensor receiver (+1k7 code)

//#define USE_PROMETHEUS                           // Add support for https://prometheus.io/ metrics exporting over HTTP /metrics endpoint

// -- PID and Timeprop ------------------------------ // Both together will add +12k1 code
// #define USE_TIMEPROP                            // Add support for the timeprop feature (+9k1 code)
                                                   // For details on the configuration please see the header of tasmota/xdrv_48_timeprop.ino
// #define USE_PID                                 // Add suport for the PID  feature (+11k2 code)
                                                   // For details on the configuration please see the header of tasmota/xdrv_49_pid.ino
// -- End of general directives ---------------------

/*********************************************************************************************\
 * ESP32 only features
\*********************************************************************************************/

#ifdef ESP32

#define USE_ESP32_WDT                            // Enable Watchdog for ESP32, trigger a restart if loop has not responded for 5s, and if `yield();` was not called

#define SET_ESP32_STACK_SIZE  (8 * 1024)         // Set the stack size for Tasmota. The default value is 8192 for Arduino, some builds might need to increase it

#undef  USE_NETWORK_LIGHT_SCHEMES                // Add support for light schemes via DDP (via UDP on port 4048)

//#define USE_SPI                                  // Add support for hardware SPI
#define USE_MI_ESP32                             // Add support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)
#define USE_BLE_ESP32                            // Add support for ESP32 as a BLE-bridge (+9k2? mem, +292k? flash)
  //#define BLE_ESP32_ENABLE false                 // [SetOption115] Default value for SetOption115
  //#define USE_IBEACON                            // Add support for Bluetooth LE passive scan of iBeacon devices (uses HM17 module)
  //#define USE_IBEACON_ESP32                      // Add support for Bluetooth LE passive scan of iBeacon devices using the internal ESP32 Bluetooth module
//#define USE_WEBCAM                               // Add support for webcam

//#define USE_AUTOCONF                             // Enable Esp32 autoconf feature, requires USE_BERRY and USE_WEBCLIENT_HTTPS (12KB Flash)
//#define USE_BERRY                                // Enable Berry scripting language
  //#define USE_BERRY_PYTHON_COMPAT                // Enable by default `import python_compat`
  //#define USE_BERRY_TIMEOUT             4000     // Timeout in ms, will raise an exception if running time exceeds this timeout
  //#define USE_BERRY_PSRAM                        // Allocate Berry memory in PSRAM if PSRAM is connected - this might be slightly slower but leaves main memory intact
  //#define USE_BERRY_IRAM                         // Allocate some data structures in IRAM (which is usually unused) when possible and if no PSRAM is available
  //#define USE_BERRY_FAST_LOOP_SLEEP_MS  5        // Minimum time in milliseconds to before calling again `tasmota.fast_loop()`, a smaller value will consume more CPU (min 1ms)
  #define USE_BERRY_DEBUG                        // Compile Berry bytecode with line number information, makes exceptions easier to debug. Adds +8% of memory consumption for compiled code
  //   #define UBE_BERRY_DEBUG_GC                   // Print low-level GC metrics
  #define USE_BERRY_INT64                        // Add 64 bits integer support (+1.7KB Flash)
  //#define USE_WEBCLIENT_HTTPS                    // Enable HTTPS outgoing requests based on BearSSL (much ligher then mbedTLS, 42KB vs 150KB) in insecure mode (no verification of server's certificate)
                                                 // Note that only two ciphers are enabled: ECDHE_RSA_WITH_AES_128_GCM_SHA256, ECDHE_ECDSA_WITH_AES_128_GCM_SHA256
    //#define USE_BERRY_WEBCLIENT_USERAGENT  "TasmotaClient" // default user-agent used, can be changed with `wc.set_useragent()`
    //#define USE_BERRY_WEBCLIENT_TIMEOUT  2000    // Default timeout in milliseconds
    #undef  USE_BERRY_LEDS_PANEL                 // Add button to dynamically load the Leds Panel from a bec file online
    //#define USE_BERRY_LEDS_PANEL_URL             "http://ota.tasmota.com/tapp/leds_panel.bec"
    //#define USE_BERRY_LVGL_PANEL                 // Add button to dynamically load the LVGL Panel from a bec file online
    //#define USE_BERRY_LVGL_PANEL_URL             "http://ota.tasmota.com/tapp/lvgl_panel.bec"
    #define USE_BERRY_PARTITION_WIZARD           // Add a button to dynamically load the Partion Wizard from a bec file online (+1.3KB Flash)
    //#define USE_BERRY_PARTITION_WIZARD_URL      "http://ota.tasmota.com/tapp/partition_wizard.bec"
    #define USE_BERRY_GPIOVIEWER                 // Add a button to dynamocally load the GPIO Viewer from a bec file online
    //#define USE_BERRY_GPIOVIEWER_URL            "http://ota.tasmota.com/tapp/gpioviewer.bec"
  #define USE_BERRY_TCPSERVER                    // Enable TCP socket server (+0.6k)
  #define USE_BERRY_ULP                          // Enable ULP (Ultra Low Power) support (+4.9k)
  // Berry crypto extensions below:
  // #define USE_BERRY_CRYPTO_AES_GCM               // enable AES GCM 256 bits
  // #define USE_BERRY_CRYPTO_AES_CCM               // enable AES CCM 128 bits
  // #define USE_BERRY_CRYPTO_AES_CTR               // enable AES CTR 256 bits
  // #define USE_BERRY_CRYPTO_EC_P256               // enable EC P256r1
  // #define USE_BERRY_CRYPTO_EC_C25519             // enable Elliptic Curve C C25519
  // #define USE_BERRY_CRYPTO_SHA256                // enable SHA256 hash function
  // #define USE_BERRY_CRYPTO_HMAC_SHA256           // enable HMAC SHA256 hash function
  // #define USE_BERRY_CRYPTO_PBKDF2_HMAC_SHA256    // PBKDF2 with HMAC SHA256, used in Matter protocol
  // #define USE_BERRY_CRYPTO_HKDF_SHA256      // HKDF with HMAC SHA256, used in Matter protocol
  // #define USE_BERRY_CRYPTO_SPAKE2P_MATTER   // SPAKE2+ used in Matter 1.0, complete name is SPAKE2+-P256-SHA256-HKDF-SHA256-HMAC-SHA256
  // #define USE_BERRY_CRYPTO_RSA              // RSA primitives including JWT RS256 (3.9KB flash)
#define USE_CSE7761                              // Add support for CSE7761 Energy monitor as used in Sonoff Dual R3

// -- Matter protocol ---------------------------------
  // #define USE_MATTER_DEVICE                      // Enable Matter device support (+380KB)
                                                    // Enabled by default in standard ESP32 binary

#endif  // ESP32

/*********************************************************************************************\
 * Debug features
\*********************************************************************************************/

//#define DEBUG_TASMOTA_CORE                       // Enable core debug messages
//#define DEBUG_TASMOTA_DRIVER                     // Enable driver debug messages
//#define DEBUG_TASMOTA_SENSOR                     // Enable sensor debug messages
//#define USE_DEBUG_DRIVER                         // Use xdrv_99_debug.ino providing commands CpuChk, CfgXor, CfgDump, CfgPeek and CfgPoke

/*********************************************************************************************\
 * Profiling features
\*********************************************************************************************/

//#define USE_PROFILING                            // Enable profiling
//#define PROFILE_THRESHOLD            70          // Minimum duration in milliseconds to start logging
//#define USE_PROFILE_DRIVER                       // Enable driver profiling
//#define USE_PROFILE_FUNCTION                     // Enable driver function profiling

/*********************************************************************************************\
 * Optional firmware configurations
 * Select none or just one for optional features and sensors as configured in tasmota_configurations.h
 * See RELEASENOTES.md for selected features
\*********************************************************************************************/

//#define FIRMWARE_LITE                            // Create tasmota-lite with no sensors
//#define FIRMWARE_SENSORS                         // Create tasmota-sensors with useful sensors enabled
//#define FIRMWARE_KNX_NO_EMULATION                // Create tasmota-knx with KNX but without Emulation
//#define FIRMWARE_DISPLAYS                        // Create tasmota-display with display drivers enabled
//#define FIRMWARE_IR                              // Create tasmota-ir with IR full protocols activated, and many sensors disabled
//#define FIRMWARE_MINIMAL                         // Create tasmota-minimal as intermediate firmware for OTA-MAGIC

/*********************************************************************************************\
 * Safe guard when needed defines are not done in Platformio                                                         *
\*********************************************************************************************/

#ifndef OTA_URL
  #define OTA_URL ""
#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
