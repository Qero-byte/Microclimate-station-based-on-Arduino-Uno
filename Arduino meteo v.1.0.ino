
#include <Ethernet.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT_NEW.h"
#include <SFE_BMP180.h>
#include <OneWire.h>
#include <SD.h>
LiquidCrystal_I2C _lcd1(0x27, 20, 4);
int _dispTempLength1=0;
boolean _isNeedClearDisp1;

DHT _dht1;

SFE_BMP180  _bmp085; 
long _bmp085P = 0;


byte _d18x2x1Addr[8]={0x28, 0xC0, 0xFF, 0xE7, 0x3, 0x0, 0x0, 0x63};

File _sd1DF;
String _sd1TS;

struct UB_178889508
{
float ubo_166622895 = 0.00;
float _gtv1 = 133.322;
};
UB_178889508 UB_178889508_Instance1;
unsigned long UB_178889508_ubi_102491196 = 0UL;
OneWire  _ow2(2);
byte ethernet_mac [] = {0x78, 0xAC, 0xC0, 0xB9, 0x69, 0x9B};
IPAddress ethernet_ip(192, 168, 10, 142);
byte ethernet_dns [] = {192, 168, 10, 1};
byte ethernet_gateway [] = {188, 19, 65, 181};
byte ethernet_subnet [] = {255, 255, 255, 0};
EthernetServer _tspWebServer(80);
EthernetClient _tspWebServer_client;
struct _I2CRealRimeClockTime
{
 byte seconds = 0;
 byte minutes = 0;
 byte Hours = 0;
 byte weekday = 0;
 byte day = 0;
 byte month = 0;
 byte year = 0;
 unsigned long startTime = 0;
};
_I2CRealRimeClockTime _RTC1;
int _disp2oldLength = 0;
bool _sd1SVOS4 = 0;
unsigned long _dht1LRT = 0UL;
unsigned long _dht1Tti = 0UL;
bool _sd1SVOS2 = 0;
bool _WSP1_A1 = 0;
bool _count1I = 0;
int _count1_Value = 0;
String _RTC1_GetTime1_StrOut;
bool _sd1SVOS1 = 0;
bool _gen1I = 0;
bool _gen1O = 0;
unsigned long _gen1P = 0UL;
int _disp1oldLength = 0;
int _disp3oldLength = 0;
bool _gen2I = 0;
bool _gen2O = 0;
unsigned long _gen2P = 0UL;
unsigned long _bmp0851Tti = 0UL;
bool _sd1SVOS3 = 0;
unsigned long _d18x2x1Tti = 0UL;
float _d18x2x1O = 0.00;
int _disp4oldLength = 0;

void setup()
{
pinMode(6, OUTPUT); 
digitalWrite(6, 1); 
pinMode(7, OUTPUT); 
digitalWrite(7, 0); 


Wire.begin();
delay(10);
  Ethernet.begin(ethernet_mac, ethernet_ip, ethernet_dns, ethernet_gateway, ethernet_subnet);
delay(1000);
_tspWebServer.begin();
_bmp085.begin();
Wire.beginTransmission(68);
Wire.write(0x0E);
Wire.write(B00000000);
Wire.write(B10001000);
Wire.endTransmission();
_RTC1.startTime = millis() - 1000;
_lcd1.init();
_lcd1.backlight();
_dht1.setup(3);
_dht1LRT = millis();
_dht1Tti = millis(); 
SD.begin(4);
SPI.begin();
pinMode(53, OUTPUT);

}
void loop()
{

byte _tempVariable_byte;
if (_isNeedClearDisp1) {_lcd1.clear(); _isNeedClearDisp1= 0;}
_tspWebServer_client = _tspWebServer.available();
if (_tspWebServer_client) {
 boolean _WSCLineIsBlank = true;
String _WSCReqest="";
bool _WSCIsFirsLine=1;
bool _WSCIsParse=0;
int _WSCPageNumber=0;
while (_tspWebServer_client.connected()) 
{ while( _tspWebServer_client.available())  
{char _tempWebServerChar = _tspWebServer_client.read(); 
if(_WSCIsFirsLine) {_WSCReqest+= _tempWebServerChar;}
 if (_tempWebServerChar == '\n' && _WSCLineIsBlank) {_sendWebServerPage(_WSCPageNumber); break;}
if (_tempWebServerChar == '\n') {_WSCLineIsBlank = true; _WSCIsFirsLine=0; if (!_WSCIsParse){ _WSCPageNumber=_parseWebServerReqest(_WSCReqest); _WSCIsParse=1;} } else if (_tempWebServerChar != '\r') { _WSCLineIsBlank = false;}
}}}
if(_isTimer(_bmp0851Tti, 1000)) {
_bmp0851Tti = millis(); 
double _tempBMP085TData;
_tempVariable_byte = _bmp085.startTemperature();
if ( _tempVariable_byte != 0) {  
 delay(_tempVariable_byte);
_tempVariable_byte = _bmp085.getTemperature(_tempBMP085TData);
if ( _tempVariable_byte != 0) {  
double _tempBMP085PData;
_tempVariable_byte = _bmp085.startPressure(3);
if ( _tempVariable_byte != 0) {  
 delay(_tempVariable_byte);
_tempVariable_byte = _bmp085.getPressure(_tempBMP085PData, _tempBMP085TData);
if ( _tempVariable_byte != 0) {  
_bmp085P =  _tempBMP085PData*100;
}}}}
}




//Плата:1
if(_isTimer(_d18x2x1Tti, 1000)) {
_d18x2x1Tti = millis(); 
_d18x2x1O=  _readDS18_ow2(_d18x2x1Addr, 0);}
digitalWrite(6, 1);
if (1) {UB_178889508_ubi_102491196 = _bmp085P;
_func_UB_178889508(&UB_178889508_Instance1, UB_178889508_ubi_102491196);}
if(_isTimer(_dht1Tti, 1000)) {
if(_isTimer(_dht1LRT,( _dht1.getMinimumSamplingPeriod()))) {
_dht1.readSensor();
_dht1LRT = millis(); 
_dht1Tti = millis(); 
}
}
if (1) {if (! _gen2I) { _gen2I = 1; _gen2O = 1; _gen2P =  millis(); } } else { _gen2I = 0 ;  _gen2O= 0;  } if (_gen2I ) { if (_gen2O) { if ( _isTimer( _gen2P , 1000 )) { _gen2P = millis(); _gen2O = 0; } } else  { if ( _isTimer( _gen2P , 299000 )) {  _gen2P = millis(); _gen2O = 1;  } } }
if(_gen2O)
{if(! _sd1SVOS1) {
_sd1TS = "temperature;"; 
_sd1TS+= "Integer;";_sd1TS+= ";";
_sd1TS+= (String((int(_dht1.temperature)))); 
_sd1TS+= ";";
_sd1TS+= "C"; 
_sd1TS+= ";";
_sd1DF = SD.open("data.csv", FILE_WRITE);
if (_sd1DF) {_sd1DF.println(_sd1TS); _sd1DF.close();}
_sd1SVOS1 = 1;}}
else
{if( _sd1SVOS1) {_sd1SVOS1 = 0; }}
if(_gen2O)
{if(! _sd1SVOS3) {
_sd1TS = "pressure;"; 
_sd1TS+= "Integer;";_sd1TS+= ";";
_sd1TS+= (String((int(UB_178889508_Instance1.ubo_166622895)))); 
_sd1TS+= ";";
_sd1TS+= "mm Hg"; 
_sd1TS+= ";";
_sd1DF = SD.open("data.csv", FILE_WRITE);
if (_sd1DF) {_sd1DF.println(_sd1TS); _sd1DF.close();}
_sd1SVOS3 = 1;}}
else
{if( _sd1SVOS3) {_sd1SVOS3 = 0; }}
get3231Date(0x68, &_RTC1);
_RTC1_GetTime1_StrOut = ( _convertRealTimeClockNumberToString(_RTC1.Hours))+
String(":")+
( _convertRealTimeClockNumberToString(_RTC1.minutes))+
String(":")+
( _convertRealTimeClockNumberToString(_RTC1.seconds));
if (1) {
_dispTempLength1 = ((_RTC1_GetTime1_StrOut)).length();
if (_disp4oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp4oldLength = _dispTempLength1;
_lcd1.setCursor(int((20 - _dispTempLength1)/2), 0);
_lcd1.print((_RTC1_GetTime1_StrOut));
} else {
if (_disp4oldLength > 0) {_isNeedClearDisp1 = 1; _disp4oldLength = 0;} 
}
if(_gen2O)
{if(! _sd1SVOS4) {
_sd1TS = "time;"; 
_sd1TS+= "String;";_sd1TS+= ";";
_sd1TS+= _RTC1_GetTime1_StrOut; 
_sd1TS+= ";";
_sd1TS+= "time"; 
_sd1TS+= ";";
_sd1DF = SD.open("data.csv", FILE_WRITE);
if (_sd1DF) {_sd1DF.println(_sd1TS); _sd1DF.close();}
_sd1SVOS4 = 1;}}
else
{if( _sd1SVOS4) {_sd1SVOS4 = 0; }}
if(_gen2O)
{if(! _sd1SVOS2) {
_sd1TS = "humidity;"; 
_sd1TS+= "Integer;";_sd1TS+= ";";
_sd1TS+= (String((int(_dht1.humidity)))); 
_sd1TS+= ";";
_sd1TS+= "%"; 
_sd1TS+= ";";
_sd1DF = SD.open("data.csv", FILE_WRITE);
if (_sd1DF) {_sd1DF.println(_sd1TS); _sd1DF.close();}
_sd1SVOS2 = 1;}}
else
{if( _sd1SVOS2) {_sd1SVOS2 = 0; }}
if (1) {
_dispTempLength1 = ((((String("H: ")) + (( _floatToStringWitRaz(_dht1.humidity,0))) + (String(" %"))))).length();
if (_disp2oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp2oldLength = _dispTempLength1;
_lcd1.setCursor(int((20 - _dispTempLength1)/2), 2);
_lcd1.print((((String("H: ")) + (( _floatToStringWitRaz(_dht1.humidity,0))) + (String(" %")))));
} else {
if (_disp2oldLength > 0) {_isNeedClearDisp1 = 1; _disp2oldLength = 0;} 
}
if (1) {
_dispTempLength1 = ((((String("T: ")) + (( _floatToStringWitRaz(_dht1.temperature,0))) + (String(" C"))))).length();
if (_disp1oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp1oldLength = _dispTempLength1;
_lcd1.setCursor(int((20 - _dispTempLength1)/2), 1);
_lcd1.print((((String("T: ")) + (( _floatToStringWitRaz(_dht1.temperature,0))) + (String(" C")))));
} else {
if (_disp1oldLength > 0) {_isNeedClearDisp1 = 1; _disp1oldLength = 0;} 
}
if (1) { if (! _gen1I) { _gen1I = 1; _gen1O = 1; _gen1P = millis(); } } else { _gen1I = 0 ; _gen1O= 0;}
 if (_gen1I) {  if ( _isTimer ( _gen1P , 500 )) { _gen1P = millis(); _gen1O = ! _gen1O;}}
if (_gen1O){
if ( ! _count1I) { 
_count1I = 1;
_count1_Value = _count1_Value + 1;
}} else {
_count1I = 0;}
digitalWrite(7, _WSP1_A1);
if (1) {
_dispTempLength1 = ((((String("P: ")) + (( _floatToStringWitRaz(UB_178889508_Instance1.ubo_166622895,0))) + (String(" mm Hg"))))).length();
if (_disp3oldLength > _dispTempLength1) {_isNeedClearDisp1 = 1;} 
_disp3oldLength = _dispTempLength1;
_lcd1.setCursor(int((20 - _dispTempLength1)/2), 3);
_lcd1.print((((String("P: ")) + (( _floatToStringWitRaz(UB_178889508_Instance1.ubo_166622895,0))) + (String(" mm Hg")))));
} else {
if (_disp3oldLength > 0) {_isNeedClearDisp1 = 1; _disp3oldLength = 0;} 
}






}

String  _floatToStringWitRaz(float value, int raz)
{
 
  return String(value,raz);
}
bool _isTimer(unsigned long startTime, unsigned long period )
  {
  unsigned long currentTime;
currentTime = millis();
if (currentTime>= startTime) {return (currentTime>=(startTime + period));} else {return (currentTime >=(4294967295-startTime+period));}
  }
float _convertDS18x2xData(byte type_s, byte data[12])
{
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) 
  {
  raw = raw << 3; 
  if (data[7] == 0x10) { raw = (raw & 0xFFF0) + 12 - data[6]; }
  }
else 
  {
   byte cfg = (data[4] & 0x60);
   if (cfg == 0x00) raw = raw & ~7;   else if (cfg == 0x20) raw = raw & ~3;  else if (cfg == 0x40) raw = raw & ~1;
  }
return  (float)raw / 16.0;
}
float _readDS18_ow2(byte addr[8], byte type_s)
{  byte data[12];
byte i;
_ow2.reset();
_ow2.select(addr);
_ow2.write(0xBE);
for ( i = 0; i < 9; i++) {
 data[i] = _ow2.read();}
_ow2.reset();
_ow2.select(addr);
_ow2.write(0x44, 1);
return _convertDS18x2xData(type_s, data);}void _sendWebServerPage(int sendPageNumber)
{_tspWebServer_client.println("HTTP/1.1 200 OK");
_tspWebServer_client.println("Connection: close");  
 if ( (sendPageNumber==1)) {if(sendPageNumber==1){_tspWebServer_client.println("Refresh: 5");}
}
_tspWebServer_client.println();
_tspWebServer_client.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
_tspWebServer_client.println("<html><head>");
_tspWebServer_client.println("<META content=\"text/html; charset=utf-8\" http-equiv=\"Content-Type\">");
_tspWebServer_client.println("</head><body>");
if (sendPageNumber ==1) {_sendWebServerPage1();}
_tspWebServer_client.println("</body></html>");
 delay(1); _tspWebServer_client.stop();}
int _parseWebServerReqest(String reqestAddres)
{
int index;
int result=0;
index=reqestAddres.indexOf("/");
  reqestAddres =_stringWithoutCharWithIndex(reqestAddres,0,(index));
index=reqestAddres.indexOf(" ");
reqestAddres =_stringWithoutCharWithIndex(reqestAddres,index,(reqestAddres.length()-index));
if (reqestAddres==""){_WSP1_A1=1; result= 1;} else {_WSP1_A1=0;} 
return result;
}
String _stringWithoutCharWithIndex(String value, int index,int count)
  {
    String result="";
    for (int i=0; i <= value.length(); i++){ 
      if((i<index) ||(i>(index+count))){
        result+=value.charAt(i);
      }
    } 
    return result; 
  }


void _sendWebServerPage1(void)
{
_tspWebServer_client.println("<head>");
_tspWebServer_client.println("	<meta charset=\"utf-8\">");
_tspWebServer_client.println("  	<title>Meteoserver</title>");
_tspWebServer_client.println("	<style>");
_tspWebServer_client.println("		@import url('https://fonts.googleapis.com/css2?family=MuseoModerno&display=swap');");
_tspWebServer_client.println("		@font-face {");
_tspWebServer_client.println("  			font-family: 'MuseoModerno', sans-serif;");
_tspWebServer_client.println("		}");
_tspWebServer_client.println("		body { ");
_tspWebServer_client.println("    			margin: 0;");
_tspWebServer_client.println("   		}");
_tspWebServer_client.println("   		.parent {");
_tspWebServer_client.println("    			margin: 5%;");
_tspWebServer_client.println("    			padding: 10px;");
_tspWebServer_client.println("   		} ");
_tspWebServer_client.println("   		.child {");
_tspWebServer_client.println("    			border: 3px solid #666;");
_tspWebServer_client.println("    			padding: 10px;");
_tspWebServer_client.println("    			margin: 5px;");
_tspWebServer_client.println("			font-family: 'MuseoModerno', sans-serif;");
_tspWebServer_client.println("   		}");
_tspWebServer_client.println("	</style>");
_tspWebServer_client.println("</head>");
_tspWebServer_client.println("<body>");
_tspWebServer_client.println("	<div class=\"parent\">");
_tspWebServer_client.println("  		<div class=\"child\">");
_tspWebServer_client.println("			<a href=\"https://ibb.co/nfqNWjq\"><img src=\"https://i.ibb.co/K7cp1Wc/logoza-ru.png\"  			alt=\"logoza-ru\" border=\"0\"></a>");
_tspWebServer_client.println("			<h2>Temperature: ");

_tspWebServer_client.println((int(_dht1.temperature)));
_tspWebServer_client.println(" C°</h2>");
_tspWebServer_client.println("			<h2>Humidity: ");

_tspWebServer_client.println((int(_dht1.humidity)));
_tspWebServer_client.println(" %</h2>");
_tspWebServer_client.println("			<h2>Pressure: ");

_tspWebServer_client.println((int(UB_178889508_Instance1.ubo_166622895)));
_tspWebServer_client.println(" mm.in.Hg.</h2>");
_tspWebServer_client.println("			<h2>Server uptime: ");

_tspWebServer_client.println(_count1_Value);
_tspWebServer_client.println(" sec.</h2>");
_tspWebServer_client.println("		 </div>");
_tspWebServer_client.println("	 </div>");
_tspWebServer_client.println("	");

}void get3231Date(int addres, struct _I2CRealRimeClockTime *timeStruct)
{
  if (!(_isTimer ((timeStruct ->startTime), 250))) {
    return;
  }
  Wire.beginTransmission( addres);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(addres, 7);
  if (Wire.available()) {
    byte  seconds = Wire.read();
    byte minutes = Wire.read();
    byte hours   = Wire.read();
    byte day     = Wire.read();
    byte date    = Wire.read();
    byte month   = Wire.read();
    byte year    = Wire.read();
    timeStruct -> seconds = (((seconds & B11110000) >> 4) * 10 + (seconds & B00001111));
    timeStruct -> minutes = (((minutes & B11110000) >> 4) * 10 + (minutes & B00001111));
    timeStruct -> Hours = (((hours & B00110000) >> 4) * 10 + (hours & B00001111));
    timeStruct -> weekday = (day & B00000111);
    timeStruct -> day    = (((date & B00110000) >> 4) * 10 + (date & B00001111));
    timeStruct -> month   = (((month & B00010000) >> 4) * 10 + (month & B00001111));
    timeStruct -> year    = (((year & B11110000) >> 4) * 10 + (year & B00001111));
  } timeStruct ->startTime = millis();
}
String _convertRealTimeClockNumberToString(byte value)
{
  if (value > 9) {
    return String(value, DEC);
  }
  return (String("0") + String(value, DEC));
}

void _func_UB_178889508(struct UB_178889508 *_ubInstans, unsigned long ubi_102491196)
{
float ubo_166622895 = _ubInstans->ubo_166622895;
float _gtv1 = _ubInstans->_gtv1;
ubo_166622895 = (ubi_102491196)/(_gtv1);
_ubInstans->ubo_166622895 = ubo_166622895;
_ubInstans->_gtv1 = _gtv1;

}
