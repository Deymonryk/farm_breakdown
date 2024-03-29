#pragma once

enum class GameState {
	MAIN_MENU,
	LEVEL_SELECT_MENU,
	SCENE,
	RELOAD_LEVEL,
	NEXT_LEVEL,
	GAME_OVER_MESSAGE,
	VICTORY_MESSAGE
};

enum class SceneState {
	INACTIVE,
	ACTIVE,
	DEFEAT
};

enum class SpriteState {
	ZERO_LIFE,
	ONE_LIFE,
	TWO_LIVES,
	INVULNERABLE
};

constexpr const int SpriteStateToInt(SpriteState e) throw()
{
	switch (e)
	{
	case SpriteState::ZERO_LIFE: return 0;
	case SpriteState::ONE_LIFE: return 1;
	case SpriteState::TWO_LIVES: return 2;
	case SpriteState::INVULNERABLE: return 999;
	}
}
enum class GameLevels {
	Level1,
	Level2,
	Level3,
	Level4,
	Level5,
	Level6
};

constexpr const char* LevelsToString(GameLevels e) throw()
{
	switch (e)
	{
	case GameLevels::Level1: return "Level1";
	case GameLevels::Level2: return "Level2";
	case GameLevels::Level3: return "Level3";
	case GameLevels::Level4: return "Level4";
	case GameLevels::Level5: return "Level5";
	case GameLevels::Level6: return "Level6";
	}
}