#include <Server/Simulation.h>

#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include <Server/EntityAllocation.h>
#include <Server/EntityDetection.h>
#include <Server/SpatialHash.h>
#include <Server/System/System.h>
#include <Server/Waves.h>
#include <Shared/Bitset.h>
#include <Shared/Crypto.h>
#include <Shared/Utilities.h>
#include <Shared/pb.h>
#include <curl/curl.h>
#define LOOP_COUNT 5             // Number of times to loop over the zones

static float last_special_spawn_time = 0.0f;
static const float SPECIAL_SPAWN_INTERVAL = 6 * 3600;
static void send_discord_notification(const char *position)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
    
}



static void set_respawn_zone(struct rr_component_arena *arena, uint32_t x,
                             uint32_t y)
{
    float dim = arena->maze->grid_size;
    arena->respawn_zone.x = 2 * x * dim;
    arena->respawn_zone.y = 2 * y * dim;
}

#define SPAWN_ZONE_X 6
#define SPAWN_ZONE_Y 13

static void set_special_zone(struct rr_component_arena *arena, uint8_t (*fun)(), uint32_t x,
                             uint32_t y, uint32_t w, uint32_t h)
{
    x *= 2;
    y *= 2;
    w *= 2;
    h *= 2;
    uint32_t dim = arena->maze->maze_dim;

    for (uint32_t Y = 0; Y < h; ++Y)
        for (uint32_t X = 0; X < w; ++X) {
            uint32_t indexY = Y + y;
            uint32_t indexX = X + x;
            if (indexY >= dim || indexX >= dim)
                continue; // Skip if out of bounds
            arena->maze->maze[indexY * dim + indexX].spawn_function = fun;
        }
}

uint8_t pter_meteor_zone()
{
    return rr_frand() > 0.02 ? rr_mob_id_pteranodon : rr_mob_id_meteor;
}
uint8_t anky_dako_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_ankylosaurus : rr_mob_id_dakotaraptor;
}
uint8_t edmo_dako_zone()
{
    return rr_frand() > 0.33 ? rr_mob_id_dakotaraptor : rr_mob_id_edmontosaurus;
}

uint8_t dako_tric_zone()
{
    return rr_frand() > 0.2 ? rr_mob_id_dakotaraptor : rr_mob_id_triceratops;
}
uint8_t anky_quetz_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_ankylosaurus : rr_mob_id_quetzalcoatlus;
}
uint8_t ornith_pachy_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_ornithomimus : rr_mob_id_pachycephalosaurus;
}
uint8_t anky_tree_zone()
{
    return rr_frand() > 0.05 ? rr_mob_id_ankylosaurus : rr_mob_id_tree;
}
uint8_t hornet_bee_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_hornet : rr_mob_id_honeybee;
}
uint8_t hornet_dragon_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_hornet : rr_mob_id_dragonfly;
}
uint8_t hornet_ant_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_hornet : rr_mob_id_ant;
}
uint8_t pter_quetz_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_quetzalcoatlus : rr_mob_id_pteranodon;
}
uint8_t dako_pachy_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_dakotaraptor : rr_mob_id_pachycephalosaurus;
}
uint8_t fern_tric_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_fern : rr_mob_id_triceratops;
}
uint8_t fern_ornith_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_fern : rr_mob_id_ornithomimus;
}
uint8_t pter_pachy_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_pteranodon : rr_mob_id_pachycephalosaurus;
}
uint8_t dako_edmo_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_dakotaraptor : rr_mob_id_edmontosaurus;
}
uint8_t pachy_tree_zone()
{
    return rr_frand() > 0.2 ? rr_mob_id_pachycephalosaurus : rr_mob_id_tree;
}
uint8_t quetz_ornith_zone()
{
    return rr_frand() > 0.5 ? rr_mob_id_quetzalcoatlus : rr_mob_id_ornithomimus;
}
uint8_t trex_zone() { return rr_mob_id_trex; }
uint8_t fern_zone() { return rr_mob_id_fern; }
uint8_t pter_zone() { return rr_mob_id_pteranodon; }
uint8_t hornet_zone() { return rr_mob_id_hornet; }
uint8_t dako_zone() { return rr_mob_id_dakotaraptor; }
uint8_t pecti_zone() { return rr_mob_id_pectinodon; }
uint8_t edmo_zone() { return rr_mob_id_edmontosaurus; }
uint8_t anky_zone() { return rr_mob_id_ankylosaurus; }

struct zone
{
    uint32_t x;
    uint32_t y;
    uint32_t w;
    uint32_t h;
    uint8_t (*spawn_func)();
};

#define ROT_COUNT 7
#define PERMA_ZONE_POSITION_COUNT 2



static struct zone zone_positions_hell_creek[] = {
    {32, 30, 5, 3, fern_ornith_zone},     {37, 37, 4, 4, trex_zone},
    {29, 33, 3, 3, fern_zone},            {26, 35, 3, 3, pter_meteor_zone},
    {33, 20, 4, 2, anky_tree_zone},       {34, 36, 3, 3, anky_quetz_zone},
    {37, 12, 3, 3, pter_pachy_zone},      {33, 13, 2, 2, pecti_zone},
    {32, 18, 3, 3, dako_tric_zone},       {32, 1, 3, 3, pter_meteor_zone},
    {18, 22, 5, 3, edmo_zone},            {25, 10, 3, 2, pter_meteor_zone},           {26, 35, 3, 3, pter_meteor_zone},
    {22, 4, 2, 2, ornith_pachy_zone},     {18, 11, 3, 4, dako_zone},
    {12, 14, 4, 4, dako_edmo_zone},       {16, 38, 3, 3, pachy_tree_zone},
    {16, 19, 3, 3, anky_zone},            {0, 12, 3, 3, fern_tric_zone},
    {2, 9, 3, 3, trex_zone},              {1, 22, 3, 4, edmo_zone},
    {1, 33, 5, 4, quetz_ornith_zone},
};

#define ZONE_POSITION_COUNT (sizeof(zone_positions_hell_creek) / sizeof(struct zone))

static struct zone zone_positions_garden[ZONE_POSITION_COUNT] = {
    {29, 3, 4, 2, hornet_bee_zone},      {20, 6, 2, 2, hornet_dragon_zone},
    {23, 30, 4, 2, hornet_ant_zone}
};



static void set_spawn_zones(struct rr_component_arena *arena) {
    puts("Refreshing spawn zones");
    struct timeval t;
    gettimeofday(&t, NULL);
    int64_t time = (t.tv_sec * 1000000 + t.tv_usec) / (1000 * 1000 * 60 * 30);

    uint64_t seed = rr_get_hash(time);

    printf("Initializing Hell Creek zones:\n");

    // Loop through the zones
    for (int loop = 0; loop < LOOP_COUNT; loop++) {
        printf("Loop %d:\n", loop + 1);
        for (uint64_t i = 0; i < ZONE_POSITION_COUNT; i++) {
            struct zone zone = zone_positions_hell_creek[i];

            // Activate the zone
            set_special_zone(arena, zone.spawn_func, zone.x, zone.y, zone.w, zone.h);
        }
    }

    puts("Finished initializing and activating all spawn zones.");
}

struct too_close_captures
{
    struct rr_simulation *simulation;
    float x;
    float y;
    float closest_dist;
    uint8_t done;
};

static void too_close_cb(EntityIdx potential, void *_captures)
{
    struct too_close_captures *captures = _captures;
    if (captures->done)
        return;
    struct rr_simulation *simulation = captures->simulation;
    if (!rr_simulation_has_mob(simulation, potential) &&
            !rr_simulation_has_flower(simulation, potential) ||
        rr_simulation_has_arena(simulation, potential))
        return;
    if (rr_simulation_get_relations(simulation, potential)->team ==
        rr_simulation_team_id_mobs)
        return;
    if (rr_simulation_get_health(simulation, potential)->health == 0)
        return;
    struct rr_component_physical *t_physical =
        rr_simulation_get_physical(simulation, potential);
    struct rr_vector delta = {captures->x - t_physical->x,
                              captures->y - t_physical->y};
    float dist = rr_vector_get_magnitude(&delta);
    if (dist > captures->closest_dist)
        return;
    captures->done = 1;
}

static int too_close(struct rr_simulation *this, float x, float y, float r)
{
    struct too_close_captures shg_captures = {this, x, y, r, 0};
    struct rr_spatial_hash *shg =
        &rr_simulation_get_arena(this, 1)->spatial_hash;
    rr_spatial_hash_query(shg, x, y, r, r, &shg_captures, too_close_cb);
    return shg_captures.done;
}


static void spawn_special_startup_mob(struct rr_simulation *this)
{
    struct rr_component_arena *arena = rr_simulation_get_arena(this, 1);

    uint32_t x, y;

    uint8_t id = rr_frand() > 0.5 ? rr_mob_id_fern : rr_mob_id_pectinodon;
    uint8_t rarity = rr_rarity_id_eternal;

    if (id == rr_mob_id_fern) {
        x = 16;
        y = 3;
    } else {
        x = 79;
        y = 9;
    }

    float grid_size = arena->maze->grid_size;
    struct rr_vector pos = {
        x * grid_size,
        y * grid_size
    };

    EntityIdx mob_id = rr_simulation_alloc_mob(
        this, 1, pos.x, pos.y, id, rarity, rr_simulation_team_id_mobs);

    struct rr_maze_grid *grid = rr_component_arena_get_grid(arena, x, y);
    rr_simulation_get_mob(this, mob_id)->zone = grid;
    grid->grid_points += RR_MOB_DATA[id].danger;
    grid->spawn_timer = 0;

    const char* mob_name = (id == rr_mob_id_fern) ? "Fern" : "Pectinodon";
    printf("%s  spawned at (%d, %d)\n", mob_name, x, y);
    char notification_msg[256];
    snprintf(notification_msg, sizeof(notification_msg), "%s spawned at (%d, %d)", mob_name, x, y);
    send_discord_notification(notification_msg);
}


void rr_simulation_init(struct rr_simulation *this)
{
    if (this == NULL) {
        // Log the error and return early
        fprintf(stderr, "Error: rr_simulation pointer is NULL\n");
        return;
    }

    memset(this, 0, sizeof *this);
    EntityIdx id = rr_simulation_alloc_entity(this);
    struct rr_component_arena *arena = rr_simulation_add_arena(this, id);
    arena->biome = RR_GLOBAL_BIOME;
    rr_component_arena_spatial_hash_init(arena, this);
    set_respawn_zone(arena, SPAWN_ZONE_X, SPAWN_ZONE_Y);
    set_spawn_zones(arena);
    // spawn_special_startup_mob(this);

    struct timeval t;
    gettimeofday(&t, NULL);
    last_special_spawn_time = (t.tv_sec * 1000000 + t.tv_usec) / 1000000.0f;
}
static void spawn_mob(struct rr_simulation *this, uint32_t grid_x,
                      uint32_t grid_y)
{
    struct rr_component_arena *arena = rr_simulation_get_arena(this, 1);
    struct rr_maze_grid *grid =
        rr_component_arena_get_grid(arena, grid_x, grid_y);
    uint8_t id;

    if (grid->spawn_function != NULL && rr_frand() <
                                            0.75
    )
        id = grid->spawn_function();
    else
        id = get_spawn_id(RR_GLOBAL_BIOME, grid);
    uint8_t rarity =
        get_spawn_rarity(grid->difficulty + grid->local_difficulty * 0.6);
    if (!should_spawn_at(id, rarity))
        return;
    for (uint32_t n = 0; n < 10; ++n)
    {
        struct rr_vector pos = {(grid_x + rr_frand()) * arena->maze->grid_size,
                                (grid_y + rr_frand()) * arena->maze->grid_size};
        if (too_close(this, pos.x, pos.y,
                      RR_MOB_DATA[id].radius *
                              RR_MOB_RARITY_SCALING[rarity].radius +
                          750))
            continue;
        EntityIdx mob_id = rr_simulation_alloc_mob(
            this, 1, pos.x, pos.y, id, rarity, rr_simulation_team_id_mobs);
        rr_simulation_get_mob(this, mob_id)->zone = grid;
        grid->grid_points += RR_MOB_DATA[id].danger * RR_MOB_RARITY_DIFFICULTY_COEFFICIENTS[rarity];
        grid->spawn_timer = 0;
        break;
    }
}

#define PLAYER_COUNT_CAP (12)

static void count_flower_vicinity(EntityIdx entity, void *_simulation)
{
    struct rr_simulation *this = _simulation;
    struct rr_component_arena *arena = rr_simulation_get_arena(this, 1);
    struct rr_component_physical *physical =
        rr_simulation_get_physical(this, entity);
#ifdef RIVET_BUILD
#define FOV 3072
#else
#define FOV 4096
#endif
    uint32_t sx = rr_fclamp((physical->x - FOV) / arena->maze->grid_size, 0,
                            arena->maze->maze_dim - 1);
    uint32_t sy = rr_fclamp((physical->y - FOV) / arena->maze->grid_size, 0,
                            arena->maze->maze_dim - 1);
    uint32_t ex = rr_fclamp((physical->x + FOV) / arena->maze->grid_size, 0,
                            arena->maze->maze_dim - 1);
    uint32_t ey = rr_fclamp((physical->y + FOV) / arena->maze->grid_size, 0,
                            arena->maze->maze_dim - 1);
#undef FOV
    uint32_t level = rr_simulation_get_flower(_simulation, entity)->level;
    for (uint32_t x = sx; x <= ex; ++x)
        for (uint32_t y = sy; y <= ey; ++y)
        {
            struct rr_maze_grid *grid =
                rr_component_arena_get_grid(arena, x, y);
            grid->player_count += grid->player_count < PLAYER_COUNT_CAP;
            grid->local_difficulty +=
                rr_fclamp((level - (grid->difficulty - 1) * 2.1) / 10, -1, 1);
        }
}

static void despawn_mob(EntityIdx entity, void *_simulation)
{
    struct rr_simulation *this = _simulation;
    struct rr_component_physical *physical =
        rr_simulation_get_physical(this, entity);
    if (physical->arena != 1)
        return;
    if (rr_simulation_has_arena(this, entity))
        return;

    struct rr_component_arena *arena = rr_simulation_get_arena(this, 1);
    struct rr_component_mob *mob = rr_simulation_get_mob(this, entity);
    struct rr_component_ai *ai = rr_simulation_get_ai(this, entity);
    if (mob->rarity == rr_rarity_id_ultimate)
        return;
    if (mob->rarity == rr_rarity_id_eternal)
        return;
    if (rr_component_arena_get_grid(
            arena,
            rr_fclamp(physical->x / arena->maze->grid_size, 0,
                      arena->maze->maze_dim - 1),
            rr_fclamp(physical->y / arena->maze->grid_size, 0,
                      arena->maze->maze_dim - 1))
            ->player_count == 0)
    {
        if (mob->ticks_to_despawn > 30 * 25)
            mob->ticks_to_despawn = 30 * 25;
        if (--mob->ticks_to_despawn == 0)
        {
            mob->no_drop = 1;
            rr_simulation_request_entity_deletion(this, entity);
        }
    }
    else
        mob->ticks_to_despawn = 30 * 25;
    if (mob->force_despawn && (mob->id == rr_mob_id_ornithomimus ||
        ai->ai_state == rr_ai_state_idle || ai->ai_state == rr_ai_state_idle_moving))
    {
        if (--mob->ticks_to_force_despawn == 0)
        {
            mob->no_drop = 1;
            rr_simulation_request_entity_deletion(this, entity);
        }
    }
}
static float get_max_points(struct rr_maze_grid *grid)
{
    return 1.35 * (0.2 + (grid->player_count) * 1.2) *
           powf(1.1, grid->overload_factor);
}
static int tick_grid(struct rr_simulation *this, struct rr_maze_grid *grid,
                     uint32_t grid_x, uint32_t grid_y)
{
    if (grid->value == 0 || (grid->value & 8))
        return 0;
    grid->local_difficulty =
        rr_fclamp(grid->local_difficulty, -0.5, PLAYER_COUNT_CAP);
    if (grid->local_difficulty > 0)
    {
        grid->overload_factor = rr_fclamp(
            grid->overload_factor + 0.005 * grid->local_difficulty / 25, 0,
            1.5 * grid->local_difficulty);
    }
    else
    {
        grid->overload_factor = rr_fclamp(grid->overload_factor - 0.025 / 25, 0,
                                          grid->overload_factor);
    }
    float player_modifier = 1 + grid->player_count * 4.0 / 3;
    float difficulty_modifier = 150 + 3 * grid->difficulty;
    float overload_modifier = powf(1.2, grid->local_difficulty + grid->overload_factor);
    float max_points = get_max_points(grid);
    if (grid->grid_points >= max_points)
        return 0;
    float base_modifier = (max_points) / (max_points - grid->grid_points);
    float spawn_at = base_modifier * difficulty_modifier * overload_modifier /
                     (player_modifier);
    if (grid->player_count == 0)
    {
        grid->overload_factor =
            rr_fclamp(grid->overload_factor - 0.025 / 25, 0, 15);
        grid->spawn_timer = rr_frand() * 0.75 * spawn_at;
    }
    else if (grid->spawn_timer >= spawn_at)
    {
        spawn_mob(this, grid_x, grid_y);
        return 1;
    }
    else
        ++grid->spawn_timer;
    return 0;
}

static void tick_maze(struct rr_simulation *this)
{
    struct rr_component_arena *arena = rr_simulation_get_arena(this, 1);
    for (uint32_t i = 0; i < arena->maze->maze_dim * arena->maze->maze_dim; ++i)
        arena->maze->maze[i].local_difficulty =
            arena->maze->maze[i].player_count = 0;

    rr_simulation_for_each_flower(this, this, count_flower_vicinity);
    rr_simulation_for_each_mob(this, this, despawn_mob);
    for (uint32_t grid_x = 0; grid_x < arena->maze->maze_dim; grid_x += 2)
    {
        for (uint32_t grid_y = 0; grid_y < arena->maze->maze_dim; grid_y += 2)
        {
            struct rr_maze_grid *nw =
                rr_component_arena_get_grid(arena, grid_x, grid_y);
            struct rr_maze_grid *ne =
                rr_component_arena_get_grid(arena, grid_x + 1, grid_y);
            struct rr_maze_grid *sw =
                rr_component_arena_get_grid(arena, grid_x, grid_y + 1);
            struct rr_maze_grid *se =
                rr_component_arena_get_grid(arena, grid_x + 1, grid_y + 1);
            float max_overall = get_max_points(nw) + get_max_points(ne) +
                                get_max_points(sw) + get_max_points(se);
            if (nw->grid_points + ne->grid_points + sw->grid_points +
                    se->grid_points >
                max_overall)
                continue;
            if (tick_grid(this, nw, grid_x, grid_y))
                continue;
            if (tick_grid(this, ne, grid_x + 1, grid_y))
                continue;
            if (tick_grid(this, sw, grid_x, grid_y + 1))
                continue;
            if (tick_grid(this, se, grid_x + 1, grid_y + 1))
                continue;
        }
    }
}

#define RR_TIME_BLOCK_(_, CODE)                                                \
    {                                                                          \
        struct timeval start;                                                  \
        struct timeval end;                                                    \
        gettimeofday(&start, NULL);                                            \
        CODE;                                                                  \
        gettimeofday(&end, NULL);                                              \
        uint64_t elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 +        \
                                (end.tv_usec - start.tv_usec);                 \
        if (elapsed_time > 3000)                                               \
        {                                                                      \
            printf(_ " took %lu microseconds with %d entities\n",              \
                   elapsed_time, this->physical_count);                        \
        }                                                                      \
    };

#define RR_TIME_BLOCK(_, CODE)                                                 \
    {                                                                          \
        CODE;                                                                  \
    };

static int64_t last_zone_epoch = -1;
void rr_simulation_tick(struct rr_simulation *this)
{
    struct rr_component_arena *arena = rr_simulation_get_arena(this, 1); 
    
    struct timeval t;
    gettimeofday(&t, NULL);
    float current_time = (t.tv_sec * 1000000 + t.tv_usec) / 1000000.0f;

    int64_t time = (t.tv_sec * 1000000 + t.tv_usec);
    int64_t current_zone_epoch = time / (1000 * 1000 * 60 * 30);

    if (current_zone_epoch != last_zone_epoch) {
        set_spawn_zones(arena); 
        last_zone_epoch = current_zone_epoch;
    }

    // if (current_time - last_special_spawn_time >= SPECIAL_SPAWN_INTERVAL) {
    //     spawn_special_startup_mob(this);
    //     last_special_spawn_time = current_time;
    // }
    rr_simulation_create_component_vectors(this);
    RR_TIME_BLOCK("collision_detection",
                  { rr_system_collision_detection_tick(this); });
    RR_TIME_BLOCK("ai", { rr_system_ai_tick(this); });
    RR_TIME_BLOCK("drops", { rr_system_drops_tick(this); });
    RR_TIME_BLOCK("petal_behavior", { rr_system_petal_behavior_tick(this); });
    RR_TIME_BLOCK("collision_resolution",
                  { rr_system_collision_resolution_tick(this); });
    RR_TIME_BLOCK("web", { rr_system_web_tick(this); });
    RR_TIME_BLOCK("velocity", { rr_system_velocity_tick(this); });
    RR_TIME_BLOCK("centipede", { rr_system_centipede_tick(this); });
    RR_TIME_BLOCK("health", { rr_system_health_tick(this); });
    RR_TIME_BLOCK("camera", { rr_system_camera_tick(this); });
    RR_TIME_BLOCK("spawn_tick", { tick_maze(this); });
    memcpy(this->deleted_last_tick, this->pending_deletions,
           sizeof this->pending_deletions);
    memset(this->pending_deletions, 0, sizeof this->pending_deletions);
    RR_TIME_BLOCK("free_component", {
        rr_bitset_for_each_bit(
            this->deleted_last_tick,
            this->deleted_last_tick + (RR_BITSET_ROUND(RR_MAX_ENTITY_COUNT)),
            this, __rr_simulation_pending_deletion_free_components);
    });
    RR_TIME_BLOCK("unset_entity", {
        rr_bitset_for_each_bit(
            this->deleted_last_tick,
            this->deleted_last_tick + RR_BITSET_ROUND(RR_MAX_ENTITY_COUNT),
            this, __rr_simulation_pending_deletion_unset_entity);
    });
}

int rr_simulation_entity_alive(struct rr_simulation *this, EntityHash hash)
{
    return this->entity_tracker[(EntityIdx)hash] &&
           this->entity_hash_tracker[(EntityIdx)hash] == (hash >> 16) &&
           !rr_bitset_get(this->deleted_last_tick, (EntityIdx)hash);
}

EntityHash rr_simulation_get_entity_hash(struct rr_simulation *this,
                                         EntityIdx id)
{
    return ((uint32_t)(this->entity_hash_tracker[id]) << 16) | id;
}
