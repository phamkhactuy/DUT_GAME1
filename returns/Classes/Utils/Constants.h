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
    TILE_LEFT = 28,
    TILE_RIGHT = 30,
    TILE_TOP = 29,
    TILE_BOT = 38,
    TILE_START = 19,//Vị trí bắt đầu
    TILE_END = 20,//Vị trí kết thúc
    TILE_SPRINGS = 25,
    TILE_FORMAT = 7,
    TILE_BARRIER = 10,//Vật cản
    TILE_STAR = 23,//Sao
    TILE_KEY = 24,
    TILE_ITEM_1 = 3,//Dịch chuyển 1 bước
    TILE_CAVE_1 = 1,//Dịch chuyển tức thời
    TILE_CAVE_2 = 2,//Dịch chuyển tức thời
    TILE_CAVE_3 = 6,//Dịch chuyển tức thời
    TILE_CAVE_4 = 4,//Dịch chuyển tức thời
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

