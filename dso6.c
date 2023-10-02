/* GHERE--	IS GLOBAL ACTUALLY IN THIS ROOM? */

/*COPYRIGHT 1980, INFOCOM COMPUTERS AND COMMUNICATIONS, CAMBRIDGE MA. 02142*/
/* ALL RIGHTS RESERVED, COMMERCIAL USAGE STRICTLY PROHIBITED */
/* WRITTEN BY R. M. SUPNIK */

#include "funcs.h"
#include "vars.h"

logical ghere_(obj, rm)
integer obj;
integer rm;
{
    /* System generated locals */
    logical ret_val;

    ret_val = TRUE_;
/* 						!ASSUME WINS. */
    switch (obj - star_1.strbit) {
        // agon-zork update: switch rewritten with all Gotos internalized
        // this avoids linker issue on legalizing instruction %61:_(s15) = G_AND %59:_, %60:_
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	    /* STARS ARE ALWAYS HERE */
	    return ret_val;
	case 12:
	    /* BIRD */
            ret_val = rm >= rindex_1.fore1 && rm < rindex_1.clear || rm == rindex_1.mtree;
            return ret_val;
	case 13:
	    /* TREE */
	    ret_val = rm >= rindex_1.fore1 && rm < rindex_1.clear && rm != rindex_1.fore3;
	    return ret_val;
	case 14:
	    /* NORTH WALL */
	    ret_val = rm >= rindex_1.bkvw && rm <= rindex_1.bkbox || rm == rindex_1.cpuzz;
	    return ret_val;
	case 15:
	case 16:
	case 17:
	    /* EAST, SOUTH, WEST WALLS */
	    ret_val = rm >= rindex_1.bkvw && rm < rindex_1.bkbox || rm == rindex_1.cpuzz;
	    return ret_val;
	case 18:
	    /* GLOBAL WATER */
	    ret_val = (rooms_1.rflag[rm - 1] & RWATER + RFILL) != 0;
	    return ret_val;
	case 19:
	    /* GLOBAL GUARDIANS */
	    ret_val = rm >= rindex_1.mrc && rm <= rindex_1.mrd || rm >= rindex_1.mrce && rm <= rindex_1.mrdw || rm == rindex_1.inmir;
	    return ret_val;
	case 20:
	case 23:
	    /* ROSE/CHANNEL */
	    ret_val = rm >= rindex_1.mra && rm <= rindex_1.mrd || rm == rindex_1.inmir;
	    return ret_val;
	case 21:
	    /* MIRROR */
	    ret_val = rm >= rindex_1.mra && rm <= rindex_1.mrc || rm >= rindex_1.mrae && rm <= rindex_1.mrcw;
	    return ret_val;
	case 22:
	    /* PANEL */
	    if (rm == rindex_1.fdoor) {
		return ret_val;
            }
	    /* !PANEL AT FDOOR. */
	    ret_val = rm >= rindex_1.mra && rm <= rindex_1.mrc || rm >= rindex_1.mrae && rm <= rindex_1.mrcw;
	    return ret_val;

	case 24:
	    /* MASTER */
	    ret_val = rm == rindex_1.fdoor || rm == rindex_1.ncorr || rm == rindex_1.parap || rm == rindex_1.cell;
	    return ret_val;
	case 25:
	    /* LADDER */
	    ret_val = rm == rindex_1.cpuzz;
	    return ret_val;
    }
    bug_(60, obj);
} /* ghere_ */

/* MRHERE--	IS MIRROR HERE? */

/* DECLARATIONS */

integer mrhere_(rm)
integer rm;
{
    /* System generated locals */
    integer ret_val, i__1;

    if (rm < rindex_1.mrae || rm > rindex_1.mrdw) {
	goto L100;
    }

/* RM IS AN E-W ROOM, MIRROR MUST BE N-S (MDIR= 0 OR 180) */

    ret_val = 1;
/* 						!ASSUME MIRROR 1 HERE. */
    if ((rm - rindex_1.mrae) % 2 == findex_1.mdir / 180) {
	ret_val = 2;
    }
    return ret_val;

/* RM IS NORTH OR SOUTH OF MIRROR.  IF MIRROR IS N-S OR NOT */
/* WITHIN ONE ROOM OF RM, LOSE. */

L100:
    ret_val = 0;
    if ((i__1 = findex_1.mloc - rm, abs(i__1)) != 1 || findex_1.mdir % 180 ==
	     0) {
	return ret_val;
    }

/* RM IS WITHIN ONE OF MLOC, AND MDIR IS E-W */

    ret_val = 1;
    if (rm < findex_1.mloc && findex_1.mdir < 180 || rm > findex_1.mloc && 
	    findex_1.mdir > 180) {
	ret_val = 2;
    }
    return ret_val;
} /* mrhere_ */
