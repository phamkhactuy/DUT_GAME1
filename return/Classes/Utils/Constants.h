//
//  Constants.h
//  gamebase
//
//  Created by NGOCDIEP on 4/20/15.
//
//

#ifndef gamebase_Constants_h
#define gamebase_Constants_h

typedef enum
{
    TILE_DEFAULT = 0,
    TILE_LEFT = 16,
    TILE_RIGHT = 17,
    TILE_TOP = 18,
    TILE_BOT = 19,
    TILE_START = 24,
    TILE_END = 25,
    TILE_SPRINGS = 9,
    TILE_FORMAT = 6,
    TILE_STAR = 10,
    TILE_KEY = 7,
    TILE_ITEM_1 = 11,
    TILE_CAVE_1 = 12,
    TILE_CAVE_2 = 13,
    TILE_CAVE_3 = 14,
    TILE_CAVE_4 = 15,
    TILE_REMOVE = 1001,
}IDTILE;

#define TILE_SIZE 60
#define SP_SHADOW "UI/shadow.png"
#define SHOW_FPS false
#define WIN_SIZE CCDirector::sharedDirector()->getWinSize()

// Musics and SFX
#define BG_MUSIC_01 "audio/vg_bt_music.mp3"
#define BG_MUSIC_02 "audio/diego_music.mp3"
#define BG_MUSIC_03 "audio/POL-turtle-blues-short.mp3"

#define SFX_JUMP "audio/jump.mp3"
#define SFX_SMASH "audio/smash.mp3"
#define SFX_SWOOSH "audio/swoosh.mp3"
#define SFX_BUTTON "audio/button.mp3"
#define SFX_LIGHTNING "audio/lightning.mp3"

#endif

