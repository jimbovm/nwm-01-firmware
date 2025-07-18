# New World Modular NWM-01 MIDI→CV Converter (firmware)

The NWM-01 is an open hardware MIDI-to-CV converter for the Eurorack format, based on the Arduino platform. It's designed to be inexpensive and easy to clone and modify, with a low component count and all components cheap to buy in multiples from your favourite supplier. It began as an experiment around just how far a simple set of inexpensive components could be pushed and aims to pack in a lot of features for its simplicity.

This repository is for the firmware only; for the hardware files see [https://github.com/jimbovm/nwm-01]().

## Features

* Nearly 5 octaves of tracking
* Reassignable velocity output (generate CV with keyboard velocity or a control change)
* Trigger output with invertible polarity and variable duration
* MIDI clock compatibility; generates clock pulses (duration configurable) from received MIDI clock
* Start/stop output responsive to MIDI start/stop messages
* Support for arbitrary tunings (i.e. other than 12 tone equal temperament)
* Heavily configurable over System Exclusive

## Features planned for the future

* An arpeggiator
* A very basic sequencer

**⚠ Both firmware and hardware for the NWM-01 are works in progress and still in development.**

## Licence

SPDX-License-Identifier: MIT
