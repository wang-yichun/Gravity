//
//  CreaterConfig.h
//  GravityMapCreater
//
//  Created by MeYouGamesP3 on 14-1-14.
//
//

#ifndef GravityMapCreater_CreaterConfig_h
#define GravityMapCreater_CreaterConfig_h

#define PROGRAM_MODE_GAME 0 // 正常游戏模式;
#define PROGRAM_MODE_CREATER 1 // 地图编辑器模式;

// 程序可以进入的模式;
#define PROGRAM_MODE PROGRAM_MODE_GAME
// CELL上面显示信息;
#define DEBUG_CELL_INFO_SHOW 0

#endif

//////////////////////////////////////////////////////////////////////////
// 在编码时选择不同程序模式的宏;
/*
#if PROGRAM_MODE == PROGRAM_MODE_GAME
	// TODO:
#elif PROGRAM_MODE == PROGRAM_MODE_CREATER
	// TODO:
#else
	CCAssert(false, "PROGRAM_MODE unexpect.");
#endif
*/