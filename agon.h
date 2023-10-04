/* agon.h -- header file for defining colors used on agon architecture */
/* This header will be used only when __AGON__ is defined */

#include <mos_api.h>
#include <agon/vdp_vdu.h>

/* The number of supported colors on Agon depends on the current video mode */
/* Some modes are monochromatic, some 4-color, some 16-color */

/* Mode 0 seems to have 16 colors and 80x25 character screen */
/* This feels like a good default mode for this game */
#ifdef __AGON_COLORIZED__

#ifndef VIDEO_MODE
#error "Agon video mode not defined while __AGON_COLORIZED__ requested, use -DVIDEO_MODE=N"
#endif

#if VIDEO_MODE > 5
#error "Agon video mode number defined in -DVIDEO_MODE=.. is unsupported"
#endif

#if VIDEO_MODE == 0 || VIDEO_MODE == 3
#define TERM_COLOR_MODE "hicolor"
#define TERM_COLOR_HEADER 6
#define TERM_COLOR_DIALOG 7
#define TERM_COLOR_SCENE 3
#define TERM_COLOR_ERROR 1
#endif

#if VIDEO_MODE == 1 || VIDEO_MODE == 4
#define TERM_COLOR_MODE "lowcolor"
#define TERM_COLOR_HEADER 3
#define TERM_COLOR_DIALOG 3
#define TERM_COLOR_SCENE 2
#define TERM_COLOR_ERROR 1
#endif

#if VIDEO_MODE == 2 || VIDEO_MODE == 5
#define TERM_COLOR_MODE "monochrome"
#define TERM_COLOR_HEADER 1
#define TERM_COLOR_DIALOG 1
#define TERM_COLOR_SCENE 1
#define TERM_COLOR_ERROR 1
#endif

#endif /* __AGON_COLORIZED__ */
