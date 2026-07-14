import csv
import os
import subprocess
import collections

first_species_index = 1573

## include/constants/species.h
species_constants = [] # SPECIES_TAMAGOTCHI = 1573,

## include/constants/pokedex.h
# NATIONAL_DEX_TAMAGOTCHI,
nat_dex_constants = [] 

# F(TAMAGOTCHI) \
reg_dex_constants = [] 

## src/data/graphics/pokemon.h
# const u32 gMonFrontPic_Tamagotchi[] = INCGFX_U32("graphics/pokemon/tamagotchi/(anim_)front.png", ".4bpp.lz");
# const u32 gMonBackPic_Tamagotchi[] = INCGFX_U32("graphics/pokemon/tamagotchi/back.png", ".4bpp.lz");
# const u16 gMonPalette_Tamagotchi[] = INCGFX_U16("graphics/pokemon/tamagotchi/normal.pal", ".gbapal");
# const u16 gMonShinyPalette_Tamagotchi[] = INCGFX_U16("graphics/pokemon/tamagotchi/shiny.pal", ".gbapal");
# const u8 gMonIcon_Tamagotchi[] = INCGFX_U8("graphics/pokemon/tamagotchi/icon.png", ".4bpp");
# const u8 gMonFootprint_Tamagotchi[] = INCGFX_U8("graphics/pokemon/tamagotchi/footprint.png", ".1bpp");
mon_gfx_constants = []

## src/data/pokemon/species_info.h
species_info = []

# Key: Species that evolves
# Value: {condition= destination species}
evolutions: dict[str, dict[str, str]] = {}


# Second pass: Reassemble evolutions with species that evolves as key
# Key: species that evolves
# Value: {condition=destination species}


def fstr(string:str, prefix:str="", suffix:str="", none_if_empty:bool=True, capitalize:bool=True):
    """
    Formats strings in various ways. prefix prepends the given string, suffix appends. If none_if_empty is true, then if string is "", make it "NONE". If capitalize is true, then everything will be made uppercase.
    """
    if string == "" and none_if_empty:
        return prefix + "NONE" + suffix
    if capitalize:
        string = string.upper()
    #handle Shigemi-san => Shigemisan
    s = string.replace("-", "")
    #handle " (Land)" etc => _Land
    s = s.replace(" ", "_")
    s = s.replace("(","")
    s = s.replace(")","")
    return prefix + s + suffix


def format_display_name(string:str):
    """
    Formats a string for display in the Pokedex as a species name. Removes parentheticals and turns -tchi endings into the charmap key TCHI.
    """
    # Strip parenthetical from display name
    if ' (' in string:
        string = string.split(' ')[0]

    # Convert tchi to abbreviation if present
    if string.endswith("tchi"):
        return string.removesuffix("tchi")+"{TCHI}"
    else:
        return string


def generate_palette_if_missing(fpath:str, pal:str):
    """
    Calls gbagfx to generate a palette from the given directory at fpath. If pal is "shiny.pal", sends gbagfx the back sprite to extract the palette from, otherwise it sends the front sprite. It does not try to generate a palette if the image it's targeting does not exist. 
    """
    #if os.path.exists(fpath + pal):
    #    return 0
    
    target = "back.png" if pal == "shiny.pal" else "front.png"
    if not os.path.exists(fpath + target):
        # Skip trying to generate a palette if the base sprite doesn't exist
        return True

    # Call gbagfx
    subprocess.Popen(["tools/gbagfx/gbagfx", fpath + target, fpath + pal])
    return False


def gfx_constant(name_in_row:str, part:str):
    var_name = fstr(name_in_row, capitalize=False)
    fpath = "graphics/pokemon/" + var_name.lower() + "/"

    g = { 
        "variable": part, 
        "name_in_variable": var_name, 
        "path": fpath 
    }
    missing = False
    match part:
        case "FrontPic":
            g["input"] =    "front.png"
            g["output"] =   ".4bpp.lz"
            g["size"] =     "32"
        case "BackPic":
            g["input"] =    "back.png"
            g["output"] =   ".4bpp.lz"
            g["size"] =     "32"
        case "Palette":
            g["input"] =    "normal.pal"
            g["output"] =   ".gbapal"
            g["size"] =     "16"
            generate_palette_if_missing(g["path"], g["input"])
        case "ShinyPalette":
            g["input"] =    "shiny.pal"
            g["output"] =   ".gbapal"
            g["size"] =     "16"
            generate_palette_if_missing(g["path"], g["input"])
        case "Icon":
            g["input"] =    "icon.png"
            g["output"] =   ".4bpp"
            g["size"] =     "8"
        case "Footprint":
            g["input"] =    "footprint.png"
            g["output"] =   ".1bpp"
            g["size"] =     "8"
    missing = False if os.path.exists(g["path"] + g["input"]) else True
    
    return ("// " if missing == True else "") + "const u{size} gMon{variable}_{name_in_variable}[] = INCGFX_U{size}(\"{path}{input}\", \"{output}\");".format_map(g)


def make_mon_gfx_constants(name_in_row:str):
    """
    Calls `gfx_constant` to make variables that will go in `src/data/graphics/pokemon.h`.
    """
    mon_gfx_constants.append(gfx_constant(name_in_row, "FrontPic"))
    mon_gfx_constants.append(gfx_constant(name_in_row, "BackPic"))
    mon_gfx_constants.append(gfx_constant(name_in_row, "Palette"))
    mon_gfx_constants.append(gfx_constant(name_in_row, "ShinyPalette"))
    mon_gfx_constants.append(gfx_constant(name_in_row, "Icon"))
    mon_gfx_constants.append(gfx_constant(name_in_row, "Footprint"))
    mon_gfx_constants.append("")

    return "graphics/pokemon/" + fstr(name_in_row).lower() + "/"


def gfx_str(d:dict, key:str):
    """
    Formats labels into the appropriate names and styles given dictionary created from a species's `graphics_info.csv` (found in their graphics directory), which uses some abbreviated keys.
    """

    # Assume not a macro that ends with a comma
    line_macro = False
    if key in d.keys():
        # Key is present in graphics info csv
        value = d[key]

        if key.endswith("PicSize"):
            # Handle coords size macro
            value = "MON_COORDS_SIZE(" + ", ".join(value.split(' ')) + ")"
        elif key == "shadow":
            # Handle shadow macro, which takes the place of lines in the struct (meaning no , after it, because the macro includes them)
            line_macro = True

            # Capitalize key to fit macro
            key = "SHADOW"
            
            # Shadow entry in csv is like "x y", so split at the space and rejoin with comma
            value = ", ".join(value.split(' '))
        
        # Format output based on if macro or not
        output = "\t.{0} = {1}," if not line_macro else "\t{0}({1})"
        return output.format(key, value)
    elif key.endswith("PicSize"):
        return "\t.{0} = MON_COORDS_SIZE(64, 64),".format(key)


def make_graphics_info_strings(d:dict, name_in_var:str):
    """
    Creates graphics entries for `species_info` from the given dictionary (created from a `graphics_info.csv` in the mon's graphics directory), including: `pokemonScale`, `pokemonOffset`, `trainerScale`, `trainerOffset`, `frontPicSize`, `frontPicYOffset`, `frontAnimId`, `backPicSize`, `backPicYOffset`, `backAnimId`, and `iconPalIndex`.
    
    Also generates `frontPic`, `backPic`, `palette`, `shinyPalette`, and `iconSprite` entries automatically.

    Any missing entries are stripped from the output so as to avoid empty lines in the struct.
    """
    fpath = "graphics/pokemon/" + name_in_var.lower() + "/"
    
    # Generate basics that are not included in graphics_info.csv
    basics = [
        ("\t.frontPic = gMonFrontPic_" + name_in_var + ",") \
            if os.path.exists(fpath + "front.png") else None,
        ("\t.backPic = gMonBackPic_" + name_in_var + ",") \
            if os.path.exists(fpath + "back.png") else None,
        ("\t.palette = gMonPalette_" + name_in_var + ",") \
            if os.path.exists(fpath + "normal.pal") else None,
        ("\t.shinyPalette = gMonShinyPalette_" + name_in_var + ",") \
            if os.path.exists(fpath + "shiny.pal") else None,
        ("\t.iconSprite = gMonIcon_" + name_in_var + ",") \
            if os.path.exists(fpath + "icon.png") else None,
        ("\tFOOTPRINT(" + name_in_var + ")") \
            if os.path.exists(fpath + "footprint.png") else None,
        "\t.frontAnimFrames = ANIM_FRAMES(\n\t\tANIMCMD_FRAME(0,1),\n\t),",
    ]

    return list(filter(None,[
        gfx_str(d, "pokemonScale"),
        gfx_str(d, "pokemonOffset"),
        gfx_str(d, "trainerScale"),
        gfx_str(d, "trainerOffset"),
        basics[0],
        gfx_str(d, "frontPicSize"),
        gfx_str(d, "frontPicYOffset"),
        basics[6],
        gfx_str(d, "enemyMonElevation"),
        gfx_str(d, "shadow"),
        gfx_str(d, "frontAnimId"),
        basics[1],
        gfx_str(d, "backPicSize"),
        gfx_str(d, "backPicYOffset"),
        gfx_str(d, "backAnimId"),
        basics[2],
        basics[3],
        basics[4],
        gfx_str(d, "iconPalIndex"),
        basics[5],
    ]))


def make_mon_evolutions(const_name: str, evo_stage: int, field: str):
    """
    Returns a list of evolutions to go in the EVOLUTION() macro based on given mon and stage.
    """
    evos = []
    if const_name == "BABYMARUTCHI":
        # Babymarutchi evolves with location
        evos.append("{{EVO_LEVEL, 0, SPECIES_LAND_KID, CONDITIONS({{IF_MIN_OVERWORLD_STEPS, 100}}, {{IF_IN_MAPSEC, MAPSEC_LAND_HILLS}})}}".format())
        evos.append("{{EVO_LEVEL, 0, SPECIES_WATER_KID, CONDITIONS({{IF_MIN_OVERWORLD_STEPS, 100}}, {{IF_IN_MAPSEC, MAPSEC_WATER_BEACH}})}}".format())
        evos.append("{{EVO_LEVEL, 0, SPECIES_SKY_KID, CONDITIONS({{IF_MIN_OVERWORLD_STEPS, 100}}, {{IF_IN_MAPSEC, MAPSEC_SKY_MOUNTAIN}})}}".format())
        evos.append("{{EVO_LEVEL, 12, SPECIES_BBMARUTCHI, CONDITIONS({{IF_IN_MAPSEC, MAPSEC_LANDING_SITE}})}}".format())

        return evos

    if const_name in evolutions:
        local_evos = evolutions[const_name]

        if evo_stage == 3 and const_name != "SPROUT_LAND" and const_name != "FLOAT_WATER" and const_name != "ROCKY_SKY":
            # Add missed pseudo-legendaries to certain young
            local_evos.update(evolutions[fstr(field, prefix="ANY_")])

        for condition in local_evos:
            level = 0
            result_mon = "SPECIES_" + local_evos[condition]
            item = "ITEM_"
        
            if evo_stage == 2:
                # Field Kids evolve with diet
                level = 12
                item += condition + "_FOOD"
            elif evo_stage == 3:
                # Young evolve with scents
                level = 20
                item += condition + "_SCENT"
            
            if condition != "NONE":
                cond = ", CONDITIONS({{IF_HOLD_ITEM, {0}}})".format(item)
            else:
                cond = ""

            evos.append("{{EVO_LEVEL, {0}, {1}{2}}}".format(str(level), result_mon, cond))
            
        return evos


def read_mon(row:dict):
    """
    Reads a row from `mon.csv`.
    
    Understatement of the year.
    """
    const_name = fstr(row["Name"]) # Tamagotchi => TAMAGOTCHI
    name_in_var = fstr(row["Name"], capitalize=False)
    # Shigemi-san => Shigemisan

    species_constants.append("SPECIES_{0} = {1},".format(const_name, first_species_index + len(species_constants)))
    nat_dex_constants.append("NATIONAL_DEX_" + const_name + ",")
    reg_dex_constants.append("\tF(" + const_name + ")")
    graphics_dir = make_mon_gfx_constants(row["Name"])

    info = []
    info.append("[SPECIES_{0}] =".format(const_name))
    info.append("{")

    # Base Stats
    stats = {
        "HP": int(row["HP"]),
        "Attack": int(row["ATK"]),
        "Defense": int(row["DEF"]),
        "Speed": int(row["SPD"]),
        "SpAttack": int(row["SpATK"]),
        "SpDefense": int(row["SpDEF"])
    }

    total = 0
    for key, value in stats.items():
        total += value
        info.append("\t.base{0} = {1},".format(key.ljust(9), str(value)))
    #info.append("\t//Base Stat Total: {0}".format(total))

    # Types
    types = [
        fstr(row["Type 1"], "TYPE_"),
        fstr(row["Type 2"], "TYPE_"),
    ]
    if types[1] == "TYPE_NONE":
        del types[1]
    info.append("\t.types = MON_TYPES({0}),".format(', '.join(types)))

    # Catch Rate
    info.append("\t.catchRate = 255,")

    # Experience Yield
    info.append("\t.expYield = 67,")

    # Effort Value Yield
    # TODO: Fix this; mons younger than adult give no EVs and that seems wrong
    evo_stage = int(row["Stage"])
    if evo_stage == 4:
        evYield = {}
        l = sorted(stats)
        val1 = stats[l[0]]
        val2 = stats[l[1]]
        val3 = stats[l[2]]

        avg_top3 = (val1 + val2 + val3) / 3
        top3_proximity = val1 - avg_top3

        if top3_proximity >= 20:
            #Highest is way higher
            evYield[l[0]] = 3
        elif top3_proximity >= 10:
            #Top 3 are less different
            evYield[l[0]] = 2
            evYield[l[1]] = 1
        else:
            #All three are close enough
            evYield[l[0]] = 1
            evYield[l[1]] = 1
            evYield[l[2]] = 1
        for key, value in evYield.items():
            info.append("\t.evYield_{0} = {1},".format(key, value))
        
    # Breeding Info
    info.append("\t.genderRatio = PERCENT_FEMALE(50),")
    info.append("\t.eggCycles = 10,")
    info.append("\t.friendship = STANDARD_FRIENDSHIP,")
    info.append("\t.growthRate = GROWTH_MEDIUM_FAST,")
    if const_name == "BBMARUTCHI":
        info.append("\t.eggGroups = MON_EGG_GROUPS(EGG_GROUP_DITTO),")
    elif evo_stage == 4:
        # Only adults can breed
        info.append("\t.eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),")
    else:
        info.append("\t.eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),")

    # Abilities
    abilities = [
        fstr(row["Ability 1"],"ABILITY_"),
        fstr(row["Ability 2"],"ABILITY_"),
        fstr(row["Ability Hidden"],"ABILITY_"),
    ]
    info.append("\t.abilities = { " + ', '.join(abilities) + " },")

    # Dex Info
    #.bodyColor
    species_name = format_display_name(row["Name"])
    info.append("\t.speciesName = _(\"{0}\"),".format(species_name))
    #.cryId
    info.append("\t.natDexNum = NATIONAL_DEX_" + const_name + ",")
    tama_field = row["Field"]
    young = row["Young"]
    category = ""
    if const_name == "BABYMARUTCHI":
        category = "Baby"
    elif const_name == "BBMARUTCHI":
        category = "Mystery"
    elif young == "Legendary":
        # Legendary cases
        match const_name:
            case "SHINIGAMI":
                category = "Grim"
            case "KURITEN":
                category = "Angel"
    else:
        category = tama_field + " "
        match evo_stage:
            #case 1 is covered by above conditional
            case 2:
                category += "Kid" #e.g. Land Kid
            case 3:
                category += "Teen" #e.g. Land Teen
            case 4:
                category += young #e.g. Land Roar
    info.append("\t.categoryName = _(\"{0}\"),".format(category))

    gfx_dict = {}
    try:
        f = open(graphics_dir + "graphics-info.csv", newline='')
    except FileNotFoundError:
        print("No graphics-info.csv found in " + graphics_dir)
    else:
        with open(graphics_dir + "graphics-info.csv", newline='') as f:
            # pokemonScale
            # pokemonOffset
            # trainerScale
            # trainerOffset
            # //frontPic
            # frontPicSize
            # frontPicYOffset
            # frontAnimId
            # //backPic
            # backPicSize
            # backPicYOffset
            # backAnimId
            # //palette
            # // shinyPalette
            # // iconSprite
            # iconPalIndex
            reader = csv.DictReader(f)
            for row in reader:
                gfx_dict[row["field"]] = row["value"]
    graphics_info = make_graphics_info_strings(gfx_dict, name_in_var)

    info.extend(graphics_info)

    # TODO: Learnsets, evolutions

    # Evolutions
    evos = make_mon_evolutions(const_name, evo_stage, tama_field)
    if evos:
        info.append("\t.evolutions = EVOLUTION({0}),".format(",\n\t\t\t\t\t\t\t".join(evos)))


    info.append("},")
    info.append("")

    species_info.append("\n".join(info))


def read_evolutions(row: dict):
    const_name = fstr(row["Name"])
    tama_field = fstr(row["Field"])
    young = fstr(row["Young"])
    evo_stage = int(row["Stage"])

    if const_name == "BBMARUTCHI" or young == "Legendary":
        pass
    elif evo_stage == 1:
        pass
    else:
        condition = ""
        prevo = ""

        if evo_stage == 2:
            prevo = "BABYMARUTCHI"
            condition = tama_field
        elif evo_stage == 3:
            # Evolves from Kid with Diet
            prevo = fstr(tama_field, suffix="_KID")
            condition = fstr(row["Diet"])
        elif evo_stage == 4:
            # Evolves from Young with Scents
            prevo = fstr(string=young, suffix="_" + tama_field)
            condition = fstr(row["Scent"])

        if prevo in evolutions.keys():
            evolutions[prevo][condition] = const_name
        else:
            evolutions[prevo] = {condition: const_name}


# Key: Species that evolves
# Value: dictionary of evolutions with key: condition and value: species
#evos: dict[str, dict[str, str]]




def output_species_constants():
    """
    Generate file to be included in [include/constants/species.h].
    """
    output = [
        "// Include this in include/constants/species.h\n",
        "#ifdef __INTELLISENSE__",
        "enum __attribute((packed)) SpeciesImported",
        "{",
        "#endif",
        ""
    ]

    output.extend(species_constants)
    output.append("\n#ifdef __INTELLISENSE__\n};\n#endif")

    with open("include/constants/imported_species.h", "w+") as f:
        f.write('\n'.join(output))


def output_nat_dex_constants():
    """
    Generate file to be included in the national dex portion of [include/constants/pokedex.h].
    """
    output = [
        "// Include this in include/constants/pokedex.h, and don't",
        "// forget to update NATIONAL_DEX_COUNT!\n",
        "#ifdef __INTELLISENSE__",
        "enum NationalDexOrderImported",
        "{",
        "#endif",
        ""
    ]

    output.extend(nat_dex_constants)
    output.append("\n#ifdef __INTELLISENSE__\n};\n#endif")

    with open("include/constants/imported_national_dex.h", "w+") as f:
        f.write('\n'.join(output))


def output_reg_dex_constants():
    """
    Generate file to be included in the regional dex portion of [include/constants/pokedex.h].
    """
    output = [
        "// Copy into include/constants/pokedex.h everything below,",
        "// replacing the FOREACH_SPECIES_IN_HOENN_DEX_ORDER(F) macro,",
        "// and don't forget to update HOENN_DEX_COUNT!",
        "/*",
        "",
        "#define FOREACH_SPECIES_IN_HOENN_DEX_ORDER(F) \\",
    ]

    #output.extend(reg_dex_constants)
    output.append(' \\\n'.join(reg_dex_constants))
    output.append("\n*/")

    with open("include/constants/imported_regional_dex.h", "w+") as f:
        f.write('\n'.join(output).expandtabs(4))


# const u32 gMonFrontPic_Tamagotchi[] = INCGFX_U32("graphics/pokemon/tamagotchi/(anim_)front.png", ".4bpp.lz");
# const u32 gMonBackPic_Tamagotchi[] = INCGFX_U32("graphics/pokemon/tamagotchi/back.png", ".4bpp.lz");
# const u16 gMonPalette_Tamagotchi[] = INCGFX_U16("graphics/pokemon/tamagotchi/normal.pal", ".gbapal");
# const u16 gMonShinyPalette_Tamagotchi[] = INCGFX_U16("graphics/pokemon/tamagotchi/shiny.pal", ".gbapal");
# const u8 gMonIcon_Tamagotchi[] = INCGFX_U8("graphics/pokemon/tamagotchi/icon.png", ".4bpp");
# const u8 gMonFootprint_Tamagotchi[] = INCGFX_U8("graphics/pokemon/tamagotchi/footprint.png", ".1bpp");
def output_mon_gfx_constants():
    """
    Generate file to be included in [src/data/graphics/pokemon.h].
    """
    output = [
        "// Include this in src/data/graphics/pokemon.h",
        "",
    ]
    output.extend(mon_gfx_constants)
    with open("src/data/graphics/imported_graphics.h", "w+") as f:
        f.write('\n'.join(output).expandtabs(4))
    return


def output_species_info():
    """
    Generate file to be included in [src/data/pokemon/species_info.h].
    """
    output = [
        "// Include this in src/data/pokemon/species_info.h\n"
        "#ifdef __INTELLISENSE__",
        "const struct SpeciesInfo gSpeciesInfoImported[] =",
        "{",
        "#endif",
        ""
    ]
    output.extend(species_info)
    output.append("\n#ifdef __INTELLISENSE__\n};\n#endif")

    with open("src/data/pokemon/imported_species_info.h", "w+") as f:
        f.write('\n'.join(output).expandtabs(4))


def main():

    with open('tools/import_mon_csv/mon.csv', newline='') as f:
        reader = csv.DictReader(f)
        for row in reader:
            read_evolutions(row)
        
        # Return to top and skip header
        f.seek(0)
        f.readline()

        for row in reader:
            read_mon(row)

    output_species_constants()
    output_nat_dex_constants()
    output_reg_dex_constants()
    output_mon_gfx_constants()
    output_species_info()

if __name__ == "__main__":
    main()