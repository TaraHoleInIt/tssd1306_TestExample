// Copyright (c) 2018 Tara Keeling
// 
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <Arduino.h>
#include "wirewrap.h"
#include "tssd1306/ssd1306.h"

void WireStartTransmission( const int Address ) {
    Wire.beginTransmission( Address );
}

void WireWrite( const uint8_t* Data, const size_t Length ) {
    Wire.write( Data, Length );
}

void WireEndTransmission( void ) {
    Wire.endTransmission( );
}

static const I2CProcs WireWrapper = {
    WireStartTransmission,
    WireWrite,
    WireEndTransmission,
    BUFFER_LENGTH
};

void setup( void ) {
    Wire.begin( );

#if defined LEDPIN
    pinMode( LEDPIN, OUTPUT );
    digitalWrite( LEDPIN, LOW );
#endif
}

void Heartbeat( void ) {
#if defined LEDPIN
    static unsigned long NextBlinkTime = 0;
    unsigned long TimeNow = 0;
    static int State = 0;

    TimeNow = millis( );

    if ( TimeNow >= NextBlinkTime ) {
        NextBlinkTime = TimeNow + 1000;
        State = ! State;

        digitalWrite( LEDPIN, State );
    }
#endif
}

void loop( void ) {
    SSD1306_Init( &WireWrapper );

    SSD1306_SetFont( &Font_Droid_Sans_7x10 );
    SSD1306_DrawString( "Hello ATTiny85!\nI'm bored.\nAgain.\nlol", 0, 0, 1 );

    while ( true ) {
        Heartbeat( );
    }
}
