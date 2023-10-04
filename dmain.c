/* DUNGEON-- MAIN PROGRAM */

/*COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142*/
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

#define EXTERN
#define INIT

#include <stdio.h>
#include "funcs.h"
#include "vars.h"
#include "agon.h"

void main(argc, argv)
int argc;
char **argv;
{
/* 1) INITIALIZE DATA STRUCTURES */
/* 2) PLAY GAME */

    if (init_()) {
#if defined __AGON__ && defined VIDEO_MODE
	vdp_mode(VIDEO_MODE);
#endif
#ifdef __AGON_COLORIZED__
	vdp_set_text_colour(TERM_COLOR_HEADER);
#endif
#ifdef __AGON_HEADER__
	printf("Dungeon/Zork adaptation for Agon Light eZ80, %s video mode.\n", TERM_COLOR_MODE);
#endif
#ifdef __AGON_COLORIZED__
	vdp_set_text_colour(TERM_COLOR_SCENE);
#endif
	game_();
    }
/* 						!IF INIT, PLAY GAME. */
    exit_();
/* 						!DONE */
} /* MAIN__ */
