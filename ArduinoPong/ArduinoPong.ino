// This is the Arduino version of Pong.
// The lights bounce from one end to the other and you must press the button in time to get it to bounce back the other way.
// If you press the button before the light gets to you, or if you don't press it in time, you will lose the game.
// One of the end lights will flash to show the winner.
// Press the reset button to start a new game.

// The pins for our 6 leds.
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led5 = 12;
int led6 = 13;

// The pins for the two buttons.
int button1 = 6;
int button2 = A0;

// The buzzer pin.
int buzzer = 3;

// The time between each light flash. This gets quicker as the game goes on.
int pause = 200;

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
}

void loop()
{
    // Bounce the LEDs from one end to the other.
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzer, 262, 10);
    delay(pause);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    tone(buzzer, 262, 10);
    delay(pause);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buzzer, 262, 10);
    delay(pause);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    tone(buzzer, 262, 10);
    delay(pause);
    digitalWrite(led5, LOW);
    digitalWrite(led6, HIGH);
    tone(buzzer, 262, 10);
    
    // If you press the button before the last light turns on that's cheating.
    if(digitalRead(button2) == HIGH)
    {
        playerOneWins();
    }
    
    // We've reached the end. Let's check if player two presses the button in time.
    int pressed = false;
    unsigned long start = millis();
    while(millis() - start < pause)
    {
       if(digitalRead(button2) == HIGH)
       {
          pressed = true;
          break;
       }
    }
    if(!pressed)
    {
        playerOneWins();
    }
    
    // Bounce the LEDs back the other way.
    digitalWrite(led6, LOW);
    digitalWrite(led5, HIGH);
    tone(buzzer, 262, 10);
    delay(pause);
    digitalWrite(led5, LOW);
    digitalWrite(led4, HIGH);
    tone(buzzer, 262, 10);
    delay(pause);
    digitalWrite(led4, LOW);
    digitalWrite(led3, HIGH);
    tone(buzzer, 262, 10);
    delay(pause);
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzer, 262, 10);
    delay(pause);
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
    tone(buzzer, 262, 10);
    
    // If you press the button before the last light turns on that's cheating.
    if(digitalRead(button1) == HIGH)
    {
        playerTwoWins();
    }
    
    // We've reached the other end. Let's check if player onw presses the button in time.
    pressed = false;
    start = millis();
    while(millis() - start < pause)
    {
       if(digitalRead(button1) == HIGH)
       {
          pressed = true;
          break;
       }
    }
    if(!pressed)
    {
        playerTwoWins();
    }

    // Make the delay time get shorter.
    pause -= 10;
}

void playerOneWins()
{
    // Player 1 wins. Let's flash the first light unitl the reset button is pressed.
    while(true)
    {
        digitalWrite(led1, HIGH);
        delay(100);
        digitalWrite(led1, LOW);
        delay(100);
    }
}

void playerTwoWins()
{
    // Player 2 wins. Let's flash the last light unitl the reset button is pressed.
    while(true)
    {
        digitalWrite(led6, HIGH);
        delay(100);
        digitalWrite(led6, LOW);
        delay(100);
    }
}

