#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TeensyView.h>

#define PIN_RESET 15
#define PIN_DC    5
#define PIN_CS    10
#define PIN_SCK   13
#define PIN_MOSI  11

#define rxPin 0
#define txPin 1
#define ledPin 9
#define speakerPin 12
#define morse_freq_hz 600
// MS = 1200 / WPM
#define wpm 20
#define time_unit 1200/wpm 

TeensyView oled(PIN_RESET, PIN_DC, PIN_CS, PIN_SCK, PIN_MOSI);

void dot() {
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, morse_freq_hz);
  delay(time_unit);
  digitalWrite(ledPin, LOW);
  noTone(speakerPin);
  symbol_space();
}

void dash() {
  digitalWrite(ledPin, HIGH);
  tone(speakerPin, morse_freq_hz);
  delay(time_unit*3);
  digitalWrite(ledPin, LOW);
  noTone(speakerPin);
  symbol_space();
}

void symbol_space() {
  delay(time_unit);
}

void character_space() {
  delay(time_unit*3);
}

void word_space() {
  delay(time_unit *7);
}

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(36);

  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
  delay(1000);     // Delay 1000 ms
  oled.clear(PAGE); // Clear the buffer.

  randomSeed(analogRead(A0) + analogRead(A1));

  printTitle("txt 2 morse", 1);
}

void display_morse(String message, int message_len) {
  oled.setFontType(0);  // Set font to type 0
  
  Serial.print("Morse Message Length:");
  Serial.println(message_len);
  
  for (int i = 0; i < message_len; i++) {
    if (i % 84 == 0) {
      delay(500);           // Delay 500 ms
      oled.clear(PAGE);     // Clear the page
      oled.setCursor(0, 0); // Set cursor to top-left
    }
    

    char msg_byte= message[i];

    Serial.print(msg_byte);

    switch(msg_byte) {
      case 'A':
      case 'a':
        oled.write(65);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms

        Serial.print(" .-");
        dot(); dash();
        character_space();
        break;
      case 'B':
      case 'b':
        oled.write(66);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -...");
        dash(); dot(); dot(); dot();
        character_space();
        break;
      case 'C':
      case 'c':
        oled.write(67);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -.-.");
        dash(); dot(); dash(); dot();
        character_space();
        break;
      case 'D':
      case 'd':
        oled.write(68);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -..");
        dash(); dot(); dot();
        character_space();
        break;
      case 'E':
      case 'e':
        oled.write(69);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .");
        dot();
        character_space();
        break;
      case 'F':
      case 'f':
        oled.write(70);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ..-.");
        dot(); dot(); dash(); dot();
        character_space();
        break;
      case 'G':
      case 'g':
        oled.write(71);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" --.");
        dash(); dash(); dot();
        character_space();
        break;
      case 'H':
      case 'h':
        oled.write(72);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ....");
        dot(); dot(); dot(); dot();
        character_space();
        break;
      case 'I':
      case 'i':
        oled.write(73);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ..");
        dot(); dot();
        character_space();
        break;
      case 'J':
      case 'j':
        oled.write(74);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .---");
        dot(); dash(); dash(); dash();
        character_space();
        break;
      case 'K':
      case 'k':
        oled.write(75);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -.-");
        dash(); dot(); dash();
        character_space();
        break;
      case 'L':
      case 'l':
        oled.write(76);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .-..");
        dot(); dash(); dot(); dot();
        character_space();
        break;
      case 'M':
      case 'm':
        oled.write(77);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" --");
        dash(); dash();
        character_space();
        break;
      case 'N':
      case 'n':
        oled.write(78);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -.");
        dash(); dot();
        character_space();
        break;
      case 'O':
      case 'o':
        oled.write(79);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ---");
        dash(); dash(); dash();
        character_space();
        break;
      case 'P':
      case 'p':
        oled.write(80);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .--.");
        dot(); dash(); dash(); dot();
        character_space();
        break;
      case 'Q':
      case 'q':
        oled.write(81);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" --.-");
        dash(); dash(); dot(); dash();
        character_space();
        break;
      case 'R':
      case 'r':
        oled.write(82);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .-.");
        dot(); dash(); dot();
        character_space();
        break;
      case 'S':
      case 's':
        oled.write(83);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ...");
        dot(); dot(); dot();
        character_space();
        break;
      case 'T':
      case 't':
        oled.write(84);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -");
        dash();
        character_space();
        break;
      case 'U':
      case 'u':
        oled.write(85);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ..-");
        dot(); dot(); dash();
        character_space();
        break;
      case 'V':
      case 'v':
        oled.write(86);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ...-");
        dot(); dot(); dot(); dash();
        character_space();
        break;
      case 'W':
      case 'w':
        oled.write(87);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .--");
        dot(); dash(); dash();
        character_space();
        break;
      case 'X':
      case 'x':
        oled.write(88);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -..-");
        dash(); dot(); dot(); dash();
        character_space();
        break;
      case 'Y':
      case 'y':
        oled.write(89);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -.--");
        dash(); dot(); dash(); dash();
        character_space();
        break;
      case 'Z':
      case 'z':
        oled.write(90);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" --..");
        dash(); dash(); dot(); dot();
        character_space();
        break;
      case '1':
        oled.write(49);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .----");
        dot(); dash(); dash(); dash(); dash();
        character_space();
        break;
      case '2':
        oled.write(50);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ..---");
        dot(); dot(); dash(); dash(); dash();
        character_space();
        break;
      case '3':
        oled.write(51);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ...--");
        dot(); dot(); dot(); dash(); dash();
        character_space();
        break;
      case '4':
        oled.write(52);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ....-");
        dot(); dot(); dot(); dot(); dash();        
        character_space();
        break;
      case '5':
        oled.write(53);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .....");
        dot(); dot(); dot(); dot(); dot();
        character_space();
        break;
      case '6':
        oled.write(54);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -....");
        dash(); dot(); dot(); dot(); dot();
        character_space();
        break;
      case '7':
        oled.write(55);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" --...");
        dash(); dash(); dot(); dot(); dot();
        character_space();
        break;
      case '8':
        oled.write(56);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ---..");
        dash(); dash(); dash(); dot(); dot();
        character_space();
        break;
      case '9':
        oled.write(57);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ----.");
        dash(); dash(); dash(); dash(); dot();
        character_space();
        break;
      case '0':
        oled.write(48);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -----");
        dash(); dash(); dash(); dash(); dash();
        character_space();
        break;
      case '.':
        oled.write(46);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .-.-.-");
        dot(); dash(); dot(); dash(); dot(); dash();
        character_space();
        break;
      case ',':
        oled.write(44);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" --..--");
        dash(); dash(); dot(); dot(); dash(); dash();
        character_space();
        break;
      case '?':
        oled.write(63);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ..--..");
        dot(); dot(); dash(); dash(); dot(); dot();
        character_space();
        break;
      case '\'':
        oled.write(39);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .----.");
        dot(); dash(); dash(); dash(); dash(); dot();
        character_space();
        break;
      case '!':
        oled.write(33);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -.-.--");
        dash(); dot(); dash(); dot(); dash(); dash();
        break;
      case '/':
        oled.write(47);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -..-.");
        dash(); dot(); dot(); dash(); dot();
        character_space();
        break;
      case ':':
        oled.write(58);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ---...");
        dash(); dash(); dash(); dot(); dot(); dot();
        character_space();
        break;
      case ';':
        oled.write(59);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -.-.-.");
        dash(); dot(); dash(); dot(); dash(); dot();
        character_space();
        break;
      case '=':
        oled.write(61);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -...-");
        dash(); dot(); dot(); dot(); dash();
        character_space();
        break;
      case '+':
        oled.write(43);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .-.-.");
        dot(); dash(); dot(); dash(); dot();
        character_space();
        break;
      case '-':
        oled.write(45);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" -....-");
        dash(); dot(); dot(); dot(); dot(); dash();
        character_space();
        break;
      case '_':
        oled.write(22);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" ..--.-");
        dot(); dot(); dash(); dash(); dot(); dash();
        character_space();
        break;
      case '"':
        oled.write(34);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .-..-.");
        dot(); dash(); dot(); dot(); dash(); dot();
        character_space();
        break;
      case '@':
        oled.write(64);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        Serial.print(" .--.-.");
        dot(); dash(); dash(); dot(); dash(); dot();
        character_space();
        break;
      case ' ':
        oled.write(0);  // Write a byte out as a character
        oled.display(); // Draw on the screen
        // delay(93);      // Wait 93ms
        
        word_space();
        break;
      case '\r':
        break;
      case '\n':
        break;
      default:
        Serial.print(" << Invalid Morse Character Detected!");
    }
    Serial.println();
  }
  Serial.println();
}

void printTitle(String title, int font)
{
  int middleX = oled.getLCDWidth() / 2;
  int middleY = oled.getLCDHeight() / 2;

  oled.clear(PAGE);
  oled.setFontType(font);
  // Try to set the cursor in the middle of the screen
  oled.setCursor(middleX - (oled.getFontWidth() * (title.length() / 2)),
                 middleY - (oled.getFontWidth() / 2));
  // Print the title:
  oled.print(title);
  oled.display();
  delay(1500);
  oled.clear(PAGE);
}

void loop() {
  digitalWrite(ledPin, LOW);
  String message = Serial.readString();
  int message_len = message.length();
  if (message_len > 0) {
    Serial.println();
    Serial.print(morse_freq_hz);
    Serial.print("HZ @ ");
    Serial.print(wpm);
    Serial.println(" WPM");
    
    display_morse(message, message_len);
    
    Serial.print("Transmitted: ");
    Serial.println(message);
    Serial.println("-----------------------------");
    Serial.println();
    Serial.println();
    Serial.println();    
    
    Serial.flush();
  }
}
