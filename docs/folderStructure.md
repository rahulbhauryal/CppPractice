# structure

**-build**\
- bin
- src
    - app
    - drivers
    - test\
    main.o
___
**-docs**\
___
**-external**\
for external code
- printf (I want to use as such from git, it is a git submodule)
___
**-src**\
* -app
    - derive.c
    - derive.h
    - enemy.c
    - enemy.h
* -common (code shred between app and driver)
    - defines.h
* -driver
    - i2c.c
    - i2c.h
    - uart.c
    - uart.h
* -test
    - unittest.c
    - unittest.h
main.c
___
**-tools**\
___
.clang-format\
.gitignore\
makefile\
README.md\
___
___

# Pitchfork layout
# Canonical project structure
