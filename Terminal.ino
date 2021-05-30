/*************************************************************
Create with PROGRAMINO-IDE http://www.programino.com

Project:       Programino Terminal Demo
Librarys:      
Author:        UlliS
Description:

Terminal special functions:
---------------------------
[#HOME#]                   -> Cursor Home-Position
[#END#]                    -> Cursor End-Postion
[#CLEAR#]                  -> Clear the Terminal-Screen
[#SAVE#filename]           -> Save the Terminal-Content
[#BEEP#]                   -> Play a beep tone
[#EXECUTE#path+filename]   -> Execute a program
**************************************************************/

long cnt = 0;

void setup() {
    
    // set baudrate to 19200 baud
    Serial.begin(19200);
    while(!Serial) {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    
    // clear the terminal
    Serial.println("[#CLEAR#]");
    delay(500);
    
    // execute the cmd.exe program
    Serial.println("[#EXECUTE#cmd.exe]");
}

void loop() {
    
    // read the analog input A0
    Serial.print(analogRead(A0));
    Serial.print("\t");           // use TAB
    Serial.print("-");
    Serial.print("\t");           // use TAB
    Serial.println(cnt);
    delay(200);
    cnt++;
    
    // save data after 50 measurements into the Logfile.txt and sounds a beep tone
    if(cnt==50)
    {
        Serial.println("[#SAVE#LogFile.txt]");
        Serial.println("[#BEEP#]");
    }
    
    // goto home, goto end and goto home :-)
    if(cnt==75) 
    {
        Serial.println("[#HOME#]");
        delay(2000);
        Serial.println("[#END#]");
        delay(2000);
        Serial.println("[#HOME#]");
        delay(2000);
    }
    
    // clear the terminal screen after 100 measurements and set counter to first line
    if(cnt==100)
    {
        Serial.println("[#CLEAR#]");
        cnt = 0;
    }
    
}
