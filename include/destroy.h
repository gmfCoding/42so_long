#ifndef H_DESTROY
# define H_DESTROY

#include "map.h"
#include "state.h"
#include "theme.h"
#include "texture.h"

void	destroy_map(t_map **map);
void	destroy_texture(t_gamestate *gs, t_texture tex);
void	destroy_theme(t_gamestate *gs, t_themeinfo **theme);
void	destroy_state(t_gamestate *state);
#endif
