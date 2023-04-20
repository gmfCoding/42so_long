
/* FULL TILE QUADRANTS */
#define TILE_FTL 0
#define TILE_FTR 1
#define TILE_FBL 0 + SHEET_WIDTH
#define TILE_FBR 1 + SHEET_WIDTH

/* CORNER QUADRANTS */

#define TILE_CTL 2
#define TILE_CTR 3
#define TILE_CBL 2 + SHEET_WIDTH
#define TILE_CBR 3 + SHEET_WIDTH

/* INVERTED CORNER QUADRANTS */
#define TILE_ITL 4
#define TILE_ITR 5
#define TILE_IBL 4 + SHEET_WIDTH
#define TILE_IBR 5 + SHEET_WIDTH
#define SUB_TILE_COUNT 12

#define SHEET_WIDTH 4
#define SHEET_HEIGHT 4
#define TILE_PX_SCALE 3
#define SUB_RES 16

typedef struct	s_themeinfo
{
	t_texture	*entire;
	t_texture	*subimgs[SUB_TILE_COUNT];

}				t_themeinfo;
t_themeinfo	*loadtheme(t_gamestate *state, const char* themeimg);
