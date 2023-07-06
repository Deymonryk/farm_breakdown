#pragma once

enum class GameState {
	MAIN_MENU,
	LEVEL_SELECT_MENU,
	SCENE,
	GAME_OVER_MESSAGE,
	NEW_GAME,
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