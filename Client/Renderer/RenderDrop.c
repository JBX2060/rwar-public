#include <Client/Renderer/ComponentRender.h>

#include <math.h>

#include <Client/Game.h>
#include <Client/Assets/RenderFunctions.h>
#include <Client/Renderer/Renderer.h>
#include <Client/Simulation.h>

void rr_component_drop_render(EntityIdx entity, struct rr_game *game, struct rr_simulation *simulation)
{
    struct rr_renderer *renderer = game->renderer;
    struct rr_component_physical *physical =
        rr_simulation_get_physical(simulation, entity);
    struct rr_component_drop *drop = rr_simulation_get_drop(simulation, entity);
    if (physical->deletion_type == 2)
    {
        struct rr_component_player_info *player_info = game->player_info;
        rr_renderer_translate(
            renderer,
            (player_info->lerp_camera_x - physical->lerp_x) *
                physical->deletion_animation,
            (player_info->lerp_camera_y - physical->lerp_y) *
                physical->deletion_animation);
    }
    rr_renderer_rotate(renderer,
                       physical->lerp_angle + physical->lerp_radius * 0.3125);
    rr_renderer_scale(renderer, 1 - physical->deletion_animation);
    rr_renderer_scale(renderer, physical->lerp_radius * 0.04);
    rr_renderer_scale(renderer, 1 + sinf(physical->animation_timer * 0.1) * 0.05);
    rr_renderer_draw_background(renderer, drop->rarity, 1);
    rr_renderer_draw_petal_with_name(renderer, drop->id,
                                             drop->rarity);
    // rr_renderer_render_static_petal(renderer, drop->id, drop->rarity);
}