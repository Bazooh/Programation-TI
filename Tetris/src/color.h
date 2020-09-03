
#ifndef PROJETS_COLOR_H
#define PROJETS_COLOR_H

# include <graphx.h>

# define BRIGHT_WHITE   0x00
# define WHITE          0x01
# define DARK_WHITE     0x02

# define BRIGHT_CYAN    0x03
# define CYAN           0x04
# define DARK_CYAN      0x05

# define BLUE           0x06
# define DARK_BLUE      0x07
# define DARK_DARK_BLUE 0x08

# define BRIGHT_ORANGE  0x09
# define ORANGE         0x0A
# define DARK_ORANGE    0x0B

# define BRIGHT_YELLOW  0x0C
# define YELLOW         0x0D
# define DARK_YELLOW    0x0E

# define BRIGHT_GREEN   0x0F
# define GREEN          0x10
# define DARK_GREEN     0x11

# define BRIGHT_PURPLE  0x12
# define PURPLE         0x13
# define DARK_PURPLE    0x14

# define BRIGHT_RED     0x15
# define RED            0x16
# define DARK_RED       0x17

# define BRIGHT_BLACK   0x18
# define BLACK          0x19
# define DARK_BLACK     0x1A

# define LENGTH_PAL 27
# define sizeof_gfx_pal LENGTH_PAL * 2
extern uint16_t gfx_pal[LENGTH_PAL];

#endif //PROJETS_COLOR_H
