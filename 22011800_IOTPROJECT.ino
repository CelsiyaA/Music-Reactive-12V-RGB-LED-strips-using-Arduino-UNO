// Defining the pins for sound sensor and LED strip
#define Sound_pin A0 //it is an analog pin connected to sound sensor
#define Red_pin 11
#define Green_pin 10
#define Blue_pin 9
#define Delay_LEDS 3

// Defining filter parameters
#define Cutofffreq 900 // Cut off Frequency in Hz
#define Alpha 0.2 // filter coefficient

// Initialization of variables
int Redvalue = 0;
int Greenvalue = 0;
int Bluevalue = 0;
int Sensorvalue = 0;
int filteredvalue = 0;

void setup() {
  // Initializing the RGB pins as output
  pinMode(Red_pin, OUTPUT);
  pinMode(Green_pin, OUTPUT);
  pinMode(Blue_pin, OUTPUT);
  
  // Serial communication initialization
  Serial.begin(9600);
}

//Defining a loop 
void loop() {
  // To read the raw sound sensor (analog)value
  int Sensorvalue = analogRead(Sound_pin);
  
  // Creating a first-order low pass filter to reduce high frequency noise
  static int previous_value = 0;
  filteredvalue = Alpha * Sensorvalue + (1 - Alpha) * previous_value;
  previous_value = filteredvalue;
  
  // Colour determination based on the filtered sound sensor value
  if (filteredvalue < 100) {
    RGBColor(255, 0, 255);
    Serial.println("Rose");//Rose
  } else if (filteredvalue < 200) {
    RGBColor(165, 42, 42);
    Serial.println("Red"); //Red
  } else if (filteredvalue < 300) {
    RGBColor(0, 255, 0);
    Serial.println("Green"); //Green
  } else if (filteredvalue < 400) {
    RGBColor(255, 255, 255);
    Serial.println("White"); //White
  } else if (filteredvalue < 500) {
    RGBColor(0, 0, 255);
    Serial.println("Blue"); //Blue
  } else if (filteredvalue < 600) {
    RGBColor(255, 165, 0);
    Serial.println("Orange"); //Orange
  } else if (filteredvalue < 700) {
    RGBColor(255, 0, 0);
    Serial.println("Red"); //Red
  } else if (filteredvalue < 800) {
    RGBColor(255, 255, 0);
    Serial.println("Yellow");//Yellow
  } else {
    RGBColor(255, 0, 255);
    Serial.println("Default: Rose"); //Rose
  }
}

//Defining the class
void RGBColor(int Redcolor, int Greencolor, int Bluecolor) {

  analogWrite(Red_pin, Redcolor);
  analogWrite(Green_pin, Greencolor);
  analogWrite(Blue_pin, Bluecolor);

  //Printing the filtered value on the monitor
  Serial.print("Sensorvalue: ");
  Serial.print(Sensorvalue);
  Serial.print("filteredvalue: ");
  Serial.print(filteredvalue);
  

  delay(Delay_LEDS);
} 
  
  