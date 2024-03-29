#pragma once

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

// #define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#define RGBLIGHT_LAYERS

#define TAPPING_TERM 300

#define TAP_CODE_DELAY 10

// mouse keys

#define MOUSEKEY_INTERVAL 16

#define MOUSEKEY_DELAY 0

#define MOUSEKEY_TIME_TO_MAX 60

#define MOUSEKEY_MAX_SPEED 6

#define MOUSEKEY_WHEEL_DELAY 0
