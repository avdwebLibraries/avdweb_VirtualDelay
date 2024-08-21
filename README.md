# `avdweb_VirtualDelay` Library Multiple delays without blocking code execution.

Allows using (multiple) delays without blocking code execution for *Arduino Uno* and *Zero*. During the delay, the code execution is continued. We can use multiple delays simultaneously and independent of each other.

### Advantages of the VirtualDelay library:
- The delay is virtual, during the delay, the code execution is continued
- We can use multiple delays sequentially in a loop.
- We can use multiple delays simultaneously and independent of each other.
- The delay time can set in micro-seconds or milli-seconds.
- No hardware timers are used
- The library is timer-rollover safe

See the article https://www.avdweb.nl/arduino/timing/virtualdelay

## Developer Note

Please run code formatting before committing the code.

```sh
clang-format -i src/*.* examples/**/*.ino
```

## License

`SPDX: GPL-3.0-or-later`

`avdweb_VirtualDelay` Library - Multiple delays without blocking code execution.

Copyright (C) 2018-2024 Albert van Dalen <http://www.avdweb.nl>

Copyright (C) 2024 Abhijit Bose (aka. Boseji) :contributor:

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.

