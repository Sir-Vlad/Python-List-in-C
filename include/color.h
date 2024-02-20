#ifndef COLOR_H
#define COLOR_H

// Regular text
#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define MAGENTA "\e[0;35m"
#define CYAN "\e[0;36m"
#define WHITE "\e[0;37m"

// Regular bold text
#define BLACK_BOLD "\e[1;30m"
#define RED_BOLD "\e[1;31m"
#define GREEN_BOLD "\e[1;32m"
#define YELLOW_BOLD "\e[1;33m"
#define BLUE_BOLD "\e[1;34m"
#define MAGENTA_BOLD "\e[1;35m"
#define CYAN_BOLD "\e[1;36m"
#define WHITE_BOLD "\e[1;37m"

// Regular dim text
#define BLACK_DIM "\e[2;30m"
#define RED_DIM "\e[2;31m"
#define GREEN_DIM "\e[2;32m"
#define YELLOW_DIM "\e[2;33m"
#define BLUE_DIM "\e[2;34m"
#define MAGENTA_DIM "\e[2;35m"
#define CYAN_DIM "\e[2;36m"
#define WHITE_DIM "\e[2;37m"

// Regular italics text
#define BLACK_ITALICS "\e[3;30m"
#define RED_ITALICS "\e[3;31m"
#define GREEN_ITALICS "\e[3;32m"
#define YELLOW_ITALICS "\e[3;33m"
#define BLUE_ITALICS "\e[3;34m"
#define MAGENTA_ITALICS "\e[3;35m"
#define CYAN_ITALICS "\e[3;36m"
#define WHITE_ITALICS "\e[3;37m"

// Regular underline text
#define BLACK_UNDERLINE "\e[4;30m"
#define RED_UNDERLINE "\e[4;31m"
#define GREEN_UNDERLINE "\e[4;32m"
#define YELLOW_UNDERLINE "\e[4;33m"
#define BLUE_UNDERLINE "\e[4;34m"
#define MAGENTA_UNDERLINE "\e[4;35m"
#define CYAN_UNDERLINE "\e[4;36m"
#define WHITE_UNDERLINE "\e[4;37m"

// Regular reversed text
#define BLACK_REVERSED "\e[7;30m"
#define RED_REVERSED "\e[7;31m"
#define GREEN_REVERSED "\e[7;32m"
#define YELLOW_REVERSED "\e[7;33m"
#define BLUE_REVERSED "\e[7;34m"
#define MAGENTA_REVERSED "\e[7;35m"
#define CYAN_REVERSED "\e[7;36m"
#define WHITE_REVERSED "\e[7;37m"

// Regular BG
#define BLACK_BG "\e[40m"
#define RED_BG "\e[41m"
#define GREEN_BG "\e[42m"
#define YELLOW_BG "\e[43m"
#define BLUE_BG "\e[44m"
#define MAGENTA_BG "\e[45m"
#define CYAN_BG "\e[46m"
#define WHITE_BG "\e[47m"

// High intensity BG
#define BLACK_HIGH_INTENSITY_BG "\e[0;100m"
#define RED_HIGH_INTENSITY_BG "\e[0;101m"
#define GREEN_HIGH_INTENSITY_BG "\e[0;102m"
#define YELLOW_HIGH_INTENSITY_BG "\e[0;103m"
#define BLUE_HIGH_INTENSITY_BG "\e[0;104m"
#define MAGENTA_HIGH_INTENSITY_BG "\e[0;105m"
#define CYAN_HIGH_INTENSITY_BG "\e[0;106m"
#define WHITE_HIGH_INTENSITY_BG "\e[0;107m"

// High intensity text
#define BLACK_HIGH_INTENSITY "\e[0;90m"
#define RED_HIGH_INTENSITY "\e[0;91m"
#define GREEN_HIGH_INTENSITY "\e[0;92m"
#define YELLOW_HIGH_INTENSITY "\e[0;93m"
#define BLUE_HIGH_INTENSITY "\e[0;94m"
#define MAGENTA_HIGH_INTENSITY "\e[0;95m"
#define CYAN_HIGH_INTENSITY "\e[0;96m"
#define WHITE_HIGH_INTENSITY "\e[0;97m"

// Bold high intensity text
#define BLACK_BOLD_HIGH_INTENSITY "\e[1;90m"
#define RED_BOLD_HIGH_INTENSITY "\e[1;91m"
#define GREEN_BOLD_HIGH_INTENSITY "\e[1;92m"
#define YELLOW_BOLD_HIGH_INTENSITY "\e[1;93m"
#define BLUE_BOLD_HIGH_INTENSITY "\e[1;94m"
#define MAGENTA_BOLD_HIGH_INTENSITY "\e[1;95m"
#define CYAN_BOLD_HIGH_INTENSITY "\e[1;96m"
#define WHITE_BOLD_HIGH_INTENSITY "\e[1;97m"

// MORE CODES
#define DIM "\e[22m"
#define BLINK "\e[5m"
#define HIDDEN "\e[8m"
#define REVERSE "\e[7m"
#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define STRIKE "\e[9m"

// Reset
#define RESET "\e[0m"
#define RESET_NL "\e[0m\n"

#endif  // COLOR_H
