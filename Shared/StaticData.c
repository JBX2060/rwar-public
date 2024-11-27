// Copyright (C) 2024  Paul Johnson

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Shared/StaticData.h>

#include <math.h>
#include <stdio.h>

#include <Shared/Utilities.h>

// clang-format off
struct rr_petal_base_stat_scale const offensive[rr_rarity_id_max] = {
    {1.2, 1.2},
    {1.7, 2.0},
    {3.0, 4.1},
    {5.0, 8.0},
    {8.5,  16},
    {14.5, 48},
    {24.6,144},
    {45.0,440},
    {90.0,852}
};

struct rr_petal_base_stat_scale const defensive[rr_rarity_id_max] = {
    {1.2, 1.2},
    {2.0, 1.7},
    {4.1, 3.0},
    {8.0, 5.0},
    {16,  8.5},
    {48, 14.5},
    {144,24.6},
    {440,45.0},
    {852,90.0}

};

struct rr_petal_data RR_PETAL_DATA[rr_petal_id_max] = {
    //   id                     min_rarity              scale    dmg      hp   clump   cd 2cd  count
    {rr_petal_id_none,      rr_rarity_id_common,    offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0}},
    {rr_petal_id_basic,     rr_rarity_id_common,    offensive, 10.0f,  15.0f,   0.0f,  50,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_pellet,    rr_rarity_id_common,    offensive, 12.5f,   5.0f,   0.0f,  20,  0, {1,2,2,3,3,5,6,6,6}},
    {rr_petal_id_fossil,    rr_rarity_id_common,    offensive, 10.0f,  60.0f,   0.0f, 100,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_stinger,   rr_rarity_id_common,    offensive, 50.0f,   3.0f,  10.0f, 150,  0, {1,1,1,1,1,3,5,5,6}},
    {rr_petal_id_light,     rr_rarity_id_rare,      offensive,  5.0f,   5.0f,  15.0f,  20,  0, {1,1,1,1,1,2,3,3,3}},
    {rr_petal_id_shell,     rr_rarity_id_rare,      offensive, 32.0f,  12.0f,   0.0f,  75, 13, {1,1,1,1,1,2,3,3,4}},
    {rr_petal_id_peas,      rr_rarity_id_rare,      offensive, 15.0f,   8.0f,   8.0f,  13, 12, {4,4,4,4,4,4,5,5,7}},
    {rr_petal_id_leaf,      rr_rarity_id_unusual,   offensive,  9.0f,  15.0f,   8.0f,  38,  0, {1,1,1,1,1,2,2,2,4}},
    {rr_petal_id_egg,       rr_rarity_id_unusual,   defensive,  1.0f,  20.0f,   0.0f,  35, 100, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_magnet,    rr_rarity_id_rare,      defensive,  2.0f,  15.0f,   0.0f,  38,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_uranium,   rr_rarity_id_legendary, offensive, 4.0f,  10.0f,   0.0f,  50, 25, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_feather,   rr_rarity_id_common,    defensive,  1.0f,   3.0f,   0.0f,  25,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_azalea,    rr_rarity_id_common,    defensive,  5.0f,  10.0f,   0.0f,  50, 25, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_bone,      rr_rarity_id_common,    defensive,  2.5f,  25.0f,   0.0f,  68,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_web,       rr_rarity_id_rare,      defensive,  5.0f,   5.0f,   0.0f,  50, 13, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_seed,      rr_rarity_id_rare,      defensive,  1.0f,  25.0f,   0.0f,  63,  1, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_gravel,    rr_rarity_id_unusual,   offensive, 12.0f,   5.0f,   0.0f,  20, 13, {1,2,2,2,3,3,4,4,5}},
    {rr_petal_id_club,      rr_rarity_id_common,    defensive,  8.0f, 300.0f,   0.0f, 200,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_crest,     rr_rarity_id_rare,      offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_droplet,   rr_rarity_id_common,    offensive, 15.0f,   5.0f,   0.0f,  37,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_beak,      rr_rarity_id_unusual,   offensive,  5.0f,   5.0f,   0.0f,  55,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_lightning, rr_rarity_id_unusual,   offensive, 13.0f,   1.0f,   0.0f,  63,  0, {1,1,1,1,1,1,1,1,3}},
    {rr_petal_id_third_eye, rr_rarity_id_legendary, offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_mandible,  rr_rarity_id_common,    offensive,  5.0f,  10.0f,   0.0f,  75,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_wax,      rr_rarity_id_unusual,   offensive,  9.0f,  15.0f,   8.0f,  38,  0, {1,1,1,1,1,2,2,2,4}},
    {rr_petal_id_sand,      rr_rarity_id_common,    offensive, 15.0f,  10.0f,  10.0f,  37,  0, {4,4,4,4,4,4,4,4,6}},
    {rr_petal_id_mint,      rr_rarity_id_unusual,   offensive,  5.0f,  10.0f,  10.0f,  50, 25, {1,1,1,1,1,1,1,1,2}},
    {rr_petal_id_cactus,    rr_rarity_id_unusual,   defensive,  5.0f,  15.0f,  10.0f,  35,  0, {1,1,1,1,1,1,2,3,3}},
    {rr_petal_id_gold,      rr_rarity_id_unusual,   offensive,  22.5f, 135.0f, 10.0f,  115, 0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_rice,      rr_rarity_id_common,    offensive,  5.0f,  0.5f,   0.0f,    1,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_horn,      rr_rarity_id_common,    offensive,  5.0f,  18.0f,  0.0f,   65,  0, {1,1,1,1,1,1,1,3,6}},
    {rr_petal_id_stick,     rr_rarity_id_rare,      offensive,  6.0f,  8.0f,   0.0f,   50,  0, {1,1,1,1,1,3,5,5,6}},
    {rr_petal_id_missile,   rr_rarity_id_rare,      offensive,  2.0f,  0.5f,   0.0f,    3,   3, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_iris,      rr_rarity_id_rare,      offensive, 0.1f,   5.0f,   8.0f,  50, 0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_rock,     rr_rarity_id_common,    offensive, 5.0f,  145.0f,   0.0f,  350,  0, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_honey,     rr_rarity_id_unusual,    defensive, 1.0f,  15.0f,   0.0f,  55,  15, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_ocean_shell, rr_rarity_id_common, defensive, 10.0f, 15.0f, 0.0f, 50, 25, {1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_kelp,    rr_rarity_id_common,    defensive,  5.0f,  10.0f,   0.0f,  50, 25, {1,1,1,1,1,1,3,3,6}},
    {rr_petal_id_fish_egg,       rr_rarity_id_unusual,   defensive,  1.0f,  20.0f,   0.0f,  35, 100, {1,1,3,3,3,3,4,5,6}},
    {rr_petal_id_scales,       rr_rarity_id_unusual,   defensive,  1.0f,  20.0f,   0.0f,  35, 100, {1,1,3,3,3,3,4,5,6}},
    {rr_petal_id_water,      rr_rarity_id_common,    offensive,  5.0f,  0.5f,   0.0f,    1,  0, {1,1,1,1,1,1,1,1,1}},
};

char const *RR_PETAL_NAMES[rr_petal_id_max] = {
    "Secret", "Petal", "Pellet", "Fossil",   "Stinger",  "Berries", "Shell",
    "Peas",   "Leaf",  "Egg",    "Magnet", "Uranium", "Feather", "Azalea",
    "Bone",   "Web",   "Seed",   "Gravel", "Club", "Crest", "Droplet",
    "Beak", "Lightning", "Third Eye", "Mandible", "Wax", "Sand", "Mint", "Cactus", "Gold", "Rice", "Horn", "Stick", "Missile", "Iris", "Rock", "Honey", "Shell", "Kelp", "Fish Egg", "Scales", "Amulet"};

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
    "Does low damage to entities in a small range",
    "It's so light it increases your movement speed. Stacks diminishingly",
    "It heals you",
    "Gives the player armor. Does not stack.",
    "It slows everything down",
    "What does this one do",
    "Tiny rocks that stay on the ground and trip dinos",
    "Heavy and sturdy",
    "Increases your vision range. Does not stack",
    "This mysterious droplet reverses your petal rotation",
    "Stuns mobs and prevents them from moving",
    "A stunning display",
    "Your petals hate it and want to move further away",
    "Does more damage if target hp is below 50%",
    "Used to be useless!",
    "Very fine",
    "Remember to feed your pets",
    "Ouch! Prickly hug. Stacks diminishingly.",
    "A beacon of wealth.",
    "The polar opposite of stinger.",
    "Give it back!",
    "Sticky Stick",
    "You can't dodge this one",
    "A poisonous fella.",
    "Just a plain old rock",
    "Sweet and savory",
    "It shields you.",
    "Pets love to eat this",
    "Koi there",
    "An interesting petal. Only takes 1 damage per hit",
    "A token of power"
};

struct rr_mob_data RR_MOB_DATA[rr_mob_id_max] = {
    // id,                         min_rarity,          max_rarity,             name,              hp, dmg, size, danger, loot
    // Hell Creek mobs
    {rr_mob_id_triceratops,        rr_rarity_id_epic,   rr_rarity_id_ultimate, "Triceratops",      45, 15, 30.0f, 3,   {{rr_petal_id_leaf,    0.15},{rr_petal_id_fossil,     0.06}}},
    {rr_mob_id_trex,               rr_rarity_id_epic,   rr_rarity_id_eternal, "T-Rex",            40, 25, 32.0f, 4,   {{rr_petal_id_stinger, 0.06},{rr_petal_id_egg,        0.06}}},
    {rr_mob_id_fern,               rr_rarity_id_common, rr_rarity_id_eternal, "Fern",             35,  5, 24.0f, 1,   {{rr_petal_id_leaf,    0.1},{rr_petal_id_azalea,      0.25}}},
    {rr_mob_id_tree,               rr_rarity_id_common, rr_rarity_id_ultimate, "Tree",            100,  5, 64.0f, 2.15,{{rr_petal_id_leaf,    0.5},{rr_petal_id_peas,        0.25},{rr_petal_id_seed,       0.10}}},
    {rr_mob_id_pteranodon,         rr_rarity_id_epic,   rr_rarity_id_ultimate, "Pteranodon",       40, 15, 20.0f, 5,   {{rr_petal_id_shell,   0.1},{rr_petal_id_beak,        0.15}}},
    {rr_mob_id_dakotaraptor,       rr_rarity_id_common, rr_rarity_id_ultimate, "Dakotaraptor",     35, 10, 25.0f, 5,   {{rr_petal_id_crest,   0.1},{rr_petal_id_feather,     0.1},{rr_petal_id_pellet,    0.07}}},
    {rr_mob_id_pachycephalosaurus, rr_rarity_id_common, rr_rarity_id_ultimate,"Pachycephalosaurus",35, 20, 20.0f, 3, {{rr_petal_id_fossil,  0.1},{rr_petal_id_light,       0.1},{rr_petal_id_web,       0.05}}},
    {rr_mob_id_ornithomimus,       rr_rarity_id_common, rr_rarity_id_ultimate, "Ornithomimus",     25, 10, 20.0f, 2,   {{rr_petal_id_feather, 0.1},{rr_petal_id_droplet,     0.06},{rr_petal_id_pellet,     0.1}}},
    {rr_mob_id_ankylosaurus,       rr_rarity_id_epic,   rr_rarity_id_ultimate, "Ankylosaurus",     50, 10, 30.0f, 4,   {{rr_petal_id_club,    0.15},{rr_petal_id_gravel,     0.1}}},
    {rr_mob_id_meteor,             rr_rarity_id_rare,   rr_rarity_id_ultimate, "Meteor",          100, 10, 32.0f, 1,   {{rr_petal_id_magnet,  0.65},{rr_petal_id_uranium,    0.25}}},
    {rr_mob_id_quetzalcoatlus,     rr_rarity_id_epic,   rr_rarity_id_ultimate, "Quetzalcoatlus",   65, 20, 28.0f, 5,   {{rr_petal_id_beak,    0.07},{rr_petal_id_fossil,     0.1},{rr_petal_id_lightning, 0.05}}},
    {rr_mob_id_edmontosaurus,      rr_rarity_id_epic,   rr_rarity_id_ultimate, "Edmontosaurus",    50, 15, 30.0f, 3,   {{rr_petal_id_bone,    0.005},{rr_petal_id_fossil,    0.1},{rr_petal_id_third_eye, 0.08}}},
    {rr_mob_id_pectinodon,         rr_rarity_id_rare,   rr_rarity_id_ultimate, "Pectinodon",       35, 10, 25.0f, 4,   {{rr_petal_id_stick,   0.01}, {rr_petal_id_feather, 0.01}, {rr_petal_id_wax, 0.01}}},

    // Garden mobs
    {rr_mob_id_ant,                rr_rarity_id_common, rr_rarity_id_ultimate, "Ant",              42, 12, 30.0f, 2,   {{rr_petal_id_pellet, 0.1}, {rr_petal_id_rice, 0.15}, {rr_petal_id_mandible, 0.01}}},
    {rr_mob_id_hornet,             rr_rarity_id_rare,   rr_rarity_id_eternal, "Hornet",           40, 10, 30.0f, 4,   {{rr_petal_id_missile, 0.1}, {rr_petal_id_crest, 0.1}}},
    {rr_mob_id_dragonfly,          rr_rarity_id_unusual,rr_rarity_id_ultimate, "Dragonfly",       50, 15, 27.0f,2,   {{rr_petal_id_mint, 0.1}, {rr_petal_id_third_eye, 0.1}}},
    {rr_mob_id_honeybee,           rr_rarity_id_common, rr_rarity_id_ultimate, "Honeybee",         25, 20, 26.0f, 3,   {{rr_petal_id_wax, 0.1}, {rr_petal_id_stinger, 0.1}}},
    {rr_mob_id_beehive,            rr_rarity_id_rare, rr_rarity_id_exotic, "Beehive",         500,  0, 30.0f, 1.15,   {}},
    {rr_mob_id_spider,             rr_rarity_id_rare,   rr_rarity_id_ultimate, "Spider",           25, 30, 28.0f, 4,   {{rr_petal_id_web, 0.1},{rr_petal_id_iris, 0.05},{rr_petal_id_light, 0.25}}},
    {rr_mob_id_house_centipede,    rr_rarity_id_common, rr_rarity_id_ultimate, "House Centipede",  50, 15, 35.0f, 2,   {{rr_petal_id_peas, 0.5},{rr_petal_id_sand, 0.1}}},
    // {rr_mob_id_lanternfly,        rr_rarity_id_unusual, rr_rarity_id_ultimate, "Lanternfly",       20, 10, 25.0f, 1,   {{rr_petal_id_mint, 0.1},{rr_petal_id_sand, 0.05}}},


    // Florr Garden Mobs
    {rr_mob_id_baby_ant,           rr_rarity_id_common, rr_rarity_id_ultimate, "Baby Ant",         42, 12, 30.0f, 1,   {}},
    {rr_mob_id_worker_ant,         rr_rarity_id_common, rr_rarity_id_ultimate, "Worker Ant",       42, 12, 30.0f, 1,   {}},
    {rr_mob_id_queen_ant,          rr_rarity_id_common, rr_rarity_id_ultimate, "Queen Ant",        42, 12, 30.0f, 1,   {}},
    {rr_mob_id_ladybug,            rr_rarity_id_common, rr_rarity_id_ultimate, "Ladybug",          42, 12, 30.0f, 1,   {}},
    {rr_mob_id_rock,               rr_rarity_id_common, rr_rarity_id_ultimate, "Rock",             42, 12, 30.0f, 1,   {}},

    // Ocean mobs
    {rr_mob_id_kelp,               rr_rarity_id_common, rr_rarity_id_ultimate, "Kelp",             50, 15, 30.0f, 1,   {}},
    {rr_mob_id_seagull,            rr_rarity_id_common, rr_rarity_id_ultimate, "Seagull",          50, 15, 30.0f, 1,   {}},
    {rr_mob_id_kingmackarel,       rr_rarity_id_common, rr_rarity_id_ultimate, "King Mackerel",    50, 15, 30.0f, 1,   {}},
    {rr_mob_id_seasnail,           rr_rarity_id_common, rr_rarity_id_ultimate, "Sea Snail",        50, 15, 30.0f, 1,   {}},

    // Florr Ocean Mobs
    {rr_mob_id_jellyfish,          rr_rarity_id_common, rr_rarity_id_ultimate, "Jellyfish",        50, 15, 30.0f, 1,   {}},
    {rr_mob_id_shell,              rr_rarity_id_common, rr_rarity_id_ultimate, "Shell",            50, 15, 30.0f, 1,   {}},
    {rr_mob_id_crab,               rr_rarity_id_common, rr_rarity_id_ultimate, "Crab",             50, 15, 30.0f, 1,   {}},
    {rr_mob_id_sponge,             rr_rarity_id_common, rr_rarity_id_ultimate, "Sponge",           50, 15, 30.0f, 1,   {}},
    {rr_mob_id_starfish,           rr_rarity_id_common, rr_rarity_id_ultimate, "Starfish",         50, 15, 30.0f, 1,   {}},
    {rr_mob_id_bubble,             rr_rarity_id_common, rr_rarity_id_ultimate, "Bubble",           3,   0, 30.0f, 1,   {}},

    // Portals
    {rr_mob_id_portal_garden,      rr_rarity_id_common, rr_rarity_id_ultimate, "Portal Garden",    500, 0, 30.0f, 1,    {}},
    {rr_mob_id_portal_ocean,       rr_rarity_id_common, rr_rarity_id_ultimate, "Portal Ocean",     500, 0, 30.0f, 1,    {}},
    {rr_mob_id_portal_hell_creek,  rr_rarity_id_common, rr_rarity_id_ultimate, "Portal Hell Creek",500, 0, 30.0f, 1,  {}},

    // SFX Abbilty
    {rr_mob_id_fire,             rr_rarity_id_common, rr_rarity_id_ultimate, "Fire",           50,   10, 30.0f, 1,   {}},

    // Desert
    {rr_mob_id_whirlpool, rr_rarity_id_common, rr_rarity_id_ultimate, "whirlpool", 600, 10, 30.f, 1, {}}
};


uint32_t RR_MOB_RARITY_DIFFICULTY_COEFFICIENTS[rr_rarity_id_max] = {
    1, // common
    1, // uncommon
    1, // rare
    1, // epic
    1.5, // legendary
    2, // mythic
    3, // exotic
    5, // ultimate
    10, // eternal ( boss )
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
    25,   //edmo,
    10    //pectinodon
};
double RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {
    5,    // triceratops
    0,    // trex
    10,    // fern
    0.5,    // tree
    0,    // pteranodon
    0,    // dakotaraptor
    0,    // pachycephalosaurus
    0,    // ornithomimus
    0,    // ankylosaurus
    0.5,    // meteor
    0,    // quetzalcoatlus
    0,    // edmontosaurus
    25,    // pectinodon
    70,    // ant
    75,    // hornet
    40,    // dragonfly
    40,    // honeybee
    5,    // beehive
    10,    // spider
    0,    // house centipede
    0,    // baby ant
    0,    // worker ant
    0,    // queen ant
    0,    // ladybug
    0,    // rock
    10,    // kelp
    0,    // seagull
    0,    // king mackarel
    0,    // sea snail
    0,  // jellyfish
    0,  // shell
    0,  // crab
    0,  // sponge
    0,  // starfish
    0,  // bubble
};


double RR_OCEAN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {
    0,    // triceratops
    0,    // trex
    0,    // fern
    0,    // tree
    0,    // pteranodon
    0,    // dakotaraptor
    0,    // pachycephalosaurus
    0,    // ornithomimus
    0,    // ankylosaurus
    0,    // meteor
    0,    // quetzalcoatlus
    0,    // edmontosaurus
    0,    // pectinodon
    0,    // ant
    0,    // hornet
    0,    // dragonfly
    0,    // honeybee
    0,    // beehive
    0,    // spider
    0,    // house centipede
    0,    // baby ant
    0,    // worker ant
    0,    // queen ant
    0,    // ladybug
    0,    // rock
    5,    // kelp
    2,    // seagull
    1,    // king mackarel
    2,    // sea snail
    0.5,    // jellyfish
    0.5,    // shell
    0.5,    // crab
    0.5,    // sponge
    0.5,    // starfish
    0.5,    // bubble
};
struct rr_petal_rarity_scale RR_PETAL_RARITY_SCALE[rr_rarity_id_max] = {
    {1,    240, 45,  0.08, 15},
    {1.8,  120, 60,  0.15, 30}, // 15
    {3.5,  60,  75,  0.22, 45}, // 22
    {6.8,  30,  100, 0.30, 60},  // 30
    {12.5, 15,  125, 0.37, 75}, // 37
    {24.5, 7.5, 150, 0.45, 90}, // 45
    {65,   2, 220, 0.52, 108}, // 52
    {180,  0.5, 250, 0.60, 120}, // 59
    {180,  0.5, 250, 0.60, 120}, // 59
};


struct rr_mob_rarity_scale RR_MOB_RARITY_SCALING[rr_rarity_id_max] = {
    {0.2,  0.2,1.0},
    {1.9,  1.1,1.2},
    {5.8,  2.6,1.5},
    {14.4, 5.0,2.0},
    {40,   7.7,2.8},
    {200, 13.5,4.0},
    {2860,24.6,7.0},
    {958e2,42.0,10.0},
    {999e2, 300.0, 20}
};
// clang-format on

uint32_t RR_RARITY_COLORS[rr_rarity_id_max] = {
    0xff7ff06d, 0xffffe65d, 0xff4d52e3, 0xff861fde,
    0xffde201f, 0xff21dbde, 0xffff2a75, 0xff30fca4, 0xff89e4df};

char const *RR_RARITY_NAMES[rr_rarity_id_max] = {
    "Common",    "Uncommon", "Rare",   "Epic",
    "Legendary", "Mythic",   "Exotic", "Ultimate", "Eternal"};

double RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_max + 1] = {
    0, 1, 6, 10, 15, 25, 160, 1200, 250};

double RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_exotic + 2] = {
    0, 1, 8, 15, 35, 125, 380, 250};
double RR_MOB_LOOT_RARITY_COEFFICIENTS[rr_rarity_id_max] = {2.5, 4,  6,   15,
                                                            35,  50, 190, 220,380, 320};

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
{_,s,S,_,_,S,S,S,s,S,_,_,X,X,X,X,X,X,_,_,x,x,x,x,x,M,M,M,M,_,_,_,m,m,M,M,_,_,_,S},
{_,X,_,_,_,_,S,s,S,s,_,_,_,_,_,_,X,X,X,_,_,x,x,x,_,M,M,M,M,M,_,_,m,_,_,M,_,_,S,S},
{_,s,X,s,_,_,s,S,s,S,_,_,_,_,_,_,_,_,X,X,X,X,s,_,_,_,_,M,M,M,_,_,m,_,M,M,_,_,s,S},
{s,X,_,_,_,s,X,s,S,_,_,_,_,M,M,M,_,_,_,_,_,s,X,_,_,_,_,M,M,M,_,_,L,_,M,_,_,X,s,s},
{X,_,_,X,s,X,s,X,_,_,_,M,M,M,M,m,m,m,m,m,_,_,_,_,_,_,M,M,M,_,_,L,L,_,M,_,_,s,X,s},
{s,_,X,X,X,s,X,_,_,M,M,M,M,_,_,_,m,m,m,m,L,m,m,m,m,m,m,M,_,_,_,L,_,_,M,_,_,X,s,X},
{X,X,X,X,_,_,_,_,M,M,M,_,M,M,m,_,_,_,m,L,L,_,_,_,_,_,_,_,_,_,_,L,_,x,x,_,_,X,X,s},
{X,X,X,_,_,X,_,_,x,M,M,_,M,m,m,m,m,_,_,_,L,L,_,_,_,l,_,_,_,_,_,L,_,x,x,_,_,_,X,X},
{_,X,X,X,X,X,_,x,x,_,_,_,m,m,m,m,m,m,_,_,_,L,L,_,l,l,l,_,_,_,_,l,_,x,_,_,_,_,X,X},
{_,_,X,X,_,_,_,x,x,_,M,m,m,m,m,m,m,L,L,_,_,L,l,l,l,l,l,l,_,_,l,l,_,x,_,_,_,_,_,X},
{_,_,_,X,x,x,x,x,_,_,M,M,m,_,_,_,L,L,L,L,_,_,l,l,_,_,_,l,_,_,l,_,_,x,_,_,_,X,X,X},
{X,X,_,_,_,_,_,_,_,M,M,M,_,_,_,_,_,L,L,L,_,_,_,_,_,_,l,E,E,_,l,_,x,x,_,_,X,X,X,_},
{X,X,X,_,_,x,_,_,M,M,M,_,_,L,L,_,_,_,L,L,l,_,l,_,_,l,E,E,E,l,l,_,x,x,X,_,X,X,_,_},
{_,X,x,_,x,x,M,_,_,M,M,_,L,L,L,L,_,_,_,_,l,l,l,l,_,E,E,E,_,l,l,_,_,_,x,_,x,_,_,_},
{_,x,x,_,x,M,M,M,_,M,M,_,L,L,L,L,L,_,_,_,_,_,_,l,_,_,E,E,_,_,l,l,_,_,x,x,x,_,_,_},
{_,x,x,_,M,_,_,M,_,_,M,_,L,L,L,L,l,l,_,_,_,l,l,E,E,_,E,e,e,_,l,l,_,_,x,x,x,_,_,_},
{_,x,x,_,M,M,_,M,M,M,M,_,L,L,L,l,l,l,l,l,l,l,E,E,E,e,e,e,e,_,l,l,L,_,x,x,_,_,_,_},
{_,x,x,_,_,M,M,M,M,M,m,_,_,L,_,l,l,l,l,l,l,E,E,E,e,e,e,e,e,_,_,L,L,L,_,x,x,_,_,_},
{_,x,x,x,_,M,M,M,_,m,m,_,_,L,_,l,l,l,l,l,E,E,E,e,e,e,e,e,e,e,_,_,L,L,_,x,x,M,_,_},
{_,_,x,x,M,M,M,M,_,m,m,m,_,L,_,_,l,l,L,_,_,E,E,E,_,_,e,e,e,R,_,_,L,L,_,_,M,M,_,_},
{X,_,_,x,x,M,M,_,_,_,m,m,m,L,_,_,_,L,L,l,l,_,E,E,_,_,_,_,R,R,R,_,_,L,m,_,_,M,M,_},
{X,X,_,_,x,x,M,_,_,_,_,m,m,m,m,_,_,l,l,l,l,l,l,E,l,_,_,_,_,R,R,r,_,_,m,m,_,M,M,_},
{X,X,X,_,x,x,x,_,_,_,_,m,m,m,m,m,_,_,l,l,l,l,l,l,l,l,l,l,_,_,r,r,r,_,_,m,_,_,M,M},
{_,X,X,_,_,x,_,_,_,_,m,m,m,m,m,m,_,_,_,_,_,_,_,l,l,l,l,l,L,_,r,r,r,U,_,m,m,M,M,M},
{_,X,X,x,_,x,_,M,_,M,M,m,m,m,m,m,m,m,m,m,_,_,l,l,l,l,l,L,L,_,r,r,U,U,U,_,_,M,M,_},
{_,X,x,x,x,x,_,M,_,M,M,M,m,_,_,m,m,m,m,_,_,_,l,l,l,_,_,L,_,_,r,U,U,_,U,_,_,_,_,_},
{_,_,X,_,_,x,_,M,M,M,M,_,_,_,_,m,m,m,L,L,L,L,L,l,L,_,_,_,_,U,U,U,U,U,u,u,u,C,u,u},
{_,_,X,X,_,x,_,_,M,_,M,_,_,m,m,m,m,_,_,_,L,L,L,L,L,L,_,_,_,r,U,U,_,_,_,_,C,C,C,u},
{_,_,_,x,_,x,x,_,_,_,M,M,_,_,_,_,L,L,L,L,L,_,L,L,L,L,L,L,_,r,r,_,_,c,c,_,_,C,_,u},
{X,_,_,x,x,x,x,x,_,M,M,_,_,L,L,_,_,_,L,L,_,_,_,_,_,L,L,_,_,r,r,_,c,c,c,c,c,c,_,u},
{X,_,_,_,x,x,x,x,x,M,_,_,_,L,L,L,L,_,_,_,_,L,L,m,m,L,L,_,_,r,r,_,_,c,c,c,c,_,_,U},
{X,X,_,_,_,_,x,x,x,_,_,_,m,L,L,L,L,L,L,L,L,L,L,L,m,m,_,_,R,R,R,R,_,_,_,_,_,_,_,U},
{X,X,X,X,_,_,_,x,_,_,m,m,m,m,L,L,_,l,l,L,L,L,L,L,L,_,_,R,R,R,R,R,R,R,R,R,r,_,U,U},
{X,x,X,X,X,_,_,x,_,m,m,m,m,_,m,L,_,l,l,l,L,_,_,_,_,_,e,e,R,R,R,_,_,_,_,_,r,r,r,U},
{x,x,x,X,X,_,_,_,_,M,_,m,m,_,m,m,_,_,l,_,_,_,E,E,e,e,e,e,e,_,_,_,_,M,M,_,_,_,_,_},
{_,x,x,x,_,_,_,M,M,M,_,m,m,_,m,m,m,_,l,l,l,E,E,E,E,e,e,e,_,_,_,_,m,M,M,M,_,_,_,x},
{_,x,_,_,_,_,M,M,_,M,_,m,m,_,m,m,m,_,_,l,l,l,_,_,_,_,_,_,_,_,m,m,m,m,M,_,_,M,M,M},
{_,x,x,x,x,M,M,M,_,M,_,_,M,_,_,m,m,m,_,l,l,_,_,_,_,_,_,L,L,m,m,m,m,m,m,_,M,M,M,M},
{_,x,x,x,_,_,_,_,_,M,M,_,M,M,_,m,m,M,_,l,l,l,l,l,L,L,L,L,L,_,_,_,_,m,M,M,M,M,M,M},
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
     {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,L,L,L,L,L,L,L,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,_,_,_,_,_,l,l,l,L,L,L,L,L,L,L,L,L,L,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,_,_,_,_,l,l,l,l,_,_,L,L,_,_,L,L,L,L,L,_,_,x,M,_,_,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,_,_,_,l,l,l,l,_,_,_,_,L,_,_,_,L,L,L,L,_,_,M,M,M,M,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,l,l,l,l,l,_,_,_,l,_,_,L,L,_,_,_,_,L,L,L,_,M,M,M,M,M,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,l,l,l,l,l,l,l,l,l,l,_,_,_,L,L,_,_,_,_,L,L,_,_,M,M,M,M,M,_,_,_,_,_},
     {_,_,_,_,_,_,l,l,l,l,_,_,l,l,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,M,M,_,M,M,M,_,_,_,_},
     {_,_,_,_,_,_,l,l,l,_,_,l,l,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,M,_,_,M,M,_,_,_,_},
     {_,_,_,_,_,_,_,l,l,_,_,_,_,_,_,_,l,l,_,l,l,l,l,l,_,_,_,L,L,L,_,M,_,_,M,M,M,_,_,_},
     {_,_,_,_,_,_,_,_,E,_,_,_,_,_,l,l,l,l,l,l,l,l,l,l,l,l,_,_,_,L,_,M,_,_,_,M,M,_,_,_},
     {_,_,_,_,l,l,_,_,E,E,_,_,E,l,l,l,l,l,l,l,l,l,l,l,l,L,L,L,L,L,_,M,M,_,_,M,M,_,_,_},
     {_,_,_,l,l,l,E,E,E,E,E,E,E,E,l,l,l,l,_,_,_,_,_,_,L,L,L,L,L,L,_,M,M,_,_,_,M,M,_,_},
     {_,_,_,l,l,l,l,_,_,E,E,E,E,E,E,l,_,_,_,_,_,_,_,_,_,_,L,L,L,L,_,_,M,_,_,_,M,M,_,_},
     {_,_,_,l,l,l,_,_,_,E,E,E,E,E,_,_,_,_,_,x,x,x,x,_,_,_,_,L,L,L,L,_,M,M,_,_,M,M,_,_},
     {_,_,l,l,l,l,_,_,E,E,E,E,E,_,_,_,x,x,x,x,x,x,x,x,_,_,_,_,L,L,L,_,_,m,_,_,M,M,_,_},
     {_,_,l,l,l,_,_,E,E,E,E,_,_,_,x,x,x,x,x,_,_,x,x,_,_,_,_,_,_,L,m,m,_,_,m,_,M,M,M,_},
     {_,_,l,l,l,_,_,E,E,E,_,_,_,X,X,x,x,x,_,_,_,x,x,_,_,_,M,_,_,_,m,m,m,_,m,m,m,M,M,_},
     {_,l,l,l,_,_,_,e,e,E,_,_,X,X,X,X,x,_,_,_,x,x,M,_,_,_,M,M,_,_,m,m,m,_,m,m,m,m,M,_},
     {_,l,l,l,_,_,e,e,e,e,_,_,X,X,X,X,_,_,_,_,x,M,M,_,_,_,M,M,_,_,_,m,m,m,m,_,_,M,M,_},
     {_,l,l,l,_,_,e,e,e,_,_,X,X,X,X,X,_,_,_,_,M,M,M,M,_,_,M,M,_,_,_,m,m,m,_,_,_,M,M,_},
     {_,l,l,l,_,_,e,e,e,_,_,X,_,_,_,X,X,_,_,_,_,M,M,M,_,M,M,M,M,_,_,_,m,m,_,_,M,M,M,_},
     {_,l,l,l,_,_,R,R,e,_,_,X,_,_,_,_,X,_,_,_,_,_,M,M,M,M,M,M,M,M,_,_,m,m,_,_,M,M,_,_},
     {_,_,l,l,_,_,R,R,R,R,_,X,X,_,_,_,X,X,_,_,_,_,_,M,M,M,M,M,M,M,_,_,m,m,_,_,M,M,_,_},
     {_,_,L,l,_,_,R,R,R,R,_,X,X,_,_,_,_,X,X,_,_,_,_,_,_,M,M,M,M,M,M,m,m,m,_,_,M,M,_,_},
     {_,_,L,L,L,_,e,R,R,u,_,_,X,X,_,_,_,X,X,X,_,_,_,_,_,_,_,M,M,M,M,M,m,_,_,M,M,M,_,_},
     {_,_,_,L,L,_,R,R,u,u,_,_,_,X,X,X,X,X,X,X,_,_,_,_,_,_,_,_,_,M,M,M,M,_,_,M,M,_,_,_},
     {_,_,_,L,L,_,_,u,u,u,_,_,_,X,X,X,X,X,X,_,_,_,X,X,X,X,_,_,_,_,M,M,_,_,_,M,M,_,_,_},
     {_,_,_,L,L,_,_,u,u,u,_,_,_,_,X,X,X,X,_,_,_,X,X,X,X,X,X,_,_,_,M,M,_,_,M,M,M,_,_,_},
     {_,_,_,_,L,_,_,u,u,u,u,_,_,_,S,s,S,s,_,_,_,x,X,X,X,X,X,_,_,_,M,_,_,_,M,M,_,_,_,_},
     {_,_,_,_,L,L,_,_,u,u,u,_,_,_,_,s,S,_,_,_,x,x,x,X,X,X,X,_,_,_,M,_,_,M,M,M,_,_,_,_},
     {_,_,_,_,_,L,_,_,u,u,_,_,_,_,_,_,_,_,_,_,x,x,x,x,X,X,_,_,_,_,M,M,_,_,M,M,_,_,_,_},
     {_,_,_,_,_,L,L,_,_,_,_,_,_,m,m,m,m,_,_,_,x,x,x,x,x,X,_,_,_,M,M,M,M,M,M,_,_,_,_,_},
     {_,_,_,_,_,_,L,L,L,m,m,m,m,m,m,m,m,m,_,_,_,x,x,x,_,_,_,_,_,M,M,M,M,M,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,L,m,m,m,m,m,m,m,m,m,m,m,_,_,x,x,_,_,_,_,_,M,M,M,M,M,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,m,m,m,m,m,m,m,m,m,m,m,_,_,x,x,_,_,x,x,M,M,M,M,M,_,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,_,_,m,m,m,m,m,m,m,m,M,M,_,x,x,x,x,x,x,x,M,M,_,_,_,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,_,_,_,_,_,m,m,m,m,M,M,M,_,_,x,x,x,x,x,x,_,_,_,_,_,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,M,M,M,M,_,x,x,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_},
     {_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}
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
    {MAZE_ENTRY(HELL_CREEK, 1024), {{33, 29}, {33, 27}, {32, 24}, {28, 19}}},
    {MAZE_ENTRY(OCEAN, 1024), {{6, 13}, {11, 15}, {16, 17}, {22, 23}}},
    {MAZE_ENTRY(GARDEN, 1024), {{8, 28},{7, 22},{7, 19},{30, 15}}},
    {MAZE_ENTRY(BURROW, 512), {{0}, {0}, {0}, {0}}}
};

uint8_t RR_GLOBAL_BIOME = rr_biome_id_garden;
uint16_t RR_GLOBAL_PORT = 2053;
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
