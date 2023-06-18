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