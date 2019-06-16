/*created by krabbencutter*/

/*initialize variables to store the crossfader & output values*/
int cfx;
int volA;
int volB;

/*set the desired output pins*/
int outA = 9; 
int outB = 11;

/*use these variables to adjust the cut in on either side*/
int cutA = 0;
int cutB = 0;

/*The Behringer X1 uses a baud rate of 31250. Connections are as follows: (red=GND;middle=Rx;left=3.3v)*/
void setup() {
        Serial.begin(31250);
}

void loop() {

        if (Serial.available() > 0) {
                cfx = Serial.read();
                if(cfx < cutA + 1){
                  volA = 0;
                  volB = 255;
                }
                else if(cfx > 126 - cutB){
                  volA = 255;
                  volB = 0;
                }
                else{
                  volA=255;
                  volB=255;
                }
                analogWrite(volA, outA);
                analogWrite(volB, outB);

                /*these lines are just for debugging*/
                /*
                Serial.print(cfx, DEC);
                Serial.print("\t");
                Serial.print(volA, DEC);
                Serial.print("\t");
                Serial.print(volB, DEC);
                Serial.println();
                */
        }
}
