void setup(){
    Serial.begin(115200);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
}

byte command, note, vel;

void loop(){
    if (Serial.available()==3){ //verificar si hay 3 datos para leer (MIDI)
        command = Serial.read();
        note    = Serial.read();
        vel     = Serial.read();
        if (command == 144 || command == 176 ){ 
            if (note == 60 ){//c3
                analogWrite(9, vel*2);
            }
            if (note == 62){ //D3
                analogWrite(10, vel*2);
            }
            if (note == 64){ //E3
                analogWrite(2, vel*2);
            }
            if (note == 65){ //F3
                analogWrite(3, vel*2);
            }
        }    
         if (command==128) //apagar 
        {
            if (note==60) //C3
            {
                analogWrite(9,0);
            }
            if (note==62) //D3
            {
                analogWrite(10,0);
            }
            if (note == 64){ //E3
                analogWrite(2, 0);
            }
            if (note == 65){ //F3
                analogWrite(3, 0);
            }
        }
    }

}
