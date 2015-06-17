#pragma once








//Uint32 mask_red, mask_green, mask_blue, mask_alpha;


//#if SDL_BYTEORDER == SDL_BIG_ENDIAN

enum Mask
{
    mask_red    = 0xff000000,
    mask_green  = 0x00ff0000,
    mask_blue   = 0x0000ff00,
    mask_alpha  = 0x000000ff,
};
//#else


//#endif
