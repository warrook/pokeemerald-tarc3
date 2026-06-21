#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen9[] =
{
#endif

#define TAMAGOTCHI_YOUNG_INFO                 \
        .types = MON_TYPES(TYPE_MYSTERY),   \
        .catchRate = 255,                   \
        .genderRatio = PERCENT_FEMALE(50),  \
        .eggCycles = 10,                    \
        .friendship = STANDARD_FRIENDSHIP,  \
        .growthRate = GROWTH_FAST,          \


    [SPECIES_BUMBLE_SKY] =
    {
        .speciesName = _("Bumble Young"),
        TAMAGOTCHI_YOUNG_INFO
    },

#ifdef __INTELLISENSE__
};
#endif