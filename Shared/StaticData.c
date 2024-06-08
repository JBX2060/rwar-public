#include <Shared/StaticData.h>

#include <math.h>
#include <stdio.h>

#include <Shared/Utilities.h>

// clang-format off
struct rr_petal_base_stat_scale const offensive[rr_rarity_id_max] = {
    {1.2, 1.2},
    {1.7, 2.0},
    {2.9, 4.0},
    {5.0, 8.0},
    {8.5,  16},
    {14.5, 48},
    {24.6,144},
    {42.0,432}
};

struct rr_petal_base_stat_scale const defensive[rr_rarity_id_max] = {
    {1.2, 1.2},
    {2.0, 1.7},
    {4.0, 2.9},
    {8.0, 5.0},
    {16,  8.5},
    {48, 14.5},
    {144,24.6},
    {432,42.0}
};

struct rr_petal_data RR_PETAL_DATA[rr_petal_id_max] = {
    {rr_petal_id_none,      rr_rarity_id_common,    offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0}},
    {rr_petal_id_basic,     rr_rarity_id_common,    offensive, 10.0f,  15.0f,   0.0f,  50,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_pellet,    rr_rarity_id_common,    offensive, 12.5f,   5.0f,   0.0f,  20,  0, {1,2,2,3,3,5,6,6}},
    {rr_petal_id_fossil,    rr_rarity_id_common,    offensive, 10.0f,  60.0f,   0.0f, 100,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_stinger,   rr_rarity_id_common,    offensive, 50.0f,   3.0f,  10.0f, 150,  0, {1,1,1,1,1,3,5,5}},
    {rr_petal_id_light,     rr_rarity_id_rare,      offensive,  5.0f,   5.0f,  15.0f,  20,  0, {1,1,1,1,1,2,3,3}},
    {rr_petal_id_shell,     rr_rarity_id_rare,      offensive, 32.0f,  12.0f,   0.0f,  75, 13, {1,1,1,1,1,2,3,3}},
    {rr_petal_id_peas,      rr_rarity_id_rare,      offensive, 15.0f,   8.0f,   8.0f,  13, 12, {4,4,4,4,4,4,5,5}},
    {rr_petal_id_leaf,      rr_rarity_id_unusual,   offensive,  9.0f,  15.0f,   8.0f,  38,  0, {1,1,1,1,1,2,2,2}},
    {rr_petal_id_egg,       rr_rarity_id_unusual,   defensive,  1.0f,  20.0f,   0.0f,  35, 200, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_magnet,    rr_rarity_id_rare,      defensive,  2.0f,  15.0f,   0.0f,  38,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_uranium,   rr_rarity_id_legendary, offensive, 4.0f,  10.0f,   0.0f,  50, 25, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_feather,   rr_rarity_id_common,    defensive,  1.0f,   3.0f,   0.0f,  25,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_azalea,    rr_rarity_id_common,    defensive,  5.0f,  10.0f,   0.0f,  50, 25, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_bone,      rr_rarity_id_common,    defensive,  2.5f,  25.0f,   0.0f,  68,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_web,       rr_rarity_id_rare,      defensive,  5.0f,   5.0f,   0.0f,  50, 13, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_seed,      rr_rarity_id_rare,      defensive,  1.0f,  25.0f,   0.0f,  63,  1, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_gravel,    rr_rarity_id_unusual,   offensive, 12.0f,   5.0f,   0.0f,  20, 13, {1,2,2,2,3,3,4,4}},
    {rr_petal_id_club,      rr_rarity_id_common,    defensive,  8.0f, 300.0f,   0.0f, 200,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_crest,     rr_rarity_id_rare,      offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0}},
    {rr_petal_id_droplet,   rr_rarity_id_common,    offensive, 15.0f,   5.0f,   0.0f,  37,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_beak,      rr_rarity_id_unusual,   offensive,  5.0f,   5.0f,   0.0f,  55,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_lightning, rr_rarity_id_unusual,   offensive, 10.0f,   1.0f,   0.0f,  67,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_third_eye, rr_rarity_id_legendary, offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0}},
    {rr_petal_id_mandible,  rr_rarity_id_common,    offensive,  5.0f,  10.0f,   0.0f,  75,  0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_wax,       rr_rarity_id_unusual,   offensive,  5.0f,  10.0f,  10.0f,  75,  0, {2,2,2,2,2,2,2,2}},
    {rr_petal_id_sand,      rr_rarity_id_common,    offensive, 15.0f,  10.0f,  10.0f,  37,  0, {4,4,4,4,4,4,4,4}},
    {rr_petal_id_mint,      rr_rarity_id_unusual,   offensive,  5.0f,  10.0f,  10.0f,  50, 25, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_stick,      rr_rarity_id_unusual, defensive,  5.0f,  15.0f,  10.0f,  35,  0, {1,1,1,1,1,1,2,3}},
    {rr_petal_id_missle,      rr_rarity_id_unusual, defensive,  5.0f,  15.0f,  10.0f,  35,  0, {1,1,1,1,1,1,2,3}},
    {rr_petal_id_cactus,      rr_rarity_id_unusual, defensive,  5.0f,  15.0f,  10.0f,  35,  0, {1,1,1,1,1,1,2,3}},
    {rr_petal_id_gold,      rr_rarity_id_unusual,   offensive,  22.5f, 135.0f, 10.0f,  115, 0, {1,1,1,1,1,1,1,1}},
    {rr_petal_id_rice,      rr_rarity_id_common,    offensive,  1.0f,  0.5f,   0.0f,   10,  0, {1,1,1,1,1,1,1,3}},
    {rr_petal_id_horn,      rr_rarity_id_common,    offensive,  5.0f,  18.0f,  0.0f,   65,  0, {1,1,1,1,1,1,1,3}},

};    

char const *RR_PETAL_NAMES[rr_petal_id_max] = {
    "Secret", "Petal", "Pellet", "Fossil",   "Stinger",  "Berries", "Shell",
    "Peas",   "Leaf",  "Egg",    "Magnet", "Uranium", "Feather", "Azalea",
    "Bone",   "Web",   "Seed",   "Gravel", "Club", "Crest", "Droplet",
    "Beak", "Lightning", "Third Eye", "Mandible", "Wax", "Sand", "Mint", "Cactus", "Gold", "Rice", "Horn"};
    
char const *RR_PETAL_DESCRIPTIONS[rr_petal_id_max] = {
    0,
    "It's just a petal",
    "Low damage, but there's lots",
    "It came from a dino",
    "Ow that hurts",
    "Gives your other petals more energy",
    "Poor snail",
    "Splits in 4. Or maybe 5 if you're a pro",
    "Heals you gradually",
    "Spawns a pet dinosaur to protect you",
    "Increases loot pickup radius. Does not stack",
    "Does low damage to mobs in a small range",
    "It's so light it increases your movement speed. Stacks diminishingly",
    "It heals you",
    "Gives the player armor. Does not stack.",
    "It slows everything down",
    "What does this one do",
    "Tiny rocks that stay on the ground and trip dinos",
    "Heavy and sturdy",
    "Increases your vision range. Does not stack",
    "This mysterious petal reverses your petal rotation",
    "Stuns mobs and prevents them from moving",
    "A stunning display",
    "Your petals hate it and want to move further away",
    "Does more damage if target hp is below 50%",
    "Made by the bees",
    "Very fine",
    "Remember to feed your pets",
    "",
    "",
    "Ouch! Prickly hug. Stacks diminishingly.",
    "A beacon of wealth.",
    "Highest DPS in the game, If you know how to use it.",
    "Give it back!"
};

struct rr_mob_data RR_MOB_DATA[rr_mob_id_max] = {
    // Hell Creek mobs
    {rr_mob_id_triceratops,        rr_rarity_id_epic, rr_rarity_id_ultimate,  45, 15, 30.0f, {{rr_petal_id_leaf,    0.15},{rr_petal_id_fossil,    0.05}}},
    {rr_mob_id_trex,               rr_rarity_id_epic, rr_rarity_id_ultimate,  40, 25, 32.0f, {{rr_petal_id_stinger, 0.05},{rr_petal_id_egg,       0.05}}},
    {rr_mob_id_fern,               rr_rarity_id_common, rr_rarity_id_ultimate,  10,  5, 24.0f, {{rr_petal_id_leaf,     0.1},{rr_petal_id_azalea,    0.25}}},
    {rr_mob_id_tree,               rr_rarity_id_common, rr_rarity_id_ultimate, 100,  5, 64.0f, {{rr_petal_id_leaf,     0.5},{rr_petal_id_peas,      0.25},{rr_petal_id_seed,       0.10}}},
    {rr_mob_id_pteranodon,         rr_rarity_id_epic, rr_rarity_id_ultimate,  40, 15, 20.0f, {{rr_petal_id_shell,  0.1},{rr_petal_id_beak,      0.15}}},
    {rr_mob_id_dakotaraptor,       rr_rarity_id_common, rr_rarity_id_ultimate,  35, 10, 25.0f, {{rr_petal_id_crest,    0.1},{rr_petal_id_feather,    0.1},{rr_petal_id_pellet,    0.05}}},
    {rr_mob_id_pachycephalosaurus, rr_rarity_id_common, rr_rarity_id_ultimate,  35, 20, 20.0f, {{rr_petal_id_fossil,   0.1},{rr_petal_id_light,      0.1},{rr_petal_id_web,       0.05}}},
    {rr_mob_id_ornithomimus,       rr_rarity_id_common, rr_rarity_id_ultimate,  25, 10, 20.0f, {{rr_petal_id_feather,  0.1},{rr_petal_id_droplet,   0.05},{rr_petal_id_pellet,     0.1}}},
    {rr_mob_id_ankylosaurus,       rr_rarity_id_epic,   rr_rarity_id_ultimate,  50, 10, 30.0f, {{rr_petal_id_club,    0.15},{rr_petal_id_gravel,     0.1}}},
    {rr_mob_id_meteor,             rr_rarity_id_common, rr_rarity_id_ultimate, 100, 10, 32.0f, {{rr_petal_id_magnet,   0.65},{rr_petal_id_uranium, 0.25}}},
    {rr_mob_id_quetzalcoatlus,     rr_rarity_id_epic, rr_rarity_id_ultimate,  65, 20, 28.0f, {{rr_petal_id_beak,    0.05},{rr_petal_id_fossil,     0.1},{rr_petal_id_lightning, 0.15}}},
    {rr_mob_id_edmontosaurus,      rr_rarity_id_epic,   rr_rarity_id_ultimate,  50, 15, 30.0f, {{rr_petal_id_bone,   0.005},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.08}}},

    // Garden mobs
    {rr_mob_id_ant,                rr_rarity_id_common, rr_rarity_id_ultimate,  42, 12, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    {rr_mob_id_hornet,             rr_rarity_id_common, rr_rarity_id_ultimate,  40, 10, 35.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    {rr_mob_id_dragonfly,          rr_rarity_id_common, rr_rarity_id_ultimate,  50, 15, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    {rr_mob_id_honeybee,           rr_rarity_id_common, rr_rarity_id_ultimate,  25, 20, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    {rr_mob_id_beehive,            rr_rarity_id_common, rr_rarity_id_ultimate,  500, 0, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    {rr_mob_id_spider,             rr_rarity_id_common, rr_rarity_id_ultimate,  42, 13, 32.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    {rr_mob_id_house_centipede,    rr_rarity_id_common, rr_rarity_id_ultimate,  50, 15, 40.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    // {rr_mob_id_lanternfly,         rr_rarity_id_common, rr_rarity_id_ultimate,  45, 13, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    
    // Ocean mobs
    {rr_mob_id_kelp,            rr_rarity_id_common, rr_rarity_id_ultimate,  50, 15, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.09}}},
    {rr_mob_id_seagull,         rr_rarity_id_common, rr_rarity_id_ultimate,  50, 15, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.10}}},
    {rr_mob_id_kingmackarel,    rr_rarity_id_common, rr_rarity_id_ultimate,  50, 15, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.10}}},
    {rr_mob_id_seasnail,        rr_rarity_id_common, rr_rarity_id_ultimate,  50, 15, 30.0f, {{rr_petal_id_bone,    0.15},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},

    // Portals
    {rr_mob_id_portal_garden,      rr_rarity_id_common, rr_rarity_id_ultimate,   500, 0, 30.0f, {}},
    {rr_mob_id_portal_ocean,       rr_rarity_id_common, rr_rarity_id_ultimate,   500, 0, 30.0f, {}},
    {rr_mob_id_portal_hell_creek,  rr_rarity_id_common, rr_rarity_id_ultimate,   500, 0, 30.0f, {}},
};

char const *RR_MOB_NAMES[rr_mob_id_max] = {
"Triceratops","T-Rex","Fern","Tree","Pteranodon","Dakotaraptor",
"Pachycephalosaurus","Ornithomimus","Ankylosaurus","Meteor",
"Quetzalcoatlus","Edmontosaurus","Ant","Hornet","Dragonfly",
"Honeybee","Beehive","Spider","House Centipede",
"Kelp","Seagull","King Mackarel","Sea Snail",
"Garden Portal", "Ocean Portal", "Hell Creek Portal"
};

uint32_t RR_MOB_DIFFICULTY_COEFFICIENTS[rr_mob_id_max] = {
    3, //tric
    4, //trex
    1, //fern
    2.15, //tree
    5, //pter
    5, //dako
    3, //pachy
    2, //ornith
    4, //anky
    1, //meteor
    5, //quetz
    3, //edmo
    4, // beehive
    2, // ant
    3, // spider
    4, // honeybee
    1, // dragonfly
    5, // hornet
    2, // house centipede

    1, // kelp
    3, // seagull
    4, // king mackarel
    1, // sea snail
};

double RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {
    50,   //tric
    100,  //trex
    15,   //fern
    0.50, //tree
    75,   //pter
    50,   //dako
    25,   //pachy
    40,   //ornith
    25,   //anky
    0.5,  //meteor
    75,   //quetz
    25,   //edmo
};
double RR_OCEAN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {
    0, //tric
    0, //trex
    0, //fern
    0, //tree
    0, //pter
    0, //dako
    0, //pachy
    0, //ornith
    0, //anky
    0, //meteor
    0, //quetz
    0, //edmo
    0, // beehive
    0, // ant
    0, // spider
    0, // honeybee
    0, // dragonfly
    0, // hornet
    0, // house centipede
    0.5, // kelp
    0.5, // seagull
    0.5, // king mackarel
    0.5, // sea snail
};

double RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {
    0, //tric
    0,//trex
    0, //fern
    0,//tree
    0, //pter
    0, //dako
    0, //pachy
    0, //ornith
    0, //anky
    0,//meteor
    0, //quetz
    0,  //edmo
    0.1, // beehive
    25, // ant
    25, // spider
    50, // honeybee
    40, // dragonfly
    50, // hornet
    0.25, // house centipede
};

struct rr_petal_rarity_scale RR_PETAL_RARITY_SCALE[rr_rarity_id_max] = {
    {1,    240, 45,  0.08, 15},
    {1.8,  120, 60,  0.15, 30}, // 15
    {3.5,  60,  75,  0.22, 45}, // 22
    {6.8,  30,  100, 0.30, 60},  // 30
    {12.5, 15,  125, 0.37, 75}, // 37
    {24.5, 7.5, 150, 0.45, 90}, // 45
    {60,   2.5, 200, 0.52, 105}, // 52
    {180,  0.5, 250, 0.60, 120},
};


struct rr_mob_rarity_scale RR_MOB_RARITY_SCALING[rr_rarity_id_max] = {
    {0.5,  0.5,1.0},
    {2.1,  1.3,1.2},
    {6.0,  2.9,1.5}, 
    {14.4, 5.0,2.0},
    {50,   8.5,2.8},
    {180, 13.5,4.0},
    {2560,24.6,5.5},
    {128e3,42.0,7.0}
};
// clang-format on

uint32_t RR_RARITY_COLORS[rr_rarity_id_max] = {
    0xff7ff06d, 0xffffe65d, 0xff4d52e3, 0xff861fde,
    0xffde201f, 0xff21dbde, 0xffff2a75, 0xff30fca4};

char const *RR_RARITY_NAMES[rr_rarity_id_max] = {
    "Common",    "Uncommon", "Rare",   "Epic",
    "Legendary", "Mythic",   "Exotic", "Ultimate"};

double RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_max + 1] = {
    0, 1, 6, 10, 15, 25, 160, 1200, 250};

double RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_exotic + 2] = {
    0, 1, 8, 15, 40, 150, 500, 2500};
double RR_MOB_LOOT_RARITY_COEFFICIENTS[rr_rarity_id_max] = {2.5, 4,  6,   15,
                                                            35,  50, 125, 150};

static void init_game_coefficients()
{   
    double sum = 1;
    double sum2 = 1;
    for (uint64_t a = 1; a < rr_rarity_id_max; ++a)
        RR_MOB_LOOT_RARITY_COEFFICIENTS[a] *=
            RR_MOB_LOOT_RARITY_COEFFICIENTS[a - 1];
    for (uint64_t a = 1; a <= rr_rarity_id_exotic; ++a)
    {
        sum += (RR_DROP_RARITY_COEFFICIENTS[a + 1] =
                    RR_DROP_RARITY_COEFFICIENTS[a] /
                    RR_DROP_RARITY_COEFFICIENTS[a + 1]);
    }
    for (uint64_t a = 1; a <= rr_rarity_id_exotic + 1; ++a)
    {
        RR_DROP_RARITY_COEFFICIENTS[a] = RR_DROP_RARITY_COEFFICIENTS[a] / sum +
                                         RR_DROP_RARITY_COEFFICIENTS[a - 1];
    }
    RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_exotic + 1] = 1;
    for (uint64_t a = 1; a <= rr_rarity_id_ultimate; ++a)
    {
        sum2 += (RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1] =
                     RR_MOB_WAVE_RARITY_COEFFICIENTS[a] /
                     RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1]);
    }
    for (uint64_t a = 1; a <= rr_rarity_id_ultimate + 1; ++a)
    {
        RR_MOB_WAVE_RARITY_COEFFICIENTS[a] =
            RR_MOB_WAVE_RARITY_COEFFICIENTS[a] / sum2 +
            RR_MOB_WAVE_RARITY_COEFFICIENTS[a - 1];
    }
    RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_ultimate + 1] = 1;
    for (uint64_t mob = 1; mob < rr_mob_id_max; ++mob)
    {
        RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
        RR_OCEAN_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_OCEAN_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
        RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
    }
    for (uint64_t mob = 0; mob < rr_mob_id_max; ++mob)
    {
        RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
        RR_OCEAN_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_OCEAN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
        RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
    }
}

#define offset(a, b)                                                           \
    ((x + a < 0 || y + b < 0 || x + a >= size / 2 || y + b >= size / 2)        \
         ? 0                                                                   \
         : template[(y + b) * size / 2 + x + a])
#define maze_grid(x, y) maze[(y)*size + (x)]

static void init_maze(uint32_t size, uint8_t *template,
                      struct rr_maze_grid *maze)
{
    for (int32_t y = 0; y < size / 2; ++y)
    {
        for (int32_t x = 0; x < size / 2; ++x)
        {
            uint8_t this_tile = offset(0, 0);
#ifdef RR_SERVER
            maze_grid(x * 2, y * 2).difficulty = this_tile;
            maze_grid(x * 2 + 1, y * 2).difficulty = this_tile;
            maze_grid(x * 2, y * 2 + 1).difficulty = this_tile;
            maze_grid(x * 2 + 1, y * 2 + 1).difficulty = this_tile;
#endif
            this_tile = this_tile != 0;
            // top left
            uint8_t top = offset(0, -1);
            uint8_t bottom = offset(0, 1);
            if (this_tile)
            {
                if (top == 0)
                {
                    if (offset(-1, 0) == 0)
                        maze_grid(x * 2, y * 2).value = 7;
                    else
                        maze_grid(x * 2, y * 2).value = this_tile;
                    if (offset(1, 0) == 0)
                        maze_grid(x * 2 + 1, y * 2).value = 5;
                    else
                        maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                if (bottom == 0)
                {
                    if (offset(-1, 0) == 0)
                        maze_grid(x * 2, y * 2 + 1).value = 6;
                    else
                        maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    if (offset(1, 0) == 0)
                        maze_grid(x * 2 + 1, y * 2 + 1).value = 4;
                    else
                        maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
            }
            else
            {
                if (top)
                {
                    if (offset(-1, 0) && offset(-1, -1))
                        maze_grid(x * 2, y * 2).value = 15;
                    else
                        maze_grid(x * 2, y * 2).value = this_tile;
                    if (offset(1, 0) && offset(1, -1))
                        maze_grid(x * 2 + 1, y * 2).value = 13;
                    else
                        maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                if (bottom)
                {
                    if (offset(-1, 0) && offset(-1, 1))
                        maze_grid(x * 2, y * 2 + 1).value = 14;
                    else
                        maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    if (offset(1, 0) && offset(1, 1))
                        maze_grid(x * 2 + 1, y * 2 + 1).value = 12;
                    else
                        maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
            }
        }
    }
}

static void print_chances(float difficulty)
{
    printf("-----Chances for %.0f-----\n", difficulty);
    uint32_t rarity_cap = rr_rarity_id_common + (difficulty + 7) / 8;
    if (rarity_cap > rr_rarity_id_ultimate)
        rarity_cap = rr_rarity_id_ultimate;
    uint32_t rarity = rarity_cap >= 2 ? rarity_cap - 2 : 0;
    for (; rarity <= rarity_cap; ++rarity)
    {
        float start =
            rarity == 0
                ? 0
                : pow(1 - (1 - RR_MOB_WAVE_RARITY_COEFFICIENTS[rarity]) * 0.3,
                      pow(1.5, difficulty));
        float end =
            rarity == rarity_cap
                ? 1
                : pow(1 - (1 - RR_MOB_WAVE_RARITY_COEFFICIENTS[rarity + 1]) *
                              0.3,
                      pow(1.5, difficulty));
        printf("%s: %.9f (1 per %.4f)\n", RR_RARITY_NAMES[rarity], end - start,
               1 / (end - start));
    }
}

double RR_BASE_CRAFT_CHANCES[rr_rarity_id_max - 1] = {0.5,  0.3,  0.15, 0.05,
                                                      0.03, 0.02, 0.015};
double RR_CRAFT_CHANCES[rr_rarity_id_max - 1];

static double from_prd_base(double C)
{
    double pProcOnN = 0;
    double pProcByN = 0;
    double sumNpProcOnN = 0;

    double maxFails = ceil(1 / C);
    for (uint32_t N = 1; N <= maxFails; ++N)
    {
        pProcOnN = fmin(1, N * C) * (1 - pProcByN);
        pProcByN += pProcOnN;
        sumNpProcOnN += N * pProcOnN;
    }
    return (1 / sumNpProcOnN);
}

static double get_prd_base(double p)
{
    if (p == 0)
        return 0;
    double Cupper = p;
    double Clower = 0;
    double Cmid = p / 2;
    double p1 = 0;
    double p2 = 1;
    while (1)
    {
        Cmid = (Cupper + Clower) / 2;
        p1 = from_prd_base(Cmid);
        if (fabs(p1 - p2) <= 0)
            break;

        if (p1 > p)
            Cupper = Cmid;
        else
            Clower = Cmid;
        p2 = p1;
    }
    return Cmid;
}

#define init(MAZE)                                                             \
    init_maze(sizeof(RR_MAZE_##MAZE[0]) / sizeof(struct rr_maze_grid),         \
              &RR_MAZE_TEMPLATE_##MAZE[0][0], &RR_MAZE_##MAZE[0][0]);

void rr_static_data_init()
{
    for (uint32_t r = 0; r < rr_rarity_id_max - 1; ++r)
        RR_CRAFT_CHANCES[r] = get_prd_base(RR_BASE_CRAFT_CHANCES[r]);
    init_game_coefficients();
    init(HELL_CREEK);
    init(OCEAN);
    init(GARDEN);
    init(BURROW);
// #ifdef RR_SERVER
//     print_chances(52);
//     print_chances(44);
//     print_chances(40);
//     print_chances(36);
//     print_chances(32);
// #endif
}

double xp_to_reach_level(uint32_t level)
{
    if (level <= 60)
        return (level + 5) * pow(1.175, level);
    double base = (level + 5) * pow(1.175, 60);
    for (uint32_t i = 60; i < level; ++i)
        base *= rr_fclamp(1.18 - 0.0075 * (i - 60), 1.1, 1.18);
    return base;
}

uint32_t level_from_xp(double xp)
{
    uint32_t level = 1;
    while (xp >= xp_to_reach_level(level + 1))
        xp -= xp_to_reach_level(++level);
    return level;
}


#ifdef RR_SERVER
#define _ 0
#define c 1
#define C 4
#define u 8
#define U 12
#define r 16
#define R 20
#define e 24
#define E 28
#define l 32
#define L 36
#define m 40
#define M 44
#define x 48
#define X 52
#define s 56
#define S 60
#else
#define _ 0
#define c 1
#define C 1
#define u 1
#define U 1
#define r 1
#define R 1
#define e 1
#define E 1
#define l 1
#define L 1
#define m 1
#define M 1
#define x 1
#define X 1
#define s 1
#define S 1
#endif

#define RR_DEFINE_MAZE(name, size)                                             \
    struct rr_maze_grid RR_MAZE_##name[size][size];                            \
    uint8_t RR_MAZE_TEMPLATE_##name[size / 2][size / 2]
// clang-format off
RR_DEFINE_MAZE(HELL_CREEK, 80) = {
{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
{_,_,_,_,x,x,x,x,X,X,X,X,X,_,X,X,X,_,_,_,X,X,X,X,X,_,_,s,s,s,s,X,_,_,s,s,s,s,_,_},
{_,_,_,_,x,x,x,_,_,_,_,X,X,_,X,_,X,_,_,X,X,X,_,X,X,X,_,s,_,_,_,X,_,s,s,_,_,s,_,_},
{_,_,_,_,x,_,X,X,X,X,_,_,_,_,X,_,X,X,X,X,X,_,_,X,X,X,_,_,_,X,X,X,X,X,s,s,s,s,_,_},
{_,_,_,x,x,_,X,X,X,X,X,X,X,X,X,_,_,_,X,X,_,_,_,_,_,X,X,X,X,X,_,_,_,_,_,_,_,_,_,_},
{_,_,_,x,x,_,_,_,_,X,X,X,X,X,X,X,_,X,X,_,_,L,L,L,_,_,_,_,_,_,_,l,l,_,l,l,l,_,_,_},
{_,_,_,x,_,_,x,x,_,_,_,_,_,_,_,X,X,X,_,_,L,L,L,L,L,L,L,L,L,_,l,l,l,_,l,l,l,l,_,_},
{_,_,_,x,_,x,x,x,x,_,X,X,X,X,_,_,_,_,_,L,L,_,L,L,_,_,_,_,L,_,l,l,l,l,l,_,_,l,_,_},
{_,_,_,x,x,x,x,x,x,x,x,X,X,_,_,L,L,L,L,L,L,_,L,L,_,l,l,_,_,_,_,l,l,_,_,_,l,l,_,_},
{_,_,_,x,_,_,_,_,_,_,_,_,_,_,_,L,_,_,_,_,L,_,L,_,_,l,l,l,_,_,_,l,_,_,l,_,l,l,_,_},
{_,_,x,x,_,_,m,m,m,m,m,m,m,m,L,L,_,_,_,L,L,_,L,_,l,l,l,l,_,_,_,l,_,l,l,_,l,_,_,_},
{_,_,x,x,_,m,m,_,_,_,_,_,_,_,_,L,m,m,_,L,_,_,l,_,l,l,l,l,l,_,l,l,l,l,l,_,E,_,_,_},
{_,_,x,x,_,m,_,_,m,m,M,M,M,M,_,_,_,m,_,L,_,l,l,_,_,l,l,l,l,l,l,_,_,_,l,_,E,_,_,_},
{_,_,x,_,_,m,_,m,m,_,_,_,_,M,M,M,_,m,_,L,_,l,l,l,_,_,_,_,_,_,_,_,l,l,E,_,E,E,_,_},
{_,_,M,_,m,m,_,m,_,_,M,M,_,_,_,M,_,m,_,L,_,_,l,l,_,_,_,_,l,l,l,l,l,E,E,E,E,E,_,_},
{_,_,M,_,m,_,_,m,_,M,M,M,M,_,_,M,_,m,_,_,_,_,l,l,l,l,l,l,l,l,l,l,_,_,_,_,E,E,_,_},
{_,_,M,_,m,_,m,m,_,M,_,_,M,_,M,M,_,m,_,_,l,l,l,_,_,_,_,_,_,_,_,_,_,_,E,E,E,E,_,_},
{_,_,M,_,m,_,m,_,_,M,_,_,M,M,M,_,_,m,_,_,l,_,_,_,R,R,R,R,e,e,e,e,e,e,E,_,_,E,_,_},
{_,_,M,_,m,_,m,_,M,M,_,M,M,M,_,_,m,m,_,_,L,_,R,R,R,R,_,_,e,e,e,_,e,E,E,_,_,E,_,_},
{_,_,M,_,m,_,m,_,M,M,_,_,_,_,_,_,m,_,_,L,L,_,R,R,R,R,R,_,e,e,e,_,_,_,_,_,l,l,_,_},
{_,_,M,_,M,_,m,_,_,M,M,M,m,_,_,m,m,_,L,L,L,_,_,_,r,r,R,_,_,_,e,E,E,_,l,l,l,l,_,_},
{_,_,M,_,M,_,m,m,_,_,_,_,m,m,m,m,_,_,L,_,_,_,U,r,r,r,r,R,R,_,_,_,E,_,_,l,l,_,_,_},
{_,_,M,_,M,_,_,m,m,m,L,_,_,_,_,_,_,L,L,_,U,U,U,U,r,_,_,R,R,R,R,_,E,E,_,_,l,_,_,_},
{_,_,M,M,M,M,_,_,_,_,L,L,L,L,L,L,L,L,_,_,U,U,U,U,U,r,_,r,_,_,R,_,_,E,E,_,l,_,_,_},
{_,_,_,M,M,M,M,M,M,_,_,_,_,L,_,_,_,L,_,U,U,u,U,U,U,U,r,r,r,_,e,e,_,E,E,_,l,_,_,_},
{_,_,_,M,_,_,_,_,M,M,_,L,L,L,_,U,_,_,_,_,u,u,u,_,_,r,r,r,r,_,_,R,_,e,_,_,l,_,_,_},
{_,_,_,M,M,M,_,M,M,M,_,_,L,L,_,u,u,u,u,_,u,u,u,u,_,_,_,_,R,R,R,R,_,e,_,l,l,_,_,_},
{_,_,_,M,_,M,_,_,_,M,M,_,m,L,_,_,_,_,C,_,_,u,u,u,_,U,U,_,_,R,_,_,_,e,_,l,l,_,_,_},
{_,_,M,M,_,M,M,_,M,M,_,_,m,_,_,u,u,C,C,_,C,C,u,u,u,u,U,U,_,R,R,e,e,e,_,l,_,_,_,_},
{_,_,M,_,_,M,M,_,_,M,_,m,m,_,u,u,u,_,C,C,C,_,u,u,_,_,_,U,_,_,_,e,_,_,_,l,l,l,_,_},
{_,_,M,M,_,M,M,M,_,M,_,m,m,_,U,u,_,_,c,c,c,_,_,u,_,r,r,U,_,e,e,e,_,l,l,l,l,l,_,_},
{_,_,M,M,_,_,_,M,_,M,_,m,_,_,U,U,_,c,c,c,c,_,_,U,_,_,r,r,_,e,_,_,_,l,l,l,l,_,_,_},
{_,_,_,M,M,M,M,M,_,M,_,m,_,U,U,U,_,c,c,c,c,_,U,U,U,U,r,_,_,E,E,E,_,_,l,l,l,_,_,_},
{_,_,_,M,_,_,_,M,M,M,_,m,_,_,U,_,_,_,c,c,_,_,U,U,_,_,r,_,_,E,E,E,E,_,_,_,l,_,_,_},
{_,_,_,M,M,_,_,_,_,M,_,m,_,_,_,_,_,_,_,_,_,_,r,U,r,_,_,_,_,E,_,_,E,E,E,_,l,_,_,_},
{_,_,_,M,M,_,m,m,_,_,_,m,_,e,e,R,R,R,R,R,r,r,r,r,r,r,_,_,E,E,_,_,E,E,E,l,l,_,_,_},
{_,_,_,_,m,m,m,m,m,m,m,m,_,_,e,e,R,R,R,R,R,_,_,r,r,r,R,_,E,E,E,E,E,_,_,_,_,_,_,_},
{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
};
RR_DEFINE_MAZE(OCEAN, 82) = {
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,l,l,l,l,l,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,l,l,l,l,_,_,l,l,l,l,l,l,l,l,_,_,_,_,_,_,e,e,_,_,e,e,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,_,_,_,e,e,e,e,e,e,e,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_,_,_},
    {_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_},
    {_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_},
    {_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_},
    {_,_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_},
    {_,_,_,_,l,l,l,l,l,m,m,m,m,m,m,m,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,c,c,_,_,_,_,_},
    {_,_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,c,c,c,c,_,_,_,_,_},
    {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,l,l,l,l,e,e,e,e,e,e,e,e,e,e,c,c,c,c,c,_,_,_,_,_},
    {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,l,l,l,_,_,_,e,e,e,e,e,e,e,c,c,c,c,c,c,c,_,_,_,_},
    {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,_,_,e,e,e,e,e,e,c,c,c,c,c,c,c,c,_,_,_},
    {_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,_,_,e,e,e,e,c,c,c,c,c,c,c,c,c,_,_,_},
    {_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,_,_,e,e,e,e,c,c,c,c,c,c,c,c,c,c,_,_},
    {_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,u,u,u,u,e,e,c,c,c,c,c,c,c,c,c,_,_},
    {_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,_,_},
    {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c,_},
    {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c,_},
    {_,_,x,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c},
    {_,_,x,x,x,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,_},
    {_,_,x,x,x,x,x,x,m,m,m,m,m,m,m,m,m,x,x,_,_,_,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,_,_},
    {_,_,x,x,x,x,x,x,x,x,m,m,m,m,m,x,x,x,x,_,_,u,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,_,_,_},
    {_,_,_,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,_,_,_,u,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,_,_,_},
    {_,_,_,_,x,x,x,x,x,x,x,x,x,x,x,x,x,_,_,_,_,_,u,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,_,_,_},
    {_,_,_,_,_,x,x,x,x,x,x,x,x,x,x,x,x,x,_,_,_,_,r,r,u,u,u,u,u,u,u,c,u,u,c,c,c,_,_,_,_},
    {_,_,_,_,_,_,x,x,x,_,_,x,x,x,x,x,x,x,_,_,_,r,r,r,r,r,u,u,u,u,u,u,u,u,u,u,u,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,x,x,x,x,_,_,_,_,r,r,r,r,r,r,r,r,r,r,u,u,u,u,u,u,u,u,u,_,_},
    {_,_,_,_,_,_,e,e,_,_,_,_,_,_,_,_,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,u,u,u,u,u,u,u,_,_},
    {_,_,_,_,e,e,e,e,e,_,_,_,_,_,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,u,u,u,u,u,_},
    {_,_,e,e,e,e,e,e,e,e,e,_,_,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,u,u,u,u,_},
    {_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,u,_,_},
    {_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,_,_},
    {_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,_,_,_},
    {_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,_,_,_,_},
    {_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,_,_,_,_,_,_},
    {_,_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,_,_,_,_,_,_,_},
    {_,_,_,_,e,e,e,e,e,e,_,_,e,e,e,e,e,e,e,e,_,_,_,_,_,r,r,r,r,r,r,r,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,e,e,_,_,_,_,_,_,e,e,_,_,_,_,_,_,_,_,_,_,_,r,r,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}
};

// RR_DEFINE_MAZE(CENTRALIA, 82) = {
//     {_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, _, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, _, c, c, _},
//     {_, c, c, _, _, _, _, _, _, _, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _, _, _, _, _, _, _, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, _},
//     {_, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, c, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _},
// };

RR_DEFINE_MAZE(GARDEN, 82) = {
    {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,c,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,u,c,_,_,_,_,_,_,_,_,_,c,c,c,c,c,_,_,_,_,_,_,_,x,x,x,x,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,u,u,c,_,_,_,_,_,c,_,_,c,c,c,c,c,c,_,_,_,_,_,_,x,x,x,x,x,x,x,_,_,_,_},
    {_,_,_,_,_,u,u,u,u,c,c,_,_,_,c,c,c,c,c,c,c,c,c,c,c,_,_,_,_,x,x,x,x,x,x,x,x,x,x,_,_},
    {_,_,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,_,_,x,x,x,x,x,x,x,x,x,x,x,x,x,_},
    {_,_,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,_,x,x,x,x,x,x,x,x,x,x,x,x,m,_},
    {_,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,_,x,x,x,x,x,x,x,x,x,x,x,m,_,_},
    {_,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,_,_,m,x,x,x,x,x,x,m,m,m,m,_,_},
    {_,_,u,u,u,u,u,u,u,u,c,c,_,_,_,c,c,c,c,c,c,c,c,c,c,_,_,m,m,m,x,x,m,m,m,m,m,m,_,_,_},
    {_,_,_,u,u,u,u,u,u,u,c,_,_,_,_,_,_,c,c,c,c,c,c,c,_,_,_,m,m,m,m,m,m,m,m,m,m,m,_,_,_},
    {_,_,_,u,u,u,u,u,u,u,_,_,_,_,_,_,_,_,_,c,c,c,_,_,_,_,_,_,m,m,m,m,m,m,m,m,m,m,m,m,_},
    {_,_,_,_,u,u,u,u,u,_,_,_,_,_,_,_,_,_,c,c,c,c,_,_,_,_,_,_,m,m,m,m,m,m,m,m,m,m,m,m,_},
    {_,_,_,_,u,u,u,u,u,_,_,_,_,_,_,_,_,_,c,c,c,c,_,_,_,_,_,_,m,m,m,m,m,m,m,m,m,m,m,_,_},
    {_,_,_,_,u,u,u,u,u,_,_,_,_,_,_,_,_,c,c,c,c,c,c,_,_,_,_,_,_,m,m,m,m,m,m,l,l,l,l,_,_},
    {_,_,_,_,u,u,u,u,_,_,_,_,_,_,_,_,_,c,c,c,c,c,c,c,_,_,_,_,_,m,m,m,l,l,l,l,l,l,_,_,_},
    {_,_,_,u,u,u,u,u,_,_,_,_,_,_,_,_,e,c,c,e,e,e,e,c,_,_,_,_,_,_,m,l,l,l,l,l,l,l,_,_,_},
    {_,_,u,u,u,u,u,u,u,_,_,_,_,_,_,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,l,l,l,l,l,l,l,l,l,_,_},
    {_,_,u,u,u,u,u,u,u,u,_,_,_,_,_,e,e,e,e,e,e,_,e,e,e,e,_,_,_,l,l,l,l,l,l,l,l,l,l,_,_},
    {_,u,u,u,u,u,u,u,u,u,_,_,_,_,e,e,e,e,e,e,_,_,e,e,e,e,e,l,l,l,l,l,l,l,l,l,l,l,_,_,_},
    {_,u,u,u,u,u,r,r,_,_,_,_,_,_,e,e,e,e,e,e,_,_,_,e,e,e,e,l,l,l,l,l,l,l,l,l,l,l,_,_,_},
    {_,r,u,u,r,r,r,r,_,_,_,_,_,_,e,e,e,e,e,e,e,_,_,_,e,e,e,l,l,l,l,l,l,l,l,l,l,l,l,_,_},
    {_,r,r,r,r,r,r,r,_,_,_,_,_,_,_,e,e,e,e,e,e,_,_,_,e,e,e,l,l,l,l,l,l,l,l,l,l,l,l,_,_},
    {_,r,r,r,r,r,r,r,_,_,_,_,_,_,_,_,e,e,e,e,e,e,_,_,_,e,e,e,l,l,l,l,l,l,l,l,l,l,_,_,_},
    {_,_,r,r,r,r,r,r,r,r,_,_,_,_,_,_,e,e,e,e,e,e,_,_,_,e,e,e,l,l,l,l,l,l,l,l,l,l,_,_,_},
    {_,_,r,r,r,r,r,r,r,r,r,r,r,r,_,_,_,e,e,e,e,e,e,_,_,_,e,e,e,l,l,l,l,l,l,l,l,_,_,_,_},
    {_,_,r,r,r,r,r,r,r,r,r,r,r,r,r,_,_,_,e,e,e,e,e,_,_,e,e,e,e,l,l,l,l,l,l,l,l,_,_,_,_},
    {_,_,r,r,r,r,r,r,r,r,r,r,r,r,r,r,_,_,e,e,e,e,e,_,_,_,e,e,e,l,l,l,l,l,l,l,l,_,_,_,_},
    {_,_,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,e,e,e,e,e,e,e,_,_,_,_,e,l,l,l,l,l,l,l,l,l,_,_,_},
    {_,_,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_,l,l,l,l,l,l,e,_,_},
    {_,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,e,e,e,e,e,e,e,e,e,e,e,_,_,e,e,e,e,e,e,e,e,e,_,_},
    {_,r,r,r,r,r,r,r,r,_,_,_,r,r,r,r,r,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_},
    {_,_,_,r,r,r,r,r,_,_,_,_,r,r,_,_,r,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_},
    {_,_,_,r,r,r,r,r,_,_,_,_,_,_,_,_,_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_},
    {_,_,_,r,r,r,r,r,r,_,_,_,_,_,_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_},
    {_,_,r,r,r,r,r,r,r,_,_,_,_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_},
    {_,_,r,r,r,r,r,r,r,_,_,_,e,e,e,e,e,e,e,e,e,e,e,e,_,_,e,e,e,e,e,e,_,_,_,_,_,_,_,_,_},
    {_,r,r,r,r,r,r,r,_,_,_,e,e,e,e,e,e,e,_,e,e,e,_,_,_,_,_,_,e,e,_,_,_,_,_,_,_,_,_,_,_},
    {_,r,r,r,r,r,r,r,_,_,e,e,e,e,e,e,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,r,r,r,r,_,e,e,e,e,e,e,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,r,r,_,_,e,e,e,e,e,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
    {_,_,_,_,_,_,_,_,_,_,e,e,e,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}
};

// RR_DEFINE_MAZE(SWAMP, 82) = {
//     {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
//     {_,_,_,_,_,_,_,_,_,_,_,_,l,l,l,l,l,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
//     {_,_,_,_,l,l,l,l,_,_,l,l,l,l,l,l,l,l,_,_,_,_,_,_,e,e,_,_,e,e,_,_,_,_,_,_,_,_,_,_,_},
//     {_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,_,_,_,e,e,e,e,e,e,e,_,_,_,_,_,_,_,_,_,_,_},
//     {_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_,_,_},
//     {_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_},
//     {_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_},
//     {_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_,_},
//     {_,_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,e,_,_,_,_,_,_},
//     {_,_,_,_,l,l,l,l,l,m,m,m,m,m,m,m,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,e,e,c,c,_,_,_,_,_},
//     {_,_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,l,l,l,l,l,e,e,e,e,e,e,e,e,e,e,e,c,c,c,c,_,_,_,_,_},
//     {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,l,l,l,l,e,e,e,e,e,e,e,e,e,e,c,c,c,c,c,_,_,_,_,_},
//     {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,l,l,l,_,_,_,e,e,e,e,e,e,e,c,c,c,c,c,c,c,_,_,_,_},
//     {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,_,_,e,e,e,e,e,e,c,c,c,c,c,c,c,c,_,_,_},
//     {_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,_,_,e,e,e,e,c,c,c,c,c,c,c,c,c,_,_,_},
//     {_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,_,_,e,e,e,e,c,c,c,c,c,c,c,c,c,c,_,_},
//     {_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,u,u,u,u,e,e,c,c,c,c,c,c,c,c,c,_,_},
//     {_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,_,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,_,_},
//     {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,_,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c,_},
//     {_,_,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,_,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c,_},
//     {_,_,x,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,c},
//     {_,_,x,x,x,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,_,_,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,c,_},
//     {_,_,x,x,x,x,x,x,m,m,m,m,m,m,m,m,m,x,x,_,_,_,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,c,_,_},
//     {_,_,x,x,x,x,x,x,x,x,m,m,m,m,m,x,x,x,x,_,_,u,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,_,_,_},
//     {_,_,_,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,_,_,_,u,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,c,_,_,_},
//     {_,_,_,_,x,x,x,x,x,x,x,x,x,x,x,x,x,_,_,_,_,_,u,u,u,u,u,u,u,u,u,c,c,c,c,c,c,c,_,_,_},
//     {_,_,_,_,_,x,x,x,x,x,x,x,x,x,x,x,x,x,_,_,_,_,r,r,u,u,u,u,u,u,u,c,u,u,c,c,c,_,_,_,_},
//     {_,_,_,_,_,_,x,x,x,_,_,x,x,x,x,x,x,x,_,_,_,r,r,r,r,r,u,u,u,u,u,u,u,u,u,u,u,_,_,_,_},
//     {_,_,_,_,_,_,_,_,_,_,_,_,x,x,x,x,_,_,_,_,r,r,r,r,r,r,r,r,r,r,u,u,u,u,u,u,u,u,u,_,_},
//     {_,_,_,_,_,_,e,e,_,_,_,_,_,_,_,_,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,u,u,u,u,u,u,u,_,_},
//     {_,_,_,_,e,e,e,e,e,_,_,_,_,_,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,u,u,u,u,u,_},
//     {_,_,e,e,e,e,e,e,e,e,e,_,_,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,u,u,u,u,_},
//     {_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,u,_,_},
//     {_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,_,_},
//     {_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,_,_,_},
//     {_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,r,r,_,_,_,_},
//     {_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,r,r,_,_,_,_,_,_},
//     {_,_,_,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,r,r,r,r,r,r,r,r,r,r,_,_,_,_,_,_,_},
//     {_,_,_,_,e,e,e,e,e,e,_,_,e,e,e,e,e,e,e,e,_,_,_,_,_,r,r,r,r,r,r,r,_,_,_,_,_,_,_,_,_},
//     {_,_,_,_,_,_,e,e,_,_,_,_,_,_,e,e,_,_,_,_,_,_,_,_,_,_,_,r,r,_,_,_,_,_,_,_,_,_,_,_,_},
//     {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}
// };

// clang-format on
RR_DEFINE_MAZE(BURROW, 4) = {{1, 1}, {0, 1}};

#define MAZE_ENTRY(MAZE, GRID_SIZE)                                            \
    (sizeof(RR_MAZE_##MAZE[0]) / sizeof(struct rr_maze_grid)), GRID_SIZE,      \
        &RR_MAZE_##MAZE[0][0]

struct rr_maze_declaration RR_MAZES[rr_biome_id_max] = {
    {MAZE_ENTRY(HELL_CREEK, 1024), {{18, 33}, {22, 28}, {25, 21}, {29, 19}}},
    {MAZE_ENTRY(OCEAN, 1024), {{6, 13}, {11, 15}, {16, 17}, {22, 23}}},
    {MAZE_ENTRY(GARDEN, 1024), {{6, 13}, {11, 15}, {16, 17}, {20, 23}}},
    {MAZE_ENTRY(BURROW, 512), {{0}, {0}, {0}, {0}}}
};

#undef c
#undef C
#undef u
#undef U
#undef r
#undef R
#undef e
#undef E
#undef l
#undef L
#undef m
#undef M
#undef x
#undef s
#undef S
