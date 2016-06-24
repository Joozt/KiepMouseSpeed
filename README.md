# KiepMouseSpeed
### A C++ application to change the Windows mouse speed by absolute or relative value

Usage: `KiepMouseSpeed [-s speed] [-i speed_difference] [-d speed_difference]`
 - `-s` : Sets mouse speed to provided speed [1..20]
 - `-i` : Increases mouse speed by speed_difference [0..19]
 - `-d` : Decreases mouse speed by speed_difference [0..19]

Examples:
```
KiepMouseSpeed -s 10
New mouse speed: 10
 
KiepMouseSpeed -i 5
Current mouse speed: 10
New mouse speed: 15
 
KiepMouseSpeed -d 5
Current mouse speed: 15
New mouse speed: 10
```

See [KiepProjects](https://github.com/Joozt/KiepProjects) for an overview of all Kiep projects.
